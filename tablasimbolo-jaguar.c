#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "tablasimbolo-jaguar.h"
#include "bison-jaguar.tab.h"
#include "funciones-generacion-codigo.h"

int current_scope = 0;
int flag_first = 0;
int flag_function = 0;
int tamInicialBuffer = 3;
int tamVector = 0;
int tamString = 100;
struct reg *punteroVector;
//Conclusiones
/*
	-> El scope da igual, porque las variables de scopes menores se van liberando
	->
*/
struct reg * top = NULL;		//puntero que apunta al top de la pila

char *inicat = "vVFP";			//código categoría
char *initip = "IBCSV";			//código tipo

//--- Buscar registro - Función
struct reg *busqFunc(char *id, struct reg *f){
	while(f != NULL){		
		if(strcmp(f->id,id)==0){
			return f;
		}
		f = f->sigparam;
	}
	return NULL;
}

//--- Buscar registro - Otros
struct reg *busq(char *id){
  	struct reg *p = top;
  	while (p!=NULL){
		if(p->scope > current_scope){
			p=p->sig;
		}else if(p->cat == func && flag_function == 1){
			return busqFunc(id, p);
		}else if(strcmp(p->id,id)==0 && ((p->func_scope == 1 && flag_function == 1) || (p->func_scope == 0 && flag_function == 0))){ 
			return p;
		}else{
			p=p->sig;
		}
	}
  	return p;
}


//--- Insertar registros Variables 
struct reg* ins(char *id, enum categ cat, enum tipos tip, int numlin){
	struct reg *h = busq(id);
	if (h != NULL){
		switch(h->cat){			
			case func:
				yyerror("-1.2: nombre de función ya definido");
				break;
			case param:
				yyerror("-1.3: nombre de parámetro ya definido");
				break;
			case varV:
				yyerror("-1.4: nombre de vector ya definido");
				break;
			default:
				yyerror("-1.1: nombre de variable ya definido");
				break;
		}
	}else{
		struct reg *p;
		switch(cat){
			case param:
				if(top->cat == func){		
					p = (struct reg *)malloc(sizeof(struct reg));		//Reservamos el espacio en memoria
		  			p->id=id; p->cat=cat; p->tip=tip;					//le asignamos, id, categoria y tipo
					p->lineno=numlin;
					struct reg *q = top; 
					//buscamos el último parámetro guardado en la lista encadenada de parametros
					while(q->sigparam != NULL){		
						q = q->sigparam;
					}
					q->sigparam = p;
					printRegistro(p);
					return p;
				}else{
					yyerror("-5.1: función no encontrada");
				}
				break;
			case varV:
				p = (struct reg *)malloc(sizeof(struct reg));		//Reservamos el espacio en memoria
		  		p->id=id; p->cat=cat; p->tip=tip;					//le asignamos, id, categoria y tipo
		  		p->scope=current_scope; p->lineno=numlin;
		  		p->sig = top;
				p->puntVector = 0;
				if(tamVector != 0){
					p->tamFijado = 1;
					asignarEspacioVector(p, tamVector);
				}else{
					p->tamFijado = 0;
					asignarEspacioVector(p, tamInicialBuffer);
				}
				top = p;
				tamVector =  0;
				punteroVector = p;
				return p;
				break;
			default:
				p = (struct reg *)malloc(sizeof(struct reg));		//Reservamos el espacio en memoria
		  		p->id=id; p->cat=cat; p->tip=tip;								//le asignamos, id, categoria y tipo
		  		p->scope=current_scope; p->lineno=numlin;
		  		p->sig = top;													//Establecemos un enlace al nodo anterior (el top de la pila)
				if(flag_function == 1){
					p->func_scope = 1;		
				}else{
					p->func_scope = 0;
				}

				if(p->cat == func){				//Se trata de una función, lo indicamos para los registros de la misma
					isFunction();
				}

				top = p;														//Ahora el nodo actual es el top de la pila
				printRegistro(p); 												//Imprimimos
				return p;
		}
	}
	return NULL;
}

