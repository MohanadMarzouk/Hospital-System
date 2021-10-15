#ifndef DOCTORS_PAGE_H
#define DOCTORS_PAGE_H

#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <doctor.h>
class DoctorsPage:public QFrame
{
    Q_OBJECT
public:
    DoctorsPage(QWidget* parent=nullptr);
private:
    QPushButton *_addButton;
    QVBoxLayout *_doctorsLayout;
private Q_SLOTS:
    void onAddCLicked();
};

#endif // DOCTORS_PAGE_H
