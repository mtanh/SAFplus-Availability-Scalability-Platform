/* 
 * File ComponentServiceInstance.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef COMPONENTSERVICEINSTANCE_HXX_
#define COMPONENTSERVICEINSTANCE_HXX_
#include "SAFplusAmfCommon.hxx"

#include <string>
#include "clMgtProv.hxx"
#include "ServiceInstance.hxx"
#include "Data.hxx"
#include "Component.hxx"
#include "clMgtList.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include "EntityId.hxx"
#include "Data.hxx"
#include "clMgtProvList.hxx"

namespace SAFplusAmf
  {

    class ComponentServiceInstance : public EntityId {

        /* Apply MGT object factory */
        MGT_REGISTER(ComponentServiceInstance);

    public:

        /*
         * Unique name of this entity
         */
        SAFplus::ClMgtProv<std::string> name;

        /*
         * Each SAFplus AMF entity gets a unique numerical identifier
         */
        SAFplus::ClMgtProv<unsigned short int> id;

        /*
         * A protection group for a specific component service instance is the group of components to which the component service instance has been assigned
         */
        SAFplus::ClMgtProvList<std::string> protectionGroup;

        /*
         * 
         */
        SAFplus::ClMgtProvList<SAFplusAmf::ComponentServiceInstance*> dependencies;
        SAFplus::ClMgtProv<SAFplusAmf::ServiceInstance*> serviceInstance;
        SAFplus::ClMgtProv<SAFplusAmf::Component*> component;

        /*
         * Arbitrary data that defines the work needed to be done.
         */
        SAFplus::ClMgtList dataList;

    public:
        ComponentServiceInstance();
        ComponentServiceInstance(std::string nameValue);
        std::vector<std::string> getKeys();
        std::vector<std::string>* getChildNames();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/name
         */
        std::string getName();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/name
         */
        void setName(std::string nameValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/id
         */
        unsigned short int getId();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/id
         */
        void setId(unsigned short int idValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/protectionGroup
         */
        std::vector<std::string> getProtectionGroup();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/protectionGroup
         */
        void setProtectionGroup(std::string protectionGroupValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/dependencies
         */
        std::vector<SAFplusAmf::ComponentServiceInstance*> getDependencies();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/dependencies
         */
        void setDependencies(SAFplusAmf::ComponentServiceInstance* dependenciesValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/serviceInstance
         */
        SAFplusAmf::ServiceInstance* getServiceInstance();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/serviceInstance
         */
        void setServiceInstance(SAFplusAmf::ServiceInstance* serviceInstanceValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/component
         */
        SAFplusAmf::Component* getComponent();

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/component
         */
        void setComponent(SAFplusAmf::Component* componentValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/data
         */
        SAFplusAmf::Data* getData(std::string nameValue);

        /*
         * XPATH: /SAFplusAmf/ComponentServiceInstance/data
         */
        void addData(SAFplusAmf::Data *dataValue);
        ~ComponentServiceInstance();

    };
}
/* namespace SAFplusAmf */
#endif /* COMPONENTSERVICEINSTANCE_HXX_ */