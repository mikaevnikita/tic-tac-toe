#include "game_widget.h"

GameWidget::GameWidget(const QString &window_title, QWidget *parent):QWidget(parent){
    setWindowTitle(window_title);
    main_layout = nullptr;
    grid_layout = nullptr;
    whoseTurnLabel = nullptr;
}


void GameWidget::slotCreateNewGameWidget(const int &boardSize){
    if(main_layout != nullptr){
        //Чистка GridLayout
        QLayoutItem *child;
        while ((child = grid_layout->takeAt(0)) != 0){
            GameButton* button = qobject_cast<GameButton*>(child->widget());
            button->deleteLater();
            delete button;
        }
        //Чистка верхнего слоя
        QLayoutItem* item;
        while(item = main_layout->takeAt(0)){
            if(item->widget())
                item->widget()->deleteLater();
            else
                item->layout()->deleteLater();
            delete item;
        }

        delete main_layout;
    }

    main_layout = new QVBoxLayout(this);
    grid_layout = new QGridLayout;
    whoseTurnLabel = new QLabel;

    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            GameButton* button = new GameButton(i,j);
            QObject::connect(button,SIGNAL(clicked(bool)),this,SLOT(slotOnGameButtonClicked()));
            grid_layout->addWidget(button,i,j);
        }
    }
    main_layout->addWidget(whoseTurnLabel);
    main_layout->addLayout(grid_layout);
    setLayout(main_layout);
}

void GameWidget::slotOnGameButtonClicked(){
    GameButton* button = qobject_cast<GameButton*>(sender());
    emit signalOnGameButtonClicked(button->getPos());
}

void GameWidget::slotSet(const Position &pos, const GameConstant &value){
    if(value == GameConstant::CROSS or value == GameConstant::ZERO){
        QLayoutItem* item = grid_layout->itemAtPosition(pos.getRow(),pos.getCol());
        GameButton* button = qobject_cast<GameButton*>(item->widget());
        button->set(value);
        QString text;
        if(value == GameConstant::CROSS)
            text = GameConstants::turnZeroLabelText;
        if(value == GameConstant::ZERO)
            text = GameConstants::turnCrossLabelText;
        whoseTurnLabel->setText(text);
    }
}
