#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hFile = CreateFile("test.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Помилка відкриття файлу", GetLastError());
        return 1;
    }
    printf("Файл успішно відкрито!\n");
    CloseHandle(hFile);
    return 0;
}

