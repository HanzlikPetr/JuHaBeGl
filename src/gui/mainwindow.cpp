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

void MainWindow::handleTextChangeOperator(QString change) {
    if(!lastOperator && !inRoot) {
        lastOperator = true;
        handleTextChange(change);
    }
}

void MainWindow::on_button0_clicked()
{
    handleTextChange("0");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button00_clicked()
{
    handleTextChange("00");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_buttonFloatDot_clicked()
{
    handleTextChangeOperator(".");
}

void MainWindow::on_button3_clicked()
{
    handleTextChange("3");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button2_clicked()
{
    handleTextChange("2");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button1_clicked()
{
    handleTextChange("1");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button6_clicked()
{
    handleTextChange("6");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button5_clicked()
{
    handleTextChange("5");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button4_clicked()
{
    handleTextChange("4");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button9_clicked()
{
    handleTextChange("9");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button8_clicked()
{
    handleTextChange("8");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_button7_clicked()
{
    handleTextChange("7");
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_buttonPlus_clicked()
{
    handleTextChangeOperator("+");
}

void MainWindow::on_buttonMinus_clicked()
{
    if (!inRoot){
        if(!lastOperator && !negativeNumber) {
            handleTextChangeOperator("-");
        } else if (!negativeNumber) {
            negativeNumber = true;
            handleTextChange("(-");
        } else {
            negativeNumber = false;
            lastOperator = false;
            handleTextChange(")");
        }
    }
}

void MainWindow::on_buttonMul_clicked()
{
    handleTextChangeOperator("*");
}

void MainWindow::on_buttonDiv_clicked()
{
    handleTextChangeOperator("/");
}

void MainWindow::on_buttonFac_clicked()
{
    handleTextChangeOperator("!");
}

void MainWindow::on_buttonPower_clicked()
{
    handleTextChangeOperator("^");
}

void MainWindow::on_buttonRoot_clicked()
{
    if(!inRoot && !lastOperator) {
        handleTextChangeOperator("^(1/");
        inRoot = true;
    } else if (inRoot) {
        handleTextChange(")");
        inRoot = false;
    }
}

void MainWindow::on_buttonAbs_clicked()
{
    lastOperator = false;
    if(!inAbs){
        handleTextChangeOperator("|");
        inAbs = true;
    } else {
        handleTextChange("|");
        inAbs = false;
    }
}

void MainWindow::on_buttonAprox_clicked()
{
    handleTextChangeOperator("≈");
}

