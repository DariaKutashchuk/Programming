#pragma once
#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // �����������
    Stack();

    // ����������� ���������
    Stack(const Stack& other);

    // ����������
    ~Stack();

    // ��������� �������� � ������� �����
    void push(int elem);

    // ��������� �������� � ������� ����� �� ���������� ���� ��������
    int pop();

    // ��������, �� ������� ����
    bool isEmpty();

    // ����������� ����� ��������
    void multiPop(int N);

    // �������� �� ��������, �� ����������� � �����
    void show();

    // �������� ������������
    Stack& operator=(const Stack& other);
};
