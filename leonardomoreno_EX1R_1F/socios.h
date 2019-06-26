
/**ESTRUCTURAS**/

typedef struct
{
  int dia;
  int mes;
  int anio;

}e_Fecha;
typedef struct
{
   int idAutor;
   char nombreAutor[61];

}e_Autores;

typedef struct
{
    int idLibro;
    char tituloDelLibro[61];
    int idAutor;
    e_Autores autor;

}e_Libros;

typedef struct
{
   int idSocio;
   int estado;
   char nombre[51];
   char apellido[51];
   char sexo;
   char telefono[51];
   char eMail[51];

    e_Fecha fechaDelSocio;
}e_Socios;

typedef struct
{
   int idPrestamo;
   int idLibro;
   int idSocio;
   int estado;

   e_Fecha fechaPrestamo;

}e_Prestamos;


/**INICIANIZADORES**/

void inicializarEstadoPrestamo(e_Prestamos str[],int cantidadElementos);
void inicializarArraySocios(e_Socios str[],int cantidadElementos);

/**HARDCODE**/

void hardcodearLibros(e_Libros str[],int cantidadElementos);
void hardcodearSocios(e_Socios str[],int *idIncremental);
void hardcodearPrestamosAsocios(e_Prestamos str[],int *idIncremental);

/**MENUES**/

void menuPrincipal(int *resultado);
void menuSocios(int *resultado);
void menuModificacion(int *resultado);
void menuListaOrdenada(e_Socios str[],int cantidadElementos);
void menuPrestamo(int *resultado);
void menuInformes(int *resultado);

/**SOCIOS**/

int buscarEspacioLibreSocios(e_Socios str[],int cantidadElementos,int valor);
void altaSocio(e_Socios str[],int cantidadElementos,int idIncremental);
void bajaSocio(e_Socios str[],int cantidadElementos);
void modificacionSocio(e_Socios str[],int cantidadElementos);
void mostrarListaSocios(e_Socios str[],int cantidadElementos,int valorOcupado);
int buscarDatoValidoSocios(e_Socios str[],int cantidadElementos,int valor);
void ordenarApellidos(e_Socios str[],int cantidadElementos);
void ordenarNombres(e_Socios str[],int cantidadElementos);
void listarPrestamosActivos(e_Socios str[],e_Prestamos str3[],e_Libros str2[],int cantidadSocios,int cantidadLibros);
void listarSocioMayorPrestamos(e_Socios str[],e_Prestamos str2[],int cantidadSocios,int cantidadPrestamos);
void ordenarApellidosDescendente(e_Socios str[],int cantidadElementos);

/**LIBROS**/

void mostrarLibros(e_Libros str[],int cantidadElementos);
void listarLibroMasSolicidato(e_Libros str[],e_Prestamos str2[],int cantidadLibros,int cantidadPrestamos);
void listarLibroMenosSolicidato(e_Libros str[],e_Prestamos str2[],int cantidadLibros,int cantidadPrestamos);
void listarLibroMenosSolicidato(e_Libros str[],e_Prestamos str2[],int cantidadLibros,int cantidadPrestamos);

/**PRESTAMOS**/

int buscarPosicionPrestamo(e_Prestamos str[],int cantidadElementos,int valor);
void altaDePrestamo(e_Prestamos str[],e_Socios str2[],e_Libros str3[],int cantidadSocios,int cantidadLibro,int idIncremental);
void listarTotalGeneralYpromedio(e_Prestamos str[],int cantidadPrestamos);
void listarLibrosPrestamoMasFecha(e_Prestamos str[],e_Libros str2[],int cantidadLibros,int cantidadPrestamos);void ordenarLibros(e_Libros str[],int cantidadLibros);
void listarSocioPrestamoMasFecha(e_Prestamos str[],e_Socios str2[],int cantidadSocios,int cantidadPrestamos);


