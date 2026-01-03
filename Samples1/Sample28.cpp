#include <stdio.h>
struct Player
{
	int ballScores[12];
	char playerName[50];
	float totalScore;
};
int validateScore(int score)
{
	if (score>=0 && score <=6)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct Player playGame(struct Player player)
{
	int score;
	for (int i=0;i<12;i++)
	{
		printf("Enter score for the ball %d:\n",i+1);
		scanf("%d",&score);
		if (validateScore(score)==1)
		{
			player.ballScores[i]=score;
		}
		else
		{
			player.ballScores[i]=0;
		}
	}
	return player;
}
int findWinner(struct Player *player1,struct Player *player2)
{
	for (int i=0;i<12;i++)
	{
		player1->totalScore=player1->totalScore+player1->ballScores[i];
		player2->totalScore=player2->totalScore+player2->ballScores[i];
	}
	if (player1->totalScore>player2->totalScore)
	{
		printf("%s is the winner\n",player1->playerName);
	}
	else if(player2->totalScore>player1->totalScore)
	{
		printf("%s is the winner\n",player2->playerName);
	}
	else
	{
		printf("It is a tie\n");
	}
}
int displayMatchScoreboard(struct Player player1,struct Player player2)
{
	printf("Scoreboard:");
	printf("\n");
	printf("\n");
	printf("%s\'s scores for each ball: \n",player1.playerName);
	for (int i=0;i<12;i++)
	{
		printf("Ball %d: %d\n",i+1,player1.ballScores[i]);
	}
	printf("%s\'s average score: %f\n",player1.playerName,player1.totalScore/12.0);
	printf("----+----+----+----\n");
	printf("%s\'s scores for each ball: \n",player2.playerName);
	for (int i=0;i<12;i++)
	{
		printf("Ball %d: %d\n",i+1,player2.ballScores[i]);
	}
	printf("%s\'s average score: %f\n",player2.playerName,player2.totalScore/12.0);
}
int main()
{
	struct Player player1,player2;
	player1.totalScore = 0;
	player2.totalScore = 0;
	printf("Enter the name of player1: \n");
	gets(player1.playerName);
	printf("Enter the name of player2: \n");
	gets(player2.playerName);
	printf("----+----+----+----\n");
	printf("Enter the scores of each of the 12 balls played by %s\n",player1.playerName);
	player1=playGame(player1);
	printf("Enter the scores of each of the 12 balls played by %s\n",player2.playerName);
	player2=playGame(player2);
	findWinner(&player1, &player2);
	printf("----+----+----+----\n");
	displayMatchScoreboard(player1,player2);
	
}

