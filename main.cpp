#include <iostream>
#include "game.h"
#include <QApplication>
using namespace std;


int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    Game g;
    g.run();
    return app.exec();
}

