#ifndef QUEUE_H
#define QUEUE_H
#include <stdint.h>
#include <stddef.h>


struct QueueNode {
    QueueNode(int v) : value(v), next(nullptr) {}

    int        value;
    QueueNode* next;
};

class Queue {
public:
    Queue();

    // Деструктор освободит память при уничтожении объекта
    // Он объявлен виртуальным, чтобы при наследовании не нарушися порядок вызова деструкторов
    virtual ~Queue();

    void init();
    void clear();       //< Очищение памяти, выделенной под ноды

    void push(int value);
    int  pop();

    size_t length();

protected:
    QueueNode* first;
    QueueNode* last;    //< Храним последний элемент для более быстрого доступа при добавлении новых

private:
    size_t len;
};

#endif // QUEUE_H
