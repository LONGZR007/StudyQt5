#include "qwnmainwindow.h"
#include "ui_qwnmainwindow.h"

QWNMainWindow::QWNMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWNMainWindow)
{
    ui->setupUi(this);
}

QWNMainWindow::~QWNMainWindow()
{
    delete ui;
}

