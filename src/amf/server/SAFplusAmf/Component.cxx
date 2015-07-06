/* 
 * File Component.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 
#include "SAFplusAmfCommon.hxx"

#include "RestartCount.hxx"
#include "clMgtIdentifier.hxx"
#include "clTransaction.hxx"
#include "HighAvailabilityReadinessState.hxx"
#include "Timeouts.hxx"
#include "StandbyAssignments.hxx"
#include "Instantiate.hxx"
#include "RestartCount.hxx"
#include "Terminate.hxx"
#include "Cleanup.hxx"
#include "MgtFactory.hxx"
#include "ActiveAssignments.hxx"
#include "CapabilityModel.hxx"
#include "Cleanup.hxx"
#include <string>
#include "ReadinessState.hxx"
#include "Timeouts.hxx"
#include "Instantiate.hxx"
#include "clMgtProv.hxx"
#include "PendingOperation.hxx"
#include "Recovery.hxx"
#include "Terminate.hxx"
#include "StandbyAssignments.hxx"
#include <vector>
#include "ActiveAssignments.hxx"
#include "HighAvailabilityState.hxx"
#include "PresenceState.hxx"
#include "Date.hxx"
#include "EntityId.hxx"
#include "clMgtProvList.hxx"
#include "ServiceUnit.hxx"
#include "Component.hxx"

using namespace SAFplusTypes;

namespace SAFplusAmf
  {

    /* Apply MGT object factory */
    MGT_REGISTER_IMPL(Component, /SAFplusAmf/Component)

    Component::Component(): presenceState("presenceState"), capabilityModel("capabilityModel"), maxActiveAssignments("maxActiveAssignments"), maxStandbyAssignments("maxStandbyAssignments"), assignedWork("assignedWork"), operState("operState"), readinessState("readinessState"), haReadinessState("haReadinessState"), haState("haState"), safVersion("safVersion"), compCategory("compCategory"), swBundle("swBundle"), commandEnvironment("commandEnvironment"), maxInstantInstantiations("maxInstantInstantiations"), maxDelayedInstantiations("maxDelayedInstantiations"), numInstantiationAttempts("numInstantiationAttempts"), instantiationSuccessDuration("instantiationSuccessDuration"), lastInstantiation("lastInstantiation"), delayBetweenInstantiation("delayBetweenInstantiation"), serviceUnit("serviceUnit"), recovery("recovery"), restartable("restartable"), proxy("proxy"), proxied("proxied"), processId("processId"), lastError("lastError"), pendingOperation("pendingOperation"), pendingOperationExpiration("pendingOperationExpiration")
    {
        this->addChildObject(&presenceState, "presenceState");
        presenceState.config = false;
        this->addChildObject(&capabilityModel, "capabilityModel");
        this->addChildObject(&maxActiveAssignments, "maxActiveAssignments");
        this->addChildObject(&maxStandbyAssignments, "maxStandbyAssignments");
        this->addChildObject(&assignedWork, "assignedWork");
        assignedWork.config = false;
        this->addChildObject(&operState, "operState");
        operState.config = false;
        this->addChildObject(&readinessState, "readinessState");
        readinessState.config = false;
        this->addChildObject(&haReadinessState, "haReadinessState");
        haReadinessState.config = false;
        this->addChildObject(&haState, "haState");
        haState.config = false;
        this->addChildObject(&safVersion, "safVersion");
        this->addChildObject(&compCategory, "compCategory");
        this->addChildObject(&swBundle, "swBundle");
        swBundle.config = false;
        this->addChildObject(&commandEnvironment, "commandEnvironment");
        this->addChildObject(&maxInstantInstantiations, "maxInstantInstantiations");
        this->addChildObject(&maxDelayedInstantiations, "maxDelayedInstantiations");
        this->addChildObject(&numInstantiationAttempts, "numInstantiationAttempts");
        numInstantiationAttempts.config = false;
        this->addChildObject(&instantiationSuccessDuration, "instantiationSuccessDuration");
        this->addChildObject(&lastInstantiation, "lastInstantiation");
        lastInstantiation.config = false;
        this->addChildObject(&delayBetweenInstantiation, "delayBetweenInstantiation");
        this->addChildObject(&serviceUnit, "serviceUnit");
        this->addChildObject(&recovery, "recovery");
        this->addChildObject(&restartable, "restartable");
        this->addChildObject(&proxy, "proxy");
        this->addChildObject(&proxied, "proxied");
        this->addChildObject(&processId, "processId");
        processId.config = false;
        this->addChildObject(&lastError, "lastError");
        lastError.config = false;
        this->addChildObject(&pendingOperation, "pendingOperation");
        pendingOperation.config = false;
        this->addChildObject(&pendingOperationExpiration, "pendingOperationExpiration");
        pendingOperationExpiration.config = false;
        this->addChildObject(&activeAssignments, "activeAssignments");
        activeAssignments.config = false;
        this->addChildObject(&standbyAssignments, "standbyAssignments");
        standbyAssignments.config = false;
        this->addChildObject(&instantiate, "instantiate");
        this->addChildObject(&terminate, "terminate");
        this->addChildObject(&cleanup, "cleanup");
        this->addChildObject(&timeouts, "timeouts");
        this->addChildObject(&restartCount, "restartCount");
        restartCount.config = false;
        this->tag.assign("Component");
    };

    Component::Component(std::string nameValue): presenceState("presenceState"), capabilityModel("capabilityModel"), maxActiveAssignments("maxActiveAssignments"), maxStandbyAssignments("maxStandbyAssignments"), assignedWork("assignedWork"), operState("operState"), readinessState("readinessState"), haReadinessState("haReadinessState"), haState("haState"), safVersion("safVersion"), compCategory("compCategory"), swBundle("swBundle"), commandEnvironment("commandEnvironment"), maxInstantInstantiations("maxInstantInstantiations"), maxDelayedInstantiations("maxDelayedInstantiations"), numInstantiationAttempts("numInstantiationAttempts"), instantiationSuccessDuration("instantiationSuccessDuration"), lastInstantiation("lastInstantiation"), delayBetweenInstantiation("delayBetweenInstantiation"), serviceUnit("serviceUnit"), recovery("recovery"), restartable("restartable"), proxy("proxy"), proxied("proxied"), processId("processId"), lastError("lastError"), pendingOperation("pendingOperation"), pendingOperationExpiration("pendingOperationExpiration")
    {
        this->name.value =  nameValue;
        this->addChildObject(&presenceState, "presenceState");
        presenceState.config = false;
        this->addChildObject(&capabilityModel, "capabilityModel");
        this->addChildObject(&maxActiveAssignments, "maxActiveAssignments");
        this->addChildObject(&maxStandbyAssignments, "maxStandbyAssignments");
        this->addChildObject(&assignedWork, "assignedWork");
        assignedWork.config = false;
        this->addChildObject(&operState, "operState");
        operState.config = false;
        this->addChildObject(&readinessState, "readinessState");
        readinessState.config = false;
        this->addChildObject(&haReadinessState, "haReadinessState");
        haReadinessState.config = false;
        this->addChildObject(&haState, "haState");
        haState.config = false;
        this->addChildObject(&safVersion, "safVersion");
        this->addChildObject(&compCategory, "compCategory");
        this->addChildObject(&swBundle, "swBundle");
        swBundle.config = false;
        this->addChildObject(&commandEnvironment, "commandEnvironment");
        this->addChildObject(&maxInstantInstantiations, "maxInstantInstantiations");
        this->addChildObject(&maxDelayedInstantiations, "maxDelayedInstantiations");
        this->addChildObject(&numInstantiationAttempts, "numInstantiationAttempts");
        numInstantiationAttempts.config = false;
        this->addChildObject(&instantiationSuccessDuration, "instantiationSuccessDuration");
        this->addChildObject(&lastInstantiation, "lastInstantiation");
        lastInstantiation.config = false;
        this->addChildObject(&delayBetweenInstantiation, "delayBetweenInstantiation");
        this->addChildObject(&serviceUnit, "serviceUnit");
        this->addChildObject(&recovery, "recovery");
        this->addChildObject(&restartable, "restartable");
        this->addChildObject(&proxy, "proxy");
        this->addChildObject(&proxied, "proxied");
        this->addChildObject(&processId, "processId");
        processId.config = false;
        this->addChildObject(&lastError, "lastError");
        lastError.config = false;
        this->addChildObject(&pendingOperation, "pendingOperation");
        pendingOperation.config = false;
        this->addChildObject(&pendingOperationExpiration, "pendingOperationExpiration");
        pendingOperationExpiration.config = false;
        this->addChildObject(&activeAssignments, "activeAssignments");
        activeAssignments.config = false;
        this->addChildObject(&standbyAssignments, "standbyAssignments");
        standbyAssignments.config = false;
        this->addChildObject(&instantiate, "instantiate");
        this->addChildObject(&terminate, "terminate");
        this->addChildObject(&cleanup, "cleanup");
        this->addChildObject(&timeouts, "timeouts");
        this->addChildObject(&restartCount, "restartCount");
        restartCount.config = false;
        this->tag.assign("Component");
    };

    std::vector<std::string> Component::getKeys()
    {
        std::string keyNames[] = { "name" };
        return std::vector<std::string> (keyNames, keyNames + sizeof(keyNames) / sizeof(keyNames[0]));
    };

    std::vector<std::string>* Component::getChildNames()
    {
        std::string childNames[] = { "name", "id", "presenceState", "capabilityModel", "maxActiveAssignments", "maxStandbyAssignments", "activeAssignments", "standbyAssignments", "assignedWork", "operState", "readinessState", "haReadinessState", "haState", "safVersion", "compCategory", "swBundle", "commandEnvironment", "instantiate", "terminate", "cleanup", "maxInstantInstantiations", "maxDelayedInstantiations", "numInstantiationAttempts", "instantiationSuccessDuration", "lastInstantiation", "delayBetweenInstantiation", "timeouts", "serviceUnit", "recovery", "restartable", "restartCount", "proxy", "proxied", "processId", "lastError", "pendingOperation", "pendingOperationExpiration" };
        return new std::vector<std::string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusAmf/Component/presenceState
     */
    SAFplusAmf::PresenceState Component::getPresenceState()
    {
        return this->presenceState.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/presenceState
     */
    void Component::setPresenceState(SAFplusAmf::PresenceState presenceStateValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->presenceState.value = presenceStateValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::PresenceState> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::PresenceState>(&(presenceState.value),presenceStateValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/capabilityModel
     */
    SAFplusAmf::CapabilityModel Component::getCapabilityModel()
    {
        return this->capabilityModel.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/capabilityModel
     */
    void Component::setCapabilityModel(SAFplusAmf::CapabilityModel capabilityModelValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->capabilityModel.value = capabilityModelValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::CapabilityModel> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::CapabilityModel>(&(capabilityModel.value),capabilityModelValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxActiveAssignments
     */
    unsigned int Component::getMaxActiveAssignments()
    {
        return this->maxActiveAssignments.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxActiveAssignments
     */
    void Component::setMaxActiveAssignments(unsigned int maxActiveAssignmentsValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->maxActiveAssignments.value = maxActiveAssignmentsValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(maxActiveAssignments.value),maxActiveAssignmentsValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxStandbyAssignments
     */
    unsigned int Component::getMaxStandbyAssignments()
    {
        return this->maxStandbyAssignments.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxStandbyAssignments
     */
    void Component::setMaxStandbyAssignments(unsigned int maxStandbyAssignmentsValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->maxStandbyAssignments.value = maxStandbyAssignmentsValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(maxStandbyAssignments.value),maxStandbyAssignmentsValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/assignedWork
     */
    std::vector<std::string> Component::getAssignedWork()
    {
        return this->assignedWork.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/assignedWork
     */
    void Component::setAssignedWork(std::string assignedWorkValue)
    {
        this->assignedWork.value.push_back(assignedWorkValue);
    };

    /*
     * XPATH: /SAFplusAmf/Component/operState
     */
    bool Component::getOperState()
    {
        return this->operState.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/operState
     */
    void Component::setOperState(bool operStateValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->operState.value = operStateValue;
        else
        {
            SAFplus::SimpleTxnOperation<bool> *opt = new SAFplus::SimpleTxnOperation<bool>(&(operState.value),operStateValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/readinessState
     */
    SAFplusAmf::ReadinessState Component::getReadinessState()
    {
        return this->readinessState.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/readinessState
     */
    void Component::setReadinessState(SAFplusAmf::ReadinessState readinessStateValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->readinessState.value = readinessStateValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::ReadinessState> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::ReadinessState>(&(readinessState.value),readinessStateValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/haReadinessState
     */
    SAFplusAmf::HighAvailabilityReadinessState Component::getHaReadinessState()
    {
        return this->haReadinessState.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/haReadinessState
     */
    void Component::setHaReadinessState(SAFplusAmf::HighAvailabilityReadinessState haReadinessStateValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->haReadinessState.value = haReadinessStateValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::HighAvailabilityReadinessState> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::HighAvailabilityReadinessState>(&(haReadinessState.value),haReadinessStateValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/haState
     */
    SAFplusAmf::HighAvailabilityState Component::getHaState()
    {
        return this->haState.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/haState
     */
    void Component::setHaState(SAFplusAmf::HighAvailabilityState haStateValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->haState.value = haStateValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::HighAvailabilityState> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::HighAvailabilityState>(&(haState.value),haStateValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/safVersion
     */
    std::string Component::getSafVersion()
    {
        return this->safVersion.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/safVersion
     */
    void Component::setSafVersion(std::string safVersionValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->safVersion.value = safVersionValue;
        else
        {
            SAFplus::SimpleTxnOperation<std::string> *opt = new SAFplus::SimpleTxnOperation<std::string>(&(safVersion.value),safVersionValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/compCategory
     */
    unsigned int Component::getCompCategory()
    {
        return this->compCategory.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/compCategory
     */
    void Component::setCompCategory(unsigned int compCategoryValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->compCategory.value = compCategoryValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(compCategory.value),compCategoryValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/swBundle
     */
    std::string Component::getSwBundle()
    {
        return this->swBundle.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/swBundle
     */
    void Component::setSwBundle(std::string swBundleValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->swBundle.value = swBundleValue;
        else
        {
            SAFplus::SimpleTxnOperation<std::string> *opt = new SAFplus::SimpleTxnOperation<std::string>(&(swBundle.value),swBundleValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/commandEnvironment
     */
    std::vector<std::string> Component::getCommandEnvironment()
    {
        return this->commandEnvironment.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/commandEnvironment
     */
    void Component::setCommandEnvironment(std::string commandEnvironmentValue)
    {
        this->commandEnvironment.value.push_back(commandEnvironmentValue);
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxInstantInstantiations
     */
    unsigned int Component::getMaxInstantInstantiations()
    {
        return this->maxInstantInstantiations.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxInstantInstantiations
     */
    void Component::setMaxInstantInstantiations(unsigned int maxInstantInstantiationsValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->maxInstantInstantiations.value = maxInstantInstantiationsValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(maxInstantInstantiations.value),maxInstantInstantiationsValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxDelayedInstantiations
     */
    unsigned int Component::getMaxDelayedInstantiations()
    {
        return this->maxDelayedInstantiations.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/maxDelayedInstantiations
     */
    void Component::setMaxDelayedInstantiations(unsigned int maxDelayedInstantiationsValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->maxDelayedInstantiations.value = maxDelayedInstantiationsValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(maxDelayedInstantiations.value),maxDelayedInstantiationsValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/numInstantiationAttempts
     */
    unsigned int Component::getNumInstantiationAttempts()
    {
        return this->numInstantiationAttempts.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/numInstantiationAttempts
     */
    void Component::setNumInstantiationAttempts(unsigned int numInstantiationAttemptsValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->numInstantiationAttempts.value = numInstantiationAttemptsValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(numInstantiationAttempts.value),numInstantiationAttemptsValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/instantiationSuccessDuration
     */
    unsigned int Component::getInstantiationSuccessDuration()
    {
        return this->instantiationSuccessDuration.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/instantiationSuccessDuration
     */
    void Component::setInstantiationSuccessDuration(unsigned int instantiationSuccessDurationValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->instantiationSuccessDuration.value = instantiationSuccessDurationValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(instantiationSuccessDuration.value),instantiationSuccessDurationValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/lastInstantiation
     */
    SAFplusTypes::Date Component::getLastInstantiation()
    {
        return this->lastInstantiation.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/lastInstantiation
     */
    void Component::setLastInstantiation(SAFplusTypes::Date lastInstantiationValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->lastInstantiation.value = lastInstantiationValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusTypes::Date> *opt = new SAFplus::SimpleTxnOperation<SAFplusTypes::Date>(&(lastInstantiation.value),lastInstantiationValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/delayBetweenInstantiation
     */
    unsigned int Component::getDelayBetweenInstantiation()
    {
        return this->delayBetweenInstantiation.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/delayBetweenInstantiation
     */
    void Component::setDelayBetweenInstantiation(unsigned int delayBetweenInstantiationValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->delayBetweenInstantiation.value = delayBetweenInstantiationValue;
        else
        {
            SAFplus::SimpleTxnOperation<unsigned int> *opt = new SAFplus::SimpleTxnOperation<unsigned int>(&(delayBetweenInstantiation.value),delayBetweenInstantiationValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/serviceUnit
     */
    SAFplusAmf::ServiceUnit* Component::getServiceUnit()
    {
        return this->serviceUnit.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/serviceUnit
     */
    void Component::setServiceUnit(SAFplusAmf::ServiceUnit* serviceUnitValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->serviceUnit.value = serviceUnitValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::ServiceUnit*> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::ServiceUnit*>(&(serviceUnit.value),serviceUnitValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/recovery
     */
    SAFplusAmf::Recovery Component::getRecovery()
    {
        return this->recovery.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/recovery
     */
    void Component::setRecovery(SAFplusAmf::Recovery recoveryValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->recovery.value = recoveryValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::Recovery> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::Recovery>(&(recovery.value),recoveryValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/restartable
     */
    bool Component::getRestartable()
    {
        return this->restartable.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/restartable
     */
    void Component::setRestartable(bool restartableValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->restartable.value = restartableValue;
        else
        {
            SAFplus::SimpleTxnOperation<bool> *opt = new SAFplus::SimpleTxnOperation<bool>(&(restartable.value),restartableValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/proxy
     */
    std::string Component::getProxy()
    {
        return this->proxy.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/proxy
     */
    void Component::setProxy(std::string proxyValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->proxy.value = proxyValue;
        else
        {
            SAFplus::SimpleTxnOperation<std::string> *opt = new SAFplus::SimpleTxnOperation<std::string>(&(proxy.value),proxyValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/proxied
     */
    std::vector<std::string> Component::getProxied()
    {
        return this->proxied.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/proxied
     */
    void Component::setProxied(std::string proxiedValue)
    {
        this->proxied.value.push_back(proxiedValue);
    };

    /*
     * XPATH: /SAFplusAmf/Component/processId
     */
    int Component::getProcessId()
    {
        return this->processId.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/processId
     */
    void Component::setProcessId(int processIdValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->processId.value = processIdValue;
        else
        {
            SAFplus::SimpleTxnOperation<int> *opt = new SAFplus::SimpleTxnOperation<int>(&(processId.value),processIdValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/lastError
     */
    std::string Component::getLastError()
    {
        return this->lastError.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/lastError
     */
    void Component::setLastError(std::string lastErrorValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->lastError.value = lastErrorValue;
        else
        {
            SAFplus::SimpleTxnOperation<std::string> *opt = new SAFplus::SimpleTxnOperation<std::string>(&(lastError.value),lastErrorValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/pendingOperation
     */
    SAFplusAmf::PendingOperation Component::getPendingOperation()
    {
        return this->pendingOperation.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/pendingOperation
     */
    void Component::setPendingOperation(SAFplusAmf::PendingOperation pendingOperationValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->pendingOperation.value = pendingOperationValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusAmf::PendingOperation> *opt = new SAFplus::SimpleTxnOperation<SAFplusAmf::PendingOperation>(&(pendingOperation.value),pendingOperationValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/pendingOperationExpiration
     */
    SAFplusTypes::Date Component::getPendingOperationExpiration()
    {
        return this->pendingOperationExpiration.value;
    };

    /*
     * XPATH: /SAFplusAmf/Component/pendingOperationExpiration
     */
    void Component::setPendingOperationExpiration(SAFplusTypes::Date pendingOperationExpirationValue, SAFplus::Transaction &t)
    {
        if(&t == &SAFplus::NO_TXN) this->pendingOperationExpiration.value = pendingOperationExpirationValue;
        else
        {
            SAFplus::SimpleTxnOperation<SAFplusTypes::Date> *opt = new SAFplus::SimpleTxnOperation<SAFplusTypes::Date>(&(pendingOperationExpiration.value),pendingOperationExpirationValue);
            t.addOperation(opt);
        }
    };

    /*
     * XPATH: /SAFplusAmf/Component/activeAssignments
     */
    SAFplusAmf::ActiveAssignments* Component::getActiveAssignments()
    {
        return dynamic_cast<ActiveAssignments*>(this->getChildObject("activeAssignments"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/activeAssignments
     */
    void Component::addActiveAssignments(SAFplusAmf::ActiveAssignments *activeAssignmentsValue)
    {
        this->addChildObject(activeAssignmentsValue, "activeAssignments");
    };

    /*
     * XPATH: /SAFplusAmf/Component/standbyAssignments
     */
    SAFplusAmf::StandbyAssignments* Component::getStandbyAssignments()
    {
        return dynamic_cast<StandbyAssignments*>(this->getChildObject("standbyAssignments"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/standbyAssignments
     */
    void Component::addStandbyAssignments(SAFplusAmf::StandbyAssignments *standbyAssignmentsValue)
    {
        this->addChildObject(standbyAssignmentsValue, "standbyAssignments");
    };

    /*
     * XPATH: /SAFplusAmf/Component/instantiate
     */
    SAFplusAmf::Instantiate* Component::getInstantiate()
    {
        return dynamic_cast<Instantiate*>(this->getChildObject("instantiate"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/instantiate
     */
    void Component::addInstantiate(SAFplusAmf::Instantiate *instantiateValue)
    {
        this->addChildObject(instantiateValue, "instantiate");
    };

    /*
     * XPATH: /SAFplusAmf/Component/terminate
     */
    SAFplusAmf::Terminate* Component::getTerminate()
    {
        return dynamic_cast<Terminate*>(this->getChildObject("terminate"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/terminate
     */
    void Component::addTerminate(SAFplusAmf::Terminate *terminateValue)
    {
        this->addChildObject(terminateValue, "terminate");
    };

    /*
     * XPATH: /SAFplusAmf/Component/cleanup
     */
    SAFplusAmf::Cleanup* Component::getCleanup()
    {
        return dynamic_cast<Cleanup*>(this->getChildObject("cleanup"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/cleanup
     */
    void Component::addCleanup(SAFplusAmf::Cleanup *cleanupValue)
    {
        this->addChildObject(cleanupValue, "cleanup");
    };

    /*
     * XPATH: /SAFplusAmf/Component/timeouts
     */
    SAFplusAmf::Timeouts* Component::getTimeouts()
    {
        return dynamic_cast<Timeouts*>(this->getChildObject("timeouts"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/timeouts
     */
    void Component::addTimeouts(SAFplusAmf::Timeouts *timeoutsValue)
    {
        this->addChildObject(timeoutsValue, "timeouts");
    };

    /*
     * XPATH: /SAFplusAmf/Component/restartCount
     */
    SAFplusAmf::RestartCount* Component::getRestartCount()
    {
        return dynamic_cast<RestartCount*>(this->getChildObject("restartCount"));
    };

    /*
     * XPATH: /SAFplusAmf/Component/restartCount
     */
    void Component::addRestartCount(SAFplusAmf::RestartCount *restartCountValue)
    {
        this->addChildObject(restartCountValue, "restartCount");
    };

    Component::~Component()
    {
    };

}
/* namespace SAFplusAmf */