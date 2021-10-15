#include "doctors_page.h"
#include <QLabel>
#include <QVBoxLayout>
#include "doctor_card.h"
#include "QDebug"
DoctorsPage::DoctorsPage(QWidget *parent):QFrame(parent)
{
    QLabel * mainLabel= new QLabel("Doctors Page",this);
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
    QObject::connect(_addButton,SIGNAL(clicked()),this,SLOT(onAddCLicked()));
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QHBoxLayout *topLayout= new QHBoxLayout;
    _doctorsLayout= new QVBoxLayout;
    _doctorsLayout->addStretch();
    QFrame *doctorsFrame= new QFrame(this);
    doctorsFrame->setStyleSheet("background-color:rgb(220,220,220);border-radius:4px");
    doctorsFrame->setLayout(_doctorsLayout);
    topLayout->addWidget(mainLabel);


    topLayout->addStretch();
    topLayout->addWidget(_addButton);

    mainLayout->addItem(topLayout);
    mainLayout->addWidget(doctorsFrame);

//    mainLayout->addStretch();
    this->setStyleSheet("QFrame{background-color:white}");
    this->setLayout(mainLayout);
}

void DoctorsPage::onAddCLicked()
{     qDebug()<<"add button clicked";
    Doctor *doctor= new Doctor();
    doctor->setProperty("Name","Ahmed Hosam");
    doctor->setProperty("Speciality Medicine","Heart");
    DoctorCard * card= new DoctorCard(*doctor,this);
//    _doctorsLayout->addWidget(card,Qt::AlignTop);
    _doctorsLayout->insertWidget(_doctorsLayout->count()-1,card);
}
