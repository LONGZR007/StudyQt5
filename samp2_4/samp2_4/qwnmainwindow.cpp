#include "qwnmainwindow.h"
#include "ui_qwnmainwindow.h"

QWNMainWindow::QWNMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWNMainWindow)
{
    ui->setupUi(this);
    iniUI();
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

    setCentralWidget(ui->textEdit);     // 这句是干嘛的？
}

