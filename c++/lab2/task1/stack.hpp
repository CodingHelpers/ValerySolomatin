#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

class Stack {
public:
    Stack();
    Stack(const Stack& from);
    ~Stack();

    Stack& operator++();     // Префиксный
    Stack  operator++(int);  // Постфиксный

    friend Stack& operator--(Stack&);
    friend Stack  operator--(Stack&, int);

    friend bool   operator!(const Stack&);

    void push(int);
    int  peek();
    void pop();

protected:

    struct Node {
        int   val;
        Node* next;
    };

    Node*  top;
    size_t length;
};

#endif // QUEUE_H
