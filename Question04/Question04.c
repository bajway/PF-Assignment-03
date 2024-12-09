/*Questionn 04*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ratings; 
    int totalScore; 
} Employee;
void inputEmployees(Employee* employees, int numEmployees, int numPeriods){
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Enter ratings for Employee %d:\n", i + 1);
        employees[i].ratings = (int*)malloc(numPeriods * sizeof(int));
        employees[i].totalScore = 0;

        for (int j = 0; j < numPeriods; j++) 
        {
            do 
            {
                printf("  Period %d (1-10): ", j + 1);
                scanf("%d", &employees[i].ratings[j]);
            } while (employees[i].ratings[j] < 1 || employees[i].ratings[j] > 10);
            
            employees[i].totalScore += employees[i].ratings[j];
        }
    }
}//end inputEmployees

void displayPerformance(Employee* employees, int numEmployees, int numPeriods){
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) 
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) 
        {
            printf("%d ", employees[i].ratings[j]);
        }
        printf("(Total Score: %d)\n", employees[i].totalScore);
    }
}//end displayPerformence

// Function to find the top-performing employee
int findEmployeeOfTheYear(Employee* employees, int numEmployees, int numPeriods){
    int topIndex = 0;
    float highestAverage = (float)employees[0].totalScore / numPeriods;

    for (int i = 1; i < numEmployees; i++)
    {
        float average = (float)employees[i].totalScore / numPeriods;
        if (average > highestAverage)
        {
            highestAverage = average;
            topIndex = i;
        }
    }
    return topIndex;
}//end ffindEmployeeOfTheYear

// Function to find the highest-rated period
int findHighestRatedPeriod(Employee* employees, int numEmployees, int numPeriods)
{
    int bestPeriod = 0;
    float highestAverage = 0;

    for (int j = 0; j < numPeriods; j++) 
    {
        int totalRatings = 0;
        for (int i = 0; i < numEmployees; i++)
        {
            totalRatings += employees[i].ratings[j];
        }
        float average = (float)totalRatings / numEmployees;
        if (average > highestAverage)
        {
            highestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}//end findHighestRatedPeriod

// Function to find the worst-performing employee
int findWorstPerformingEmployee(Employee* employees, int numEmployees, int numPeriods){
    int worstIndex = 0;
    float lowestAverage = (float)employees[0].totalScore / numPeriods;

    for (int i = 1; i < numEmployees; i++)
    {
        float average = (float)employees[i].totalScore / numPeriods;
        if (average < lowestAverage) {
            lowestAverage = average;
            worstIndex = i;
        }
    }
    return worstIndex;
}//end findWorstPerformingEmployee
int main() {
    //declaring variables
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);
        //allocate memory
    Employee* employees = (Employee*)malloc(numEmployees * sizeof(Employee));
    inputEmployees(employees, numEmployees, numPeriods); //function call
    //ratingss display
    displayPerformance(employees, numEmployees, numPeriods);
    //dispay top performing employess
    int topEmployee = findEmployeeOfTheYear(employees, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", topEmployee + 1);
    //display hifhest rated period
    int highestRatedPeriod = findHighestRatedPeriod(employees, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(employees, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    //free memory
    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].ratings);
    }
    free(employees);

    return 0;
}//end main
