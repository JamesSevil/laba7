#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int evaluateExpression(string &s, int &i);

int calculate(string &s) {
    int i = 0;
    return evaluateExpression(s, i);
}

int evaluateExpression(string &s, int &i) {
    int result = 0;
    int sign = 1;  // 1(+)|-1(-)
    int num = 0;
 
    while (i < s.length()) {

        char c = s[i];

        if (isdigit(s[i])) { // Если число, то переводим его в int и записываем в переменную num
            num += atoi(&c);
        } else if (s[i] == '+') { // Если +, то записываем число в результат с соответствующим знаком, знак обновили
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (s[i] == '-') { // Если -, то записываем число в результат с соответствующим знаком, знак обновили
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (s[i] == '(') { // Если встречаем (, то переходим на следующий элемент и считаем значения в скобках через рекурсию. Она остановится на )
            i++;
            int nestedResult = evaluateExpression(s, i);
            result += sign * nestedResult;
            num = 0;
        } else if (s[i] == ')') { // Если встретили ), то записываем результат и возращаем его значения(для рекурсии)
            result += sign * num;
            return result;
        }
        i++; // переход на следующий элемент строки
    }

    return result + sign * num;
}

int main() {
    string expression;
    while (true) {
        bool check = true;
        cout << "Введите выражение: ";
        cin >> expression;
        if (expression.length()>3*(10^5)) { // проверка длины выражения
            cout << "Слишком мало или много аргументов у выражения!" << endl;
        } else {
            int i = 0;
            while (i < expression.length()) { // проверка на правильный ввод аргументов
                if (!isdigit(expression[i]) && expression[i] != '+' && expression[i] != '-' && expression[i] != '(' && expression[i] != ')') {
                    check = false;
                    break;
                }
                i++;
            }
            if (check == true) cout << "Результат: " << calculate(expression) << endl; // Вывод результата, если всё введено верно
            else cout << "Ошибка в вводе аргументов!" << endl; // Иначе вывод ошибки
        }
    }
    return 0;
}