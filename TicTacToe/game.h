#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "gamelogic.h"
#include "board.h"
#include "board.h"
#include <QWidget>
#include <QApplication>
#include <QTimer>
#include <QTime>
#include <QTextEdit>

class Game : public QWidget
{
    Q_OBJECT

private:
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    Player *currentPlayer;
    Player *currentPlayer1;
    Player *currentPlayer2;
    Player *nextPlayer1;
    Player *nextPlayer2;
    Board *board;
    QTextEdit *messageBox;
    GameLogic *logic;
    GameState *state;
    void setNextMove(int&);
    void writeFile(const std::string& file,  int totalGame, int winGameP1, int winGameP2, int loseGameP1, int loseGameP2, int nullGame);
    std::vector<std::string> readFile(const std::string& file);

public:
    Game(Player*, Player*, Player*, Player*, Board*, GameState*, QWidget *parent = 0);
    QTimer *timer;
    Q_SIGNAL void messageChanged(const QString &message);
    int nextMove;
    void changePlayers();
    void delay(int);
    void setMessageBox(QTextEdit *messageBox) {
        this->messageBox = messageBox;
    }

public slots:
    void nextRound();
    void restart();
    void changeNextPlayer1(QString);
    void changeNextPlayer2(QString);
};

#endif // GAME_H
