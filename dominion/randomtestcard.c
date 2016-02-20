#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 10

//This randomly tests council room

int main() {

		int assertCount = 0;
		
	  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, l, n, players, player = 0, handCount, deckCount, seed, address, numBuys, r, newHandCount;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for council_room\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.
	  (I just put this on the second file as well)

	  This program wouldn't work without the printouts, oddly enough.
	  */

		for (i = 0; i < MAX_TESTS; i++) {
		
			players = 4; //(rand() % 2) + 2; 
			player = 0;
			
			
			seed = rand();		//pick random seed
			
			initializeGame(players, k, seed, &state);	//initialize Gamestate

			//Initiate valid state variables
			//state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			//state.discardCount[player] = rand() % MAX_DECK;
			//state.handCount[player] = rand() % MAX_HAND;
			
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
			numBuys = state.numBuys;

			
			
			//1 in 3 chance of making empty deck for coverage
			if (seed % 3 == 0) {
			
				for (l = 0; l < state.discardCount[j]; l++) //move all the deck to the discard pile
				{
					state.discard[player][ state.discardCount[player] ] = state.deck[player][l];
					state.deck[player][l] = -1;
					state.deckCount[player]--;
					state.discardCount[player]++;
				}
				
			}
			

			
			state.whoseTurn = player;
			state.hand[player][0] = 8;
			
			
			r = playCard(player, 1, 1, 1, &state);		//Run adventurer card
			
			
			my_assert( r == 0, "r wasn't 0", &assertCount);
			
			for(j=1; j<players; j++)
			{
				my_assert(state.handCount[j] == 1, "one of the players did not have 1 more cards in hand", &assertCount);
			}
			
			my_assert(state.handCount[player] == (handCount - 1 + 4), "player did not have 4 more cards in hand", &assertCount);
			my_assert(state.numBuys == (numBuys + 1), "player did correct number of buys", &assertCount);
			
			
			  
			  
		}
		
		printf("number of asserts for council_room : %i \n", assertCount);
	
		printf("test completed\n");
		
		return 0;
		
	}