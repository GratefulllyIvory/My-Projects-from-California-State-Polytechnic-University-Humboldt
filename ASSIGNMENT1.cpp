// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    int item1, item2, item3, item4, diff, diff2, sum;

    std::cout << "Enter first integer: ";
    std::cin >> item1;
    std::cout << "Enter second integer: ";
    std::cin >> item2;
    std::cout << "Enter third inter: ";
    std::cin >> item3;
    std::cout << "Enter fourth integear: ";
    std::cin >> item4;
    __asm {
        mov EBX, item2;
        mov EAX, item1;
        sub EAX, EBX;
        mov diff, EAX;
        mov ECX, item3;
        mov EDX, item4;
        sub ECX, EDX;
        mov diff2, ECX;
        add EAX, ECX ;
        mov sum, EAX ;


    }
    std::cout << "The first diff is: " << diff << std::endl;
    std::cout << "The second diff is: " << diff2 << std::endl;
    std::cout << "The first diff plus the second diff is: " << sum << std::endl;
    return 0;
   
}
