#include <iostream>
#include "stack.hpp"
using namespace std;



int main() {
    // Создаем новую очередб
    Stack q;

    if(!q) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    // Попытка достать элемент с постфиксным оператором не сработает,
    // так как в временной копии очереди, элемента еще не будет
    try {
        int i = (q++).peek();
        cout << "Peeked first element: " << i << endl;
    } catch (exception& e) {
        cout << "Failed to peek element: " << e.what() << endl;
    }

    // Префиксное удаление и попвтка достать элемент так же не сработает
    // так как временной копии тут нет и мы сразу удаляем элемент
    try {
        int i = (--q).peek();
        cout << "Peeked first element: " << i << endl;
    } catch (exception& e) {
        cout << "Failed to peek element: " << e.what() << endl;
    }

    // Стек снова пуст
    if(!q) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    // Префиксное добавление и попытка достать элемент будет успешны
    // так как сначала мы элемент добавим, потом извлечем, без временной копии
    try {
        int i = (++q).peek();
        cout << "Peeked first element: " << i << endl;
    } catch (exception& e) {
        cout << "Failed to peek element: " << e.what() << endl;
    }

    // Постфиксное удаление и попытка достать элемент будет успешны
    // так как пусть элемент и удален, он все еще есть во временной копии, с которой и работает peek()
    try {
        int i = (q--).peek();
        cout << "Peeked first element: " << i << endl;
    } catch (exception& e) {
        cout << "Failed to peek element: " << e.what() << endl;
    }

    // Стек снова пуст
    if(!q) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    return 0;
}
