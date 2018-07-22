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
	int temp_cost = 0;

	int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village}; 

	initializeGame (number_players, deck, seed, &standard_game);
	
	printf("--------------------\n");
	printf("Test getCost()\n");
	printf("--------------------\n");

	printf("Cost of curse should be 0\n");
	temp_cost = getCost(curse);
	printf("Expected 0 | Actual: %d\n",temp_cost);
	assert(temp_cost == 0);

	printf("--------------------\n");

	printf("Cost of estate should be 2\n");
	temp_cost = getCost(estate);
	printf("Expected 2 | Actual: %d\n",temp_cost);
	assert(temp_cost == 2);

	printf("--------------------\n");

	printf("Cost of duchy should be 0\n");
	temp_cost = getCost(duchy);
	printf("Expected 5 | Actual: %d\n",temp_cost);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of province should be 8\n");
	temp_cost = getCost(province);
	printf("Expected 8 | Actual: %d\n",temp_cost);
	assert(temp_cost == 8);

	printf("--------------------\n");

	printf("Cost of copper should be 0\n");
	temp_cost = getCost(copper);
	printf("Expected 0 | Actual: %d\n",temp_cost);
	assert(temp_cost == 0);

	printf("--------------------\n");

	printf("Cost of silver should be 3\n");
	temp_cost = getCost(silver);
	printf("Expected 3 | Actual: %d\n",temp_cost);
	assert(temp_cost == 3);

	printf("--------------------\n");

	printf("Cost of gold should be 6\n");
	temp_cost = getCost(gold);
	printf("Expected 6 | Actual: %d\n",temp_cost);
	assert(temp_cost == 6);

	printf("--------------------\n");

	printf("Cost of adventurer should be 6\n");
	temp_cost = getCost(adventurer);
	printf("Expected 6 | Actual: %d\n",temp_cost);
	assert(temp_cost == 6);

	printf("--------------------\n");

	printf("Cost of council_room should be 5\n");
	temp_cost = getCost(council_room);
	printf("Expected 5 | Actual: %d\n",temp_cost);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of feast should be 4\n");
	temp_cost = getCost(feast);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of gardens should be 4\n");
	temp_cost = getCost(gardens);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of mine should be 5\n");
	temp_cost = getCost(mine);
	printf("Expected 5 | Actual: %d\n",mine);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of remodel should be 4\n");
	temp_cost = getCost(remodel);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of smithy should be 4\n");
	temp_cost = getCost(smithy);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of village should be 3\n");
	temp_cost = getCost(village);
	printf("Expected 3 | Actual: %d\n",temp_cost);
	assert(temp_cost == 3);

	printf("--------------------\n");

	printf("Cost of baron should be 4\n");
	temp_cost = getCost(baron);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of great_hall should be 3\n");
	temp_cost = getCost(great_hall);
	printf("Expected 3 | Actual: %d\n",temp_cost);
	assert(temp_cost == 3);

	printf("--------------------\n");

	printf("Cost of minion should be 3\n");
	temp_cost = getCost(minion);
	printf("Expected 5 | Actual: %d\n",temp_cost);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of steward should be 3\n");
	temp_cost = getCost(steward);
	printf("Expected 3 | Actual: %d\n",temp_cost);
	assert(temp_cost == 3);

	printf("--------------------\n");

	printf("Cost of tribute should be 5\n");
	temp_cost = getCost(tribute);
	printf("Expected 5 | Actual: %d\n",temp_cost);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of cutpurse should be 4\n");
	temp_cost = getCost(cutpurse);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of ambassador should be 3\n");
	temp_cost = getCost(ambassador);
	printf("Expected 3 | Actual: %d\n",temp_cost);
	assert(temp_cost == 3);

	printf("--------------------\n");

	printf("Cost of embargo should be 2\n");
	temp_cost = getCost(embargo);
	printf("Expected 2 | Actual: %d\n",temp_cost);
	assert(temp_cost == 2);

	printf("--------------------\n");

	printf("Cost of outpst should be 5\n");
	temp_cost = getCost(outpost);
	printf("Expected 5 | Actual: %d\n",temp_cost);
	assert(temp_cost == 5);

	printf("--------------------\n");

	printf("Cost of salvager should be 4\n");
	temp_cost = getCost(salvager);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of sea_hag should be 4\n");
	temp_cost = getCost(sea_hag);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Cost of treasure_map should be 4\n");
	temp_cost = getCost(treasure_map);
	printf("Expected 4 | Actual: %d\n",temp_cost);
	assert(temp_cost == 4);

	printf("--------------------\n");

	printf("Tests Completed\n");
	printf("Pass: 27 \n");
	printf("Fail: 0 \n");
}