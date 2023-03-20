#include "testy.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <Game.h>
using namespace std;

void test_sasiadow(){
    Game gra;
    punkt p;
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            if(y==2 && (x==1 || x==0)){
                p={x,y,true};
                gra.dodaj((p));
            }
            else{
                p={x,y,false};
                gra.dodaj((p));
                }
        }
    }
    if(gra.liczba_sasiadow(4)==2){
        qDebug()<<"GIT";
    }
    else{
        qDebug()<<"NIC NIE DZIALA";
    }
}

void test_zasad(){
    Game gra;
    punkt p;
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            if((x==1 && y==1) || (x==2 && y==2) || (x==0 && y==2)){
                p={x,y,true};
                gra.dodaj((p));
            }
            else{
                p={x,y,false};
                gra.dodaj((p));
            }
        }
    }
    gra.Zasady_Gry();
    gra.iteracja();
    QList<punkt> testowa_lista=gra.getLista_punktow();
    if(testowa_lista[4].isAlive && testowa_lista[5].isAlive    
            && !testowa_lista[0].isAlive && !testowa_lista[1].isAlive
            && !testowa_lista[2].isAlive && !testowa_lista[3].isAlive
            && !testowa_lista[6].isAlive && !testowa_lista[7].isAlive
            && !testowa_lista[8].isAlive){
        qDebug()<<"GIT";
    }
    else{
        qDebug()<<"NIC NIE DZIALA";
    }
}
