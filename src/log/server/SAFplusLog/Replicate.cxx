/* 
 * File Replicate.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#include "MgtEnumType.hxx"
#include <iostream>
#include "SAFplusLogCommon.hxx"
#include "Replicate.hxx"

using namespace SAFplusLog;

namespace SAFplusLog
  {

    /*
     * Provide an implementation of the en2str_map lookup table.
     */
    const ReplicateManager::map_t ReplicateManager::en2str_map = {
            pair_t(Replicate::NONE, "NONE"),
            pair_t(Replicate::SYSTEM_CONTROLLERS, "SYSTEM_CONTROLLERS"),
            pair_t(Replicate::APPLICATIONS, "APPLICATIONS"),
            pair_t(Replicate::ANY, "ANY")
    }; // uses c++11 initializer lists 

    const char* c_str(const SAFplusLog::Replicate &replicate)
    {
        return ReplicateManager::c_str(replicate);
    };

    std::ostream& operator<<(std::ostream &os, const SAFplusLog::Replicate &replicate)
    {
        return os << ReplicateManager::toString(replicate);
    };

    std::istream& operator>>(std::istream &is, SAFplusLog::Replicate &replicate)
    {
        std::string buf;
        is >> buf;
        replicate = ReplicateManager::toEnum(buf);
        return is;
    };

}
/* namespace ::SAFplusLog */
