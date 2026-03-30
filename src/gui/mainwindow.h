#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    /**
     * @brief Add "0" to our lineEdit (result)
     */
    void on_button0_clicked();

    /**
     * @brief Add "00" to our lineEdit (result)
     */
    void on_button00_clicked();

    /**
     * @brief Add "." tou our lineEdit (result)
     */
    void on_buttonFloatDot_clicked();

    /**
     * @brief Add "3" tou our lineEdit (result)
     */
    void on_button3_clicked();

    /**
     * @brief Add "2" tou our lineEdit (result)
     */
    void on_button2_clicked();

    /**
     * @brief Add "1" tou our lineEdit (result)
     */
    void on_button1_clicked();

    /**
     * @brief Add "6" tou our lineEdit (result)
     */
    void on_button6_clicked();

    /**
     * @brief Add "5" tou our lineEdit (result)
     */
    void on_button5_clicked();

    /**
     * @brief Add "4" tou our lineEdit (result)
     */
    void on_button4_clicked();

    /**
     * @brief Add "9" tou our lineEdit (result)
     */
    void on_button9_clicked();

    /**
     * @brief Add "8" tou our lineEdit (result)
     */
    void on_button8_clicked();

    /**
     * @brief Add "7" tou our lineEdit (result)
     */
    void on_button7_clicked();

   private:
    /**
     * @brief Take string and add to existing string, after that set that string to lineEdit (result)
     * @param change - string that you want add
     */
    void handleTextChange (QString change);

    Ui::Calculator *ui;
    QString lineEditText = "";
};
#endif  // MAINWINDOW_H
