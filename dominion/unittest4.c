#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define DEBUG 0
#define NOISY_TEST 1

//testing the handCard function
int main(int argc, char **argv)
{
	int assertCount = 0;
	int r;
	struct gameState game;
	
	game.numPlayers = 1;
	game.whoseTurn = 0;
	game.hand[0][0] = 0;
	
	r = handCard(0, &game);
	
	my_assert(r == 0, "handCard didn't return the right number, i.e. 0", assertCount);
	
	my_assert(game.hand[0][0] == 0, "player 1's first card wasn't still 0", assertCount);
	printf("number of asserts for handCard test: %i\n", assertCount);
}