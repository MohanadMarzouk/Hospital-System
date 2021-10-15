#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
class Appointment
{
private:
    bool _available ;
    std::string _time;

public:
    Appointment();
    bool available() const;
    void setAvailable(bool available);
    bool operator==(const Appointment& otherAppointment);
    const std::string& time()const;

};

#endif // APPOINTMENT_H
