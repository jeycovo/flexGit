%option noyywrap
%{
#include "bison-jaguar.tab.h"
#include <string.h>

int numlin = 1;
//void error(char*);
char* subcadena(char* string, int a, int b);
%}

letra   [a-zA-Z]
digito  [0-9]
letdig  {letra}|{digito}

%%
[-+*/^=<>\(\)\[\]\{\},\;]      {return yytext[0];}
\'{letra}\'		{yylval.caracter = yytext[1]; return CHARACTER;}
\"[^\"]*\"		{yylval.cadena = subcadena(yytext,1, strlen(yytext)-2); return STRINGLITERAL;}

\<=			{return SMALLEREQUALTHAN;}
\>=			{return BIGGEREQUALTHAN;}
==			{return EQUIVALENT;}
!			{return NOT;}
!=			{return EQUIVALENTNOT;}		
\n        	{numlin++;/* continua leyendo */}

if 			{return IFCOND;}
elif 		{return ELIF;}
else 		{return ELSECOND;}
for 		{return FOR;}
while 		{return WHILELOOP;}
do  		{return DOLOOP;}
break 		{return BREAK;}
continue 	{return CONTINUE;}
return 		{return RETURN;}
void 		{return VOID;}
int 		{return INT;}
char 		{return CHAR;}
bool 		{return BOOL;}
string 		{return STRING;}
AND			{return AND;}
OR			{return OR ;}
true		{yylval.booleano = 1; return TRUE;}
false		{yylval.booleano = 0; return FALSE;}
print 		{return PRINTF;}
\<<			{return PRINTFARROW;}
{digito}+  				{yylval.entero = atoi(yytext); return NUMBER;}
{letra}(_|{letdig})*   	{yylval.cadena = strdup(yytext) ;return IDENTIF;}

[ \t]+	
\$.*	
\$\$([^\$])*\$\$             {/* ignora */}
\0

{digito}+(_|{letdig})* |
.                  {char s[4]; sprintf(s, "'%c'", yytext[0]); yyerror("Léxico","");}
<<EOF>>            {return 0; /* por defecto */}
%%
/*
void error(char* mens) {
  printf("Error lexico en linea %i: %s\n",numlin,mens);
}
*/

char* subcadena(char* string, int a, int b){
	char* resultado = malloc(strlen(string)-2);
	strncpy(resultado, string+a, b);
    return resultado;
}

/*
\( 			{return OPENPARENTHESIS;}
\) 			{return CLOSEPARENTHESIS;}
\[			{return OPENSQUAREBRACKETS;}
\]			{return CLOSESQUAREBRACKETS;}
\{ 			{return OPENBRACKET;}
\} 			{return CLOSEBRACKET;}
\,			{return COMMA;}
\;			{return POINTCOMMA;}
*/

/*
int main(int argc, char** argv) {
  int s;
  if(argc>1) yyin=fopen(argv[1],"r");
 // else yyin=stdin
  do printf("%i ",s=yylex());
  while(s != 0);
  return 0;
}
*/

//("+"|-)?{digito}+  	{yylval = atoi(yytext); return NUMBER;}

