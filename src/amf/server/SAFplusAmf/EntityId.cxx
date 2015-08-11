/* 
 * File EntityId.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include <string>
#include "clTransaction.hxx"
#include "clMgtProv.hxx"
#include <vector>
#include "clMgtContainer.hxx"
#include <cstdint>
#include "EntityId.hxx"


namespace SAFplusAmf
  {

    EntityId::EntityId(): SAFplus::MgtContainer("EntityId"), name("name"), id("id")
    {
        this->addChildObject(&name, "name");
        this->addChildObject(&id, "id");
    };

    std::vector<std::string>* EntityId::getChildNames()
    {
        std::string childNames[] = { "name", "id" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusAmf/EntityId/name
     */
    std::string EntityId::getName()
    {
        return this->name;
    };

    /*
     * XPATH: /SAFplusAmf/EntityId/name
     */
    void EntityId::setName(std::string nameValue, SAFplus::Transaction &txn)
    {
        this->name = nameValue;
    };

    /*
     * XPATH: /SAFplusAmf/EntityId/id
     */
    ::uint16_t EntityId::getId()
    {
        return this->id.value;
    };

    /*
     * XPATH: /SAFplusAmf/EntityId/id
     */
    void EntityId::setId(::uint16_t idValue, SAFplus::Transaction &txn)
    {
        this->id.set(idValue,txn);
    };

    EntityId::~EntityId()
    {
    };

}
/* namespace SAFplusAmf */
