#ifndef QUEUE_H
#define QUEUE_H
#include "list.hpp"

class Queue : public List {
public:
    Queue() {}

    virtual void push(const float& val) {
        // Заносим элемент в список справа
        this->pushRight(val);
    }

    virtual float pop() {
        // Извлекаем и сохраняем значение слева (First In First Out
        float value = this->peekLeft();

        // Удаляем элемент слева
        this->popLeft();

        // Возвращаем значение
        return value;
    }
};

#endif // QUEUE_H
