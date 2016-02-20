#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1


//testing card baron
int main(int argc, char **argv)
{
	struct gameState game;
	int r;
	int assertCount = 0;
		
	
	game.numPlayers = 1;
	game.deck[0][0] = copper;
	game.deckCount[0] = 1;
	game.handCount[0] = 1;
	game.hand[0][0] = baron;
	game.numActions = 1;
	game.supplyCount[estate] = 2;
	game.playedCardCount = 0;
	game.numBuys = 0;
	game.discardCount[0] = 0;
	

	r = cardEffect(baron, 0, 0, 0, &game, 0, 0);
	
	
	my_assert( r == 0, "baron didn't return 0", &assertCount);
	my_assert( game.handCount[0] == 1, "handCount doesn't equal 1", &assertCount);
	my_assert( game.supplyCount[estate] == 1, "supplyCount doesn't equal 1", &assertCount);
	
	
	printf("\nnumber of asserts for baron card test: %i\n\n", assertCount);
		
	return 0;
	
}