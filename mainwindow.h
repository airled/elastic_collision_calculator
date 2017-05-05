#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    float mass1;
    float mass2;
    float initialVelocity1;
    float initialVelocity2;
    float finalVelocity1;
    float finalVelocity2;
    float initialMomentum1;
    float initialMomentum2;
    float finalMomentum1;
    float finalMomentum2;

    void getInitialValues();
    QString checkInitialValues();
    void calculateFinalVelocities();
    void calculateInitialMomentums();
    void calculateFinalMomentums();
    void showResults();
    void clearResults();
};

#endif // MAINWINDOW_H
