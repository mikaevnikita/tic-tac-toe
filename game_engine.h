#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "gameconstants.h"
#include <QObject>
#include "position_class.h"
using GameConstants::GameConstant;

class GameEngine:public QObject
{
    Q_OBJECT
private:
    int _size;
    GameConstant** pArray;
    GameConstant winner;
    GameConstant checkWin(const int &row, const int &col, const GameConstant& value);
    int count_free_cells;
    GameConstant current_gamer;
public:
    GameEngine(const int& size=GameConstants::minSizeBoard, QObject* parent=0);
    GameEngine(GameEngine &engine);
    GameConstant whoWin();
    GameConstant getPos(const int& row, const int& col);
    GameConstant getPos(const Position& p);
    int getSize();
    int countOfFreeCells();
    GameConstant whoseTurn();
    ~GameEngine();
public slots:
    void startNewGame(const int& size);
    GameConstant setPos(const int& row, const int& col, const GameConstant& value);
    GameConstant setPos(const Position& p, const GameConstant &value);
signals:
    void endOfGame(const GameConstant&);
};

#endif
