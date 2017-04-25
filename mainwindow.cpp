#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float calculateVelocityAfter1(float initialVelocity1, float initialVelocity2, float mass1, float mass2) {
    return ((mass1 - mass2) * initialVelocity1 + 2 * mass2 * initialVelocity2) / (mass1 + mass2);
}

QString checkValues(float initialVelocity1, float initialVelocity2, float mass1, float mass2) {
    if (initialVelocity2 >= initialVelocity1 && initialVelocity1 > 0 && initialVelocity2 > 0) {
        return "First thing is slower or has same velocity - no collision";
    }
    else if (initialVelocity1 <= initialVelocity2 && initialVelocity1 < 0 && initialVelocity2 < 0) {
        return "Second thing is slower or has same velocity - no collision";
    }
    else if (initialVelocity1 <= 0 && initialVelocity2 >= 0) {
        return "Different dirrection - no collision";
    }
    else if (mass1 == 0 || mass2 == 0) {
        return "Mass cant be 0";
    }
    else {
        return "ok";
    }
}

void MainWindow::on_pushButton_clicked()
{
    float initialVelocity1 = ui->initVelocity1->text().toFloat();
    float initialVelocity2 = ui->initVelocity2->text().toFloat();
    float mass1 = ui->mass1->text().toFloat();
    float mass2 = ui->mass2->text().toFloat();

    QString checkResult = checkValues(initialVelocity1, initialVelocity2, mass1, mass2);
    if (checkResult == "ok") {
        float velocityAfter1 = calculateVelocityAfter1(initialVelocity1, initialVelocity2, mass1, mass2);
        float velocityAfter2 = velocityAfter1 + initialVelocity1 - initialVelocity2;
        ui->velocityResult1->setText(QString::number(velocityAfter1));
        ui->velocityResult2->setText(QString::number(velocityAfter2));
    }
    else {
       ui->velocityResult1->clear();
       ui->velocityResult2->clear();
       QMessageBox::warning(this, "Warning", checkResult);
    }
}
