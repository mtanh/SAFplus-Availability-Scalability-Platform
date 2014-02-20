/* 
 * File StreamConfig.cxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#include <map>
#include "clMgtObject.hxx"
#include "Stream.hxx"
#include <vector>
#include "MgtFactory.hxx"
#include <string>
#include "StreamConfig.hxx"

using namespace std;

namespace SAFplusLog {

    /* Apply MGT object factory */
    REGISTERIMPL(StreamConfig, /SAFplusLog/StreamConfig)

    StreamConfig::StreamConfig(): ClMgtObject("StreamConfig") {
    };

    vector<string> *StreamConfig::getChildNames() {
        string childNames[] = { "stream" };
        return new vector<string> (childNames, childNames + sizeof(childNames) / sizeof(childNames[0]));
    };

    /*
     * XPATH: /SAFplusLog/StreamConfig/stream
     */
    Stream* StreamConfig::getStream(string nameValue) {
        map<string, vector<ClMgtObject*>* >::iterator mapIndex = mChildren.find("stream");
        /* Check if MGT module already exists in the database */
        if (mapIndex != mChildren.end()) {
            vector<ClMgtObject*> *objs = (vector<ClMgtObject*>*) (*mapIndex).second;
            for (unsigned int i = 0; i < objs->size(); i++) {
                ClMgtObject* childObject = (*objs)[i];
                if (((Stream*)childObject)->getName() == nameValue) {
                    return (Stream*)childObject;
                }
            }
        }
        return NULL;
    };

    /*
     * XPATH: /SAFplusLog/StreamConfig/stream
     */
    void StreamConfig::addStream(Stream *streamValue) {
        this->addChildObject(streamValue, "stream");
    };

    /*
     * XPATH: /SAFplusLog/StreamConfig/stream
     */
    void StreamConfig::addStream(string nameValue) {
        Stream *objstream = new Stream(nameValue);
        this->addChildObject(objstream, "stream");
    };

    StreamConfig::~StreamConfig() {
    };

}
/* namespace SAFplusLog */
