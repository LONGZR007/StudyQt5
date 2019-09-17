#ifndef QWNMAINWINDOW_H
#define QWNMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QWNMainWindow; }
QT_END_NAMESPACE

class QWNMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWNMainWindow(QWidget *parent = nullptr);
    ~QWNMainWindow();

private:
    Ui::QWNMainWindow *ui;
};
#endif // QWNMAINWINDOW_H
