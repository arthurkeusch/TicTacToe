#include "settings.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    comboBoxResolution = new QComboBox(this);
    comboBoxResolution->addItem("640x480");
    comboBoxResolution->addItem("800x600");
    comboBoxResolution->addItem("1024x768");

    buttonApply = new QPushButton("Apply", this);

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
