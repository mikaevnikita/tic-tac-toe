#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H
#include <QPushButton>
#include "gameconstants.h"
#include "position_class.h"
using GameConstants::GameConstant;
class GameButton:public QPushButton{
    Q_OBJECT
private:
    bool setted;
    Position position;
public:
    GameButton(const Position& pos, QWidget* parent = 0);
    GameButton(const int& row, const int& col, QWidget* parent = 0);
    bool isSetted();
    const Position& getPos();
public slots:
    void set(const GameConstant& value);
    void off();
};
#endif // GAME_BUTTON_H
