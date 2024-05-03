#include "stack.h"
#include <iostream>

// Конструктор за замовчуванням
Stack::Stack() {
    capacity = 10;
    arr = new int[capacity];
    top = -1;
}

// Конструктор копіювання
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    arr = new int[capacity];
    top = other.top;
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

// Деструктор
Stack::~Stack() {
    delete[] arr;
}

// Додавання елемента в вершину стека
void Stack::push(int elem) {
    if (top == capacity - 1) {
        int* newArr = new int[2 * capacity];
        for (int i = 0; i < capacity; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }
    arr[++top] = elem;
}

// Видалення елемента з вершини стека та повернення його значення
int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        return -1; // Якщо стек порожній, повертаємо -1
    }
    return arr[top--];
}

// Перевірка, чи порожній стек
bool Stack::isEmpty() {
    return top == -1;
}

// Виштовхнути кілька елементів
void Stack::multiPop(int N) {
    while (N-- && !isEmpty()) {
        pop();
    }
}

// Показати всі елементи, що знаходяться в стеці
void Stack::show() {
    for (int i = 0; i <= top; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Оператор присвоювання
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        arr = new int[capacity];
        top = other.top;
        for (int i = 0; i <= top; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
