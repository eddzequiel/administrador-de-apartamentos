#include <stdio.h> // Cabecera estándar E/S C
#include <stdlib.h> // Cabecera estandar
#include "datos.h" // Cabecera en la que se almacenan algunas variables
#include <time.h> // Cabecera que se utiliza para extraer el tiempo de la maquina
#include <iostream> // Libreria estándar E/S C++
#include <vector> // Libreria para realizar manejo de variables y arrays correctamente
#include <conio.h> // Cabecera que se utiliza en el login para "pausar", cambiar el fondo de pantalla, letras de la pantalla y limpiarla.
#include <windows.h> // Cabecera que permite realizar ajuste de la ventana del ejecutable
#include <sstream> // Permite la manipulacion de cadena de caracteres "Strings"
#define ENTER 13 //Funcion usada en el login 
#define BACKSPACE 8 //Funcion usada en el login


using namespace std;

void ver_pago(); //Subproceso que permite ver los pagos realizados en el año por el inquilino.
void SubMenuApartamento(FILE *f); //Menu que muestra la opcion de ingresar inquilino, ver inquilino, ver pago.
void visualizar(FILE *f); //Muestra los datos del inquilino y muestra un menu que permite su modificacion o eliminacion.
void modificar(FILE *f); //Modifica los datos del inquilino a eleccion del usuario.
void ingresar(); //Permite ingresar todos los datos de un inquilino nuevo.
void pago(); //Realiza el pago de los meses de un inquilino
void ver_pago(FILE *f); //Permite ver los meses que se han pagado de un inquilinos
void Menu(); //Despliega el menu principal con varias opciones
void crearFichero(FILE* f, int &salida); //Si no se ha creado el fichero lo crea 
void login(int &valido); //Simple login para una persona que no permite el ingreso de alguien ajeno. 
void eliminar(); //Elimina el registro del inquilino registrado
void fecha(); //Permite mostrar la fecha en el programa 
bool AjustarVentana(int Ancho, int Alto); //Ajusta el tamaño de la ventana del ejecutable


bool AjustarVentana(int Ancho, int Alto)
{
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tamaño
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tamaño de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}


void login(int &valido)
{
    vector<string> usuarios;  // vector de usernames
    vector<string> passwords; // vector de passwords

    // Se llena el vector de username con aquellos usarios que tienen permiso para logearse
    usuarios.push_back("Mercedes");

    // Se llena el vector de passwords con las contraseñas de los usuarios
    passwords.push_back("1234");

    string usuario, password; // Variables en donde se reciben los datos del usuario
    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout<< "\t\t   Apartament's Administrator"<<endl;
        cout << "\t\t\t----------------" << endl;


        // Lectura del username
        cout <<endl<<"\tUsuario: ";
        getline(cin, usuario);

        // Lectura del password
        char caracter;
        cout << "\tContrase\244a: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";

            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }

        // Se procede a buscar al usuario y password
        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && passwords[i] == password)
            {
                ingresa = true;
                break;	// Se sale del ciclo porque se encontró al usuario
            }
        }

        if (!ingresa)   // Entra aquí cuando no se encuentra el usuario
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    }
    while (ingresa == false && contador < 3);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema." << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema Apartament's Administrator " << endl;
    }

    cin.get();
    valido=1; //Esta variable hace que pueda continuar por el if del main()

    return;
}


void Menu()
{
    system("cls");
    cout << "__________________________________________"<< endl;
    cout <<"|                                          |"<< endl;
    cout <<"|      Apartament's Administrator          |"<< endl;
    cout <<"|__________________________________________|"<< endl;
    cout <<"|            B I E N V E N I D O           |"<< endl;
    cout <<"| 1. Ver Apartamento 1                     |"<< endl;
    cout <<"| 2. Ver Apartamento 2                     |"<< endl;
    cout <<"| 3. Ver Apartamento 3                     |"<< endl;
    cout <<"| 4. Ver Apartamento 4                     |"<< endl;
    cout <<"| 5. Ver Apartamento 5                     |"<< endl;
    cout <<"| 6. Ver Apartamento 6                     |"<< endl;
    cout <<"| 7. Ver Apartamento 7                     |"<< endl;
    cout <<"| 8. Salir del Programa                    |"<< endl;
    cout <<"|                                          |"<< endl;
    cout <<"|                               ";
    fecha(); //Permite mostrar la fecha del sistema
    cout<<"  |"<< endl;
    cout <<"|__________________________________________|"<< endl;
}


