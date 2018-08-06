#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int testAdventurer( int player, struct gameState * post) {
    struct gameState before;
    int numTreasureBefore = 0;
    int numTreasureAfter = 0;
    int handCountBefore = post->handCount[player];
    memcpy (&before, post, sizeof(struct gameState));

    cardEffect(adventurer,0,0,0,post,0,0);
    int cardDrawn = 0;
    int handCountAfter = post->handCount[player];
    for (int i = 0; i< handCountBefore; i++) {
        cardDrawn = before.hand[player][i];
        if (cardDrawn == copper) {
            numTreasureBefore += 1;
        }
        else if (cardDrawn == silver) {
            numTreasureBefore += 1;
        }
        else if (cardDrawn == gold) {
            numTreasureBefore += 1;
        }
    }
    for (int i = 0; i< handCountAfter; i++) {
        cardDrawn = post->hand[player][i];
        if (cardDrawn == copper) {
            numTreasureAfter += 1;
        }
        else if (cardDrawn == silver) {
            numTreasureAfter += 1;
        }
        else if (cardDrawn == gold) {
            numTreasureAfter += 1;
        }
    }
    assert( numTreasureAfter - numTreasureBefore >= 0);
    return 0;
}

int main() {
    int i, r,  deckCount, discardCount, handCount;
    int numberTests, player;

    int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village}; 

    printf("Random testing for Adventurer card.")
    struct gameState game;
    memset(&game,0, sizeof(struct gameState));

    PutSeed(888);
    SelectStream(2);

    for (numberTests=0; numberTests < 2000; numberTests++) {
        initializeGame(2, kingdomCards, numberTests, &game);
        player = floor(Random() * 2 ) ;
        int rand1 = (int) (floor(Random() * MAX_HAND));
        int rand2 = (int) (floor(Random() * MAX_DECK));
        int rand3 = (int) (floor(Random() * MAX_HAND));
        game.handCount[player] = rand1;
        game.deckCount[player] = rand2;
        game.discardCount[player] = rand3;
        game.whoseTurn =  player;
        int lower = estate;
        int higher = treasure_map;
        for (i=0; i< game.deckCount[player]; i++) {
            game.hand[player][i] = floor((Random() *26) + 1);
        }
        testAdventurer(player, &game);
    }
    printf("All Tests OK\n");
}