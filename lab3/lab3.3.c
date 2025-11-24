#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    float grade;
} Student;

int main() {
    Student students[2] = {
        {"Ivan", 20, 85.5},
        {"Olena", 19, 92.0}
    };

    FILE *fout = fopen("students.bin", "wb");
    if (!fout) {
        perror("Помилка відкриття для запису");
        return 1;
    }
    fwrite(students, sizeof(Student), 2, fout);
    fclose(fout);

    FILE *fin = fopen("students.bin", "rb");
    if (!fin) {
        perror("Помилка відкриття для читання");
        return 1;
    }

    Student read_students[2];
    fread(read_students, sizeof(Student), 2, fin);
    fclose(fin);

    for (int i = 0; i < 2; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n",
               read_students[i].name,
               read_students[i].age,
               read_students[i].grade);
    }

    return 0;
}
