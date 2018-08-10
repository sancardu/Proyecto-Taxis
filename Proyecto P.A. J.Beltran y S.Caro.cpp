/*

Jerson Beltran y Santiago Caro

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define maxcar 30
#define maxcal 10
#define maxtax 20
#define maxtaxcu 3

using namespace std;

struct info
{
    string placa;
    char tipo;
    bool activo;
    char estado;
    int capacidad;
    int carrera;
    int calle;

};
struct mat
{
    int taxi;
    string placa[maxtaxcu];
};
void color (int x);
int ingresar (info taxi[], int carreras, int calles,mat cuadrantes[maxcar][maxcal]);
void listar (info taxi[], int num);
void plano (info taxi[],int carreras,int calles, int num, mat cuadrantes[maxcar][maxcal]);
void medio(int colum, int maxi, info taxi[],int filas,int num, mat cuadrantes[maxcar][maxcal]);
void terminar(int colum);
void inicio(int colum);
void medin(int colum);
void inactivar (info taxi[], int num,  mat cuadrantes[maxcar][maxcal]);
void activar (info taxi[], int num,mat cuadrantes[maxcar][maxcal],int carreras, int calles);
void pedir (info taxi[], int num, int carreras, int calles, mat cuadrantes[maxcar][maxcal]);
void buscuadrante (info taxi[], int carreras, int calles,int num);
bool buscaplaca(info taxi[], int carreras, int calles,int num,string plac);
void busplaca (info taxi[], int carreras, int calles,int num,string plac);
void mover (info taxi[], int carreras, int calles,int num,mat cuadrantes[maxcar][maxcal]);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    info taxi[maxtax];
    mat cuadrantes[maxcar][maxcal];
    string plac;
    int opcion, numcall, numcarr, numtax;
    int con=0;

    //Inicia el contador en cada matriz
    for(int i =0; i<maxcar; i++)
    {
        for (int j=0; j<maxcal; j++)
        {
            cuadrantes[i][j].taxi=0;
        }
    }

    //Pone espacios para matriz.
    for(int i =0; i<maxcar; i++)
    {
        for (int j=0; j<maxcal; j++)
        {
            for (int k=0; k<maxtaxcu; k++)
            {
                cuadrantes[i][j].placa[k]="      ";
            }

        }
    }
    do
    {
        cout << endl;
        color(15);
        cout<<setw(45);
        color(11);
        cout<< "BIENVENIDO";
        color(15);
        cout << endl;
        cout << endl;
        if (con==0)
        {
            color(14);
            cout<< setw(29)<< "0. -INGRESAR DATOS DE TAXI."<< endl; //Terminado
            color(15);
        }
        cout<< setw(42)<< "1. -LISTA DE DATOS BASICOS DE LOS TAXIS."<< endl;//Terminado
        cout<< setw(25)<< "2. -PLANO DE LA CIUDAD."<< endl;//Terminado
        cout<< setw(24)<< "3. -INACTIVAR UN TAXI."<< endl;//Terminado
        cout<< setw(38)<< "4. -ACTIVAR UN TAXI EN UN CUADRANTE."<< endl;//Terminado
        cout<< setw(28)<< "5. -SOLICITAR UN SERVICIO."<< endl;//Terminado
        cout<< setw(31)<< "6. -EXTRAER DATOS DE UN TAXI."<< endl;//Terminado
        cout<< setw(36)<< "7. -EXTRAER DATOS DE UN CUADRANTE."<< endl;//Terminado
        cout<< setw(20)<< "8. -MOVER UN TAXI."<< endl;//Terminado
        cout<< setw(25)<< "9. -SALIR DEL PROGRAMA."<< endl;//Terminado
        cout<< setw(20)<< "ELIJA UNA OPCION: " ;//Terminado
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 0:
            if (con==0)
            {
                do
                {
                    cout << "INGRESE EL NUMERO DE CARRERAS, MAXIMO "<< maxcar <<" : ";
                    cin >> numcarr;
                    if (numcarr>maxcar||numcarr<0)
                    {
                        color(12);
                        cout << "VALOR INVALIDO"<< endl;
                        color(15);
                    }
                }
                while (numcarr>maxcar||numcarr<0);
                do
                {
                    cout << "INGRESE EL NUMERO DE CALLES, MAXIMO "<< maxcal<< " : ";
                    cin >> numcall;
                    if (numcall>maxcal||numcall<0)
                    {
                        color(12);
                        cout << "VALOR INVALIDO"<< endl;
                        color(15);
                    }
                }
                while (numcall>maxcal||numcall<0);
                numtax=ingresar(taxi,numcarr,numcall,cuadrantes);
                con++;
            }
            else
            {
                color(12);
                cout<< "OPCION INVALIDA, SOLO SE PUEDE INGRESAR UNA VEZ LA INFORMACION"<< endl;//Cuando el contador es mayor a 0.
                color(15);
            }

            break;
        case 1:
            if (con>0)
            {
                listar(taxi,numtax);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }

            break;
        case 2:
            if (con>0)
            {
                plano (taxi,numcarr,numcall,numtax,cuadrantes);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 3:
            if (con>0)
            {
                inactivar(taxi, numtax,cuadrantes);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 4:
            if (con>0)
            {
                activar(taxi,numtax,cuadrantes,numcarr,numcall);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 5:
            if (con>0)
            {
                pedir(taxi,numtax,numcarr,numcall,cuadrantes);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 6:
            if (con>0)
            {
                color(13);
                cout <<setw(49)<< "BUSQUEDA POR PLACA"<< endl;
                color(15);
                cout << endl;
                cout << "INGRESE LA PLACA A BUSCAR: ";
                cin >> plac;
                busplaca(taxi,numcarr,numcall,numtax,plac);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 7:
            if (con>0)
            {
                buscuadrante(taxi,numcarr,numcall,numtax);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 8:
            if (con>0)
            {
                mover (taxi,numcarr,numcall,numtax,cuadrantes);
            }
            else
            {
                color(12);
                cout << "PRIMERO INGRESE DATOS EN LA OPCION 0"<< endl;
                color(15);

            }
            break;
        case 9:
            color(14);
            cout<<setw(46) << "VUELVA PRONTO"<< endl;
            color(15);
            break;
        default:
            color(12);
            cout<< "OPCION INVALIDA." << endl;
            color(15);
        }

    }
    while (opcion!=9);

}

/*-----------------------------------------FUNCIONES---------------------------------------------------------------------*/

