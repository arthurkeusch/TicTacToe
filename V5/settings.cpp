#include "settings.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout();

    comboBoxResolution = new QComboBox(this);
    comboBoxResolution->addItem("640x480");
    comboBoxResolution->addItem("800x600");
    comboBoxResolution->addItem("1024x768");

    buttonApply = new QPushButton("Apply", this);
    QPushButton *quit = new QPushButton("Quit", this);

    hbox->addWidget(comboBoxResolution, 0);
    hbox->addWidget(buttonApply, 1);
    vbox->addLayout(hbox, 0);
    vbox->addWidget(quit, 2, Qt::AlignTop);

    setLayout(vbox);

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
