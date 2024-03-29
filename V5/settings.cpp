#include "settings.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;

#include <map>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *color = new QHBoxLayout();

    comboBoxColor = new QComboBox(this);
    std::map<QString, QString> colorMap;
    colorMap["White"] = "#FFFFFF";
    colorMap["Black"] = "#000000";
    colorMap["Red"] = "#FF0000";
    colorMap["Green"] = "#00FF00";
    colorMap["Blue"] = "#0000FF";
    for (const auto& pair : colorMap) {
        comboBoxColor->addItem(pair.first);
    }

    comboBoxPlayer1Color = new QComboBox(this);
    for (const auto& pair : colorMap) {
        comboBoxPlayer1Color->addItem(pair.first);
    }

    comboBoxPlayer2Color = new QComboBox(this);
    for (const auto& pair : colorMap) {
        comboBoxPlayer2Color->addItem(pair.first);
    }

    QPushButton *quit = new QPushButton("Quit", this);
    QPushButton *changeColor = new QPushButton("Apply change");

    color->addWidget(new QLabel("Board color:"));
    color->addWidget(comboBoxColor);
    color->addWidget(new QLabel("Player 1 color:"));
    color->addWidget(comboBoxPlayer1Color);
    color->addWidget(new QLabel("Player 2 color:"));
    color->addWidget(comboBoxPlayer2Color);
    color->addWidget(changeColor);

    vbox->addLayout(color);
    vbox->addWidget(quit, 2, Qt::AlignTop);

    setLayout(vbox);

    connect(changeColor, &QPushButton::clicked, this, &SettingsWidget::onValiderClicked);
    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);
}

SettingsWidget::~SettingsWidget()
{

}

void SettingsWidget::onValiderClicked()
{
    QString selectedPlateauColorName = comboBoxColor->currentText();
    QString selectedPlayer1ColorName = comboBoxPlayer1Color->currentText();
    QString selectedPlayer2ColorName = comboBoxPlayer2Color->currentText();

    std::map<QString, QString> colorMap;
    colorMap["White"] = "#FFFFFF";
    colorMap["Black"] = "#000000";
    colorMap["Red"] = "#FF0000";
    colorMap["Green"] = "#00FF00";
    colorMap["Blue"] = "#0000FF";

    QString selectedPlateauColorHex = colorMap[selectedPlateauColorName];
    QString selectedPlayer1ColorHex = colorMap[selectedPlayer1ColorName];
    QString selectedPlayer2ColorHex = colorMap[selectedPlayer2ColorName];

    writeFile("colors.txt", selectedPlateauColorHex.toStdString(), selectedPlayer1ColorHex.toStdString(), selectedPlayer2ColorHex.toStdString());
}


void SettingsWidget::writeFile(const std::string& fileName, const std::string& boardColor, const std::string& P1Color, const std::string& P2Color) {
    ofstream file(fileName.c_str());
    file << boardColor << endl;
    file << P1Color << endl;
    file << P2Color << endl;
}
