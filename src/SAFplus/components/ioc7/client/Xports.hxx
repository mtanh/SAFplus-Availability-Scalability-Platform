/* 
 * File Xports.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#ifndef XPORTS_HXX_
#define XPORTS_HXX_

#include <map>
#include "Xport.hxx"
#include "clMgtObject.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include <string>

namespace SAFplusMsgServer {

    class Xports : public ClMgtObject {

        /* Apply MGT object factory */
        REGISTER(Xports);

    public:

    public:
        Xports();
        std::vector<std::string> *getChildNames();

        /*
         * XPATH: /SAFplusMsgServer/xports/xport
         */
        Xport* getXport(std::string typeValue);

        /*
         * XPATH: /SAFplusMsgServer/xports/xport
         */
        void addXport(Xport *xportValue);

        /*
         * XPATH: /SAFplusMsgServer/xports/xport
         */
        void addXport(std::string typeValue);
        ~Xports();

    };
}
/* namespace SAFplusMsgServer */
#endif /* XPORTS_HXX_ */