//--- Insertar Valores en el vector
//-- Int
void insVectorInt(int value){
	if(punteroVector != NULL){
		struct reg *r = punteroVector;
		if(r->cat == varV){
			int pV	= r->puntVector;		//nº elementos del vector
			int tMV = r->tamMemVector;		//nº elementos que hemos reservado en memoria para el vector
			if(tMV <= pV){			   		//Vamos a introducir un elemento 
				if(tamVector == 0){
					r->tamMemVector += tamInicialBuffer;						// Actualizamos el tamaño del vector
					r->intV_type=(int*)realloc(r->intV_type,r->tamMemVector*sizeof(int));
				}else{
					yyerror("-7.1: número de elementos de la asignación mayor al número indicado en la declaración del vector");
				}
			}
			r->intV_type[pV] = value;
			r->puntVector++;		//Aumentamos el puntero, hemos metido un elemento más
		}else{
			yyerror("-8.0: la variable no es de tipo vector");
		}
	}else{
		yyerror("-5.2: vector no encontrado");
	}
}

// -- Boolean
void insVectorBool(int value){
	if(punteroVector != NULL){
		struct reg *r = punteroVector;
		if(r->cat == varV){
			int pV	= r->puntVector;		//nº elementos del vector
			int tMV = r->tamMemVector;		//nº elementos que hemos reservado en memoria para el vector
			if(tMV <= pV){			   		//Vamos a introducir un elemento 
				if(tamVector == 0){
					r->tamMemVector += tamInicialBuffer;						// Actualizamos el tamaño del vector
					r->boolV_type=(int*)realloc(r->boolV_type,r->tamMemVector*sizeof(int));
				}else{
					yyerror("-7.1: número de elementos de la asignación mayor al número indicado en la declaración del vector");
				}
			}
			r->boolV_type[pV] = value;
			r->puntVector++;		//Aumentamos el puntero, hemos metido un elemento más
		}else{
			yyerror("-8.0: la variable no es de tipo vector");
		}
	}else{
		yyerror("-5.2: vector no encontrado");
	}
}


// -- Char
void insVectorChar(char value){
	if(punteroVector != NULL){
		struct reg *r = punteroVector;
		if(r->cat == varV){
			int pV	= r->puntVector;			//nº elementos del vector
			int tMV = r->tamMemVector;		//nº elementos que hemos reservado en memoria para el vector
			if(tMV <= pV){			   		//Vamos a introducir un elemento 
				if(tamVector == 0){
					r->tamMemVector += tamInicialBuffer;						// Actualizamos el tamaño del vector
					r->charV_type=(char*)realloc(r->charV_type,r->tamMemVector*sizeof(char)); // Asignamos al vector el nuevo vector que hemos creado
				}else{
					yyerror("-7.1: número de elementos de la asignación mayor al número indicado en la declaración del vector");
				}
			}
			r->charV_type[pV] = value;		
			r->puntVector++;				//Aumentamos el puntero, hemos metido un elemento más
		}else{
			yyerror("-8.0: la variable no es de tipo vector");
		}
	}else{
		yyerror("-5.2: vector no encontrado");
	}
}

//-- String
void insVectorString(char* value){
	if(punteroVector != NULL){
		struct reg *r = punteroVector;
		if(r->cat == varV){
			int pV	= r->puntVector;			//nº elementos del vector
			int tMV = r->tamMemVector;		//nº elementos que hemos reservado en memoria para el vector
			if(tMV <= pV){			   		//Vamos a introducir un elemento 
				if(tamVector == 0){
					r->tamMemVector += tamInicialBuffer;						// Actualizamos el tamaño del vector
					r->stringV_type=(char**)realloc(r->stringV_type,r->tamMemVector * tamString*sizeof(char));
				}else{
					yyerror("-7.1: número de elementos de la asignación mayor al número indicado en la declaración del vector");
				}
			}
			if(strlen(value)+1 > tamString){
				yyerror("-8.0: la string a guardar ha superado el tamaño reservado, solo se ha almacenado hasta el %dº carácter", tamString+1);
			}
			r->stringV_type[pV] = (char*)malloc(sizeof(char)*(strlen(value)+1));
			r->stringV_type[pV] = value;		
			//printf("---valor [%d] -> %s", pV, r->stringV_type[pV]);
			r->puntVector++;				//Aumentamos el puntero, hemos metido un elemento más
		}else{
			yyerror("-8.0: la variable no es de tipo vector");
		}
	}else{
		yyerror("-5.2: vector no encontrado");
	}
}


//--- Borrar un bloque (mismo scope) de registros
void finBloque(){
	while (top!=NULL && top->scope == current_scope && top->cat != func) {// mientras este en nuestro scope, metemos su nombre en la Death Note
		struct reg *p = top->sig;		
		free(top->id); free(top); top=p;
	}
  current_scope--;
}



//-- Adicionales -------------------------------------------------------
//Printear todos los registros
//Pal futuro -> añadir un printf por cada tipo, para que se printee el contenido