void crearFichero(FILE *f, int &salida)
{
    int creacion=0;

    cout<<"La base de datos no ha sido creada."<< endl;
    cout<<"¿Desea crearla?"<<endl;
    cout<<"1. Si."<<endl;
    cout<<"2. No."<<endl;
    cin>>creacion;
    if (creacion==1) 
    {
        f = fopen("apartamentos", "w");
    }
    else
    {
        salida=1; //Permite la salida del main()
        cout<<"Gracias por utilizar el programa";
    }
    return;
}



void eliminar()
{
    reg[opc-1].estado=1; //Pone el estado del inquilino seleccionado en modo: Disponible 

}



void modificar(FILE *f)
{
    int x;
    int opcion;
    fflush(stdin);
    cout<<"       Archivos abiertos con exito. "<<endl<<endl<<endl;
    cout << "Ingresa una opcion segun el campo que desea modificar: " << endl;
    cout << "1: Para modificar el nombre. " << endl;
    cout << "2: Para modificar la cedula. " << endl;
    cout << "3: Para modificar la ocupacion. " << endl;
    cout << "4: Para modificar el telefono. " << endl;
    cout << "5: Para modificar el sexo. " << endl;
    cout << "6: Para modificar la edad. " << endl;
    cout << "7: Regresar al menu" << endl;

    do
    {
        cout << endl<< "Seleccione una opci\242n: " << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
        {
            fflush(stdout);
            cout <<endl<<"Digite el nuevo nombre: " << endl;
            fflush(stdin);
            gets(reg[opc-1].nombre);
            break;
        }
        case 2:
        {
            fflush(stdout);
            cout<<endl<<"Digite la nueva c\202dula: "<<endl;
            fflush(stdin);
            gets(reg[opc-1].cedula);
            break;
        }
        case 3:
        {
            fflush(stdout);
            cout <<endl<< "Digite la nueva ocupaci\242n: " << endl;
            fflush(stdin);
            gets(reg[opc-1].ocupacion);
            break;
        }
        case 4:
        {
            fflush(stdout);
            cout <<endl<< "Digite el nuevo tel\202fono: " << endl;
            fflush(stdin);
            gets(reg[opc-1].telefono);
            break;
        }
        case 5:
        {
            fflush(stdout);
            cout <<endl<< "Digite el nuevo sexo: " << endl;
            fflush(stdin);
            gets(reg[opc-1].sexo);
            break;
        }
        case 6:
        {
            fflush(stdout);
            cout <<endl<< "Digite la nueva edad: " << endl;
            fflush(stdin);
            cin >> reg[opc-1].edad;
            break;
        }
        case 7:
        {
            system("cls");
            cout<<endl<<endl<<"  La ficha de informaci\242n del inquilino "<<opc<<" se ha modificado."<<endl<<endl;

            f= fopen("apartamentos","w");  //Abre el archivo para escribir en el
            rewind(f); //Para poner el puntero al inicio del archivo
            for (x=1 ; x<=7; x++)
            {
                fwrite(&reg[x-1], sizeof(struct inquilinos), 1, f); //Se realiza un loop para escribir en todas las estructuras del fichero 
																	//sin cambiar nada mas que lo seleccionado como inquilino.
            }
            break;

        }
        default:
            cout <<endl<< "Digite una opci\242n v\240lida!" << endl;
            break;
        }
    }
    while (opcion!=7);

    system("PAUSE");
    system("cls");

    return;

}



void ingresar()
{
    system("cls");
    fflush(stdin);
    cout << "Ingrese el nombre del inquilino: " << endl;
    gets(reg[opc-1].nombre);

    cout << "Ingrese la c\202dula del inquilino: " << endl;
    fflush(stdin);
    gets(reg[opc-1].cedula);

    cout << "Ingrese la edad del inquilino: " << endl;
    fflush(stdin);
    cin >> reg[opc-1].edad;

    cout << "Ingrese la ocupaci\242n del inquilino: " << endl;
    fflush(stdin);
    gets(reg[opc-1].ocupacion);

    cout << "Ingrese el tel\202fono del inquilino: " << endl;
    fflush(stdin);
    gets(reg[opc-1].telefono);

    cout << "Ingrese el sexo: M/F" << endl;
    fflush(stdin);
    gets(reg[opc-1].sexo);

    reg[opc-1].estado=0; //Al poner el estado en 0 se valida el cuarto como OCUPADO

    return;
}


