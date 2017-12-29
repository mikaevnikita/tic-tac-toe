#include "game_button.h"
#include "gameconstants.h"
using GameConstants::GameConstant;

void GameButton::set(const GameConstant &value){
    if(value == GameConstant::CROSS or value == GameConstant::ZERO){
        QPushButton::setText(value == GameConstant::CROSS ? GameConstants::crossSymbol : GameConstants::zeroSymbol);
        setEnabled(false);
        setted=true;
    }
    else
        throw std::invalid_argument("error");
}

void GameButton::off(){
    QPushButton::setText(GameConstants::emptySymbol);
    setEnabled(true);
    setted=false;
}


bool GameButton::isSetted(){
    return setted;
}

GameButton::GameButton(const Position& pos, QWidget *parent):QPushButton(parent){
    position=pos;
}

GameButton::GameButton(const int &row, const int &col, QWidget *parent):QPushButton(parent){
    position.setRow(row);
    position.setCol(col);
}


const Position& GameButton::getPos(){
    return position;
}
