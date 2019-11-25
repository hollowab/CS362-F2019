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
    int currentPlayer = 1;
    int i = G->discardCount;
    play_minion(0, 1, 1, currentPlayer, &G);
    int j = G->discardCount;
    int k = assert(i, j);               //Assert that discardcount before and after the card is called are different
    if(k == 0){
        printf("Test Failed\n");
    }
    else{
        printf("Test Passed\n");
    }
    G->numPlayers = 4;
    int before = G->playedCardCount;
    int initial = G->handCount[currentPlayer] = 8;
    play_minion(0, 1, 1, currentPlayer, &G);
    int final = G->handCount[currentPlayer];
    int after = G->playedCardCount;
    int ast = assert(before, after);
    if(ast == 0){
       printf("Incorrect discard of minion card\n");
   }
    else{
        printf("Correct discard of minion\n");
    }
    final = final + 4;
    if(assert(initial, final) == 0){
        printf("Correct draw 4\n");
    }
    else{
        printf("incorrect draw 4\n");
    }




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
