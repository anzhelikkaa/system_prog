#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;              // структура для параметрів запуску
    PROCESS_INFORMATION pi;      // структура для інформації про процес

    ZeroMemory(&si, sizeof(si)); // обнуляємо пам’ять
    si.cb = sizeof(si);          // задаємо розмір структури
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
        "C:\\Windows\\System32\\notepad.exe", // програма для запуску
        NULL, NULL, NULL, FALSE,              // параметри безпеки
        0, NULL, NULL, &si, &pi))             // додаткові параметри
    {
        printf("Процес успішно створено! PID=%lu\n", pi.dwProcessId);
        CloseHandle(pi.hProcess); // закриваємо дескриптори
        CloseHandle(pi.hThread);
    } else {
        printf("Помилка створення процесу (%lu)\n", GetLastError());
    }

    return 0;
}
