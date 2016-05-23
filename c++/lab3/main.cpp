#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
using namespace std;

int main() {
    Queue<float> q;
    Stack<float> s;

    // Проверяем работу очереди.
    // Первыми должны выйти элементы, которые вошли первыми.
    for(int i = 1; i <= 5; i++) {
        q.push(i);
        cout << i << " -> Queue.push: " << q << endl;
    }

    // Извлекаем все значения, пока list не кинет исключение
    while(1) {
        try {
            float p = q.pop();
            cout << p << " <- Queue.pop:  " << q << endl;
        } catch(exception&) {
            break;
        }
    }

    // Если все верно, на экране должна быть видна рабора очереди.

    cout << endl;

    // Теперь проверяем работу стэка.
    // Первыми должны выйти элементы, которые вошли последними

    for(int i = 1; i <= 5; i++) {
        s.push(i);
        cout << i <<" -> Stack.push: " << s << endl;
    }

    // Извлекаем все значения, пока list не кинет исключение
    while(1) {
        try {
            float p = s.pop();
            cout << p << " <- Stack.pop:  " << s << endl;
        } catch(exception&) {
            break;
        }
    }

    // Если все верно, на экране должна быть видна работа стека

    return 0;
}
