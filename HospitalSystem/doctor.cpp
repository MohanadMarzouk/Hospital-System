#include "doctor.h"

Doctor::Doctor():Person ()
{
    addProperty("Speciality Medicine","");
}

void Doctor::reserveAppointment(Appointment appointment)
{
    for(std::size_t appointmentIndex=0;appointmentIndex<_appointments.size();++appointmentIndex)
    {  // may be not free
        if(appointment==_appointments[appointmentIndex])
        {
            _appointments[appointmentIndex].setAvailable(false);
            return;
        }
    }
    throw "this appointment is not avilable";
}

void Doctor::freeAllAppointments()
{
    for(std::size_t appointmentIndex=0;appointmentIndex<_appointments.size();++appointmentIndex)
    {
            _appointments[appointmentIndex].setAvailable(true);
    }
}

void Doctor::addNewAppointment(Appointment appointment)
{
    _appointments.push_back(appointment);
}

void Doctor::removeAppointment(Appointment appointment)
{
    for(std::size_t appointmentIndex=0;appointmentIndex<_appointments.size();++appointmentIndex)
    {
        if(appointment==_appointments[appointmentIndex])
        {
            _appointments.erase(_appointments.begin()+appointmentIndex);
        }
    }
}

void Doctor::addAppointments(std::vector<Appointment> appointments)
{
    _appointments=appointments;
}

bool Doctor::isAppointmentFree(Appointment appointment)
{
    for(std::size_t appointmentIndex=0;appointmentIndex<_appointments.size();++appointmentIndex)
    {
        if(appointment==_appointments[appointmentIndex])
        {
            return _appointments[appointmentIndex].available();
        }
    }
    return false;
}

std::vector<Appointment> Doctor::freeAppointments()
{
    std::vector<Appointment> appointmentsVector;
    for(std::size_t appointmentIndex=0;appointmentIndex<_appointments.size();++appointmentIndex)
    {
        if(_appointments[appointmentIndex].available())
        {
            appointmentsVector.push_back(_appointments[appointmentIndex]);
        }
    }
    return appointmentsVector;
}
