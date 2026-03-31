#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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

   protected:
    /**
     * @brief Handles keyboard input for calculator operations.
     * * Maps physical key presses (numbers, operators, Enter, Backspace)
     * to their corresponding UI button clicks using animation.
     * * @param event The key event containing information about the pressed key.
     */
    void keyPressEvent(QKeyEvent *event) override;

   private slots:
    /**
     * @brief Adds the digit "0" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button0_clicked();

    /**
     * @brief Adds "00" to the current expression.
     * * Appends the digits if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button00_clicked();

    /**
     * @brief Adds a decimal point "." to the current expression.
     * * Internally processed as an operator to prevent consecutive placements.
     * Requires the `canUseDot` flag to be true.
     */
    void on_buttonFloatDot_clicked();

    /**
     * @brief Adds the digit "3" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button3_clicked();

    /**
     * @brief Adds the digit "2" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button2_clicked();

    /**
     * @brief Adds the digit "1" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button1_clicked();

    /**
     * @brief Adds the digit "6" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button6_clicked();

    /**
     * @brief Adds the digit "5" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button5_clicked();

    /**
     * @brief Adds the digit "4" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button4_clicked();

    /**
     * @brief Adds the digit "9" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button9_clicked();

    /**
     * @brief Adds the digit "8" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button8_clicked();

    /**
     * @brief Adds the digit "7" to the current expression.
     * * Appends the digit if the `nextNumber` state allows it. Updates the
     * internal operator state and enables the use of a decimal point.
     */
    void on_button7_clicked();

    /**
     * @brief Adds the addition "+" operator to the current expression.
     * * Processed safely to avoid consecutive operator syntax errors.
     */
    void on_buttonPlus_clicked();

    /**
     * @brief Adds the subtraction "-" operator or begins a negative number.
     * * Depending on the current context, this either acts as a standard
     * mathematical subtraction or encapsulates the following number in
     * parentheses `(-` to represent a negative value.
     */
    void on_buttonMinus_clicked();

    /**
     * @brief Adds the multiplication "*" operator to the current expression.
     * * Processed safely to avoid consecutive operator syntax errors.
     */
    void on_buttonMul_clicked();

    /**
     * @brief Adds the division "/" operator to the current expression.
     * * Processed safely to avoid consecutive operator syntax errors.
     */
    void on_buttonDiv_clicked();

    /**
     * @brief Adds the factorial "!" operator to the current expression.
     * * Processed safely to avoid consecutive operator syntax errors.
     * Disables appending new numbers directly afterward.
     */
    void on_buttonFac_clicked();

    /**
     * @brief Adds the power "^" operator to the current expression.
     * * Processed safely to avoid consecutive operator syntax errors.
     */
    void on_buttonPower_clicked();

    /**
     * @brief Inserts an nth-root fractional exponent into the expression.
     * * On the first click, it appends `^(1/` to start the root exponent.
     * On the subsequent click, it closes the expression with `)` and prevents
     * direct appending of new numbers.
     */
    void on_buttonRoot_clicked();

    /**
     * @brief Inserts absolute value bars into the expression.
     * * Toggles between opening and closing absolute value bars `|`
     * depending on the current internal state.
     */
    void on_buttonAbs_clicked();

    /**
     * @brief Adds the approximation "≈" operator to the current expression.
     */
    void on_buttonAprox_clicked();

    /**
     * @brief Clears the current expression and resets the calculator state.
     * * Empties the input field and resets all internal tracking variables
     * (operator flags, brackets, etc.) to their default states.
     */
    void on_buttonClear_clicked();

    /**
     * @brief Inserts the result of the previous calculation.
     * * Acts as an 'Ans' feature, appending the last computed result
     * to the current expression.
     */
    void on_buttonAC_clicked();

    /**
     * @brief Evaluates the current expression and displays the final result.
     * * Clears internal state flags, appends the calculation to the history
     * widget (maintaining a maximum of 50 entries), and updates the
     * display line edit with the computed result.
     */
    void on_buttonEq_clicked();

    /**
     * @brief Removes the last character from the current expression.
     * * Deletes the rightmost character in the input string, updates the
     * display, and triggers a state recalculation to ensure continued
     * valid input.
     */
    void on_buttonBack_clicked();

   private:
    /**
     * @brief Appends a string to the expression and updates the display.
     * * @param change The string character(s) to be appended.
     */
    void handleTextChange(QString change);

    /**
     * @brief Safely appends a mathematical operator to the expression.
     * * Verifies that the previous character was not an operator and that
     * the expression is not currently inside a root denominator before
     * appending. Updates `lastOperator`, `nextNumber`, and `canUseDot` flags.
     * * @param change The operator string to be appended.
     * @return bool True if the operator was successfully appended, false otherwise.
     */
    bool handleTextChangeOperator(QString change);

    /**
     * @brief Recalculates internal state flags after a character deletion.
     * * Analyzes the remaining expression from right to left to correctly
     * restore flags such as `lastOperator`, `canUseDot`, `inRoot`, `inAbs`,
     * and `negativeNumber` based on the context of the remaining characters.
     */
    void updateFlagsAfterBackspace();

    Ui::Calculator *ui;
    QString lineEditText = "";
    QString lastResult = "";

    /**
     * @brief Flag indicating if the last added character was an operator.
     */
    bool lastOperator = true;

    /**
     * @brief Flag indicating if the expression is currently formatting a root.
     */
    bool inRoot = false;

    /**
     * @brief Flag indicating if currently formatting a negative number.
     */
    bool negativeNumber = false;

    /**
     * @brief Flag indicating if currently inside absolute value bars.
     */
    bool inAbs = false;

    /**
     * @brief Flag indicating if a decimal point can be safely added to the current number.
     */
    bool canUseDot = false;

    /**
     * @brief Flag indicating if appending a new digit or number is currently allowed.
     */
    bool nextNumber = true;
};
#endif  // MAINWINDOW_H
