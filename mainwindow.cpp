#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Contriver");
    QIcon icon("://resources/Contriver.png");
    setWindowIcon(icon);

    ui->textEdit->setStyleSheet("QTextEdit { padding-left:20; padding-top:20; padding-bottom:20; padding-right:20}");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fontBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}

void MainWindow::on_fontSizeBox_valueChanged(int arg1)
{
    ui->textEdit->setFontPointSize(arg1);
}

void MainWindow::on_boldButton_toggled(bool checked)
{
    if (checked)
        ui->textEdit->setFontWeight(80);
    else
        ui->textEdit->setFontWeight(1);
}

void MainWindow::on_italicButton_toggled(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}

void MainWindow::on_leftAllignButton_toggled(bool checked)
{
    if (checked)
        ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_centerAllignButton_toggled(bool checked)
{
    if (checked)
        ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_rightAllignButton_toggled(bool checked)
{
    if (checked)
        ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save As", "", "Text Document (*.txt)");

    if (filename.isEmpty()) {
        qDebug() << "error";
        return;
    }

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error";
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit;
    file.close();
}
