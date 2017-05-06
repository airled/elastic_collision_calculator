#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/img/img/pic.jpg");
    int width = ui->pic->width();
    int height = ui->pic->height();
    ui->pic->setPixmap(pic.scaled(width, height, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getInitialValues()
{
    initialVelocity1 = ui->initVelocity1->text().toFloat();
    initialVelocity2 = ui->initVelocity2->text().toFloat();
    mass1 = ui->mass1->text().toFloat();
    mass2 = ui->mass2->text().toFloat();
}

QString MainWindow::checkInitialValues()
{
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

void MainWindow::calculateFinalVelocities()
{
    finalVelocity1 = ((mass1 - mass2) * initialVelocity1 + 2 * mass2 * initialVelocity2) / (mass1 + mass2);
    finalVelocity2 = finalVelocity1 + initialVelocity1 - initialVelocity2;
}

void MainWindow::calculateInitialMomentums()
{
    initialMomentum1 = initialVelocity1 * mass1;
    initialMomentum2 = initialVelocity2 * mass2;
}

void MainWindow::calculateFinalMomentums()
{
    finalMomentum1 = finalVelocity1 * mass1;
    finalMomentum2 = finalVelocity2 * mass2;
}

void MainWindow::showResults()
{
    ui->velocityResult1->setText(QString::number(finalVelocity1));
    ui->velocityResult2->setText(QString::number(finalVelocity2));
    ui->initialMomentum1->setText(QString::number(initialMomentum1));
    ui->initialMomentum2->setText(QString::number(initialMomentum2));
    ui->finalMomentum1->setText(QString::number(finalMomentum1));
    ui->finalMomentum2->setText(QString::number(finalMomentum2));
}

void MainWindow::clearResults()
{
    ui->velocityResult1->clear();
    ui->velocityResult2->clear();
    ui->initialMomentum1->clear();
    ui->initialMomentum2->clear();
    ui->finalMomentum1->clear();
    ui->finalMomentum2->clear();
}

void MainWindow::on_pushButton_clicked()
{
    getInitialValues();
    QString checkResult = checkInitialValues();
    if (checkResult == "ok") {
        calculateFinalVelocities();
        calculateInitialMomentums();
        calculateFinalMomentums();
        showResults();
    }
    else {
       clearResults();
       QMessageBox::warning(this, "Warning", checkResult);
    }
}
