#pragma once 
#ifndef NODE_HXX__ 
#define NODE_HXX__ 


namespace SAFplus 
{

class NodeKey {
  public:
    std::string myName; 

    NodeKey(){};

    NodeKey(std::string myNameVal)
    {
        myName = myNameVal;
    }

    bool operator<(const NodeKey &k2) const
    {
        return myName < k2.myName;
    }

    std::string str()
    {
        std::stringstream ss;
        ss << myName ;
        return ss.str(); 
    }

    void build(std::map<std::string,std::string> keyList)
    {
        std::map<std::string,std::string>::iterator iter; 

        iter = keyList.find("myName");
        if(iter != keyList.end())
        {
            myName = iter->second;
        }
    }
}; //end class
} //end namespace
#endif //NODE_HXX