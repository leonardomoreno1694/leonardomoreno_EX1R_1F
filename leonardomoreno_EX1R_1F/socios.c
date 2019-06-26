#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "socios.h"

#define LIBRE -1
#define OCUPADO 1

//**INICIALIZADORES**//

/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArraySocios(e_Socios str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;

    }
}

void inicializarEstadoPrestamo(e_Prestamos str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;

    }
}

//**HARDCODE**//

/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/

void hardcodearLibros(e_Libros str[],int cantidadElementos)
{
    int i;
    int id[5]={1,2,3,4,5};
    int idAutor[5]={1,2,3,4,5};
    char libro[5][50]={"El visitante","Mysery","Cuentos Macabros","The Feeding","Sleepy Hollow"};
    char autor[5][50]={"Stephen King","Stephen King","Edgar Allan Poe","Sutter Cane","Washington Irving"};

    for(i=0; i<5; i++)
    {
        str[i].idLibro = id[i];
        str[i].idAutor = idAutor[i];
        strcpy(str[i].tituloDelLibro,libro[i]);
        strcpy(str[i].autor.nombreAutor,autor[i]);
    }
}
void hardcodearSocios(e_Socios str[],int *idIncremental)
{
    int i;
    int estado[]={1,1,1,1,1};
    int idSocio[]={1,2,3,4,5};
    char apellido[][50]={"Repeto","Gomez","Posman","Felice","Fisherman"};
    char nombre[][50]={"Pedro","Lucila","Fabio","Nahuel","Jhonatan"};
    int dia[]={22,14,11,22,8};
    int mes[]={3,4,7,6,5};
    int anio[]={2001,2012,2011,2001,2015};
    char eMail[][50]={"PedroRepeto@hotmail.com","LuGomez@hotmail.com","Fabiofabio@hotmail.com","Nananahuel@hotmail.com","Jhony@hotmail.com"};
    char telefono[][50]={"45542223","1566781234","44445555","1144522333","41235678"};
    char sexo[]={'M','F','M','M','M','F'};
    for(i=0; i<5; i++)
    {
        str[i].idSocio = idSocio[i];
        str[i].estado = estado[i];
        strcpy(str[i].nombre,nombre[i]);
        strcpy(str[i].apellido,apellido[i]);
        strcpy(str[i].eMail,eMail[i]);
        str[i].fechaDelSocio.dia = dia[i];
        str[i].fechaDelSocio.mes = mes[i];
        str[i].fechaDelSocio.anio = anio[i];
        str[i].sexo = sexo[i];
        strcpy(str[i].telefono,telefono);
        idIncremental = &idIncremental + 1;
    }
}
/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearPrestamosAsocios(e_Prestamos str[],int *idIncremental)
{
    int i;
    int id[5]={1,2,3,4,5};
    int idLibro[]={1,2,3,4,5};
    int idSocio[]={1,2,3,4,5};
    int dia[]={7,7,7,6,6};
    int mes[]={5,5,5,5,5};
    int anio[]={2019,2019,2019,2019,2019};

    for(i=0; i<5; i++)
    {
        str[i].idLibro = idLibro[i];
        str[i].idSocio = idSocio[i];
        str[i].fechaPrestamo.dia = dia[i];
        str[i].fechaPrestamo.mes = mes[i];
        str[i].fechaPrestamo.anio = anio[i];
        str[i].idPrestamo = id[i];
        str[i].estado = 1;
        *++idIncremental;
    }
}



///***-------------***///


int buscarPosicionPrestamo(e_Prestamos str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}


///***MENUES***///

void menuSocios(int *resultado)
{
    char aux[15];
    getNumber("\n1:ALTA NUEVO SOCIO\n\n2:BAJA DE UN SOCIO\n\n3:MODIFICAR DATOS DE UN SOCIO\n\n4:LISTAR SOCIOS\n\n5:VOLVER A MENU PRINCIPAL ","OP ERROR ",1,5,1,2,aux);
    *resultado = atoi(aux);
}
void menuPrestamo(int *resultado)
{
    char aux[15];
    getNumber("\n1:DAR ALTA DE UN PRESTAMO\n\n2:LISTAR LOS PRESTAMOS ACTIVOS\n\n3:VOLVER A MENU PRINCIPAL\n ","opcion incorrecta: ",1,3,1,2,aux);
    *resultado = atoi(aux);
}


