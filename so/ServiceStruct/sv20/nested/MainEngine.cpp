#include "MainEngine.h"

MainEngine::MainEngine()
{

}
MainEngine::~MainEngine()
{
    
}


void MainEngine::Set_Json(web::json::array &dstArray, std::vector<DB_MainEngine> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_MainEngine &info = srcVector.at(0);
        VSETJSON_S(szShutdown);
        VSETJSON_S(szSlowdown);
        VSETJSON_B(bUseRpm1);
        VSETJSON_B(bUseRpm2);
        VSETJSON_I(dRpm1);
        VSETJSON_I(dRpm2);


    }

}


void MainEngine::Set_Struct(std::vector<DB_MainEngine> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();
    destVector.clear();
    destVector.resize(nArraySize);




    for(int i = 0; i < nArraySize; i++)
    {
        DB_MainEngine &info = destVector.at(i);

        VFIELD_S(szShutdown);
        VFIELD_S(szSlowdown);
        VFIELD_B(bUseRpm1);
        VFIELD_B(bUseRpm2);
        VFIELD_D(dRpm1);
        VFIELD_D(dRpm2);

    }
}
