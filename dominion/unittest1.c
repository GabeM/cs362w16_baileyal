#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


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
	
	r = numHandCards(&game);
	
	my_assert(r == 3, "numHandCards didn't return 3", &assertCount);
	my_assert(game.whoseTurn == 0, "whoseTurn wasn't still 0", &assertCount);
	
	my_assert(game.handCount[0] == 3, "handCount wasn't still 0", &assertCount);
	printf("number of asserts for numHandsCards test: %i\n", assertCount);
}
	
	
	
	
	