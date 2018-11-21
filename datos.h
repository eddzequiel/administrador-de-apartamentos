int opc=0; //Opcion global que es necesaria en todos los subprocesos.

struct inquilinos
{
    bool pago[12]; //Bool para los pagos del año.
    char nombre[50]; //Para guardar el nombre
    char cedula[50]; //Para guardar la cedula
    char ocupacion[50]; //Para guardar la ocupacion del inquilino
    char telefono[10]; //Para guardar el telefono del inquilino
    char sexo[1]; //Para guardar el sexo
    int edad; //Para guardar la edad
    int estado; //Para guardar el estado actual del apartamento
}reg[7];

struct tm_tm; //Estructura de TIME

