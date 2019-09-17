#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
      : QDialog(parent)
     , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->radioRed, SIGNAL(clicked()), this, SLOT(setFontColor()));
    connect(ui->radioBlack, SIGNAL(clicked()), this, SLOT(setFontColor()));
    connect(ui->radioBlue, SIGNAL(clicked()), this, SLOT(setFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}

/* 复选槽函数 */
void Dialog::on_checkBoxBold_clicked(bool checked)
{
      QFont font = ui->textEdit->font();

      font.setBold(checked);

      ui->textEdit->setFont(font);
}

void Dialog::on_checkBoxUnder_clicked(bool checked)
{
    QFont font = ui->textEdit->font();

    font.setUnderline(checked);

    ui->textEdit->setFont(font);

}

void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->textEdit->font();

    font.setItalic(checked);

    ui->textEdit->setFont(font);
}

/* 单选槽函数 */
void Dialog::setFontColor()
{
    QPalette plet = ui->textEdit->palette();

    if (ui->radioRed->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::red);
    }
    else if (ui->radioBlue->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::blue);
    }
    else if (ui->radioBlack->isChecked())
    {
        plet.setColor(QPalette::Text, Qt::black);
    }
    else
    {
        plet.setColor(QPalette::Text, Qt::black);
    }

    ui->textEdit->setPalette(plet);
}
