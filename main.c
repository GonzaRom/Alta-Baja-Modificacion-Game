#include "lista.h"
#include "users.h"
#include "menu.h"

#define ADMIN "admin404"
#define ADMINPASS "error404"

void agregaScoreArchi(stScores nuevoScore);

void switchSubMenuAdm(stCelda enJuego[],int validos);
void switchSubMenuUser(stCelda enJuego[],int validos,stCelda elJugador);
void switchSubMenuJuego(stCelda enJuego[],int validos,stCelda elJugador);

int main()
{
    srand(time(0));
    int registrosValidos;
    char elArchivoUsuarios[]="usuarios.dat";
    char elArchivoScores[]="scores.dat";




    stCelda enJuego[MAXUSR*20];
    int validos=0;
    int aux=0;
    //system("color 2");
    ///escribirArchivoStart();
    //mostrarRegistros(elArchivoUsuarios);
    //limpia();

    ///stCelda* enJuego=(stCelda*)malloc(sizeof(stCelda)*cuentaRegistros(elArchivoUsuarios,sizeof(stUsuario)));
    registrosValidos=cuentaRegistros(elArchivoUsuarios,sizeof(stUsuario));
    validos=archivoToEnJuego(enJuego,validos);
    ///escribirArchivoScores(enJuego,validos);
    archiScoreToCeldas(enJuego,validos);



    /*system("pause");
    mostrarEnJuego(enJuego,validos);
    limpia();
    mostrarRegistrosScores(elArchivoScores);
    limpia();*/

    int op;
    do
    {
        stCelda elJugador;
        iniciarMenu();
        op = ingresarOpcion();
        system("cls");
        switch(op)
        {
        case 0:
            printf("\n\n\n\n\n\t\t\t\tGRACIAS POR JUGAR\n\n\n\n\n");
            break;
        case 1:
            imprimirCabecera("LOGIN");
            elJugador=login(enJuego,validos);
            system("cls");
            mostrarUnaCelda(elJugador);
            if (strcmp(elJugador.usr.nombreUsuario,ADMIN)==0)
            {
                switchSubMenuAdm(enJuego,validos);
                system("cls");
            }
            else
            {
                switchSubMenuUser(enJuego,validos,elJugador);
            }
            system("cls");
            break;
        case 2:
            imprimirCabecera("REGISTRO");
            validos=altaDeUsuario(enJuego,validos);
            system("cls");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);


/////////////////


    return 0;
}

void switchSubMenuAdm(stCelda enJuego[],int validos)
{
    int op;
    int pos;
    do
    {
        imprimirOpcionesSubMenuAdm();
        op = ingresarOpcion();
        switch(op)
        {
        case 0:
            break;
        case 1:
            system("cls");
            imprimirCabecera("Eliminar Jugador");
            eliminaCelda(enJuego,validos);
            break;
        case 2:
            system("cls");
            modificarJugador(enJuego,validos);
            break;
        case 3:
            pos=buscaPosIdUsuario(enJuego,404,validos);
            switchSubMenuUser(enJuego,validos,enJuego[pos]);
            break;
        case 4:
            printf("Ingreso a la opcion 4 del Submenu 1\n");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);

}

void switchSubMenuUser(stCelda enJuego[],int validos,stCelda elJugador)
{
    int op;
    int puntos=0;
    stScores nuevo;
    nodoListaScores* nuevoScore;
    do
    {
        imprimirOpcionesSubMenuUser();
        op = ingresarOpcion();

        switch(op)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            switchSubMenuJuego(enJuego,validos,elJugador);
            break;
        case 2:
            system("cls");
            recorrerYmostrar(elJugador.tablaScores);
            break;
        case 3:
            system("cls");
            topDiez(enJuego,validos);
            system("pause");
            break;
        case 4:
            menuModificar(elJugador.usr);
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);
}

void switchSubMenuJuego(stCelda enJuego[],int validos,stCelda elJugador)
{
    int op;
    int puntos=0;
    stScores nuevo;
    nodoListaScores* nuevoScore;
    do
    {
        imprimirOpcionesSubMenuJuegos();
        op = ingresarOpcion();

        switch(op)
        {
        case 0:
            system("cls");
            break;
        case 1:
           // puntos=juegoTetris(elJugador.usr.nombreUsuario,puntos);
           // nuevo=generaScores(elJugador.usr.idUsuario,puntos);
          //  nuevoScore=crearNodo(nuevo);
          //  elJugador.tablaScores=agregarEnOrden(elJugador.tablaScores,nuevoScore);
        ///agregaScoreArchi(nuevo);

            break;
        case 2:
            //puntos=juegoTaTeTi(elJugador.usr.nombreUsuario);
            //nuevo=generaScores(elJugador.usr.idUsuario,puntos);
           // nuevoScore=crearNodo(nuevo);
            //elJugador.tablaScores=agregarEnOrden(elJugador.tablaScores,nuevoScore);
           // agregaScoreArchi(nuevo);
            system("cls");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(op != 0);
}


void agregaScoreArchi(stScores nuevoScore)
{

    FILE *buffArchivo=fopen(archiScores,"ab");
    if(!buffArchivo)
        printf("\nE R R O R en la apertura del archivo\n");
    else
        fwrite(&nuevoScore,sizeof(stScores),1,buffArchivo);

    if(fclose(buffArchivo)==-1)
        printf("\n\nERROR de Salva de Score");
}
