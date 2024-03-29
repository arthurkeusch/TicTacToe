#include "board.h"

#include <cmath>
#include <QMouseEvent>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;

Board::Board(GameState *state, QWidget *parent) : QWidget(parent)
{
    tileSize = 100;

    setMaximumSize(3*tileSize, 3*tileSize);
    setMinimumSize(3*tileSize, 3*tileSize);
    setToolTip("Board");

    this->state = state;

    clicked = -1;
    allowed = false;

    std::vector<std::string> colors = readFile("colors.txt");
    if (colors.size() >= 3) {
        plateauColor = QString::fromStdString(colors[0]);
        player1Color = QString::fromStdString(colors[1]);
        player2Color = QString::fromStdString(colors[2]);
    } else {
        plateauColor = QString::fromStdString("#ffffff");
        player1Color = QString::fromStdString("#000000");
        player2Color = QString::fromStdString("#000000");
    }
}

Board::~Board() {

}

void Board::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush(QColor("#000000")), 4));

    int a = sqrt(state->getBoardSize());

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            switch(state->getBoard()[i*a+j]) {
                case 0:
                    painter.setBrush(QBrush(QColor(plateauColor)));
                    painter.drawRect(j*tileSize, i*tileSize, tileSize, tileSize);
                    break;
                case 1:
                    painter.setBrush(QBrush(QColor(plateauColor)));
                    painter.drawRect(j*tileSize, i*tileSize, tileSize, tileSize);
                    painter.setPen(QPen(QBrush(QColor(player1Color)), 4));
                    painter.drawLine(j*tileSize+10, i*tileSize+10, j*tileSize+tileSize-10, i*tileSize+tileSize-10);
                    painter.drawLine(j*tileSize+10, i*tileSize+tileSize-10, j*tileSize+tileSize-10, i*tileSize+10);
                    painter.setPen(QPen(QBrush(QColor("#000000")), 4));
                    break;
                case 2:
                    painter.setBrush(QBrush(QColor(plateauColor)));
                    painter.drawRect(j*tileSize, i*tileSize, tileSize, tileSize);
                    painter.setPen(QPen(QBrush(QColor(player2Color)), 4));
                    painter.drawEllipse(j*tileSize+10, i*tileSize+10, 80, 80);
                    painter.setPen(QPen(QBrush(QColor("#000000")), 4));
                    break;
            }
        }
    }
}

void Board::mousePressEvent(QMouseEvent *e) {
    std::cout << state->getCurrentPlayer() << std::endl;
    if (allowed){
        int x, y;
        x = e->pos().rx() / 100;
        y = e->pos().ry() / 100;
        clicked = y*3 + x;
    }
}

void Board::getClicked(int& val) {
    val = this->clicked;
}

void Board::setAllowed(bool value) {
    this->allowed = value;
}

std::vector<std::string> Board::readFile(const std::string& fileName) {
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
