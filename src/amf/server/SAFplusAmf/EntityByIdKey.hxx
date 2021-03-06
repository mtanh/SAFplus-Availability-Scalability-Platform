#pragma once 
#ifndef __ENTITYBYIDKEY_HXX__
#define __ENTITYBYIDKEY_HXX__

#include <iostream>
#include <sstream>
#include <map>

namespace SAFplusAmf
{
  class EntityByIdKey {

    public:
      ::uint16_t id;

      /* default constructor/destructor */
      EntityByIdKey();
      ~EntityByIdKey();

      EntityByIdKey(::uint16_t idValue);

      /* building an instance from string list */
      void build(std::map<std::string,std::string> &keyList);

      /* key xpath: [@key1="value1" and @key2="value2" and ...] */
      std::string toXpath() const;

      /* xml string: <interface key1="value1" key2="value2"></interface> */
      std::string toString() const;

      /* Serialize keys */
      std::string str() const;

      friend std::ostream& operator<<(std::ostream& out, const EntityByIdKey &value);

      /* compare hash key */
      inline bool operator<(const EntityByIdKey &rhs) const
      {
        /* TODO: implement by user */
        return true;
      }

  };
}
/* namespace SAFplusAmf */
#endif /* ENTITYBYIDKEY_HXX_ */
