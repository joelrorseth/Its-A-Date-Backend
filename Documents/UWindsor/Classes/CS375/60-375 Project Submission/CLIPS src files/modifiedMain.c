#include "clips.h"

int main()
{
    void *theEnv;
    DATA_OBJECT iterate;
    void *theInstance;
    
    theEnv = CreateEnvironment();
    EnvReset(theEnv);
    EnvLoad(theEnv, "./Env/functionsmore.clp");
    //EnvLoad(theEnv, "./Env/template4single.clp");
    EnvLoad(theEnv, "./Env/rules1more.clp");
    EnvLoadFacts(theEnv, "morefacts.clp");
    EnvSaveFacts(theEnv, "factsBefore.txt", LOCAL_SAVE);
    EnvRun(theEnv, -1); // second number is how many rules will fire, negative means indefinite.
    //EnvSave(theEnv, "theEnv.txt");
    EnvSaveFacts(theEnv, "factsAfter.txt", LOCAL_SAVE);
    
    
}