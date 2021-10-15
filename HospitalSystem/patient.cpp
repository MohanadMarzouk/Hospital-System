#include "patient.h"

Patient::Patient()
    :Person()
{
    addProperty("Gender","");
    addProperty("Symptoms","");
    addProperty("PaymentMethod","");
    addProperty("Diagnosis","");
}

//std::string Patient::gender() const
//{
//    return _gender;
//}

//void Patient::setGender(const std::string &gender)
//{
//    _gender = gender;
//}

//std::string Patient::symptoms() const
//{
//    return _symptoms;
//}

//void Patient::setSymptoms(const std::string &symptoms)
//{
//    _symptoms = symptoms;
//}

//std::string Patient::paymentMethod() const
//{
//    return _paymentMethod;
//}

//void Patient::setPaymentMethod(const std::string &paymentMethod)
//{
//    _paymentMethod = paymentMethod;
//}

//std::string Patient::diagnosis() const
//{
//    return _diagnosis;
//}

//void Patient::setDiagnosis(const std::string &diagnosis)
//{
//    _diagnosis = diagnosis;
//}
