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
    // Создание структуры TwoInts и инициализация значений a и b
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // Вывод значений a и b на экран
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Создание двух переменных типа StructWithArray и инициализация их массивов arr
    StructWithArray s = { };
    s.arr[0] = 10;

    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // Использование указателя для работы с массивом arr в структуре s через sPointer
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;

    // Вывод и изменение значений элементов массива arr через s и sPointer
    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;

    // Изменение значения массива arr в s1 через указатель sPointer
    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl;

    // Инициализация массива структур и работы с указателями
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3];

    // Использование указателей для изменения значений элементов массива arr
    sPointer = &s;
    int* pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer;

    // Заполнение памяти переменной memory нулями с помощью функции memset()
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));
    return 0;
}
