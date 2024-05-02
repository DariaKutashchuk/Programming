#include "lab10205.h"

// Конструктор класу Array.
Array::Array(int initialSize, int step)
{
    this->initialSize = initialSize;    // Початковий розмір масиву.
    this->step = step;                  // Крок, з яким масив збільшується.
    this->arr = new int[initialSize];   // Виділення пам'яті для масиву.
    this->currentIndex = 0;             // Ініціалізація поточного індексу.
    this->currentSize = initialSize;    // Ініціалізація поточного розміру.
}

// Деструктор класу Array.
Array::~Array()
{
    delete[] arr;   // Звільнення пам'яті, відведеної для масиву.
}

// Виводить на екран елементи масиву.
void Array::showElements()
{
    for (int i = 0; i < currentIndex; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Розширює масив на певну кількість елементів.
void Array::expandArray(int size)
{
    int newSize = currentSize + size;   // Визначення нового розміру масиву.
    int* tempArr = new int[newSize];   // Створення тимчасового масиву.
    for (int i = 0; i < currentIndex; ++i) {
        tempArr[i] = arr[i];    // Копіювання елементів з поточного масиву в тимчасовий.
    }
    delete[] arr;   // Звільнення пам'яті, відведеної для поточного масиву.
    arr = tempArr;  // Перенесення тимчасового масиву в поточний.
    currentSize = newSize;  // Оновлення поточного розміру масиву.
}

// Повертає розмір масиву.
int Array::getSize()
{
    return currentSize;
}

// Повертає фактичний розмір масиву (кількість збережених елементів).
int Array::getElemSize()
{
    return currentIndex;
}

// Додає заданий елемент у масив.
void Array::setValue(int val)
{
    if (currentIndex >= currentSize) {  // Перевірка наявності вільного місця в масиві.
        expandArray(step);   // Розширення масиву на величину кроку.
    }
    arr[currentIndex] = val;    // Додавання значення до масиву.
    currentIndex++;             // Інкремент поточного індексу.
}

// Замінює масив на новий масив, переданий через вказівник.
void Array::setArray(int* pArr, int size)
{
    if (currentSize < size) {   // Перевірка, чи достатньо розміру масиву.
        expandArray(size - currentSize);    // Розширення масиву на необхідну кількість елементів.
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = pArr[i];   // Копіювання елементів нового масиву в поточний.
    }
    currentIndex = size;    // Оновлення поточного індексу.
}
