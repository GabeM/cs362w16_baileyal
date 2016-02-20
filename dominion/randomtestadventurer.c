#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 10

//This randomly tests Adventurer

int main() {
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	int i, j, l, n, players, player, handCount, deckCount, seed, address;
	int assertCount = 0, newHandCount, r;
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
		
		newHandCount = rand() % 4 + 1; //there must always be at least 1 card because it is adventurer
		
		
		for(j=5; j > newHandCount; j--)
		{
			state.discard[player][ state.discardCount[player] ] = state.hand[player][j];
			state.hand[player][j] = -1;
			state.handCount[player] -= 1;
			state.discardCount[player]++;
		}
		


		  //Copy state variables
		handCount = state.handCount[player];
		deckCount = state.deckCount[player];
		
		//printf("handCount before: %i \n", handCount);

		
		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0) {
		
			for (j = 0; j < state.deckCount[player];j++) //move all the deck to the discard pile
			{
				state.discard[player][ state.discardCount[player] ] = state.deck[player][j];
				state.deck[player][j] = -1;
				state.deckCount[player] -= 1;
				state.discardCount[player]++;
			}
			
		}
		
		
		state.hand[player][0] = adventurer; //give the player adventurer
		state.whoseTurn = player;
		
		
		r = playCard(0, 1, 1, 1, &state);		//Run adventurer card
		
		//printf("new hand: %i  old hand: %i \n", state.handCount[player], handCount);
		
		my_assert( r == 0, "playCard didn't return 0", &assertCount);
		my_assert(state.handCount[player] == (handCount + 2 ), "player did not have correct number of cards", &assertCount);
		
		
	}
		
	printf("number of asserts for adventurer random test: %i \n", assertCount);
	
	
	printf("test complete\n");
	
	  
	return 0;
}