void color (int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
int ingresar (info taxi[], int carreras, int calles, mat cuadrantes[maxcar][maxcal])
{
    char g;
    cout << endl;
    color(9);
    cout<<setw(48)<< "INGRESO DE DATOS"<< endl;
    color(15);
    cout << endl;
    int numtax; //Varianble de cuantos taxis se van a ingresar
    bool aux; //Booleano para verificar la placa
    do
    {
        cout << "INGRESE LA CANTIDAD DE TAXIS, MAXIMO "<< maxtax <<" : ";
        cin >> numtax;
        if(numtax>maxtax|| numtax<0) //Cuando el numero de taxis es mayor al maximo o menor a 0.
        {
            color(12);
            cout << "VALOR INVALIDO"<< endl;
            color(15);
        }
    }
    while (numtax>maxtax|| numtax<0);

    for (int i=0; i<numtax; i++)
    {
        do
        {
            cout << "INGRESE LA PLACA DEL TAXI " << i << " : ";
            cin >> taxi[i].placa;
            aux = buscaplaca(taxi,carreras,calles,i,taxi[i].placa);
            if (aux) //Si auxiliar es verdadero la placa ya existe.
            {
                color(12);
                cout<< "PLACA YA INGRESADA "<< endl;
                color(15);
            }
        }
        while (aux);
        do
        {
            cout << "INGRESE EL TIPO DE VEHICULO (VAN(v)/AUTO(a)) " << i << " : ";
            cin >> taxi[i].tipo;
            taxi[i].tipo=tolower(taxi[i].tipo);
            if(taxi[i].tipo!='v'&&taxi[i].tipo!='a')
            {
                color(12);
                cout << "VALOR INVALIDO"<< endl;
                color(15);
            }
        }
        while (taxi[i].tipo!='v'&&taxi[i].tipo!='a');

        cout << "INGRESE LA CAPACIDAD DEL TAXI " << i << " : ";
        cin >> taxi[i].capacidad;

        taxi[i].activo=true;//Al principio todos estan activos
        taxi[i].estado='l';//Al principio todos estan libres.


        for(int h=0; h<1; h++)//Verifica que haya espacio en el cuadrante.
        {
            do
            {
                cout << "INGRESE LA CARRERA DEL TAXI, MAXIMO " << carreras-1 << " : ";
                cin >> taxi[i].carrera;
                if(taxi[i].carrera>carreras-1 ||taxi[i].carrera<0 )
                {
                    color(12);
                    cout << "VALOR INVALIDO"<< endl;
                    color(15);
                }
            }
            while (taxi[i].carrera>carreras-1 ||taxi[i].carrera<0 );
            do
            {
                cout << "INGRESE LA CALLE DEL TAXI , MAXIMO " << calles-1 << " : ";
                cin >> taxi[i].calle;
                if(taxi[i].calle>calles-1|| taxi[i].calle<0)
                {
                    color(12);
                    cout << "VALOR INVALIDO"<< endl;
                    color(15);
                }
            }
            while (taxi[i].calle>calles-1|| taxi[i].calle<0);

            if (cuadrantes[taxi[i].carrera][taxi[i].calle].taxi<3)
            {
                cuadrantes[taxi[i].carrera][taxi[i].calle].placa[cuadrantes[taxi[i].carrera][taxi[i].calle].taxi]= taxi[i].placa;
                cuadrantes[taxi[i].carrera][taxi[i].calle].taxi=cuadrantes[taxi[i].carrera][taxi[i].calle].taxi+1;
            }
            else
            {
                color(12);
                cout << "CUADRANTE LLENO."<< endl;
                h--;//Para poder volver a ingresar al ciclo de las calles y las carreras.
                color(15);
            }
        }

    }
    Sleep(500);
    system("CLS");//Limpiar pantalla
    return numtax;
}

void listar (info taxi[], int num)
{
    color(14);
    cout<<setw(43)<< "LISTADO"<< endl;
    cout << endl;
    color(15);
    cout << setw(10)<<"PLACA"<< setw(10)<<"TIPO"<< setw(10)<<"CAPACIDAD"<<setw(10)<<"ACTIVIDAD"<<setw(10)<<"ESTADO"<< setw(10)<<"CARRERA"<< setw(10)<<"CALLE"<< endl;
    cout << endl;
    for (int i=0; i<num; i++)
    {
        cout<< setw(10) << taxi[i].placa;
        cout<< setw(10) << taxi[i].tipo;
        cout<< setw(10) << taxi[i].capacidad;
        if (taxi[i].activo)
        {
            cout<< setw(10) << "ACTIVO";
        }
        else
        {
            cout<< setw(10) << "INACTIVO";
        }
        if (taxi[i].estado=='l')
        {
            cout<< setw(10) << "LIBRE";
        }
        else
        {
            cout<< setw(10) << "OCUPADO";
        }
        if (taxi[i].carrera==-1)//Si es -1 esta inactivo y no se sabe cual es la carrera o la calle
        {
            cout<< setw(10) << " ";//Imprime un espacio para indicarlo
        }
        else
        {
            cout<< setw(10) << taxi[i].carrera;
        }
        if (taxi[i].calle==-1)
        {
            cout<< setw(10) << " ";
        }
        else
        {
            cout<< setw(10) << taxi[i].calle;
        }
        cout<< endl;
    }
    cout<< endl;
    cout<< endl;
    cout<< endl;
}

void plano (info taxi[],int carreras,int calles, int num,mat cuadrantes[maxcar][maxcal])
{
    color(13);
    cout<<setw(48)<< "PLANO DE LA CIUDAD"<< endl;
    cout << endl;
    color(15);
    int maxi=maxtaxcu;
    inicio(calles);
    cout << endl;
    for (int j=0; j<carreras-1; j++)
    {
        medio(calles,maxi,taxi,carreras,j, cuadrantes);
        medin(calles);
    }
    medio(calles,maxi,taxi,carreras,carreras-1,cuadrantes);
    terminar(calles);
}

void inicio(int colum)
{
    int a;
    for (int l=0; l<colum; l++)
    {
        if (l==0)
        {
            cout <<setw(40-(((colum*6)+(colum+1))/2)+3)<<l;//Imprime el numero de la columna en que va
        }
        else
        {
            cout <<setw(7)<<l;
        }

    }
    cout << endl<< setw(-7);
    a=201;
    cout <<setw(40-(((colum*6)+(colum+1))/2))<< (char)a;

    for (int i=0; i<colum; i++)// El 4 controla el numero columnas.
    {
        for (int j=0; j<6; j++) //el 6 controla los espacios del principio entre columna y columna.
        {
            a=205;

            cout << (char)a;

        }

        a=203;
        if (i<colum-1)//Numero de columnas -1  para que no imprima la ultima por que la ultima es diferente
        {
            cout << (char)a;
        }

    }

    a=187;
    cout << (char)a;

}

void medio(int colum, int maxi, info taxi[],int filas,int num, mat cuadrantes[maxcar][maxcal])
{
    int a;
    a=186;
    for (int j=0; j<1; j++) //El maxi controla cuantas veces va a poner las lineas. Espacio entre linea y linea
    {
        for (int k=0; k<3; k++)
        {
            for (int i=0; i<colum; i++) //El 4 Controla cuantas lineas de columnas tiene que poner. Numero de columnas
            {
                if(cuadrantes [num][i].taxi==0)
                {
                    if(j==colum-1&&colum!=1)
                    {
                        cout <<endl;
                    }
                    else
                    {
                        if (i==0)
                        {
                            cout <<setw(40-(((colum*6)+(colum+1))/2))<<(char)a<<"      ";
                        }
                        else
                        {
                            cout <<(char)a<<"      ";
                        }
                    }
                }
                else
                {
                    if(j==colum-1&&colum!=1)
                    {
                        cout <<(char)a<<setw(6)<< cuadrantes [num][i].placa[k]<<endl;
                    }
                    else
                    {
                        if (i==0)
                        {
                            cout <<setw(40-(((colum*6)+(colum+1))/2))<<(char)a<<setw(6)<<cuadrantes [num][i].placa[k];
                        }
                        else
                        {
                            cout <<(char)a<<setw(6)<<cuadrantes [num][i].placa[k];
                        }
                    }
                    //cout << (char)a<< "vdc985";//El 7 controla los espacios entre columna y columna. Setw se imprimen las placas.

                }
            }

            cout<< (char)a;
            if(k==1)
            {
                cout <<setw(-7)<< " "<<num<<  endl;//Acaba y imprime el numero de la fila en que va.
            }
            else
            {
                cout <<setw(-7)<< " "<<  endl;
            }

        }
    }

}

void medin(int colum)
{
    int a;
    a=204;
    cout <<setw(40-(((colum*6)+(colum+1))/2))<< (char)a;
    for (int j =0; j<colum; j++) //El 3 es el numero de columnas que hay.
    {
        for(int b=0; b<6; b++) //6 Son espacios entre columnas
        {
            a=205;
            cout << (char)a;
        }
        if (j<colum-1)//Numero de columnas -1 para que no imprima la ultima por que la ultima es diferente
        {
            a=206;
            cout << (char)a;
        }
    }
    a=185;
    cout<< (char)a<< endl;
}

void terminar(int colum)
{
    int a;
    a=200;
    cout<<setw(40-(((colum*6)+(colum+1))/2))<<(char)a;
    for (int j =0; j<colum; j++) //El 3 es el numero de columnas que hay.
    {
        for(int b=0; b<6; b++) //6 Son espacios entre columnas
        {
            a=205;
            cout << (char)a;
        }
        if (j<colum-1)//Numero de columnas -1, para que no imprima la ultima por que la ultima es diferente
        {
            a=202;
            cout << (char)a;
        }
    }
    a=188;
    cout<< (char)a<< endl;
}

void inactivar (info taxi[], int num,  mat cuadrantes[maxcar][maxcal])
{
    string placa,aux, aux2;
    color(9);
    cout <<setw(44)<< "INACTIVAR";
    color(15);
    cout << endl;
    cout << endl;
    cout << "INGRESE LA PLACA DEL TAXI A DESACTIVAR : ";
    cin>> placa;
    for (int i=0; i<num; i++)
    {
        if (placa==taxi[i].placa)
        {
            if (taxi[i].activo)
            {
                cuadrantes [taxi[i].carrera][taxi[i].calle].taxi--;
                taxi[i].estado='o';
                for (int t=0; t<maxtaxcu; t++)//Busca en que posicion esta la placa dentro de la matriz.
                {
                    if(placa==cuadrantes [taxi[i].carrera][taxi[i].calle].placa[t])//En esta posicion la encontro
                    {
                        cuadrantes [taxi[i].carrera][taxi[i].calle].placa[t]="      ";//Se reemplaza por espacio
                        if(t==1)//En la posicion uno la placa en la posicion 2 la pas a la 1
                        {
                            aux=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2];
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=aux;
                        }
                        if(t==0)//Sube las placas en el cuadraante
                        {
                            aux=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2];
                            aux2=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[0];
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[0]=aux2;
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=aux;

                        }
                    }
                }

                taxi[i].activo=false;
                taxi[i].calle=-1;
                taxi[i].carrera=-1;
                color(10);
                cout<< "TAXI INACTIVADO"<< endl;
                color(15);
            }
            else
            {
                color(12);
                cout << "TAXI YA INACTIVO"<< endl;
                color(15);
            }

            return;
        }
    }
    color(12);
    cout << "PLACA INEXISTENTE"<< endl;
    color(15);
}

