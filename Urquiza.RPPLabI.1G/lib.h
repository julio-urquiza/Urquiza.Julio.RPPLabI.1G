#include "alquiler.h"
#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED



#endif // LIB_H_INCLUDED
int altaCliente(eCliente* clientes,int tamc,int* idCliente);
int modificarCliente(eCliente* clientes,int tamc);
int darDeBajaCliente(eCliente* clientes,int tamc);
int altaAlquiler(int* codigoAlquiler,eAlquiler* alquileres,int tama,eCliente* clientes,int tamc);
int FinalizarAlquiler(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc);
void personaConMasAlquileres(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc);
void tiempoPromedioDeALqulerDeLosEquipos(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc);
