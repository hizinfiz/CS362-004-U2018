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
	struct gameState players3;
	struct gameState players4;
	int seed = 888;

	int player = 0;
	int other_player = 1;
	int choice_1 = 0;
	int choice_2 = 0;
	int choice_3 = 0;
	int hand_pos = 0;
	int bonus = 0;

	int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village};    

	initializeGame (2, deck, seed, &standard_game);
	initializeGame (3, deck, seed, &players3);
	initializeGame (4, deck, seed, &players4);

	printf("--------------------\n");
	printf("Test initializeGame()\n");
	printf("--------------------\n");

	printf("2 PLAYER GAME\n");
	printf("Expected players: 2 | Actual: %d\n", standard_game.numPlayers);
	assert(standard_game.numPlayers == 2);
	printf("Expected curse cards: 10 | Actual: %d\n", standard_game.supplyCount[curse]);
	assert(standard_game.supplyCount[curse] == 10);
	printf("Expected estate cards: 8 | Actual: %d\n", standard_game.supplyCount[estate]);
	assert(standard_game.supplyCount[estate] == 8);
	printf("Expected duchy cards: 8 | Actual: %d\n", standard_game.supplyCount[duchy]);
	assert(standard_game.supplyCount[duchy] == 8);
	printf("Expected province cards: 8 | Actual: %d\n", standard_game.supplyCount[province]);
	assert(standard_game.supplyCount[province] == 8);

	printf("--------------------\n");
	
	printf("3 PLAYER GAME\n");
	printf("Expected players: 3 | Actual: %d\n", players3.numPlayers);
	assert(players3.numPlayers == 3);
	printf("Expected curse cards: 20 | Actual: %d\n", players3.supplyCount[curse]);
	assert(players3.supplyCount[curse] == 20);
	printf("Expected estate cards: 12 | Actual: %d\n", players3.supplyCount[estate]);
	assert(players3.supplyCount[estate] == 12);
	printf("Expected duchy cards: 12 | Actual: %d\n", players3.supplyCount[duchy]);
	assert(players3.supplyCount[duchy] == 12);
	printf("Expected province cards: 12 | Actual: %d\n", players3.supplyCount[province]);
	assert(players3.supplyCount[province] == 12);

	printf("--------------------\n");
	
	printf("4 PLAYER GAME\n");
	printf("Expected players: 4 | Actual: %d\n", players4.numPlayers);
	assert(players4.numPlayers == 4);
	printf("Expected curse cards: 30 | Actual: %d\n", players4.supplyCount[curse]);
	assert(players4.supplyCount[curse] == 30);
	printf("Expected estate cards: 12 | Actual: %d\n", players4.supplyCount[estate]);
	assert(players4.supplyCount[estate] == 12);
	printf("Expected duchy cards: 12 | Actual: %d\n", players4.supplyCount[duchy]);
	assert(players4.supplyCount[duchy] == 12);
	printf("Expected province cards: 12 | Actual: %d\n", players4.supplyCount[province]);
	assert(players4.supplyCount[province] == 12);

	printf("--------------------\n");
	
	printf("NUMBER OF RESOURCES\n");
	printf("Expected silver: 40 | Actual: %d\n" ,
		standard_game.supplyCount[silver] == 40);
	assert(standard_game.supplyCount[silver] == 40);
	printf("Expected gold: 30 | Actual: %d\n", 
		standard_game.supplyCount[gold] == 30);
	printf("Expected copper (2 players): 46 | Actual %d\n", 
		standard_game.supplyCount[copper] );
	assert(standard_game.supplyCount[copper] == 46);
	printf("Expected copper (3 players): 39 | Actual %d\n",
		players3.supplyCount[copper]);
	assert(players3.supplyCount[copper] == 39);
	printf("Expected copper (4 players): 32 | Actual %d\n", 
		players4.supplyCount[copper]);

	printf("--------------------\n");	

	printf("Tests Completed\n");
	printf("Pass: 18\n");
	printf("Fail: 0\n");
}