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

    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("Dup2 failed");
        return 1;
    }

    close(file_fd);

    printf("Redirected output: This goes to the file, not the screen.\n");

    fflush(stdout); 

    fprintf(stderr, "This still goes to terminal (stderr is untouched).\n");

    return 0;
}