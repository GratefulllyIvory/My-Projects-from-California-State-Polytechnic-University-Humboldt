// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
int main(int argc, char** argv) {
    int series, input;

    std::cout << "Which element of the series would you like? ";
    std::cin >> input;

    __asm {
        mov eax, input //declaring parameters
        push eax
        mov edx, 0
        mov ebx, 2
        push edx
        push ebx
        call Pow//first function call 
        add esp, 4
        jmp pastit
     Pow:
            push ebp
            mov ebp, esp
            sub esp, 12
            cmp edx, eax //compares input and i
            jge unwind //jump if i is greater than or equal to original input
            mov eax, DWORD PTR[ebp+4]// move 2, then 24, then 288 ... into eax
            push[ebp+12]//store paramaters 
            push[ebp+8]
            push[ebp+4]
            imul ebx, 12// mul eax and 12, moves into eax
            add ebx, eax //add 24 to 2, 288 to 26...
            mov eax, DWORD PTR[ebp+12] // moves old eax back into eax
            add edx, 1 // increments 
            call Pow //calls the function again
            jmp unwind
     unwind:
            mov series, ebx// stores ebx into series
            add esp, 24
            pop ebp
            ret
     pastit:

    };

   // std::cout << "f(" << input << ") = " << series << std::endl;
    return 0;
}

