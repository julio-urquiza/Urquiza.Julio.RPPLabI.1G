#include <stdio.h>
#include <stdlib.h>
#include "Validaciòn.h"
#include "lib.h"


#define AMOLADORA 10
#define MEZCLADORA 11
#define TALADRO 12

#define ALQUILADO 1
#define FINALIZADO 0

#define TAMC 20
#define TAMA 20

int menu(void);

int main()
{
    int seguir=1;
    int idClientes=100;
    int idAlquiler=1000;
    eCliente clientes[TAMC];
    eAlquiler alquileres[TAMA];

    inicializarClientes(clientes,TAMC);
    inicializarAquileres(alquileres,TAMA);


    do
    {
        switch(menu())
        {
        case 1://alta cliente
            system("cls");
            altaCliente(clientes,TAMC,&idClientes);
            break;

        case 2://modificar cliente
            system("cls");
            modificarCliente(clientes,TAMC);
            break;

        case 3: //baja cliente
            system("cls");
            darDeBajaCliente(clientes,TAMC);
            break;

        case 4://Nuevo alquiler
            system("cls");
            altaAlquiler(&idAlquiler,alquileres,TAMA,clientes,TAMC);
            break;

        case 5://Fin del Alquiler
            system("cls");
            FinalizarAlquiler(alquileres,TAMA,clientes,TAMC);
            break;

        case 6://informar
            system("cls");
            mostrarAlquileres(alquileres,TAMA,clientes,TAMC);
            personaConMasAlquileres(alquileres,TAMA,clientes,TAMC);
            tiempoPromedioDeALqulerDeLosEquipos(alquileres,TAMA,clientes,TAMC);
            break;

        case 7://salir
            system("cls");
            seguir=0;
            break;

        default:
            system("cls");
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }
    while(seguir);
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("Lista de opciones\n");
    printf("1.Alta cliente\n");
    printf("2.Modificar cliente\n");
    printf("3.Baja cliente\n");
    printf("4.Nuevo alquiler\n");
    printf("5.Fin del Alquiler\n");
    printf("6.Informar\n");
    printf("7.Salir\n");
    pedirNumeroSinLimite(&opcion,"Elija una de las opciones: ","ERROR,");
    return opcion;
}
