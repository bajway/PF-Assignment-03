/*Write a program that organizes a digital cricket match, "Cricket Showdown," where two players,
Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each ball.
Players can enter scores between 0 and 6 for each ball, and if a score outside this range is entered,
it will be disregarded, but the ball will still be marked.
1. Define a structure Player with the following members:
a. ballScores[12]: An array to store the score for each ball.
b. playerName: A string to hold the player's name.
c. totalScore: An integer to store the total score for each player.
2. Define functions:
a. playGame(struct Player player): This function prompts each player to enter their
score for each of the 12 balls.
b. validateScore(int score): This function checks if the score is between 0 and 6
(inclusive). If it’s not, the score is disregarded, but the ball is still marked.
c. findWinner(struct Player player1,struct Player player2): Determines the winner based
on the total score.
d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
summary of each player’s performance, including each ball’s score, the average
score, and total score.*/
#include<stdio.h>
struct Player
{
    int ballScores[12];
    char playerName[50];
    int totalScore;
};
void playGame(struct Player *player){
    printf("Enter the name of player: ");
    scanf("%s", player->playerName);
    printf("Enter the score for the 12 balls you played: ");
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &player->ballScores[i]);
    }
    
}
int validateScore(struct Player *player){
    
    int totalScore = 0;
    for (int i = 0; i < 12; i++)
    {
        if (player->ballScores[i]>=0 && player->ballScores[i]<=6)
        {
           totalScore += player->ballScores[i];
           
        }
        else
        {
            continue;
        }
        
    }
    player->totalScore = totalScore;
    return totalScore;  
}
 int findWinner(struct Player *player1, struct Player *player2){
    if (player1->totalScore > player2->totalScore)
    {
        return 1;
    }
    else if (player1->totalScore < player2->totalScore)
    {
        return 2;
    }
    else
    {
        return 0; //Incase if tie
    }
    
}
void displayMatchScoreboard(struct Player p1, struct Player p2){
    printf("\n* * * * * * * Score Board * * * * * * *\n");
    printf("Summary of player: %s\n", p1.playerName);
    printf("Each ball score:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("Ball[%d] Score = %d\n", i + 1, p1.ballScores[i]);
    }
    float averageScore = p1.totalScore / 12.0;
    printf("Average Score = %f\n", averageScore);
    printf("Total Score of %s is %d \n\n= ", p1.playerName, p1.totalScore);
    printf("Summary of player: %s\n", p2.playerName);
    printf("Each ball score:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("Ball[%d] Score = %d\n", i + 1, p2.ballScores[i]);
    }
    averageScore = p2.totalScore / 12.0;
    printf("Average Score = %f\n", averageScore);
    printf("Total Score of %s is %d = \n", p2.playerName, p2.totalScore);
}
int main(){
    struct Player player1, player2;
    playGame(&player1);
    playGame(&player2);
    int p1TotalScore = validateScore(&player1);
    int p2TotalScore = validateScore(&player2);
    int winner=findWinner(&player1, &player2);
    displayMatchScoreboard(player1, player2);

    printf("\n* * * * * * * Match Result * * * * * * *\n");
    if (winner == 1) 
        printf("Winner: %s\n", player1.playerName);
    else if (winner == 2) 
        printf("Winner: %s\n", player2.playerName);
    else 
        printf("The match is a tie!\n");
    

    return 0;
    
}
