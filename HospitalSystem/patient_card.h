#ifndef PATIENT_CARD_H
#define PATIENT_CARD_H
#include <QFrame>
#include <QPushButton>
#include <patient.h>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>

class patientCard :public QFrame
{
    Q_OBJECT
public:
    patientCard(Patient &patient , QWidget *parent=nullptr);
    unsigned int id();
    unsigned int index();
private :
static int count;
int _index;
QLabel * _nameLabel;
QLabel *_diagnosis;
QPushButton *_editButton;
QPushButton *_deleteButton;
QLabel *_bar;
Patient & _patient;


};

#endif // PATIENT_CARD_H
