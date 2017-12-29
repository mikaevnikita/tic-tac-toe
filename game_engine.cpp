#include "game_engine.h"
#include <stdexcept>

using GameConstants::GameConstant;

GameConstant GameEngine::whoseTurn(){
    if(winner != GameConstant::CONTINUE)
        return GameConstant::EMPTY;
    return current_gamer;
}

GameEngine::GameEngine(const int& size, QObject* parent):QObject(parent)
{
    pArray=nullptr;
    startNewGame(size);
}

int GameEngine::getSize(){
    return _size;
}

void GameEngine::startNewGame(const int& size){
    current_gamer=GameConstant::CROSS;
    if(size<0)
        throw std::invalid_argument("invalid size");
    else{
        if(pArray!=nullptr){
            for(int i=0;i<_size;i++)
                delete[] pArray[i];
            delete[] pArray;
        }
        _size=size;
        winner=GameConstant::CONTINUE;
        count_free_cells=size*size;
        pArray=new GameConstant*[size];
        for(int i=0;i<size;i++){
            pArray[i]=new GameConstant[size];
            for(int j=0;j<size;j++)
                pArray[i][j]=GameConstant::EMPTY;
        }
    }
}

GameConstant GameEngine::whoWin(){
    return winner;
}

GameConstant GameEngine::checkWin(const int& row, const int& col, const GameConstant& value){
    /*Имеет смысл проверять только горизонталь, вертикаль содержащие поставленную клетку
     * и две диагонали
     * */
    if(value==GameConstant::CROSS or value==GameConstant::ZERO){
        int count=0;
        //Проверка по горизонтали
        for(int i=0;i<_size;i++){
            if(pArray[row][i]!=value){
                count=0;
                break;
            }
            else
                count++;
        }
        if(count==_size)
            return value;
        //Проверка по вертикали
        for(int i=0;i<_size;i++){
            if(pArray[i][col]!=value){
                count=0;
                break;
            }
            else
                count++;
        }
        if(count==_size)
            return value;

        //Проверка диагонали 1
        for(int i=0;i<_size;i++){
            if(pArray[i][i]!=value){
                count=0;
                break;
            }
            else
                count++;
        }
        if(count==_size)
            return value;

        //Проверка диагонали 2
        for(int i=0,j=0;i<_size;i++,j++){
            if(pArray[_size-i-1][j]!=value){
                count=0;
                break;
            }
            else
                count++;
        }
        if(count==_size)
            return value;
    }
    if(count_free_cells==0)
        return GameConstant::DRAW;//В конечном счете если ни одно из условий не выполнилось(нет победителя)
    else
        return GameConstant::CONTINUE;
}


GameConstant GameEngine::setPos(const int& row, const int& col, const GameConstant& value){
    if( !(value==GameConstant::CROSS or value==GameConstant::ZERO) or row<0 or row>=_size or col<0 or col>=_size)
        throw std::invalid_argument("invalid arguments");
    else{
        if(winner!=GameConstant::CONTINUE or pArray[row][col]!=GameConstant::EMPTY or whoseTurn() != value)
            return GameConstant::EMPTY;
        else{
            pArray[row][col]=value;
            current_gamer=(value == GameConstant::CROSS) ? GameConstant::ZERO : GameConstant::CROSS;
            count_free_cells--;
            GameConstant result=checkWin(row,col,value);
            winner = result;
            if(winner != GameConstant::CONTINUE)
                emit endOfGame(winner);
            return value;
        }
    }
}

GameConstant GameEngine::setPos(const Position& p, const GameConstant &value){
    return setPos(p.getRow(),p.getCol(),value);
}

GameConstant GameEngine::getPos(const int& row, const int& col){
    if(row<0 or row>=_size or col<0 or col>=_size)
        throw std::invalid_argument("invalid position");
    else
        return pArray[row][col];
}

GameEngine::GameEngine(GameEngine &engine){
    startNewGame(engine._size);
    winner=engine.winner;
    count_free_cells=engine.count_free_cells;
    for(int i=0;i<_size;i++){
        for(int j=0;j<_size;j++)
            pArray[i][j]=engine.pArray[i][j];
    }
}

GameEngine::~GameEngine(){
    for(int i=0;i<_size;i++)
        delete[] pArray[i];
    delete[] pArray;
}

int GameEngine::countOfFreeCells(){
    return count_free_cells;
}


GameConstant GameEngine::getPos(const Position& p){
    return getPos(p.getRow(),p.getCol());
}
