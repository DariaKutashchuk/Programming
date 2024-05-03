#pragma once
#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Конструктор
    Stack();

    // Конструктор копіювання
    Stack(const Stack& other);

    // Деструктор
    ~Stack();

    // Додавання елемента в вершину стека
    void push(int elem);

    // Видалення елемента з вершини стека та повернення його значення
    int pop();

    // Перевірка, чи порожній стек
    bool isEmpty();

    // Виштовхнути кілька елементів
    void multiPop(int N);

    // Показати всі елементи, що знаходяться в стеці
    void show();

    // Оператор присвоювання
    Stack& operator=(const Stack& other);
};