void activar (info taxi[], int num,mat cuadrantes[maxcar][maxcal],int carreras, int calles)
{
    string placa;
    color(13);
    cout << setw(43)<<"ACTIVAR";
    color(15);
    cout << endl;
    cout << endl;
    cout << "INGRESE LA PLACA DEL TAXI A ACTIVAR : ";
    cin>> placa;
    for (int i=0; i<num; i++)
    {
        if (placa==taxi[i].placa)
        {
            if (taxi[i].estado=='o')//Verifica que el taxi que este false.
            {
                for(int h=0; h<1; h++)//Este ciclo controla que el cuadrante no este lleno.
                {

                    do
                    {
                        cout << "INGRESE LA CARRERA DEL TAXI, MAXIMO " <<carreras-1<<" : ";
                        cin >> taxi[i].carrera;
                        if(taxi[i].carrera>carreras-1 ||taxi[i].carrera<0 )
                        {
                            color(12);
                            cout << "VALOR INVALIDO"<< endl;
                            color(15);
                        }
                    }
                    while (taxi[i].carrera>carreras-1 ||taxi[i].carrera<0 );
                    do
                    {
                        cout << "INGRESE LA CALLE DEL TAXI, MAXIMO " <<calles-1<<" : ";
                        cin >> taxi[i].calle;
                        if(taxi[i].calle>calles-1|| taxi[i].calle<0)
                        {
                            color(12);
                            cout << "VALOR INVALIDO"<< endl;
                            color(15);
                        }
                    }
                    while (taxi[i].calle>calles-1|| taxi[i].calle<0);

                    if (cuadrantes[taxi[i].carrera][taxi[i].calle].taxi<3)
                    {
                        taxi[i].activo=true;
                        taxi[i].estado='l';
                        cuadrantes[taxi[i].carrera][taxi[i].calle].placa[cuadrantes[taxi[i].carrera][taxi[i].calle].taxi]=placa;
                        cuadrantes[taxi[i].carrera][taxi[i].calle].taxi++;
                        color(10);
                        cout<< "TAXI ACTIVADO"<< endl;
                        color(15);
                    }
                    else
                    {
                        color(12);
                        cout << "CUADRANTE LLENO."<< endl;
                        h--;
                        color(15);
                    }
                }
            }
            else
            {
                color(12);
                cout << "TAXI YA ACTIVO"<< endl;
                color(15);
            }

            return;
        }
    }
    color(12);
    cout << "PLACA INEXISTENTE"<< endl;
    color(15);
}

