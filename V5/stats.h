#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class StatsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatsWidget(QWidget *parent = nullptr);

signals:

public slots:
    void refreshStats();

};

#endif // STATS_H
