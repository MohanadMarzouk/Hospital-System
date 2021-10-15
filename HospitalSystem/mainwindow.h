#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include "hospital_system_manager.h"
#include "welcome_page_frame.h"
#include <QStackedWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    virtual void resizeEvent(QResizeEvent *e);
private Q_SLOTS:
    void onPatientsButtonClicked();
    void onDoctorsButtonClicked();
private:
    Ui::MainWindow *ui;
    QStackedWidget *_mainStackedWidget;
    HospitalSystemManager _hospitalSystemManager;
    int _welcomePageIndex;
    int _doctorsPageIndex;
    int _patientsPageIndex;

};

#endif // MAINWINDOW_H
