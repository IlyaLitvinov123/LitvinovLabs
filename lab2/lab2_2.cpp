#include <stdlib.h>
#include <iostream>

struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // �������� ��������� TwoInts � ������������� �������� a � b
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // ����� �������� a � b �� �����
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // �������� ���� ���������� ���� StructWithArray � ������������� �� �������� arr
    StructWithArray s = { };
    s.arr[0] = 10;

    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // ������������� ��������� ��� ������ � �������� arr � ��������� s ����� sPointer
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;

    // ����� � ��������� �������� ��������� ������� arr ����� s � sPointer
    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;

    // ��������� �������� ������� arr � s1 ����� ��������� sPointer
    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl;

    // ������������� ������� �������� � ������ � �����������
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3];

    // ������������� ���������� ��� ��������� �������� ��������� ������� arr
    sPointer = &s;
    int* pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer;

    // ���������� ������ ���������� memory ������ � ������� ������� memset()
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));
    return 0;
}
