#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


/************************* NOTE SOMETIMES THIS GETS STUCK IN INFINITE LOOP, COULDN'T FIGURE OUT WHY, BUT IF 
							YOU RUN IT AGAIN IT SHOULD WORK*************************/


#define CHANCE_NOT_USE 100
#define CHANCE_NOT_BUY 100

int isInK(int k[], int card);
int selectKingdomCards( int possible[], int k[]);
int countHandMoney(struct gameState *p, int currentPlayer);
int isInArray(int a[], int aLength, int item);

//int actionCardFinder(struct gameState *p, int handActionCards[], int handActionCardsLength, int possibleActionCards[], int possibleActionCardsLength); 

int main (int argc, char** argv) {
	struct gameState g;
	struct gameState *p = &g;


	int i;
	int k[10];
	int possibleKingdom[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
	int currentPlayer;
	int currentCard;
	int cardPlayed;
	int turn = 0;
	//int numActions;
	time_t t;
	
	
	srand((unsigned) time(&t));
	
	
	int numPlayer = (rand() % 2) + 2;

	selectKingdomCards( possibleKingdom, k);
  
	printf ("Starting game.\n");
	
	srand((unsigned) time(&t));
  
	initializeGame(numPlayer, k, rand(), p);
  
	//int money = 0;
  
	while(!isGameOver(p))
	{
		printf("turn: %i \n", turn);
		turn++;
		//money = 0;
		currentPlayer = whoseTurn(p);
		
		printf("player %i turn\n", currentPlayer);
		//numBuys = g.numBuys;
		
		
		
		//if(currentPlayer == 0)
		//{
			//money += countHandMoney(p, currentPlayer);
			//numActions = g.numActions;
		
		cardPlayed = 0;
			
			
		for(i=0; i<numHandCards(p) && cardPlayed != 1; i++)
		{
			//action phase
			currentCard = g.hand[currentPlayer][i];
			
			
			switch(currentCard)
			{
				case adventurer:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played adventurer\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case council_room:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played council_room\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case feast:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played feast\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case gardens:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played gardens\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case mine:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played mine\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case remodel:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played remodel\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case smithy:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case village:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played village\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case baron:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played baron\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case great_hall:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played great_hall\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case minion:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played minion\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case steward:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played steward\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case tribute:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case ambassador:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played ambassador\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case cutpurse:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played cutpurse\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case embargo:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played embargo\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case outpost:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played outpost\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case salvager:
					if( rand() % CHANCE_NOT_USE == -1)
					{
						printf("player %i played salvager\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case sea_hag:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played sea_hag\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				case treasure_map:
					if( rand() % CHANCE_NOT_USE != 0)
					{
						printf("player %i played treasure_map\n", currentPlayer);
						playCard(i, -1, -1, -1, p);
						cardPlayed = 1;
					}
					break;
				default:
					break;
			}
					
				
		}
		
		if(cardPlayed == 0)
		{
			updateCoins(currentPlayer, p, 0);
		}
			
			//buy phase
			//for(i=0; i<numBuys; i++)
			//
			
		if(g.coins == 8)
		{
			
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought province\n", currentPlayer);
				buyCard(province, p);
			}
		}
		if(g.coins == 6)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought gold\n", currentPlayer);
				buyCard(gold, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought adventurer\n", currentPlayer);
				buyCard(adventurer, p);
			}
		}
		if(g.coins == 5)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought duchy\n", currentPlayer);
				buyCard(duchy, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought council_room\n", currentPlayer);
				buyCard(council_room, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought mine\n", currentPlayer);
				buyCard(mine, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought minion\n", currentPlayer);
				buyCard(minion, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought tribute\n", currentPlayer);
				buyCard(tribute, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought outpost\n", currentPlayer);
				buyCard(outpost, p);
			}
		}
		if(g.coins == 4)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought feast\n", currentPlayer);
				buyCard(feast, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought gardens\n", currentPlayer);
				buyCard(gardens, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought remodel\n", currentPlayer);
				buyCard(remodel, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought smithy\n", currentPlayer);
				buyCard(smithy, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought baron\n", currentPlayer);
				buyCard(baron, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought cutpurse\n", currentPlayer);
				buyCard(cutpurse, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought salvager\n", currentPlayer);
				buyCard(salvager, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought sea_hag\n", currentPlayer);
				buyCard(sea_hag, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought treasure_map\n", currentPlayer);
				buyCard(treasure_map, p);
			}
		}
		if(g.coins == 3)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought silver\n", currentPlayer);
				buyCard(silver, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought village\n", currentPlayer);
				buyCard(village, p);
			}
			else if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought great_hall\n", currentPlayer);
				buyCard(great_hall, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought steward\n", currentPlayer);
				buyCard(steward, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought ambassador\n", currentPlayer);
				buyCard(ambassador, p);
			}
		}
		if(g.coins == 2)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought estate\n", currentPlayer);
				buyCard(estate, p);
			}
			else if( rand() % CHANCE_NOT_BUY == -1 )
			{
				printf("player %i bought embargo\n", currentPlayer);
				buyCard(embargo, p);
			}
		}
		if(g.coins == 0)
		{
			if( rand() % CHANCE_NOT_BUY != 0 )
			{
				printf("player %i bought copper\n", currentPlayer);
				buyCard(copper, p);
			}
		}
			
		printf("player %i: endTurn\n", currentPlayer);
		
		endTurn(p);
		
		for(i=0; i<g.numPlayers; i++)
		{
			printf ("Player %i: %d\n", i, scoreFor(i, p) );
		}
				
	}
	
	
	
	printf ("Finished game.\n");
	
	for(i=0; i<g.numPlayers; i++)
	{
		printf ("Player %i: %d\n", i, scoreFor(i, p) );
	}
		
	return 0;
}

		
int selectKingdomCards(int possible[], int k[])
{
	int i;
	int r;
	int card;
	
	time_t t;
	
	srand((unsigned) time(&t));
	
	for(i=0; i<10; i++)
	{
		r = rand() %20;
		card = possible[r];
		
		if( isInK(k, card) == 0)
		{
			k[i] = card;
		}
		else
		{
			i--;
		}
	}
	
	return 0;
}


int isInK(int k[], int card)
{
	int i;
	
	for( i=0; i<10; i++)
	{ 
		if(k[i] == card)
		{
			return 1;
		}
	}
	
	return 0;
}
	


int countHandMoney(struct gameState *p, int currentPlayer)
{
	int i=0;
	int money = 0;
	
	for(i=0; i<numHandCards(p); i++)
	{
		if (handCard(i, p) == copper)
		{
			money++;
		}
		else if (handCard(i, p) == silver)
		{
			money += 2;
		}
		else if (handCard(i, p) == gold)
		{
			money += 3;
		}
	}
	
	return money;
}


/*
int actionCardFinder(struct gameState *p, int handActionCards[], int handActionCardsLength)
{
	int i;
	
	for(i=0; i<numHandCards(p); i++)
	{
		if( adventurer)
		
	}
}
*/
	
	
	
int isInArray(int a[], int aLength, int item)
{
	int i;
	
	for(i=0; i<aLength; i++)
	{
		if(a[i] == item)
		{
			return i;
		}
	}
	return 0;
}