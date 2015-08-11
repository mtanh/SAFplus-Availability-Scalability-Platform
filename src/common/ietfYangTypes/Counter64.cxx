/* 
 * File Counter64.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "ietfYangTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"
#include <cstdint>
#include "Counter64.hxx"


namespace ietfYangTypes
  {

    Counter64::Counter64()
    {
    };

    ::uint64_t Counter64::getValue()
    {
        return this->value;
    };

    void Counter64::setValue(::uint64_t value, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->value = value;
        else
        {
            SAFplus::SimpleTxnOperation<::uint64_t> *opt = new SAFplus::SimpleTxnOperation<::uint64_t>(&this->value,value);
            t.addOperation(opt);
        }
    };

    ietfYangTypes::Counter64& Counter64::operator=(const ietfYangTypes::Counter64 &counter64)
    {
        value = counter64.value;
        return *this;
    };

    Counter64::~Counter64()
    {
    };

    std::ostream& operator<<(std::ostream &os, const ietfYangTypes::Counter64 &counter64)
    {
        return os << counter64.value;
    };

    std::istream& operator>>(std::istream &is, ietfYangTypes::Counter64 &counter64)
    {
        return is >> counter64.value;
    };

}
/* namespace ietfYangTypes */
