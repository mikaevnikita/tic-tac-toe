#ifndef GAME_WIDGET_H
#define GAME_WIDGET_H
#include "game_button.h"
#include "gameconstants.h"
#include "position_class.h"
#include "QtWidgets"

class GameWidget:public QWidget{
    Q_OBJECT
private:
    QVBoxLayout* main_layout;
    QGridLayout* grid_layout;
    QLabel* whoseTurnLabel;
public:
    GameWidget(const QString& window_title = GameConstants::window_title, QWidget* parent = 0);
public slots:
    void slotCreateNewGameWidget(const int& boardSize);
    void slotSet(const Position& pos, const GameConstant& value);
private slots:
    void slotOnGameButtonClicked();
signals:
    void signalOnGameButtonClicked(const Position& pos);
};


#endif // GAME_WIDGET_H
