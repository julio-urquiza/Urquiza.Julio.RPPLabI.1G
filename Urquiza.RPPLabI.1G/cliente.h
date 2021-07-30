#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char DNI[10];
    char nombre[21];
    char apellido[21];
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int buscarUnClientePorId(eCliente* clientes,int tamc,int id,int* indice);
void mostrarUnCliente(eCliente cliente);
int mostrarClientes(eCliente* clientes,int tamc);
int inicializarClientes(eCliente* clientes,int tamc);
int buscarPrimerClienteLibre(eCliente* clientes,int tamc,int* indice);
int buscarSiHayClientes(eCliente* clientes,int tamc);
int buscarSiElClienteExiste(eCliente* clientes,int tamc,int codigo);
void hardcodearClientes(eCliente* clientes,int tamc,eCliente* clientes2,int tamc2,int* idClientes);

int setNombre(eCliente* cliente,char* nombre);
int setApellido(eCliente* cliente,char* apellido);
int setDNI(eCliente* cliente,char* dni);
int setIsEmpty(eCliente* cliente,int isEmpty);
int setId(eCliente* cliente,int id);
int setCliente(eCliente* cliente,int id,char* nombre,char* apellido,char* dni);

int getNombre(eCliente cliente,char* nombre);
int getApellido(eCliente cliente,char* apellido);
int getDNI(eCliente cliente,char* dni);
int getId(eCliente cliente,int* id);
int getCliente(eCliente cliente,int* id,char* nombre,char* apellido,char* dni);




