#ifndef WELCOME_PAGE_FRAME_H
#define WELCOME_PAGE_FRAME_H

#include <QFrame>

class WelcomePageFrame:public QFrame
{
    Q_OBJECT
public:
    WelcomePageFrame(QWidget* parent=nullptr);
private Q_SLOTS:
    void onPatientsButtonClicked();
    void onDoctorsButtonClicked();
Q_SIGNALS:
    void patientButtonClicked();
    void doctorsButtonClicked();
};


#endif // WELCOME_PAGE_FRAME_H
