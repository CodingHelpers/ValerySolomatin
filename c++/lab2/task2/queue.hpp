#ifndef STACK_H
#define STACK_H
#include <stddef.h>
#include <iostream>

class Queue {
public:
    Queue();
    Queue(const Queue& from);
    ~Queue();

    Queue& operator+(int i);
    Queue& operator=(const Queue& from);

    friend Queue& operator+=(Queue& q, int i);
    friend Queue& operator*(Queue& q, int i);

    friend int operator--(Queue& q, int);

    friend bool operator==(const Queue& a, const Queue& b);
    friend bool operator!=(const Queue& a, const Queue& b);

    friend bool operator!(const Queue& q);

    friend std::ostream& operator<< (std::ostream& os, const Queue& q);
    friend std::istream& operator>> (std::istream& is, Queue& q);

    void push(int i);
    int  peek();
    void pop();
    void clear();

protected:
    void copy(const Queue& q);

    struct Node {
        int   val;
        Node* prev;
    };

    Node*  first;
    size_t length;
};

#endif // STACK_H
