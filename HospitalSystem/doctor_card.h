#ifndef DOCTOR_CARD_H
#define DOCTOR_CARD_H

#include "doctor.h"
#include <QLabel>
#include <QFrame>
#include <QPushButton>

class DoctorCard:public QFrame
{
    Q_OBJECT
public:
    DoctorCard(Doctor & doctor, QWidget *parent=nullptr);
    unsigned int id();
    unsigned int index();
private:
    static int count;
    int _index;
    Doctor &_doctor;
    QLabel * _nameLabel;
    QLabel * _specialityMedicineLabel;
    QPushButton *_editButton;
    QPushButton *_reserveButton;
    QPushButton *_deleteButton;
    QLabel *_bar;

};

#endif // DOCTOR_CARD_H
