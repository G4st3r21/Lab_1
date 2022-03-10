#include <iostream>

using namespace std;

double readNumber(char letter) {
    double number;
    cout << "Введите число " << letter << ": ";
    cin >> number;

    return number;
}

char readSign() {
    char sign;
    cout << "Введите знак" << ": ";
    cin >> sign;

    return sign;
}

void printDivisionByZeroError() {
    cout << "Второе число при делении не может быть нулем" << endl;
}

void printSignError() {
    cout << "Введите пожалуйста один из следующих знаков: '+', '-', '*', '/'" << endl;
}

void printAnswer(double answerNumber) {
    cout << "Ответ: " << answerNumber << endl;
}

double calculate(double firstNumber, double secondNumber, char sign) {
    double answerNumber;
    switch (sign) {
        case '+': {
            answerNumber = firstNumber + secondNumber;
            break;
        }

        case '-': {
            answerNumber = firstNumber - secondNumber;
            break;
        }

        case '*': {
            answerNumber = firstNumber * secondNumber;
            break;
        }

        case '/': {
            if (secondNumber != 0) {
                answerNumber = static_cast<double>(firstNumber) / secondNumber;
            } else {
                printDivisionByZeroError();
                exit(1);
            }
            break;
        }

        default: {
            printSignError();
            exit(1);
        }
    }

    return answerNumber;
}

int main() {

    double firstNumber = readNumber('a');
    double secondNumber = readNumber('b');

    char sign = readSign();

    printAnswer(calculate(firstNumber, secondNumber, sign));

    return 0;
}
