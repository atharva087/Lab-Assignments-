#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 3

struct Student {
    int rollNumber;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
};

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count;

    printf("Enter the number of students: ");
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("\nEnter roll number, name, and marks of 3 subjects for student %d:\n",
               i + 1);
        scanf("%d %49s", &students[i].rollNumber, students[i].name);

        students[i].total = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }

        students[i].percentage = students[i].total / SUBJECTS;
    }

    printf("\nRoll No  Name                 Subject 1  Subject 2  Subject 3  Total  Percentage\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-10.2f %-10.2f %-10.2f %-6.2f %.2f\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].total,
               students[i].percentage);
    }

    return 0;
}