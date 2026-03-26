#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char name[50];
    float grade;
} Student;

typedef struct
{
    Student *list;
    int numStudents;
    int capacity;
} StudentManager;

StudentManager *createManager(int initialCapacity);
void addStudent(StudentManager *manager, char *name, float grade);
float calculateAverage(StudentManager *manager);
void listStudents(StudentManager *manager);
void freeManager(StudentManager *manager);
int validateGrade(float grade);

StudentManager *createManager(int initialCapacity)
{
    StudentManager *manager = (StudentManager *)malloc(sizeof(StudentManager));

    if (manager == NULL)
    {
        return NULL;
    }

    manager->list = (Student *)malloc(initialCapacity * sizeof(Student));

    if (manager->list == NULL)
    {
        free(manager);
        return NULL;
    }

    manager->numStudents = 0;
    manager->capacity = initialCapacity;

    return manager;
}

int validateGrade(float grade)
{
    return (grade >= 0 && grade <= 20);
}

void addStudent(StudentManager *manager, char *name, float grade)
{
    if (manager == NULL)
    {
        printf("Error: invalid manager.\n");
        return;
    }

    if (!validateGrade(grade))
    {
        printf("Error: invalid grade (must be between 0 and 20).\n");
        return;
    }

    if (manager->numStudents >= manager->capacity)
    {
        int newCapacity = manager->capacity * 2;
        Student *newList = (Student *)realloc(manager->list,
                                              newCapacity * sizeof(Student));

        if (newList == NULL)
        {
            printf("Error expanding list!\n");
            return;
        }

        manager->list = newList;
        manager->capacity = newCapacity;
        printf("List expanded to %d students.\n", newCapacity);
    }

    strcpy(manager->list[manager->numStudents].name, name);
    manager->list[manager->numStudents].grade = grade;
    manager->numStudents++;
    printf("Student added successfully!\n");
}

float calculateAverage(StudentManager *manager)
{
    float sum = 0;
    int i;

    if (manager == NULL || manager->numStudents == 0)
    {
        printf("There are no registered students.\n");
        return 0;
    }

    for (i = 0; i < manager->numStudents; i++)
    {
        sum += manager->list[i].grade;
    }

    return sum / manager->numStudents;
}

void listStudents(StudentManager *manager)
{
    int i;

    if (manager == NULL || manager->numStudents == 0)
    {
        printf("No registered students.\n");
        return;
    }

    printf("\n=== Student List (Total: %d) ===\n", manager->numStudents);
    for (i = 0; i < manager->numStudents; i++)
    {
        printf("%d. %s - %.2f\n", i + 1,
               manager->list[i].name,
               manager->list[i].grade);
    }
}

void freeManager(StudentManager *manager)
{
    if (manager != NULL)
    {
        if (manager->list != NULL)
        {
            free(manager->list);
            manager->list = NULL;
        }
        free(manager);
        printf("Memory freed successfully.\n");
    }
}

int main(void)
{
    StudentManager *manager = createManager(10);
    int option;
    char name[50];
    float grade;

    if (manager == NULL)
    {
        printf("Error creating student manager!\n");
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
            printf("Name: ");
            scanf("%s", name);
            printf("Grade (0-20): ");
            scanf("%f", &grade);
            addStudent(manager, name, grade);
            break;
        case 2:
            printf("Average: %.2f\n", calculateAverage(manager));
            break;
        case 3:
            listStudents(manager);
            break;
        case 0:
            printf("Closing program...\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (option != 0);

    freeManager(manager);
    return 0;
}