#include "cliente.h"
#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct{
    int idAlquiler;
    int idCliente;
    int idEquipo;
    int estado;
    char operador[31];
    int timpoEstimado;
    int timpoReal;
    int isEmpty;
}eAlquiler;

#endif // ALQUILER_H_INCLUDED
int buscarUnAlquilerPorId(eAlquiler* alquileres,int tama,int idAlquiler,int* indice);
int definirEstado(int idEstado,char* estado);
int definirEquipo(int idEquipo,char* equipo);
void mostrarUnAlquiler(eAlquiler alquiler,eCliente* clientes,int tamc);
int mostrarAlquileres(eAlquiler* alquileres,int tama,eCliente* clientes,int tamc);
int inicializarAquileres(eAlquiler* alquileres,int tama);
int buscarPrimerAlquilerLibre(eAlquiler* alquileres,int tama,int* indice);
int buscarSiHayAlquileres(eAlquiler* alquileres,int tama);
void hardcodearAlquileres(eAlquiler* alquileres,int tama,eAlquiler* alquileres2,int tama2,int* idAlquileres);

int setCodigoIdCliente(eAlquiler* alquiler,int idCliente);
int setCodigoIdAlquiler(eAlquiler* alquiler,int idAlquiler);
int setCodigoIdEquipo(eAlquiler* alquiler,int idEquipo);
int setCodigoEstado(eAlquiler* alquiler,int estado);
int setIsEmptyAlquiler(eAlquiler* alquiler,int isEmpty);
int setOperador(eAlquiler* alquiler,char* operador);
int setCodigoTimpoEstimado(eAlquiler* alquiler,int timpoEstimado);
int setCodigoTimpoReal(eAlquiler* alquiler,int timpoReal);
int setAlquiler(eAlquiler* alquiler,int idCliente,int idAlquiler,int idEquipo,char* operador,int timpoEstimado);
