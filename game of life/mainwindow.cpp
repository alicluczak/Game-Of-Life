#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), timer(new QTimer(this))
{
    ui->setupUi(this);
    create_board();
    ui->Board->setStyleSheet("background-color: #1B1B20;");
    connect(timer,SIGNAL(timeout()),this,SLOT(iteracja_timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_board_size_valueChanged(int value)
{
    gra.powieksz_tablice();
    gra.setMax(value);
    max_alive();
    create_board();
    ui->ilosc_punkt->setMaximum(ui->board_size->value()*ui->board_size->value());
}

void MainWindow::on_draw_clicked()
{
  gra.Los_stanu_pocz(ui->ilosc_punkt->value());
  create_board();
}

void MainWindow::create_board(){
    scene = new QGraphicsScene(ui->Board);
    ui->Board->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush(QColor(90, 208, 184, 150));
    int wielkosc_okna=400;
    punkt pkt;
    int cell_size=wielkosc_okna/gra.getMax();
    ui->Board->setMaximumSize(wielkosc_okna+gra.getMax(),wielkosc_okna+gra.getMax());
    ui->Board->setMinimumSize(wielkosc_okna+gra.getMax(),wielkosc_okna+gra.getMax());
    for(int wielkosc_x=0; wielkosc_x<ui->board_size->value(); wielkosc_x++){
        pkt.x = wielkosc_x;
        for(int wielkosc_y=0; wielkosc_y<ui->board_size->value(); wielkosc_y++){
            pkt.y=wielkosc_y;
            if(gra.getIsAlive({pkt.x,pkt.y})){
                square = scene->addRect(cell_size*wielkosc_x, cell_size*wielkosc_y, cell_size, cell_size, blackpen, brush);
            }
            else{
                square = scene->addRect(cell_size*wielkosc_x, cell_size*wielkosc_y, cell_size, cell_size, blackpen);
                }
            }
        }
    }

void MainWindow::max_alive(){
    ui->ilosc_punkt->setMaximum(ui->board_size->value()*ui->board_size->value());
}

void MainWindow::on_iteracja_clicked()
{
    gra.powieksz_tablice();
    gra.Zasady_Gry();
    gra.iteracja();
    create_board();
}

void MainWindow::on_start_clicked()
{
    timer->setInterval(500);
    timer->start();
}

void MainWindow::iteracja_timer(){
    gra.Zasady_Gry();
    gra.iteracja();
    create_board();
}

void MainWindow::on_stop_clicked()
{
    timer->stop();
    gra.Los_stanu_pocz(0);
    create_board();
}

void MainWindow::on_pauza_clicked()
{
    timer->stop();
    create_board();
}

void MainWindow::on_Load_clicked()
{
    sciezka_do_odczytu();
    gra.odczyt(path);
    create_board();
    path=nullptr;
}


void MainWindow::on_Save_clicked()
{
    sciezka_do_zapisu();
    gra.zapis(path);
}

void MainWindow::sciezka_do_odczytu()
{
    QString pom = QFileDialog::getOpenFileName(this,"Save", "","Save (*.txt)");
    if(!pom.isEmpty()) path = pom;
}

void MainWindow::sciezka_do_zapisu()
{
    QString pom = QFileDialog::getSaveFileName(this,"Save", "","Save (*.txt)");
    if(!pom.isEmpty()) path = pom;
}


void MainWindow::on_Slider_zywe_sliderPressed()
{
     ui->ilosc_punkt->setMaximum(ui->board_size->value()*ui->board_size->value());
}