void visualizar(FILE *f)
{
    int opcion;
    system("cls");
    fflush(stdout);
    cout << "Nombre: " << reg[opc-1].nombre << endl;
    fflush(stdout);
    cout << "C\202dula: " << reg[opc-1].cedula << endl;
    fflush(stdout);
    cout << "Ocupaci\242n: " << reg[opc-1].ocupacion << endl;
    fflush(stdout);
    cout << "Tel\202fono: " << reg[opc-1].telefono << endl;
    fflush(stdout);
    cout << "Edad: " << reg[opc-1].edad << endl;
    fflush(stdout);
    cout << "Sexo: " << reg[opc-1].sexo << endl<<endl;

    do
    {
        cout << "Seleccione una Opci\242n: " << endl;
        cout << " ____________________________ "<< endl;
        cout << "|                            |"<< endl;
        cout << "|1. Modificar inquilino      |"<< endl;
        cout << "|2. Eliminar inquilino       |"<< endl;
        cout << "|3. Regresar al men\243         |"<< endl;
        cout << "|____________________________|"<< endl;
        fflush(stdin);
        cin >> opcion;

        switch(opcion)
        {
        case 1:
        {
            system("cls");
            fclose(f);
            modificar(f);
            break;
        }
        case 2:
        {
            system("cls");
            eliminar();
            break;
        }
        case 3:
        {
            break;
        }

        default:
        {
            cout<<"Opci\242n incorrecta";
            break;
        }
        }
    }

    while(opcion!=3);
    return;
}


void SubMenuApartamento(FILE *f)
{
    int opcion = 0;

    cout<<"Usted seleccion\242 el apartamento "<< opc << endl;
    cout<<"Estado:";


    if (reg[opc-1].estado==1)
    {

        do
        {

            cout << " Disponible"<< endl;
            cout <<" ________________________________"<< endl;
            cout <<"|                                |"<< endl;
            cout <<"| 1 - Ingresar nuevo Inquilino   |"<< endl;
            cout <<"| 2 - Regresar al men\243 principal |"<< endl;
            cout <<"|________________________________|"<< endl;
            cout <<"Seleccione Una Opci\242n: ";
            fflush(stdin);
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                ingresar();
                break;

            case 2:
                Menu();
                break;

            default:
                cout<<"Estimado user digite una opci\242n v\240lida!"<<endl;
                system("pause");
                break;
            }
            return;
        }
        while (opcion!=2);
    }
    else
    {
        if (reg[opc-1].estado==0)
        {
            cout << " Ocupado" << endl;
            cout <<" ________________________________"<< endl;
            cout <<"|                                |"<< endl;
            cout <<"| 1 - Ver Inquilino              |"<< endl;
            cout <<"| 2 - Ver Pagos                  |"<< endl;
            cout <<"| 3 - Regresar al men\243           |"<< endl;
            cout <<"|________________________________|"<< endl;
            cout <<"Seleccione Una Opci\242n: ";
            fflush(stdin);
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                visualizar(f);
                break;
            case 2:
                ver_pago(f);
                break;

            default:
                system("cls");
                break;
            }
        }
    }
    return;
}


void pago()
{
    int opcion;

    do
    {
        cout<<"¿A que mes ingresara pago?"<<endl<<endl;
        cout<<"Seleccione el mes:"<<endl;
        cout<<"1-  Enero"<<endl;
        cout<<"2-  Febrero"<<endl;
        cout<<"3-  Marzo "<<endl;
        cout<<"4-  Abril"<<endl;
        cout<<"5-  Mayo"<<endl;
        cout<<"6-  Junio"<<endl;
        cout<<"7-  Julio"<<endl;
        cout<<"8-  Agosto"<<endl;
        cout<<"9-  Septiembre"<<endl;
        cout<<"10- Octubre"<<endl;
        cout<<"11- Noviembre"<<endl;
        cout<<"12- Diciembre"<<endl<<endl;
        cout<<"13- Regresar"<<endl;

        cin>>opcion;

        if (opcion>=1 && opcion<=12)
        {
            reg[opc-1].pago[opcion-1]=true;
        }
        else
        {
            if (opcion==13)
            {
                system("cls");
                cout<<"Adi\242s, hasta pronto"<<endl;
            }
            else
            {
                cout<<"Opci\242n incorrecta";//////
            }
        }

        cout <<"Se ha registrado el pago del mes "<<opcion<< endl;
        system("PAUSE");
        system("cls");
    }
    while (opcion!=13);
    return;
}


