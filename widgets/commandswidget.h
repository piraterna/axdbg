#ifndef COMMANDSWIDGET_H
#define COMMANDSWIDGET_H

#include <QDialog>

namespace Ui {
class CommandsWidget;
}

class CommandsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CommandsWidget(QWidget *parent = nullptr);
    ~CommandsWidget();

private slots:
    void on_sendButton_clicked();

private:
    Ui::CommandsWidget *ui;
};

#endif // COMMANDSWIDGET_H
