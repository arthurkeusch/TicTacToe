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
    void onValiderClicked();

private:
    QComboBox *comboBoxColor;
    QComboBox *comboBoxPlayer1Color;
    QComboBox *comboBoxPlayer2Color;
    void writeFile(const std::string& fileName, const std::string& boardColor, const std::string& P1Color, const std::string& P2Color);
};

#endif // SETTINGS_H
