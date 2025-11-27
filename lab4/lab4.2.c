#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;             
    PROCESS_INFORMATION pi;      
    ZeroMemory(&si, sizeof(si)); 
    si.cb = sizeof(si);          
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
        "C:\\Windows\\System32\\notepad.exe", 
        NULL, NULL, NULL, FALSE,              
        0, NULL, NULL, &si, &pi))             
        printf("успішно PID=%lu\n", pi.dwProcessId);
        CloseHandle(pi.hProcess); 
        CloseHandle(pi.hThread);
    } else {
        printf("помилка (%lu)\n", GetLastError());
    }

    return 0;
}
