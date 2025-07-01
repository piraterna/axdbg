#include "mainwindow.h"
#include "ui/ui_mainwindow.h"

#include "logswidget.h"
#include "commandswidget.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DockManager = new ads::CDockManager(this);

    // set up file
    fileMenu = new QMenu();
    fileMenu->setTitle(tr("File"));

    // set up view menu
    viewMenu = new QMenu();
    viewMenu->setTitle(tr("View"));

    // set up help menu
    helpMenu = new QMenu();
    helpMenu->setTitle(tr("Help"));

    // create widget instances
    LogsWidget *logsWidget = new LogsWidget();
    CommandsWidget *cmdWidget = new CommandsWidget();

    // Create a dock widget with the title Label 1 and set the created label
    // as the dock widget content
    ads::CDockWidget *dockLogsWidget = DockManager->createDockWidget(tr("Logs"));
    dockLogsWidget->setWidget(logsWidget);

    ads::CDockWidget *dockCmdWidget = DockManager->createDockWidget(tr("Commands"));
    dockCmdWidget->setWidget(cmdWidget);

    // Add the toggleViewAction of the dock widget to the menu to give
    // the user the possibility to show the dock widget if it has been closed
    //ui->menubar->addAction(DockWidget->toggleViewAction());
    viewMenu->addAction(dockLogsWidget->toggleViewAction());
    viewMenu->addAction(dockCmdWidget->toggleViewAction());

    // add widgets to dock area
    DockManager->addDockWidget(ads::LeftDockWidgetArea, dockLogsWidget);
    DockManager->addDockWidget(ads::RightDockWidgetArea, dockCmdWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
