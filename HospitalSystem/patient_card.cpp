#include "patient_card.h"
int patientCard::count=0;
patientCard::patientCard(Patient &patient ,QWidget *parent)
    :QFrame (parent),_index(count++),_patient(patient)
{
    this->setContentsMargins(5,0,5,0);
    this->setCursor(Qt::ArrowCursor);
    _nameLabel= new QLabel(QString::fromStdString(_patient.property("Name").value()),this);
    _nameLabel->setStyleSheet(QString("QLabel{border:none; background-color:transparent;}"));
    _nameLabel->setFixedWidth(100);
    _nameLabel->setAlignment(Qt::AlignLeft);
    _diagnosis = new QLabel(QString::fromStdString(_patient.property("Diagnosis").value()),this);

    _diagnosis->setStyleSheet(QString("QLabel{border:none; background-color:transparent;}"));
    _diagnosis->setFixedWidth(100);
    _diagnosis->setAlignment(Qt::AlignLeft);
   QIcon editIcon(QPixmap("edit.png"));
    _editButton = new QPushButton(editIcon,"",this);
    _editButton->setCursor(Qt::PointingHandCursor);

    _editButton->setFixedSize(22,22);
    _editButton->setStyleSheet(QString("QPushButton {border:none; background-color:transparent;"
                   "color: white; border-radius: 8px;}"));
    _editButton->setCursor(Qt::PointingHandCursor);
    _editButton->setFlat(true);
    _editButton->setToolTip("Edit");
    _editButton->setIconSize(QSize(20,20));
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
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(_nameLabel,0,Qt::AlignVCenter);
    layout->addWidget(_bar, 0, Qt::AlignVCenter);
    layout->addWidget(_editButton,0, Qt::AlignVCenter);
   layout->addWidget(_deleteButton,Qt::AlignVCenter);
    layout->setSpacing(2);
    layout->setContentsMargins(2,2,2,2);
    this->setLayout(layout);
    this->setStyleSheet("QFrame{background-color:rgb(192,192,192);border-radius:4px}");



}
unsigned int patientCard::id()
{
    return _patient.id();

}
unsigned int patientCard::index()
{
    return _index;
}
