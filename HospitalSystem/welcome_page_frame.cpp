#include "welcome_page_frame.h"
#include <QDir>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

WelcomePageFrame::WelcomePageFrame(QWidget *parent):QFrame(parent)
{
    QLabel * centerLabel= new QLabel(this);
    QPixmap bkgnd("displayImage.jpg");
    centerLabel->setPixmap(bkgnd);
    centerLabel->setScaledContents(true);

    QPushButton * doctorsPushButton= new QPushButton("Doctors",centerLabel);
    doctorsPushButton->setStyleSheet("QPushButton{background-color:white;border-radius:5} QPushButton:hover{background-color:rgb(173,216,230)}");

    doctorsPushButton->setFlat(true);
    doctorsPushButton->setFixedSize(90,50);
    QObject::connect(doctorsPushButton,SIGNAL(clicked()),this,SLOT(onDoctorsButtonClicked()));

    QPushButton * patientsPushButton= new QPushButton("Patients",centerLabel);
    patientsPushButton->setStyleSheet("QPushButton{background-color:white;border-radius:5} QPushButton:hover{background-color:rgb(173,216,230)}");
    patientsPushButton->setFlat(true);
    patientsPushButton->setFixedSize(90,50);
    QObject::connect(patientsPushButton,SIGNAL(clicked()),this,SLOT(onPatientsButtonClicked()));
    QHBoxLayout *buttonsLayout=new QHBoxLayout;
    buttonsLayout->addWidget(doctorsPushButton,Qt::AlignHCenter|Qt::AlignVCenter);
    buttonsLayout->addWidget(patientsPushButton,Qt::AlignHCenter|Qt::AlignVCenter);
    centerLabel->setLayout(buttonsLayout);

    QVBoxLayout * mainLayout= new QVBoxLayout;
    mainLayout->addWidget(centerLabel);
    this->setLayout(mainLayout);
}

void WelcomePageFrame::onPatientsButtonClicked()
{
   Q_EMIT patientButtonClicked();
}

void WelcomePageFrame::onDoctorsButtonClicked()
{
    Q_EMIT doctorsButtonClicked();
}
