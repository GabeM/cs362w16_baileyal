#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1


//testing card smithy
int main(int argc, char **argv)
{
	struct gameState game;
	int r;
	int assertCount = 0;
	int i;
	
	//printf("start test\n");
	
	game.numPlayers = 1;
	game.deck[0][0] = copper;
	game.deck[0][1] = copper;
	game.deck[0][2] = copper;
	game.deckCount[0] = 3;
	game.handCount[0] = 1;
	game.hand[0][0] = smithy;
	game.playedCardCount = 0;
	
	
	//printf("after setup\n");

	r = cardEffect(smithy, 0, 0, 0, &game, 0, 0);
	
	//printf("after cardEffect\n");
	
	my_assert( r == 0, "smithy didn't return 0", &assertCount);
	my_assert( game.deckCount[0] == 0, "deckCount doesn't equal 0", &assertCount);
	my_assert( game.handCount[0] == 3, "handCount doesn't equal 0", &assertCount);
	for( i = 0; i<3; i++)
	{
		my_assert( game.hand[0][i] == copper, "player hand didn't have all copper", &assertCount);
	}
	
	printf("\nnumber of asserts for smithy card test: %i\n\n", assertCount);
		
	return 0;
}