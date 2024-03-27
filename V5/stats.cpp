#include "stats.h"

StatsWidget::StatsWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    QLabel *label = new QLabel("Stats:", this);
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Refresh", this);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &StatsWidget::refreshStats);
}

void StatsWidget::refreshStats()
{
    // Implementer la logique pour rafraîchir les statistiques ici
    // Par exemple, vous pouvez récupérer les données du fichier et les afficher dans un QTextEdit
}

