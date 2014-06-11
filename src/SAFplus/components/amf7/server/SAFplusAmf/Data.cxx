/* 
 * File Data.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include <string>
#include "clMgtProv.hxx"
#include "clMgtList.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include "Data.hxx"


namespace SAFplusAmf
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(Data, /SAFplusAmf/ComponentServiceInstance/data)

    Data::Data(): SAFplus::MgtList<std::string>("data"), myName("myName"), val("val")
    {
        std::string myNameName("myName");
        std::string valname("val");
        this->addChildObject(&myName, myNameName);
        this->addChildObject(&val, valname);
    };

    Data::Data(std::string myNameValue): SAFplus::MgtList<std::string>("data"), myName("myName"), val("val")
    {
        this->myName.value =  myNameValue;
        std::string myNameName("myName");
        std::string valname("val");
        this->addChildObject(&myName, myNameName);
        this->addChildObject(&val, valname);
    };

    void Data::toString(std::stringstream &xmlString)
    {
        /* TODO:  */
    };

    std::vector<std::string> Data::getKeys()
    {
        std::string keyNames[] = { "myName" };
        return std::vector<std::string> (keyNames, keyNames + sizeof(keyNames) / sizeof(keyNames[0]));
    };

    std::vector<std::string>* Data::getChildNames()
    {
        std::string childNames[] = { "myName", "val" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/data/myName
     */
    std::string Data::getMyName()
    {
        return this->myName.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/data/myName
     */
    void Data::setMyName(std::string myNameValue)
    {
        this->myName.value = myNameValue;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/data/val
     */
    std::string Data::getVal()
    {
        return this->val.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/data/val
     */
    void Data::setVal(std::string valValue)
    {
        this->val.value = valValue;
    };

    Data::~Data()
    {
    };

}
/* namespace SAFplusAmf */
