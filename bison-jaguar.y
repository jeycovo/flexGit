%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tablasimbolo-jaguar.h"
#include "Qlib.h"

#define YYDEBUG 1

extern FILE *yyin;
extern int numlin;
extern int current_scope;
extern struct reg *punteroVector;
//int yydebug=1;
void yyerror (char* mens);
int yylex();
char* concN (char* string, int n);
int powJ(int a, int b);

//Generación de código
int sm = 0x12000;
int fm;
int et = 1;

FILE *obj;
%}

//tipos
//%error-verbose
%union{
	int entero;
	char caracter;
	char* cadena;
	int booleano;
}
//%define lr.default-reduction accepting

//tipos
%token VOID
%token INT
%token CHAR
%token BOOL
%token STRING

//literales
%token <entero>   NUMBER
%token <caracter> CHARACTER
%token <cadena>   IDENTIF
%token <cadena>   STRINGLITERAL

//estructuras
////General

%token RETURN

////Condicional
%token IFCOND
%token ELIF
%token ELSECOND

////Bucles
%token FOR
%token WHILELOOP
%token DOLOOP
%token BREAK
%token CONTINUE

//Funciones Built-in
%token PRINTF
%token PRINTFARROW

//Comparadores
%token SMALLEREQUALTHAN
%token BIGGEREQUALTHAN
%token EQUIVALENT
%token EQUIVALENTNOT

//booleanos
%token AND
%token OR
%token NOT
%token <booleano> TRUE
%token <booleano> FALSE

//tipos
%type <caracter> expC
%type <cadena>   expS
%type <booleano> expB
%type <entero>   expI

//Operandos Aritméticos Precedencia

%left BREAK CONTINUE
%left '>' '<' AND OR EQUIVALENT EQUIVALENTNOT BIGGEREQUALTHAN SMALLEREQUALTHAN
%left '+' '-'
%left '*' '/' '^'
%left '(' ')' '{' '}'
%left ';'
%%

//--Estructuras
//Estructuras de alto nivel

programa : bloque
		 | %empty
		 ;

bloque   : loopStructure
		 | instr
		 | conditionalStructure 
		 | functionStructure
		 | error
		 | functionStructure bloque
		 | conditionalStructure bloque
		 | instr bloque
	     | error bloque
		 | loopStructure bloque
		 ;

/*
//Estructuras de medio nivel
//Funciones
//
*/

functionStructure : INT IDENTIF		{ins($2,func,Int,numlin);}  	'(' functionParameter ')' '{' functionBlockEmpty '}' {notFunction();}
				  | CHAR IDENTIF	{ins($2,func,Char,numlin);} 	'(' functionParameter ')' '{' functionBlockEmpty '}' {notFunction();}	
				  | BOOL IDENTIF	{ins($2,func,Bool,numlin);}		'(' functionParameter ')' '{' functionBlockEmpty '}' {notFunction();}	
				  | STRING IDENTIF	{ins($2,func,String,numlin);}	'(' functionParameter ')' '{' functionBlockEmpty '}' {notFunction();}
				  | VOID IDENTIF 	{ins($2,func,Void,numlin);}		'(' functionParameter ')' '{' functionBlockEmpty '}' {notFunction();}
				  | functionCallStructure ';'
				  ;

functionCallStructure : IDENTIF '(' functionCallParameter ')' 
				      ;

functionParameter : {current_scope++;} Parameter
				  | {current_scope++;} %empty
			      ;

//metodo de insertar para funcion
Parameter : INT IDENTIF						{ins($2,param,Int,numlin);}
		  | CHAR IDENTIF					{ins($2,param,Char,numlin);}
		  | STRING IDENTIF					{ins($2,param,String,numlin);}
		  | BOOL IDENTIF					{ins($2,param,Bool,numlin);}
		  | INT IDENTIF ',' Parameter		{ins($2,param,Int,numlin);}
		  | CHAR IDENTIF ',' Parameter		{ins($2,param,Char,numlin);}
		  | STRING IDENTIF ',' Parameter	{ins($2,param,String,numlin);}
		  | BOOL IDENTIF ',' Parameter		{ins($2,param,Bool,numlin);}
		  ;

functionCallParameter	: IDENTIF
						| %empty
						| IDENTIF ',' functionCallParameter
						| expI ',' functionCallParameter
						| expB ',' functionCallParameter
						| expC ',' functionCallParameter
						| expS ',' functionCallParameter
						| expI
						| expB
						| expC
						| expS
						;

