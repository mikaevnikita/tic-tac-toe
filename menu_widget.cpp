#include <menu_widget.h>
MenuWidget::MenuWidget(const QString &window_name, QWidget *parent):QWidget(parent){
    sb = new QSpinBox;
    sb->setMaximum(GameConstants::maxSizeBoard);
    sb->setMinimum(GameConstants::minSizeBoard);

    lbl = new QLabel("Размер поля:");
    startGameButton = new QPushButton("Начать");
    main_layout = new QVBoxLayout;
    layout = new QHBoxLayout;

    layout->addWidget(lbl);
    layout->addWidget(sb);

    main_layout->addLayout(layout);
    main_layout->addWidget(startGameButton);

    setLayout(main_layout);
    setWindowTitle(window_name);

    QObject::connect(startGameButton,SIGNAL(clicked(bool)),this,SLOT(slotStartGameButtonClickedHandler()));
}

void MenuWidget::slotStartGameButtonClickedHandler(){
    int board_size = sb->value();
    emit startGameButtonClicked(board_size);
}
