#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // added for setlocale

/**
 * Documentation
 *
 * 1. Initialize the variable `sum` to 0 in the `calculateAverage()` function.
 * 2. Free allocated memory in the `freeMemory()` function when the program finishes.
 * 3. Limit `scanf` input to 49 characters using `scanf("%49s", name);`.
 * 4. Add validation to check if the student list size is less than 10 before adding a new student.
 * 5. Calculate the average only if there are students in the list to avoid division by zero.
 * 6. Prevent failure during initial memory allocation.
 */

// Structure to store student data
typedef struct
{
    char name[50];
    float grade;
} Student;

// Global variables
Student *students;
int numStudents;

// Function prototypes
void addStudent(char *name, float grade);
float calculateAverage();
void listStudents();
void freeMemory(Student *variable);

// Main function
int main(void)
{
    int option;
    char name[50];
    float grade;
    setlocale(LC_ALL, "PT");
    numStudents = 0;
    students = (Student *)malloc(10 * sizeof(Student));

    if (students == NULL)
    {
        printf("Sorry, the program cannot start due to insufficient memory.\n");
        printf("Please close other programs and try again.\n");
        return 1;
    }

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Add student\n");
        printf("2. Calculate average\n");
        printf("3. List students\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (numStudents < 10)
            {
                printf("Name: ");
                scanf("%49s", name);
                printf("Grade: ");
                scanf("%f", &grade);
                addStudent(name, grade);
            }
            else
            {
                printf("Student list is full\n");
            }
            break;
        case 2:
            printf("Average: %.2f\n", calculateAverage());
            break;
        case 3:
            listStudents();
            break;
        }
    } while (option != 0);

    freeMemory(students);
    return 0;
}

// Adds a student to the list
void addStudent(char *name, float grade)
{

    strcpy(students[numStudents].name, name);
    students[numStudents].grade = grade;
    numStudents++;
    printf("Student added successfully!\n");
}

// Calculates the average grade
float calculateAverage()
{
    float sum = 0;
    int i;

    if (numStudents == 0)
    {
        return 0;
    }

    for (i = 0; i < numStudents; i++)
    {
        sum = sum + students[i].grade;
    }

    return sum / numStudents;
}

// Lists all students
void listStudents()
{
    int i;

    if (numStudents == 0)
    {
        printf("No students registered.\n");
        return;
    }

    printf("\n=== Student List ===\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("%d. %s - %.2f\n", i + 1, students[i].name, students[i].grade);
    }
}

// Frees the allocated memory
void freeMemory(Student *variable)
{
    free(variable);
    variable = NULL;
    printf("Freeing memory...\n");
    // (memory release code omitted by the original programmer)
}