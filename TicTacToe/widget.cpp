#include "widget.h"
#include "board.h"
#include "gamestate.h"
#include "agent.h"
#include "humanplayer.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QStringList>

Widget::Widget(Board *board, Game *game, QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QVBoxLayout *vbox = new QVBoxLayout();
    QVBoxLayout *players = new QVBoxLayout();
    QHBoxLayout *buttons = new QHBoxLayout();

    statusLabel = new QLabel("Have Fun", this);

    messageBox = new QTextEdit(this);
    messageBox->setReadOnly(true);

    QPushButton *quit = new QPushButton("Quit", this);
    QPushButton *restart = new QPushButton("Restart", this);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(restart, &QPushButton::clicked, game, &Game::restart);

    QStringList *pselection;
    pselection = new QStringList();
    pselection->append("");
    pselection->append("Human");
    pselection->append("Computer");

    combo1 = new QComboBox();
    combo1->addItems(*pselection);
    combo2 = new QComboBox();
    combo2->addItems(*pselection);

    connect(combo1, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated), game, &Game::changeNextPlayer1);
    connect(combo2, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated), game, &Game::changeNextPlayer2);

    vbox->addWidget(board);
    vbox->addWidget(statusLabel, 1, Qt::AlignTop);

    buttons->addWidget(restart);
    buttons->addWidget(quit);

    vbox->addLayout(buttons);
    vbox->addWidget(messageBox);

    hbox->addLayout(vbox);

    players->addWidget(combo1, 0);
    players->addWidget(combo2, 1, Qt::AlignTop);
    hbox->addLayout(players);

    setLayout(hbox);

    connect(game, &Game::messageChanged, this, &Widget::updateMessageBox);
}

void Widget::updateMessageBox(const QString &message) {
    messageBox->append(message);
}

Widget::~Widget() {

}
