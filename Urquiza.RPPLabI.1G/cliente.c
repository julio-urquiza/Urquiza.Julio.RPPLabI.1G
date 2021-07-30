#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int buscarUnClientePorId(eCliente* clientes,int tamc,int id,int* indice)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0 && id>0 && indice!=NULL)
    {
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].id==id)
            {
                *indice=i;
                retorno=1;
            }
        }
    }
    return retorno;
}
void mostrarUnCliente(eCliente cliente)
{
    printf("%15d %15s %15s %15s\n",cliente.id,cliente.nombre,cliente.apellido,cliente.DNI);
}
int mostrarClientes(eCliente* clientes,int tamc)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0)
    {
        printf("%15s %15s %15s %15s\n","ID","nombre","apellido","DNI");
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].isEmpty)
            {
                mostrarUnCliente(clientes[i]);
            }
        }
        retorno=1;
    }
    return retorno;
}
int inicializarClientes(eCliente* clientes,int tamc)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0)
    {
        for(int i=0;i<tamc;i++)
        {
            clientes[i].isEmpty=0;
        }
        retorno=1;
    }
    return retorno;
}
int buscarPrimerClienteLibre(eCliente* clientes,int tamc,int* indice)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0 && indice!=NULL)
    {
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].isEmpty==0)
            {
                *indice=i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int buscarSiHayClientes(eCliente* clientes,int tamc)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0)
    {
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].isEmpty==1)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int buscarSiElClienteExiste(eCliente* clientes,int tamc,int id)
{
    int retorno=0;
    if(clientes!=NULL && tamc>0 && id>=0)
    {
        for(int i=0;i<tamc;i++)
        {
            if(clientes[i].isEmpty==1 && clientes[i].id==id)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
void hardcodearClientes(eCliente* clientes,int tamc,eCliente* clientes2,int tamc2,int* idClientes)
{
    if(clientes!=NULL && tamc>0 && clientes2!=NULL && tamc2>0 && tamc2<tamc)
    {
        for(int i=0;i<tamc2;i++)
        {
            clientes[i]=clientes2[i];
            *idClientes=clientes[i].id+1;
        }
    }
}



int setNombre(eCliente* cliente,char* nombre)
{
    int retorno=0;
    if(nombre!=NULL)
    {
        strcpy(cliente->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int setApellido(eCliente* cliente,char* apellido)
{
    int retorno=0;
    if(apellido!=NULL)
    {
        strcpy(cliente->apellido,apellido);
        retorno=1;
    }
    return retorno;
}
int setDNI(eCliente* cliente,char* dni)
{
    int retorno=0;
    if(dni!=NULL)
    {
        strcpy(cliente->DNI,dni);
        retorno=1;
    }
    return retorno;
}
int setIsEmpty(eCliente* cliente,int isEmpty)
{
    int retorno=0;
    if(isEmpty==1 || isEmpty==0)
    {
        cliente->isEmpty=isEmpty;
        retorno=1;
    }
    return retorno;
}
int setId(eCliente* cliente,int id)
{
    int retorno=0;
    if(id>=0)
    {
        cliente->id=id;
        retorno=1;
    }
    return retorno;
}
int setCliente(eCliente* cliente,int id,char* nombre,char* apellido,char* dni)
{
    int retorno=0;
    if(setId(cliente,id) &&
       setNombre(cliente,nombre) &&
       setApellido(cliente,apellido) &&
       setDNI(cliente,dni) &&
       setIsEmpty(cliente,1))
    {
        retorno=1;
    }
    return retorno;
}


int getNombre(eCliente cliente,char* nombre)
{
    int retorno=0;
    if(nombre!=NULL)
    {
        strcpy(nombre,cliente.nombre);
        retorno=1;
    }
    return retorno;
}
int getApellido(eCliente cliente,char* apellido)
{
    int retorno=0;
    if(apellido!=NULL)
    {
        strcpy(apellido,cliente.apellido);
        retorno=1;
    }
    return retorno;
}
int getDNI(eCliente cliente,char* dni)
{
    int retorno=0;
    if(dni!=NULL)
    {
        strcpy(dni,cliente.DNI);
        retorno=1;
    }
    return retorno;
}
int getId(eCliente cliente,int* id)
{
    int retorno=0;
    if(id!=NULL)
    {
        id=cliente.id;
        retorno=1;
    }
    return retorno;
}
int getCliente(eCliente cliente,int* id,char* nombre,char* apellido,char* dni)
{
    int retorno=0;
    if(getId(cliente,id) &&
       getNombre(cliente,nombre) &&
       getApellido(cliente,apellido) &&
       getDNI(cliente,dni))
    {
        retorno=1;
    }
    return retorno;
}



