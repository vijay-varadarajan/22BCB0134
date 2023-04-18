#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Personal { // construct Personal structure
    char name[100];
    char dob[50];
    char salary[20];
};

int main(void)
{
    struct Personal personal;
    
    char temp, tmpname[100], tmpdob[50], tmpsalary[20]; // declare variables to store data
    int basic_salary; float HRA, DA, TA, gross_salary, PF, Income_tax, net_salary;

    printf("\nName: "); // get name, dob and salary and copy it to structure variables
    fgets(tmpname,100,stdin);
    strcpy(personal.name, tmpname);

    printf("DOB: ");
    fgets(tmpdob,50,stdin);
    strcpy(personal.dob, tmpdob);

    printf("Enter basic salary: ");
    fgets(tmpsalary,20,stdin);
    strcpy(personal.salary, tmpsalary);

    for (int i = 0; tmpsalary[i] != '\0'; i++) // check if salary is a float
    {
        if (tmpsalary[i] == '.')
        {
            printf("\nInvalid input. Please enter a valid input.");
            return 1;
        }
    }

    basic_salary = atoi(personal.salary); // convert salary to integer

    if (basic_salary == 0 && tmpsalary[0] != '0') // check if salary is not characters
    {
        printf("\nInvalid input. Please enter a valid input.");
        return 1;
    }

    // calculate HRA, DA, TA, gross_salary, PF, Income_tax, net_salary
    HRA = 0.24 * basic_salary;
    DA = 0.15 * basic_salary;
    TA = 4000.00;
    gross_salary = basic_salary + HRA + DA + TA;
    PF = 0.1 * basic_salary;
    Income_tax = 0.05 * gross_salary;
    net_salary = gross_salary - PF - Income_tax;

    // print calculated values
    printf("\n\t Basic Salary\t: %i", basic_salary);
    printf("\n\t HRA \t\t: %.1f", HRA);
    printf("\n\t DA \t\t: %.1f", DA);
    printf("\n\t TA \t\t: %.1f", TA);
    printf("\n\t Gross Salary\t: %.1f", gross_salary);
    printf("\n\t PF \t\t: %.1f", PF);
    printf("\n\t Income tax\t: %.1f", Income_tax);
    printf("\n\t Net salary\t: %.1f", net_salary);
}