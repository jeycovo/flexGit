#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

enum categ {UNDEF, VAR, ARRAY, FUNCTION, METHOD};
enum tipos {UNDEF_TYPE, INT_TYPE, BOOL_TYPE, CHAR_TYPE, STRING_TYPE};

struct reg {
	enum categ clase;
	enum tipos tipo;
} *top;

int main( int argc, const char* argv[]){
	struct reg *p = (struct reg *)malloc(sizeof(struct reg));
	p->clase=VAR;
	p->tipo=INT_TYPE;
	printf("clase: %i - tipo: %i", p->clase, p->tipo);
}

