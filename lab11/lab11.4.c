#include <windows.h>
#include <stdio.h>

typedef int (*SquareFunc)(int);

int main() {
    HINSTANCE hLib = LoadLibrary("mathdll.dll");
    if (!hLib) {
        printf("Cannot load DLL\n");
        return 1;
    }

    SquareFunc square = (SquareFunc)GetProcAddress(hLib, "square");
    if (!square) {
        printf("Function not found\n");
        return 1;
    }

    printf("Dynamic square: %d\n", square(9));

    FreeLibrary(hLib);
    return 0;
}
