/* 
 * File Counter32.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "ietfYangTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"
#include <cstdint>
#include "Counter32.hxx"


namespace ietfYangTypes
  {

    Counter32::Counter32()
    {
    };

    ::uint32_t Counter32::getValue()
    {
        return this->value;
    };

    void Counter32::setValue(::uint32_t value, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->value = value;
        else
        {
            SAFplus::SimpleTxnOperation<::uint32_t> *opt = new SAFplus::SimpleTxnOperation<::uint32_t>(&this->value,value);
            t.addOperation(opt);
        }
    };

    ietfYangTypes::Counter32& Counter32::operator=(const ietfYangTypes::Counter32 &counter32)
    {
        value = counter32.value;
        return *this;
    };

    Counter32::~Counter32()
    {
    };

    std::ostream& operator<<(std::ostream &os, const ietfYangTypes::Counter32 &counter32)
    {
        return os << counter32.value;
    };

    std::istream& operator>>(std::istream &is, ietfYangTypes::Counter32 &counter32)
    {
        return is >> counter32.value;
    };

}
/* namespace ietfYangTypes */
