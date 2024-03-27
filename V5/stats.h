#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <fstream>
#include <vector>

class StatsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatsWidget(QWidget *parent = nullptr);
    ~StatsWidget();

public slots:
    void refreshStats();
    void resetStats(const std::string& fileName);
    std::vector<std::string> readStats(const std::string& fileName);

private:
    std::vector<QLabel*> statLabels;
    QLabel *totalGamesLabel;
    QLabel *player1WinsLabel;
    QLabel *player2WinsLabel;
    QLabel *player1LossesLabel;
    QLabel *player2LossesLabel;
    QLabel *drawsLabel;
};

#endif // STATS_H
