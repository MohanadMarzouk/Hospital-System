#ifndef HOSPITAL_SYSTEM_MANAGER_H
#define HOSPITAL_SYSTEM_MANAGER_H
#include "doctor.h"
#include "emergencypatient.h"
#include "patient.h"
#include "room.h"

#include<vector>
#include <string>

class HospitalSystemManager
{
private:
    std::vector<Patient> _patients;
    std::vector<EmergencyPatient> _emergencyPatients;
    std::vector<Doctor> _doctors;
    std::vector<Room> _rooms;

public:
    HospitalSystemManager();
    void addNewDoctor(Doctor doctor);
    void addNewPatient(Patient patient);
    void setDoctorProperty(unsigned int doctorId,std::string propertyName,std::string propertyValue);
    void setPatientProperty(unsigned int patientId,std::string propertyName,std::string propertyValue);
    void setEmergencyPatientProperty(unsigned int patientId,std::string propertyName,std::string propertyValue);

    const std::vector<Patient> & patients();
    const std::vector<EmergencyPatient> & emergencyPatients();
    const std::vector<Doctor> & Doctors();

    Doctor & doctor(unsigned int doctorId);
//    const Doctor &doctor(unsigned int doctorId)const;
    void reserveDoctorAppointment(unsigned int doctorId,Appointment appointment);
    void freeAllDoctorAppointments(unsigned int doctorId);
    void addNewDoctorAppointment(unsigned int doctorId,Appointment appointment);
    void removeDoctorAppointment(unsigned int doctorId,Appointment appointment);
    void addDoctorAppointments(unsigned int doctorId,std::vector<Appointment> appointments);
    bool isDoctorAppointmentFree(unsigned int doctorId,Appointment appointment);
    std::vector<Appointment> freeDoctorAppointments(unsigned int doctorId);




};

#endif // HOSPITAL_SYSTEM_MANAGER_H
