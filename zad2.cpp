#include <iostream>
#include <string>

using namespace std;

int Expression(string &s, int &i);

int calculate(string &s) {
    int i = 0;
    return Expression(s, i);
}

int Expression(string &s, int &i) {
    int result = 0;
    int num = 0;
    int sign = 1;

    string C;

    while (i < s.length()) {

        char c = s[i];

        if (isdigit(c)) { // Если символ - число, то добавляем его в строку и переводим в int
            C += c;
            num = stoi(C);
        } else if ((c == '-' && i == 0) || (c == '-' && s[i+1] == '(')) { // цикл для корректной работы калькулятора( - в самом начале, - перед '(' )
            sign = -1;
        } else if (c == '+' && s[i+1] == '(') { // цикл для корректной работы калькулятора( + перед '(' )
            sign = 1;
        } else if (c == '+') { // Если +, то...
            num = stoi(C); // переводим число в строку(ещё раз, чтобы он считал также числа, состоящие из 2+ цифр)
            C = ""; // обнуляем строку
            result += sign * num; // записываем результат
            num = 0; // обнуляем промежуточную переменную num
            sign = 1; // обновляем знак
        } else if (c == '-') { // Если -, то повторяем действия как с +, только меняем знак
            num = stoi(C);
            C = ""; 
            result += sign * num; 
            num = 0; 
            sign = -1; 
        } else if (c == '(') { // Если (, то запускаем рекурсию и высчитываем значение в скобках
            i++; // переход к следующему элементу
            int resultInSkobka = Expression(s, i); // рекурсия
            result += sign * resultInSkobka; // значение рекурсии добавляем в общий результат
        } else if (c == ')') { // Если ), то рекурсия заканчивается и записывается результат рекурсии
            result += sign * num;
            return result;
        }
        
        i++;
    }

    return result + sign * num;
}

int main() {
    setlocale(LC_ALL, "Rus");

    string expression; // выражение
    while (true) {
        bool check = true;
        cout << "Введите выражение: ";
        cin >> expression;
        if (expression.length()>3*1e5) { // проверка длины выражения
            cout << "Слишком много аргументов у выражения!" << endl;
        } else {
            int j = 0;
            while (j < expression.length()) { // проверка на правильный ввод аргументов
                if (!isdigit(expression[j]) && expression[j] != '+' && expression[j] != '-' && expression[j] != '(' && expression[j] != ')') {
                    check = false;
                    break;
                }
                j++;
            }
            if (check == true) cout << "Результат: " << calculate(expression) << endl << endl; // Вывод результата, если всё введено верно
            else cout << "Ошибка в вводе аргументов!" << endl << endl; // Иначе вывод ошибки
        }
    }

    return 0;
}