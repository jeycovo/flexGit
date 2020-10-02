$ --- Listado de pruebas de la tabla de símbolos ---
$ -- Declaración y asignacion de variables --
string z = "hejejej";
int a = 3;
char b = 'o';
bool c = true;
string d = "¡Hola Buenas!";

$ -- Declaración y Asignación de Vectores --
int [] aV = [1,2,3,4,5,6,7,8,9,10];
int [4] bV = [1,2,3,4];
int [] bV2 = [1,1,1,1];
bV [0] = 5;

bool []  cV = [true,true,false];
bool [6] dV = [true,true,true,false,true,false];
cV [1] = false;

char []  eV = ['a','b','c','d','e','f','g','h'];
char [8] fV = ['a','b','c','d','e','f','g','h'];
fV [2] = 'G';


string [] gV = ["hola", "soy", "er puto"];
string [] hV = ["Guardame", "un", "secreto", "mi nombre", "es", "horacio"];
string [10] iV = ["era","un","domingo","la", "tarde","en","los", " coches", "de", "choque"];
hV [5] = "Casildo";

$ -- Operaciones con vectores y variables--
int e = aV[1];
char g = eV[4];
string f = gV[0];

$$
string f = gV[0];
string g = gV[0] + hV[3] + hV[4] + gV[2];
bool h = iV[2] * 4;
$$
$$ --- To-Do List ---
 -> Vectores
 -> sacar un elemento de un vector
 -> modificar un elemento de un vector
 -> liberar los vectores bien
$$
