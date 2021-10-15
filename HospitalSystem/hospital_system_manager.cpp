#include "hospital_system_manager.h"

HospitalSystemManager::HospitalSystemManager()
{

}

void HospitalSystemManager::addNewDoctor(Doctor doctor)
{
    _doctors.push_back(doctor);
}

void HospitalSystemManager::addNewPatient(Patient patient)
{
    _patients.push_back(patient);
}

void HospitalSystemManager::setDoctorProperty(unsigned int doctorId, std::string propertyName, std::string propertyValue)
{
    for(std::size_t doctorIndex=0;doctorIndex<_doctors.size();++doctorIndex)
    {
        if(doctorId==_doctors[doctorIndex].id())
        {
            _doctors[doctorIndex].setProperty(propertyName,propertyValue);
        }
    }
}

void HospitalSystemManager::setPatientProperty(unsigned int patientId, std::string propertyName, std::string propertyValue)
{
    for(std::size_t patientIndex=0;patientIndex<_patients.size();++patientIndex)
    {
        if(patientId==_patients[patientIndex].id())
        {
            _patients[patientIndex].setProperty(propertyName,propertyValue);
        }
    }
}

void HospitalSystemManager::setEmergencyPatientProperty(unsigned int patientId, std::string propertyName, std::string propertyValue)
{
    for(std::size_t patientIndex=0;patientIndex<_emergencyPatients.size();++patientIndex)
    {
        if(patientId==_emergencyPatients[patientIndex].id())
        {
            _emergencyPatients[patientIndex].setProperty(propertyName,propertyValue);
        }
    }
}

Doctor &HospitalSystemManager::doctor(unsigned int doctorId)
{
    for(std::size_t doctorIndex=0;doctorIndex<_doctors.size();++doctorIndex)
    {
        if(doctorId==_doctors[doctorIndex].id())
        {
            return _doctors[doctorIndex];
        }
    }
    throw "Doctor does not exist";
}



void HospitalSystemManager::reserveDoctorAppointment(unsigned int doctorId, Appointment appointment)
{
    doctor(doctorId).reserveAppointment(appointment);
}

void HospitalSystemManager::freeAllDoctorAppointments(unsigned int doctorId)
{
    doctor(doctorId).freeAppointments();
}

void HospitalSystemManager::addNewDoctorAppointment(unsigned int doctorId, Appointment appointment)
{
    doctor(doctorId).addNewAppointment(appointment);

}

void HospitalSystemManager::removeDoctorAppointment(unsigned int doctorId, Appointment appointment)
{
    doctor(doctorId).removeAppointment(appointment);
}

void HospitalSystemManager::addDoctorAppointments(unsigned int doctorId, std::vector<Appointment> appointments)
{
    doctor(doctorId).addAppointments(appointments);
}

bool HospitalSystemManager::isDoctorAppointmentFree(unsigned int doctorId, Appointment appointment)
{
    return doctor(doctorId).isAppointmentFree(appointment);
}

std::vector<Appointment> HospitalSystemManager::freeDoctorAppointments(unsigned int doctorId)
{
    return doctor(doctorId).freeAppointments();
}
