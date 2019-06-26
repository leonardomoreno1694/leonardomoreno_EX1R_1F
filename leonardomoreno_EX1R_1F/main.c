#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "socios.h"


#define CANTIDAD_SOCIOS  10
#define CANTIDAD_LIBROS 5
#define CANTIDAD_AUTORES 5

int main()
{   //ARRAYS DE ESTRUCTURAS
    e_Socios arraySocios[CANTIDAD_SOCIOS];
    e_Libros arrayLibros[CANTIDAD_LIBROS];
    e_Prestamos arrayPrestamo[CANTIDAD_SOCIOS*CANTIDAD_LIBROS];
    //INIT ESPACIOS LIBRES
    inicializarArraySocios(arraySocios,CANTIDAD_SOCIOS);
    inicializarEstadoPrestamo(arrayPrestamo,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
    //HARDCODEO LIBROS Y AUTORES
    hardcodearLibros(arrayLibros,CANTIDAD_LIBROS);
    // VARS A USAR
    int opcion;
    int opcion2;
    int idIncrementalSocios = 1;
    int idIncrementalPrestamo = 1;

    //HARDCODEOS PARA TESTEAR
    hardcodearSocios(arraySocios,&idIncrementalSocios); idIncrementalSocios = 6;
    hardcodearPrestamosAsocios(arrayPrestamo,&idIncrementalPrestamo); idIncrementalPrestamo = 6;

//INICIO DEL PROGRAMA
do
{   system("cls");
    printf("\n\n:::::::::::: EXAMEN 1 : RECUPERATORIO :::::::::::::\n\n");
    menuPrincipal(&opcion); //MENU PRINCIPAL
    switch(opcion)
    {
        case 1:
           do
            {   system("cls");
                printf("\n\n:::::::::::: MENU SOCIOS :::::::::::::\n\n");
                menuSocios(&opcion2); //CASE 1 : ABM SOCIOS
                switch(opcion2)
                {
                case 1:
                    altaSocio(arraySocios,CANTIDAD_SOCIOS,idIncrementalSocios);
                    ++idIncrementalSocios;
                    break;
                case 2:
                    bajaSocio(arraySocios,CANTIDAD_SOCIOS);
                    break;
                case 3:
                    modificacionSocio(arraySocios,CANTIDAD_SOCIOS);
                    break;
                case 4:
                    menuListaOrdenada(arraySocios,CANTIDAD_SOCIOS);
                    break;
                }
            }while(opcion2 != 5);
            break;
        case 2:
            system("cls");
            mostrarLibros(arrayLibros,CANTIDAD_LIBROS);
            system("pause");
            break;
        case 3://MENU DE PRESTAMOS
            system("cls");
            menuPrestamo(&opcion2);
            switch(opcion2)
            {
            case 1:
                altaDePrestamo(arrayPrestamo,arraySocios,arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS,idIncrementalPrestamo);
                idIncrementalPrestamo++;
                break;
            }
            break;


        case 4:
            system("cls");
            menuInformes(&opcion2); //MENU DE INFORMES
            switch(opcion2)
            {
            case 1:
                listarTotalGeneralYpromedio(arrayPrestamo,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                system("pause");
                break;
            case 2:
                printf("\n No entendi la consigna,todos los demas estan hechos\n ");
                system("pause");
                break;
            case 3:
                listarPrestamosActivos(arraySocios,arrayPrestamo,arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS);
                system("pause");
                break;
            case 4:
                listarPrestamosActivos(arraySocios,arrayPrestamo,arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS);
                system("pause");
                break;
            case 5:
                listarLibroMenosSolicidato(arrayLibros,arrayPrestamo,CANTIDAD_LIBROS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                system("pause");
                break;
            case 6:
                listarSocioMayorPrestamos(arraySocios,arrayPrestamo,CANTIDAD_SOCIOS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                system("pause");
                break;
            case 7:
                listarLibrosPrestamoMasFecha(arrayPrestamo,arrayLibros,CANTIDAD_LIBROS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                system("pause");
                break;
            case 8:
                listarSocioPrestamoMasFecha(arrayPrestamo,arraySocios,CANTIDAD_SOCIOS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                system("pause");
                break;
            case 9:
                ordenarLibros(arrayLibros,CANTIDAD_LIBROS);
                mostrarLibros(arrayLibros,CANTIDAD_LIBROS);
                system("pause");
                break;
            case 10:
                ordenarApellidosDescendente(arraySocios,CANTIDAD_SOCIOS);
                mostrarListaSocios(arraySocios,CANTIDAD_SOCIOS,-1);
                system("pause");
                break;
            }
            break;
    }
}while(opcion != 5);
return 0;
}

