#include "commandswidget.h"
#include "ui/ui_commandswidget.h"

CommandsWidget::CommandsWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CommandsWidget)
{
    ui->setupUi(this);
}

CommandsWidget::~CommandsWidget()
{
    delete ui;
}

void CommandsWidget::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}

void CommandsWidget::on_sendButton_clicked()
{
    std::string cmd = ui->commandLine->text().toStdString();
    (void)cmd;
}
