/* 
 * File Node.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include <vector>
#include "Capacity.hxx"
#include "clMgtObject.hxx"
#include "clMgtProv.hxx"
#include "Capacity.hxx"
#include "clMgtList.hxx"
#include "ServiceUnitFailureEscalationPolicy.hxx"
#include "MgtFactory.hxx"
#include "AdministrativeState.hxx"
#include "clMgtProvList.hxx"
#include "ServiceUnitFailureEscalationPolicy.hxx"
#include <string>
#include "ServiceUnit.hxx"
#include "Node.hxx"


namespace SAFplusAmf
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(Node, /SAFplusAmf/Node)

    Node::Node(): SAFplus::ClMgtObject("Node"), name("name"), id("id"), adminState("adminState"), operState("operState"), autoRepair("autoRepair"), failFastOnInstantiationFailure("failFastOnInstantiationFailure"), failFastOnCleanupFailure("failFastOnCleanupFailure"), serviceUnits("serviceUnits"), capacityList("capacity")
    {
        this->addChildObject(&name, "name");
        this->addChildObject(&id, "id");
        this->addChildObject(&adminState, "adminState");
        this->addChildObject(&operState, "operState");
        this->addChildObject(&autoRepair, "autoRepair");
        this->addChildObject(&failFastOnInstantiationFailure, "failFastOnInstantiationFailure");
        this->addChildObject(&failFastOnCleanupFailure, "failFastOnCleanupFailure");
        this->addChildObject(&serviceUnits, "serviceUnits");
        this->addChildObject(&capacityList, "capacity");
        this->addKey("name");
    };

    Node::Node(std::string nameValue): SAFplus::ClMgtObject("Node"), name("name"), id("id"), adminState("adminState"), operState("operState"), autoRepair("autoRepair"), failFastOnInstantiationFailure("failFastOnInstantiationFailure"), failFastOnCleanupFailure("failFastOnCleanupFailure"), serviceUnits("serviceUnits"), capacityList("capacity")
    {
        this->name.Value =  nameValue;
        this->addKey("name");
        this->addChildObject(&name, "name");
        this->addChildObject(&id, "id");
        this->addChildObject(&adminState, "adminState");
        this->addChildObject(&operState, "operState");
        this->addChildObject(&autoRepair, "autoRepair");
        this->addChildObject(&failFastOnInstantiationFailure, "failFastOnInstantiationFailure");
        this->addChildObject(&failFastOnCleanupFailure, "failFastOnCleanupFailure");
        this->addChildObject(&serviceUnits, "serviceUnits");
        this->addChildObject(&capacityList, "capacity");
    };

    std::vector<std::string> Node::getKeys()
    {
        std::string keyNames[] = { "name" };
        return std::vector<std::string> (keyNames, keyNames + sizeof(keyNames) / sizeof(keyNames[0]));
    };

    std::vector<std::string>* Node::getChildNames()
    {
        std::string childNames[] = { "name", "id", "adminState", "operState", "capacity", "serviceUnitFailureEscalationPolicy", "autoRepair", "failFastOnInstantiationFailure", "failFastOnCleanupFailure", "serviceUnits" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusAmf/Node/name
     */
    std::string Node::getName()
    {
        return this->name.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/name
     */
    void Node::setName(std::string nameValue)
    {
        this->name.Value = nameValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/id
     */
    unsigned short int Node::getId()
    {
        return this->id.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/id
     */
    void Node::setId(unsigned short int idValue)
    {
        this->id.Value = idValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/adminState
     */
    SAFplusAmf::AdministrativeState Node::getAdminState()
    {
        return this->adminState.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/adminState
     */
    void Node::setAdminState(SAFplusAmf::AdministrativeState adminStateValue)
    {
        this->adminState.Value = adminStateValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/operState
     */
    bool Node::getOperState()
    {
        return this->operState.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/operState
     */
    void Node::setOperState(bool operStateValue)
    {
        this->operState.Value = operStateValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/autoRepair
     */
    bool Node::getAutoRepair()
    {
        return this->autoRepair.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/autoRepair
     */
    void Node::setAutoRepair(bool autoRepairValue)
    {
        this->autoRepair.Value = autoRepairValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/failFastOnInstantiationFailure
     */
    bool Node::getFailFastOnInstantiationFailure()
    {
        return this->failFastOnInstantiationFailure.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/failFastOnInstantiationFailure
     */
    void Node::setFailFastOnInstantiationFailure(bool failFastOnInstantiationFailureValue)
    {
        this->failFastOnInstantiationFailure.Value = failFastOnInstantiationFailureValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/failFastOnCleanupFailure
     */
    bool Node::getFailFastOnCleanupFailure()
    {
        return this->failFastOnCleanupFailure.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/failFastOnCleanupFailure
     */
    void Node::setFailFastOnCleanupFailure(bool failFastOnCleanupFailureValue)
    {
        this->failFastOnCleanupFailure.Value = failFastOnCleanupFailureValue;
    };

    /*
     * XPATH: /SAFplusAmf/Node/serviceUnits
     */
    std::vector<SAFplusAmf::ServiceUnit*> Node::getServiceUnits()
    {
        return this->serviceUnits.Value;
    };

    /*
     * XPATH: /SAFplusAmf/Node/serviceUnits
     */
    void Node::setServiceUnits(SAFplusAmf::ServiceUnit* serviceUnitsValue)
    {
        this->serviceUnits.Value.push_back(serviceUnitsValue);
    };

    /*
     * XPATH: /SAFplusAmf/Node/capacity
     */
    SAFplusAmf::Capacity* Node::getCapacity(std::string resourceValue)
    {
        for (unsigned int i = 0; i < this->capacityList.getEntrySize(); i++)
        {
            Capacity* childObject = (Capacity*)this->capacityList.getEntry(i);
            if (childObject->getResource() == resourceValue)
            {
                return childObject;
            }
        }
        return NULL;
    };

    /*
     * XPATH: /SAFplusAmf/Node/capacity
     */
    void Node::addCapacity(SAFplusAmf::Capacity *capacityValue)
    {
        this->capacityList.addEntry(capacityValue);
    };

    /*
     * XPATH: /SAFplusAmf/Node/serviceUnitFailureEscalationPolicy
     */
    SAFplusAmf::ServiceUnitFailureEscalationPolicy* Node::getServiceUnitFailureEscalationPolicy()
    {
        return (ServiceUnitFailureEscalationPolicy*)this->getChildObject("serviceUnitFailureEscalationPolicy");
    };

    /*
     * XPATH: /SAFplusAmf/Node/serviceUnitFailureEscalationPolicy
     */
    void Node::addServiceUnitFailureEscalationPolicy(SAFplusAmf::ServiceUnitFailureEscalationPolicy *serviceUnitFailureEscalationPolicyValue)
    {
        this->addChildObject(serviceUnitFailureEscalationPolicyValue, "serviceUnitFailureEscalationPolicy");
    };

    Node::~Node()
    {
    };

}
/* namespace SAFplusAmf */
