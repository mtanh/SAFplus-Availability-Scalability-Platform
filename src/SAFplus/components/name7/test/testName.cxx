#include <clCommon.hxx>
#include <clLogApi.hxx>
#include <clGlobals.hxx>
#include <clNameApi.hxx>
#include <stdio.h>
#include <clTestApi.hxx>

#define __THREAD
#undef __THREAD

using namespace SAFplus;

class ObjTest
{
private:
   std::string nm;
public:
   ObjTest(const char* name){
      nm = name;
   }
   std::string& getName()
   {
      return nm;
   }
   void greet(){
      printf("%s greets from ObjTest\n", nm.c_str());
   }       
};

typedef struct {
   char name[100];
   NameRegistrar::MappingMode mm;
   uint32_t idx;
   uint32_t proc;
   uint32_t node;
   void* obj;
}Params;

typedef std::map<std::string, SAFplus::Handle> TheMap;
TheMap theMap;

void testNameSetGet(const char* n, NameRegistrar::MappingMode m, uint32_t idx, void* obj = NULL, uint32_t process=0xffffffff, uint32_t node=0xffff)
{
   Handle h(PointerHandle, idx, process, node);   
   name.set(n, h, m);
   name.setLocalObject(n,obj);
   theMap[n] = h;
   try {
     SAFplus::Handle& oh = name.getHandle(n);
     clTest(("Handle got "), oh == h, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
   }catch (NameException &ne) {
      clTest(("Handle get unexpected exception"), 0, ("exception [%s]", ne.what()));
   }
   try {
     SAFplus::Handle& oh = name.getHandle("blah");
     clTest(("Unexpected handle got"), 0, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
   }catch (NameException &ne) {
      clTest(("Handle get expected exception because of non-existence"), 1, ("exception [%s]", ne.what()));
   }   
}

void testNameAppend(const char* n, NameRegistrar::MappingMode m, uint32_t idx, void* obj = NULL, uint32_t process=0xffffffff, uint32_t node=0xffff)
{
   Handle h(PointerHandle, idx, process, node);
   Handle h2(PointerHandle, idx+1, process, node);
   name.append(n,h,m); 
   name.append(n,h2,m);  
   
   try {
     SAFplus::Handle& oh = name.getHandle(n);    
     if (m == NameRegistrar::MODE_REDUNDANCY)
     {
        SAFplus::Handle firstHdl = theMap[n];
        clTest(("Handle got "), oh == firstHdl, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
     }
     else if (m == NameRegistrar::MODE_PREFER_LOCAL)
     {
        if (process != 0xffffffff || node != 0xffff)
        {
           clTest(("Handle got "), oh == h, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
        }
        else
        {
           clTest(("Handle got "), oh == h2, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
        }
     }
   }catch (NameException &ne) {
      clTest(("Handle get unexpected exception"), 0, ("exception [%s]", ne.what()));
   }
   try {
     SAFplus::Handle& oh = name.getHandle("blah");
     clTest(("Invalid handle got"), 0, ("Handle got [0x%lx.0x%lx]", oh.id[0],oh.id[1]));
   }catch (NameException &ne) {     
      clTest(("Handle get expected exception because of non-existence"), 1, ("exception [%s]", ne.what()));    
   }   
}

void objectGet(const char* n, const char* objName)
{
   try {
     RefObjMapPair ho = name.get(n);
     ObjTest* po = (ObjTest*)ho.second;
     clTest(("Object got "), (po != NULL && !po->getName().compare(objName)), ("Actual object [%s]", po->getName().c_str()));
   }catch (NameException &ne) {
      clTest(("Object get unexpected exception"), 0, ("exception [%s]", ne.what())); 
   }
}

void arbitraryDataSet(const char* n, void* data, int len, bool failureCase)
{
   try {
      name.set(n, data, len);            
   }catch (NameException &ne) {
      clTest(("Arbitrary data setting unexpected exception"), !failureCase, ("exception [%s]", ne.what())); 
   }
}

void arbitraryDataSet(const char* n, SAFplus::Buffer* pdata, bool failureCase)
{
   try {
      name.set(n, pdata);
   }catch (NameException &ne) {
      clTest(("Arbitrary data setting unexpected exception"), !failureCase, ("exception [%s]", ne.what())); 
   }
}

void arbitraryDataGet(const char* n, const char* dataToCompare, bool failureCase)
{
   try {
      const SAFplus::Buffer& buf = name.getData(n);
      if (!failureCase)
         clTest(("Arbitrary data got "), (!memcmp(buf.data, dataToCompare, buf.len())), ("Actual arbitrary data got [%s]", buf.data));
      else
         clTest(("Invalid arbitrary data got "), (false), ("Actual arbitrary data got [%s]", buf.data));
   }catch (NameException &ne) {
      clTest(("Arbitrary data got unexpected exception"), !failureCase, ("exception [%s]", ne.what())); 
   }  
}

void* threadSetProc(void* p)
{
   Params* pr = (Params*)p;
   testNameSetGet(pr->name, pr->mm, pr->idx, pr->obj, pr->proc, pr->node);
   delete pr;
   return 0;
}

void* threadAppendProc(void* p)
{
   Params* pr = (Params*)p;
   testNameAppend(pr->name, pr->mm, pr->idx, pr->obj, pr->proc, pr->node);
   delete pr;
   return 0;
}

void threadNameSetGet(const char* n, NameRegistrar::MappingMode m, uint32_t idx, void* obj = NULL, uint32_t process=0xffffffff, uint32_t node=0xffff)
{
   Params* p = new Params;
   strcpy(p->name,n);
   p->mm = m;
   p->idx = idx;
   p->proc = process;
   p->node = node;
   p->obj = obj;
   pthread_t thid;
   pthread_create(&thid, NULL, threadSetProc, (void*)p);
   pthread_join(thid, NULL);
}

void threadNameAppendGet(const char* n, NameRegistrar::MappingMode m, uint32_t idx, void* obj = NULL, uint32_t process=0xffffffff, uint32_t node=0xffff)
{
   Params* p = new Params;
   strcpy(p->name,n);
   p->mm = m;
   p->idx = idx;
   p->proc = process;
   p->node = node;
   p->obj = obj;
   pthread_t thid;
   pthread_create(&thid, NULL, threadAppendProc, (void*)p);
   pthread_join(thid, NULL);
}


int main(int argc, char* argv[])
{
#ifndef __THREAD
#if 1
   logInitialize();
   logEchoToFd = 1;  // echo logs to stdout for debugging
   utilsInitialize();
   clTestGroupInitialize(("Test name set, append, get"));
   ObjTest* jim = new ObjTest("Jim");   
   //obj->greet();
   const char* name1 = "_name1";
   clTestCase(("Test name1 set, get"), testNameSetGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbcc, jim));
   clTestCase(("Test name1 append, get"), testNameAppend(name1, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbdd, jim));
   ObjTest* jane = new ObjTest("Jane");
   const char* name2 = "_name2";
   clTestCase(("Test name 2 set, get"), testNameSetGet(name2, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbce, jane));
   clTestGroupFinalize();

   name.dumpObj();
   clTestGroupInitialize(("Test object set, get"));   
   clTestCase(("Test setting object of name1"), objectGet(name1, "Jim"));   
   clTestCase(("Test setting object of name2"), objectGet(name2, "Jane"));   
   clTestGroupFinalize();

   clTestGroupInitialize(("Test arbitrary data set, get"));
   char data[120], data2[120];   
   strcpy(data, "This is arbitrary data example. Don't care its content");
   clTestCase(("Test setting of arbitrary data of name1"), arbitraryDataSet(name1, data, strlen(data)+1,false));
   strcpy(data2, "This is another arbitrary data example. Don't care its content!...");
   clTestCase(("Test setting of arbitrary data of name2"), arbitraryDataSet(name2, data2, strlen(data2)+1,false));
   clTestCase(("Test getting of arbitrary data of name1"), arbitraryDataGet(name1, data, false));   
   clTestCase(("Test getting of arbitrary data of name2"), arbitraryDataGet(name2, data2, false));
   
   //char modbuf[120];   
   char* modbuf = new char[120];
   strcpy(modbuf,"This is the modified buffer");
   size_t sz = strlen(modbuf)+sizeof(SAFplus::Buffer);
   char temp[sz];
   SAFplus::Buffer* pbuf = new(temp) SAFplus::Buffer(sz);
   *pbuf = modbuf;
   //clTestCase(("Test setting of arbitrary data of name1"), arbitraryDataSet(name1, pbuf, false));
   arbitraryDataSet(name1, pbuf, false);
   clTestCase(("Test getting of arbitrary data of name1"), arbitraryDataGet(name1, modbuf, false));   
   
#endif
   //char data[120];
   strcpy(data, "This is arbitrary data example. Don't care its content");
   clTestCase(("Test setting of arbitrary data of an invalid name"), arbitraryDataSet("aaa", data, strlen(data)+1, true));
   SAFplus::Buffer buf;
   clTestCase(("Test setting of arbitrary data of an invalid name"), arbitraryDataSet("aaa", &buf, true));   
   clTestGroupFinalize();
   delete jim;
   delete jane;
   delete []modbuf;
   clTestGroupFinalize();
// Test the case process or node failure
#if 0
   pid_t thispid = getpid();   
   const char* name3 = "_name3";
   testNameSetGet(name3, NameRegistrar::MODE_REDUNDANCY, 0xaabbe4, NULL);
   testNameAppend(name3, NameRegistrar::MODE_NO_CHANGE, 0xaabbe5, NULL);
   testNameAppend(name3, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbe7, NULL, (uint32_t)thispid);
   printf("----Dumpping the name service database---\n");
   name.dump();   
   //printf("---------process failed------------\n");
   //name.processFailed(thispid, 0);
   //name.dump();
   //const char* name3 = "_001000111";
   testNameAppend(name3, NameRegistrar::MODE_NO_CHANGE, 0xaabbe9, NULL, 0xffffffff, 2);
   name.dump();
   //printf("---------node failed------------\n");
   //name.nodeFailed(2, 0);
   
   const char* name4 = "_name4";
   testNameSetGet(name4, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbf6, NULL, (uint32_t)thispid);
   name.dump();
   //printf("---------process failed------------\n");
   //name.processFailed(thispid, 0);

   const char* name5 = "_name5";
   testNameSetGet(name5, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbf2, NULL, 0xffffffff, 2);
   name.dump();   
#endif   
   //printf("---------node failed------------\n");
   //name.nodeFailed(2, 0);
#else
   const char* name1 = "_name1";   
   threadNameSetGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbc1);
   uint32_t idx = 0xaabbc2;
   int i;
   for(i=0;i<30;i++) {
     threadNameAppendGet(name1, NameRegistrar::MODE_PREFER_LOCAL, idx);
     idx+=2;
   } 
   /*threadNameAppendGet(name1, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbc2);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbc4);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbc6);      
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbc8);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbca);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbcc);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbce);
   threadNameAppendGet(name1, NameRegistrar::MODE_ROUND_ROBIN, 0xaabbc6);*/
   const char* name2 = "_name2";   
   threadNameSetGet(name2, NameRegistrar::MODE_REDUNDANCY, 0xaabbe1);  
   idx=0xaabbe2;
   for(i=0;i<30;i++) {
     threadNameAppendGet(name2, NameRegistrar::MODE_ROUND_ROBIN, idx);     
     idx+=2;
   }   
   //threadNameAppendGet(name2, NameRegistrar::MODE_PREFER_LOCAL, 0xaabbec);
   //threadNameAppendGet(name2, NameRegistrar::MODE_REDUNDANCY, 0xaabbee);
#endif
   //printf("----Dumpping the name service database---\n");
   //name.dump(); 
   //while (1) { sleep(1);}  
   return 0;
}