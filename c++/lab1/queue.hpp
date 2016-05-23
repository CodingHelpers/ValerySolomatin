#ifndef QUEUE_H
#define QUEUE_H
#include <stdint.h>
#include <stddef.h>


struct QueueNode {
    QueueNode(float v) : value(v), next(nullptr) {}

    float      value;
    QueueNode* next;
};

class Queue {
public:
    Queue();

    // Деструктор освободит память при уничтожении объекта
    ~Queue();

    void clear();       //< Очищение памяти, выделенной под ноды

    void  push(float value);
    float pop();

    size_t length();

protected:
    QueueNode* first;
    QueueNode* last;    //< Храним последний элемент для более быстрого доступа при добавлении новых

private:
    size_t len;
};

#endif // QUEUE_H
