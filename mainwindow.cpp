#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include "settingsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    msettingsDialog (new SettingsDialog ( this ) )
{
    ui->setupUi(this);

    //Задаём комбинации клавиш для действий
    ui->action_Undo->setShortcut ( QKeySequence::Undo );
    ui->action_Redo->setShortcut ( QKeySequence::Redo );
    ui->action_Cut->setShortcut ( QKeySequence::Cut );
    ui->action_Copy->setShortcut ( QKeySequence::Copy );
    ui->action_Paste->setShortcut ( QKeySequence::Paste );
    ui->action_SelectAll ->setShortcut ( QKeySequence::SelectAll );
    ui->action_New->setShortcut ( QKeySequence::New);
    ui->action_Open->setShortcut ( QKeySequence::Open );
    ui->action_Save->setShortcut ( QKeySequence::Save );
    ui->action_Exit->setShortcut ( QKeySequence::Quit );

    /*
    ui->action_New->setIcon(QIcon(":/actions/new"));
    ui->action_Redo->setIcon(QIcon(":/actions/redo"));
    ui->action_Undo->setIcon(QIcon(":/actions/undo"));
    ui->action_Cut->setIcon(QIcon(":/actions/cut"));
    ui->action_Copy->setIcon(QIcon(":/actions/copy"));
    ui->action_Paste->setIcon(QIcon(":/actions/paste"));
    ui->action_SelectAll ->setIcon(QIcon(":/actions/select"));
    ui->action_Open->setIcon(QIcon(":/actions/open"));
    ui->action_Save->setIcon(QIcon(":/actions/save"));
    ui->action_Exit->setIcon(QIcon(":/actions/exit"));
    ui->action_About_program->setIcon(QIcon(":/actions/help"));
    ui->actionAbout_Qt->setIcon(QIcon(":/actions/qt"));
*/

    //Присоединяем действия к созданным слотам
    connect(ui->action_New, SIGNAL(triggered()),this, SLOT(slotNew()),Qt::UniqueConnection);
    connect(ui->action_Open, SIGNAL(triggered()), this, SLOT(slotOpen()),Qt::UniqueConnection);
    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT( slotSave()), Qt::UniqueConnection );
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT( aboutQt ( ) ), Qt::UniqueConnection );
    connect(ui->action_About_program, SIGNAL(triggered()), this, SLOT(slotAboutProgram()),Qt::UniqueConnection);

    connect(ui->actionPreferences, SIGNAL(triggered()),this, SLOT(showPreferencesDialog()), Qt::UniqueConnection);
    connect(msettingsDialog, SIGNAL(accepted()), this, SLOT (slotPreferencesAccepted()), Qt::UniqueConnection);

    //В конце вызываем слот для нового документа. Таким образом, пользователь сможет сразу
    //же приступить к работе
        slotNew ( );
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Метод обновления заголовка окна
void MainWindow::updateTitle ( )
{
//Подставляем в название заголовка имя текущего открытого файла.
//Комбинацией символов "[*]" обозначаем место, где будет выводиться знак "*" в случае,
//когда содержимое окна модифицировано.
QString lTitle=QString ( "TextEditor - %1 [*]" ).arg( mFileName);
//устанавливаем заголовок окна
setWindowTitle ( lTitle );
}

//Слот для создания нового документа
void MainWindow::slotNew ( )
{
    //Спросить пользователя о сохранении документа
    if (!askForFileSaveAndclose())
    {
        //Если пользоватеель нажал "Отменить" игнорировать вызов — продолжать работу
        return;
    }

    mFileName = "Untitled File"; //Задать имя для нового файла по умолчанию
    ui->plainTextEdit ->clear ( ); //Очистить текстовое поле
    setWindowModified ( false ); //Установить — содержание не модифицировано
    updateTitle ( ); //Обновить заголовок окна
}

