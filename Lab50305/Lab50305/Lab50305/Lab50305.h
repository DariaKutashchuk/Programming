#pragma once
#include <iostream>
#include <stdexcept>

class CList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    CList(); // Конструктор за замовчуванням. Ініціалізує початковий стан списку.
    CList(const CList& other); // Конструктор копіювання. Створює копію іншого списку.
    ~CList(); // Деструктор. Звільняє пам'ять, видалює всі елементи списку.

    void insertBegin(int value); // Вставляє новий елемент у початок списку.
    void insertEnd(int value); // Вставляє новий елемент у кінець списку.
    bool insertAfter(int afterValue, int value); // Вставляє новий елемент після вказаного значення.
    int popBegin(); // Видаляє та повертає перший елемент списку.
    int popEnd(); // Видаляє та повертає останній елемент списку.
    bool deleteElem(int value); // Видаляє елемент зі списку за вказаним значенням.
    bool isEmpty(); // Перевіряє, чи є список пустим.
    void sort(); // Сортує елементи списку за зростанням.
    void show(bool reverse = false); // Виводить елементи списку у звичайному або зворотньому порядку.

};
