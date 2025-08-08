// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
int main(int argc, char** argv)) {
    int series, input;

    std::cout << "Which element of the series would you like? ";
    std::cin >> input;

    __asm(
    mov EAX, input;
    push EAX:
    call Power:
    add esp, 4;
Power(int):
    push ebp;
    mov ebp, esp;
    sub esp, 8;
    mov DWORD PTR[ebp-4], eax;
    cmp eax, [EBP+4];
    jme end:
    sub eax, 1;
    call Power:
    mov EAX, series;
end:
    add esp, 8;
    pop ebp;
    ret
    );

    std::cout << "f(" << input << ") = " << series << std::endl;
    return 0;
}
