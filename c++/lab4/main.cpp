#include <iostream>
#include "fastsort.hpp"
#include "stack.hpp"

using namespace std;

template<typename T>
ostream& operator<< (ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for(size_t i = 0; i < vec.size(); i++) {
        os << vec[i] << ", ";
    }
    return os << "]";
}

void test_sort() {
    cout << "Quich Sort:" << endl;

    // Создаем массив float
    std::vector<float> arr1 = {
        9, 1, 4.5, 91, 3.1, -10, 44, 23, 4
    };
    std::cout << "Float Array:        " << arr1 << endl;

    // Сортируем массив
    quicksort(arr1);
    std::cout << "Sorted Float Array: " << arr1 << endl;

    // Создаем массив int
    std::vector<int> arr2;
    for(int i = 0; i < 10; i++) {
        arr2.push_back(rand() % 100);
    }
    std::cout << "Int Array:          " << arr2 << endl;

    // Сортируем массив
    quicksort(arr2);
    std::cout << "Sorted Int Array:   " << arr2 << endl;

    // Создаем массив char
    std::vector<char> arr3;
    for(int i = 0; i < 10; i++) {
        arr3.push_back(65 + rand() % 10);
    }
    std::cout << "Char Array:         " << arr3 << endl;

    // Сортируем массив char
    quicksort(arr3);
    std::cout << "Sorted Char Array:  " << arr3 << endl;
}

void test_stack() {
    cout << "\n\n" << "Stack:" << endl;

    // Проверяем работу стэка float
    Stack<float> sf;
    for(float i = 1.1; i <= 10; i += 1.1) {
        sf.push(i);
        cout << i <<" -> Stack.push: " << sf << endl;
    }

    // Извлекаем все значения, пока list не кинет исключение
    while(1) {
        try {
            float p = sf.peek();
            sf.pop();
            cout << p << " <- Stack.pop:  " << sf << endl;
        } catch(exception&) {
            break;
        }
    }

    // Проверяем работу стэка int
    Stack<int> si;
    for(int i = 0; i <= 9; i += 1) {
        si.push(i);
        cout << i << " -> Stack.push: " << si << endl;
    }

    // Извлекаем все значения, пока list не кинет исключение
    while(1) {
        try {
            int p = si.peek();
            si.pop();
            cout << p << " <- Stack.pop:  " << si << endl;
        } catch(exception&) {
            break;
        }
    }

    // Проверяем работу стэка char
    Stack<char> sc;
    for(char i = 'A'; i <= 'A' + 10; i += 1) {
        sc.push(i);
        cout << i <<" -> Stack.push: " << sc << endl;
    }

    // Извлекаем все значения, пока list не кинет исключение
    while(1) {
        try {
            char p = sc.peek();
            sc.pop();
            cout << p << " <- Stack.pop:  " << sc << endl;
        } catch(exception&) {
            break;
        }
    }

}

int main() {
    srand(time(NULL));

    test_sort();
    test_stack();


    return 0;
}
