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

int RandomMinion(){
	int pass = 0; 
	int fail = 0;
	int test = 0;
	int error1 = 0;
	int error2 = 0;
	int error3 = 0;
	struct gameState G;
	int k[10] = {baron, minion, tribute, feast, village, mine, remodel, great_hall, gardens, smithy};
	memset(&G, 1, sizeof(struct gameState));
	initializeGame(3, k, 2000, &G);
	int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
	int p = rand()%10;
    
	int i, l, ch1, ch2, hpos;
	for(i = 0; i < 1000; i++){
		int currentPlayer = rand() %2;
		hpos = rand() %5;
		ch1 = rand() %2;
		if(ch1 == 1)
			ch2 = 0;
		else
			ch2 = 1;
		G.handCount[currentPlayer] = rand() %MAX_HAND+1;
		G.deckCount[currentPlayer] = rand() %MAX_DECK+1;
		G.discardCount[currentPlayer] = 0;
		G.whoseTurn = rand() %2;
		int actionbefore = G.numActions;
		int coinsbefore = G.coins;
		int cardsbefore = G.handCount;
		minioncardEffect(ch1, ch2, &G, hpos);
		int coinsafter = G.coins;
		int actionafter = G.numActions;
		int cardsafter = G.handCount;
		if(assert(actionafter, actionbefore) != 0){
			pass++;
			test++;
		}
		else{
			fail++;
			error1++;
			test++;
		}
		if(ch1 == 1){
			if(assert(coinsafter, coinsbefore) != 0){
				pass++;
				test++;
			}
			else{
				test++;
				fail++;
				error2++;
			}
		}
		if(ch2 == 1){
			if(assert(cardsafter, cardsbefore) != 0){
				test++;
				pass++;
			}
			else{
				test++;
				fail++;
				error3++;
			}

		}
	}
		printf("TESTS PASSED: %d | TESTS FAILED: %d\n", pass, fail);
		printf("Status: Passed | Correct numActions X%d\n", (test-error1));
		printf("Status: Failed | incorrect numActions X%d\n", error1);
		printf("Status: Passed | Correct Coins X%d\n", (test - error2) );
		printf("Status: Failed | incorrect Coins X%d\n", error2 );
		printf("Status: Passed | Correct Cards X%d\n", (test - error3) );
		printf("Status: Failed | incorrect Cards X%d\n", error3);		

	return 0;
}

int main(){
	
	srand(time(NULL));

	printf("********BEGIN RANDOM TESTING OF Minion CARD********\n");

	RandomMinion();

	printf("********END RANDOM TESTING OF Minion CARD********\n");
	printf("\n\n\n");
		
	return 0;
}

