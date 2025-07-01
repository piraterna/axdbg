#include "mainwindow.h"
#include "ui/ui_mainwindow.h"

#include "logswidget.h"
#include "commandswidget.h"
#include "preferencesdialog.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Aurix Debugger");

    DockManager = new ads::CDockManager(this);

    // create widget instances
    LogsWidget *logsWidget = new LogsWidget();
    CommandsWidget *cmdWidget = new CommandsWidget();

    // add widgets to dock manager
    ads::CDockWidget *dockLogsWidget = DockManager->createDockWidget(tr("Logs"));
    dockLogsWidget->setWidget(logsWidget);

    ads::CDockWidget *dockCmdWidget = DockManager->createDockWidget(tr("Commands"));
    dockCmdWidget->setWidget(cmdWidget);

    // set up file menu
    fileMenu = new QMenu();
    fileMenu->setTitle(tr("File"));

    // set up view menu
    viewMenu = new QMenu();
    viewMenu->setTitle(tr("View"));

    viewMenu->addAction(dockLogsWidget->toggleViewAction());
    viewMenu->addAction(dockCmdWidget->toggleViewAction());

    // set up tools menu
    toolsMenu = new QMenu();
    toolsMenu->setTitle(tr("Tools"));

    QAction *preferencesAction = new QAction(tr("Preferences"));
    preferencesAction->setShortcuts(QKeySequence::Preferences);
    preferencesAction->setStatusTip(tr("Open an existing file"));
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::openPreferences);
    toolsMenu->addAction(preferencesAction);

    // set up help menu
    helpMenu = new QMenu();
    helpMenu->setTitle(tr("Help"));

    // load all menus
    ui->menubar->addMenu(fileMenu);
    ui->menubar->addMenu(viewMenu);
    ui->menubar->addMenu(toolsMenu);
    ui->menubar->addMenu(helpMenu);

    // add widgets to dock area
    DockManager->addDockWidget(ads::LeftDockWidgetArea, dockLogsWidget);
    DockManager->addDockWidget(ads::RightDockWidgetArea, dockCmdWidget);
}

void MainWindow::openPreferences()
{
    PreferencesDialog *pref = new PreferencesDialog();
    pref->exec();
    delete pref;
}

MainWindow::~MainWindow()
{
    delete ui;
}
