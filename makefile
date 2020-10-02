
 makeStart: flex-jaguar.l bison-jaguar.y tablasimbolo-jaguar.c tablasimbolo-jaguar.h
	flex flex-jaguar.l 
	bison -v -d bison-jaguar.y
	gcc -o milex tablasimbolo-jaguar.c lex.yy.c bison-jaguar.tab.c  Qlib.h
	./milex ejemploMilex.j milex.q.c
	gcc IQ.o Qlib.c -o IQ
	./IQ milex.q.c

#cat ejemploMilex.txt
#all: milex $(F)
#	./milex $(F)

#clean:
#	rm -f lex.yy.c bison-jaguar.tab.* milex

#milex: bison-jaguar.tab.c lex.yy.c
#	gcc -o milex tablasimbolo-jaguar.c bison-jaguar.tab.c lex.yy.c

#lex.yy.c: flex-jaguar.l bison-jaguar.tab.h
#	flex flex-jaguar.l 

#bison-jaguar.tab.c: bison-jaguar.y tablasimbolo-jaguar.c tablasimbolo-jaguar.h
#	bison -d bison-jaguar.y

