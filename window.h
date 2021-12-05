#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "windowmatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_stade_clicked();

    void on_match_clicked();

private:
    Ui::Window *ui;
    MainWindow *stade;
    WindowMatch *match;
};
#endif // WINDOW_H


