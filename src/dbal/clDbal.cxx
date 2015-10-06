#include <clCommon.hxx>
#include <clDbalBase.hxx>

namespace SAFplusI
{
  SAFplus::DbalPlugin* defaultDbalPlugin = NULL;
};

namespace SAFplus
{
  void clDbalInitialize(void)
  {    
    //? This environment variable specifies which dbal plugin should be used.
    const char* dbalFile = getenv("SAFPLUS_DB_PLUGIN");
    if (!dbalFile)
    {
      dbalFile = SAFplusI::defaultDbalPluginFile;
    }

    ClPlugin* api = NULL;

#ifdef SAFPLUS_DBAL_DIRECTLY_LINKED
    api  = clPluginInitialize(SAFplus::CL_DBAL_PLUGIN_VER);
#else
    ClPluginHandle* plug = clLoadPlugin(SAFplus::CL_DBAL_PLUGIN_ID,SAFplus::CL_DBAL_PLUGIN_VER,dbalFile);
    if (plug) api = plug->pluginApi;
    else
    {
      assert(!"Cannot load dbal plugin");
    }
#endif

    if (api)
    {
      DbalPlugin* dp = dynamic_cast<DbalPlugin*> (api);
      if (dp) 
      {      
        SAFplusI::defaultDbalPlugin = dp;
        logInfo("DBAL","INI","Dbal plugin [%s] initialized.", dp->type);      
      }    
      else
      {
        assert(!"bad plugin");
      }
    }
    else
    {
      assert(!"bad plugin");
    }
  }
};