functionBlockEmpty : %empty
				   | {isFunction();} functionBlock 
				   ;

functionBlock : loopStructure
		   	  | conditionalStructure 
		      | functionStructure
			  | instr
		   	  | RETURN IDENTIF ';'
		      | RETURN expI ';'
			  | RETURN expB ';'
			  | RETURN expC ';'
			  | RETURN expS ';'
			  | instr						functionBlock
		   	  | RETURN IDENTIF ';'			functionBlock
		      | RETURN expI ';'		functionBlock
			  | RETURN expB ';'		functionBlock
			  | RETURN expC ';'		functionBlock
			  | RETURN expS ';'		functionBlock
			  | loopStructure				functionBlock
		   	  | conditionalStructure 		functionBlock
		      | functionStructure			functionBlock
		   	  ;



//-Condicionales
conditionalStructure : ifStructure 
					 | ifStructure elifStructure
					 | ifStructure elifStructure elseStructure
					 | ifStructure elseStructure
					 ;

ifStructure   : IFCOND '(' expB ')' '{' ifBlockEmpty '}'
			  ;

elifStructure : ELIF '(' expB ')' '{' ifBlockEmpty'}'
			  | ELIF '(' expB ')' '{' ifBlockEmpty '}' elifStructure
			  ;

elseStructure : ELSECOND '{' ifBlockEmpty '}'
			  ;

ifBlockEmpty : %empty
			 | {current_scope++;} ifBlock {finBloque();}
			 ;

ifBlock : loopStructure
		| conditionalStructure 
	   	| functionStructure
	   	| instr
	   	| loopBlock instr 
	   	| loopBlock loopStructure
	   	| loopBlock conditionalStructure 
	   	| loopBlock functionStructure
	   	;

//-Bucles
loopStructure : FOR '(' declI ';' expB ';' expI ')' '{' loopBlockEmpty '}' 
			  | DOLOOP '{' loopBlockEmpty'}' WHILELOOP '(' expB ')' ';'
			  | WHILELOOP '(' expB ')' '{' loopBlockEmpty '}'
			  ;

loopBlockEmpty : %empty
			   | {current_scope++;} loopBlock {finBloque();}
			   ;

loopBlock  : loopStructure
		   | conditionalStructure 
		   | functionStructure
		   | instr
		   | BREAK    ';' 
		   | CONTINUE ';' 
		   | loopBlock BREAK ';' 
		   | loopBlock CONTINUE ';' 
		   | loopBlock instr 
		   | loopBlock loopStructure
		   | loopBlock conditionalStructure 
		   | loopBlock functionStructure
		   ;

//-Estructuras de bajo nivel

instr	: dexp ';';

/*
instr	: dexp 		';'
		| declVI	';'
	 	| declVC	';'
	 	| declVB	';'
	 	| declVS	';'
	 	;
//pner el declF
*/

dexp : declI 
	 | declC
	 | declB
	 | declS
	 | declVI
	 | declVC
	 | declVB
	 | declVS
	 ;


//--Declaraciones y Asignaciones
//-Elementales

/*
declF : INT IDENTIF '=' functionCallStructure 
	  | CHAR IDENTIF '=' functionCallStructure
	  | STRING IDENTIF '=' functionCallStructure
	  | BOOL IDENTIF '=' functionCallStructure
	  | IDENTIF '=' functionCallStructure 
	  ;
*/
//void ins(char *id, enum categ cat, enum tipos tip)
//enum categ {var, varV, func, param};
//enum tipos {Int, Bool, Char, String, Void};

//printeo en reserva
//print : PRINTF PRINTFARROW IDENTIF {imprimir(busq($3)->tipos);}

/*
dexp: INT IDENTIF '=' expI {struct reg *r = ins($2, var, Int, numlin); if(r != NULL) {}}
	| BOOL IDENTIF'=' expB {struct reg *r = ins($2, var, Bool, numlin); if(r != NULL) {}}
	| CHAR IDENTIF'=' expC {struct reg *r = ins($2, var, CHAR, numlin); if(r != NULL) {}}
	| STRING IDENTIF'='expS {struct reg *r = ins($2, var, Int, numlin); if(r != NULL) {}}
	| INT IDENTIF 	'=' functionCallStructure
	| BOOL IDENTIF	'=' functionCallStructure
	| CHAR IDENTIF	'=' functionCallStructure
	| STRING IDENTIF'=' functionCallStructure
	| INT IDENTIF		{ins($2, var, Int, numlin);}
	| BOOL IDENTIF		{ins($2, var, Bool, numlin);}
	| CHAR IDENTIF		{ins($2, var, Char, numlin);}
	| STRING IDENTIF	{ins($2, var, String, numlin);}
	;
*/

