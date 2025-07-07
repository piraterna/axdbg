#include "preferencesdialog.h"
#include "ui/ui_preferencesdialog.h"

#include <QStyle>
#include <QStyleFactory>

bool updateStyle = false;
bool updateLanguage = false;
int curLanguage;

// I'm not going to create a header file just for one function
extern void switchLanguage(QString lang);
extern QString getLanguage();

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Preferences"));

    ui->tabWidget->setTabText(0, tr("General"));
    ui->tabWidget->setTabText(1, tr("Connection"));

    // Qt for some reason doesn't store available translations.
    // NOTE: When a new language gets added, update this list.
    //       Also see another note below.
    ui->languageCombo->addItem("Čeština (cs)");
    ui->languageCombo->addItem("English (en)");
    if (QString::compare(getLanguage(), "cs_CZ") == 0) {
        curLanguage = 0;
    } else if (QString::compare(getLanguage(), "en_US") == 0) {
        curLanguage = 1;
    } else {
        throw std::invalid_argument("Unknown language was set!");
    }
    ui->languageCombo->setCurrentIndex(curLanguage);

    // themes
    QStringList styles = QStyleFactory::keys();
    QString currentStyle = QApplication::style()->name();
    int styleIndex = 0;
    for (auto s : styles) {
        ui->themeCombo->addItem(s);
        if (QString::compare(currentStyle, s, Qt::CaseInsensitive) == 0) {
            ui->themeCombo->setCurrentIndex(styleIndex);
        }
        styleIndex++;
    }
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::on_cancelButton_clicked()
{
    updateStyle = false;
    updateLanguage = false;
    this->hide();
}


void PreferencesDialog::on_okButton_clicked()
{
    // TODO: save settings

    if (updateStyle) {
        QApplication::setStyle(QStyleFactory::create(ui->themeCombo->currentText()));
    }

    if (updateLanguage) {
        curLanguage = ui->languageCombo->currentIndex();

        // NOTE: See note above.
        switch (curLanguage) {
        case 0: // Czech (cs_CZ)
            switchLanguage("cs_CZ");
            break;
        case 1: // English (en_US)
            switchLanguage("en_US");
            break;
        default: // ????
            throw std::invalid_argument("Tried to switch to an invalid language");
            break;
        }

        ui->retranslateUi(this);
    }

    updateStyle = false;
    updateLanguage = false;
    this->hide();
}


void PreferencesDialog::on_themeCombo_currentIndexChanged(int index)
{
    updateStyle = true;
}


void PreferencesDialog::on_languageCombo_currentIndexChanged(int index)
{
    updateLanguage = true;
}

