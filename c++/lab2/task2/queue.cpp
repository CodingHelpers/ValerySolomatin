#include "queue.hpp"
#include <stdexcept>

Queue::Queue() : first(NULL), length(0) {}

// Копирующий конструктор
Queue::Queue(const Queue& from) : Queue() {
    copy(from);
}

// Деструктор, освобождающий память, выделенную для нод
Queue::~Queue() {
    clear();
}

// Сначала реализуем функции вставки и извлечения, которые будут использоваться операторами

/* Вставка элемента */
void Queue::push(int i) {
    // Создаем ноду
    Node* node = new Node;
    node->val = i;
    node->prev = NULL;

    // Если длина равна нулю, ставим эту ноду первой
    if(!length) {
        first = node;
    } else {
    // Иначе ставим ноду последней
        // Двигаемся до последней ноды
        Node* last = first;
        while(last->prev) { last = last->prev; }

        // Ставим новуб ноду после последней
        last->prev = node;
    }

    // Инкрементируем длину
    length++;
}


/* Просмотр первого элемента */
int Queue::peek() {
    // Проверяем очередь на пустоту
    if(!first) {
        throw std::runtime_error("No elements in Queue");
    }

    return first->val;
}

/* Извлечение первого элемента */
void Queue::pop() {
    // Проверяем очередь на пустоту
    if(!first) {
        throw std::runtime_error("No elements in Queue");
    }

    // Достаем первую ноду
    Node* node = first;

    // Делаем следующую ноду первой
    first = node->prev;

    // Удаляем ноду
    delete node;

    // Декрементируем размер
    length--;
}

/* Очистка очереди */
void Queue::clear() {
    while(first) {
        pop();
    }
}

/* Копирование очередей */
void Queue::copy(const Queue& from) {
    Node* origin = from.first;
    while(origin) {
        push(origin->val);
        origin = origin->prev;
    }
}


Queue& Queue::operator+(int i) {
    push(i);
    return *this;
}

Queue& Queue::operator=(const Queue& from) {
    // Проверяем на случай, если присвоение идет с самим собой
    if(&from == this) {
        return *this;
    }

    // Очищаем текущий список
    clear();

    // Копируем из переданного списка
    copy(from);

    return *this;
}

Queue& operator+=(Queue& q, int i) {
    // Используем определенный выше оператор сложения
    return q + i;
}

Queue& operator*(Queue& q, int i) {
    // Проходим по всем нодам и умножаем каждую
    Queue::Node* node = q.first;
    while(node) {
        node->val *= i;
        node = node->prev;
    }

    return q;
}

int operator--(Queue& q, int) {
    int val = q.peek();
    q.pop();
    return val;
}

bool operator==(const Queue& a, const Queue& b) {
    // Сравниваем длины
    if(a.length != b.length) {
        return false;
    }

    // Если длины совпали, сравниваем поэлементно
    Queue::Node* na = a.first;
    Queue::Node* nb = b.first;
    while(na && nb) {
        if(na->val != nb->val) {
            return false;
        }

        na = na->prev;
        nb = nb->prev;
    }

    return true;
}

bool operator!=(const Queue& a, const Queue& b) {
    // Используем поределенный выше оператор ==
    return !(a == b);
}

bool operator!(const Queue& q) {
    return !q.length;
}

std::ostream& operator<< (std::ostream& os, const Queue& q) {
    // Выводим длину
    os << q.length << ": ";

    // Выводим каждый элемент
    Queue::Node* node = q.first;
    while(node) {
        os << node->val << " ";
        node = node->prev;
    }

    return os;
}

std::istream& operator>> (std::istream& is, Queue& q) {
    int cnt, t;

    // Вводим количество элементов для добавления
    is >> cnt;

    // вводим len элементов
    while(cnt--) {
        is >> t;
        q.push(t);
    }

    return is;
}
