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
    float calculateVelocityAfter1(float, float, float, float);
    void calculateInitialMomentums(float, float, float, float);
    void calculateFinalMomentums(float, float, float, float);
    QString checkValues(float, float, float, float);

};

#endif // MAINWINDOW_H
