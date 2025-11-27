#include <windows.h>
#include <stdio.h>

DWORD WINAPI SumThread(LPVOID lpParam) {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    HANDLE hThread;
    DWORD threadId;
    DWORD exitCode;

    printf("Main: Creating Windows thread...\n");

    hThread = CreateThread(
        NULL,      
        0,          
        SumThread,  
        NULL,       
        0,          
        &threadId   
    );

    if (hThread == NULL) {
        printf("CreateThread failed\n");
        return 1;
    }

    WaitForSingleObject(hThread, INFINITE);

    if (GetExitCodeThread(hThread, &exitCode)) {
        printf("Main: Sum of 1 to 100 is: %lu\n", exitCode);
    }

    CloseHandle(hThread);
    return 0;
}