void pedir (info taxi[], int num, int carreras, int calles,mat cuadrantes[maxcar][maxcal])
{
    int carr,call,capa,suma, mini,dis1,dis2,con=0,indi, emp, emp2,ocu=0;
    char tipo;
    string aux, aux2;
    color(10);
    cout<<setw(48)<< "SOLICITUD DE TAXI"<< endl;
    color(15);
    cout << endl;
    cout << endl;
    for (int y=0; y<num; y++)
    {
        if(taxi[y].estado=='o')
        {
            ocu++;
        }
    }
    if (ocu==num)
    {
        color(12);
        cout<< "LO SENTIMOS, NO HAY TAXIS DISPONIBLES."<< endl;
        color(15);
        cout << endl;
        cout << endl;
        return;
    }

    do
    {
        cout << "INGRESE LA CARRERA DONDE QUIERE SOLICITAR, MAXIMO " <<carreras-1<<" : ";
        cin >> carr;
        if(carr>carreras-1 ||carr<0 )
        {
            color(12);
            cout << "VALOR INVALIDO"<< endl;
            color(15);
        }
    }
    while (carr>carreras-1 ||carr<0 );
    do
    {
        cout << "INGRESE LA CALLE DONDE QUIERE SOLICITAR, MAXIMO " <<calles-1<<" : ";
        cin >> call;
        if(call> calles-1|| call<0)
        {
            color(12);
            cout << "VALOR INVALIDO"<< endl;
            color(15);
        }
    }
    while (call>calles-1|| call<0);
    cout << endl;
    do
    {
        cout << "INGRESE EL TIPO DE VEHICULO A SOLICITAR (VAN (v)/ AUTOMOVIL(a)): ";
        cin >> tipo;
        tipo=tolower(tipo);
        cout << endl;
        if((tipo!='v'&&tipo!='a'))
        {
            color(12);
            cout << "VALOR INVALIDO"<< endl;
            color(15);
        }
    }
    while((tipo!='v'&&tipo!='a'));
    cout << "INGRESE EL NUMERO DE PASAJEROS : ";
    cin >> capa;
    cout << endl;
    for(int n=0; n<num; n++)
    {
        if((taxi[n].capacidad>=capa) && (taxi[n].tipo==tipo)&&(taxi[n].estado=='l'))
        {
            dis1=carr-taxi[n].carrera;
            dis2=call-taxi[n].calle;
            suma=abs(dis1)+abs(dis2);
            if (con==0)
            {
                mini=suma;
                indi=n;
            }
            else
            {
                if(mini>suma)
                {
                    mini=suma;
                    indi=n;
                }
                if (mini == suma)
                {
                    //cout << "EMPATE"<< endl;
                    for (int a=0; a<maxtaxcu; a++)
                    {
                        if(taxi[indi].placa==cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[a])
                        {
                            emp=a;
                        }
                    }
                    for (int a=0; a<maxtaxcu; a++)
                    {
                        if(taxi[n].placa==cuadrantes [taxi[n].carrera][taxi[n].calle].placa[a])
                        {
                            emp2=a;
                        }
                    }
                    if (emp>emp2)
                    {
                        mini=suma;
                        indi=n;
                    }
                }
            }
            con++;
        }
    }
    if (con==0)
    {
        color(12);
        cout<< "LO SENTIMOS, NO HAY TAXIS DISPONIBLES."<< endl;
        color(15);
    }
    else
    {
        color(10);
        cout << "TAXI ENCONTRADO!"<< endl;
        color(15);
        cout << "EL TAXI CON LA PLACA "<< taxi[indi].placa<< endl;
        cout << "SE ENCUENTRA A UNA DISTANCIA DE: " << mini*100 << " METROS.";
        cout << endl;
        cout << endl;
        for (int t=0; t<maxtaxcu; t++)
        {
            if(taxi[indi].placa==cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[t])
            {
                cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[t]="      ";
                cuadrantes [taxi[indi].carrera][taxi[indi].calle].taxi--;
                if(t==1)
                {
                    aux=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2];
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2]=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1];
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1]=aux;
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2]="      ";
                }
                if(t==0)
                {
                    aux=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2];
                    aux2=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1];
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1]=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[0];
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2]=cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1];
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[0]=aux2;
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[1]=aux;
                    cuadrantes [taxi[indi].carrera][taxi[indi].calle].placa[2]="      ";
                }

            }

        }
        taxi[indi].estado='o';
        taxi[indi].carrera=-1;
        taxi[indi].calle=-1;
    }

}

