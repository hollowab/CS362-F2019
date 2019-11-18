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

int RandomTribute(){
	int pass = 0; 
	int fail = 0;
	int test = 0;
	int error1 = 0;
	int error2 = 0;
	int error3 = 0;
	int actionbefore, actionafter;
	struct gameState G;
	int k[10] = {baron, minion, tribute, feast, village, mine, remodel, great_hall, gardens, smithy};
	memset(&G, 1, sizeof(struct gameState));
	initializeGame(3, k, 2000, &G);
	int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
	int p = rand()%10;
	int i;
	for(i = 0; i < 10000; i++){
		G.whoseTurn = rand() %1;
		int currentPlayer = rand() %2;
		G.deckCount[currentPlayer] = rand() %2;
		G.discardCount[currentPlayer] = rand() %2;
		int cp = G.whoseTurn;
		actionbefore = G.numActions;
		tributecardEffect(&G);
		int np = (G.whoseTurn + 1);
		actionafter = G.numActions;
		if(assert(cp, np) == 0){
			pass++;
			test++;
		}
		else{
			test++;
			fail++;
			error1++;
		}
		if(assert(actionafter, actionbefore) == 0){
			fail++;
			error2++;
			test++;
		}
		else{
			pass++;
			test++;
		}

	}
		printf("TESTS PASSED: %d | TESTS FAILED: %d\n", pass, fail);
		printf("Status: Passed | Correct NextPlayer X%d\n", (10000 - error1));
		printf("Status: Failed | incorrect NextPlayer X%d\n", error1);
		printf("Status: Passed | Correct Actions X%d\n", (10000 - error2) );
		printf("Status: Failed | incorrect Actions X%d\n", error2 );
	return 0;
}
int main(){

	printf("********BEGIN RANDOM TESTING OF TRIBUTE CARD********\n");

	RandomTribute();

	printf("********END RANDOM TESTING OF TRIBUTE CARD********\n");
	printf("\n\n\n");

	return 0;
}
