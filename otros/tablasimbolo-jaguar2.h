
/* tipos de token */
enum categ {var, varV, func, bloque};
enum tipos {Int, Bool, Char, String, Void};

/* por parametro o por referencia */
#define  BY_VALUE 1
#define  BY_REFER 2

/* scope actual */
int current_scope = 0;

/* Estructura de parametros */
typedef struct Param{
	//Tipo del parametro y nombre
	int par_type;
	char param_name[MAXTOKENLEN];

	// para guardar el valor
	int ival; bool bval; char cval; char* sval;
	int passing; //value or reference
}Param;

/* Una lista de refencias linkeadas para cada variable */
typedef struct RegList{
	int lineno;
	struct RegList *next;
}RegList;

//Estructura que representa una lista de nodos
typedef struct list_t{
	char st_name[MAXTOKENLEN];
	int st_size;
	int scope;
	RefList *lines;

	// guardar valores y otra información
	int ival, bool bval; char cval; char* sval;
	
	//type
	int st_type;
	
	// for arrays (info type), for pointers (pointing type)
	// and for functions the (return type)
	int inf_type;

	//array stuff
	int *ivals; double *f_vals; char **s_vals;
	int array_size;
	
	//function parameters
	Param *parameters;
	int num_of_pars;

	//pointer to next item in the list
	struct list_t *next;
}list_t;

// Declaración de Funciones
void init_hash_table();  								// inicializar la tabla hash
unsigned int hash(char *key) 							// función hash
void insert(char *name, int len, int type, int lineno); // Insertar entrada
list_t *lookup(char *name); 							// Buscar por una entrada
list_t *lookup_scope(char *name, int scope); 			// Buscar un registro en el scope actual
void hide_scope(); 										// Ocultamos el scope actual
void incr_scope(); 										// Vamos al siguiente scope
void symtab_dump(FILE *of); 							// Dump file

