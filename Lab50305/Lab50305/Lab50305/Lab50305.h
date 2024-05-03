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
    CList(); // ����������� �� �������������. �������� ���������� ���� ������.
    CList(const CList& other); // ����������� ���������. ������� ���� ������ ������.
    ~CList(); // ����������. ������� ���'���, ������� �� �������� ������.

    void insertBegin(int value); // �������� ����� ������� � ������� ������.
    void insertEnd(int value); // �������� ����� ������� � ����� ������.
    bool insertAfter(int afterValue, int value); // �������� ����� ������� ���� ��������� ��������.
    int popBegin(); // ������� �� ������� ������ ������� ������.
    int popEnd(); // ������� �� ������� ������� ������� ������.
    bool deleteElem(int value); // ������� ������� � ������ �� �������� ���������.
    bool isEmpty(); // ��������, �� � ������ ������.
    void sort(); // ����� �������� ������ �� ����������.
    void show(bool reverse = false); // �������� �������� ������ � ���������� ��� ����������� �������.

};
