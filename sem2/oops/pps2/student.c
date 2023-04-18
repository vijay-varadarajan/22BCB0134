#include <stdio.h>
#include <string.h>
#include <ctype.h>

// construct Student stucture
struct Student {
    char roll_no[50];
    char stud_name[50];
    char course[50];
};

void print_details(struct Student student); // function prototype to print details passing student structure

int main(void)
{
    struct Student student;
    char temp, tmproll[50], tmpname[50], tmpcourse[50];

    // get details from user and copy strings to structure using strcpy
    printf("Enter student details:\n");
    printf("Roll number:");
    scanf("%s", tmproll);
    strcpy(student.roll_no, tmproll);

    printf("Name:");
    scanf("%s", tmpname);
    strcpy(student.stud_name, tmpname);

    printf("Course:");
    scanf("%s", tmpcourse);
    strcpy(student.course, tmpcourse);

    print_details(student); //call function to print obtained details passing in student structure variable
}

void print_details(struct Student student)
{
    int valid_roll = 1, valid_name = 1, valid_course = 1;

    printf("\nStudent details: ");
    
    // check if roll number is valid
    for (int i = 0; student.roll_no[i] != '\000'; i++)
    {    
        if (!isdigit(student.roll_no[i]))
        {
            valid_roll = 0;
            break;
        }
    }
    
    // check if name is valid
    for (int i = 0; student.stud_name[i] != '\000'; i++)
    {
        if (!isalpha(student.stud_name[i]))
        {
            valid_name = 0;
            break;
        }
    }

    // check if course is valid
    for (int i = 0; student.course[i] != '\000'; i++)
    {
        if (!isalpha(student.course[i]))
        {
            valid_course = 0;
            break;
        }
    }

    // print output accordingly
    if (!valid_name && !valid_course && !valid_roll)
    {
        printf("\nInvalid Structure Element");
    }
    else
    {
        if (valid_roll == 1)
            printf("\nRoll number: %s", student.roll_no);
        else
            printf("\nEnter valid roll number");

        if (valid_name == 1)
            printf("\nName: %s", student.stud_name);
        else
            printf("Enter valid name\n");

        if (valid_course == 1)
            printf("\nCourse: %s", student.course);
        else
            printf("\nEnter valid course\n");
    }
};
