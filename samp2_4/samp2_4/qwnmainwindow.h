#ifndef QWNMAINWINDOW_H
#define QWNMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

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

private:
    QLabel *fLabCurFile;            // 状态栏里显示当前文件的Label
    QProgressBar *progressBarq;     // 在状态栏显示的进度条
    QSpinBox *spinFontSize;         // 字体大小 spinBox
    QFontComboBox *comboFont;       // 字体名称
    void iniUI();
};
#endif // QWNMAINWINDOW_H
