#include <stdio.h>
#include <string.h>

//Structs
struct Course {
    char course_code[20];
    char course_name[50];
};

struct Grade {
    int mark;
    char grade;
    int is_set; // 0 if not calculated, 1 if calculated
};

struct Student {
    char reg_no[21];
    char name[51];
    int age;
    struct Course course;
    struct Grade grade;
};

struct Student students[40];
int count = 0;

char calculate_grade(int mark) {
    if (mark > 69) return 'A';
    else if (mark > 59) return 'B';
    else if (mark > 49) return 'C';
    else if (mark > 39) return 'D';
    else return 'E';
}
void add_student() {
    if (count >= 40) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    printf("Enter registration number: ");
    scanf(" %20s", students[count].reg_no);

    printf("Enter name: ");
    scanf(" %50[^\n]", students[count].name);

    printf("Enter age: ");
    scanf("%d", &students[count].age);

    printf("Enter course code: ");
    scanf(" %19s", students[count].course.course_code);

    printf("Enter course name: ");
    scanf(" %49[^\n]", students[count].course.course_name);

    students[count].grade.is_set = 0;

    count++;
    printf("Student added successfully.\n");
}

void edit_student() {
    char reg_no[21];
    printf("Enter registration number of student to edit: ");
    scanf(" %20s", reg_no);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            printf("Editing student %s\n", students[i].name);

            printf("Enter new name: ");
            scanf(" %50[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course code: ");
            scanf(" %19s", students[i].course.course_code);

            printf("Enter new course name: ");
            scanf(" %49[^\n]", students[i].course.course_name);

            printf("Details updated.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void add_marks() {
    char reg_no[21];
    printf("Enter registration number of student to enter marks for: ");
    scanf(" %20s", reg_no);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].reg_no, reg_no) == 0) {
            if (students[i].grade.is_set) {
                printf("Grade already set. Cannot change.\n");
                return;
            }

            int mark;
            printf("Enter mark (0-100): ");
            scanf("%d", &mark);

            if (mark < 0 || mark > 100) {
                printf("Invalid mark. Must be between 0 and 100.\n");
                return;
            }

            students[i].grade.mark = mark;
            students[i].grade.grade = calculate_grade(mark);
            students[i].grade.is_set = 1;

            printf("Mark and grade set successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}
//display students
void display_students() {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Reg No: %s\n", students[i].reg_no);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course Code: %s\n", students[i].course.course_code);
        printf("Course Name: %s\n", students[i].course.course_name);

        if (students[i].grade.is_set) {
            printf("Mark: %d\n", students[i].grade.mark);
            printf("Grade: %c\n", students[i].grade.grade);
        } else {
            printf("Grade: Not yet set.\n");
        }

        printf("-----------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Add Marks and Calculate Grade\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: edit_student(); break;
            case 3: add_marks(); break;
            case 4: display_students(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
