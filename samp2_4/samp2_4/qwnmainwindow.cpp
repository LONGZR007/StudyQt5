#include "qwnmainwindow.h"
#include "ui_qwnmainwindow.h"
#include <iostream>

QWNMainWindow::QWNMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWNMainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

QWNMainWindow::~QWNMainWindow()
{
    delete ui;
}

void QWNMainWindow::iniUI()
{
    /* 在状态栏上增加标签 */
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件:");
    ui->statusBar->addWidget(fLabCurFile);    // 增加标签到状态栏

    /* 在状态栏上增加进度条 */
    progressBarq = new QProgressBar;
    progressBarq->setMaximumWidth(200);
    progressBarq->setMaximum(50);
    progressBarq->setMinimum(5);
    progressBarq->setValue(ui->textEdit->font().pointSize());
    ui->statusBar->addWidget(progressBarq);

    /* 在工具栏上增加SpinBox */
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();     // 在工具栏增加分栏符

    /* 增加字体选择 */
    ui->toolBar->addWidget(new QLabel(" 字体 "));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->textEdit);     // 这句是干嘛的？(让窗口居中)

    /* 槽连接信号 */
}

void QWNMainWindow::on_actBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if (checked)
    {
        fmt.setFontWeight(QFont::Bold);
    }
    else
    {
        fmt.setFontWeight(QFont::Normal);
    }

    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void QWNMainWindow::on_actItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();

    fmt.setFontItalic(checked);

    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void QWNMainWindow::on_actUnder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();

    fmt.setFontUnderline(checked);

    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void QWNMainWindow::iniSignalSlots()
{
    connect(spinFontSize, SIGNAL(valueChanged(int)), this, SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(on_comboFont_currentIndexChanged(const QString &)));
}


void QWNMainWindow::on_textEdit_copyAvailable(bool b)
{
    // 更新cut, copy, paste的enabled
    ui->actCopy->setEnabled(b);
    ui->actCut->setEnabled(b);
    ui->actPaste->setEnabled(b);
}

void QWNMainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt = ui->textEdit->currentCharFormat();

    ui->actItalic->setChecked(fmt.fontItalic());
    ui->actBold->setChecked(fmt.font().bold());
    ui->actItalic->setChecked(fmt.fontUnderline());
}

void QWNMainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBarq->setValue(aFontSize);
}

void QWNMainWindow::on_comboFont_currentIndexChanged(const QString &argl)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(argl);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}
