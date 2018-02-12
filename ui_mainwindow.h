/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Redo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_SelectAll;
    QAction *action_About_program;
    QAction *actionAbout_Qt;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(587, 336);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/actions/new"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/actions/open"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/actions/save"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QStringLiteral("action_Undo"));
        action_Undo->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/actions/undo"), QSize(), QIcon::Normal, QIcon::Off);
        action_Undo->setIcon(icon3);
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QStringLiteral("action_Redo"));
        action_Redo->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/actions/redo"), QSize(), QIcon::Normal, QIcon::Off);
        action_Redo->setIcon(icon4);
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        action_Cut->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/actions/cut"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon5);
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Copy->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/actions/copy"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon6);
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/actions/paste"), QSize(), QIcon::Normal, QIcon::Off);
        action_Paste->setIcon(icon7);
        action_SelectAll = new QAction(MainWindow);
        action_SelectAll->setObjectName(QStringLiteral("action_SelectAll"));
        action_About_program = new QAction(MainWindow);
        action_About_program->setObjectName(QStringLiteral("action_About_program"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/actions/preferences"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 21));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menu_file->addAction(action_New);
        menu_file->addAction(action_Open);
        menu_file->addAction(action_Save);
        menu_file->addSeparator();
        menu_file->addAction(actionPreferences);
        menu_file->addAction(action_Exit);
        menuEdit->addAction(action_Undo);
        menuEdit->addAction(action_Redo);
        menuEdit->addSeparator();
        menuEdit->addAction(action_Cut);
        menuEdit->addAction(action_Copy);
        menuEdit->addAction(action_Paste);
        menuEdit->addSeparator();
        menuEdit->addAction(action_SelectAll);
        menuAbout->addAction(action_About_program);
        menuAbout->addAction(actionAbout_Qt);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Undo);
        mainToolBar->addAction(action_Redo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_Paste);

        retranslateUi(MainWindow);
        QObject::connect(action_Exit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(plainTextEdit, SIGNAL(copyAvailable(bool)), action_Copy, SLOT(setEnabled(bool)));
        QObject::connect(plainTextEdit, SIGNAL(copyAvailable(bool)), action_Cut, SLOT(setEnabled(bool)));
        QObject::connect(plainTextEdit, SIGNAL(undoAvailable(bool)), action_Undo, SLOT(setEnabled(bool)));
        QObject::connect(plainTextEdit, SIGNAL(redoAvailable(bool)), action_Redo, SLOT(setEnabled(bool)));
        QObject::connect(plainTextEdit, SIGNAL(modificationChanged(bool)), MainWindow, SLOT(setWindowModified(bool)));
        QObject::connect(action_Paste, SIGNAL(triggered()), plainTextEdit, SLOT(paste()));
        QObject::connect(action_Undo, SIGNAL(triggered()), plainTextEdit, SLOT(undo()));
        QObject::connect(action_SelectAll, SIGNAL(triggered()), plainTextEdit, SLOT(selectAll()));
        QObject::connect(action_Redo, SIGNAL(triggered()), plainTextEdit, SLOT(redo()));
        QObject::connect(action_Cut, SIGNAL(triggered()), plainTextEdit, SLOT(cut()));
        QObject::connect(action_Copy, SIGNAL(triggered()), plainTextEdit, SLOT(copy()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New->setText(QApplication::translate("MainWindow", "&New", nullptr));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", nullptr));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        action_Undo->setText(QApplication::translate("MainWindow", "&Undo", nullptr));
        action_Redo->setText(QApplication::translate("MainWindow", "&Redo", nullptr));
        action_Cut->setText(QApplication::translate("MainWindow", "Cu&t", nullptr));
        action_Copy->setText(QApplication::translate("MainWindow", "&Copy", nullptr));
        action_Paste->setText(QApplication::translate("MainWindow", "&Paste", nullptr));
        action_SelectAll->setText(QApplication::translate("MainWindow", "Select &all", nullptr));
        action_About_program->setText(QApplication::translate("MainWindow", "&About program", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About &Qt", nullptr));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        menu_file->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
