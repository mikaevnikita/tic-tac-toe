#ifndef GAME_H
#define GAME_H

#include "gameconstants.h"
#include "game_button.h"
#include "game_engine.h"
#include "menu_widget.h"
#include "game_widget.h"
#include "position_class.h"
#include <QtWidgets>

class Game:public QObject{
    Q_OBJECT
private:
    GameEngine* game_engine;
    MenuWidget* menu_widget;
    GameWidget* game_widget;
    QMessageBox msgBox;
    QPushButton* exit_button;
    QPushButton* repeat_button;
public:
    Game(QObject* parent = 0);
    virtual ~Game();
    void run();
public slots:
    void slotOnGameEnd(const GameConstant& whoWin);
    void slotOnStartGameButtonClicked(const int& boardSize);
    void slotOnGameButtonClicked(const Position& pos);
};


#endif // GAME_H
