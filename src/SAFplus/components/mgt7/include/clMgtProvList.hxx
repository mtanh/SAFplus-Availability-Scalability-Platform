/*
 * Copyright (C) 2002-2013 OpenClovis Solutions Inc.  All Rights Reserved.
 *
 * This file is available  under  a  commercial  license  from  the
 * copyright  holder or the GNU General Public License Version 2.0.
 *
 * The source code for  this program is not published  or otherwise
 * divested of  its trade secrets, irrespective  of  what  has been
 * deposited with the U.S. Copyright office.
 *
 * This program is distributed in the  hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied  warranty  of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * For more  information, see  the file  COPYING provided with this
 * material.
 */

/**
 *  \file
 *  \brief Header file of the ClMgtProvList class which provides APIs to manage "provisioned" objects
 *  \ingroup mgt
 */

/**
 *  \addtogroup mgt
 *  \{
 */

#ifndef CLMGTPROVLIST_HXX_
#define CLMGTPROVLIST_HXX_

#include "clMgtObject.hxx"

#include <typeinfo>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>

namespace SAFplus
{
/*
 *
 */
template <class T>
class ProvListOperation;

template<class T>
class ClMgtProvList: public ClMgtObject
{
public:
    /**
     *  Value of the "ClMgtProv" object
     */
    std::vector<T> Value;
    ProvListOperation<T> *mOpt;

public:
    ClMgtProvList(const char* name);

    virtual ~ClMgtProvList();

    virtual void toString(std::stringstream& xmlString);

    /**
     * \brief   Virtual function to validate object data
     */
    virtual ClBoolT
    set(const void *pBuffer, ClUint64T buffLen, SAFplus::Transaction& t);

    /**
     * \brief   Virtual function to validate object data; throws transaction exception if fails
     */
    virtual void xset(const void *pBuffer, ClUint64T buffLen, SAFplus::Transaction& t);
  
    std::string toStringItemAt(T &x);

    // Overload PointList stream insertion operator
    inline friend std::ostream & operator<<(std::ostream &os, const ClMgtProvList &b)
    {
        copy(b.Value.begin(), b.Value.end(), std::ostream_iterator<T>(b));
        return os;
    }

    // Overload PointList stream extraction operator
    inline friend std::istream & operator>>(std::istream &is, const ClMgtProvList &b)
    {
        copy(std::istream_iterator<T>(is), std::istream_iterator<T>(), std::back_inserter(b));
        return is;
    }

    virtual std::vector<std::string> *getChildNames();

    /**
     * \brief   Function to set data to database
     */
    ClRcT setDb();

    /**
     * \brief   Function to get data from database
     */
    ClRcT getDb();

