#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Спочатку створимо файл із контентом для тесту
    int fd_create = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_create < 0) { perror("Create failed"); return 1; }
    write(fd_create, "1234567890", 10);
    close(fd_create);

    // --- Основне завдання ---
    
    // 1. Відкриваємо файл для читання
    int fd1 = open("input.txt", O_RDONLY);
    if (fd1 < 0) { perror("Open failed"); return 1; }

    // 2. Дублюємо дескриптор
    // fd2 отримає найменший вільний номер (наприклад, 3)
    int fd2 = dup(fd1);
    if (fd2 < 0) { perror("Dup failed"); return 1; }

    printf("Original FD: %d, Duplicated FD: %d\n", fd1, fd2);

    char buffer[6]; // 5 символів + \0
    memset(buffer, 0, 6);

    // 3. Читаємо 5 байт з ОРИГІНАЛЬНОГО дескриптора
    read(fd1, buffer, 5);
    printf("Read from FD1: %s\n", buffer);

    // 4. Читаємо наступні 5 байт з ДУБЛЬОВАНОГО дескриптора
    // Оскільки offset спільний, ми маємо прочитати "67890", а не "12345"
    memset(buffer, 0, 6);
    read(fd2, buffer, 5);
    printf("Read from FD2: %s (Notice it continued from where FD1 left off)\n", buffer);

    close(fd1);
    close(fd2);
    
    // Видаляємо тестовий файл
    unlink("input.txt");

    return 0;
}