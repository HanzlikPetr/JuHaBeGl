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

bool MainWindow::handleTextChangeOperator(QString change) {
    if(!lastOperator && !inRoot && change != ".") {
        lastOperator = true;
        nextNumber = true;
        canUseDot = false;
        handleTextChange(change);
        return true;
    }

    if(change == "." && canUseDot && !inRoot) {
        lastOperator = true;
        handleTextChange(change);
        canUseDot = false;
        return true;
    }

    return false;
}

void MainWindow::on_button0_clicked()
{
    if(nextNumber) {
        handleTextChange("0");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button00_clicked()
{
    if(nextNumber) {
        handleTextChange("00");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_buttonFloatDot_clicked()
{
    handleTextChangeOperator(".");
}

void MainWindow::on_button3_clicked()
{
    if(nextNumber){
        handleTextChange("3");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button2_clicked()
{
    if(nextNumber) {
        handleTextChange("2");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button1_clicked()
{
    if(nextNumber) {
        handleTextChange("1");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button6_clicked()
{
    if(nextNumber) {
        handleTextChange("6");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button5_clicked()
{
    if(nextNumber) {
        handleTextChange("5");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button4_clicked()
{
    if(nextNumber) {
        handleTextChange("4");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button9_clicked()
{
    if(nextNumber) {
        handleTextChange("9");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button8_clicked()
{
    if(nextNumber) {
        handleTextChange("8");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
}

void MainWindow::on_button7_clicked()
{
    if(nextNumber) {
        handleTextChange("7");
        canUseDot = true;
        if(!negativeNumber && !inAbs) lastOperator = false;
    }
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
            nextNumber = false;
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
    if(handleTextChangeOperator("!")) {
        lastOperator = false;
        nextNumber = false;
    }
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
    } else if (inRoot && !lastOperator) {
        handleTextChange(")");
        inRoot = false;
        lastOperator = false;
        nextNumber = false;
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

void MainWindow::on_buttonClear_clicked()
{
    lineEditText = "";
    ui->result->clear();
    lastOperator = true;
    inRoot = false;
    negativeNumber = false;
    inAbs = false;
    canUseDot = false;
    nextNumber = true;
}

void MainWindow::on_buttonAC_clicked()
{
    handleTextChange(lastResult);
    if(!negativeNumber && !inAbs) lastOperator = false;
}

void MainWindow::on_buttonEq_clicked()
{
    QString result = "TODO";
    lastResult = result;
    lastOperator = false;
    inAbs = false;
    inRoot = false;
    negativeNumber = false;
    canUseDot = false;
    nextNumber = false;

    ui->histResult->addItem(lineEditText + " = " + result);
    ui->histResult->scrollToBottom();

    if (ui->histResult->count() > 50) {
        delete ui->histResult->takeItem(0);
    }

    ui->result->setText(result);
    lineEditText = result;
}

