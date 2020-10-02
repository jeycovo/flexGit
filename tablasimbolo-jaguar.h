//categorias y tipos
enum categ {var, varV, func, param};
enum tipos {Int, Bool, Char, String, Void};

// Registro especial, parametro
// param -> variables que no se borran pero no hay que tenerla en cuenta para el nombramiento.
// Opcion 1 -> los parametros son registros que estan conectados al registro funcion.
// Opcion 2 -> Los Registro-función tienen usan un atributo (array) para almacenar sus parametros.
//extern current_scope;

extern struct reg {
	char *id;			//nombre del registro
	enum categ cat;		//clase
	enum tipos tip;		//tipo

	//Almacenamiento de valores - depende del tipo
	int int_type; int bool_type; char char_type; char *string_type;
	int scope;				//nivel del registro
	struct reg *sig;			//enlace al siguiente nodo
	struct reg *sigparam;			//Solo funciones - lista enlazada de parametros		
	
	int lineno;				//Número de línea donde se encontro el registro
	int func_scope;				//Indicador de si el registro pertenece a una función o no
	int tamFijado;				//0 -> El tamaño lo define los elementos metidos  -- 1 -> tamaño del vector definido en la declaración
	int tamMemVector;			//Número de espacio reservado en memoria de un vector
	int puntVector;				//Indica el número de elementos total que hay en un momento dado en el vector
	int est;				//0 -> Local 1-> Estático
	//Almacenamiento de valores - Vectores
	int *intV_type; int *boolV_type; char *charV_type; char **stringV_type; 
	//int info;
	//struct reg *padre;
	//unsigned int *dir;
} *top;

extern struct valores{
	int intValue;
	int boolValue;
	char charValue;
	char* stringValue;
};

struct reg *busq(char *id);
struct reg *ins(char *id, enum categ cat, enum tipos tip, int numlin);
void finBloque();
void dump(const char* s);
void printRegistro(struct reg *p);
void printBloque();
void printValorRegistro(struct reg *p);
void printTodo();
void isFunction();
void notFunction();
void insVectorInt(int value);
void insVectorChar(char value);
void insVectorBool(int value);
void insVectorString(char* value);
void cambiarTamVector(int t);
void asignarEspacioVector(struct reg *p, int tam);
void chequearTamVector();
int getVectorI(struct reg* r, int pos);
int getVectorB(struct reg* r, int pos);
char getVectorC(struct reg* r, int pos);
char* getVectorS(struct reg* r, int pos);
void setVectorI(struct reg* r, int pos, int value);
void setVectorB(struct reg* r, int pos, int value);
void setVectorC(struct reg* r, int pos, char value);
void setVectorS(struct reg* r, int pos, char* value);
void copiarVector(struct reg *r, struct reg *s);
struct reg *busqFunc(char *id, struct reg *f);

