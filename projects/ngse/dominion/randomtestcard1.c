#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int testGreatHall( int player, struct gameState * post) {
    struct gameState before;
    int numTreasureBefore = 0;
    int numTreasureAfter = 0;
    int newCards = 1;
    int discardedCards = 0;
    int handCountBefore = post->handCount[player];
    memcpy (&before, post, sizeof(struct gameState));
    cardEffect(great_hall,0,0,0,post,0,0);
    int cardDrawn = 0;
    int handCountAfter = post->handCount[player];

    assert(post->handCount[player] == before.handCount[player]  );
    assert(post->coins == before.coins);
    assert(post->numBuys == before.numBuys);
    assert(post->numActions == before.numActions + 2);
    return 0;
}

int main() {
    int i, r,  deckCount, discardCount, handCount;
    int numberTests, player;

    int deck[10] = {adventurer, ambassador, baron, council_room, great_hall, mine, remodel, sea_hag, smithy, village}; 

    printf("Random testing for Great Hall card.")
    struct gameState game;
    memset(&game,0, sizeof(struct gameState));

    PutSeed(888);
    SelectStream(2);

    for (numberTests=0; numberTests < 2000; numberTests++) {
        initializeGame(2, kingdomCards, numberTests, &game);
        player = floor(Random() * 2 ) ;
        player = 0;
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
        testGreatHall(player, &game);
    }
    printf("All Tests OK\n");
}