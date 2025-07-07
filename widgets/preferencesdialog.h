#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

    void on_themeCombo_currentIndexChanged(int index);

    void on_languageCombo_currentIndexChanged(int index);

private:
    Ui::PreferencesDialog *ui;
};

#endif // PREFERENCESDIALOG_H
