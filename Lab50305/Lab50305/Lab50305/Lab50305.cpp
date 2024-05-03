#include "Lab50305.h"

CList::CList() : head(nullptr), tail(nullptr) {}

CList::CList(const CList& other) : head(nullptr), tail(nullptr) {
    Node* temp = other.head;
    while (temp) {
        insertEnd(temp->data);
        temp = temp->next;
    }
}

CList::~CList() {
    while (!isEmpty()) {
        popBegin();
    }
}

void CList::insertBegin(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void CList::insertEnd(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

bool CList::insertAfter(int afterValue, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == afterValue) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            if (temp->next) {
                temp->next->prev = newNode;
            }
            else {
                tail = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int CList::popBegin() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
    return value;
}

int CList::popEnd() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    int value = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
    return value;
}

bool CList::deleteElem(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            if (temp == head) {
                popBegin();
                return true;
            }
            if (temp == tail) {
                popEnd();
                return true;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool CList::isEmpty() {
    return head == nullptr;
}

void CList::sort() {
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void CList::show(bool reverse) {
    if (isEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (reverse) {
        Node* temp = tail;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    else {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
    std::cout << std::endl;
}