struct valores* getVecValue(struct reg *p, int pos){
	struct valores *v;
	switch(p->tip){
			case Int:
				v->intValue = p->intV_type[pos];
				break;
			case Bool:
				v->boolValue = p->boolV_type[pos];
				break;
			case Char:
				v->charValue = p->charV_type[pos];
				break;
			case String:
				v->stringValue = p->stringV_type[pos];
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
	return v;
}

struct valores* getVarValue(struct reg *p){
	struct valores *v;
	switch(p->tip){
			case Int:
				v->intValue = p->int_type;
				break;
			case Bool:
				v->boolValue = p->bool_type;
				break;
			case Char:
				v->charValue = p->char_type;
				break;
			case String:
				v->stringValue = p->string_type;
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
	return v;
}

//- Getters de elementos de vectores
int getVectorI(struct reg* r, int pos){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector-a");
	}else{
		printf("-get: %s[%d] -> %d\n", r->id, pos, r->intV_type[pos]);
		return (int) r->intV_type[pos];
	}
	return (int) -1;
}

int getVectorB(struct reg* r, int pos){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vectora-b");
	}else{
		printf("-get: %s[%d] -> %d\n", r->id, pos, r->boolV_type[pos]);
		return (int) r->boolV_type[pos];
	}
	return (int) -1;
}

char getVectorC(struct reg* r, int pos){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector-c");
	}else{
		printf("-get: %s[%d] -> %c\n", r->id, pos, r->charV_type[pos]);
		return (char) r->charV_type[pos];
	}
	return (char) '\0';
}

char* getVectorS(struct reg* r, int pos){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector-d");	
	}else{
		//strcpy(char* value, r->stringV_type[pos]);
		printf("-get: %s[%d] -> %s\n", r->id, pos, r->stringV_type[pos]);
		return (char*) r->stringV_type[pos];
	}
	return (char*) "\0";
}

//setters de vectores
void setVectorI(struct reg* r, int pos, int value){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector");
	}else{
		r->intV_type[pos] = value;
		printf("-set: %d -> %s[%d]\n", value, r->id, pos);
	}
}

void setVectorB(struct reg* r, int pos, int value){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector");
	}else{
		r->boolV_type[pos] = value;
		printf("-set: %d -> %s[%d]\n",value, r->id, pos);
	}
}

void setVectorC(struct reg* r, int pos, char value){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector");
	}else{
		r->charV_type[pos] = value;
		printf("-set: %c -> %s[%d]\n",value, r->id, pos);
	}	
}

void setVectorS(struct reg* r, int pos, char* value){
	if(pos >= r->tamMemVector){
		yyerror("La posición a la que intenta acceder es mayor al total de los elementos del vector");
	}else{
		r->stringV_type[pos] = value;
		printf("-set: %s -> %s[%d]\n",value, r->id, pos);
	}
}

void cambiarTamVector(int t){
	tamVector = t;
}

