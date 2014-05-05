/* 
 * File Node.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef NODE_HXX_
#define NODE_HXX_
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

namespace SAFplusAmf
  {

    class Node : public SAFplus::ClMgtObject {

        /* Apply MGT object factory */
        MGT_REGISTER(Node);

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
         * Does the operator want this entity to be off, idle, or in service?
         */
        SAFplus::ClMgtProv<SAFplusAmf::AdministrativeState> adminState;

        /*
         * True is enabled, False is disabled.  To move from False to True a 'repair' action must occur.
         */
        SAFplus::ClMgtProv<bool> operState;

        /*
         * Automatically attempt to bring this entity back into a healthy state if its operational state becomes disabled.
         */
        SAFplus::ClMgtProv<bool> autoRepair;

        /*
         * If a component fails to instantiate on this node after potentially multiple attempts (as configured in the component) the AMF will reboot this node if this field is true
         */
        SAFplus::ClMgtProv<bool> failFastOnInstantiationFailure;

        /*
         * If a component's cleanup script fails on this node after potentially multiple attempts (as configured in the component) the AMF will reboot this node if this field is true
         */
        SAFplus::ClMgtProv<bool> failFastOnCleanupFailure;

        /*
         * Service Units configured to be instantiated on this node.
         */
        SAFplus::ClMgtProvList<SAFplusAmf::ServiceUnit*> serviceUnits;

        /*
         * An abstract definition of the amount of work this node can handle.  Nodes can be assigned capacities for arbitrarily chosen strings (MEM or CPU, for example).  Service Instances can be assigned 'weights' and the sum of the weights of service instances assigned active or standby on this node cannot exceed these values.
         */
        SAFplus::ClMgtList capacityList;

    public:
        Node();
        Node(std::string nameValue);
        std::vector<std::string> getKeys();
        std::vector<std::string>* getChildNames();

        /*
         * XPATH: /SAFplusAmf/Node/name
         */
        std::string getName();

        /*
         * XPATH: /SAFplusAmf/Node/name
         */
        void setName(std::string nameValue);

        /*
         * XPATH: /SAFplusAmf/Node/id
         */
        unsigned short int getId();

        /*
         * XPATH: /SAFplusAmf/Node/id
         */
        void setId(unsigned short int idValue);

        /*
         * XPATH: /SAFplusAmf/Node/adminState
         */
        SAFplusAmf::AdministrativeState getAdminState();

        /*
         * XPATH: /SAFplusAmf/Node/adminState
         */
        void setAdminState(SAFplusAmf::AdministrativeState adminStateValue);

        /*
         * XPATH: /SAFplusAmf/Node/operState
         */
        bool getOperState();

        /*
         * XPATH: /SAFplusAmf/Node/operState
         */
        void setOperState(bool operStateValue);

        /*
         * XPATH: /SAFplusAmf/Node/autoRepair
         */
        bool getAutoRepair();

        /*
         * XPATH: /SAFplusAmf/Node/autoRepair
         */
        void setAutoRepair(bool autoRepairValue);

        /*
         * XPATH: /SAFplusAmf/Node/failFastOnInstantiationFailure
         */
        bool getFailFastOnInstantiationFailure();

        /*
         * XPATH: /SAFplusAmf/Node/failFastOnInstantiationFailure
         */
        void setFailFastOnInstantiationFailure(bool failFastOnInstantiationFailureValue);

        /*
         * XPATH: /SAFplusAmf/Node/failFastOnCleanupFailure
         */
        bool getFailFastOnCleanupFailure();

        /*
         * XPATH: /SAFplusAmf/Node/failFastOnCleanupFailure
         */
        void setFailFastOnCleanupFailure(bool failFastOnCleanupFailureValue);

        /*
         * XPATH: /SAFplusAmf/Node/serviceUnits
         */
        std::vector<SAFplusAmf::ServiceUnit*> getServiceUnits();

        /*
         * XPATH: /SAFplusAmf/Node/serviceUnits
         */
        void setServiceUnits(SAFplusAmf::ServiceUnit* serviceUnitsValue);

        /*
         * XPATH: /SAFplusAmf/Node/capacity
         */
        SAFplusAmf::Capacity* getCapacity(std::string resourceValue);

        /*
         * XPATH: /SAFplusAmf/Node/capacity
         */
        void addCapacity(SAFplusAmf::Capacity *capacityValue);

        /*
         * XPATH: /SAFplusAmf/Node/serviceUnitFailureEscalationPolicy
         */
        SAFplusAmf::ServiceUnitFailureEscalationPolicy* getServiceUnitFailureEscalationPolicy();

        /*
         * XPATH: /SAFplusAmf/Node/serviceUnitFailureEscalationPolicy
         */
        void addServiceUnitFailureEscalationPolicy(SAFplusAmf::ServiceUnitFailureEscalationPolicy *serviceUnitFailureEscalationPolicyValue);
        ~Node();

    };
}
/* namespace SAFplusAmf */
#endif /* NODE_HXX_ */
