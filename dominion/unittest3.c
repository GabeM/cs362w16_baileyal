#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define DEBUG 0
#define NOISY_TEST 1

//testing the whoseTurn function
int main(int argc, char **argv)
{
	int assertCount = 0;
	int r;
	struct gameState game;
	
	game.whoseTurn = 0;
	
	r = whoseTurn(&game);
	
	my_assert(r == 0, "whoseTurn didn't return the right number, i.e. 0", assertCount);
	
	my_assert(game.handCount[0] == 0, "whoseTurn wasn't still 0", assertCount);
	printf("number of asserts for whoseTurn test: %i\n", assertCount);
}