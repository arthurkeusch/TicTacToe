#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QCursor>
#include <QLabel>
#include <QPainter>
#include "gamestate.h"
#include "gamelogic.h"
#include "player.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(GameState *state, QWidget *parent = 0);
    ~Board();

signals:

public slots:
    void setAllowed(bool);
    void getClicked(int&);

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    GameState *state;
    QLabel *statusLabel;
    int tileSize;
    std::vector<std::string> readFile(const std::string& file);
    QString plateauColor; // Couleur du plateau
    QString player1Color; // Couleur du joueur 1
    QString player2Color; // Couleur du joueur 2

public:
    bool allowed;
    int clicked;

};

#endif // BOARD_H
