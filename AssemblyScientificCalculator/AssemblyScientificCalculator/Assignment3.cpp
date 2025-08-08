// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    char operation;
    float radius, solvefor, result, four = 4, three = 3;

    std::cout << "Which operation would you like to perform?\n";
    std::cout << "(s) sine, (c) cosine, (t) tangent\n";
    std::cout << "(a) area of a circle, (v) volume of a sphere\n";
    std::cout << "(g) log_2, (n) ln, (l) log_10\n";

    std::cin >> operation;
    std::cout << "Enter the number you want to solve for(enter 0 if you want the Area of a Circle or Volume of a Sphere):\n";
    std::cin >> solvefor;
    std::cout << "If you want the Area of a Circle (a) or Volume of a Sphere (v) also enter the radius otherwise enter 0:\n ";
    std::cin >> radius;

    __asm {
        mov al, operation
        cmp al, 0x73
        je Sin
        cmp al, 0x63
        je Cos
        cmp al, 0x74
        je Tan
        cmp al, 0x61
        je Area
        cmp al, 0x76
        je Volu
        cmp al, 0x67
        je Log2
        cmp al, 0x6E
        je Naty
        cmp al, 0x6C
        je Log10
        jmp end
     Sin :
        FLD solvefor
        FSIN
        FST result
        JMP end
    Cos :
        FLD solvefor
        FCOS
        FST result
        JMP end
    Tan :
        FLD solvefor
        FPTAN
        FSTP ST(0)
        FST result
        JMP end
    Area:
        cmp al, 0x61
        jb end
        ja end
        FLD radius
        FLD radius
        FMULP ST(1), ST(0)
        FLDPI
        FMULP ST(1), ST(0)
        FST result
        JMP end
    Volu:
        cmp al, 0x76
        jb end
        ja end
        FLD four
        FLD three
        FDIVP ST(1), ST(0)
        FLD radius
        FLD radius
        FMULP ST(1), ST(0)
        FLD radius
        FMULP ST(1), ST(0)
        FLDPI
        FMULP ST(1), ST(0)
        FMULP ST(1), ST(0)
        FST result
        JMP end
    Log2:
        FLD1
        FLD solvefor
        FYL2X
        FST result
        JMP end
        
    Naty:
        FLDL2E
        FLD1
        FLD solvefor
        FYL2X
        FDIV ST(0), ST(1)
        FST result

    Log10:
        FLDL2T
        FLD1
        FLD solvefor
        FYL2X
        FDIV ST(0), ST(1)
        FST result 
    end:
        };
    std::cout << result;
    
    return 0;
}