void menuModificacion(int *resultado)
{
    char aux[15];
    getNumber("\nMODIFICAR:\n 1:NOMBRE Y APELLIDO\n2:SEXO\n3:TELEFONO\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);
}


void menuPrincipal(int *resultado)
{
    char aux[15];
    getNumber("\n1:MENU SOCIOS\n\n2:LISTADO DE LIBROS Y AUTORES\n\n3:MENU PRESTAMOS\n\n4:MENU DE INFORMES\n\n5:TERMINAR PROGRAMA\n\n ","OP. ERROR: ",1,5,1,2,aux);
    *resultado = atoi(aux);
}

void menuListaOrdenada(e_Socios str[],int cantidadElementos)
{
    char auxiliar[15];
    int opcion2;
    getNumber("\nOrdenar por 1:NOMBRE o 2:APELLIDO: ","opcion incorrecta",1,2,1,2,auxiliar);
                    opcion2 = atoi(auxiliar);
                    switch(opcion2)
                    {
                      case 1:
                        ordenarNombres(str,cantidadElementos);
                        mostrarListaSocios(str,cantidadElementos,-1);
                        break;
                      case 2:
                        ordenarApellidos(str,cantidadElementos);
                        mostrarListaSocios(str,cantidadElementos,-1);
                        break;
                    }
}
void menuInformes(int *resultado)
{
    char aux[15];

    printf("\n:::::::::::: MENU DE INFORMES ::::::::::\n\n\n");

    printf("\n1:TOTAL GENERAL Y PROMEDIO DIARIO\n\n");

    printf("2:CANTIDAD DE DIAS CUYA SOLICITUD A PRESTAMO NO SUPERAN EL PROMEDIO DEL ITEM ANTERIOR\n\n");

    printf("3:SOCIOS QUE SOLICITARON EL PRESTAMO DE UN LIBRO DETERMINADO\n\n");

    printf("4:LIBROS QUE FUERON SOLICITADIOS A PRESTAMO POR UN SOCIO DETERMINADO\n\n");

    printf("5:LIBRO MENOS SOLICITADO EN PRESTAMO\n\n");

    printf("6:SOCIO/OS QUE REALIZARON MAS SOLICITUDES DE PRESTAMO\n\n");

    printf("7:LIBROS QUE SOLICITARON  EN FECHA UNA DETERMINADA\n\n");

    printf("8:SOCIOS QUE REALIAZARON AL MENOS UNA SOLICITUD A PRESTAMO EN UNA FECHA DETERMINADA\n\n");

    printf("9:LIBROS ORDENADOS POR TITULO(DESCENDENTE)\n\n");

    getNumber("10:SOCIOS ORDENADOS POR APELLIDO: ",
              "caracter incorrecto",1,10,1,3,aux);
    *resultado = atoi(aux);
}

/**SOCIOS**/

int buscarEspacioLibreSocios(e_Socios str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

int buscarDatoValidoSocios(e_Socios str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].idSocio == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

void altaSocio(e_Socios str[],int cantidadElementos,int idIncremental)
{
    int espacioLibre;
    char auxiliar[51];
    char auxSexo;
    espacioLibre = buscarEspacioLibreSocios(str,cantidadElementos,-1);

    if(espacioLibre != -1)
    {

        getName("Ingrese el nombre: ","caracteres incorrecto",1,51,str[espacioLibre].nombre);
        getName("Ingrese apellido: ","caracteres incorrecto",1,51,str[espacioLibre].apellido);
        getSexo("Ingrese el sexo M o F: ","caracter incorrecto",&auxSexo);
        fflush(stdin);
        getNumber("Ingrese telefono(minimo 8 caracteres): ","telefono incorrecto",
                  1,999999999,8,11,str[espacioLibre].telefono);
        getEmail("Ingrese eMail: "," eMail incorrecto",6,20,str[espacioLibre].eMail);

        getNumber("Dia: ","dia incorrecto",1,31,1,10,auxiliar);
        str[espacioLibre].fechaDelSocio.dia = atoi(auxiliar);
        getNumber("Mes: ","mes incorrecto",1,12,1,10,auxiliar);
        str[espacioLibre].fechaDelSocio.mes = atoi(auxiliar);
        getNumber("(2000 - 2019)Anio: ","anio incorrecto",2000,2019,1,20,auxiliar);
        str[espacioLibre].fechaDelSocio.anio = atoi(auxiliar);
        str[espacioLibre].sexo = auxSexo;
        str[espacioLibre].idSocio = idIncremental;
        str[espacioLibre].estado = 1;

        printf("\nALTA EXITOSA");
    }
    else
    {
        printf("No encontro lugar");
    }
}


void bajaSocio(e_Socios str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarEspacioLibreSocios(str,5,1);
   if(espacioLibre != -1)
   {
    mostrarListaSocios(str,cantidadElementos,-1);
    getNumber("Que id desea dar de bajaSocio: ","caracter incorrecto",1,1000,1,cantidadElementos,auxDato);
    espacioLibre = buscarDatoValidoSocios(str,cantidadElementos,atoi(auxDato));

        if(espacioLibre != -1)
        {
            str[espacioLibre].estado = -1;
            printf("\nbajaSocio exitosa");
        }
        else
        {
            printf("\nEl dato no existe");
        }
   }
   else
   {
       printf("\nno hay datos cargados");
   }
}

void modificacionSocio(e_Socios str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarEspacioLibreSocios(str,5,1);
    int opcion;
    if(espacioLibre != -1)
    {
        mostrarListaSocios(str,cantidadElementos,-1);
        getNumber("Ingrese la id a modificar: ","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarDatoValidoSocios(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            menuModificacion(&opcion);
            do
            {
            switch(opcion)
            {
            case 1:
                getName("\nIngrese nuevo nombre:  ","error",1,51,str[espacioLibre].nombre);
                getName("\nIngrese nuevo apellido:  ","error",1,51,str[espacioLibre].apellido);
                printf("\nMODIFICACION EXITOSA");
                break;
            case 2:
                getSexo("\nIngrese el nuevo sexo M o F: ","dato incorrecto",str[espacioLibre].sexo);
                printf("\nMODIFICACION EXITOSA");
                break;
            case 3:
                getName("\nIngrese el nuevo telefono: ","telefono incorrecto",9,10,str[espacioLibre].telefono);
                printf("\nMODIFICACION EXITOSA");
                break;
            }
            break;
            }while(opcion != 4);

        }
        else
        {
            printf("El dato no existe");
        }
    }
    else
    {
        printf("no hay datos cargados");
    }
}

void mostrarListaSocios(e_Socios str[],int cantidadElementos,int valorLibre)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != valorLibre)
        {
           printf("\nID:%d\n NOMBRE:%s APELLIDO:%s\n SEXO:%c\n TELEFONO:%s E-MAIL:%s\n",str[i].idSocio,str[i].nombre,str[i].apellido,str[i].sexo,str[i].telefono,str[i].eMail);
           printf(" dia: %d mes: %d anio: %d\n\n",str[i].fechaDelSocio.dia,str[i].fechaDelSocio.mes,str[i].fechaDelSocio.anio);


        }
    }
    system("pause");
}