void ver_pago(FILE *f)
{

    int x,opcion;
    system("cls");
    for (x=1; x<=12; x++)
    {
        if (x<10)
        {
            cout<<"Mes  "<<x;
        }
        else
        {
            cout<<"Mes "<<x;
        }

        if (reg[opc-1].pago[x-1]!=false)
        {
            cout<<"=  Pagado"<<endl;
        }
        else
        {
            cout<<"=  No pagado"<<endl;
        }

    }
    system("pause");
    system("cls");

    cout<<"Que desea realizar?"<<endl;
    cout <<" ________________________________"<< endl;
    cout <<"|                                |"<< endl;
    cout <<"| 1 - Realizar pago              |"<< endl;
    cout <<"| 2 - Regresar al menu           |"<< endl;
    cout <<"|________________________________|"<< endl;

    do
    {

        fflush(stdin);
        cin>>opcion;

        switch(opcion)
        {
        case 1:
        {
            system("cls");
            pago();
            break;
        }


        case 2:

        {
            system("cls");
            break;

        }

        default:
        {
            cout<<"Estimado user digite una opci\242n valida!"<<endl;
            system("pause");
            break;
        }
        }
return;
    }
    while (opcion!=2);


}



void fecha()
{
    time_t t = time(NULL);
    struct tm tm= *localtime(&t); //Estructura en la que se guardan todos los datos obtenidos del sistema.

        int anio;
        int mes;
        int dia;
        anio=tm.tm_year+1900; //Se guarda el año actual, se le suma 1900 ya que este empieza a contar desde el 1900.
        mes=tm.tm_mon+1; //Se guarda el mes actual, se suma 1 porque empieza a contar desde 0.
        dia=tm.tm_mday; //Se guarda el dia actual.

        //number to convert int a string

        stringstream fechaentradastream; //Se declara una string personalizable o modificable a placer.

        fechaentradastream << anio<<"/"<<mes<<"/"<<dia;//add the value of Number to the characters in the stream //Se ingresa en esa stream valores enteros.

        string fechaentrada = fechaentradastream.str(); //Convierte de un tipo raro que no se puede mandar entre subprocesos a string
        cout<<fechaentrada; //imprime la fecha.

    }




int main()
{
	system("color 3E"); //Cambia el color de letra y fondo
	system("TITLE Apartament's Administrator "); //Cambia el titulo del ejecutable
    AjustarVentana(65,40); //Ajusta la ventana del ejecutable

    int x;
    int salida=0;
    int valido=0;

    login(valido);
    if (valido==1)
    {
        for (x=1; x<=7; x++)
        {
            reg[x-1].estado=1;
        }

        FILE *f;

        f = fopen("apartamentos", "r");
        if(!f)
        {
            crearFichero(f, salida);
        }
        else
        {

            for (x=1 ; x<=7; x++)
            {
                fread(&reg[x-1],sizeof(struct inquilinos),1,f); ///
            }
            fclose(f);

        }

        while (salida!=1)
        {
            Menu();
            cout<<"Digite su opci\242n: ";
            fflush(stdin);
            cin >> opc;
            switch (opc)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                system("cls");
                SubMenuApartamento(f);
                break;
            case 8:
                cout << "Gracias por utilizar el programa " << endl;
                salida=1;
                f=fopen("apartamentos","w");
                for (x=1 ; x<=7; x++)
                {
                    fwrite(&reg[x-1], sizeof(struct inquilinos), 1, f); ///
                }

                fclose(f);
                break;
            default:
                cout<<"Estimado user digite una opci\242n valida!"<<endl;
                system("pause");
            }
        }
    }

    return 0;
}
