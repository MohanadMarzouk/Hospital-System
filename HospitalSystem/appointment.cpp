#include "appointment.h"

Appointment::Appointment():_available(true)
{

}

bool Appointment::available() const
{
    return _available;
}

void Appointment::setAvailable(bool available)
{
    _available = available;
}

bool Appointment::operator==(const Appointment &otherAppointment)
{
    if(_time==otherAppointment.time())
        return true;
    return false;
}

const std::string &Appointment::time() const
{
    return _time;
}
