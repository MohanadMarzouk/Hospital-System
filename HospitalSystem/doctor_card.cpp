#include "doctor_card.h"

int DoctorCard::count=0;
#include <QHBoxLayout>
#include <QIcon>
DoctorCard::DoctorCard(Doctor &doctor, QWidget *parent)
    :QFrame(parent),_index(count++),_doctor(doctor)
{
    this->setContentsMargins(5,0,5,0);
    this->setCursor(Qt::ArrowCursor);
    _nameLabel = new QLabel(QString::fromStdString(_doctor.property("Name").value()),this);
    _nameLabel->setStyleSheet(QString("QLabel{border:none; background-color:transparent;}"));
    _nameLabel->setFixedWidth(100);
    _nameLabel->setAlignment(Qt::AlignLeft);
    _specialityMedicineLabel = new QLabel(QString::fromStdString(_doctor.property("Speciality Medicine").value()),this);
    _specialityMedicineLabel->setStyleSheet(QString("QLabel{border:none; background-color:transparent;}"));
    _specialityMedicineLabel->setFixedWidth(100);

    QIcon editIcon(QPixmap("edit.png"));
    _editButton= new QPushButton(editIcon,"",this);
    _editButton->setCursor(Qt::PointingHandCursor);

    _editButton->setFixedSize(22,22);
    _editButton->setStyleSheet(QString("QPushButton {border:none; background-color:transparent;"
                   "color: white; border-radius: 8px;}"));
    _editButton->setCursor(Qt::PointingHandCursor);
    _editButton->setFlat(true);
    _editButton->setToolTip("Edit");
    _editButton->setIconSize(QSize(20,20));

    QIcon reserveIcon(QPixmap("reserve.png"));
    _reserveButton= new QPushButton(reserveIcon,"",this);
    _reserveButton->setFixedSize(22,22);
    _reserveButton->setIconSize(QSize(20,20));

    _reserveButton->setCursor(Qt::PointingHandCursor);
    _reserveButton->setToolTip("Reserve");

    _reserveButton->setStyleSheet(QString("QPushButton {border:none; background-color:transparent;"
                   "color: white; border-radius: 8px;}"));
    _reserveButton->setFlat(true);
    QIcon deleteIcon(QPixmap("delete.png"));
    _deleteButton = new QPushButton(deleteIcon,"",this);
    _deleteButton->setFixedSize(22,22);
    _deleteButton->setIconSize(QSize(20,20));
    _deleteButton->setFlat(true);
    _deleteButton->setStyleSheet(QString("QPushButton {border:none; background-color:transparent;"
                   "color: white; border-radius: 8px;}"));
    _deleteButton->setToolTip("Delete");


    _bar = new QLabel("");
    _bar->setFixedWidth(2);
    _bar->setFixedHeight(16);
    _bar->setStyleSheet("background-color:black");
    this->setFixedHeight(22);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(_nameLabel,0,Qt::AlignVCenter);
    layout->addWidget(_bar, 0, Qt::AlignVCenter);
    layout->addWidget(_specialityMedicineLabel, 0, Qt::AlignVCenter);
    layout->addWidget(_editButton,0, Qt::AlignVCenter);
    layout->addWidget(_reserveButton,0, Qt::AlignVCenter);
    layout->addWidget(_deleteButton,Qt::AlignVCenter);
    layout->setSpacing(2);

    layout->setContentsMargins(2,2,2,2);
    this->setLayout(layout);
    this->setStyleSheet("QFrame{background-color:rgb(192,192,192);border-radius:4px}");
}

unsigned int DoctorCard::id()
{
    return _doctor.id();
}

unsigned int DoctorCard::index()
{
    return _index;
}
