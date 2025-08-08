#include <iostream>
#include <cstdlib>
int square() {
    int w, x, y, z;
    __asm {
        mov EAX, x;
        mov EBX, y;
        add EAX, EBX;
        mov ECX, w;
        add EAX, ECX;
        mov z, EAX;
    }
    return z;
}