#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "Validaciòn.h"

int altaCliente(eCliente* clientes,int tamc,int* idCliente)
{
    int retorno=0;
    int indice;
    char nombre[21];
    char apellido[21];
    char dni[10];
    if(clientes!=NULL && tamc>0 && idCliente!=NULL)
    {
        if(buscarPrimerClienteLibre(clientes,tamc,&indice))
        {
            pedirTexto(nombre,"Ingrese el nombre: ","ERROR, ");
            pedirTexto(apellido,"Ingrese el apellido: ","ERROR, ");
            pedirTextoConNumeros(dni,"Ingrese el DNI: ","ERROR, ");
            if(setCliente(&clientes[indice],*idCliente,nombre,apellido,dni))
            {
                printf("Cliente cargado con exito\n");
                *idCliente=*idCliente+1;
                retorno=1;
            }
        }
        else
        {
            printf("No hay Espacio para mas Cliente\n");
        }
    }
    return retorno;
}

int modificarCliente(eCliente* clientes,int tamc)
{
    int retorno=0;
    int indice;
    int idCliente;
    char nombre[21];
    char apellido[21];
    char dni[10];
    if(clientes!=NULL && tamc>0)
    {
        if(buscarSiHayClientes(clientes,tamc))
        {
            mostrarClientes(clientes,tamc);
            pedirNumeroSinLimite(&idCliente,"Ingrese el codigo del cliente que desea modificar: ","ERROR, ");
            if(buscarUnClientePorId(clientes,tamc,idCliente,&indice))
            {
                system("cls");
                getCliente(clientes[indice],&idCliente,nombre,apellido,dni);
                printf("ID: %d\n",idCliente);
                printf("DNI: %s\n",dni);
                printf("1.nombre: %s\n",nombre);
                printf("2.apellido: %s\n",apellido);
                switch(opcionSwitch("Elija Una opcion para modificarla: ","ERROR, ",1,2))
                {
                case 1:
                    pedirTexto(nombre,"Ingrese el nombre: ","ERROR, ");
                    break;
                case 2:
                    pedirTexto(apellido,"Ingrese el apellido: ","ERROR, ");
                    break;
                }


                if(setCliente(&clientes[indice],idCliente,nombre,apellido,dni))
                {
                    printf("Cliente cargado con exito\n");
                    retorno=1;
                }
            }
            else
            {
                printf("El Cliente no exite\n");
            }
        }
        else
        {
            printf("No hay clientes que modificar\n");
        }
    }
    return retorno;
}

int darDeBajaCliente(eCliente* clientes,int tamc)
{
    int retorno=0;
    int indice;
    int idCliente;
    if(clientes!=NULL && tamc>0)
    {
       if(buscarSiHayClientes(clientes,tamc))
        {
            mostrarClientes(clientes,tamc);
            pedirNumeroSinLimite(&idCliente,"Ingrese el codigo del cliente que desea dar de baja: ","ERROR, ");
            if(buscarUnClientePorId(clientes,tamc,idCliente,&indice))
            {
                if(setIsEmpty(&clientes[indice],0))
                {
                    printf("El cliente ha sido de baja exitosamente\n");
                    retorno=1;
                }
            }
            else
            {
                printf("El Cliente no exite\n");
            }
        }
        else
        {
            printf("No hay clientes que eliminar\n");
        }
    }
    return retorno;
}

