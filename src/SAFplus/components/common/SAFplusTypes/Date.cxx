/* 
 * File Date.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"
#include "Date.hxx"


namespace SAFplusTypes
  {

    Date::Date()
    {
    };

    unsigned long int Date::getValue()
    {
        return this->value;
    };

    void Date::setValue(unsigned long int value, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->value = value;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned long int> *opt = new SAFplus::SimpleTxnOperation<unsigned long int>(&this->value,value);
            t.addOperation(opt);
        }
    };

    SAFplusTypes::Date& Date::operator=(const SAFplusTypes::Date &date)
    {
        value = date.value;
        return *this;
    };

    Date::~Date()
    {
    };

    std::ostream& operator<<(std::ostream &os, const SAFplusTypes::Date &date)
    {
        return os << date.value;
    };

    std::istream& operator>>(std::istream &is, SAFplusTypes::Date &date)
    {
        return is >> date.value;
    };

}
/* namespace SAFplusTypes */
