/* 
 * File ComponentServiceInstance.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include <string>
#include "clTransaction.hxx"
#include "clMgtProv.hxx"
#include "ServiceInstance.hxx"
#include "Component.hxx"
#include "clMgtList.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include "EntityId.hxx"
#include "clMgtProvList.hxx"
#include "ComponentServiceInstance.hxx"


namespace SAFplusAmf
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(ComponentServiceInstance, /SAFplusAmf/ComponentServiceInstance)

    ComponentServiceInstance::ComponentServiceInstance(): protectionGroup("protectionGroup"), dependencies("dependencies"), serviceInstance("serviceInstance"), component("component"), dataList("data")
    {
        this->addChildObject(&protectionGroup, "protectionGroup");
        this->addChildObject(&dependencies, "dependencies");
        this->addChildObject(&serviceInstance, "serviceInstance");
        this->addChildObject(&component, "component");
        this->addChildObject(&dataList, "data");
        this->name.assign("ComponentServiceInstance");
    };

    ComponentServiceInstance::ComponentServiceInstance(std::string myNameValue): protectionGroup("protectionGroup"), dependencies("dependencies"), serviceInstance("serviceInstance"), component("component"), dataList("data")
    {
        this->myName.value =  myNameValue;
        this->addChildObject(&protectionGroup, "protectionGroup");
        this->addChildObject(&dependencies, "dependencies");
        this->addChildObject(&serviceInstance, "serviceInstance");
        this->addChildObject(&component, "component");
        this->addChildObject(&dataList, "data");
        this->name.assign("ComponentServiceInstance");
    };

    void ComponentServiceInstance::toString(std::stringstream &xmlString)
    {
        /* TODO:  */
    };

    std::vector<std::string> ComponentServiceInstance::getKeys()
    {
        std::string keyNames[] = { "myName" };
        return std::vector<std::string> (keyNames, keyNames + sizeof(keyNames) / sizeof(keyNames[0]));
    };

    std::vector<std::string>* ComponentServiceInstance::getChildNames()
    {
        std::string childNames[] = { "myName", "id", "protectionGroup", "dependencies", "data", "serviceInstance", "component" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/protectionGroup
     */
    std::vector<std::string> ComponentServiceInstance::getProtectionGroup()
    {
        return this->protectionGroup.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/protectionGroup
     */
    void ComponentServiceInstance::setProtectionGroup(std::string protectionGroupValue)
    {
        this->protectionGroup.value.push_back(protectionGroupValue);
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/dependencies
     */
    std::vector<SAFplusAmf::ComponentServiceInstance*> ComponentServiceInstance::getDependencies()
    {
        return this->dependencies.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/dependencies
     */
    void ComponentServiceInstance::setDependencies(SAFplusAmf::ComponentServiceInstance* dependenciesValue)
    {
        this->dependencies.value.push_back(dependenciesValue);
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/serviceInstance
     */
    SAFplusAmf::ServiceInstance* ComponentServiceInstance::getServiceInstance()
    {
        return this->serviceInstance.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/serviceInstance
     */
    void ComponentServiceInstance::setServiceInstance(SAFplusAmf::ServiceInstance* serviceInstanceValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->serviceInstance.value = serviceInstanceValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::ServiceInstance*> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::ServiceInstance*>(&(serviceInstance.value),serviceInstanceValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/component
     */
    SAFplusAmf::Component* ComponentServiceInstance::getComponent()
    {
        return this->component.value;
    };

    /*
     * XPATH: /SAFplusAmf/ComponentServiceInstance/component
     */
    void ComponentServiceInstance::setComponent(SAFplusAmf::Component* componentValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->component.value = componentValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::Component*> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::Component*>(&(component.value),componentValue);
            t.addOperation(opt);
        }
    };

    ComponentServiceInstance::~ComponentServiceInstance()
    {
    };

}
/* namespace SAFplusAmf */
