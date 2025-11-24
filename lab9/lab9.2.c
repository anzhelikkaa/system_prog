#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd < 0) {
        perror("Open failed");
        return 1;
    }

    printf("This prints to the terminal BEFORE redirection.\n");

    // --- Магія dup2 ---
    // Ми підміняємо дескриптор 1 (stdout) на file_fd.
    // Весь вивід, що йде в stdout, тепер піде у файл.
    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("Dup2 failed");
        return 1;
    }

    // Тепер file_fd і 1 вказують на одну структуру файлу.
    // Можна закрити старий file_fd, він більше не потрібен (ми маємо копію в 1).
    close(file_fd);

    // Цей рядок не з'явиться на екрані, а потрапить у output.txt
    printf("Redirected output: This goes to the file, not the screen.\n");
    
    // Щоб переконатися, що буфер скинуто
    fflush(stdout); 

    // Пишемо повідомлення у stderr (дескриптор 2), щоб показати, 
    // що його ми НЕ перенаправляли.
    fprintf(stderr, "This still goes to terminal (stderr is untouched).\n");

    return 0;
}