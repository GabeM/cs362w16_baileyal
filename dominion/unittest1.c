#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion.c"

#define DEBUG 0
#define NOISY_TEST 1


//testing the numHandsCards func
int main(int argc, char **argv)
{
	int assertCount = 0;
	int r;
	struct gameState game;
	
	game.numPlayers = 1;
	game.whoseTurn = 0;
	
	game.handCount[0] = 3;
	
	numHandsCards(&game);
	
	my_assert(r == 3, "handCount didn't return the right number, i.e. 3", assertCount);
	
	my_assert(game.handCount[0] == 3, "handCount wasn't still 0", assertCount);
	printf("number of asserts for numHandsCards test: %i\n", assertCount);
}
	
	
	
	
	