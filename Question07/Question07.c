/*In a Netflix-like streaming platform, 2D pointers are used to dynamically manage and personalize
the viewing experience for millions of users across diverse content categories and device types.
The platform employs a 2D pointer structure, where each row represents a user profile, and each
column corresponds to a content category (e.g., Action, Drama, Comedy). A double**
engagementMatrix pointer points to this 2D array, where each element stores a numerical
engagement score (e.g., average viewing time or like/dislike ratio) for a user's interaction with that
category.
Each user profile structure includes a pointer to their respective row in the engagement matrix,
allowing for quick retrieval and updates of personalized data. For example,
engagementMatrix[userIndex][categoryIndex] can be updated whenever the user streams content
from a specific category, dynamically recalibrating their preferences in real-time.
The system also uses a secondary 2D pointer structure to manage device-specific preferences.
For instance, deviceMatrix[userIndex][deviceIndex] points to dynamically allocated arrays holding
resolution preferences, playback history, and bandwidth usage for different devices (smart TVs,
laptops, smartphones) associated with a user's profile. This enables seamless transitions between
devices while maintaining personalized settings like resolution and playback position.
Additionally, another 2D pointer system tracks content metadata, where each row corresponds to a
content category and each column represents a specific piece of content. Each element in this
matrix contains a pointer to a structure with attributes like title, rating, runtime, and encoding
formats, enabling quick access to metadata for streaming.
This multi-layered 2D pointer-based design allows the platform to efficiently store, retrieve, and
update personalized recommendations, device preferences, and content metadata. By leveraging
such dynamic data structures, the system delivers a highly tailored, device-optimized viewing
experience for users, ensuring maximum engagement and satisfaction while handling the scalability
needs of a global user base.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definnig structure
typedef struct ContentMetadata{
    char title[100];
    float rating;
    int runtime; //in mins
    char encodingFormat[50];
} ContentMetadata;
double **allocateEngagementMatrix(int users, int categories){
    double **matrix = (double **)malloc(users * sizeof(double *));
    for (int i = 0; i < users; i++) {
        matrix[i] = (double *)malloc(categories * sizeof(double));
        for (int j = 0; j < categories; j++) {
            matrix[i][j] = 0.0; //intializing score
        }
    }
    return matrix;
}//end allocateEngagementMatrix
double **allocateDeviceMatrix(int users, int devices){
    double **matrix = (double **)malloc(users * sizeof(double *));
    for (int i = 0; i < users; i++) {
        matrix[i] = (double *)malloc(devices * sizeof(double));
        for (int j = 0; j < devices; j++) {
            matrix[i][j] = 1080; //default resolution 1080p
        }
    }
    return matrix;
}//end allocateDeviceMatrix
ContentMetadata ***allocateContentMatrix(int categories, int contentPerCategory){
    ContentMetadata ***matrix = (ContentMetadata ***)malloc(categories * sizeof(ContentMetadata **));
    for (int i = 0; i < categories; i++) {
        matrix[i] = (ContentMetadata **)malloc(contentPerCategory * sizeof(ContentMetadata *));
        for (int j = 0; j < contentPerCategory; j++) {
            matrix[i][j] = (ContentMetadata *)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}//end allocateContentMatrx

void populateContentMetadata(ContentMetadata ***matrix, int categories, int contentPerCategory){
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < contentPerCategory; j++) {
            sprintf(matrix[i][j]->title, "Content %d-%d", i, j);
            matrix[i][j]->rating = 4.0 + (j % 5) * 0.2; // Example rating
            matrix[i][j]->runtime = 90 + (j * 5); // Example runtime
            strcpy(matrix[i][j]->encodingFormat, "H.264");
        }
    }
}//end populateContentMetadata
int main() {
    //passinf parameters
    int userCount = 3;
    int categoryCount = 5; 
    int deviceCount = 3;         
    int contentPerCategory = 4;


    double **engagementMatrix = allocateEngagementMatrix(userCount, categoryCount);

    double **deviceMatrix = allocateDeviceMatrix(userCount, deviceCount);

    //allocate content
    ContentMetadata ***contentMatrix = allocateContentMatrix(categoryCount, contentPerCategory);
    populateContentMetadata(contentMatrix, categoryCount, contentPerCategory);

    //updating engagement score for user
    engagementMatrix[0][2] = 5.5; 
    deviceMatrix[1][0] = 720; 

    
    printf("Engagement Matrix:\n");
    for (int i = 0; i < userCount; i++)
    {
        for (int j = 0; j < categoryCount; j++) {
            printf("%.1f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
    printf("Device Preferences Matrix:\n");
    for (int i = 0; i < userCount; i++) {
        for (int j = 0; j < deviceCount; j++) {
            printf("%.1f ", deviceMatrix[i][j]);
        }
        printf("\n");
    }

    // Print content metadata
    printf("\nContent Metadata:\n");
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < contentPerCategory; j++) {
            printf("Category %d, Content %d: %s, Rating: %.1f, Runtime: %d, Format: %s\n",
                   i, j, contentMatrix[i][j]->title, contentMatrix[i][j]->rating,
                   contentMatrix[i][j]->runtime, contentMatrix[i][j]->encodingFormat);
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < userCount; i++)
    {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);//free memory
    free(deviceMatrix);

    for (int i = 0; i < categoryCount; i++) 
    {
        for (int j = 0; j < contentPerCategory; j++) {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);
    return 0;
}//end main
//Sir g thora rehem pleasee
