/* 
 * File Counter64.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef COUNTER64_HXX_
#define COUNTER64_HXX_
#include "ietfYangTypesCommon.hxx"

#include <iostream>
#include "clTransaction.hxx"

namespace ietfYangTypes
  {

    class Counter64 {
    public:
        unsigned long int value;

    public:
        Counter64();
        unsigned long int getValue();
        void setValue(unsigned long int value, SAFplus::Transaction &t=SAFplus::NO_TXN);
        ietfYangTypes::Counter64& operator=(const ietfYangTypes::Counter64 &counter64);
        friend std::ostream& operator<<(std::ostream &os, const ietfYangTypes::Counter64 &counter64);
        friend std::istream& operator>>(std::istream &is, ietfYangTypes::Counter64 &counter64);
        ~Counter64();

    };
}
/* namespace ietfYangTypes */
#endif /* COUNTER64_HXX_ */
