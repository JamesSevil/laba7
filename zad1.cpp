#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lastnum(int num) { // последняя цифра числа
    return num % 10;
}

int firstnum(int num) { // первая цифра числа
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

void getposledov(vector<int> nums, vector<int> posled, int num, int i) { // получение последовательности
    
    int last = lastnum(num);
    for (int j = 0; j < nums.size(); ++j) { // сравниваем последнюю цифру числа с первыми цифрами всех чисел массива
        int first = firstnum(nums[j]);
        if (last == first && num != nums[j]) { // Если найдено, то добавим число в последовательность
            for (int l = 0; l < nums.size(); ++l) { // убираем повторения
                if (nums[l] == num) {
                    nums[l] = 0;
                }
            }
            posled.push_back(num);
            num = nums[j];
            break; // выход из цикла, чтобы не было повторов
        }
    }

    if (posled.empty()) { // если последовательность пуста(не нашли подходящие числа для числа)
        i++; // то добавляем счетчик и не даём уйти за границы
        if (i <= nums.size()) return getposledov(nums, posled, nums[i], i); // если счётчик впорядке, то запускаем рекурсию
        else cout << "не найдена"; // ушли за счётчик и последовательность в итоге пуста - нельзя составить последовательность
    } else {
        i++; // иначе повторяем тоже самое, только уже для найденного числа последовательности, чтобы продлить последовательность
        if (i <= nums.size()) return getposledov(nums, posled, num, i);
        else {
            posled.push_back(num);
            for(int k : posled) cout << k << " ";
        }
    }

}

int main() {
    setlocale(LC_ALL, "Rus");

    vector<int> nums = {101, 51, 15, 107, 89}; // 101 15 51 107
    vector<int> posled;
    
    int i = 0;
    cout << "Последовательность: ";
    getposledov(nums, posled, nums[i], i);
    

    return 0;
}