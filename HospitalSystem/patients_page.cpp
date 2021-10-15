#include "patients_page.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QIcon>
#include <patient_card.h>
#include <QDebug>
PatientsPage::PatientsPage(QWidget *parent):QFrame(parent)
{
    QLabel * mainLabel= new QLabel("Patients Page",this);
    mainLabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    QFont font("Helvetica", 12, QFont::Bold);
    mainLabel->setFont(font);
    QIcon addIcon(QPixmap("add.png"));
    _addButton= new QPushButton(addIcon,"",this);
    _addButton->setCursor(Qt::PointingHandCursor);
    _addButton->setToolTip("Add");
    _addButton->setFixedSize(32,32);
    _addButton->setStyleSheet(QString("QPushButton {border:none; background-color:transparent;"
                   "color: white; border-radius: 16px;}"));
    _addButton->setCursor(Qt::PointingHandCursor);
    _addButton->setFlat(true);
    _addButton->setIconSize(QSize(30,30));
    QObject::connect(_addButton,SIGNAL(clicked()),this,SLOT(onAddClicked()));
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QHBoxLayout *topLayout= new QHBoxLayout;
    _patientsLayout= new QVBoxLayout;
    _patientsLayout->addStretch();
    QFrame *patientsFrame= new QFrame(this);
    patientsFrame->setStyleSheet("background-color:rgb(220,220,220);border-radius:4px");
    patientsFrame->setLayout(_patientsLayout);
    topLayout->addWidget(mainLabel);


    topLayout->addStretch();
    topLayout->addWidget(_addButton);

    mainLayout->addItem(topLayout);
    mainLayout->addWidget(patientsFrame);

//    mainLayout->addStretch();
    this->setStyleSheet("QFrame{background-color:white}");
    this->setLayout(mainLayout);
}
void PatientsPage::onAddClicked()
{    qDebug()<<"add button clicked";
    Patient *patient= new Patient();
    patient->setProperty("Name","Ahmed Hosam");
    patient->setProperty("Diagnosis","Heart");
    patientCard * card= new patientCard(*patient,this);
//    _doctorsLayout->addWidget(card,Qt::AlignTop);
    _patientsLayout->insertWidget(_patientsLayout->count()-1,card);
}
