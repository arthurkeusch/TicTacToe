#include "game.h"

Game::Game(Player *player1, Player *player2, Player *player3, Player *player4, Board *board, GameState *state, QWidget *parent) : QWidget(parent)
{
    this->player1 = player1;
    this->player2 = player2;
    this->player3 = player3;
    this->player4 = player4;
    this->currentPlayer1 = player1;
    this->currentPlayer2 = player3;
    this->nextPlayer1 = player1;
    this->nextPlayer2 = player3;

    this->currentPlayer = currentPlayer1;

    this->board = board;
    this->state = state;
    logic = new GameLogic();
    nextMove = -1;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Game::nextRound);

}

void Game::changeNextPlayer1(QString s) {
    std::cout << "changePlayer1" << std::endl;
    if (s == "Human") {
        std::cout << "it's player1 now" << std::endl;
        this->nextPlayer1 = player1;
    }
    else if (s == "Computer") {
        std::cout << "it's player3 now" << std::endl;
        this->nextPlayer1 = player3;
    }
}

void Game::changeNextPlayer2(QString s) {
    std::cout << "changePlayer2" << std::endl;
    if (s == "Human") {
        this->nextPlayer2 = player2;
    }
    else if (s == "Computer") {
        this->nextPlayer2 = player4;
    }
}

void Game::changePlayers() {
    if (currentPlayer == currentPlayer1) {
        std::cout << "this worked" << std::endl;
        currentPlayer = currentPlayer2;
    }
    else if (currentPlayer == currentPlayer2) {
        currentPlayer = currentPlayer1;
    }
}

void Game::restart() {
    this->currentPlayer1 = this->nextPlayer1;
    this->currentPlayer2 = this->nextPlayer2;
    this->currentPlayer = this->currentPlayer1;
    state->initiate();
    board->clicked = -1;
    board->update();
    nextRound();
}

void Game::nextRound()
{
    delay(100);
    if (!(logic->gameOver(state) || logic->gameWon(state))) {
        if (currentPlayer->isHuman()) {
            board->setAllowed(true);
            board->getClicked(nextMove);
            if (nextMove != -1) {
                setNextMove(nextMove);
            }
            else {
                timer->start(100);
            }
        }
        else if (!currentPlayer->isHuman()) {
            currentPlayer->generateNextMove(nextMove, state);
            setNextMove(nextMove);
        }
    } else {
        timer->stop();
        if (logic->gameWon(state)) {
            QString message = "La partie est terminée. Le joueur " + QString::number(state->otherPlayer(state->getCurrentPlayer())) + " a gagné!";
            emit messageChanged(message);
        }
        else if (logic->gameOver(state)) {
            QString message = "La partie est terminée. Aucun coup n'est possible.";
            emit messageChanged(message);
        }
        std::vector<std::string> data = readFile("data.txt");
        if (logic->gameWon(state)) {
            if (state->otherPlayer(state->getCurrentPlayer()) == 1) {
                if (data[0] == "vide") {
                    writeFile("data.txt", 1, 1, 0, 0, 1, 0);
                } else {
                    int totalGame = std::stoi(data[0]);
                    int winGameP1 = std::stoi(data[1]);
                    int winGameP2 = std::stoi(data[2]);
                    int loseGameP1 = std::stoi(data[3]);
                    int loseGameP2 = std::stoi(data[4]);
                    int nullGame = std::stoi(data[5]);
                    totalGame += 1;
                    winGameP1 += 1;
                    loseGameP2 += 1;
                    writeFile("data.txt", totalGame, winGameP1, winGameP2, loseGameP1, loseGameP2, nullGame);
                }
            } else if (state->otherPlayer(state->getCurrentPlayer()) == 2) {
                if (data[0] == "vide") {
                    writeFile("data.txt", 1, 0, 1, 1, 0, 0);
                } else {
                    int totalGame = std::stoi(data[0]);
                    int winGameP1 = std::stoi(data[1]);
                    int winGameP2 = std::stoi(data[2]);
                    int loseGameP1 = std::stoi(data[3]);
                    int loseGameP2 = std::stoi(data[4]);
                    int nullGame = std::stoi(data[5]);
                    totalGame += 1;
                    winGameP2 += 1;
                    loseGameP1 += 1;
                    writeFile("data.txt", totalGame, winGameP1, winGameP2, loseGameP1, loseGameP2, nullGame);
                }
            }
            std::cout << "The game has ended, and Player " << state->otherPlayer(state->getCurrentPlayer()) << " has won!" << std::endl;
        } else {
            if (data[0] == "vide") {
                writeFile("data.txt", 1, 0, 0, 0, 0, 1);
            } else {
                int totalGame = std::stoi(data[0]);
                int winGameP1 = std::stoi(data[1]);
                int winGameP2 = std::stoi(data[2]);
                int loseGameP1 = std::stoi(data[3]);
                int loseGameP2 = std::stoi(data[4]);
                int nullGame = std::stoi(data[5]);
                totalGame += 1;
                nullGame += 1;
                writeFile("data.txt", totalGame, winGameP1, winGameP2, loseGameP1, loseGameP2, nullGame);
            }
            std::cout << "No more moves are possible." << std::endl;
        }
    }
}

void Game::setNextMove(int &move) {
    nextMove = move;
    int vmSize = logic->numOfValidMoves(state);
    int validMoves[vmSize];
    logic->generateValidMoves(state, validMoves); // is changed by the function.

    if (logic->validMove(nextMove, validMoves, vmSize, state)) {
        board->setAllowed(false);
        state->makeMove(nextMove);
        state->printBoard();
        board->update();
        changePlayers();
        nextRound();
    }
    else {
        //std::cout << "Invalid move" << std::endl;
    }
    nextMove = -1;
}


void Game::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;

void Game::writeFile(const std::string& fileName, int totalGame, int winGameP1, int winGameP2, int loseGameP1, int loseGameP2, int nullGame) {
    ofstream file(fileName.c_str());
    file << totalGame << endl;      // Nombre de partie totale
    file << winGameP1 << endl;      // Nombre de partie gagné par le joueur 1
    file << winGameP2 << endl;      // Nombre de partie gagné par le joueur 2
    file << loseGameP1 << endl;     // Nombre de partie perdu par le joueur 1
    file << loseGameP2 << endl;     // Nombre de partie perdu par le joueur 2
    file << nullGame << endl;       // Nombre de partie null
}

std::vector<std::string> Game::readFile(const std::string& fileName) {
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
    } else {
        lines.push_back("vide");
    }
    return lines;
}
