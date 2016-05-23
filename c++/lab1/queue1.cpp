#include "queue1.hpp"
#include <iostream>

Queue1::Queue1() {
    // Вызываем конструктор базоового класса
    Queue();
}

float
Queue1::average() {
    float sum = 0.0;

    // Проходимся по каждому элементу
    const QueueNode* node = first;
    while(node) {
        sum += node->value;
        node = node->next;
    }

    return sum / length();
}

void
Queue1::printAverage() {
    std::cout << "Average of "<< length() << " elements: " << average() << std::endl;
}

