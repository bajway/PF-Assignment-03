/*Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of each
employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxNameLength 50
#define maxDateLength 11
struct Employee
{
    int employeeCode;
    char employeeName[maxNameLength];
    char dateOfJoining[maxDateLength];
} ;
void assignDetails( struct Employee *emp){
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    getchar();
    printf("Enter employee Name: ");
    fgets(emp->employeeName, maxNameLength, stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0'; // Clear input buffer
    printf("Enter employee date of joining: ");
    scanf("%s", &emp->dateOfJoining);
    getchar();
}
void calculateTenure(struct Employee employees[], int count ){
    char todayDate[maxDateLength];
    printf("Enter todays date: ");
    scanf("%s", todayDate); // enter date in yyyy-mm-dd format only
    int currentYear = atoi(strtok(todayDate, "-"));
    int employeeCount = 0;
    int trueCount = 0;
    for (int i = 0; i < count; i++)
    {
        int joiningYear= atoi(strtok(employees[i].dateOfJoining, "-"));
        int tenure = currentYear - joiningYear;
        if (tenure>3)
        {
            printf("Employee code: %d\n", employees[i].employeeCode);
            printf("Name of employee: %s\n", employees[i].employeeName);
            printf("Employee date of joining: %s\n", employees[i].dateOfJoining);
            printf("Tenure of employee: %d years\n", tenure);
            employeeCount++;
        }
        
    }
    printf(" Number of Employees having tenure > 3 are :%d", employeeCount);
}
int main(){//Structure array
    struct Employee employees[4];
    for (int i = 0; i < 4; i++)
    {
        printf("Enter details of Employee[%d]:\n", i + 1);
        assignDetails(&employees[i]);
    }
    calculateTenure(employees, 4);

    return 0;
}//End main

