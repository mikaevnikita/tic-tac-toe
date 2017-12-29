#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
#include "gameconstants.h"


class MenuWidget:public QWidget{
    Q_OBJECT
private:
    QSpinBox* sb;
    QLabel* lbl;
    QPushButton* startGameButton;
    QVBoxLayout* main_layout;
    QHBoxLayout* layout;
public:
    MenuWidget(const QString& window_name = "", QWidget* parent = 0);
signals:
    void startGameButtonClicked(const int&);
private slots:
    void slotStartGameButtonClickedHandler();
};


#endif // VIEW_H
