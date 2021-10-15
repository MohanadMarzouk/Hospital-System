#include "person.h"

unsigned int Person::counter =0;

Person::Person():_id(counter++)
{
    addProperty("Name","");
    addProperty("Phone Number","");
    addProperty("Address","");
}

void Person::setProperty(std::string propertyName, std::string propertyValue)
{
    for(std::size_t propertyIndex=0;propertyIndex<_properties.size();++propertyIndex)
    {
        if(_properties[propertyIndex].name()==propertyName)
        {
            _properties[propertyIndex].setValue(propertyValue);
            return;
        }
    }
    throw "wrong property value";

}

const Property &Person::property(const std::string &propertyName)
{
    for(std::size_t propertyIndex=0;propertyIndex<_properties.size();++propertyIndex)
    {
        if(_properties[propertyIndex].name()==propertyName)
        {
            return _properties[propertyIndex];
        }
    }
    throw "wrong property Value";
}

const std::vector<Property> &Person::properties()
{
    return _properties;
}

void Person::addProperty(std::string propertyName, std::string propertyValue)
{
    Property property(propertyName,propertyValue);
    _properties.push_back(property);
}


unsigned int Person::id() const
{
    return _id;
}

/* void Person::setId(unsigned int id)
{
    _id = id;
}
*/
Property::Property(std::string name, std::string value)
    :_name(name),_value(value)
{

}

const std::string Property::name()const
{
    return _name;
}

const std::string Property::value() const
{
    return _value;
}

void Property::setName(const std::string &name)
{
    _name = name;
}

void Property::setValue(const std::string &value)
{
    _value=value;
}



//Person::Person(std::string name, std::string address, std::string phoneNumber)
//    :_id(counter++),_name(name),_address(address),_phoneNumber(phoneNumber)
//{

//}

//Person::Person():_id(counter++),_name(""),_address(""),_phoneNumber("")
//{

//}

//std::string Person::phoneNumber() const
//{
////    return _phoneNumber;
//}

//void Person::setPhoneNumber(const std::string &phoneNumber)
//{
////    _phoneNumber = phoneNumber;
//}

//std::string Person::address() const
//{
////    return _address;
//}

//void Person::setAddress(const std::string &address)
//{
////    _address = address;
//}

//std::string Person::name() const
//{
////    return _name;
//}

//void Person::setName(const std::string &name)
//{
////    _name = name;
//}
