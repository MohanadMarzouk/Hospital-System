#ifndef DOCTOR_H
#define DOCTOR_H

#include "appointment.h"
#include "person.h"
#include <vector>
class Doctor:public Person
{
private:
    std::vector<Appointment> _appointments;

public:
    Doctor();
    void reserveAppointment(Appointment appointment);
    void freeAllAppointments();
    void addNewAppointment(Appointment appointment);
    void removeAppointment(Appointment appointment);
    void addAppointments(std::vector<Appointment> appointments);
    bool isAppointmentFree(Appointment appointment);
    std::vector<Appointment> freeAppointments();


};

#endif // DOCTOR_H