void chequearTamVector(){
	struct reg *r = punteroVector;
	if(r->tamFijado == 0){		//Ajustamos el tamaño del vector para almacenar el espacio solamente necesario
		switch(r->tip){
			case Int:
				r->intV_type=(int*)realloc(r->intV_type,r->puntVector*sizeof(int));
				break;
			case Bool:
				r->boolV_type=(int*)realloc(r->boolV_type,r->puntVector*sizeof(int));
				break;
			case Char:
				r->charV_type=(char*)realloc(r->charV_type,r->puntVector*sizeof(char));
				break;
			case String:
				r->stringV_type=(char**)realloc(r->stringV_type,r->puntVector*sizeof(char)*tamString);
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
		r->tamMemVector = r->puntVector;
	}
	printRegistro(r);
	punteroVector = NULL;
}

void asignarEspacioVector(struct reg *p, int tam){
	p->tamMemVector = tam;
	switch(p->tip){
		case Int:
			//p->intV_type = (int)calloc(p->tamMemVector, sizeof(int)*(p->tamMemVector));
			p->intV_type = (int*)malloc(sizeof(int)*(p->tamMemVector));
			break;
		case Bool:
			//p->boolV_type = (int)calloc(p->tamMemVector, sizeof(int)*(p->tamMemVector));
			p->boolV_type = (int*)malloc(sizeof(int)*(p->tamMemVector));
			break;
		case Char:
			//p->charV_type = (char*)calloc(p->tamMemVector, sizeof(char)*(p->tamMemVector));
			p->charV_type = (char*)malloc(sizeof(char)*(p->tamMemVector));
			break;
		case String:
			//p->stringV_type = (char**)calloc(p->tamMemVector, sizeof(char)*(p->tamMemVector)*tamString);
			p->stringV_type = (char**)malloc(sizeof(char)*(p->tamMemVector)*tamString);
			break;
		default:
			yyerror("-6: Tipo erróneo");
			break;
	}
}

void copiarVector(struct reg *r, struct reg *s){
	if(s->cat != varV){
		yyerror("A un vector solo se le puede asignar otro vector");
	}else if(r->tip != s->tip){
		yyerror("El vector ha asignar debe ser del mismo tipo");
	}else if(r->tamMemVector != s->tamMemVector){
		yyerror("Ambos vectores deben tener el mismo tamaño");
	}else{
		switch(r->tip){
			case Int:
				r->intV_type = s->intV_type;
				break;
			case Bool:
				r->boolV_type = s->boolV_type;
				break;
			case Char:
				r->charV_type = s->charV_type;
				break;
			case String:
				r->stringV_type = s->stringV_type;
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
	}
}

void isFunction(){
	flag_function = 1;
}

void notFunction(){
	flag_function = 0;
	current_scope--; 		//Hemos terminado el scope_function así que hay que reducir en 1 el scope
}

void printRegistro(struct reg *p){
	if(flag_first == 0) printf("------------ Lista de Registros: ------------\n"); flag_first = 1;
	if(p->cat == func){
		printf("linea:%d -- %s : categoria-> %c -- tipo-> %c -- scope-> %d -- \n", p->lineno, p->id, inicat[p->cat], initip[p->tip], p->scope);
		while(p->sigparam != NULL){	
			p = p->sigparam;	
			printf("linea:%d -- %s : categoria-> %c -- tipo-> %c -- scope-> %d -- \n", p->lineno, p->id, inicat[p->cat], initip[p->tip], p->scope);
		}
	}else if(p->cat == var){
		printf("linea:%d -- %s : categoria-> %c -- tipo-> %c -- scope-> %d -- \n", p->lineno, p->id, inicat[p->cat], initip[p->tip], p->scope);
	}if(p->cat == varV){
		printf("linea:%d -- %s : num. Elementos-> %d  -- esp. Reservado -> %d -- categoria-> %c -- tipo-> %c -- scope-> %d -- \n", p->lineno, p->id, p->puntVector, p->tamMemVector, inicat[p->cat], initip[p->tip], p->scope);
		int count = 0;
		int valueI;
		char valueC;
		char* valueS;
		while(count <  p->puntVector){
			switch(p->tip){
				case Int:
					valueI = p->intV_type[count];
					printf("- Elemento [%d] -> %d\n", count, valueI);
					break;
				case Bool:
					valueI = p->boolV_type[count];
					if(valueI == 0){
						printf("- Elemento [%d] -> %d : %s\n", count, valueI, "false");
					}else{
						printf("- Elemento [%d] -> %d : %s\n", count, valueI, "true");
					}
					break;
				case Char:
					valueC = p->charV_type[count];
					printf("- Elemento [%d] -> %c\n", count, valueC);
					break;
				case String:
					valueS = p->stringV_type[count];
					printf("- Elemento [%d] -> %s\n", count, valueS);
					break;
				default:
					printf("error!");							
					break;
			}
		count++;
		}
	}
}

void printValorRegistro(struct reg *p){
	switch(p->tip){
		case Int:
			printf("Valor -> %d\n", p->int_type);
			break;
		case Bool:
			printf("Valor -> %d\n", p->bool_type);
			break;
		case Char:
			printf("Valor -> %c\n", p->char_type);
			break;
		case String:
			printf("Valor -> %s\n", p->string_type);
			break;
		case Void:
			printf("Valor -> Void");
			break;
		default:
			printf("default");
			break;
	}
}

void printBloque(){
	printf(" ------------ Lista de Registros: Bloque--------------");
	struct reg *p = top;
  	while (p!=NULL && p->scope == current_scope){
		printf("linea:%d -- %s : categoria-> %c -- tipo-> %c -- scope-> %d -- linea-> %d -- \n", p->lineno, p, p->id, inicat[p->cat], initip[p->tip], p->scope);
		p=p->sig;
	}
}
 
void printTodo(){
	printf("\n------------ Lista de Registros: Todo --------------\n");
	flag_first = 1;
	struct reg *p = top;
  	while (p!=NULL){
		printRegistro(p);
		p=p->sig;
	}
	printf("\n\n");
}

