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
    void iniSignalSlots();
private slots:
    void on_actBold_triggered(bool checked);  //粗体Action
    void on_actItalic_triggered(bool checked); //斜体Action
    void on_actUnder_triggered(bool checked);   //下划线Action
    void on_textEdit_copyAvailable(bool b);
    void on_textEdit_selectionChanged();

    void on_spinBoxFontSize_valueChanged(int aFontSize);
    void on_comboFont_currentIndexChanged(const QString &argl);
};
#endif // QWNMAINWINDOW_H
