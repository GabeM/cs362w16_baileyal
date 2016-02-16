#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	int i, j, l, n, players, player, handCount, deckCount, seed, address;
	//struct gameState state;
	struct gameState state;
	struct gameState stat;
	struct gameState sta;

  printf("Running Random Adventurer Test\n");

	/*
								--- Author's Note ---
	So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	*/

	for (i = 0; i < MAX_TESTS; i++) 
	{
		players = (rand() % 2) + 2; //make the number of players either 2, 3, or 4 otherwise the game won't initialize correctly
		player = 1;
		
	   seed = rand();		//pick random seed
		
	   initializeGame(players, k, seed, &state);	//initialize Gamestate 

		//Initiate valid state variables
		
		//state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size		
		//state.discardCount[player] = rand() % MAX_DECK;
		//state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];

		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0) {
		
			for(j=0; i<players; i++)
			{
				for (k = 0; i < state.discardCount[j];i++) //move all the deck to the discard pile
				{
					state.discard[player][discardCount] = state.deck[player][k];
					state.deck[player][k] = -1;
					state.deckCount[player]--;
					state.discardCount++;
				}
			}
		}
		
		cardEffect(adventurer, 1, 1, 1, &state);		//Run adventurer card
		
		my_assert(state.deckCount[player] == (handCount + 2), "player did not have to more cards", numAsserts);
		
		printf("i: %i numAsserts: %i \n", i, numAsserts);
		
	}
	
	
	printf("test complete\n");
	
	  
	return 0;
}
