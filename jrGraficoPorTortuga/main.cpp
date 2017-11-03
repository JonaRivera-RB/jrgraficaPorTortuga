//
//  main.cpp
//  jrGraficoPorTortuga
//
//  Created by misael rivera on 01/11/17.
//  Copyright © 2017 misael rivera. All rights reserved.
//
#include <iostream>
int menu();
void comenzar(int tablero[][20],int tamaño);
void mostrarTablero(int tablero[][20], int tamaño);
using namespace std;
int main(int argc, const char * argv[]) {
    int opc, tamaño=20;
    int tablero[20][20]{{0}};
    cout << "Grafica por tortuga!\n";
    
    //mostrarTablero(tablero, tamaño);
    opc = menu();
    if (opc==1)
        comenzar(tablero, tamaño);
    else if (opc==2)
        cout<<"opc 1";
    else if (opc==0)
        cout<<"opc 1";
    else
        cout<<"opcion no valida";
    mostrarTablero(tablero, tamaño);
    return 0;
}
int menu()
{
    int opc;
    cout<<"\tPor favor seleccione una opcion: \n";
    cout<<"\t1.-comenzar\n";
    cout<<"\t2.-Instrucciones\n";
    cout<<"\t0.-Salir\n";
    cin>>opc;
    return opc;
}
void comenzar(int tablero[][20],int tamaño)
{
    int opc,pasos = 0,pluma=0,girarDerecha = 0,girarIzq;
    int posicionY=0,posicionX=0;
    int t = 0;
    cout<<"\t\t\tAVISO\t\n";
    cout<<"la primera vez que carga el playground la tortuga estara mirando hacia la derecha -> y la pluma estara hacia arriba\n\n";
    cout<<"\t\t\tComandos\n";
    cout<<"1 = pluma hacia arriba\n"
    <<"2 = pluma hacia abajo\n"
    <<"3 = girar a la derecha\n"
    <<"4 = girar a la izquierda\n"
    <<"5 = avanzar\n"
    <<"6 = salir\n";
    do {
        
        cin>>opc;
        if (opc==1)
        {
            pluma=0;
            cout<<"pluma hacia arriba\n";
        }
        else if (opc==2)
        {
            pluma=1;
            cout<<"pluma hacia abajo\n";
        }
        else if(opc==3){
            girarDerecha += 1;
            if(girarDerecha==4)
                girarDerecha=0;
            cout<<girarDerecha<<"--giraste a la derecha\n";
        }
        else if(opc==4)
            girarIzq = 1;
        else if (opc==5) {
            cout<<"cuantos pasos quiere dar?\n";
            cin>>pasos;
            if (girarDerecha==0)
                for (int i=posicionY; i<=posicionY; i++) {
                    for (int j=posicionX, k=pasos; k>0; j++,k--) {
                        tablero[i][j]=pluma;
                        posicionX=j;
                        cout<<posicionX;
                    }
                }
            else if (girarDerecha==1)
                for (int k=pasos,i=posicionY; k>0; k--,i++) {
                    for (int j=posicionX; j<=posicionX; j++) {
                        tablero[i][j]=pluma;
                    }
                    posicionY=i;
                    cout<<posicionY;
                }
            else if (girarDerecha==2)
                for (int i=posicionY; i<=posicionY; i++) {
                    for (int k=posicionX, j=pasos; j>0; j--,k--) {
                        tablero[i][k]=pluma;
                        posicionX=k;
                        cout<<posicionX<<"x\n";
                    }
                }
            else if (girarDerecha==3)
                for (int k=posicionY, i=pasos; i>0; i--,k--) {
                    for (int j=posicionX; j<=posicionX; j++) {
                        tablero[k][j]=pluma;
                    }
                    posicionY=k;
                    cout<<posicionY;
                }
        }
        
    } while (opc!=6);
}
void mostrarTablero(int tablero[][20], int tamaño)
{
    for (int i=0; i<tamaño; i++) {
        for (int j=0; j<tamaño; j++)
            cout<<" "<<tablero[i][j];
        cout<<"\n";
    }
}
