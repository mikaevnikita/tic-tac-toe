#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H
#include <QString>
/*
 * CROSS - крестик
 * ZERO - нолик
 * EMPTY - пустая клетка
 * DRAW - ничья
 * CONTINUE - игра продолжается
 * */
namespace GameConstants{
    enum GameConstant{ZERO=0,CROSS=1,EMPTY=2,DRAW=3,CONTINUE=4};
    static int minSizeBoard=3;
    static int maxSizeBoard=5;
    static QString crossSymbol="X";
    static QString zeroSymbol="O";
    static QString emptySymbol="";
    static QString turnCrossLabelText="Ходит "+crossSymbol;
    static QString turnZeroLabelText="Ходит "+zeroSymbol;
    static QString winCrossText="Победил "+crossSymbol;
    static QString winZeroText="Победил "+zeroSymbol;
    static QString winDrawText="Ничья";
    static QString window_title="Tic-Tac-Toe";
    static QString exit_button_text="Выход";
    static QString repeat_button_text="Начать новую игру";
    static Qt::WindowFlags windows_styles=Qt::Window | Qt::WindowMinimizeButtonHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint ;
}
#endif // GAMECONSTANTS_H
