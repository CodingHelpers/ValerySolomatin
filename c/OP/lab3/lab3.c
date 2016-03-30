#include <stdio.h>  // printf, scanf
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

/* Макрос - инициализатор */
#define DEQUE_INITIALIZER {NULL, 0}

/* Структура с данными студентов */
typedef struct student_data {
    int   student_num; // Шифр студента
    int   average;     // Средний балл
    char  fio[64];     // ФИО
} sdata;

/* Нода дека */
typedef struct DecNode {
    sdata  data;       // Данные в ноде
    struct DecNode *next, // Указатель на следующий элемент
                *prev; // Указатель на предыдущий элемент
} DecNode;

/* Хэдер дека, нужен для упрощения взаимодействий с деком.
 * Хранит все необходимые данные */
typedef struct Dec {
    DecNode* first;       // Первая нода дека
    int len;           // Количество нод в деке
} Dec;

/* Добавление элемента слева */
void AddLeft(Dec *deque, sdata new_node_data) {
    DecNode *newnode      = malloc(sizeof(DecNode));  // Создаем новую ноду в куче
    newnode->data      = new_node_data;         // Присваиваем ей данные

    if(!deque->first) {             // Если дек пуст (указатель на первый элеиент - NULL)
        deque->first = newnode;            // Делаем новую ноду первой
        deque->first->next = NULL;         // Зануляем указатели на следующий
        deque->first->prev = NULL;         // и предыдущий элементы
    } else {                        // Иначе (в деке уже есть первый элемент)
        newnode->next      = deque->first; // Делаем первую ноду следующей для новой
        deque->first->prev = newnode;      // Делаем новую ноду предыдущей по отношению к первой
        deque->first       = newnode;      // Делаем новую ноду первой (она ведь теперь первая слева)
    }
    deque->len++; // Инкрементируем длину дека
}

/* Добавление элемента справа */
void push_right(Dec *deque, sdata new_node_data) {
    DecNode *newnode = malloc(sizeof(DecNode));      // Создаем новую ноду в куче
    newnode->data  = new_node_data;            // Присваиваем ей данные

    if(!deque->first) {             // Если дек пуст (указатель на первый элеиент - NULL)
        deque->first = newnode;             // Делаем новую ноду первой
        deque->first->next = NULL;          // Зануляем указатели на следующий
        deque->first->prev = NULL;          // и предыдущий элементы
    } else {                        // Иначе (в деке уже есть первый элемент)
        DecNode *lastnode = deque->first;      // Ищем самую правую (последнюю) ноду.
        while(lastnode->next)               // Для этого двигаемся в цикле по указателю на next
            lastnode = lastnode->next;      // до NULL (следующего элемента нет)
        newnode->prev  = lastnode;          // Делаем последнюю ноду предыдущей по отношению к новой
        lastnode->next = newnode;           // Делаем новую ноду следующей по отношению к последней
    }
    deque->len++; // Инкрементируем длину
}

/* Удаление элеиента справа */
sdata PopRight(Dec *deque) {
    if(!deque->first) { // Если нет элементов, аварийно завершаем работу
        printf("Error: no elements left to pop\n");
        exit(1);
    }

    /* Находим последнюю ноду */
    DecNode *lastnode = deque->first;
    while(lastnode->next) lastnode = lastnode->next;

    /* Выдергиваем из нее данные и сохраняем */
    sdata d = lastnode->data;

    if(lastnode->prev) {     // Если есть ноды сзади (слева)
        lastnode = lastnode->prev; // Перемещаемся назад
        free(lastnode->next);      // Удаляем самую правую ноду
        lastnode->next = NULL;     // Зануляем указатель на next предпоследней ноды
    } else {                 // Иначе
        deque->first = NULL;       // Зануляем указатель на самую левую ноду, так как сейчас удалим единственную оставшуюся
        free(lastnode);            // Удаляем текущую ноду, так как она единственная
    }

    deque->len--; // Декрементируем длину дека
    return d;     // Возвращаем сохраненные из последней ноды данные
}

/* Проверка на пустоту */
int empty(Dec *deque) {
    /* Если deque.len != 0 вернуть 1
     * Иначе               вернуть 0 */
    return (deque->len) ? 0 : 1;
}

Dec make_struct(int n) {
    Dec deque = DEQUE_INITIALIZER; // Инициализируем дек
                                     // (равноценно Deque deque = {NULL, 0};
    int i;
    sdata data;

    /* Спрашиваем у пользователя ввод n структур */
    for(i = 0; i < n; i++) {
        /* Ввод кода студента */
        printf("Student code: ");
        scanf("%i", &data.student_num);

        /* Ввод средней оценки */
        printf("Average:      ");
        scanf("%i", &data.average);

        /* Ввод ФИО */
        printf("Student FIO:  ");
        do {
            fgets(data.fio, 64, stdin);
        } while(data.fio[0] == '\n');        // Читаем ввод пока в data.fio не окажется ввод (сначала вводится \n от предыдущей строки)
        data.fio[strlen(data.fio)-1] = '\0'; // Записываем на место символа переноса строки в конце \0 (конец строки)

        /* Добавляем вправо. Можно и влево, не важно */
        push_right(&deque, data);
    }

    return deque; // Возвращаем созданный дек
}

/* Вывод дека на экран */
void print(Dec *deque) {
    DecNode* node = deque->first;

    /* Проходим по всем нодам, пока текущая != NULL */
    while(node) {
        /* Вывод полей структуры */
        printf("Student %s, number %i, average %i\n", node->data.fio, node->data.student_num, node->data.average);
        /* Переход дальше по указателю */
        node = node->next;
    }
}

int main(void) {
    printf("make_struct test\n");
    Dec deque = make_struct(3);
    print(&deque);

    printf("\nis_empty test\n");
    printf("Is now deque empty? %s\n", empty(&deque) ? "YES!" : "NO!");
    /* если is_empty вернет 0, будет выбрано NO, иначе YES */

    sdata data = {445, 3, "Gavrilov Alexey Vladimirovich"};

    printf("\npush_lest test\n");
    AddLeft(&deque, data);
    print(&deque);

    printf("\npush_right test\n");
    push_right(&deque, data);
    print(&deque);

    printf("\npop right test\n");
    data = PopRight(&deque);
    print(&deque);

    printf("Extracted node:\n");
    printf("Student %s, number %i, average %i\n", data.fio, data.student_num, data.average);

    printf("\nis_empty test2\n");
    while(deque.len) {
        PopRight(&deque);
    }

    printf("Is now deque empty? %s\n", empty(&deque) ? "YES!" : "NO!");
    return 0;
}

