#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define FILE_NAME_ADDSUB    "./libaddsub.so"
#define FILE_NAME_MULDIV    "./libmuldiv.so"
#define FILE_NAME_MDENCR    "./libmuldiv_enc.so"

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
    void on_calculateButton_clicked();

    void on_licenseButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
