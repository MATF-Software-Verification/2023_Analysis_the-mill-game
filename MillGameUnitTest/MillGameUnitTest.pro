QT += testlib
QT += gui core widgets network

CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

TEMPLATE = app

SOURCES +=  tst_mill_game_test.cpp \
    ../02-the-mill-game/code/src/Board.cpp \
    ../02-the-mill-game/code/src/Field.cpp \
    ../02-the-mill-game/code/src/Game.cpp \
    ../02-the-mill-game/code/src/GameAi.cpp \
    ../02-the-mill-game/code/src/GameMap.cpp \
    ../02-the-mill-game/code/src/GameServer.cpp \
    ../02-the-mill-game/code/src/GraphicLine.cpp \
    ../02-the-mill-game/code/src/GraphicPiece.cpp \
    ../02-the-mill-game/code/src/Help.cpp \
    ../02-the-mill-game/code/src/LocalGameMenu.cpp \
    ../02-the-mill-game/code/src/MainMenu.cpp \
    ../02-the-mill-game/code/src/MultiplayerMenu.cpp \
    ../02-the-mill-game/code/src/MyGraphicsScene.cpp \
    ../02-the-mill-game/code/src/Piece.cpp \
    ../02-the-mill-game/code/src/Player.cpp \
    ../02-the-mill-game/code/src/TcpClient.cpp \
    ../02-the-mill-game/code/src/TcpServer.cpp

SUBDIRS += \
    ../02-the-mill-game/NineMensMorris.pro

HEADERS += \
    ../02-the-mill-game/code/include/Board.h \
    ../02-the-mill-game/code/include/Field.h \
    ../02-the-mill-game/code/include/Game.h \
    ../02-the-mill-game/code/include/GameAi.h \
    ../02-the-mill-game/code/include/GameMap.h \
    ../02-the-mill-game/code/include/GameServer.h \
    ../02-the-mill-game/code/include/GraphicLine.h \
    ../02-the-mill-game/code/include/GraphicPiece.h \
    ../02-the-mill-game/code/include/Help.h \
    ../02-the-mill-game/code/include/Lib.h \
    ../02-the-mill-game/code/include/LocalGameMenu.h \
    ../02-the-mill-game/code/include/MainMenu.h \
    ../02-the-mill-game/code/include/MultiplayerMenu.h \
    ../02-the-mill-game/code/include/MyGraphicsScene.h \
    ../02-the-mill-game/code/include/Piece.h \
    ../02-the-mill-game/code/include/Player.h \
    ../02-the-mill-game/code/include/TcpClient.h \
    ../02-the-mill-game/code/include/TcpServer.h

DISTFILES += \
    ../02-the-mill-game/code/src/.clang-format
