#include <windows.h>
#include <stdio.h>

HANDLE hMutex;

DWORD WINAPI WriteToFile(LPVOID lpParam) {
    int threadNum = *(int*)lpParam;
    
    // Очікування захоплення м'ютекса (INFINITE - чекати вічно, поки не звільниться)
    WaitForSingleObject(hMutex, INFINITE);

    // --- Критична секція ---
    FILE* file = fopen("log.txt", "a");
    if (file != NULL) {
        fprintf(file, "Thread %d is writing to file...\n", threadNum);
        printf("Thread %d access granted.\n", threadNum);
        Sleep(100); // Імітація роботи
        fclose(file);
    }
    // -----------------------

    // Звільнення м'ютекса
    ReleaseMutex(hMutex);
    return 0;
}

int main() {
    HANDLE threads[3];
    int ids[3] = {1, 2, 3};

    // Створення м'ютекса
    hMutex = CreateMutex(NULL, FALSE, NULL);

    for (int i = 0; i < 3; i++) {
        threads[i] = CreateThread(NULL, 0, WriteToFile, &ids[i], 0, NULL);
    }

    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    CloseHandle(hMutex);
    for(int i=0; i<3; i++) CloseHandle(threads[i]);

    printf("All threads finished writing.\n");
    return 0;
}