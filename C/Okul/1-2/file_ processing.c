#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int grade;
    int status;  // 1 = Passed, 0 = Failed
} Student;

int main() {
    FILE *file = fopen("ogrenci_notlari.txt", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return 1;
    }

    Student students[100];
    int total_grade = 0, student_count = 0, i;
    int passed_count = 0, failed_count = 0;
    char line[100];

    // Skip the first line (header)
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        int id, grade;
        char name[50];

        if (sscanf(line, "%d %[^\t] %d", &id, name, &grade) == 3) {
            students[student_count].id = id;
            strcpy(students[student_count].name, name);
            students[student_count].grade = grade;
            total_grade += grade;
            student_count++;
        }
    }

    fclose(file);

    if (student_count == 0) {
        printf("No student data in the file!\n");
        return 1;
    }

    float average = (float)total_grade / student_count;
    printf("Class Average: %.2f\n", average);
    
    for (i = 0; i < student_count; i++) {
        if (students[i].grade >= average) {
            students[i].status = 1;
            passed_count++;
        } else {
            students[i].status = 0;
            failed_count++;
        }
    }

    printf("Number of Passed Students: %d\n", passed_count);
    printf("Number of Failed Students: %d\n", failed_count);

    printf("\nList of Failed Students:\n");
    for (i = 0; i < student_count; i++) {
        if (students[i].status == 0) {
            printf("%s -> FAILED\n", students[i].name);
        }
    }

    return 0;
}
