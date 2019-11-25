#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

int assert(int a, int b){
	if(a == b){
		return 0;
	}
	return -1;
}

int RandomBaron(){
	struct gameState G;
	int k[10] = {baron, minion, tribute, feast, village, mine, remodel, great_hall, gardens, smithy};
	int pass = 0;
	int fail = 0;
	int error1 = 0;
	int error2 = 0;
	int test = 0;
	memset(&G, 1, sizeof(struct gameState));
	initializeGame(3, k, 1000, &G);
	int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    
	int i, l;
	for(i = 0; i < 1000; i++){
		int currentPlayer = rand() %2;
		int p = rand() %5;
		int q = rand() %5;
		G.handCount[p] = rand() %15;
		G.deckCount[p] = rand() %15;
		G.discardCount[p] = rand() %1;
		G.whoseTurn = rand() %2;
		
//		printf("Test #: %d\n", i);
		int j = rand() % 2;
//		printf("Choice 1: %d\n", j);
		int b = G.numBuys;
		int n = G.coins;
		play_baron(j, currentPlayer, &G);
		int m = G.coins;
		int c = G.numBuys;
		if(assert(c, b) == -1){
			pass++;
			test++;
		}
		else{
			fail++;
			error1++;
			test++;
		}
			if(assert(n, m) != 0){
				test++;
				pass++;
			}
			else{
				test++;
				fail++;
				error2++;
			}
		
	}
	printf("TESTS PASSED: %d | TESTS FAILED: %d\n", pass, fail);
	printf("Status: Passed | Correct numBuys X%d\n", (test/2-error1));
	printf("Status: Failed | incorrect numBuys X%d\n", error1);
	printf("Status: Passed | Correct Coins X%d\n", error2 );
	printf("Status: Failed | incorrect Coins X%d\n", (test/2 - error2));
	return 0;
}

int main(){
	
	srand(time(NULL));

	printf("********BEGIN RANDOM TESTING OF BARON CARD********\n");

	RandomBaron();

	printf("********END RANDOM TESTING OF BARON CARD********\n");
	printf("\n\n\n");
	return 0;
}

