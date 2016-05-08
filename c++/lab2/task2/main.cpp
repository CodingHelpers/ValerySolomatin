#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
    // Создаем очереди
    Queue q1;
    Queue q2;

    // Вводим элементы очередей из stdin
    cout << "Enter Q1: ";
    cin  >> q1;
    cout << "Enter Q2: ";
    cin  >> q2;

    // Выводим очереди
    cout << endl
         << "Q1: " << q1 << endl
         << "Q2: " << q2 << endl
         << endl;

    // Сравниваем очереди
    cout << "Q1 == Q1: " << (q1 == q2 ? "true" : "false") << endl
         << "Q1 != Q2: " << (q1 != q2 ? "true" : "false") << endl << endl;

    // Создаем третью очередь и присваиваем ей q1
    Queue q3 = q1;
    cout << "Q3 = Q1" << endl
         << "Q3: " << q3 << endl << endl;

    // Присваваем третьей очереди q2
    q3 = q2;
    cout << "Q3 = Q2" << endl
         << "Q3: " << q3 << endl << endl;

    // Добавляем элемент третьей очереди оператором +
    q3 = q3 + 10;
    cout << "Q3 = Q3 + 10" << endl
         << "Q3: " << q3 << endl << endl;

    // Добавляем еще один оператором +=
    q3 += 20;
    cout << "Q3 += 20" << endl
         << "Q3: " << q3 << endl << endl;

    // Умножаем все элементы q3 на 100
    q3 = q3 * 100;
    cout << "Q3 = Q3 * 100" << endl
         << "Q3: " << q3 << endl << endl;

    // Извлекаем элемент
    int E = q3--;
    cout << "E = Q3--" << endl
         << "E: " << E << endl
         << "Q3: " << q3 << endl << endl;

    return 0;
}