declI: INT IDENTIF '=' expI {struct reg *r = ins($2, var, Int, numlin); if(r != NULL) {}}
	 | IDENTIF	   '=' expI		
	 | INT IDENTIF '=' functionCallStructure
	 | INT IDENTIF	{ins($2, var, Int, numlin);}	
	 ;

declB: BOOL IDENTIF '=' expB {struct reg *r = ins($2, var, Bool, numlin); if(r != NULL) {}}
	 | IDENTIF	    '=' expB
	 | BOOL IDENTIF	'=' functionCallStructure
	 | BOOL IDENTIF	 {ins($2, var, Bool, numlin);}
	 ;

declC: CHAR IDENTIF'=' expC {struct reg *r = ins($2, var, CHAR, numlin); if(r != NULL) {}}
	 | CHAR IDENTIF	'=' functionCallStructure
	 | CHAR IDENTIF		{ins($2, var, Char, numlin);}
	 ;

DeclS: STRING IDENTIF'='expS {struct reg *r = ins($2, var, Int, numlin); if(r != NULL) {}}
	 | STRING IDENTIF'=' functionCallStructure
	 | STRING IDENTIF	{ins($2, var, String, numlin);}
	 ;

//-Vectores
declVI 	: INT '[' ']' IDENTIF '='		{ins($4, varV, Int, numlin);} '[' viContent ']' {chequearTamVector();}	 
		| INT '[' ']' IDENTIF			{ins($4, varV, Int, numlin);}
		| INT '[' expI ']' IDENTIF '=' 	{cambiarTamVector($3); ins($5, varV, Int, numlin);} '[' viContent ']' {chequearTamVector();}
		| INT '[' expI ']' IDENTIF		{cambiarTamVector($3); ins($5, varV, Int, numlin);} 
		| IDENTIF '=' {struct reg *r = busq($1); if(r!=NULL) punteroVector = r; else yyerror("Sintáctico", "Vector no encontrado");} '[' viContent ']' {chequearTamVector();}
		| IDENTIF '[' expI ']' '=' expI	{struct reg *r = busq($1); if(r!=NULL) setVectorI(r, $3, $6); else yyerror("Sintáctico", "Vector no encontrado");}
		;
/*	
		| INT '[' ']' IDENTIF  '=' IDENTIF 
{r = ins($4, varV, Int, numlin); s = busq($6); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else {yyerror("Vector no encontrado");}}
		| INT '[' expI ']' IDENTIF  '='  IDENTIF {cambiarTamVector($3); r = ins($5, varV, Int, numlin); s = busq($7); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else {yyerror("Vector no encontrado");}}
		| IDENTIF '=' IDENTIF {r = busq($1); s = busq($3); if(s!=NULL && r!=NULL) {copiarVector(r,s); printRegistro(r);} else {yyerror("Vector no encontrado");}}
		;
*/
viContent : expI {if(punteroVector != NULL) insVectorInt($1);}
		  | expI {if(punteroVector != NULL) insVectorInt($1);}	',' viContent										
		  ;

declVC 	: CHAR '[' ']' IDENTIF '=' 		{ins($4, varV, Char, numlin);} '[' vcContent ']' {chequearTamVector();}
		| CHAR '[' ']' IDENTIF			{ins($4, varV, Char, numlin);} 
		| CHAR '[' expI ']' IDENTIF '=' {cambiarTamVector($3); ins($5, varV, Char, numlin);} '[' vcContent ']' {chequearTamVector();}
		| CHAR '[' expI ']' IDENTIF		{cambiarTamVector($3); ins($5, varV, Char, numlin);}
		| IDENTIF '=' {struct reg *r = busq($1); if(r!=NULL) punteroVector = r; else yyerror("Sintáctico", "Vector no encontrado");}  {chequearTamVector();}
		| IDENTIF '[' expI ']' '=' expC	{struct reg *r = busq($1); if(r!=NULL) setVectorC(r, $3, $6); else yyerror("Sintáctico", "Vector no encontrado");}
		;
/*		
		| CHAR '[' ']' IDENTIF  '=' IDENTIF 
			{r = ins($4, varV, Char, numlin); s = busq($6); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}
		| CHAR '[' expI ']' IDENTIF  '='  IDENTIF
			{cambiarTamVector($3); r = ins($5, varV, Char, numlin); s = busq($7); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}
		| IDENTIF '=' IDENTIF
			{r = busq($1); s = busq($3); if(s!=NULL && r!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}
		;
*/

