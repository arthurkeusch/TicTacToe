#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}





#include <QApplication>
#include <QIcon>
#include <iostream>

#include "widget.h"
#include "board.h"
#include "board.h"
#include "agent.h"
#include "humanplayer.h"
#include "game.h"


void MainWindow::on_pushButton_4_clicked()
{
    Player *player1 = new HumanPlayer(1);
    Player *player2 = new HumanPlayer(2);
    Player *player3 = new Agent(1);
    Player *player4 = new Agent(2);

    GameState *state = new GameState(9, player1->getPlayerNumber());
    Board *board = new Board(state);
    Game *game = new Game(player1, player2, player3, player4, board, state);

    Widget *window;
    window = new Widget(board, game);

    game->nextRound();

    ui->stackedWidget->addWidget(window);
    ui->stackedWidget->setCurrentWidget(window);
}

