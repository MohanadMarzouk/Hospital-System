#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "doctors_page.h"
#include "patients_page.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),_welcomePageIndex(-1)
{
    ui->setupUi(this);

    _mainStackedWidget= new QStackedWidget(this);
    WelcomePageFrame * welcomePage= new WelcomePageFrame(_mainStackedWidget);
    QObject::connect(welcomePage,SIGNAL(patientButtonClicked()),this,SLOT(onPatientsButtonClicked()));
    QObject::connect(welcomePage,SIGNAL(doctorsButtonClicked()),this,SLOT(onDoctorsButtonClicked()));
    _welcomePageIndex=_mainStackedWidget->addWidget(welcomePage);

    DoctorsPage *doctorsPage= new DoctorsPage(_mainStackedWidget);
    _doctorsPageIndex=_mainStackedWidget->addWidget(doctorsPage);

    PatientsPage *patientsPage= new PatientsPage(_mainStackedWidget);
    _patientsPageIndex=_mainStackedWidget->addWidget(patientsPage);

    _mainStackedWidget->setCurrentIndex(_welcomePageIndex);
    this->setCentralWidget(_mainStackedWidget);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    QMainWindow::resizeEvent(e);
    this->centralWidget()->setGeometry(this->geometry());
}

void MainWindow::onPatientsButtonClicked()
{
    qDebug()<<"patients button clicked";
    _mainStackedWidget->setCurrentIndex(_patientsPageIndex);
}

void MainWindow::onDoctorsButtonClicked()
{
    qDebug()<<"doctors button clicked";
    _mainStackedWidget->setCurrentIndex(_doctorsPageIndex);
}
