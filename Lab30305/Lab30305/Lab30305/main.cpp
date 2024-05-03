#include "Lab30305.h"
#include <iostream>

int main() {
    // ��������� ���� ������
    Array arr1, arr2;
    arr1.setValue(6);
    arr1.setValue(60);
    arr2.setValue(40);
    arr2.setValue(40);

    // �������� �� ������
    if (arr1 == arr2) {
        std::cout << "Eq" << std::endl;
    }

    // �������� �� ��������
    if (arr1 != arr2) {
        std::cout << "Not Eq" << std::endl;
    }

    // ���������� ���� ������
    Array arr3 = arr1 + arr2;
    std::cout << "arr3 (arr1 + arr2): " << arr3 << std::endl;

    // ��������� ����� �� ������� �������� ������
    Array arr4 = arr1 + 7;
    std::cout << "arr4 (arr1 + 7): " << arr4 << std::endl;

    // ³������� ����� �� ������� �������� ������
    Array arr5 = arr1 - 7;
    std::cout << "arr5 (arr1 - 7): " << arr5 << std::endl;

    // ����������� ���������
    arr1++;
    std::cout << "arr1++: " << arr1 << std::endl;

    // ��������� �������� ���������
    arr1 += 7;
    std::cout << "arr1 += 7: " << arr1 << std::endl;

    // �������� ������������
    std::cout << "arr1[0]: " << arr1[0] << std::endl;

    // ��������� ����� �� ������� �������� ������ (������ ��������)
    Array arr6 = 7 + arr1;
    std::cout << "arr6 (7 + arr1): " << arr6 << std::endl;

    return 0;
}
