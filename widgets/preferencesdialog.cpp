#include "preferencesdialog.h"
#include "ui/ui_preferencesdialog.h"

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Preferences"));

    ui->tabWidget->setTabText(0, tr("General"));
    ui->tabWidget->setTabText(1, tr("Connection"));
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::on_cancelButton_clicked()
{
    this->hide();
}


void PreferencesDialog::on_okButton_clicked()
{
    // TODO: save settings
    this->hide();
}

