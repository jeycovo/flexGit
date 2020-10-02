#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolo-jaguar2.h"

char *inicat = "TGLR";
struct reg *top = NULL;


//Insertar un registro
void ins(char *id, enum categ cat, enum categ tipo, struct reg *tp){
	if (busq(id)!=NULL) yyerror("-1: nombre ya definido");
	struct reg *p = (struct reg *)malloc(sizeof(struct reg));
	p->id=id; p->cat=cat; p->tip=tp;
	p->sig = top;
	top = p;
}

//Buscar un registro c
struct reg *busq(char *id){
	struct reg *p = busq(id);
	if (p! = NULL && p->cat==cat) return p; else return NULL;
}



void finbloq(){
	printf(" DUMP: %s\n", s);
	struct reg *p = top;
	while (p!=NULL){
		printf("0x%x %c %s %s\n", (int)p, inicat[p->cat], p->id, p->tip==NULL?".":p->tip->id); p=p->sig;
	}
}