void buscuadrante (info taxi[], int carreras, int calles,int num)
{
    color(10);
    cout<<setw(48)<< "TAXI EN CUADRANTE"<< endl;
    color(15);
    int carre, cal,con=0;
    cout <<"QUE CUADRANTE DESEA BUSCAR: "<< endl;
    do
    {
        cout <<"INGRESE CARRERA, MAXIMO "<< carreras-1<< " : ";
        cin >> carre;
        if (carre > carreras-1||carre<0)
        {
            color(12);
            cout<< "NUMERO INVALIDO"<< endl;
            color(15);
        }
    }
    while (carre >carreras-1||carre<0);
    do
    {
        cout <<"INGRESE CALLE MAXIMO "<< calles-1<< " : ";
        cin >> cal;
        if (cal> calles-1||cal<0)
        {
            color(12);
            cout<< "NUMERO INVALIDO"<< endl;
            color(15);
        }
    }
    while (cal >calles-1||cal<0);
    cout << endl;
    for (int i=0; i<num; i++)
    {
        if (taxi[i].carrera ==carre && taxi[i].calle==cal)
        {
            con++;
        }
    }
    if (con>0)
    {
        cout << setw(10)<<"PLACA"<< setw(10)<<"TIPO"<< setw(10)<<"CAPACIDAD"<<setw(10)<<"ACTIVIDAD"<<setw(10)<<"ESTADO"<< setw(10)<<"CARRERA"<< setw(10)<<"CALLE"<< endl;
    }
    for (int i=0; i<num; i++)
    {
        if (taxi[i].carrera ==carre && taxi[i].calle==cal)
        {
            cout<< setw(10) << taxi[i].placa;
            cout<< setw(10) << taxi[i].tipo;
            cout<< setw(10) << taxi[i].capacidad;
            if (taxi[i].activo)
            {
                cout<< setw(10) << "ACTIVO";
            }
            else
            {
                cout<< setw(10) << "INACTIVO";
            }
            if (taxi[i].estado=='l')
            {
                cout<< setw(10) << "LIBRE";
            }
            else
            {
                cout<< setw(10) << "OCUPADO";
            }
            if (taxi[i].carrera==-1)
            {
                cout<< setw(10) << " ";
            }
            else
            {
                cout<< setw(10) << taxi[i].carrera;
            }
            if (taxi[i].calle==-1)
            {
                cout<< setw(10) << " ";
            }
            else
            {
                cout<< setw(10) << taxi[i].calle;
            }
            cout<< endl;
        }
    }
    if (con==0)//Verifica que haya taxis en el cuadrante.
    {
        color(12);
        cout<< "NO HAY TAXIS EN ESTE CUADRANTE"<< endl;
        color(15);
    }
}

