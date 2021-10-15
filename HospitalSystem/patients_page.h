#ifndef PATIENTS_PAGE_H
#define PATIENTS_PAGE_H
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <patient.h>
class PatientsPage:public QFrame
{
    Q_OBJECT

public:
    PatientsPage(QWidget* parent=nullptr);

private:
    QPushButton *_addButton;
    QVBoxLayout *_patientsLayout;

 private  Q_SLOTS :
    void onAddClicked();

};

#endif // PATIENTS_PAGE_H
