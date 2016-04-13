/* 
 * File StreamAttributes.hxx
 * This file has been auto-generated by Y2CPP, the
 * plug-in of pyang.
 */ 

#pragma once
#ifndef STREAMATTRIBUTES_HXX_
#define STREAMATTRIBUTES_HXX_

#include "FileFullAction.hxx"
#include "SAFplusLogCommon.hxx"
#include "clMgtContainer.hxx"
#include "clTransaction.hxx"
#include "Replicate.hxx"
#include <string>
#include "clMgtProv.hxx"
#include <cstdint>
#include <vector>
#include "StreamScope.hxx"

namespace SAFplusLog
  {

    class StreamAttributes : public SAFplus::MgtContainer {
    public:

        /*
         * Name of the stream
         */
        SAFplus::MgtProv<std::string> name;

        /*
         * Output file name
         */
        SAFplus::MgtProv<std::string> fileName;

        /*
         * Replicate this log to other nodes/processes
         */
        SAFplus::MgtProv<::SAFplusLog::Replicate> replicate;

        /*
         * Node and directory where the file is to be output
         */
        SAFplus::MgtProv<std::string> fileLocation;

        /*
         * Maximum size of a log file
         */
        SAFplus::MgtProv<::uint64_t> fileUnitSize;

        /*
         * Maximum size of a single log record
         */
        SAFplus::MgtProv<::uint64_t> recordSize;

        /*
         * Action to take when the log file is full
         */
        SAFplus::MgtProv<::SAFplusLog::FileFullAction> fileFullAction;

        /*
         * If fileFullAction is ROTATE, this field indicates the number of files to rotate.
         */
        SAFplus::MgtProv<::uint32_t> maximumFilesRotated;

        /*
         * When this number of logs are available in shared memory, the log server is triggered to output them.  This field controls how often logs are posted during heavy log use.
         */
        SAFplus::MgtProv<::uint32_t> flushFreq;

        /*
         * The log server wakes up every flushInterval ms and outputs all logs in shared memory.  This field therefore defines the maximum age of unposted logs during light log use.
         */
        SAFplus::MgtProv<::uint64_t> flushInterval;

        /*
         * Should these logs be output to syslog
         */
        SAFplus::MgtProv<bool> syslog;

        /*
         * Is this log stream available across the entire cluster, or just available on the node?
         */
        SAFplus::MgtProv<::SAFplusLog::StreamScope> streamScope;

    public:
        StreamAttributes();
        std::vector<std::string>* getChildNames();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/name
         */
        std::string getName();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/name
         */
        void setName(std::string nameValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileName
         */
        std::string getFileName();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileName
         */
        void setFileName(std::string fileNameValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/replicate
         */
        ::SAFplusLog::Replicate getReplicate();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/replicate
         */
        void setReplicate(::SAFplusLog::Replicate &replicateValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileLocation
         */
        std::string getFileLocation();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileLocation
         */
        void setFileLocation(std::string fileLocationValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileUnitSize
         */
        ::uint64_t getFileUnitSize();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileUnitSize
         */
        void setFileUnitSize(::uint64_t fileUnitSizeValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/recordSize
         */
        ::uint64_t getRecordSize();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/recordSize
         */
        void setRecordSize(::uint64_t recordSizeValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileFullAction
         */
        ::SAFplusLog::FileFullAction getFileFullAction();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/fileFullAction
         */
        void setFileFullAction(::SAFplusLog::FileFullAction &fileFullActionValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/maximumFilesRotated
         */
        ::uint32_t getMaximumFilesRotated();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/maximumFilesRotated
         */
        void setMaximumFilesRotated(::uint32_t maximumFilesRotatedValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/flushFreq
         */
        ::uint32_t getFlushFreq();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/flushFreq
         */
        void setFlushFreq(::uint32_t flushFreqValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/flushInterval
         */
        ::uint64_t getFlushInterval();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/flushInterval
         */
        void setFlushInterval(::uint64_t flushIntervalValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/syslog
         */
        bool getSyslog();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/syslog
         */
        void setSyslog(bool syslogValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);

        /*
         * XPATH: /SAFplusLog/StreamAttributes/streamScope
         */
        ::SAFplusLog::StreamScope getStreamScope();

        /*
         * XPATH: /SAFplusLog/StreamAttributes/streamScope
         */
        void setStreamScope(::SAFplusLog::StreamScope &streamScopeValue, SAFplus::Transaction &txn=SAFplus::NO_TXN);
        ~StreamAttributes();

    };
}
/* namespace ::SAFplusLog */
#endif /* STREAMATTRIBUTES_HXX_ */
