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
        push 0
        push 12
        push 2
        call Pow(int);//first function call 
        add esp, 4
        jmp pastit
    Pow:
        push ebp
            mov ebp, esp
            sub esp, 16
            cmp DWORD PTR[ebp + 16], DWORD PTR[ebp + 12] //compares input and i
            jge unwind //jump if i is greater than or equal to original input
        mov eax, DWORD PTR[ebp + 4]// move 2, then 24, then 288 ... into eax
            mov DWORD PTR[ebp - 4], DWORD PTR[ebp + 16]// moves parameters into local variables
            mov DWORD PTR[ebp - 8], DWORD PTR[ebp + 12]//''
            mov DWORD PTR[ebp - 12], DWORD PTR[ebp + 8]//''
            mov DWORD PTR[ebp - 16], DWORD PTR[ebp + 4]//''
            imul DWORD PTR[ebp - 12], DWORD PTR[ebp - 16] // mul eax and 12
            add DWORD PTR[ebp - 16], eax //adds eax into local variable (2,24,288...)
            mov eax, DWORD PTR[ebp - 4] // moves old eax back into eax
            add DWORD PTR[ebp - 8], 1 // increments i 
            mov ebx, DWORD PTR[ebx + 4]// stores into ebx
            mov series, ebx// stores ebx into series
            call Pow(int) //calls the function again
            jmp unwind 
    unwind:
            add esp, 16
            pop ebp
            ret
            pastit:

    };

    std::cout << "f(" << input << ") = " << series << std::endl;
    return 0;
}

