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
	int return_val = 0;

	int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village};

	initializeGame (number_players, deck, seed, &standard_game);

	printf("--------------------\n");
	printf("Test playCard()\n");
	printf("--------------------\n");

	printf("if phase is not zero should be negative 1");
	standard_game.phase = 1;
	return_val = playCard(0, choice_1, choice_2, choice_3, &standard_game);
	printf("Expected -1 | Actual: %d\n", return_val);
	assert( return_val == -1);
	standard_game.phase = 0;

	printf("--------------------\n");

	printf("if actions are less than one should return -1\n");
	standard_game.numActions = -1;
	return_val = playCard(0, choice_1, choice_2, choice_3, &standard_game);
	printf("Expected -1 | Actual: %d\n", return_val);
	assert(return_val == -1);
	standard_game.numActions = 10;

	printf("--------------------\n");

	standard_game.whoseTurn = 0;
	printf(" if card is not an action should be -1\n");
	standard_game.hand[0][hand_pos] = gold;
	return_val = playCard(hand_pos, choice_1, choice_2, choice_3, &standard_game);
	printf("Expected: -1 | Actual: %d\n",return_val);
	assert(return_val == -1);

	printf("--------------------\n");

	hand_pos = 1;
	standard_game.hand[0][hand_pos] = smithy;
	int beg_actions = standard_game.numActions;
	playCard(hand_pos, choice_1, choice_2, choice_3, &standard_game);
	printf("Number of actions should be decreased by one for successful card\n");
	printf("Beginning: %d | After: %d\n", beg_actions, standard_game.numActions);
	assert(beg_actions == standard_game.numActions + 1);

	printf("--------------------\n");

	printf("Tests Completed\n");
	printf("Pass: 4\n");
	printf("Fail: 0\n");

}