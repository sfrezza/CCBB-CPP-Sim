#include "AutoSim.hpp"
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <rapidcheck.h>

class AutoSimTests : public ::testing::Test {
protected:
    std::vector<std::string> listOfPlayers;
    
    AutoSimTests() {
    }

    ~AutoSimTests() override {
    }

    void SetUp() override {
    }

    void TearDown() override {
    }

    std::vector<std::string> generateRandomListOfPLayers(int numberOfPlayers) {
        std::vector<std::string> allPlayers = { "Red", "Yellow", "Green", "Blue" };
        for (int i = 0; i < numberOfPlayers; i++) {
            const auto player = *rc::gen::elementOf(allPlayers);
            auto it = std::find(allPlayers.begin(), allPlayers.end(), player);
            allPlayers.erase(it);
            listOfPlayers.push_back(player);
        }
        return listOfPlayers;
    }

    std::vector<std::string> generateRandomListOfInvalidPLayers(int numberOfPlayers) {
        std::vector<std::string> listOfPlayers = generateRandomListOfPLayers(numberOfPlayers);
        const auto hasDuplicateColor = *rc::gen::arbitrary<bool>();
        if (hasDuplicateColor) {
            listOfPlayers.pop_back();
            const auto index = *rc::gen::inRange(0, (int)listOfPlayers.size());
            listOfPlayers.push_back(listOfPlayers[index]);
        }
        else {
            listOfPlayers.pop_back();
            listOfPlayers.push_back("Black");
        }
        return listOfPlayers;
    }

    int getIndexFromOrderedPlayerList(std::string playerColor) {
        auto playerColorIterator = std::find(listOfPlayers.begin(), listOfPlayers.end(), playerColor); // should be the player position;
        auto position = std::distance(listOfPlayers.begin(), playerColorIterator);
        
        if (position < listOfPlayers.size()) return position; //should succeed
        
        return -1;  // function failed... Very bad.
    }
};

RC_GTEST_FIXTURE_PROP(AutoSimTests, numberOfPlayersConstructor, ()) {
    const auto playerNumbers = *rc::gen::inRange(2, 4);
    AutoSim* mySim = new AutoSim(playerNumbers);
    RC_ASSERT(mySim->getPlayers().size() == playerNumbers);
    
    const auto p1 = *rc::gen::elementOf(mySim->getPlayers());
    const auto p2 = *rc::gen::elementOf(mySim->getPlayers());

    if (p1 != p2) {
        RC_ASSERT(p1->myColor != p2->myColor);
        RC_ASSERT(p1->myColor == "Red" || p1->myColor == "Green" || p1->myColor == "Blue" || p1->myColor == "Yellow");
        RC_ASSERT(p2->myColor == "Red" || p2->myColor == "Green" || p2->myColor == "Blue" || p2->myColor == "Yellow");
    }
    //Verify that the board was constructed correctly:
    EXPECT_EQ(mySim->getBoard()->route3->path.size(), 16);
    EXPECT_EQ(mySim->getBoard()->route2->path.size(), 18);
    EXPECT_EQ(mySim->getBoard()->route1->path.size(), 26);
    ASSERT_EQ(mySim->getBoard()->players.size(), playerNumbers);
}

RC_GTEST_FIXTURE_PROP(AutoSimTests, invalidNumberOfPlayersConstructor, ()) {
    const auto playerNumbers = *rc::gen::arbitrary<int>();
    if (playerNumbers >= 2 && playerNumbers <= 4) {
        return;
    }
   // RC_ASSERT_THROWS([](int playerNumbers) {AutoSim* mySim = new AutoSim(playerNumbers); }, InvalidPlayerCountException);
}

RC_GTEST_FIXTURE_PROP(AutoSimTests, listOfPlayersConstructor, ()) {
    const auto playerNumbers = *rc::gen::inRange(2, 4);
    std::vector<std::string> players = generateRandomListOfPLayers(playerNumbers);
    AutoSim* mySim = new AutoSim(players);
    RC_ASSERT(mySim->getPlayers().size() == playerNumbers);

    for (int i = 0; i < playerNumbers; i++) {
        RC_ASSERT(players[i] == mySim->getPlayers()[i]->myColor);
    }
    //Verify that the board was constructed correctly:
    EXPECT_EQ(mySim->getBoard()->route3->path.size(), 16);
    EXPECT_EQ(mySim->getBoard()->route2->path.size(), 18);
    EXPECT_EQ(mySim->getBoard()->route1->path.size(), 26);
    ASSERT_EQ(mySim->getBoard()->players.size(), playerNumbers);
}
/*
RC_GTEST_FIXTURE_PROP(AutoSimTests, invalidListOfPlayersConstructor, ()) {
    const auto playerNumbers = *rc::gen::inRange(2, 4);
    std::vector<std::string> players = generateRandomListOfInvalidPLayers(playerNumbers);
    
    RC_ASSERT_THROWS([](std::vector<std::string> players) {AutoSim* mySim = new AutoSim(players); }, InvalidPlayerListException);
    RC_ASSERT_THROWS([]() {AutoSim* mySim = new AutoSim({}); }, InvalidPlayerListException);

    players = generateRandomListOfPLayers(1);
    // RC_ASSERT_THROWS([](std::vector<std::string> players) {AutoSim* mySim = new AutoSim(players); }, InvalidPlayerListException);
}
*/

RC_GTEST_FIXTURE_PROP(AutoSimTests, takeTurns, ()) {
    const auto playerNumbers = *rc::gen::inRange(2, 4);
    std::vector<std::string> players = generateRandomListOfPLayers(playerNumbers);
    AutoSim* mySim = new AutoSim(players);
    const auto turnCount = *rc::gen::inRange(playerNumbers, 2 * playerNumbers);
    //RC_ASSERT(mySim->getPlayers()[0] == mySim->nextPlayer());                 // Access Violation

    for (int i = 0; i < turnCount; i++) {
        std::vector<Space*> previousSpaces;
        for (auto p : mySim->getPlayers()) {
            previousSpaces.push_back(p->currentSpace);
        }
        Player* previousPlayer = mySim->nextPlayer();
        TurnTuple turn = mySim->takeTurn();
        RC_ASSERT(turn.player == previousPlayer);   // Am moving the correct nextPlayer()

        //RC_ASSERT(turn.player == mySim->getPlayers()[i % playerNumbers]);       // Access Violation
        RC_ASSERT(turn.roll >= 1 && turn.roll <= 6); //Rolled die correctly
        for (int i = 0; i < playerNumbers; i++) {    //Players moved/not moved correctly
            Player* p = mySim->getPlayers()[i];
            Space* previousSpace = previousSpaces[i];
            if (p == turn.player) {
                RC_ASSERT(turn.player->currentSpace != previousSpace);
            }
            else {
                RC_ASSERT(turn.player->currentSpace == previousSpace);
            }
        }
        Player* nextUpPlayer = mySim->nextPlayer();
        RC_ASSERT(nextUpPlayer != previousPlayer);  // takeTurn() advanced the player to be something new; not the same as the <previousPlayer>
        int movedPlayerIndex = getIndexFromOrderedPlayerList(previousPlayer->myColor);
        int nextUpPlayerIndex = getIndexFromOrderedPlayerList(nextUpPlayer->myColor);
        //Need to verify that the <newNextPlayer> was the correct one from the order of the <players> list.
        RC_ASSERT ((nextUpPlayerIndex > movedPlayerIndex) ||
                   (nextUpPlayerIndex == 0));
    }
}