vcContent : expC 	{insVectorChar($1);}
		  | expC 	{insVectorChar($1);} ',' vcContent		
		  ;

declVS 	: STRING '[' ']' IDENTIF '=' 		{ins($4, varV, String, numlin);} '[' vsContent ']' {chequearTamVector();}
		| STRING '[' ']' IDENTIF			{ins($4, varV, String, numlin);}
		| STRING '[' expI ']' IDENTIF '='	{cambiarTamVector($3); ins($5, varV, String, numlin);} '[' vsContent ']' {chequearTamVector();}
		| STRING '[' expI ']' IDENTIF		{cambiarTamVector($3); ins($5, varV, String, numlin);}
		| IDENTIF '=' '[' vsContent ']'  	{struct reg *r = busq($1); if(r!=NULL) punteroVector = r; else yyerror("Sintáctico", "Vector no encontrado");} {chequearTamVector();}
		| IDENTIF '[' expI ']' '=' expS		{struct reg *r = busq($1); if(r!=NULL) setVectorS(r, $3, $6); else yyerror("Sintáctico", "Vector no encontrado");}
		;
/*		
		| STRING '[' ']' IDENTIF  '=' IDENTIF 
			{r = ins($4, varV, String, numlin); s = busq($6); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}
		| STRING '[' expI ']' IDENTIF  '='  IDENTIF
			{cambiarTamVector($3); r = ins($5, varV, String, numlin); s = busq($7); if(s!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}
		| IDENTIF '=' IDENTIF
			{r = busq($1); s = busq($3); if(s!=NULL && r!=NULL) {copiarVector(r,s); printRegistro(r);} else yyerror("Vector no encontrado");}		
		;
*/
vsContent : expS {insVectorString($1);}	
		  | expS {insVectorString($1);}',' vsContent
		  ;

declVB 	: BOOL '[' ']' IDENTIF '=' 		{ins($4, varV, Bool, numlin);} '[' vbContent ']' {chequearTamVector();}
		| BOOL '[' ']' IDENTIF			{ins($4, varV, Bool, numlin);}
		| BOOL '[' expI ']' IDENTIF '=' {cambiarTamVector($3); ins($5, varV, Bool, numlin);} '[' vbContent ']'	{chequearTamVector();}
		| BOOL '[' expI ']' IDENTIF		{cambiarTamVector($3); ins($5, varV, Bool, numlin);}
		| IDENTIF '=' '[' vbContent ']' {struct reg *r = busq($1); if(r!=NULL) punteroVector = r; else yyerror("Sintáctico", "Vector no encontrado");} {chequearTamVector();}
		| IDENTIF '[' expI ']' '=' expB {struct reg *r = busq($1); if(r!=NULL) setVectorB(r, $3, $6); else yyerror("Sintáctico", "Vector no encontrado");}
		;
/*
		| BOOL '[' ']' IDENTIF  '=' IDENTIF 
			{r = ins($4, varV, Bool, numlin); s = busq($6); if(s!=NULL) copiarVector(r,s); else yyerror("Vector no encontrado");}
		| BOOL '[' expI ']' IDENTIF  '='  IDENTIF
			{cambiarTamVector($3); r = ins($5, varV, Bool, numlin); s = busq($7); if(s!=NULL) copiarVector(r,s); else yyerror("Vector no encontrado");}
		| IDENTIF '=' IDENTIF
			{r = busq($1); s = busq($3); if(s!=NULL && r!=NULL) copiarVector(r,s); else yyerror("Vector no encontrado");}
		;
*/
vbContent : expB {insVectorBool($1);}	
		  | expB {insVectorBool($1);}	',' vbContent
		  ;

//Operaciones entre int
expI	:	expI '+' expI {$$ = $1 + $3;}
		|	expI '-' expI {$$ = $1 - $3;}
		|	expI '*' expI {$$ = $1 * $3;}
		|	expI '/' expI {$$ = $1 / $3;}
		|	expI '^' expI {$$ = powJ($1,$3);}
		|	'(' expI ')'  {$$ = $2;}
		|	NUMBER	      {$$ = $1;}
		| 	'-' NUMBER    {$$ = -$2;}
		| 	IDENTIF '[' NUMBER ']' {printf("soy un elemento de un vector");}
		|   IDENTIF		  		   {printf("soy una variable");}
		;

