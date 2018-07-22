#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int new_cards = 0;
	int discarded_cards = 1;
	int extra_coins = 0;
	int shuffled_cards = 0;

	struct gameState standard_game;
	int seed = 888;

	int number_players = 2;
	int player = 0;
	int other_player = 1;
	int choice_1 = 0;
	int choice_2 = 0;
	int choice_3 = 0;
	int hand_pos = 0;
	int bonus = 0;

	int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village};  

	initializeGame (number_players, deck, seed, &standard_game);

	printf("--------------------\n");
	printf("Test buyCard()\n");
	printf("--------------------\n");

	printf("Testing numBuys is less than 1\n");
	standard_game.numBuys = -1;
	int return_val = buyCard(village, &standard_game);
	printf("Expected: -1 | Actual: %d\n", return_val);
	assert(return_val == -1);
	standard_game.numBuys = 1;

	printf("--------------------\n");

	printf("Test not enough coins\n");
	standard_game.coins = 0;
	return_val = buyCard(village, &standard_game);
	printf("Expected: -1 | Actual: %d\n", return_val);
	assert(return_val == -1);
	standard_game.coins = 10;
	standard_game.numBuys = 10;

	printf("--------------------\n");

	printf("Test not enough of a card available\n");
	standard_game.supplyCount[village] = 0;
	return_val = buyCard(village, &standard_game);
	printf("Expected: -1 | Actual: %d\n", return_val);
	assert(return_val == -1);
	standard_game.supplyCount[village] = 10;

	printf("--------------------\n");

	printf("Test for when the buy is successful");
	int beg_coins = standard_game.coins;
	standard_game.numBuys = 10;
	int beg_buys = standard_game.numBuys;
	buyCard(village, &standard_game);
	printf("Started with 10 coins; village cost 3 should be 7\n");
	printf("Expected coins: 7 | Actual: %d\n", standard_game.coins);
	assert(standard_game.coins == 7);
	printf("Started with 10 buys; village should use 1\n");
	printf("Expected buys: 9 | Actual: %d\n", standard_game.numBuys);
	assert(standard_game.numBuys == 9);

	printf("--------------------\n");

	printf("Tests Completed\n");
	printf("Pass: 5\n");
	printf("Fail: 0\n");
}