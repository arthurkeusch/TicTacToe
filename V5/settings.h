#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget();

signals:

private slots:
    void applySettings();

private:
    QComboBox *comboBoxResolution;
    QPushButton *buttonApply;
};

#endif // SETTINGS_H
