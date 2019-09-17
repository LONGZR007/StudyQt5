#include "qwdigmanual.h"
#include <QHBoxLayout>

QWDigManual::QWDigManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("Form created manually");
}

QWDigManual::~QWDigManual()
{
}

void QWDigManual::iniUI()
{
    /* 创建 3 个 CheckBox，并水平布局 */
    chkBoxBold = new QCheckBox(tr("Bold"));
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    QHBoxLayout *Hlay1 = new QHBoxLayout;
    Hlay1->addWidget(chkBoxUnder);
    Hlay1->addWidget(chkBoxItalic);
    Hlay1->addWidget(chkBoxBold);

    /* 创建 3 单选按钮，并水平布局 */
    rButBlack = new QRadioButton(tr("Black"));
    rButBlack->setChecked(true);    // 默认选中第一个
    rButBlue = new QRadioButton(tr("Blue"));
    //rButBlue->setChecked(true);
    rButRed = new QRadioButton(tr("Red"));
    //rButRed->setChecked(true);
    QHBoxLayout *Hlay2 = new QHBoxLayout;
    Hlay2->addWidget(rButBlack);
    Hlay2->addWidget(rButBlue);
    Hlay2->addWidget(rButRed);

    /* 创建 3 个按钮，并水平布局 */
    btnOK = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout *Hlay3 = new QHBoxLayout;
    Hlay3->addStretch();
    Hlay3->addWidget(btnOK);
    Hlay3->addWidget(btnCancel);
    Hlay3->addStretch();
    Hlay3->addWidget(btnClose);

    /* 创建文本框，并初始化字体 */
    textEdit = new QPlainTextEdit("Hello,world\n\rIt is my demo");
    //textEdit->setPlainText("Hello,world\n\rIt is my demo");
    QFont font = textEdit->font();
    font.setPointSize(20);
    textEdit->setFont(font);

    /* 创建 垂直布局，并设置为主布局 */
    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(Hlay1);
    VLay->addLayout(Hlay2);
    VLay->addWidget(textEdit);
    VLay->addLayout(Hlay3);
    setLayout(VLay);
}

void QWDigManual::iniSignalSlots()
{
    connect(rButBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rButRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rButBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnder(bool)));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}



void QWDigManual::on_chkBoxUnder(bool checked)
{
    QFont font = textEdit->font();

    font.setUnderline(checked);

    textEdit->setFont(font);
}

void QWDigManual::on_chkBoxItalic(bool checked)
{
    QFont font = textEdit->font();

    font.setItalic(checked);

    textEdit->setFont(font);
}

void QWDigManual::on_chkBoxBold(bool checked)
{
    QFont font = textEdit->font();

    font.setBold(checked);

    textEdit->setFont(font);
}

void QWDigManual::setTextFontColor()
{
    QPalette plet = textEdit->palette();

    if (rButRed->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::red);
    }
    else if (rButBlue->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::blue);
    }
    else if (rButBlack->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::black);
    }
    else
    {
        plet.setColor(QPalette::Text, Qt::black);
    }

    textEdit->setPalette(plet);
}

