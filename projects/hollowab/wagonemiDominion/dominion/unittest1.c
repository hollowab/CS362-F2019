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

int BaronTest(struct gameState *G, int p){
	int l;
	int currentPlayer = 1;
	for(l = -1; l < 3; l++){
		int dc1 = G->discardCount;
		int i = G->numBuys;
		play_baron(l, currentPlayer, &G);
		int j = G->numBuys ;
		int a = assert(i, j);
		if(a != 0)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");
	
		int dc2 = G->discardCount;
		int b = assert(dc1, dc2);
		if(b != 0)
			printf("Test Passed\n");
		else
			printf("Test Failed\n");
	}

	G->hand[0][0] == estate;
//	play_baron(l, currentPlayer, &G);
	G->hand[1][1] == estate;
//	play_baron(l, currentPlayer, &G);

	G->hand[0][0] == estate;
//	play_baron(0, currentPlayer, &G);
	G->hand[1][1] == estate;
//	play_baron(0, currentPlayer, &G);

	
	return 0;
}

int main(){

	printf("BEGIN TESTING BARON\n");
	
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
	BaronTest(&G, p);

	
	printf("END TESTING BARON\n");
	printf("\n");

return 0;
}
