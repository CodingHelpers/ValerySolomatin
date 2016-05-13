#ifndef QUEUE_H
#define QUEUE_H
#include "list.hpp"

template<typename T>
class Queue : public List<T> {
public:
    Queue() {}

    virtual void push(const T& val) {
        // Заносим элемент в список справа
        this->pushRight(val);
    }

    virtual T pop() {
        // Извлекаем и сохраняем значение слева (First In First Out
        T value = this->peekLeft();

        // Удаляем элемент слева
        this->popLeft();

        // Возвращаем значение
        return value;
    }
};

#endif // QUEUE_H
