#include "stats.h"

StatsWidget::StatsWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    std::vector<std::string> stats = readStats("data.txt");

    if (stats.empty() || stats[0] == "vide") {
        QLabel *noStatsLabel = new QLabel("Veuillez lancer une partie pour obtenir des statistiques", this);
        layout->addWidget(noStatsLabel);
    } else {
        QLabel *totalGamesLabel = new QLabel("Nombre de parties totales: " + QString::fromStdString(stats[0]), this);
        layout->addWidget(totalGamesLabel);

        QLabel *player1WinsLabel = new QLabel("Nombre de parties gagnées par le joueur 1: " + QString::fromStdString(stats[1]), this);
        layout->addWidget(player1WinsLabel);

        QLabel *player2WinsLabel = new QLabel("Nombre de parties gagnées par le joueur 2: " + QString::fromStdString(stats[2]), this);
        layout->addWidget(player2WinsLabel);

        QLabel *player1LossesLabel = new QLabel("Nombre de parties perdues par le joueur 1: " + QString::fromStdString(stats[3]), this);
        layout->addWidget(player1LossesLabel);

        QLabel *player2LossesLabel = new QLabel("Nombre de parties perdues par le joueur 2: " + QString::fromStdString(stats[4]), this);
        layout->addWidget(player2LossesLabel);

        QLabel *drawsLabel = new QLabel("Nombre de parties nulles: " + QString::fromStdString(stats[5]), this);
        layout->addWidget(drawsLabel);
    }

    QPushButton *button = new QPushButton("Reset Stats", this);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, [this]() {
        resetStats("data.txt");
        refreshStats();
    });
}

StatsWidget::~StatsWidget() {
    // Nettoyer les QLabel
    for (QLabel *label : statLabels) {
        delete label;
    }
}

void StatsWidget::refreshStats() {
    std::vector<std::string> stats = readStats("data.txt");

    if (stats.empty() || stats[0] == "vide") {
        QLabel *noStatsLabel = new QLabel("Veuillez lancer une partie pour obtenir des statistiques", this);
        layout()->addWidget(noStatsLabel);
    } else {
        totalGamesLabel = new QLabel("Nombre de parties totales: " + QString::fromStdString(stats[0]), this);
        layout()->addWidget(totalGamesLabel);

        player1WinsLabel = new QLabel("Nombre de parties gagnées par le joueur 1: " + QString::fromStdString(stats[1]), this);
        layout()->addWidget(player1WinsLabel);

        player2WinsLabel = new QLabel("Nombre de parties gagnées par le joueur 2: " + QString::fromStdString(stats[2]), this);
        layout()->addWidget(player2WinsLabel);

        player1LossesLabel = new QLabel("Nombre de parties perdues par le joueur 1: " + QString::fromStdString(stats[3]), this);
        layout()->addWidget(player1LossesLabel);

        player2LossesLabel = new QLabel("Nombre de parties perdues par le joueur 2: " + QString::fromStdString(stats[4]), this);
        layout()->addWidget(player2LossesLabel);

        drawsLabel = new QLabel("Nombre de parties nulles: " + QString::fromStdString(stats[5]), this);
        layout()->addWidget(drawsLabel);
    }
}


void StatsWidget::resetStats(const std::string& fileName) {
    std::ofstream file(fileName);
    file << "vide" << std::endl;

    // Supprimer les anciens labels du layout
    QLayoutItem *child;
    while ((child = layout()->takeAt(0)) != nullptr) {
        if (QWidget *widget = child->widget()) {
            delete widget;
        }
        delete child;
    }
}

std::vector<std::string> StatsWidget::readStats(const std::string& fileName) {
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
