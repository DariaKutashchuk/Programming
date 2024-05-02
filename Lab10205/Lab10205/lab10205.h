#pragma once
#include <iostream>

class Array {
private:
    int initialSize;  // Початковий розмір, крок.
    int step;         // Розмір збільшення.
    int* arr;         // Вказівник на масив.
    int currentIndex; // Поточний індекс.
    int currentSize;  // Поточний розмір.

public:
    // Конструктор.
    Array(int initialSize = 10, int step = 5);

    // Деструктор.
    ~Array();

    // Показати елементи.
    void showElements();

    // Розширити масив.
    void expandArray(int size);

    // Отримати розмір.
    int getSize();

    // Фактичний розмір.
    int getElemSize();

    // Додати елемент.
    void setValue(int val);

    // Додати масив.
    void setArray(int* pArr, int size);
};
