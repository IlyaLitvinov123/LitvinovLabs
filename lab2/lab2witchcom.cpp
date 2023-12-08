#include <stdlib.h>
#include <iostream>

struct TwoInts {
    int a;
    int b;
};

struct StructWithArray {
    int arr[4];
    int* someNumber;
};

int main() {
    // Sozdaem strukturu TwoInts i initsializiruem znacheniya a i b
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // Vivod znacheniy a i b na ekran
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Sozdaem dva peremennyh tipa StructWithArray i initsializiruem ih massivami arr
    StructWithArray s = { };
    s.arr[0] = 10;

    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // Ispol'zovanie ukazatelya dlya raboty s massivom arr v strukture s cherez sPointer
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;

    // Vivod i izmenenie znacheniy elementov massiva arr cherez s i sPointer
    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;

    // Izmenenie znacheniya massiva arr v s1 cherez ukazatel' sPointer
    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl;

    // Initsializatsiya massiva struktur i rabota s ukazatelyami
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3];

    // Ispol'zovanie ukazateley dlya izmeneniya znacheniy elementov massiva arr
    sPointer = &s;
    int* pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer;

    // Zapolnenie pamyati peremennoy memory nulyami s pomoshch'yu funkcii memset()
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));
    return 0;
}
