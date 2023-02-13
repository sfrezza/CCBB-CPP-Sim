//
//  Route.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Route.hpp"
#include "Space.hpp"

SpaceTuple Route::getCurrentSpace(Player *player) {
    if (startSpace.currentPlayers.contains(player)) {
        return SpaceTuple(&startSpace, -1);
    }
    else {
        int index = 0;
        for (Space *s : path) {
            if (s->currentPlayers.contains(player)) {
                SpaceTuple tuple = SpaceTuple(s, index);
                return tuple;
            }
            index += 1;
        }
    }
    return SpaceTuple(&startSpace, -1) // This is a BAD error condition.  'Should be 'catch-throw'
}
 
/*
Space Route::movePlayer (Player player, int noSpaces) {
    return startSpace;   // This should never be called
}
*/

SpaceTuple Route::startPlayerMove(Player *player, int noSpaces) {
    SpaceTuple spaceTuple = getCurrentSpace(player);
    return spaceTuple;
}
