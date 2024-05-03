#pragma once
#include <iostream>

class Array {
private:
    int initialSize;
    int step;
    int* arr;
    int currentIndex;
    int currentSize;

public:
    Array(int initialSize = 10, int step = 5);
    Array(const Array& other);
    ~Array();

    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int* pArr, int size);

    Array& operator=(const Array& other);
    Array operator+(const Array& other) const;
    Array operator+(int value) const;
    Array operator-(int value) const;
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    Array operator++(int);
    Array& operator+=(int value);
    int& operator[](int index);

    friend std::ostream& operator<<(std::ostream& out, const Array& array);
    friend Array operator+(int value, const Array& array);
};
