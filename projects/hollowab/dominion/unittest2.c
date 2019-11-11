#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
//#include <assert.h>
#include "rngs.h"

int assert(int i, int j){
	if(i == j)
		return 0;
		
	return -1;
}

int minionTest(struct gameState *G){
    int c;
    int i = G->discardCount;
    minioncardEffect(0, 1, &G, 1);
    int j = G->discardCount;
    int k = assert(i, j);               //Assert that discardcount before and after the card is called are different
    if(k == 0){
        printf("Test Failed\n");
    }
    else{
        printf("Test Passed\n");
    }
    G->numPlayers = 4;
    for(c = 0; c < 5; c++){
        G->handCount[c] = 6;
        minioncardEffect(c, 0, &G, 1);
        minioncardEffect(1, c, &G, 1);
        minioncardEffect(1, 0, &G, c);
        minioncardEffect(c, 1, &G, 1);
        minioncardEffect(0, c, &G, 1);
        minioncardEffect(0, 1, &G, c);
    }
	
    G->handCount[0] = 8;
    minioncardEffect(1, 0, &G, 1);
    minioncardEffect(0, 1, &G, 1);
    minioncardEffect(1, 0, &G, 0);
    minioncardEffect(0, 1, &G, 0);

	return 0;
}

int main(){

	printf("BEGIN TESTING MINION\n");
	
	int k[10] = {adventurer, tribute, feast, gardens, mine, remodel, smithy, baron, 
			minion, ambassador};
	struct gameState G;
	memset(&G, 23, sizeof(&G));
	initializeGame(2, k, 1, &G);
	int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    int p = 1;
    G.deckCount[p] = 20;
    G.discardCount[p] = 0;
    G.handCount[p] = 5;
	minionTest(&G);

	
	printf("END TESTING MINION\n");
	printf("\n");

return 0;
}
