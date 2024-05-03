//
//  Route.cpp
//  CCPP_Sim
//
//  Created by Steve Frezza on 2/12/23.
//

#include "Space.hpp"
#include "Route.hpp"
#include "Player.hpp"

Route::Route() {
    startSpace = new Space("Start");
    startSpace->myRoute = this;
}

Route::Route(int length) {
    startSpace = new Space("Start");
    for (int index =0; index < (length - 1); index++) {
        Space *newSpace = new Space(std::string("Black"));
        newSpace->myRoute = this;
        path.push_back(newSpace);
    }
    startSpace->myRoute = this;
}
Space* Route::movePlayer(Player *player, int noSpaces) {
    return player->currentSpace;  // Do nothing.  Should not be called.
};

SpaceTuple Route::startPlayerMove(Player *player, int noSpaces) {
    SpaceTuple spaceTuple = getCurrentSpace(player);
    return spaceTuple;
}

SpaceTuple Route::getCurrentSpace(Player *player) {
    if (player->currentSpace == startSpace) {
        return SpaceTuple(startSpace, -1);
    }
    int index = 0;
    for (Space *s : path) {
        if (player->currentSpace == s) {
            return SpaceTuple(s, index);
        }
        index += 1;
    }
    throw new std::out_of_range("Player not found on route");
}
/* Original (buggy) code:
 SpaceTuple Route::getCurrentSpace(Player *player) {
     if (startSpace->currentPlayers.find(player) != startSpace->currentPlayers.end() ) {
         return SpaceTuple(startSpace, -1);
     }
     else {
         int index = 0;
         for (Space *s : path) {
             if (s->currentPlayers.find(player) != startSpace->currentPlayers.end() ) {
                 SpaceTuple tuple = SpaceTuple(s, index);
                 return tuple;
             }
             index += 1;
         }
     }
     return SpaceTuple(startSpace, -1); // This is a BAD error condition.  'Should be 'catch-throw'
 }

 */
