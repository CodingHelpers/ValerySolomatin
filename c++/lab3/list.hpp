#ifndef LIST_H
#define LIST_H
#include <stdint.h>
#include <stdexcept>
#include <iostream>

// Шаблонный класс элемента списка
struct ListNode {
    ListNode(const float& val) : value(val), l(nullptr), r(nullptr) {}

    float value;
    ListNode* l;
    ListNode* r;
};

// Шаблонный класс Список
class List {
public:
    List() : length(0), leftest(nullptr), rightest(nullptr) {}
    virtual ~List() {
        while(length) {
            popLeft();
        }
    }

    /* Объявляем чистые виртуальные функции, которые должны быть переопределены в наследованном классе */
    virtual void push(const float& val) = 0;
    virtual float pop() = 0;

    /* Добавление элемента справа, принимает константную ссылку на данные */
    void pushRight(const float& val) {
        // Создаем новую ноду
        ListNode* new_node = new ListNode(val);

        // Если очередь пуста)
        if(!rightest) {
            // Делаем новый элемент самым правым и самым левым
            leftest = rightest = new_node;
        } else {
            // Иначе ставим новый элемент справа
            rightest->r = new_node;
            new_node->l = rightest;
            rightest    = new_node;
        }

        // Увеличиваем счетчик элементов
        length++;
    }

    /* Добавление элемента слева, принимает константную ссылку на данные */
    void pushLeft(const float& val) {
        // Создаем новую ноду
        ListNode* new_node = new ListNode(val);

        // Если очередь пуста)
        if(!leftest) {
            // Делаем новый элемент самым правым и самым левым
            leftest = rightest = new_node;
        } else {
            // Иначе ставим новый элемент справа
            leftest->l = new_node;
            new_node->r = leftest;
            leftest    = new_node;
        }

        // Увеличиваем счетчик элементов
        length++;
    }

    /* Извлечение значения элемента справа, возвращает константную ссылку на данные элемента */
    const float& peekRight() const {
        if(!rightest) {
            throw std::runtime_error("List is empty");
        }
        return rightest->value;
    }

    /* Извлечение значения элемента слева, возвращает константную ссылку на данные элемента */
    const float& peekLeft() const {
        if(!leftest) {
            throw std::runtime_error("List is empty");
        }
        return leftest->value;
    }

    /* Удаление элемента справа */
    void popRight() {
        if(!rightest) {
            throw std::runtime_error("List is empty");
        }

        // Сохраняем указатель на самый правый элемент
        ListNode* tmp = rightest;

        // Делаем следущий элемент самым правым
        rightest = rightest->l;

        // Освобождаем память удаляемого элемента
        delete tmp;
        length--;
    }

    /* Удаление элемента слева */
    void popLeft() {
        if(!rightest) {
            throw std::runtime_error("List is empty");
        }

        // Сохраняем указатель на самый левый элемент
        ListNode* tmp = leftest;

        // Делаем следущий элемент самым левым
        leftest = leftest->r;

        // Освобождаем память удаляемого элемента
        delete tmp;
        length--;
    }

    unsigned len() const {
        return length;
    }

    /* Оператор вывода списка в поток */
    friend std::ostream& operator<< (std::ostream& os, const List& lst) {
        ListNode* node = lst.leftest;
        os << "[ ";

        // Проходим по всем элементам от самого левого до самого правого
        while(node) {
            /// Выводим значение и разделитель
            os << node->value << " ";

            node = node->r;
        }

        os << "]";
        return os;
    }

private:
    unsigned length;

    ListNode* leftest;
    ListNode* rightest;
};


#endif // LISfloat_H
