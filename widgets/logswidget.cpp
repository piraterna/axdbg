#include "logswidget.h"
#include "ui/ui_logswidget.h"

LogsWidget::LogsWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogsWidget)
{
    ui->setupUi(this);
}

LogsWidget::~LogsWidget()
{
    delete ui;
}

void LogsWidget::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }

    QWidget::changeEvent(event);
}
