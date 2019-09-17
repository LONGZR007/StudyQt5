#ifndef QWDIGMANUAL_H
#define QWDIGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class QWDigManual : public QDialog
{
    Q_OBJECT

private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rButBlack;
    QRadioButton *rButRed;
    QRadioButton *rButBlue;
    QPlainTextEdit *textEdit;
    QPushButton *btnClose;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void iniUI();              //  UI 创建与初始化
    void iniSignalSlots();     // 初始化信号与槽的链接

private slots:
    void on_chkBoxUnder(bool checked);      // chkBoxUnder 的槽函数
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void setTextFontColor();               // QRadioButton 的槽函数

public:
    QWDigManual(QWidget *parent = nullptr);
    ~QWDigManual();
};
#endif // QWDIGMANUAL_H
