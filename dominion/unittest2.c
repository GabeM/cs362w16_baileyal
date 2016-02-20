#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define DEBUG 0
#define NOISY_TEST 1


//testing the supplyCount() func
int main(int argc, char **argv)
{
	
	int assertCount = 0;
	int r;
	struct gameState game;
	
	game.supplyCount[0] = 10;
	
	r = supplyCount(0, &game);
	
	my_assert( r == 10, "supplyCount didn't return correct number, i.e. 10", assertCount);
	my_assert( game.supplyCount[0] == 10, "game didn't have original number of supply, i.e. 10", assertCount);
	
	printf("number of asserts for supplyCount test: %i\n", assertCount);
}