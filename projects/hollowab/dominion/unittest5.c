#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"


int assert(int i, int j){
	if(i == j){
		return 0;
    }
    else{	
	    return -1;
    }
}

int testMine(struct gameState *G){
    G->hand[0][1] = 5;
    G->hand[1][1] = 5;
    G->hand[1][0] = 5;
    G->hand[0][0] = 5;
    minecardEffect(1, 1, &G, 1);
    G->hand[0][1] = 5;
    int j = whoseTurn(&G);
    minecardEffect(1, -1, &G, 0);
    int k = -1;
    int i = minecardEffect(1, 2, &G, 0);
    int p = assert(k, i);
    if(p == 0){
        printf("Test Failed\n");
    }
    else{
        printf("Test Passed\n");      
    }
    

}

int main(){

printf("BEGIN TESTING MINE\n");

    int p;
    int k[10] = {adventurer, tribute, feast, gardens, mine, remodel, smithy, baron, 
			minion, ambassador};

    struct gameState G;
    initializeGame(3, k, 1000, &G);
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    p = 0;
    G.deckCount[p] = 20;
    G.discardCount[p] = 0;
    G.handCount[p] = 5;

    testMine(&G);


printf("END TESTING MINE");
printf("\n");

return 0;
}

