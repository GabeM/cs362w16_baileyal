#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1


//testing card great_hall
int main(int argc, char **argv)
{
	struct gameState game;
	int r;
	int assertCount = 0;
		
	
	
	game.numPlayers = 1;
	game.deck[0][0] = copper;
	game.deckCount[0] = 1;
	game.handCount[0] = 1;
	game.hand[0][0] = great_hall;
	game.numActions = 1;

	r = cardEffect(great_hall, 0, 0, 0, game, 0, 0);
	
	my_assert( r == 0, "great_hall didn't return 0", assertCount);
	my_assert( game.deckCount == 0, "deckCount doesn't equal 0", assertCount);
	my_assert( game.handCount == 1, "handCount doesn't equal 1", assertCount);
	my_assert( game.hand[0][0] == copper, "player hand didn't have copper", assertCount);
	my_assert( game.numActions == 1, "numActions doesn't equal 1", assertCount);
	
	
	printf("number of asserts for great_hall card test: %i\n", assertCount);
		
	
}