/**ORDENAMIENTOS Y LISTADOS**/

void mostrarLibros(e_Libros str[],int cantidadElementos)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        printf("\nID: %d\nTITULO: %s \nAUTOR: %s\n\n",str[i].idLibro,str[i].tituloDelLibro,str[i].autor.nombreAutor);
    }
}

void listarPrestamosActivos(e_Socios str[],e_Prestamos str3[],e_Libros str2[],int cantidadSocios,int cantidadLibros)
{
    int i, j, k;

    for( i = 0; i < cantidadLibros; i++)
    {
        for( j = 0; j < (cantidadSocios * cantidadLibros); j++ )
        {
            if( str2[i].idLibro == str3[j].idLibro && str3[j].estado == 1)
            {
                for( k = 0; k<cantidadSocios;k++)
                {
                    if( str[k].estado != -1 && str3[j].idSocio == str[k].idSocio )
                    {
                        printf("\nID del Prestamo:%d  %d %s %s libro: %s autor: %s", str3[j].idPrestamo,str[k].idSocio,
                               str[k].nombre,str[k].apellido,str2[i].tituloDelLibro,str2[i].autor.nombreAutor);
                    }
                }
            }
        }
    }
}


void ordenarApellidos(e_Socios str[],int cantidadElementos)
{
    int i,j;
    e_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(str[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(str[j].idSocio == -1)
                        {
                            continue;
                        }
                        if(strcmp(str[i].apellido,str[j].apellido) > 0)
                        {
                            auxSocios = str[j];
                            str[j] = str[i];
                            str[i] = auxSocios;

                        }
                    }
                }
}


