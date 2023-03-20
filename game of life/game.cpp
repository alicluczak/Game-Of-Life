#include "Game.h"
#include <iostream>
#include <fstream>
#include <QDebug>

using namespace std;


void Game::przepisanie_punktow(){
    punkt nowy_punkt;
    for(int x=0;x<max;x++){
        for( int y=0;y<max;y++){
            nowy_punkt={x,y,false};
            lista_punktow.push_back(nowy_punkt);
            }
    }
}

void Game::powieksz_tablice(){
    QVector<punkt> lista_zywych;
    for(int i=0;i<lista_punktow.size();i++){
        if (lista_punktow[i].isAlive){
            lista_zywych.push_back(lista_punktow[i]);
        }
    }
    lista_punktow.clear();
    przepisanie_punktow();
    for(int index=0; index<lista_punktow.size(); index++){
        for(int index_zywych=0; index_zywych<lista_zywych.size(); index_zywych++){
            if(lista_punktow[index].x==lista_zywych[index_zywych].x && lista_punktow[index].y==lista_zywych[index_zywych].y)
                lista_punktow[index].isAlive=true;
        }
    }
}


void Game::Los_stanu_pocz(int ilosc_punktow_do_wylosowania){
    lista_punktow.clear();
    przepisanie_punktow();
    srand(time(NULL));
    int wylosowany_index=0;
    for(int licznik=0; licznik<ilosc_punktow_do_wylosowania; licznik++){
        wylosowany_index=rand()%lista_punktow.size();
        if(!lista_punktow[wylosowany_index].isAlive){
            lista_punktow[wylosowany_index].isAlive=true;
        }else{
            licznik--;
        }
    }
}

int Game::licznik_sasiadow(vector<int> sasiad,int index, int size){
    int licznik=0;
    punkt pkt;
    punkt pomocniczy;
    pkt=lista_punktow[index];
    for(int index=0; index<size;index++){
        switch(sasiad[index]){
        case 1:
            pomocniczy = {pkt.x-1,pkt.y,getIsAlive({pkt.x-1,pkt.y})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 2:
            pomocniczy={pkt.x+1,pkt.y,getIsAlive({pkt.x+1,pkt.y})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 3:
            pomocniczy={pkt.x,pkt.y-1,getIsAlive({pkt.x,pkt.y-1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 4:
            pomocniczy={pkt.x,pkt.y+1,getIsAlive({pkt.x,pkt.y+1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 5:
            pomocniczy={pkt.x-1,pkt.y+1,getIsAlive({pkt.x-1,pkt.y+1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 6:
            pomocniczy={pkt.x-1,pkt.y-1,getIsAlive({pkt.x-1,pkt.y-1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 7:
            pomocniczy={pkt.x+1,pkt.y+1,getIsAlive({pkt.x+1,pkt.y+1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
        case 8:
            pomocniczy={pkt.x+1,pkt.y-1,getIsAlive({pkt.x+1,pkt.y-1})};
            if(pomocniczy.isAlive){licznik++;}
            break;
            }
        }
    return licznik;
}

int Game::liczba_sasiadow(int index_punktu){
    int ilosc_sasiadow=0;
    punkt pkt;
    int rozmiar;
    pkt=lista_punktow[index_punktu];
    if(pkt.x==min || pkt.x==max || pkt.y==min || pkt.y==max){
        if(pkt.x==min && pkt.y==min){
           rozmiar=3;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=2;
           sasiedzi[1]=4;
           sasiedzi[2]=7;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.x==max && pkt.y==min){
           rozmiar=3;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=4;
           sasiedzi[1]=1;
           sasiedzi[2]=5;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.x==min && pkt.y==max){
           rozmiar=3;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=3;
           sasiedzi[1]=2;
           sasiedzi[2]=8;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.x==max && pkt.y==max){
           rozmiar=3;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=3;
           sasiedzi[1]=1;
           sasiedzi[2]=6;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.x==min){
           rozmiar=5;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=4;
           sasiedzi[1]=3;
           sasiedzi[2]=7;
           sasiedzi[3]=2;
           sasiedzi[4]=8;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.x==max){
           rozmiar=5;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=4;
           sasiedzi[1]=5;
           sasiedzi[2]=1;
           sasiedzi[3]=6;
           sasiedzi[4]=3;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.y==min){
           rozmiar=5;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=1;
           sasiedzi[1]=2;
           sasiedzi[2]=5;
           sasiedzi[3]=4;
           sasiedzi[4]=7;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
       }else if(pkt.y==max){
           rozmiar=5;
           vector<int> sasiedzi(rozmiar);
           sasiedzi[0]=2;
           sasiedzi[1]=1;
           sasiedzi[2]=6;
           sasiedzi[3]=3;
           sasiedzi[4]=8;
           ilosc_sasiadow=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
        }
    }else{
        rozmiar=8;
        vector<int> sasiedzi(rozmiar);
        for(int index=0; index<rozmiar; index++){
            sasiedzi[index]=index+1;
            }
        ilosc_sasiadow+=licznik_sasiadow(sasiedzi, index_punktu, rozmiar);
        }
    return ilosc_sasiadow;
}

int Game::getMax(){
    return max;
}

void Game::setMax(int rozmiar_okna){
    max=rozmiar_okna;
}

void Game::dodaj(punkt pkt){
    lista_punktow.push_back(pkt);
}

bool Game::getIsAlive(punkt pkt){
    bool alive=false;
    for(int index=0; index<lista_punktow.size(); index++){
        if(pkt.x==lista_punktow[index].x && pkt.y==lista_punktow[index].y){
            alive=lista_punktow[index].isAlive;
            }
        }
    return alive;
}

void Game::smierc(int index){
   lista_punktow[index].isAlive=false;
}

void Game::zycie(int index){
   lista_punktow[index].isAlive=true;
}

void Game::Zasady_Gry(){
   for(int i=0;i<lista_punktow.size();i++){
        if(liczba_sasiadow(i)>3 || liczba_sasiadow(i)<2){
            zgon.push_back(i);
        }else if(liczba_sasiadow(i)==3){
            urodziny.push_back(i);
        }
   }
}

void Game::iteracja(){
    for(int liczba_zgonow=0; liczba_zgonow<zgon.size(); liczba_zgonow++){
        smierc(zgon[liczba_zgonow]);
        }
    for(int liczba_urodzin=0; liczba_urodzin<urodziny.size(); liczba_urodzin++){
        zycie(urodziny[liczba_urodzin]);
        }
    zgon.clear();
    urodziny.clear();
}

QList<punkt> Game::getLista_punktow(){
    return lista_punktow;
}

QVector<int> Game::getUrodzenia(){
    return urodziny;
}

void Game::zapis(QString sciezka){
    if(!sciezka.isEmpty()){
        std::ofstream file(sciezka.toStdString());
        for(int index_punktu=0; index_punktu<lista_punktow.size(); index_punktu++){
            file <<lista_punktow[index_punktu].x <<" ";
            file <<lista_punktow[index_punktu].y <<" ";
            file <<lista_punktow[index_punktu].isAlive <<endl;
            }
        file.close();
        }
    }

void Game::odczyt(QString sciezka){
    if(!sciezka.isEmpty()){
        lista_punktow.clear();
        int x,y;
        bool czyZywe;
        std::ifstream file(sciezka.toStdString());
        for(int i=0;!file.eof();i++){
            file>>x, file>>y, file>>czyZywe;
            lista_punktow.push_back({x,y,czyZywe});
            }
        file.close();
    }
}
