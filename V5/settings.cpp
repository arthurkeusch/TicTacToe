#include "settings.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();

    QHBoxLayout *resol = new QHBoxLayout();

    QHBoxLayout *color = new QHBoxLayout();


    comboBoxResolution = new QComboBox(this);

    comboBoxResolution->addItem("640x480");

    comboBoxResolution->addItem("800x600");

    comboBoxResolution->addItem("1024x768");


    comboBoxColor = new QComboBox(this);

    comboBoxColor->addItem("#FFC0CB");

    comboBoxColor->addItem("#ADD8E6");


    buttonApply = new QPushButton("Apply", this);

    QPushButton *quit = new QPushButton("Quit", this);

    QPushButton *changeColor = new QPushButton("ChangeColor");


    resol->addWidget(comboBoxResolution, 0);

    resol->addWidget(buttonApply, 1);

    color->addWidget(comboBoxColor, 0);

    color->addWidget(changeColor, 1);

    vbox->addLayout(resol, 0);

    vbox->addLayout(color, 0);

    vbox->addWidget(quit, 2, Qt::AlignTop);


    setLayout(vbox);


    //connect(comboBoxColor, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsWidget::onPlateauColorChanged);

    connect(changeColor, &QPushButton::clicked, this, &SettingsWidget::onValiderClicked);

    connect(quit, &QPushButton::clicked, qApp, &QApplication::quit);

    connect(buttonApply, &QPushButton::clicked, this, &SettingsWidget::applySettings);
}

SettingsWidget::~SettingsWidget()
{
    delete comboBoxResolution;
    delete buttonApply;
}

void SettingsWidget::applySettings()
{
    // Appliquer les paramètres sélectionnés
}

void SettingsWidget::onValiderClicked()
{
    // Appliquer les paramètres sélectionnés
}
