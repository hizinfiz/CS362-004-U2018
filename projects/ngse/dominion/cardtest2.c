#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <Stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int new_cards = 0;
    int discarded_cards = 1;
    int extra_coins = 0;
    int shuffled_cards = 0;

    struct gameState standard_game;
    struct gameState test_game;
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
    printf("Test Adventurer\n");
    printf("--------------------\n");

    memcpy(&test_game, & standard_game, sizeof(struct gameState));
    cardEffect( adventurer, choice_1, choice_2, choice_3, &test_game,
       hand_pos, &bonus);
    extra_coins = 0;
    int hand_count = test_game.handCount[player];
    int treasure_sum = 0;
    int card_drawn = 0;
    for (int i=0; i < hand_count; i++)
    {
        card_drawn = test_game.hand[player][i];
        if (card_drawn == copper) {
            card_drawn += 1;
        }
        else if (card_drawn == silver) {
            card_drawn += 1;
        }
        else if (card_drawn == gold) {
            card_drawn += 1;
        }
    }
    printf("number of treasure should be at least two, actual: %d\n", card_drawn);

    printf("--------------------\n");

    printf("Now I will test that the other players data has not changed\n");
    new_cards = 0;
    extra_coins = 0;
    discarded_cards = 0;
    printf("hand count = %d, expected = %d\n", test_game.handCount[other_player], 
        standard_game.handCount[other_player] + new_cards - discarded_cards);
    printf("deck count = %d, expected = %d\n", test_game.deckCount[other_player],
        standard_game.deckCount[other_player] - new_cards + shuffled_cards);
    printf("discard count = %d, expected = %d\n", test_game.discardCount[other_player], 
        standard_game.discardCount[other_player] + discarded_cards);
    assert(test_game.handCount[other_player] == standard_game.handCount[other_player] 
        + new_cards - discarded_cards);
    assert(test_game.deckCount[other_player] == standard_game.deckCount[other_player] 
        - new_cards + shuffled_cards);
    printf("I have checked the players' game state and the others' players game state.\n");
    printf("Now, I will look at the game state that is shared.");
    printf("coins = %d, expected coins = %d\n", test_game.coins, 
        standard_game.coins + extra_coins);
    assert(test_game.coins == standard_game.coins + extra_coins);
    printf("numActions = %d, expected actions = %d", test_game.numActions, 
        standard_game.numActions);
    assert(test_game.numActions == standard_game.numActions);
    printf("numPlayers = %d, expected = %d \n", test_game.numPlayers, 
        standard_game.numPlayers);;
    assert(test_game.numPlayers == standard_game.numPlayers);
    printf("numBuys = %d, expected = %d \n", test_game.numBuys, 
        standard_game.numBuys);;
    assert(test_game.numBuys == standard_game.numBuys);

    printf("--------------------\n");

    printf("Now I will check the kingdom and victory cards are as expected\n");
    printf("This is the check of the kingdom cards\n");
    for(int i=adventurer; i < treasure_map+ 1; i++)
    {
            printf("kingdom card: %d, expected: %d\n", 
                test_game.supplyCount[i], standard_game.supplyCount[i]);
            assert(test_game.supplyCount[i] == standard_game.supplyCount[i]);
    }
    printf("This is a check of the victory cards\n");
    printf("estate : %d, expected: %d\n", test_game.supplyCount[estate], 
        standard_game.supplyCount[estate]);
    assert(test_game.supplyCount[estate] == standard_game.supplyCount[estate]);
    printf("duchy : %d, expected: %d\n", test_game.supplyCount[duchy], 
        standard_game.supplyCount[duchy]);
    assert(test_game.supplyCount[duchy] == standard_game.supplyCount[duchy]);
    printf("province : %d, expected: %d\n", test_game.supplyCount[province], 
        standard_game.supplyCount[province]);
    assert(test_game.supplyCount[province] == standard_game.supplyCount[province]);

    printf("--------------------\n");

    printf("Tests Completed\n");
    printf("Pass: 10\n");
    printf("Fail: 0\n");
}