#include <windows.h>
#include <stdio.h>

HANDLE hSemaphore;

DWORD WINAPI WorkerThread(LPVOID lpParam) {
    int id = *(int*)lpParam;
    printf("Thread %d is waiting.\n", id);

    WaitForSingleObject(hSemaphore, INFINITE);

    printf("--> Thread %d is WORKING.\n", id);
    Sleep(2000);
    printf("<-- Thread %d finished.\n", id);

    ReleaseSemaphore(hSemaphore, 1, NULL);
    return 0;
}

int main() {
    HANDLE threads[5];
    int ids[5] = {1, 2, 3, 4, 5};

    hSemaphore = CreateSemaphore(NULL, 2, 2, NULL);

    for (int i = 0; i < 5; i++) {
        threads[i] = CreateThread(NULL, 0, WorkerThread, &ids[i], 0, NULL);
    }

    WaitForMultipleObjects(5, threads, TRUE, INFINITE);
    CloseHandle(hSemaphore);
    
    return 0;
}