bool buscaplaca(info taxi[], int carreras, int calles,int num,string plac)
{
    int con=0;
    for (int i=0; i<num; i++)
    {
        if (taxi[i].placa==plac)
        {
            con++;
        }
    }
    if (con==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void busplaca (info taxi[], int carreras, int calles,int num,string plac)
{

    int con=0;
    for (int i=0; i<num; i++)
    {
        if (taxi[i].placa==plac)
        {
            cout << setw(10)<<"PLACA"<< setw(10)<<"TIPO"<< setw(10)<<"CAPACIDAD"<<setw(10)<<"ACTIVIDAD"<<setw(10)<<"ESTADO"<< setw(10)<<"CARRERA"<< setw(10)<<"CALLE"<< endl;
            cout<< setw(10) << taxi[i].placa;
            cout<< setw(10) << taxi[i].tipo;
            cout<< setw(10) << taxi[i].capacidad;
            if (taxi[i].activo)
            {
                cout<< setw(10) << "ACTIVO";
            }
            else
            {
                cout<< setw(10) << "INACTIVO";
            }
            if (taxi[i].estado=='l')
            {
                cout<< setw(10) << "LIBRE";
            }
            else
            {
                cout<< setw(10) << "OCUPADO";
            }
            if (taxi[i].carrera==-1)
            {
                cout<< setw(10) << " ";
            }
            else
            {
                cout<< setw(10) << taxi[i].carrera;
            }
            if (taxi[i].calle==-1)
            {
                cout<< setw(10) << " ";
            }
            else
            {
                cout<< setw(10) << taxi[i].calle;
            }
            cout<< endl;
            con++;
        }
    }
    if (con==0)
    {
        color(12);
        cout<< "TAXI INEXISTENTE"<< endl;
        color(15);
    }

}

void mover (info taxi[], int carreras, int calles,int num, mat cuadrantes[maxcar][maxcal])
{
    string plac,aux,aux2;
    int con=0,nuecarr,nuecal,opcion,opcion2,ind;
    color(8);
    cout << setw(46)<<"MOVER UN TAXI"<< endl;
    color(15);
    cout <<endl;
    if(carreras==1&&calles==1)
    {
        color(12);
        cout<< "\nNO SE PUEDE MOVER HACIA NINGUN CUADRANTE."<< endl;
        color(15);
        return;
    }
    do
    {
        cout << "INGRESE LA PLACA A BUSCAR: ";
        cin >> plac;
        for (int k=0; k<num; k++)
        {
            if (taxi[k].placa==plac)
            {
                ind=k;
                con++;
            }
        }
        if (con==0)
        {
            color(12);
            cout<< "\nTAXI INEXISTENTE"<< endl;
            color(15);
            return;
        }


        if (taxi[ind].estado=='o')
        {
            color(12);
            cout<< "TAXI NO DISPONIBLE"<< endl;
            color(15);
        }
    }
    while(taxi[ind].estado=='o');

    for (int i=0; i<num; i++)
    {
        if (taxi[i].placa==plac)
        {
            for(int h=0; h<1; h++)
            {
                do
                {
                    cout << endl;
                    cout << "0. -MOVER EL TAXI EN LAS CARRERAS.(ARRIBA/ABAJO)" << endl;
                    cout << "1. -MOVER EL TAXI EN LAS CALLES.(IZQUIERDA/DERRECHA)"<< endl;
                    cout << "INGRESE UNA OPCION: ";
                    cin >> opcion;
                    cout << endl;
                    switch (opcion)
                    {
                    case 0:
                        nuecal=taxi[i].calle;
                        do
                        {
                            if(taxi[i].carrera+1<carreras)
                            {
                                cout << "0. -MOVER A LA CARRERA : " << taxi[i].carrera+1<< endl;
                            }
                            if(taxi[i].carrera-1>=0)
                            {
                                cout << "1. -MOVER A LA CARRERA : " << taxi[i].carrera-1<<endl;
                            }
                            cout << "INGRESE UNA OPCION: ";
                            cin >> opcion2;
                            cout << endl;
                            switch(opcion2)
                            {
                            case 0:
                                if(taxi[i].carrera+1>=carreras)
                                {
                                    opcion2=3;
                                    color(12);
                                    cout<< "OPCION INVALIDA." << endl;
                                    color(15);
                                }
                                else
                                {
                                    nuecarr=taxi[i].carrera+1;
                                }
                                break;
                            case 1:
                                if(taxi[i].carrera-1<0)
                                {
                                    opcion2=3;
                                    color(12);
                                    cout<< "OPCION INVALIDA." << endl;
                                    color(15);
                                }
                                else
                                {
                                    nuecarr=taxi[i].carrera-1;
                                }
                                break;
                            default:
                                color(12);
                                cout<< "OPCION INVALIDA." << endl;
                                color(15);
                            }
                        }
                        while(opcion2!=0&&opcion2!=1);
                        break;
                    case 1:
                        nuecarr=taxi[i].carrera;
                        do
                        {
                            if(taxi[i].calle+1<calles)
                            {
                                cout << "0. -MOVER A LA CALLE : " << taxi[i].calle+1<<endl;
                            }
                            if(taxi[i].calle-1>=0)
                            {
                                cout << "1. -MOVER A LA CALLE : " << taxi[i].calle-1<<endl;
                            }
                            cout << "INGRESE UNA OPCION: ";
                            cin >> opcion2;
                            cout << endl;
                            switch(opcion2)
                            {
                            case 0:
                                if(taxi[i].calle+1>=calles)
                                {
                                    opcion2=3;
                                    color(12);
                                    cout<< "OPCION INVALIDA." << endl;
                                    color(15);
                                }
                                else
                                {
                                    nuecal=taxi[i].calle+1;
                                }
                                break;
                            case 1:
                                if(taxi[i].calle-1<0)
                                {
                                    opcion2=3;
                                    color(12);
                                    cout<< "OPCION INVALIDA." << endl;
                                    color(15);
                                }
                                else
                                {
                                    nuecal=taxi[i].calle-1;
                                }
                                break;
                            default:
                                color(12);
                                cout<< "OPCION INVALIDA." << endl;
                                color(15);
                            }
                        }
                        while(opcion2!=0&&opcion2!=1);
                        break;
                    default:
                        color(12);
                        cout<< "OPCION INVALIDA." << endl;
                        color(15);
                    }
                }
                while(opcion!=0&&opcion!=1);

                if (cuadrantes[nuecarr][nuecal].taxi<3)
                {

                    cuadrantes[nuecarr][nuecal].placa[cuadrantes[nuecarr][nuecal].taxi]=plac;
                    cuadrantes[nuecarr][nuecal].taxi++;
                    for (int t=0; t<maxtaxcu; t++)
                    {
                        if(plac==cuadrantes [taxi[i].carrera][taxi[i].calle].placa[t])
                        {
                            cuadrantes [taxi[i].carrera][taxi[i].calle].placa[t]="      ";
                            if(t==1)
                            {
                                aux=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2];
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=aux;
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]="      ";
                            }
                            if(t==0)
                            {
                                aux=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2];
                                aux2=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[0];
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]=cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1];
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[0]=aux2;
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[1]=aux;
                                cuadrantes [taxi[i].carrera][taxi[i].calle].placa[2]="      ";
                            }

                        }

                    }
                    cuadrantes [taxi[i].carrera][taxi[i].calle].taxi--;
                    taxi[i].carrera=nuecarr;
                    taxi[i].calle=nuecal;
                    color(10);
                    cout <<"TAXI CAMBIADO"<< endl;
                    color(15);
                }
                else
                {
                    color(12);
                    cout << "CUADRANTE LLENO."<< endl;
                    h--;
                    color(15);
                }
            }
            con++;
        }
    }
}

//FIN DEL PROGRAMA.



