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

void CommandsWidget::on_sendButton_clicked()
{
    QString cmd = ui->commandLine->text();
    (void)cmd;
}
