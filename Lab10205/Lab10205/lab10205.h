#pragma once
#include <iostream>

class Array {
private:
    int initialSize;  // ���������� �����, ����.
    int step;         // ����� ���������.
    int* arr;         // �������� �� �����.
    int currentIndex; // �������� ������.
    int currentSize;  // �������� �����.

public:
    // �����������.
    Array(int initialSize = 10, int step = 5);

    // ����������.
    ~Array();

    // �������� ��������.
    void showElements();

    // ��������� �����.
    void expandArray(int size);

    // �������� �����.
    int getSize();

    // ��������� �����.
    int getElemSize();

    // ������ �������.
    void setValue(int val);

    // ������ �����.
    void setArray(int* pArr, int size);
};
