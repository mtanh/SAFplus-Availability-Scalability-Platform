/* 
 * File SAFplusLog.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusLogCommon.hxx"

#include <vector>
#include "MgtFactory.hxx"
#include "Stream.hxx"
#include "clMgtContainer.hxx"
#include "SAFplusLog.hxx"


namespace SAFplusLog
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(SAFplusLogRoot, /SAFplusLog)

    SAFplusLogRoot::SAFplusLogRoot(): SAFplus::MgtContainer("SAFplusLog")
    {
    };

    void SAFplusLogRoot::toString(std::stringstream &xmlString)
    {
        /* TODO:  */
    };

    std::vector<std::string>* SAFplusLogRoot::getChildNames()
    {
        std::string childNames[] = { "ServerConfig", "StreamConfig" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    SAFplusLogRoot::~SAFplusLogRoot()
    {
    };

}
/* namespace SAFplusLog */