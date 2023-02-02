#include <QtTest>

// add necessary includes here
#include <utility>
#include <map>
#include <../02-the-mill-game/code/include/Player.h>
#include <../02-the-mill-game/code/include/Field.h>
#include <../02-the-mill-game/code/include/GameMap.h>
#include <../02-the-mill-game/code/include/Game.h>

class mill_game_test : public QObject
{
    Q_OBJECT

public:
    mill_game_test();
    ~mill_game_test();

private slots:
    void testPlayerId();
    void testPlayerName();
    void testPlayerNumOfPieces();
    void testPlayerTurn();

    void testFieldOccupied();
    void testFieldPosition();
    void testFieldNeighbourIndices();
    void testFieldMills();

    void testGameMapInitializeFields();
    void testGameMapInitializePieces();
    void testGameMapInitializeMills();

    void testGameWinner();
    void testGameMessage();
};

mill_game_test::mill_game_test() {}

mill_game_test::~mill_game_test() {}

void mill_game_test::testPlayerId() {
    Player* player = new Player(FIELDSTATE::PLAYER_1, "The first player");

    QCOMPARE(player->id(), FIELDSTATE::PLAYER_1);

    delete player;
}

void mill_game_test::testPlayerName() {
    Player* player = new Player(FIELDSTATE::PLAYER_1, "The first player");

    QCOMPARE(player->getName(), "The first player");

    delete player;
}

void mill_game_test::testPlayerNumOfPieces() {
    Player* player = new Player(FIELDSTATE::PLAYER_1, "The first player");
    QCOMPARE(player->getNumOfPieces(), 0);

    player->incNumOfPieces();
    player->incNumOfPieces();
    QCOMPARE(player->getNumOfPieces(), 2);

    player->decNumOfPieces();
    player->decNumOfPieces();
    player->decNumOfPieces();
    player->decNumOfPieces();
    QCOMPARE(player->getNumOfPieces(), 0);

    delete player;
}

void mill_game_test::testPlayerTurn() {
    Player* player = new Player(FIELDSTATE::PLAYER_1, "The first player");
    QCOMPARE(player->turn(), false);

    player->setTurn(true);
    QCOMPARE(player->turn(), true);

    delete player;
}

void mill_game_test::testFieldOccupied() {
    Field* field = new Field(1);
    QCOMPARE(field->isOccupied(), false);

    field->occupy(FIELDSTATE::PLAYER_1);
    QCOMPARE(field->isOccupied(), true);

    field->deoccupy();
    QCOMPARE(field->isOccupied(), false);

    delete  field;
}

void mill_game_test::testFieldPosition() {
    Field* field = new Field(1);
    auto expectedPosition = 1;
    auto actualPosition = field->getFieldPosition();

    delete field;

    QCOMPARE(actualPosition, expectedPosition);
}

void mill_game_test::testFieldNeighbourIndices() {
    Field* field = new Field(1);
    auto expectedNeighbours = std::vector<unsigned>({2, 3, 4, 5, 6, 7, 8, 9, 10});

    field->addNeighboursIndices(2, 3);
    field->addNeighboursIndices(4, 5, 6);
    field->addNeighboursIndices(7, 8, 9, 10);

    auto actualNeighbours = field->getNeighboursIndices();

    delete field;

    QCOMPARE(actualNeighbours, expectedNeighbours);
}

void mill_game_test::testFieldMills() {
    Field* field = new Field(1);

    auto expected_mills = std::make_pair(
                std::make_pair<unsigned, unsigned>(0, 2),
                std::make_pair<unsigned, unsigned>(4, 7)
                );

    field->addMills(0, 2, 4, 7);
    auto actual_mills = field->getMills();

    delete field;

    QCOMPARE(actual_mills, expected_mills);
}

void mill_game_test::testGameMapInitializeFields() {
    GameMap* gameMap = new GameMap();

    auto boardFields = gameMap->getBoardFields();
    QCOMPARE(boardFields.size(), 24);

    std::map<unsigned int, std::vector<unsigned int>> expectedNeighbours;
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(0, {1,9}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(1, {0,2,4}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(2, {1,14}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(3, {4,10}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(4, {1,3,5,7}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(5, {4,13}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(6, {7,11}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(7, {4,6,8}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(8, {7,12}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(9, {0,10,21}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(10, {3,9,11,18}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(11, {6,10,15}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(12, {8,13,17}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(13, {5,12,14,20}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(14, {2,13,23}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(15, {11,16}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(16, {15,17,19}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(17, {12,16}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(18, {10,19}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(19, {16,18,20,22}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(20, {13,19}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(21, {9,22}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(22, {19,21,23}));
    expectedNeighbours.insert(std::pair<unsigned, std::vector<unsigned>>(23, {14,22}));

    for (auto field : boardFields) {
        auto position = field.getFieldPosition();
        auto actualNeighbours = field.getNeighboursIndices();
        auto expectedNeighboursList = expectedNeighbours.at(position);
        QCOMPARE(actualNeighbours, expectedNeighboursList);
    }

    delete gameMap;
}

void mill_game_test::testGameMapInitializePieces() {
    GameMap* gameMap = new GameMap();

    auto redPieces = gameMap->getRedPieces();
    auto bluePieces = gameMap->getBluePieces();

    QVERIFY(redPieces.size() == NUM_OF_PIECES);
    QVERIFY(bluePieces.size() == NUM_OF_PIECES);

    delete gameMap;
}

void mill_game_test::testGameMapInitializeMills() {
    GameMap* gameMap = new GameMap();

    auto fields = gameMap->getBoardFields();

    auto emptyMills = std::make_pair(
                    std::make_pair<unsigned, unsigned>(0, 0),
                    std::make_pair<unsigned, unsigned>(0, 0)
                );

    for (auto field : fields) {
        auto mills = field.getMills();
        QVERIFY(mills != emptyMills);
    }

    delete gameMap;
}

void mill_game_test::testGameWinner() {
    Player* player1 = new Player(FIELDSTATE::PLAYER_1, "The first player");
    Player* player2 = new Player(FIELDSTATE::PLAYER_2, "The second player");
    Game* game = new Game(player1, player2, GAMEMODE::LOCAL);

    auto currentWinner = game->getWinner();
    QCOMPARE(currentWinner, FIELDSTATE::EMPTY);

    game->setWinner(FIELDSTATE::PLAYER_1);
    currentWinner = game->getWinner();
    QCOMPARE(currentWinner, FIELDSTATE::PLAYER_1);
}

void mill_game_test::testGameMessage() {
    Player* player1 = new Player(FIELDSTATE::PLAYER_1, "The first player");
    Player* player2 = new Player(FIELDSTATE::PLAYER_2, "The second player");
    Game* game = new Game(player1, player2, GAMEMODE::LOCAL);

    auto expectedMessage = "Player 2 played on 12";
    game->setGameMessage(expectedMessage);
    auto actualMessage = game->getGameMessage();
    QCOMPARE(actualMessage, expectedMessage);

    game->clearGameMessage();
    QVERIFY(game->getGameMessage().isEmpty());

    expectedMessage = "You can't play on that field";
    game->setErrorMessage(expectedMessage);
    actualMessage = game->getErrorMessage();
    QCOMPARE(actualMessage, expectedMessage);

    game->clearErrorMessage();
    QVERIFY(game->getGameMessage().isEmpty());
}

QTEST_MAIN(mill_game_test)

#include "tst_mill_game_test.moc"
