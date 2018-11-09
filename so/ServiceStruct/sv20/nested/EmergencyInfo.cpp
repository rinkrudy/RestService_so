#include "EmergencyInfo.h"

EmergencyInfo::EmergencyInfo()
{

}
EmergencyInfo::~EmergencyInfo()
{
    
}


void EmergencyInfo::SetEmergencyInfo_Json(web::json::array &dstArray, std::vector<DB_EmergencyInfo> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_EmergencyInfo &info = srcVector.at(0);
        VSETJSON_S(szRunTime);
        VSETJSON_S(szFireSafetyCode);
        VSETJSON_S(szSeakeepingQualiyCode);
        VSETJSON_S(szNavigationSafetyCode);

        VSETJSON_I(nFireLevel);
        VSETJSON_I(nSeakeepingLevel);
        VSETJSON_I(nNavigationLevel);

    }

}


void EmergencyInfo::SetEmergencyInfo_Struct(std::vector<DB_EmergencyInfo> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();
    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_EmergencyInfo &info = destVector.at(i);

        VFIELD_S(szRunTime);
        VFIELD_I(nFireLevel);
        VFIELD_I(nSeakeepingLevel);
        VFIELD_I(nNavigationLevel);
        VFIELD_S(szFireSafetyCode);
        VFIELD_S(szSeakeepingQualiyCode);
        VFIELD_S(szNavigationSafetyCode);

    }
}