void ordenarNombres(e_Socios str[],int cantidadElementos)
{
    int i,j;
    e_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(str[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(str[j].idSocio == -1)
                        {
                            continue;
                        }
                        if(strcmp(str[i].nombre,str[j].nombre) > 0)
                        {
                            auxSocios = str[j];
                            str[j] = str[i];
                            str[i] = auxSocios;

                        }
                    }
                }
}

void altaDePrestamo(e_Prestamos str[],e_Socios str2[],e_Libros str3[],int cantidadSocios,int cantidadLibros
                    ,int idIncremental)
{
    int espacioLibre;

    char auxiliar[51];
    int i;
    espacioLibre = buscarPosicionPrestamo(str,cantidadSocios*cantidadLibros,-1);
    i = buscarEspacioLibreSocios(str2,cantidadSocios,1);
    if(espacioLibre != -1 && i != -1)
    {
        mostrarLibros(str3,cantidadLibros);
        getNumber("\nSELECCIONE ID DEL LIBRO ","ID INCORRECTA",1,cantidadLibros,1,10,auxiliar);
        str[espacioLibre].idLibro = atoi(auxiliar);
        mostrarListaSocios(str2,cantidadSocios,-1);
        getNumber("\nSELECCIONE ID DEL SOCIO: ","caracter incorrecto",1,1000,1,4,auxiliar);
        i = buscarDatoValidoSocios(str2,cantidadSocios,atoi(auxiliar));
        while(i == -1)
        {
            getNumber("\nDato Inexistente\nSeleccione el socio: ","caracter incorrecto",1,1000,1,4,auxiliar);
            i = buscarDatoValidoSocios(str2,cantidadSocios,atoi(auxiliar));
        }
        str[espacioLibre].idSocio = atoi(auxiliar);
        str[espacioLibre].idPrestamo = idIncremental;
        str[espacioLibre].estado = 1;



        printf("\n                                          ALTA EXITOSA\n\n");
        system("pause");
    }
    else
    {
        printf("NO HAY SOCIOS CARGADOS");
    }
}

