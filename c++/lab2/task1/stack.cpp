#include "stack.hpp"
#include <stdexcept>

Stack::Stack() : top(NULL), length(0) {}

// Копирующий конструктор
Stack::Stack(const Stack& from) : Stack() {
    Node* origin = from.top;
    while(origin) {
        push(origin->val);
        origin = origin->next;
    }
}

// Деструктор, освобождающий память, выделенную для нод
Stack::~Stack() {
    while(top) {
        pop();
    }
}

// Сначала реализуем функции вставки и извлечения, которые будут использоваться операторами

/* Вставка элемента */
void Stack::push(int i) {
    // Создаем ноду
    Node* node = new Node;
    node->val = i;
    node->next = NULL;

    // Находим предыдущую вершину
    Node* prevtop = NULL;;
    if(top) {
        prevtop = top;
    }

    // Делаем новую ноду вершиной
    top = node;

    // Стамим старую вершину следующей за новой
    node->next = prevtop;

    // Инкрементируем длину
    length++;
}

/* Просмотр первого элемента */
int Stack::peek() {
    // Проверяем стек на пустоту
    if(!top) {
        throw std::runtime_error("No elements in stack");
    }

    return top->val;
}

/* Извлечение первого элемента */
void Stack::pop() {
    // Проверяем стек на пустоту
    if(!top) {
        throw std::runtime_error("No elements in stack");
    }

    // Достаем вершину
    Node* node = top;

    // Делаем следующую ноду вершиной
    top = node->next;

    // Удаляем ноду
    delete node;

    // Декрементируем размер
    length--;
}

Stack& Stack::operator++() {
    push(0);
    return *this;
}

Stack Stack::operator++(int i) {
    // Копируем в новый список
    Stack old(*this);
    push(0);
    return old;
}

Stack& operator--(Stack& s) {
    s.pop();
    return s;
}

Stack operator--(Stack& s, int i) {
    Stack old(s);
    s.pop();
    return old;
}

bool operator!(const Stack& s) {
    return !s.length;
}
