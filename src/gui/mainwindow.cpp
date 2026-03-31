#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);
    ui->result->setFocusPolicy(Qt::NoFocus);
    ui->histResult->setFocusPolicy(Qt::NoFocus);
    for (QPushButton *button : this->findChildren<QPushButton*>()) {
        button->setFocusPolicy(Qt::NoFocus);
    }
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    ui->buttonBack->setAutoRepeat(true);
    ui->buttonBack->setAutoRepeatDelay(300);
    ui->buttonBack->setAutoRepeatInterval(80);
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

void MainWindow::updateFlagsAfterBackspace()
{
    if (lineEditText.isEmpty()) {
        lastOperator = true;
        inRoot = false;
        negativeNumber = false;
        inAbs = false;
        canUseDot = false;
        nextNumber = true;
        return;
    }

    QChar lastChar = lineEditText.back();

    QString operators = "+-*/^(";
    if (operators.contains(lastChar)) {
        lastOperator = true;
        nextNumber = true;
    } else if (lastChar == '!' || lastChar == ')' || lastChar == '|') {
        lastOperator = false;
        nextNumber = false;
    } else {
        lastOperator = false;
        nextNumber = true;
    }

    canUseDot = true;
    if (!nextNumber) {
        canUseDot = false;
    } else {
        for (int i = lineEditText.length() - 1; i >= 0; --i) {
            QChar c = lineEditText.at(i);
            if (c == '.') {
                canUseDot = false;
                break;
            }
            if (!c.isDigit()) {
                break;
            }
        }
    }

    int absCount = lineEditText.count('|');
    inAbs = (absCount % 2 != 0);

    inRoot = false;
    negativeNumber = false;
    int openBrackets = 0;

    for (int i = lineEditText.length() - 1; i >= 0; --i) {
        if (lineEditText.at(i) == ')') {
            openBrackets--;
        } else if (lineEditText.at(i) == '(') {
            openBrackets++;
            if (openBrackets > 0) {
                if (i + 1 < lineEditText.length() && lineEditText.at(i+1) == '-') {
                    negativeNumber = true;
                }
                else if (i > 0 && lineEditText.at(i-1) == '^') {
                    inRoot = true;
                }
                break;
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_0: ui->button0->animateClick(); break;
        case Qt::Key_1: ui->button1->animateClick(); break;
        case Qt::Key_2: ui->button2->animateClick(); break;
        case Qt::Key_3: ui->button3->animateClick(); break;
        case Qt::Key_4: ui->button4->animateClick(); break;
        case Qt::Key_5: ui->button5->animateClick(); break;
        case Qt::Key_6: ui->button6->animateClick(); break;
        case Qt::Key_7: ui->button7->animateClick(); break;
        case Qt::Key_8: ui->button8->animateClick(); break;
        case Qt::Key_9: ui->button9->animateClick(); break;

        case Qt::Key_Plus:     ui->buttonPlus->animateClick(); break;
        case Qt::Key_Minus:    ui->buttonMinus->animateClick(); break;
        case Qt::Key_Asterisk: ui->buttonMul->animateClick(); break;
        case Qt::Key_Slash:    ui->buttonDiv->animateClick(); break;
        case Qt::Key_Exclam:   ui->buttonFac->animateClick(); break;

        case Qt::Key_Enter:
        case Qt::Key_Return:
            ui->buttonEq->animateClick();
            break;

        case Qt::Key_Backspace:
            ui->buttonBack->animateClick();
            break;

        case Qt::Key_Period:
        case Qt::Key_Comma:
            ui->buttonFloatDot->animateClick();
            break;

        default:
            QMainWindow::keyPressEvent(event);
            break;
    }
}

void MainWindow::on_buttonBack_clicked()
{
    if (!lineEditText.isEmpty()) {
        lineEditText.chop(1);
        ui->result->setText(lineEditText);
        updateFlagsAfterBackspace();
    }
}
