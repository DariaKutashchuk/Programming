#include <iostream>
#include "stack.h"

int main() {
    Stack st;

    st.push(6);
    st.push(60);
    st.push(40);

    std::cout << "Stack elements: ";
    st.show(); // Виведе: 6 60 40

    if (!st.isEmpty()) {
        std::cout << "Popped element: " << st.pop() << std::endl; // Виведе: Popped element: 40

        std::cout << "Stack elements after popping: ";
        st.show(); // Виведе: 6 60
    }

    // Видалення декількох елементів
    st.multiPop(2);

    // Показати елементи у стеці після видалення
    std::cout << "Stack elements after multiPop: ";
    st.show(); // Виведе: Stack elements after multiPop:

    return 0;
}
