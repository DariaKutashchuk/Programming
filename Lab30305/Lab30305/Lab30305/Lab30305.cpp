#include "Lab30305.h"
#include <iostream>

// Конструктор
Array::Array(int initialSize, int step)
    : initialSize(initialSize), step(step), arr(new int[initialSize]), currentIndex(0), currentSize(initialSize) {
}

// Конструктор копіювання
Array::Array(const Array& other)
    : initialSize(other.initialSize), step(other.step), arr(new int[other.currentSize]), currentIndex(other.currentIndex), currentSize(other.currentSize) {
    for (int i = 0; i < currentIndex; ++i) {
        arr[i] = other.arr[i];
    }
}

// Деструктор
Array::~Array() {
    delete[] arr;
}

// Показати всі елементи
void Array::showElements() {
    for (int i = 0; i < currentIndex; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Розширити масив
void Array::expandArray(int size) {
    int* temp = new int[currentSize + size];
    for (int i = 0; i < currentIndex; ++i) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    currentSize += size;
}

// Отримати поточний розмір масиву
int Array::getSize() {
    return currentIndex;
}

// Отримати розмір кожного елемента
int Array::getElemSize() {
    return sizeof(arr[0]);
}

// Встановити значення за поточним індексом
void Array::setValue(int val) {
    if (currentIndex >= currentSize) {
        expandArray(step);
    }
    arr[currentIndex++] = val;
}

// Встановити масив за вказівником та розміром
void Array::setArray(int* pArr, int size) {
    if (size > currentSize) {
        delete[] arr;
        arr = new int[size];
        currentSize = size;
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = pArr[i];
    }
    currentIndex = size;
}

// Оператор присвоєння
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        initialSize = other.initialSize;
        step = other.step;
        currentSize = other.currentSize;
        currentIndex = other.currentIndex;
        arr = new int[currentSize];
        for (int i = 0; i < currentIndex; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Оператор додавання для злиття масивів
Array Array::operator+(const Array& other) const {
    Array result(*this);
    for (int i = 0; i < other.currentIndex; ++i) {
        result.setValue(other.arr[i]);
    }
    return result;
}

// Оператор додавання для додавання числа до кожного елемента
Array Array::operator+(int value) const {
    Array result(*this);
    for (int i = 0; i < currentIndex; ++i) {
        result.arr[i] += value;
    }
    return result;
}

// Оператор віднімання для віднімання числа від кожного елемента
Array Array::operator-(int value) const {
    Array result(*this);
    for (int i = 0; i < currentIndex; ++i) {
        result.arr[i] -= value;
    }
    return result;
}

// Оператор порівняння для порівняння двох масивів
bool Array::operator==(const Array& other) const {
    if (currentIndex != other.currentIndex) {
        return false;
    }
    for (int i = 0; i < currentIndex; ++i) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

// Оператор порівняння для порівняння двох масивів
bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

// Постфіксний інкремент для збільшення кожного елемента на одиницю
Array Array::operator++(int) {
    Array temp(*this);
    for (int i = 0; i < currentIndex; ++i) {
        arr[i]++;
    }
    return temp;
}

// Складений оператор присвоєння для додавання числа до кожного елемента
Array& Array::operator+=(int value) {
    for (int i = 0; i < currentIndex; ++i) {
        arr[i] += value;
    }
    return *this;
}

// Оператор індексування для доступу до елементів за індексом
int& Array::operator[](int index) {
    if (index < 0 || index >= currentIndex) {
        std::cout << "Індекс поза межами" << std::endl;
        // Повернути посилання на дійсний елемент або обробити випадок виходу за межі відповідно.
        // Тут я повертаю посилання на перший елемент.
        return arr[0];
    }
    return arr[index];
}

// Дружня функція для перевантаження оператора виводу
std::ostream& operator<<(std::ostream& out, const Array& array) {
    for (int i = 0; i < array.currentIndex; ++i) {
        out << array.arr[i] << " ";
    }
    return out;
}

// Дружня функція для перевантаження оператора додавання для додавання числа до кожного елемента
Array operator+(int value, const Array& array) {
    Array result(array);
    for (int i = 0; i < array.currentIndex; ++i) {
        result.arr[i] += value;
    }
    return result;
}
