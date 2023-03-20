#ifndef GAME_H
#define GAME_H
#include <random>
#include <QList>
#include <QFileDialog>
using namespace std;

struct punkt{
 int x;
 int y;
 bool isAlive;
};

class Game{

private:
    int min=0, max=10;
    QList<punkt> lista_punktow;
    QVector<int> urodziny;
    QVector<int> zgon;

public:
    void Los_stanu_pocz(int ilosc_punktow_do_wylosowania);
    void Zasady_Gry();
    int liczba_sasiadow(int index_punktu);
    int licznik_sasiadow(vector<int> sasiad, int index, int size);
    void zycie(int index);
    void smierc(int index);
    void przepisanie_punktow();
    void setMax(int rozmiar_okna);
    int getMax();
    void dodaj(punkt pkt);
    bool getIsAlive(punkt pkt);
    QList<punkt> getLista_punktow();
    void iteracja();
    QVector<int> getUrodzenia();
    void zapis(QString sciezka);
    void odczyt(QString sciezka);
    void powieksz_tablice();

};


#endif // GAME_H
