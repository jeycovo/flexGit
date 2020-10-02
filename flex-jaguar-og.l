%option noyywrap
%{
#include <stdio.h>
#define SMALLERTHAN 226
#define BIGGERTHAN 227
#define SMALLEREQUALTHAN 228
#define BIGGEREQUALTHAN	229
#define EQUIVALENT 230
#define COMMA 231
#define OPENBRACKET 233
#define CLOSEBRACKET 234
#define OPENPARENTHESIS 235
#define CLOSEPARENTHESIS 236
#define IF 237
#define ELIF 238
#define ELSE 239
#define FOR 240
#define WHILE 241
#define DOWHILE 242
#define BREAK 243
#define CONTINUE 244
#define RETURN 245
#define VOID 246
#define INT 247
#define CHAR 248
#define BOOL 249
#define STRING 250
#define PRINTF 254
#define AND 255
#define OR 256
#define NOT	257
#define NUMBER 258
#define IDENTIF 259
#define ASIGNEQUAL 260
#define OPENSQUAREBRACKETS 261
#define CLOSESQUAREBRACKETS 262
#define TRUE 263
#define FALSE 264
#define DO 265
#define POINTCOMMA 266
#define	QUOTE	267
#define DOUBLEQUOTE 268
#define CHARACTER 269

int numlin = 1;
void error(char*);
%}

letra   [a-zA-Z]
digito  [0-9]
letdig  {letra}|{digito}

%%
[-+*/^]     {return yytext[0];}
\,			{return COMMA;}
\;			{return POINTCOMMA;}
\'{letra}\'			{return CHARACTER;}
\"([^\"])*\"		{return DOUBLEQUOTE;}

\( 			{return OPENPARENTHESIS;}
\) 			{return CLOSEPARENTHESIS;}
\[			{return OPENSQUAREBRACKETS;}
\]			{return CLOSESQUAREBRACKETS;}
\{ 			{return OPENBRACKET;}
\} 			{return CLOSEBRACKET;}

=			{return ASIGNEQUAL;}
\<			{return SMALLERTHAN;}
>			{return BIGGERTHAN;}
\<=			{return SMALLEREQUALTHAN;}
\>=			{return BIGGEREQUALTHAN;}
==			{return EQUIVALENT;}
!			{return NOT;}
\n        {numlin++; printf("\n"); /* continua leyendo */}

if 			{return IF;}
elif 			{return ELIF;}
else 			{return ELSE;}
for 			{return FOR;}
while 			{return WHILE;}
do  			{return DO;}
break 			{return BREAK;}
continue 		{return CONTINUE;}
return 			{return RETURN;}
void 			{return VOID;}
int 			{return INT;}
char 			{return CHAR;}
bool 			{return BOOL;}
string 			{return STRING;}
and 			{return AND;}
or 			{return OR ;}
true			{return TRUE;}
false			{return FALSE;}
print 			{return PRINTF;}


("+"|-)?{digito}+  	{/*yylval.valor = atoi(yytext);*/ return NUMBER;}
{letra}(_|{letdig})*   	{return IDENTIF;}


[ \t]

^\$.*
\$\$([^\$])*\$\$             {/* ignora */}
\0

.                  		{char s[4]; sprintf(s, "'%c'", yytext[0]); error(s);}
<<EOF>>            {return 0; /* por defecto */}
%%

int main(int argc, char** argv) {
  int s;
  if(argc>1) yyin=fopen(argv[1],"r");
/* else yyin=stdin */
  do printf("%i ",s=yylex());
  while(s != 0);
  return 0;
}


void error(char* mens) {
  printf("Error lexico en linea %i: %s\n",numlin,mens);
}


/*
void error(char* mens, char character){
	printf("Error léxico en línea %i: %s [%c]\n",numlin,mens, character);
}
*/