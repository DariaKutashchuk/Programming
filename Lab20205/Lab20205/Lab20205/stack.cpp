#include "stack.h"
#include <iostream>

// ����������� �� �������������
Stack::Stack() {
    capacity = 10;
    arr = new int[capacity];
    top = -1;
}

// ����������� ���������
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    arr = new int[capacity];
    top = other.top;
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

// ����������
Stack::~Stack() {
    delete[] arr;
}

// ��������� �������� � ������� �����
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

// ��������� �������� � ������� ����� �� ���������� ���� ��������
int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        return -1; // ���� ���� �������, ��������� -1
    }
    return arr[top--];
}

// ��������, �� ������� ����
bool Stack::isEmpty() {
    return top == -1;
}

// ����������� ����� ��������
void Stack::multiPop(int N) {
    while (N-- && !isEmpty()) {
        pop();
    }
}

// �������� �� ��������, �� ����������� � �����
void Stack::show() {
    for (int i = 0; i <= top; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// �������� ������������
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
