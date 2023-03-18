#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int n; 

    // get number of employees
    printf("How many employees' details entered: "); 
    scanf("%d", &n);
    printf("\n");

    // declare arrays of size n to store number, name and salary
    int number[n]; char salary[n][10]; char name[n][50]; 

    // get details of each employee using a loop and store it in the respective arrays
    for (int i = 0; i < n; i++) 
    {
        printf("Enter details of employee %d:\n", i+1);
        printf("Employee number: ");
        scanf("%d", &number[i]);
        printf("Employee name: ");
        scanf("%s", name[i]);
        printf("Salary: ");
        scanf("%s", salary[i]);

        // check if given salary is valid, exit if invalid
        for(int j = 0; j < 10; j++) 
        {
            if(salary[i][j] == '\0')
                break;
            if(salary[i][j] < '0' || salary[i][j] > '9')
            {
                printf("Invalid\n");
                return 1;
            }
        }
    }

    // loop through the salaries array to get the index of employee with max. salary
    int max = 0; 
    for (int i = 1; i < n; i++)
    {
        // if multiple employees have highest salary, exit.
        if (strcmp(salary[i], salary[max]) == 0) 
        {
            printf("Cannot determine\n");
            return 1;
        }
        if (salary[i] > salary[max])
            max = i;
    }

    // print the details of the employee with the maximum salary according to the given format
    printf("\nHighest salary employee details: \n");
    printf("Emp.no  Name  Salary\n");
    printf("%d\t%s\t%s", number[max], name[max], salary[max]);
    return 0;
}
