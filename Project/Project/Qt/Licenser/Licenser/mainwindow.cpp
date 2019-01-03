
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

#include <dlfcn.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes_crypto.h"

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

void MainWindow::on_calculateButton_clicked()
{
    void *handle;
    int (*func)(int, int);
    int res;
    bool ok;

    int number1 = ui->numberTextEdit1->toPlainText().toInt(&ok);

    if (!ok) {
        QMessageBox::information(this, "Warning", "Please enter a valid number");
        return;
    }

    int number2 = ui->numberTextEdit2->toPlainText().toInt(&ok);

    if (!ok) {
        QMessageBox::information(this, "Warning", "Please enter a valid number");
        return;
    }

    // Free Version Add/Sub

    handle = dlopen(FILE_NAME_ADDSUB, RTLD_LAZY);

    if (!handle)
        return;

    *(void**)(&func) = dlsym(handle, "add");

    if (!func) {
        dlclose(handle);
        return;
    }

    res = func(number1, number2);
    ui->addResultLabel->setText(QString::number(res));

    *(void**)(&func) = dlsym(handle, "sub");

    if (!func) {
        dlclose(handle);
        return;
    }

    res = func(number1, number2);
    ui->subResultLabel->setText(QString::number(res));

    dlclose(handle);

    // Licensed Version Mul/Div
    handle = dlopen(FILE_NAME_MULDIV, RTLD_LAZY);

    if (!handle)
        return;

    *(void**)(&func) = dlsym(handle, "mul");

    if (!func) {
        dlclose(handle);
        return;
    }

    res = func(number1, number2);
    ui->mulResultLabel->setText(QString::number(res));

    if (number2 != 0) {
        *(void**)(&func) = dlsym(handle, "div");

        if (!func) {
            dlclose(handle);
            return;
        }

        res = func(number1, number2);
        ui->divResultLabel->setText(QString::number(res));
    } else {
        ui->divResultLabel->setText("-");
    }

    dlclose(handle);
}

void MainWindow::on_licenseButton_clicked()
{
    QString licenceKey = ui->licenseTextEdit->toPlainText().trimmed();

    if (licenceKey == "") {
        QMessageBox::information(this, "Warning", "Please Enter License Key");
        return;
    }

    QFile fileEnc(FILE_NAME_MDENCR);

    if (!fileEnc.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, "Warning", "Files are missing");
        return;
    }

    QByteArray fileEncba = fileEnc.readAll();

    fileEnc.close();

    {
        EVP_CIPHER_CTX *en, *de;

        unsigned int salt[] = {14531453, 35413541};
        char *key_data;
        int key_data_len;

        int len;

        uint8_t *plaintext;
        uint8_t *ciphertext;

        QByteArray licba = licenceKey.toLocal8Bit();
        key_data = licba.data();
        key_data_len = licenceKey.length();

        if (aes_init((uint8_t *) key_data, key_data_len, (unsigned char *) &salt, &en, &de)) {
            QMessageBox::information(this, "Warning", "Couldn't initialize AES cipher");
            return;
        }

        ciphertext = (uint8_t *) fileEncba.data();
        len = fileEncba.length();

        plaintext = aes_decrypt(de, ciphertext, &len);

        QByteArray fileDecba = QByteArray((char *) plaintext, len);

        QFile fileDec(FILE_NAME_MULDIV);

        if (!fileDec.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, "Warning", "File cannot be opened");
            return;
        }

        fileDec.write(fileDecba);
        fileDec.close();

        free(plaintext);

        EVP_CIPHER_CTX_cleanup(en);
        EVP_CIPHER_CTX_cleanup(de);
    }

    {
        void *handle;
        int (*func)(int, int);

        handle = dlopen(FILE_NAME_MULDIV, RTLD_LAZY);

        if (!handle) {
            QMessageBox::information(this, "Warning", "Invalid License Key");
            return;
        }

        *(void**)(&func) = dlsym(handle, "mul");

        if (!func) {
            QMessageBox::information(this, "Warning", "Invalid License Key");
            dlclose(handle);
            return;
        }

        dlclose(handle);

        QMessageBox::information(this, "Notice", "License Key key successfully applied");
    }
}
