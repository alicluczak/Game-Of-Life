#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Game.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void create_board();
    void max_alive();

private slots:

    void on_board_size_valueChanged(int value);
    void on_draw_clicked();
    void on_iteracja_clicked();
    void on_start_clicked();
    void iteracja_timer();
    void on_stop_clicked();
    void on_pauza_clicked();
    void on_Load_clicked();
    void on_Save_clicked();
    void sciezka_do_odczytu();
    void sciezka_do_zapisu();
    void on_Slider_zywe_sliderPressed();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *square;
    Game gra;
    QTimer *timer = nullptr;
    QString path;

};

#endif // MAINWINDOW_H
