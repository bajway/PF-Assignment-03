/*Create a program to validate an email address based on a few basic criteria. The program will
prompt the user to enter an email address and will dynamically allocate memory to store and
process the input.
Define the following function:
1. int validateEmail(char* email): This function validates the email based on the following
criteria:
○ Contains exactly one @ symbol.
○ Contains at least one dot (.) after the @ symbol.
○ Is non-empty.
○ Returns 1 if the email is valid, and 0 if invalid.

Steps:
1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for the
email, ensuring the memory size is based on the input length.
2. Validation Process:
○ Call the validateEmail function to check if the email meets the criteria.
3. Display Results:
○ Print "Valid Email" if the email meets the criteria.
○ Print "Invalid Email" if the email does not meet the criteria.
4. Memory Cleanup:
○ Free the dynamically allocated memory after validation to prevent memory leaks.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int validateEmail(char* email){
    int atCount =0, dotAfterAt=0, foundAt=0; //initializers
    for (int i = 0; i < strlen(email); i++)
    {
        if(email[i] == '@'){
            atCount++;
            foundAt = 1;
        }
        if(foundAt=1 && email[i]=='.'){
            dotAfterAt++;
            
        }
    }//end for loop
    if(atCount==1 && dotAfterAt>=1 && email[0]!='\0') //If email is valid
    {
        return 1;
    }
    else //invalid email
    {
        return 0;
    }
} //end email Validate function
int main(){
    char *email;
    int emailSize = 100;

    email = (char *)malloc(emailSize * sizeof(char));
    if (email==NULL)
    {
        printf("Memory allocation Failed!\n");
        return 1;
    }
    
        printf("Enter your email address: ");
        fgets(email, emailSize, stdin);
        size_t length = 0;
        while (email[length] !='\0')
        {
            length++;
        }
        if ( length>0 && email[length-1]=='\n')
        {
            email[length - 1] = '\0';
        }
        printf("Email adress is: %s\n", email);
        
        int output = validateEmail(email);
        if (output==1)
        {
            printf("This is a valid Email Address\n");
        }
        else{
            printf("This is an invalid Email Address\n");
        }
        free(email);
        return 0;
} //End main