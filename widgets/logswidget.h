#ifndef LOGSWIDGET_H
#define LOGSWIDGET_H

#include <QDialog>

namespace Ui {
class LogsWidget;
}

class LogsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LogsWidget(QWidget *parent = nullptr);
    ~LogsWidget();

private:
    Ui::LogsWidget *ui;
};

#endif // LOGSWIDGET_H
