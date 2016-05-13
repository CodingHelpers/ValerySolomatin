#ifndef STACK_H
#define STACK_H
#include "list.hpp"

template<typename T>
class Stack : public List<T> {
public:
    Stack() {}

    virtual void push(const T& val) {
        // Заносим элемент в список слева
        this->pushLeft(val);
    }

    virtual T pop() {
        // Извлекаем и сохраняем значение слева (First In Last Out)
        T value = this->peekLeft();

        // Удаляем элемент слева
        this->popLeft();

        // Возвращаем значение
        return value;
    }
};
#endif // STACK_H
