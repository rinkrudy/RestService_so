#include "Generator.h"

Generator::Generator()
{

}
Generator::~Generator()
{
    
}


void Generator::Set_Json(web::json::array &dstArray, std::vector<DB_Generator> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_Generator &info = srcVector.at(0);
        VSETJSON_I(sNo);
        VSETJSON_I(sCount);
        VSETJSON_S(szCFW_HighTemp_Trip);
        VSETJSON_S(szLO_LowPress_Trip);
        VSETJSON_S(szOverSpeed_Trip);
        VSETJSON_S(szCommon_Trip);
        VSETJSON_S(szSpeedSensorFail_Trip);
        VSETJSON_S(szStartFail);
        VSETJSON_S(szCommonShutdown);

    }

}


void Generator::Set_Struct(std::vector<DB_Generator> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();
    destVector.clear();
    destVector.resize(nArraySize);




    for(int i = 0; i < nArraySize; i++)
    {
        DB_Generator &info = destVector.at(i);

        VFIELD_I(sNo);
        VFIELD_I(sCount);
        VFIELD_S(szCFW_HighTemp_Trip);
        VFIELD_S(szLO_LowPress_Trip);
        VFIELD_S(szOverSpeed_Trip);
        VFIELD_S(szCommon_Trip);
        VFIELD_S(szSpeedSensorFail_Trip);
        VFIELD_S(szStartFail);
        VFIELD_S(szCommonShutdown);

    }
}
