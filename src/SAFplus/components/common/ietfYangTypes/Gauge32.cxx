/* 
 * File Gauge32.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "ietfYangTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"
#include "Gauge32.hxx"


namespace ietfYangTypes
  {

    Gauge32::Gauge32()
    {
    };

    unsigned int Gauge32::getValue()
    {
        return this->value;
    };

    void Gauge32::setValue(unsigned int value, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->value = value;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&this->value,value);
            t.addOperation(opt);
        }
    };

    ietfYangTypes::Gauge32& Gauge32::operator=(const ietfYangTypes::Gauge32 &gauge32)
    {
        value = gauge32.value;
        return *this;
    };

    Gauge32::~Gauge32()
    {
    };

    std::ostream& operator<<(std::ostream &os, const ietfYangTypes::Gauge32 &gauge32)
    {
        return os << gauge32.value;
    };

    std::istream& operator>>(std::istream &is, ietfYangTypes::Gauge32 &gauge32)
    {
        return is >> gauge32.value;
    };

}
/* namespace ietfYangTypes */