//Слот для открытия файла в редакторе
void MainWindow::slotOpen ( )
{
    //Спросить пользователя о сохранении документа
    if (!askForFileSaveAndclose())
    {
        //Если пользоватеель нажал "Отменить" игнорировать вызов — продолжать работу
        return;
    }

    //Вызвать системный диалог открытия файла в домашней папке пользователя
    QString lFileName=QFileDialog::getOpenFileName ( this, "open file...", QDir::homePath(),"Text files (*.txt);;All files (*.*)");
    //указываем фильтры для просмотра файлов
    if ( lFileName.isEmpty ( ) ) //Если пользователь не выбрал ни одного файла
    {
        return; //выйти из метода
    }

    QFile lFile ( lFileName ); //Устанавливаем имя открытого файла
    //Если текстовый файл открыт только для чтения...
    if ( lFile.open ( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        mFileName = lFileName; //задать имя файла
        //читаем все содержимое и устанавливаем текст для редактора
        ui->plainTextEdit ->setPlainText( lFile.readAll ( ) );
        lFile.close ( ); //закрываем открытый файл
        //устанавливаем состояние окна — содержимое не модифицировано
        setWindowModified ( false );
        //и обновляем заголовок окна для демонстрации названия текущего открытого файла
        updateTitle();
    }
    else
    {
        //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
        //содержащим имя файла, одну кнопку "Ок" и заголовок "Error"
        QMessageBox::warning ( this, "Error", QString ("Could not open File %1 for "
        "reading " ).arg(lFile.fileName()),QMessageBox::Ok);
    }
}
//Слот для сохранения изменений в текущем файле
void MainWindow::slotSave ( )
{
    //Если содержимое не модифицировано...
    if (!isWindowModified() ) //Если содержимое не модифицировано
    {
    return; //Выйти из метода — продолжить работу
    }

    //Вызвать системный диалог сохранения файла в домашней папке пользователя
    QString lFileName=QFileDialog::getSaveFileName(this,tr("Save File..." ),QDir::homePath(),tr("Text files (*.txt);;All files (*.*)"));
    //Если пользователь не выбрал имя файла для сохранения...
    if ( lFileName.isEmpty ( ) )
    {
        return; // ... выйти из метода
    }
    QFile lFile(lFileName ); //Устанавливаем имя открытого файла
    //Если текстовый файл открыт для записи
    if ( lFile.open ( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        mFileName = lFileName; //Задать имя файла
        //Создаем временный QByteArray для записи данных
        QByteArray lData;
        //Читаем текст из редактора и добавляем QByteArray, записываем в файл
        //и закрываем файл после записи
        lData.append ( ui->plainTextEdit ->toPlainText( ) );
        lFile.write ( lData );
        lFile.close ( );
        //Устанавливаем состояние окна — содержимое не модифицировано
        setWindowModified ( false );
    }
    else
    {
        //Если при открытии файла возникла ошибка выводим диалоговое окно с сообщением,
        //содержащим имя файла, одну кнопку "Ок" и заголовок "Error"
        QMessageBox::warning ( this, "Error", QString ("Could not open File %1 for "
        "writing ").arg(lFile.fileName()), QMessageBox::Ok);
    }
}

//Метод для проверки текущего файла на изменения и вывода диалога для пользователя,
//с предложением сохранить изменения. Метод возвращает логическое значение,
//содержащее false в случае, когда пользователь нажал в диалоге кнопку "Cancel"
bool MainWindow::askForFileSaveAndclose ( )
{
    if (isWindowModified()) //Если содержимое окна модифицировано
    {
    //вызываем диалог с вопросом, нужно ли сохранять изменения: подставляем в текст диалога
    //название текущего открытого файла, задаем кнопки: "Да", "Нет" и "Отмена".
    //Результат работы диалога (нажатой кнопки) записываем в переменную
        int lResult = QMessageBox::question (this,tr ("Save changes"),
        QString (tr("File %1 is modified.Do you want to save your changes ?" )).arg
            (mFileName), QMessageBox::Yes, QMessageBox::No);
        if ( QMessageBox::Yes == lResult ) //Если нажали кнопку "Да"
        {
            slotSave(); //сохранить изменения
        }
        else
        {
           // if ( QMessageBox::No == lResult ) //Если нажали кнопку "No"
            {
                return false;
            }
        }
    }
    return true;
}
//Слот для отображения информации о программе
void MainWindow::slotAboutProgram()
{
    //Выводим диалоговое информационное окно с сообщением, куда подставляем версию и название
    //программы возвращаемых QApplication. Указываем — окно содержит заголовок "About".
    QMessageBox::about( this,tr("About"),
    QString("%1v.%2").arg(qApp->applicationName()).arg(qApp->applicationVersion()));
}
void MainWindow::showPreferencesDialog ( )
{
    readSettings ( ); //Считываем настройки и устанавливаем их для диалога
    msettingsDialog->show ( ); //Показываем диалог настроек
}
void MainWindow::slotPreferencesAccepted ( )
{
    writeSettings ( ); //Записать новые настройки
    applySettings ( ); //Применить настройки
}

void MainWindow::readSettings ( )
{
//Указываем, где хранились настройки. QSettings::NativeFormat — в формате определенном системой
//QSettings::UserScope — настройки для каждого пользователя отдельно.
//Также устанавливаем имя организации и название программы
    QSettings lsettings ( QSettings::NativeFormat, QSettings::UserScope, "", qApp->applicationName ( ) );
//Открываем группу настроек
    lsettings.beginGroup(SETTINGS_GROUP_VIEW);
//Читаем настройки
    bool lShowToolBar= lsettings.value (SETTING_SHOW_TOOLBAR, true ).toBool();
    msettingsDialog->setShowToolBar ( lShowToolBar );
    bool lShowStatusBar = lsettings.value (SETTING_SHOW_STATUS_BAR, true ).toBool();
    msettingsDialog->setShowStatusBar( lShowStatusBar );
}
void MainWindow::writeSettings ( )
{
//Указываем как сохранять настройки. QSettings::NativeFormat — в формате определенном системой
//QSettings::UserScope — настройки для каждого пользователя отдельно.
//Также устанавливаем имя организации и название программы.
    QSettings lSettings ( QSettings::NativeFormat, QSettings::UserScope, "", qApp
    ->applicationName ( ) );
//Открываем группу настроек
    lSettings.beginGroup (SETTINGS_GROUP_VIEW);
//Записываем настройки
    lSettings.setValue (SETTING_SHOW_TOOLBAR, msettingsDialog->isShowToolBar());
    lSettings.setValue (SETTING_SHOW_STATUS_BAR, msettingsDialog->isShowStatusBar());
}
void MainWindow::applySettings ( )
{
//Читаем настройки установленые в диалоге и применяем их
    ui->mainToolBar->setVisible ( msettingsDialog ->isShowToolBar ( ) );
    ui->statusBar->setVisible ( msettingsDialog ->isShowStatusBar ( ) );
}
