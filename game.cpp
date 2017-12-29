#include "game.h"

Game::Game(QObject *parent):QObject(parent){
    game_engine = new GameEngine;
    menu_widget = new MenuWidget(GameConstants::window_title);
    game_widget = new GameWidget(GameConstants::window_title);

    menu_widget->setWindowFlags(GameConstants::windows_styles);
    game_widget->setWindowFlags(GameConstants::windows_styles);

    QObject::connect(game_engine,SIGNAL(endOfGame(const GameConstant&)),this,SLOT(slotOnGameEnd(const GameConstant&)));
    QObject::connect(menu_widget,SIGNAL(startGameButtonClicked(const int&)),this,SLOT(slotOnStartGameButtonClicked(const int&)));
    QObject::connect(game_widget,SIGNAL(signalOnGameButtonClicked(const Position&)),this,SLOT(slotOnGameButtonClicked(const Position&)));


    exit_button = msgBox.addButton(GameConstants::exit_button_text,QMessageBox::RejectRole);
    repeat_button = msgBox.addButton(GameConstants::repeat_button_text,QMessageBox::AcceptRole);
}

void Game::run(){
    menu_widget->show();
}

void Game::slotOnGameButtonClicked(const Position &pos){
    GameConstant result = game_engine->setPos(pos,game_engine->whoseTurn());
    game_widget->slotSet(pos,result);
}


void Game::slotOnGameEnd(const GameConstants::GameConstant &whoWin){
    QString text;
    if(whoWin == GameConstant::CROSS)
        text = GameConstants::winCrossText;
    if(whoWin == GameConstant::ZERO)
        text = GameConstants::winZeroText;
    if(whoWin == GameConstant::DRAW)
        text = GameConstants::winDrawText;
    msgBox.setText(text);
    game_widget->hide();
    msgBox.exec();
    if(msgBox.clickedButton() == repeat_button)
        menu_widget->show();
}

void Game::slotOnStartGameButtonClicked(const int &boardSize){
    menu_widget->hide();
    game_engine->startNewGame(boardSize);
    game_widget->slotCreateNewGameWidget(boardSize);
    game_widget->show();
}

Game::~Game(){
    game_engine->deleteLater();
    delete game_engine;
    menu_widget->deleteLater();
    delete menu_widget;
    game_widget->deleteLater();
    delete game_widget;
}
