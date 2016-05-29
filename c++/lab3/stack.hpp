#ifndef STACK_H
#define STACK_H
#include "list.hpp"

class Stack : public List {
public:
    Stack() {}

    virtual void push(const float& val) {
        // Заносим элемент в список слева
        this->pushLeft(val);
    }

    virtual float pop() {
        // Извлекаем и сохраняем значение слева (First In Last Out)
        float value = this->peekLeft();

        // Удаляем элемент слева
        this->popLeft();

        // Возвращаем значение
        return value;
    }
};
#endif // SfloatACK_H