int altaAlquiler(int* codigoAlquiler,eAlquiler* alquileres,int tama,eCliente* clientes,int tamc)
{
    int retorno=0;
    int indice;
    int codigoCliente;
    int idEquipo;
    int tiempoEstimado;
    char operador[21];
    if(codigoAlquiler!=NULL &&
       alquileres!=NULL && tama>0 &&
       clientes!=NULL && tamc>0)
    {
        if(buscarPrimerAlquilerLibre(alquileres,tama,&indice))
        {
            mostrarClientes(clientes,tamc);
            pedirNumeroSinLimite(&codigoCliente,"Ingrese el codigo del cliente: ","ERROR, ");
            while(buscarSiElClienteExiste(clientes,tamc,codigoCliente)==0)
            {
                printf("ERROR,El cliente ingresado no esta dentro del sistema\n");
                pedirNumeroSinLimite(&codigoCliente,"Ingrese el codigo del juego: ","ERROR, ");
            }
            printf("10.AMOLADORA\n");
            printf("11.MEZCLADORA\n");
            printf("12.TALADRO\n");
            pedirNumero(&idEquipo,"Ingrese el id del Equipo: ","ERROR, ",12,10);
            pedirNumero(&tiempoEstimado,"Ingrese el tiempo Estimado en dias: ","ERROR, ",100,0);
            pedirTexto(operador,"Ingrese el nombre del operador: ","ERROR, ");
            if(setAlquiler(&alquileres[indice],codigoCliente,*codigoAlquiler,idEquipo,operador,tiempoEstimado))
            {
                printf("Alquiler cargado con exito\n");
                *codigoAlquiler=*codigoAlquiler+1;
                retorno=1;
            }
        }
        else
        {
            printf("No hay Espacio para mas Alquileres\n");
        }
    }
    return retorno;
}

int FinalizarAlquiler(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc)
{
    int retorno=0;
    int codigoAlquiler;
    int indice;
    int tiempoReal;
    if(alquileres!=NULL && tama>0 && clientes!=NULL && tamc>0)
    {
        if(buscarSiHayAlquileres(alquileres,tama))
        {
            mostrarAlquileres(alquileres,tama,clientes,tamc);
            pedirNumeroSinLimite(&codigoAlquiler,"Ingrese el codigo del alquiler que desea finalizar: ","ERROR, ");
            if(buscarUnAlquilerPorId(alquileres,tama,codigoAlquiler,&indice))
            {
                pedirNumero(&tiempoReal,"Ingrese el tiempo que estuvo alquilado el equipo: ","ERROR, ",1000,0);
                if(setCodigoEstado(&alquileres[indice],0) &&
                   setCodigoTimpoReal(&alquileres[indice],tiempoReal))
                {
                    printf("El alquiler ha sido finalizado exitosamente\n");
                    retorno=1;
                }
            }
            else
            {
                printf("El alquiler no existe\n");
            }
        }
        else
        {
            printf("No hay alquileres que finalizar\n");
        }
    }
    return retorno;
}

void personaConMasAlquileres(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc)
{
    int acumulador;
    int maximo;
    int flag=1;
    char nombre[21];
    char apellido[21];
    if(alquileres!=NULL && tama>0 && clientes!=NULL && tamc>0 &&
       buscarSiHayAlquileres(alquileres,tama) && buscarSiHayClientes(clientes,tamc))
    {
       for(int i=0;i<tamc;i++)
       {
           acumulador=0;
           for(int j=0;j<tama;j++)
           {
               if(clientes[i].id==alquileres[j].idCliente && clientes[i].isEmpty && alquileres[j].isEmpty)
               {
                   acumulador++;
                   if(flag || acumulador>maximo)
                   {
                       flag=0;
                       maximo=acumulador;
                       strcpy(nombre,clientes[i].nombre);
                       strcpy(apellido,clientes[i].apellido);
                   }
               }
           }
       }
       printf("la persona con mas alquileres es %s %s\n",nombre,apellido);
    }
    else
    {
        printf("No hay Alquileres o Clientes como para definir la persona comas alquileres\n");
    }
}

void tiempoPromedioDeALqulerDeLosEquipos(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc)
{
    int Acumulador=0;
    int contador=0;
    float tiempoPromedio;
    if(alquileres!=NULL && tama>0 && clientes!=NULL && tamc>0 &&
       buscarSiHayAlquileres(alquileres,tama) && buscarSiHayClientes(clientes,tamc))
    {
       for(int i=0;i<tama;i++)
       {
           if(alquileres[i].isEmpty)
           {
               contador++;
               Acumulador+=alquileres[i].timpoReal;
           }
       }
       tiempoPromedio=(float)Acumulador/contador;
       printf("El promedio de tiempo real es de %.2f dias\n",tiempoPromedio);
    }
    else
    {
        printf("No hay Alquileres o Clientes como para definir el promedio de tiempo de alquiler\n");
    }
}

