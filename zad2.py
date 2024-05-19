def expression(s, i):
    result = 0
    num = 0
    sign = 1
    C = ""

    while i < len(s):
        c = s[i]

        if c.isdigit():  # Если символ - число, то добавляем его в строку и переводим в int
            C += c
            num = int(C)
        elif (c == '-' and i == 0) or (c == '-' and s[i+1] == '('):  # цикл для корректной работы калькулятора( - в самом начале, - перед '(' )
            sign = -1
        elif c == '+' and s[i+1] == '(':  # цикл для корректной работы калькулятора( + перед '(' )
            sign = 1
        elif c == '+':  # Если +, то...
            num = int(C)  # переводим число в строку(ещё раз, чтобы он считал также числа, состоящие из 2+ цифр)
            C = ""  # обнуляем строку
            result += sign * num  # записываем результат
            num = 0  # обнуляем промежуточную переменную num
            sign = 1  # обновляем знак
        elif c == '-':  # Если -, то повторяем действия как с +, только меняем знак
            num = int(C)
            C = ""
            result += sign * num
            num = 0
            sign = -1
        elif c == '(':  # Если (, то запускаем рекурсию и высчитываем значение в скобках
            i += 1  # переход к следующему элементу
            result_in_bracket = expression(s, i)  # рекурсия
            result += sign * result_in_bracket  # значение рекурсии добавляем в общий результат
        elif c == ')':  # Если ), то рекурсия заканчивается и записывается результат рекурсии
            result += sign * num
            return result
        
        i += 1

    return result + sign * num

def calculate(s):
    i = 0
    return expression(s, i)


while True:
    expression_input = input("Введите выражение: ")
    if len(expression_input) > 3 * 10**5:  # проверка длины выражения
        print("Слишком много аргументов у выражения!")
    else:
        check = all(c.isdigit() or c in "+-()" for c in expression_input)
        if check:
            print("Результат:", calculate(expression_input), "\n")
        else:
            print("Ошибка в вводе аргументов!\n")