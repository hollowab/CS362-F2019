#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
//#include <assert.h>
#include "rngs.h"

int assert(int i, int j){
	if(i == j){
		return 0;
    }
    else{	
	    return -1;
    }
}

int testTribute(struct gameState *G){
    int j = 0;
    int i = tributecardEffect(&G);
    int k = assert(i, j);
    if(k == 0){
        printf("Test Passed\n");
    }
    else{
        printf("Test Failed\n");
    }

    G->discardCount[0] = 0;
    int s = G->discardCount[0];
    tributecardEffect(&G);
    int t = G->discardCount[0];
    printf("after %d\n", t);
    int l = assert(s, t);
    if(l == 0){
        printf("Test Failed\n");
    }
    else{
        printf("Test Passed\n");
    }
    
    G->discardCount[0] = 4;
    int x = G->discardCount[0];
    tributecardEffect(&G);
    int y = G->discardCount[0];
    G->deckCount[1] = 0;
    tributecardEffect(&G);

    return 0;
}

int main(){
    int p;
    int k[10] = {adventurer, tribute, feast, gardens, mine, remodel, smithy, baron, 
			minion, ambassador};

    printf("BEGIN TESTING TRIBUTE\n");
    struct gameState G;
    initializeGame(3, k, 1000, &G);
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    p = 1;
    G.deckCount[p] = 20;
    G.discardCount[p] = 0;
    G.handCount[p] = 5;

    testTribute(&G);

    printf("END TESTING TRIBUTE\n");
    printf("\n");

return 0;
}

