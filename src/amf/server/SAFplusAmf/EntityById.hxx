/* 
 * File EntityById.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef ENTITYBYID_HXX_
#define ENTITYBYID_HXX_
#include "SAFplusAmfCommon.hxx"

#include <string>
#include "clTransaction.hxx"
#include "clMgtProv.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include "clMgtContainer.hxx"
#include <cstdint>

namespace SAFplusAmf
  {

    class EntityById : public SAFplus::MgtContainer {

        /* Apply MGT object factory */
        MGT_REGISTER(EntityById);

    public:
        SAFplus::MgtProv<::uint16_t> id;
        SAFplus::MgtProv<std::string> entity;

    public:
        EntityById();
        EntityById(::uint16_t idValue);
        std::vector<std::string> getKeys();
        std::vector<std::string>* getChildNames();

        /*
         * XPATH: /SAFplusAmf/EntityById/id
         */
        ::uint16_t getId();

        /*
         * XPATH: /SAFplusAmf/EntityById/id
         */
        void setId(::uint16_t idValue, SAFplus::Transaction &t=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusAmf/EntityById/entity
         */
        std::string getEntity();

        /*
         * XPATH: /SAFplusAmf/EntityById/entity
         */
        void setEntity(std::string entityValue, SAFplus::Transaction &t=SAFplus::NO_TXN);
        ~EntityById();

    };
}
/* namespace SAFplusAmf */
#endif /* ENTITYBYID_HXX_ */