//Operaciones entre string
expS : 	expS '+'  expS {$$ = strcat($1,$3);}
	 |  expI '*'  expS {$$ = concN($<cadena>3,$<entero>1);}
	 |  expS '*'  expI {$$ = concN($<cadena>1,$<entero>3);}
	 |	'(' expS ')' {$$ = $2;}
     | 	STRINGLITERAL  {$$ = $1;}
	 |  IDENTIF '[' NUMBER ']'  {printf("soy un elemento de un vector");}
	 |  IDENTIF	 			 	{printf("soy una variable");}
	 ;

//Operaciones booleanos
expB : expB AND expB				{$$ = $1 * $3;}
	 | expB OR expB					{$$ = ($1+$3 >= 1) 			? 1: 0;}
	 | expB EQUIVALENT expB 		{$$ = ($1 == $3)  			? 1: 0;}
	 | expI EQUIVALENT expI 		{$$ = ($1 == $3)  			? 1: 0;}
	 | expC EQUIVALENT expC 		{$$ = ($1 == $3)  			? 1: 0;}
	 | expS EQUIVALENT expS 		{$$ = (strcmp($1, $3) == 0) ? 1: 0;}
	 | expB EQUIVALENTNOT expB 		{$$ = ($1 == $3)  			? 0: 1;}
	 | expI EQUIVALENTNOT expI 		{$$ = ($1 == $3)  			? 0: 1;}
	 | expC EQUIVALENTNOT expC 		{$$ = ($1 == $3)  			? 0: 1;}
	 | expS EQUIVALENTNOT expS 		{$$ = (strcmp($1, $3) == 0) ? 0: 1;}
	 | expI BIGGEREQUALTHAN expI 	{$$ = ($1 >= $3)  			? 1: 0;}
	 | expS BIGGEREQUALTHAN expS 	{$$ = (strcmp($1, $3) >= 0) ? 1: 0;}
	 | expI SMALLEREQUALTHAN expI 	{$$ = ($1 <= $3)  			? 1: 0;}
	 | expS SMALLEREQUALTHAN expS 	{$$ = (strcmp($1, $3) <= 0) ? 1: 0;}
	 | expS '>' expS 				{$$ = (strcmp($1, $3)  > 0) ? 1: 0;}
	 | expI '>' expI 				{$$ = ($1 > $3)  			? 1: 0;}
	 | expS '<' expS 				{$$ = (strcmp($1, $3)  < 0) ? 1: 0;}
	 | expI '<' expI 				{$$ = ($1 < $3)  			? 1: 0;}
	 |'(' expB ')' 					{$$ = $2;}
	 | TRUE							{$$ = $1;}
	 | FALSE						{$$ = $1;}
	 | IDENTIF '[' NUMBER ']'	    {printf("soy un elemento de un vector");}
	 | IDENTIF						{printf("soy una variable");}
	 ;

expC : CHARACTER {$$ = $1;}
	 | IDENTIF '[' NUMBER ']' {printf("soy un elemento de un vector");}
	 | IDENTIF				  {printf("soy una variable");}
	 ;

%%
int powJ(int a, int b){
	int n = 1;
	int num = a;
	if (b == 0){
		return 1;
	}else{
		int i;
		for(i = 0; i<b; i++){
			num = num * a;
		}
		return num;
	}
}


char* concN (char* string, int n){
	int i = 0;
	char* concatenado = malloc(strlen(string)*n);

		for(i=0; i<n; i++){
			strcat(concatenado,string);
		}

	return concatenado;
}

void yyerror (char* category, char* mens){
	printf("Error: %s -> encontrado en la línea %i: %s\n",category, numlin, mens);
}

// Métodos generación de código
int etiqs(){

}

int main (int argc, char** argv){
	if (argc>1) yyin=fopen(argv[1],"r");	//Abrimos el Programa escrito en Jaguar
	if (argc>2) obj=fopen(argv[2],"w");		//Abrimos el Fichero resultado
	lol();
	fprintf(obj, "#include \"Q.h\"\nBEGIN\n");	//comienzo generacion de código
	yyparse();							//Ejecutamos el parser
	fprintf(obj, "END\n");				//Final generación de código.
	
	printTodo();		//Printeamos lo que quede de la tabla de simbo
	//finBloque();
	fclose(yyin);		//Cerramos el programa escrito en Jaguar
	fclose(obj);		//Cerramos el programa escrito en Jaguar
	return 0;			//Si todo termina bien, devolvemos 0
}		
