#include <iostream>
#include "queue1.hpp"

using namespace std;

int main() {
    Queue1 q;

    // Число вводимых элементов
    uint cnt = 5;

    // Переменная для хранения ввода
    int  val;

    // Читаем ввод и закидываем введенные элементы в очередь
    cout << "Enter " << cnt << " elements: ";
    while(cnt-- ) {
        cin >> val;
        q.push(val);
    }

    // Выводим среднее арифметическое введенных чисел
    q.printAverage();

    // Вытаскиваем первое значение
    std::cout << "Popped " << q.pop() << endl;

    // Выводим среднее арифметическое без первого значения
    q.printAverage();

    return 0;
}
