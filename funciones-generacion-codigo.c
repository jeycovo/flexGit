#include "funciones-generacion-codigo.h"
#include "bison-jaguar.tab.h"
extern current_scope;
extern top;
extern FILE *obj;
unsigned int MAXR = 5;
int regoc[MAXR];
int stat_counter = -1;		// Contador n de STAT(n)
int code_counter = 0;		// Contador n de CODE(n)

//Métodos de Generación 
// gestor registros
// gestor etiquetas saltos
// extraer valor variable
// Meter valor variable
// dirMemrelativa
// dirMemTotal

//--- Métodos generales
//Gestor etiquetas
int etiq(){
	static int et = 0;
	return ++et;
}

void librereg(int i) { recog[i]=0; }

int ocreg(){
  int i;
  for (i=0;i<MAXR && regoc[i];i++);
  //Si no tengo el máximo ocupado libero
  if (i<MAXR) {
    regoc[i]=1;
    return i;
    //Tdos los registros ocupados
  } else yyerror("Generación de código","Ningún registro libre"); // insuficientes registros
}

//--- Bloques Stat y Code
void stat(){
	stat_counter++;
	fprintf(obj, "STAT(%d)", stats_counter);
}

void code(){
	if(stat_counter > -1){
		if(code_counter == stat_counter){	
			fprintf(obj, "CODE(%d)", code_counter);
			code_counter++;
		}else{
			yyerror("Generación de código", "Bloque code con un número superior al del stat anterior");
		}
	}else{
		yyerror("Generación de código", "No puede haber un bloque code sin un bloque stat antes");
	}
}
//--- Variables
//-- Estáticas
//- Declaración
declVarStat(struct reg *r){
	//Declaramos un bloque estático si no ha sido declarado
	if (stat_counter != code_counter){
		stat();
	}

	if(r->est == 1){	//Comprobamos si es estático
		int dir = r->dir;
		switch(r->tip){	//Según el tipo, reservamos distinto espacio
			case Int:
				fprintf(obj, "\tMEM(0x%x, 4);",dir);
				break;
			case Bool:
				fprintf(obj, "\tMEM(0x%x, 4);",dir);
				break;
			case Char:
				fprintf(obj, "\tMEM(0x%x, 1);",dir);
				break;
			case String:
				fprintf(obj, "\tMEM(0x%x, 100);",dir);
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
	}else{
		yyerror("Generación de código", "variable local");
	}
}

//- Declaración y asignación
declAsigVarStat(struct reg *r){
	//Declaramos un bloque estático si no ha sido declarado
	if (stat_counter != code_counter){
		stat();
	}

	if(r->est == 1){	//Comprobamos si es estático
		int dir = r->dir;
		switch(r->tip){ //Según el tipo, reservamos distinto espacio
			case Int:
				fprintf(obj, "\tFILL(0x%x, 4, %d);",dir, r->int_type);
				break;
			case Bool:
				fprintf(obj, "\tFILL(0x%x, 4, %d);",dir, r->bool_type);
				break;
			case Char:
				fprintf(obj, "\tFILL(0x%x, 1, %c);",dir, r->char_type);
				break;
			case String:
				fprintf(obj, "\tSTR(0x%x, %s);",dir, r->string_type);
				break;
			default:
				yyerror("-6: Tipo erróneo");
				break;
		}
	}else{
		yyerror("Generación de código", "variable local");
	}
}

//- Lectura
int accVarStat(char* var){
	struct reg *a = busq(var);
	if(a != NULL){
		int r = ocreg();
		int aDir = a->dir;
		fprintf(obj, "\tR%d=I(0x%x);\n",r,aDir);
		return r;
	}else{
		yyerror("Generación de código","no se encuentra la variable");
	}
}

//- Modificación
int modVarStat(char* var, int reg){
	struct reg *a = busq(var);
	if(a != NULL){
		int aDir = a->dir;
		fprintf(obj, "\tI(0x%x)=R%d;\n",aDir,r);
		//liberar registro ?
	}else{
		yyerror("Generación de código","no se encuentra la variable");
	}
}


//-- Locales
//- Acceso
//- 
//--- otras movidas
void expr(int r1, char op, int r2,){
	fprintf(obj, "\tR%d=R%d%cR%d;\n",r1,op,r2);
	librereg(r2);
}

int constant(char* value){
	int r = ocreg();
	fprintf("\tR%d=%s;\n",r,value);
}

//--- Métodos de bucles y condicionales
void jump(int e){
	fprintf(obj, "\tGT(%d);\n", e);
}

void comienzoBucle(int ec){
	fprintf(obj, "L %d:", ec);
}

void finBucle(int ec, int eb){
	fprintf(obj, "\tGT(%d);\nL %d:", ec, eb);
}

void cond(int nReg, int eb){
	fprintf(obj,"\tIF(!R%d) GT(%d);\n",ec, eb);
}
