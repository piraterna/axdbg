#include "widgets/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QStyle>
#include <QStyleFactory>

// this looks dirty... it probably is.
// it works though
QTranslator *transl;
QApplication *app;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("AxDbg");
    QApplication::setApplicationDisplayName("Aurix Debugger");
    QApplication::setApplicationVersion("0.1");
    QApplication::setOrganizationName("Jozef Nagy");
    QApplication::setOrganizationDomain("www.aurix.github.io");
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;

    transl = &translator;
    app = &a;

    w.show();
    return a.exec();
}

void switchLanguage(QString lang)
{
    app->removeTranslator(transl);

    if (!transl->load(":/i18n/" + lang)) {
        // TODO: Display an error message?
        return;
    }

    app->installTranslator(transl);

    // TODO: I have to figure out how to trigger a full retranslation on the main window
    //       Maybe look at QEvent::LanguageChange?
}

QString getLanguage()
{
    return transl->language();
}