void listarSocioMayorPrestamos(e_Socios str[],e_Prestamos str2[],int cantidadSocios,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadSocios];
    for(i=0;i<cantidadSocios;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadSocios];

    int aux;
    for( i = 0; i < cantidadPrestamos; i++)
    {
        for( j = 0; j<cantidadSocios; j++ )
        {
            if(str[j].estado != -1 && str[j].idSocio == str2[i].idSocio)
            {
                buscarMayor[j]++;
                posicion[j] = j;
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadSocios-1;i++)
        {
            for(j=i+1;j<cantidadSocios;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;

                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }
        printf("\nLa persona con mayor prestamos es: %s %s",str[posicion[0]].nombre,str[posicion[0]].apellido);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}
void listarLibroMasSolicidato(e_Libros str[],e_Prestamos str2[],int cantidadLibros,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadLibros];
    for(i=0;i<cantidadLibros;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadLibros];

    int aux;
    for( i = 0; i < cantidadPrestamos; i++)
    {
        for( j = 0; j<cantidadLibros; j++ )
        {
            if(str[j].idLibro == str2[i].idLibro)
            {
                buscarMayor[j]++;
                posicion[j] = j;
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadLibros-1;i++)
        {
            for(j=i+1;j<cantidadLibros;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;

                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }
        printf("\nEl libro mas solicitado es: %s autor: %s",str[posicion[0]].tituloDelLibro,
               str[posicion[0]].autor.nombreAutor);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}

void listarTotalGeneralYpromedio(e_Prestamos str[],int cantidadPrestamos)
{
    int i;
    int acumulador = 0;

    for( i = 0; i<cantidadPrestamos;i++)
    {
        if(str[i].estado != -1)
        {
            acumulador++;
        }
    }
    printf("\nLa cantidad de prestamos es: %d\n",acumulador);

}


void listarLibroMenosSolicidato(e_Libros str[],e_Prestamos str2[],int cantidadLibros,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadLibros];
    for(i=0;i<cantidadLibros;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadLibros];

    int aux;
    for( i = 0; i < cantidadPrestamos; i++)
    {
        for( j = 0; j<cantidadLibros; j++ )
        {
            if(str[j].idLibro == str2[i].idLibro)
            {
                buscarMayor[j]++;
                posicion[j] = j;
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadLibros-1;i++)
        {
            for(j=i+1;j<cantidadLibros;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;

                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }

        printf("\nEl libro menos solicitado es: %s autor: %s",str[posicion[cantidadLibros-1]].tituloDelLibro,
               str[posicion[cantidadLibros-1]].autor.nombreAutor);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}

void listarLibrosPrestamoMasFecha(e_Prestamos str[],e_Libros str2[],
                                  int cantidadLibros,int cantidadPrestamos)
{
    int i, j;

    for( i = 0; i < cantidadLibros; i++)
    {
        for( j = 0; j < cantidadPrestamos; j++ )
        {
            if( str2[i].idLibro == str[j].idLibro && str[j].estado != -1)
            {
                printf("\nLibro en prestamo : %s %s fecha de prestamo: ",
                       str2[i].tituloDelLibro,str2[i].autor.nombreAutor);
                printf("dia: %d mes: %d anio: %d",str[j].fechaPrestamo.dia,
                       str[j].fechaPrestamo.mes,str[j].fechaPrestamo.anio);
            }
        }
    }
}

void ordenarLibros(e_Libros str[],int cantidadLibros)
{
    int i,j;
    e_Libros auxLibros;
    for(i=0; i < cantidadLibros - 1; i++)
    {
        for(j=i+1; j < cantidadLibros; j++)
        {
            if(strcmp(str[i].tituloDelLibro,str[j].tituloDelLibro) < 0)
            {
                auxLibros = str[j];
                str[j] = str[i];
                str[i] = auxLibros;
            }
        }
    }
}

void listarSocioPrestamoMasFecha(e_Prestamos str[],e_Socios str2[],
                                  int cantidadSocios,int cantidadPrestamos)
{
    int i, j;

    for( i = 0; i < cantidadSocios; i++)
    {
        if(str[i].estado != -1)
        {
            for( j = 0; j < cantidadPrestamos; j++ )
            {
                if( str2[i].idSocio == str[j].idSocio)
                {
                    printf("\nID %d nombre: %s %s fecha de prestamo: ",
                       str2[i].idSocio,str2[i].nombre,str2[i].apellido);
                    printf("dia: %d mes: %d anio: %d",str[j].fechaPrestamo.dia,
                       str[j].fechaPrestamo.mes,str[j].fechaPrestamo.anio);
                }
            }
        }
    }
}

void ordenarApellidosDescendente(e_Socios str[],int cantidadElementos)
{
    int i,j;
    e_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
    {
        if(str[i].estado == -1)
        {
            continue;
        }
        for(j=i+1; j < cantidadElementos; j++)
        {
            if(str[j].idSocio == -1)
            {
                continue;
            }
            if(strcmp(str[i].apellido,str[j].apellido) < 0)
            {
                auxSocios = str[j];
                str[j] = str[i];
                str[i] = auxSocios;
            }
        }
    }
}
