#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "cliente.h"


int buscarUnAlquilerPorId(eAlquiler* alquileres,int tama,int idAlquiler,int* indice)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0 && idAlquiler>0 && indice !=NULL)
    {
        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].idAlquiler==idAlquiler && alquileres[i].isEmpty)
            {
                *indice=i;
                retorno=1;
            }
        }
    }
    return retorno;
}
int definirEstado(int idEstado,char* estado)
{
    int retorno=0;
    if(estado!=NULL)
    {
        if(idEstado==1)
        {
            strcpy(estado,"alquilado");
        }
        else
        {
            strcpy(estado,"finalizado");
        }
        retorno=1;
    }
    return retorno;
}
int definirEquipo(int idEquipo,char* equipo)
{
    int retorno=0;
    if(equipo!=NULL)
    {
        switch(idEquipo)
        {
        case 10:
            strcpy(equipo,"amoladora");
            break;
        case 11:
            strcpy(equipo,"mezcladora");
            break;
        case 12:
            strcpy(equipo,"taladro");
            break;
        }
        retorno=1;
    }
    return retorno;
}
void mostrarUnAlquiler(eAlquiler alquiler,eCliente* clientes,int tamc)
{
    int idCliente;
    char estado[31];
    char equipo[31];
    definirEquipo(alquiler.idEquipo,equipo);
    definirEstado(alquiler.estado,estado);
    buscarUnClientePorId(clientes,tamc,alquiler.idCliente,&idCliente);
    printf("%10d%10s%10s%10s%10s%10s%15i%15i\n",alquiler.idAlquiler,
                                                clientes[idCliente].nombre,
                                                clientes[idCliente].apellido,
                                                equipo,
                                                estado,
                                                alquiler.operador,
                                                alquiler.timpoEstimado,
                                                alquiler.timpoReal);
}
int mostrarAlquileres(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0 && clientes!=NULL && tamc>0)
    {
        printf("%10s%10s%10s%10s%10s%10s%15s%15s\n","id","nombre","apelldio","equipo","estado","operador","timpo Est","timpo Real");
        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].isEmpty)
            {
                mostrarUnAlquiler(alquileres[i],clientes,tamc);
            }
        }
        retorno=1;
    }
    return retorno;
}
int inicializarAquileres(eAlquiler* alquileres,int tama)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0)
    {
        for(int i=0;i<tama;i++)
        {
            alquileres[i].isEmpty=0;
        }
        retorno=1;
    }
    return retorno;
}
int buscarPrimerAlquilerLibre(eAlquiler* alquileres,int tama,int* indice)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0 && indice!=NULL)
    {
        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].isEmpty==0)
            {
                *indice=i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int buscarSiHayAlquileres(eAlquiler* alquileres,int tama)
{
    int retorno=0;
    if(alquileres!=NULL && tama>0)
    {
        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].isEmpty==1)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
void hardcodearAlquileres(eAlquiler* alquileres,int tama,eAlquiler* alquileres2,int tama2,int* idAlquileres)
{
    if(alquileres!=NULL && tama>0 && alquileres2!=NULL && tama2>0 && tama2<tama)
    {
        for(int i=0;i<tama2;i++)
        {
            alquileres[i]=alquileres2[i];
            *idAlquileres=alquileres[i].idAlquiler+1;
        }
    }
}


int setCodigoIdCliente(eAlquiler* alquiler,int idCliente)
{
    int retorno=0;
    if(idCliente>=0 && alquiler!=NULL)
    {
        alquiler->idCliente=idCliente;
        retorno=1;
    }
    return retorno;
}
int setCodigoIdAlquiler(eAlquiler* alquiler,int idAlquiler)
{
    int retorno=0;
    if(idAlquiler>=0 && alquiler!=NULL)
    {
        alquiler->idAlquiler=idAlquiler;
        retorno=1;
    }
    return retorno;
}
int setCodigoIdEquipo(eAlquiler* alquiler,int idEquipo)
{
    int retorno=0;
    if(idEquipo>=0 && alquiler!=NULL)
    {
        alquiler->idEquipo=idEquipo;
        retorno=1;
    }
    return retorno;
}
int setCodigoEstado(eAlquiler* alquiler,int estado)
{
    int retorno=0;
    if((estado==0 || estado==1)&& alquiler!=NULL)
    {
        alquiler->estado=estado;
        retorno=1;
    }
    return retorno;
}
int setIsEmptyAlquiler(eAlquiler* alquiler,int isEmpty)
{
    int retorno=0;
    if((isEmpty==1 || isEmpty==0) && alquiler!=NULL)
    {
        alquiler->isEmpty=isEmpty;
        retorno=1;
    }
    return retorno;
}
int setOperador(eAlquiler* alquiler,char* operador)
{
    int retorno=0;
    if(operador!=NULL && alquiler!=NULL)
    {
        strcpy(alquiler->operador,operador);
        retorno=1;
    }
    return retorno;
}
int setCodigoTimpoEstimado(eAlquiler* alquiler,int timpoEstimado)
{
    int retorno=0;
    if(timpoEstimado>=0 && alquiler!=NULL)
    {
        alquiler->timpoEstimado=timpoEstimado;
        retorno=1;
    }
    return retorno;
}
int setCodigoTimpoReal(eAlquiler* alquiler,int timpoReal)
{
    int retorno=0;
    if(timpoReal>=0 && alquiler!=NULL)
    {
        alquiler->timpoReal=timpoReal;
        retorno=1;
    }
    return retorno;
}
int setAlquiler(eAlquiler* alquiler,int idCliente,int idAlquiler,int idEquipo,char* operador,int timpoEstimado)
{
    int retorno=0;
    if(setCodigoIdCliente(alquiler, idCliente) &&
       setCodigoIdAlquiler(alquiler, idAlquiler) &&
       setCodigoIdEquipo(alquiler, idEquipo) &&
       setCodigoEstado(alquiler,1) &&
       setIsEmptyAlquiler(alquiler,1) &&
       setOperador(alquiler,operador) &&
       setCodigoTimpoEstimado(alquiler, timpoEstimado) &&
       setCodigoTimpoReal(alquiler, 0))
    {
        retorno=1;
    }
    return retorno;
}