    void pushBackValue(const std::string& strVal);
};

template <class T>
class ProvListOperation : public SAFplus::TransactionOperation
{
protected:
    ClMgtProvList<T> *mOwner;
    std::vector<void *> mData;

public:
    ProvListOperation()
    {
        mOwner = NULL;
    }
    void setOwner(ClMgtProvList<T> *owner);
    void addData(void *data, ClUint64T buffLen);
    virtual bool validate(SAFplus::Transaction& t);
    virtual void commit();
    virtual void abort();
};

template <class T>
void ProvListOperation<T>::setOwner(ClMgtProvList<T> *owner)
{
    mOwner = owner;
}

template <class T>
void ProvListOperation<T>::addData(void *data, ClUint64T buffLen)
{
    void *tempData = (void *) malloc (buffLen);

    if(!tempData) return;

    memcpy(tempData, data, buffLen);
    mData.push_back(tempData);
}

template <class T>
bool ProvListOperation<T>::validate(SAFplus::Transaction& t)
{
    if ((!mOwner) || (mData.size() == 0))
        return false;

    return true;
}

template <class T>
void ProvListOperation<T>::commit()
{
    if ((!mOwner) || (mData.size() == 0))
        return;

    mOwner->Value.clear();

    for(unsigned int i = 0; i < mData.size(); i++)
    {
        mOwner->pushBackValue((char *)mData[i]);
        free(mData[i]);
    }

    mOwner->setDb();
    mOwner->mOpt = NULL;
    mData.clear();
}

template <class T>
void ProvListOperation<T>::abort()
{
    if ((!mOwner) || (mData.size() == 0))
        return;

    for(unsigned int i = 0; i < mData.size(); i++)
    {
        free(mData[i]);
    }

    mOwner->mOpt = NULL;
    mData.clear();
}

template<class T>
ClMgtProvList<T>::ClMgtProvList(const char* name) :
        ClMgtObject(name)
{
    mOpt = NULL;
}

template<class T>
ClMgtProvList<T>::~ClMgtProvList()
{
}
template<class T>
std::string ClMgtProvList<T>::toStringItemAt(T &x)
{
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template<class T>
void ClMgtProvList<T>::toString(std::stringstream& xmlString)
{
    getDb();
    for (unsigned int i = 0; i < Value.size(); i++)
    {
        xmlString << "<" << Name << ">" << toStringItemAt(Value.at(i)) << "</" << Name << ">";
    }
}

template<class T> void ClMgtProvList<T>::xset(const void *pBuffer, ClUint64T buffLen, SAFplus::Transaction& t)
{
  if (!set(pBuffer,buffLen,t)) throw SAFplus::TransactionException(t);
}

template<class T>
ClBoolT ClMgtProvList<T>::set(const void *pBuffer, ClUint64T buffLen,
        SAFplus::Transaction& t)
{
    const xmlChar *valstr, *namestr;
    int ret;
    bool addOpt = false;

    xmlTextReaderPtr reader = xmlReaderForMemory((const char*) pBuffer, buffLen,
            NULL, NULL, 0);

    if (reader != NULL)
    {
        ret = xmlTextReaderRead(reader);
        while (ret)
        {
            namestr = xmlTextReaderConstName(reader);

            if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
                    && !strcmp((const char*) namestr, Name.c_str()))
            {
                ret = xmlTextReaderRead(reader);
                if (ret && xmlTextReaderHasValue(reader)
                        && !xmlTextReaderIsEmptyElement(reader))
                {
                    valstr = xmlTextReaderConstValue(reader);
                    if (!mOpt)
                    {
                        mOpt = new ProvListOperation<T>;
                        mOpt->setOwner(this);
                        addOpt = true;
                    }

                    mOpt->addData((void *)valstr, strlen((char *)valstr) + 1);
                }
            }
            ret = xmlTextReaderRead(reader);
        }
        xmlFreeTextReader(reader);
    }

    if (!mOpt)
        return CL_FALSE;

    if (addOpt)
        t.addOperation(mOpt);

    return mOpt->validate(t);
}

template<class T>
void ClMgtProvList<T>::pushBackValue(const std::string& strVal)
{
    T value;

    deXMLize(strVal,this,value); 

    Value.push_back(value);
}

/*
 * List-leaf doesn't have children
 */
template <class T>
std::vector<std::string> *ClMgtProvList<T>::getChildNames()
{
    return NULL;
}

template <class T>
ClRcT ClMgtProvList<T>::setDb()
{
    ClRcT rc = CL_OK;
    std::string key = getFullXpath();

    ClMgtDatabase *db = ClMgtDatabase::getInstance();
    if(!db->isInitialized())
    {
        return CL_ERR_NOT_INITIALIZED;
    }

    std::vector<std::string> iter = db->iterate(key);

    int updateCount = (iter.size() < Value.size()) ? iter.size() : Value.size();

    for (int i = 1; i <= updateCount; i++)
    {
        std::string itemkey = "";
        std::stringstream s;
        s << i;
        itemkey.append(key).append("[").append(s.str()).append("]");
        if (!db->setRecord(itemkey, toStringItemAt(Value.at(i-1))))
        {
            db->insertRecord(itemkey, toStringItemAt(Value.at(i-1)));
        }
    }

    if (iter.size() < Value.size())
    {
        for (int i = iter.size() + 1; i <= Value.size(); i++)
        {
            std::string itemkey = "";
            std::stringstream s;
            s << i;
            itemkey.append(key).append("[").append(s.str()).append("]");
            db->insertRecord(itemkey, toStringItemAt(Value.at(i-1)));
        }
    }
    else
    {
        for (int i = Value.size() + 1; i <= iter.size(); i++)
        {
            std::string itemkey = "";
            std::stringstream s;
            s << i;
            itemkey.append(key).append("[").append(s.str()).append("]");
            db->deleteRecord(itemkey);
        }
    }

    return rc;
}

template <class T>
ClRcT ClMgtProvList<T>::getDb()
{
    ClRcT rc = CL_OK;
    std::string key = getFullXpath();

    ClMgtDatabase *db = ClMgtDatabase::getInstance();
    if(!db->isInitialized())
    {
        return CL_ERR_NOT_INITIALIZED;
    }

    std::vector<std::string> iter = db->iterate(key);

    Value.clear();
    for (std::vector<std::string>::iterator it=iter.begin(); it!=iter.end(); it++)
    {
        std::string value;
        if (db->getRecord(*it, value))
        {
          //          T value;
          // destore(rec,this,&value); 
          this->pushBackValue(value);
        }
    }

    return rc;
}
};
#endif /* CLMGTPROVLIST_HXX_ */
