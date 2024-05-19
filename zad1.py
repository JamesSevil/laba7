def lastnum(num):  # последняя цифра числа
    return num % 10

def firstnum(num):  # первая цифра числа
    while num >= 10:
        num //= 10
    return num

def getposledov(nums, posled, num, i):  # получение последовательности
    last = lastnum(num)
    for j in range(len(nums)):  # сравниваем последнюю цифру числа с первыми цифрами всех чисел массива
        first = firstnum(nums[j])
        if last == first and num != nums[j]:  # Если найдено, то добавим число в последовательность
            for l in range(len(nums)):  # убираем повторения
                if nums[l] == num:
                    nums[l] = 0
            posled.append(num)
            num = nums[j]
            break  # выход из цикла, чтобы не было повторов

    if not posled:  # если последовательность пуста(не нашли подходящие числа для числа)
        i += 1  # то добавляем счетчик и не даём уйти за границы
        if i <= len(nums):
            getposledov(nums, posled, nums[i], i)  # если счётчик впорядке, то запускаем рекурсию
        else:
            print("не найдена")  # ушли за счётчик и последовательность в итоге пуста - нельзя составить последовательность
    else:
        i += 1  # иначе повторяем тоже самое, только уже для найденного числа последовательности, чтобы продлить последовательность
        if i <= len(nums):
            getposledov(nums, posled, num, i)
        else:
            posled.append(num)
            for k in posled:
                print(k, end=" ")


nums = [101, 51, 15, 107, 89]  # 101 15 51 107
posled = []
i = 0
print("Последовательность: ", end="")
getposledov(nums, posled, nums[i], i)