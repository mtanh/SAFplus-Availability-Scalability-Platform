/* 
 * File SaTimeT.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef SATIMET_HXX_
#define SATIMET_HXX_
#include "SAFplusTypesCommon.hxx"

#include <iostream>

namespace SAFplusTypes
  {

    class SaTimeT {
    public:
        unsigned long int Value;

    public:
        SaTimeT();
        unsigned long int getValue();
        void setValue(unsigned long int value);
        SAFplusTypes::SaTimeT& operator=(const SAFplusTypes::SaTimeT &SaTimeT);
        friend std::ostream& operator<<(std::ostream &os, const SAFplusTypes::SaTimeT &SaTimeT);
        friend std::istream& operator>>(std::istream &is, SAFplusTypes::SaTimeT &SaTimeT);
        ~SaTimeT();

    };
}
/* namespace SAFplusTypes */
#endif /* SATIMET_HXX_ */