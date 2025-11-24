#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Student;

int main() {
    int n = 2;
    Student *students = (Student*)malloc(n * sizeof(Student));

    if (students == NULL) return 1;

    // Записуємо дані (імітація вводу)
    strcpy(students[0].name, "Ivan");
    students[0].age = 20;

    strcpy(students[1].name, "Maria");
    students[1].age = 19;

    printf("Students list:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d\n", students[i].name, students[i].age);
    }

    free(students);
    return 0;
}