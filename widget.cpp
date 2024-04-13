#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);

    ui->pbMilk->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    if(money >= 100) {
        ui->pbCoffee->setEnabled(true);
        if(money >= 150) {
            ui->pbTea->setEnabled(true);
            if(money >= 200) {
                ui->pbMilk->setEnabled(true);
            }
        }
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    char buf[10000];
    sprintf(buf, "500\t: %d\n100\t: %d\n50\t: %d\n10\t: %d", money/500, money%500/100, money%100/50, money%50/10);
    QMessageBox mb;
    mb.information(this, "Reset", buf);
    changeMoney(-money);
}

