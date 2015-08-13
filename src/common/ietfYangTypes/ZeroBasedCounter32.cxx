/* 
 * File ZeroBasedCounter32.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "ietfYangTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"
#include <cstdint>
#include "ZeroBasedCounter32.hxx"


namespace ietfYangTypes
  {

    ZeroBasedCounter32::ZeroBasedCounter32()
    {
    };

    ::uint32_t ZeroBasedCounter32::getValue()
    {
        return this->value;
    };

    void ZeroBasedCounter32::setValue(::uint32_t value, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->value = value;
        else
        {
            SAFplus::SimpleTxnOperation<::uint32_t> *opt = new SAFplus::SimpleTxnOperation<::uint32_t>(&this->value,value);
            t.addOperation(opt);
        }
    };

    ietfYangTypes::ZeroBasedCounter32& ZeroBasedCounter32::operator=(const ietfYangTypes::ZeroBasedCounter32 &zeroBasedCounter32)
    {
        value = zeroBasedCounter32.value;
        return *this;
    };

    ZeroBasedCounter32::~ZeroBasedCounter32()
    {
    };

    std::ostream& operator<<(std::ostream &os, const ietfYangTypes::ZeroBasedCounter32 &zeroBasedCounter32)
    {
        return os << zeroBasedCounter32.value;
    };

    std::istream& operator>>(std::istream &is, ietfYangTypes::ZeroBasedCounter32 &zeroBasedCounter32)
    {
        return is >> zeroBasedCounter32.value;
    };

}
/* namespace ietfYangTypes */