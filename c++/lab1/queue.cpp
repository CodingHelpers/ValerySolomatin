#include "queue.hpp"
#include <stdexcept>

Queue::Queue() : first(nullptr), last(nullptr), len(0) {
    init();
}

Queue::~Queue() {
    clear();
}

void
Queue::init() {
    // Если есть элементы, очищаем память
    if(first) {
        clear();
    }
}

void
Queue::clear() {
    QueueNode* target;

    // Проходим в цикле пока first != nullptr
    while(first) {
        target = first;       //< Сохраняем указатель на текущий элемент
        first  = first->next; //< Переходим на следующий элемент
        delete target;        //< Удаляем элемент по сохраненному указателю
    }

    first = nullptr;
    last  = nullptr;
    len   = 0;
}

void
Queue::push(int value) {
    // Создаем новую ноду
    QueueNode* new_node = new QueueNode(value);

    // Если очередь пуста (нет первого элемента)
    if(!first) {
        // Делаем новый элемент первым и последним
        first = last = new_node;
    } else {
        // Иначе ставим новый элемент в конец очереди
        last->next = new_node;
        last       = new_node;
    }

    // Увеличиваем счетчик элементов
    len++;
}

int
Queue::pop() {
    // Проверяем случай, если очередь пуста
    if(!first) {
        // Если такое произошло, выкидываем исключение
        throw std::runtime_error("Queue is empty, can't pop");
    }

    // Сохраняем указатель на первый элемент и значение
    QueueNode* node = first;
    int value = node->value;

    // Делаем первым элементом следующий за ним
    first = first->next;

    // Декрементируем длину
    len--;

    // Удаляем первый элемент
    delete node;

    return value;
}

size_t
Queue::length() {
    return len;
}


