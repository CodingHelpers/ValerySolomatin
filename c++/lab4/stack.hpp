#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include <iostream>


// Шаблонный класс Стек
template<typename T>
class Stack {
public:
    Stack() : length(0), bottom(nullptr), top(nullptr) {}
    ~Stack() {
        while(length) {
            pop();
        }
    }

    /* Добавление элемента, принимает константную ссылку на данные */
    void push(const T& val) {
        // Создаем новую ноду
        StackNode* new_node = new StackNode(val);

        // Если стек пусе
        if(!top) {
            // Делаем новый элемент самым верхним и нижним
            bottom = top = new_node;
        } else {
            // Иначе ставим новый элемент наверх
            top->next = new_node;
            new_node->prev = top;
            top    = new_node;
        }

        // Увеличиваем счетчик элементов
        length++;
    }

    /* Извлечение значения элемента с вершины стека, возвращает константную ссылку на данные элемента */
    const T& peek() const {
        if(!top) {
            throw std::runtime_error("Stack is empty");
        }
        return top->value;
    }

    /* Удаление элемента */
    void pop() {
        if(!top) {
            throw std::runtime_error("Stack is empty");
        }

        // Сохраняем указатель на вершину
        StackNode* tmp = top;

        // Делаем следущий элемент вершиной
        top = top->prev;
        if(top) {
            top->next = nullptr;
        }

        // Освобождаем память удаляемого элемента
        delete tmp;
        length--;
    }

    unsigned len() const {
        return length;
    }

    /* Оператор вывода стека в поток */
    friend std::ostream& operator<< (std::ostream& os, const Stack<T>& lst) {
        StackNode* node = lst.bottom;
        os << "[ ";

        // Проходим по всем элементам от вершины до дня
        for(size_t i = 0; i < lst.length; i++) {
            /// Выводим значение и разделитель
            os << node->value << " ";

            /// Переходим к следующему элементу вниз по стеку
            node = node->next;
        }

        os << "]";
        return os;
    }

private:
    struct StackNode {
        StackNode(const T& val) : value(val), prev(nullptr), next(nullptr) {}

        T value;
        StackNode* prev;
        StackNode* next;
    };

    unsigned length;
    StackNode* bottom;
    StackNode* top;
};

#endif // STACK_H
