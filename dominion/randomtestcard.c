#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests smithy

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for Smithy\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.
	  (I just put this on the second file as well)

	  This program wouldn't work without the printouts, oddly enough.
	  */

	  for (i = 0; i < MAX_TESTS; i++) {

		  
		 players = rand() % 4;
		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  		  	  		  		  printf("%d\n", i);


		  cardEffect(smithy, 1, 1, 1, &state);		//Run adventurer card

		  printf("%dB\n", i);
	  }


	   for (i = 0; i < MAX_TESTS; i++) {

		   
		printf("PRE2\n");

		initializeGame(players, k, seed, &stat);	//initialize Gamestate

		printf("POST\n");
		
		//Initiate valid state variables
		stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		stat.discardCount[player] = rand() % MAX_DECK;
		stat.handCount[player] = rand() % MAX_HAND;


		//Copy state variables
		handCount = stat.handCount[player];
		deckCount = stat.deckCount[player];

   		printf("%d\n", i);


		cardEffect(smithy, 1, 1, 1, &stat);		//Run adventurer card

		printf("%dB\n", i);

	  }


	   for (i = 0; i < MAX_TESTS; i++) {


		   	   	  printf("PRE2\n");


 	  initializeGame(players, k, seed, &sta);	//initialize Gamestate

	  	printf("POST2\n");

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  printf("%d\n", i);

		  cardEffect(smithy, 1, 1, 1, &sta);		//Run adventurer card

		 printf("%dB\n", i);

	  }
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests council room

int main() {

		int assertCount = 0;
		
	  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, l, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for Smithy\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.
	  (I just put this on the second file as well)

	  This program wouldn't work without the printouts, oddly enough.
	  */

	for (i = 0; i < MAX_TESTS; i++) {

		players = (rand() % 2) + 2; 
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
		numBuys = state.numBuys;

		printf("%d\n", i);
		
		//1 in 3 chance of making empty deck for coverage
		if (seed % 3 == 0) {
		
			for(j=0; i<players; i++)
			{
				for (l = 0; i < state.discardCount[j];i++) //move all the deck to the discard pile
				{
					state.discard[player][discardCount] = state.deck[player][l];
					state.deck[player][l] = -1;
					state.deckCount[player]--;
					state.discardCount++;
				}
			}
		}

		printf("%dB\n", i);
		cardEffect(council_room, 1, 1, 1, &state);		//Run adventurer card
		
		for(j=0; j<players; j++)
		{
			my_assert(state.handCount[j] == (handCount + 1), "one of the players did not have 1 more cards in hand", assertCount);
		}
		
		my_assert(state.handCount[player] == (handCount + 4), "player did not have 4 more cards in hand", assertCount);
		my_assert(state.numBuys[player] == (numBuys + 1), "player did not have 4 more cards in hand", assertCount);
		
		
		printf("assertCount: %i \n", assertCount); 
		  
		  
		}
	
	printf("test completed\n");
		
	return 0;
		
	  }

	  printf("Tests Complete\n");

	  return 0;
}
