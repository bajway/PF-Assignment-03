/*You're building an inventory system for a pet shop called "Pets in Heart" that keeps track of
different species of animals and their specific supplies (e.g., food, toys, bedding). The shop
inventory system uses a 2D dynamic array char** speciesSupplies where:
● Rows are explicitly set for each species (e.g., "Dogs," "Cats," "Parrots"), and each row
corresponds to a different species.
● Columns are dynamically allocated for each species to hold their specific supplies (e.g.,
"Food," "Leash," "Toys").
Task:
Write a C program that:
1. Initialize the Inventory: Allocate memory for a specified number of species, with each
species having its own list of supplies (initially empty).
2. Add Supplies: For each species, dynamically allocate memory for a list of supplies and allow
the user to add supplies for that species.
3. Update Supplies: Let users update the name of a supply item for a specific species.
4. Remove Species: Allow users to delete a species and free the associated memory (both for
the species and its supplies).
5. Display Inventory: Show the current supplies for each species in the inventory.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUPPLY_LENGTH 50
//function prototypes
void addSupplies(char ***speciesSupplies, int speciesIndex, int supplyCount);
void updateSupply(char ***speciesSupplies, int speciesIndex, int supplyIndex);
void removeSpecies(char ***speciesSupplies, int *speciesCount, int speciesIndex);
void displayInventory(char ***speciesSupplies, int speciesCount);

int main(){
    char ***speciesSupplies = NULL; //pointer to 2D array
    int speciesCount = 0; //number of species

    int choice;
    do{
        printf("\n* * * Pets in Heart Inventory Menu * * *\n");
        printf("1. Initialize Inventory\n");
        printf("2. Add Supplies for a Species\n");
        printf("3. Update a Supply\n");
        printf("4. Remove a Species\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                initializeInventory(&speciesSupplies, &speciesCount);
                break;
            case 2:
            {
                int speciesIndex, supplyCount;
                printf("Enter species index (0 to %d): ", speciesCount - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex < 0 || speciesIndex >= speciesCount) {
                    printf("Invalid species index.\n");
                    break;
                }
                printf("Enter number of supplies to add: ");
                scanf("%d", &supplyCount);
                addSupplies(speciesSupplies, speciesIndex, supplyCount);
                break;
            }
            case 3:
            {
                int speciesIndex, supplyIndex;
                printf("Enter species index (0 to %d): ", speciesCount - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex < 0 || speciesIndex >= speciesCount)
                {
                    printf("Invalid species index.\n");
                    break;
                }
                printf("Enter supply index to update: ");
                scanf("%d", &supplyIndex);
                updateSupply(speciesSupplies, speciesIndex, supplyIndex);
                break;
            }
            case 4:
            {
                int speciesIndex;
                printf("Enter species index to remove (0 to %d): ", speciesCount - 1);
                scanf("%d", &speciesIndex);
                removeSpecies(speciesSupplies, &speciesCount, speciesIndex);
                break;
            }
            case 5:
                displayInventory(speciesSupplies, speciesCount);
                break;
            case 6:
                printf("Exiting program. Freeing memory...\n");
                //free alocated memeory
                for (int i = 0; i < speciesCount; i++)
                {
                    for (int j = 0; speciesSupplies[i][j] != NULL; j++) {
                        free(speciesSupplies[i][j]);
                    }
                    free(speciesSupplies[i]);
                }
                free(speciesSupplies);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
} //End main

//funtions definations
void initializeInventory(char ***speciesSupplies[], int *speciesCount){
    printf("Enter the number of species: ");
    scanf("%d", speciesCount);
    //allocating memorydynimically
    *speciesSupplies = (char ***)malloc(*speciesCount * sizeof(char **));
    if (*speciesSupplies == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    //intializing each specie to NULL---no supplies yet
    for (int i = 0; i < *speciesCount; i++)
    {
        (*speciesSupplies)[i] = NULL;
    }

    printf("Inventory initialized with %d species. Each species currently has no supplies.\n", *speciesCount);
}//end intializeInventory

void addSupplies(char ***speciesSupplies, int speciesIndex, int supplyCount){
    speciesSupplies[speciesIndex] = (char **)malloc((supplyCount + 1) * sizeof(char *));
    for (int i = 0; i < supplyCount; i++)
    {
        speciesSupplies[speciesIndex][i] = (char *)malloc(MAX_SUPPLY_LENGTH * sizeof(char));
        printf("Enter name of supply %d: ", i + 1);
        scanf("%s", speciesSupplies[speciesIndex][i]);
    }
    speciesSupplies[speciesIndex][supplyCount] = NULL; //terminating row
}//end addSupplies
void updateSupply(char ***speciesSupplies, int speciesIndex, int supplyIndex){
    printf("Enter new name for supply %d: ", supplyIndex);
    char newSupply[MAX_SUPPLY_LENGTH];
    scanf("%s", newSupply);

    free(speciesSupplies[speciesIndex][supplyIndex]);
    speciesSupplies[speciesIndex][supplyIndex] = (char *)malloc(strlen(newSupply) + 1);
    strcpy(speciesSupplies[speciesIndex][supplyIndex], newSupply);

    printf("Supply updated successfully.\n");
}//end updateSupply
void removeSpecies(char ***speciesSupplies, int *speciesCount, int speciesIndex){
    // Free supplies for the species
    for (int i = 0; speciesSupplies[speciesIndex][i] != NULL; i++)
    {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);
    //shifting rows to remove species
    for (int i = speciesIndex; i < *speciesCount - 1; i++) {
        speciesSupplies[i] = speciesSupplies[i + 1];
    }

    (*speciesCount)--;
    speciesSupplies = realloc(speciesSupplies, *speciesCount * sizeof(char **));
    printf("Species removed successfully.\n");
}//end removeSpecies
void displayInventory(char ***speciesSupplies, int speciesCount){
    for (int i = 0; i < speciesCount; i++)
    {
        printf("Species %d:\n", i);
        if (speciesSupplies[i] == NULL)
        {
            printf("  No supplies added.\n");
            continue;
        }
        for (int j = 0; speciesSupplies[i][j] != NULL; j++)
        {
            printf("  - %s\n", speciesSupplies[i][j]);
        }
    }
}
