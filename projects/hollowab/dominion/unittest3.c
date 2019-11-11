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

int testAmbassador(struct gameState *G){
    //Catches the error that choice 1 and choice 2 are switched in function header amassadorcardEffect
    G->numPlayers = 10;
   int r = ambassadorcardEffect(-1, 1, &G, 0);
   int c = assert(r, -1);
   if(c == 0){
       printf("Test Failed\n"); 
   } 
   else{
       printf("Test Passed\n");
   }
   //Catches line 904 for coverage
    int s = ambassadorcardEffect(1, 1, &G, 1);
    int x = assert(r, -1);
    if(x == 0){
       printf("Test Failed\n"); 
    } 
    else{
       printf("Test Passed\n");
    }

    G->hand[1][1] = 0;
    G->handCount[1] = 5;
    ambassadorcardEffect(1, 4, &G, 6);
    G->handCount[0] = 5;
    ambassadorcardEffect(6, 1, &G, 0);
    ambassadorcardEffect(1, 1, &G, 5);
    G->hand[0][1] = 0;
    ambassadorcardEffect(1, 1, &G, 2);



    return 0;
}

int main(){
    int p = 1;
    int k[10] = {adventurer, tribute, feast, gardens, mine, remodel, smithy, baron, 
			minion, ambassador};

    printf("BEGIN TESTING AMBASSADOR\n");
    struct gameState G;
    initializeGame(3, k, 1000, &G);
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    G.supplyCount[p] = 1;


    testAmbassador(&G);

    printf("END TESTING AMBASSADOR\n");
    printf("\n");

return 0;
}

