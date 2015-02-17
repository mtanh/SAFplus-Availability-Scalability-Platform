#pragma once
#include <string>
#include <clGlobals.hxx>
#include <clDbg.hxx>
#include <saAis.h>


namespace SAFplus
{

enum
  {
    VersionMajor = 7,
    VersionMinor = 0,
    VersionBugfix = 0,
  };

/** printf but for std::string */
std::string strprintf(const std::string fmt_str, ...);

// All statements that begin with "dbg" are NO OPERATION in production code.
#ifdef CL_DEBUG
  inline void dbgAssert(bool x) { assert(x); }
#else
  inline void dbgAssert(bool x) {}
#endif


  /**
   *  Version array entry stored by a client library that describes what
   *  versions are supported by the client library implementation.
   */
  typedef struct ClVersionDatabase
  {
    ClInt32T        versionCount;   /* Number of versions listed as supported */
    ClVersionT *versionsSupported;  /* Versions supported by implementation */
  } ClVersionDatabaseT;

  /**
******************************************************************************
*  \par Synopsis:
*
*  Verifies if given version is compatible with client.
*
*  \par Description:
*  This API checks if the given version is compatible with the versions
*  described in the version database of the client.
*
*  FIXME: The actual description of the algorithm is provided in the SA
*  FORUM AIS specifications.  We should copy that text here.
*
*  \param versionDatabase: Pointer to the version database that contains
*  an array of versions supported by the library.
*
*  \param version: The version to be checked against the version database for
*  compatibility.
*
*  \retval CL_OK: The API executed successfully, the returned handle is valid.
*  \retval CL_ERR_NO_MEMORY: Memory allocation failure.
*  
*  \note
*  Returned error is a combination of the component id and error code.
*  Use \c CL_GET_ERROR_CODE(RET_CODE) defined in clCommonErrors.h to get the error code.
*
*/
  extern bool clVersionVerify (ClVersionDatabaseT *versionDatabase, ClVersionT *version);

  ClBoolT clIsProcessAlive(ClUint32T pid); 
  ClBoolT clParseEnvBoolean(const char* envvar);
  inline bool parseEnvBoolean(const char* envvar) { return clParseEnvBoolean(envvar); }

  ClCharT *clParseEnvStr(const char* envvar);
  inline char* parseEnvStr(const char* envvar) { return clParseEnvStr(envvar); }

  /** \brief Generic callback function object
      \par Synopsis:
      This class is used throughout the SAFplus APIs whenever SAFplus
      functions need to call out to application code.
      Since thread mutexes and semaphores are Wakeable, APIs can
      implement either blocking or callback semantics by simply
      calling Wakeable::wake()
   */
  class Wakeable
  {
  public:
    virtual void wake(int amt,void* cookie=NULL) = 0;

    //static Wakeable& Synchronous;  // This const is a reference to NULL and simply indicates that the function should be synchronous instead of async.
  };

  class WakeableNoop:public Wakeable
  {
  public:
   virtual void wake(int amt,void* cookie=NULL) {};
  };

  extern WakeableNoop IGNORE;
  extern Wakeable& BLOCK;  // This const is a reference to NULL and simply indicates that the function should be synchronous instead of async.
  extern Wakeable& ABORT;  // This const is a reference to 1 and indicates that the function should throw/return an error rather than block.

  /** This class allows you to allocate something on the heap that is
   * automatically deleted when this variable goes out of scope
   */
  class ScopedAllocation
    {
    public:
    void *memory;
    void* operator = (void* o) { memory = o; }
    operator  void* () const { return memory; } 
    ScopedAllocation(void* o=NULL) {memory = o; }
    ScopedAllocation(unsigned long int count) { memory = malloc(count); }
    ~ScopedAllocation() { if (memory) free(memory); memory=NULL; }
    };

  /** \brief  Load the SaNameT structure.
      \param  name The structure you want to load
      \param  str  The value to be put into the SaNameT structure

      If str is too long, then this function will ASSERT in debug mode, and crop in production mode 
  */
  void saNameSet(SaNameT* name, const char* str);
  //void saNameSet(SaNameT* name, const std::string& str) { saNameSet(name,(const char*) str.c_str()); }

  /** \brief  Load the str from a SaNameT structure.
      \param  name The string you want to read.
      \param  str  The destination char* array
      \param  maxLen The length of the available memory buffer. String
      will be a max length of maxLen-1 to account for the null terminator.

      If str is too long, then this function will ASSERT in debug mode, and crop in production mode 
  */
  void saNameGet(char* str,const SaNameT* name, uint_t maxLen);

  /** \brief  Load the SaNameT structure.
      \param  name The structure you want to load
      \param  name The structure to be put into the SaNameT structure

      If length is too long, then this function will ASSERT in debug mode, and crop in production mode 
  */
  void saNameCopy(SaNameT* nameOut, const SaNameT *nameIn);

  /** \brief  Join SaNameT structures
      \param  nameOut The result
      \param  prefix The beginning string.  Pass NULL if there is no beginning
      \param  separator The middle string. Pass NULL for no separator
      \param  suffix The ending string. Pass NULL for no ending

      If the sum of the lengths of the prefix, separator, and suffix is too long, the function will crop.
  */
  void saNameConcat(SaNameT* nameOut, const SaNameT *prefix, const char* separator, const SaNameT *suffix);


  /* Initialize SAFplus utilities, including global variables */
  void utilsInitialize();

  enum class ComponentId  /* also used as the IOC port */
  {
    Checkpoint = 0x20,
  };
  
  enum class MsgProtocols
  {
    Checkpoint = 0x20,
  };

  class Error: public std::exception
  {
  public:

  typedef enum
  {
    SAF_ERROR        = 0,
    SAFPLUS_ERROR    = 1,
    SYSTEM_ERROR     = 2
  } ErrorFamily;

  const char* errStr;
  const char* file;
  int          line;  
  unsigned int saError;  // SAF error code (if applicable)
  unsigned int clError;  // OpenClovis error code (if applicable)
  unsigned int osError;  // Operating system error code (i.e errno), if applicable

  enum  // OpenClovis Error codes defined here
    {
    UNKNOWN=0,
    NOT_IMPLEMENTED=1,

    // For simplicity put derived class error categories here
    PROCESS_ERRORS = 1000
    };

    Error(const char* str): errStr(str) 
    {
    }

    Error(ErrorFamily family, unsigned int returnCode,const char* str = NULL,const char* filep = __FILE__, int linep = __LINE__): errStr(str) 
    {
    clError = 0;
    saError = 0;
    osError = 0;
    file     = filep;
    line     = linep;
    if (family == SAF_ERROR) saError = returnCode;
    if (family == SAFPLUS_ERROR) clError = returnCode;
    if (family == SYSTEM_ERROR) osError = returnCode;
    }

    virtual const char* what() const throw()
    {
      return errStr;
    }
  };
  
  extern SaVersionT safVersion;
};  
