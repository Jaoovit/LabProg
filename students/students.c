#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // added for setlocale

// Structure to store student data
typedef struct
{
    char name[50];
    float grade;
} Student;

// Function prototypes
void addStudent(char *name, float grade, int numStudents, Student *students);
float calculateAverage(int numStudents, Student *students);
void listStudents();
void freeMemory();

// Main function
int main()
{
    int option;
    char name[50];
    float grade;
    setlocale(LC_ALL, "PT");
    int numStudents = 0;
    Student *students = (Student *)malloc(10 * sizeof(Student));

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
            printf("Name: ");
            scanf("%s", name);
            printf("Grade: ");
            scanf("%f", &grade);
            addStudent(name, grade, numStudents, students);
            break;
        case 2:
            printf("Average: %.2f\n", calculateAverage(numStudents, students));
            break;
        case 3:
            listStudents(numStudents, students);
            break;
        }
    } while (option != 0);

    freeMemory();
    return 0;
}

// Adds a student to the list
void addStudent(char *name, float grade, int numStudents, Student *students)
{
    if (numStudents < 10)
    {
        strcpy(students[numStudents].name, name);
        students[numStudents].grade = grade;
        numStudents++;
        printf("Student added successfully!\n");
    }
    else
    {
        printf("List is full!\n");
    }
}

// Calculates the average grade
float calculateAverage(int numStudents, Student *students)
{
    float sum;
    int i;

    for (i = 0; i < numStudents; i++)
    {
        sum = sum + students[i].grade;
    }
    return sum / numStudents;
}

// Lists all students
void listStudents(int numStudents, Student *students)
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
void freeMemory()
{
    printf("Freeing memory...\n");
    // (memory release code omitted by the original programmer)
}