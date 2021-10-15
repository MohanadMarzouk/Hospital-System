#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

class Property
{
private:
    std::string _name;
    std::string _value;

    public:
        Property(std::string name,std::string value);
        const std::string name()const ;
        const std::string value()const ;
        void setName(const std::string &name);
        void setValue(const std::string &value);


};

class Person
{
public:
//    Person(std::string name,std::string address,std::string phoneNumber);
    Person();
    void setProperty(std::string propertyName,std::string propertyValue);
    const Property & property(const std::string& propertyName);
    const std::vector<Property>& properties();
//    std::string phoneNumber() const;
//    void setPhoneNumber(const std::string &phoneNumber);

//    std::string address() const;
//    void setAddress(const std::string &address);

//    std::string name() const;
//    void setName(const std::string &name);

    unsigned int id() const;
   // void setId(unsigned int id);
protected:
    void addProperty(std::string propertyName,std::string propertyValue);

private:
    static unsigned int counter;
    unsigned int _id;
    std::vector<Property> _properties;
//    std::string _name;
//    std::string _address;
//    std::string _phoneNumber;

};

#endif // PERSON_H
