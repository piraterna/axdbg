#include "widgets/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("AxDbg");
    QApplication::setApplicationDisplayName("Aurix Debugger");
    QApplication::setApplicationVersion("0.1");
    QApplication::setOrganizationName("Jozef Nagy");
    QApplication::setOrganizationDomain("www.aurix.github.io");

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
    w.show();
    return a.exec();
}
