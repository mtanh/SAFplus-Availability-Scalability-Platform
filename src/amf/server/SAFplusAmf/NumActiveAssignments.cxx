/* 
 * File NumActiveAssignments.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include <vector>
#include "MgtFactory.hxx"
#include "IntStatistic.hxx"
#include "NumActiveAssignments.hxx"


namespace SAFplusAmf
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(NumActiveAssignments, /SAFplusAmf/ServiceInstance/numActiveAssignments)

    NumActiveAssignments::NumActiveAssignments()
    {
        this->tag.assign("numActiveAssignments");
    };

    std::vector<std::string>* NumActiveAssignments::getChildNames()
    {
        std::string childNames[] = { "current", "history10sec", "history1min", "history10min", "history1hour", "history1day", "history1week", "history1month" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    NumActiveAssignments::~NumActiveAssignments()
    {
    };

}
/* namespace SAFplusAmf */
