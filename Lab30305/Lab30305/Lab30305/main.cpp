#include "Lab30305.h"
#include <iostream>

int main() {
    // Створення двох масивів
    Array arr1, arr2;
    arr1.setValue(6);
    arr1.setValue(60);
    arr2.setValue(40);
    arr2.setValue(40);

    // Перевірка на рівність
    if (arr1 == arr2) {
        std::cout << "Eq" << std::endl;
    }

    // Перевірка на нерівність
    if (arr1 != arr2) {
        std::cout << "Not Eq" << std::endl;
    }

    // Склеювання двох масивів
    Array arr3 = arr1 + arr2;
    std::cout << "arr3 (arr1 + arr2): " << arr3 << std::endl;

    // Додавання числа до кожного елемента масиву
    Array arr4 = arr1 + 7;
    std::cout << "arr4 (arr1 + 7): " << arr4 << std::endl;

    // Віднімання числа від кожного елемента масиву
    Array arr5 = arr1 - 7;
    std::cout << "arr5 (arr1 - 7): " << arr5 << std::endl;

    // Постфіксний інкремент
    arr1++;
    std::cout << "arr1++: " << arr1 << std::endl;

    // Складений оператор присвоєння
    arr1 += 7;
    std::cout << "arr1 += 7: " << arr1 << std::endl;

    // Оператор індексування
    std::cout << "arr1[0]: " << arr1[0] << std::endl;

    // Додавання числа до кожного елемента масиву (дружній оператор)
    Array arr6 = 7 + arr1;
    std::cout << "arr6 (7 + arr1): " << arr6 << std::endl;

    return 0;
}
