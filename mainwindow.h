#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#define SETTINGS_GROUP_VIEW "group_view"
#define SETTING_SHOW_TOOLBAR "show_toolbar"
#define SETTING_SHOW_STATUS_BAR "show_status_bar"


namespace Ui {
class MainWindow;
}
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots :
    void slotNew();
    void slotOpen();
    void slotSave();
    void slotAboutProgram();
    void showPreferencesDialog();
    void slotPreferencesAccepted ( );
private :
    QString mFileName;
    SettingsDialog * msettingsDialog;
private :
    void updateTitle();
    bool askForFileSaveAndclose();
    void readSettings ( );
    void writeSettings ( );
    void applySettings ( );
};

#endif // MAINWINDOW_H
