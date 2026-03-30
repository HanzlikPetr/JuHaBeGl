#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::handleTextChange(QString change)
{
    lineEditText += change;
    ui->result->setText(lineEditText);
}

void MainWindow::on_button0_clicked()
{
    handleTextChange("0");
}

void MainWindow::on_button00_clicked()
{
    handleTextChange("00");
}

void MainWindow::on_buttonFloatDot_clicked()
{
    handleTextChange(".");
}

void MainWindow::on_button3_clicked()
{
    handleTextChange("3");
}

void MainWindow::on_button2_clicked()
{
    handleTextChange("2");
}

void MainWindow::on_button1_clicked()
{
    handleTextChange("1");
}

void MainWindow::on_button6_clicked()
{
    handleTextChange("6");
}

void MainWindow::on_button5_clicked()
{
    handleTextChange("5");
}

void MainWindow::on_button4_clicked()
{
    handleTextChange("4");
}

void MainWindow::on_button9_clicked()
{
    handleTextChange("9");
}

void MainWindow::on_button8_clicked()
{
    handleTextChange("8");
}

void MainWindow::on_button7_clicked()
{
    handleTextChange("7");
}

