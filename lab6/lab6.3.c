#include <windows.h>
#include <stdio.h>

// Функція потоку у Windows має сигнатуру DWORD WINAPI
DWORD WINAPI SumThread(LPVOID lpParam) {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    return sum; // Повертаємо результат як код виходу
}

int main() {
    HANDLE hThread;
    DWORD threadId;
    DWORD exitCode;

    printf("Main: Creating Windows thread...\n");

    // Створення потоку
    hThread = CreateThread(
        NULL,       // Атрибути безпеки
        0,          // Розмір стека (0 = за замовчуванням)
        SumThread,  // Функція потоку
        NULL,       // Аргумент функції
        0,          // Прапорці створення (0 = запустити відразу)
        &threadId   // Змінна для ID потоку
    );

    if (hThread == NULL) {
        printf("CreateThread failed\n");
        return 1;
    }

    // Чекаємо завершення потоку (аналог pthread_join)
    WaitForSingleObject(hThread, INFINITE);

    // Отримуємо результат (код завершення)
    if (GetExitCodeThread(hThread, &exitCode)) {
        printf("Main: Sum of 1 to 100 is: %lu\n", exitCode);
    }

    CloseHandle(hThread); // Обов'язково закриваємо дескриптор
    return 0;
}