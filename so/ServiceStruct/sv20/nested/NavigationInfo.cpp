#include "NavigationInfo.h"

NavigationInfo::NavigationInfo()
{

}
NavigationInfo::~NavigationInfo()
{
    
}


void NavigationInfo::SetNavigationInfo_Json(web::json::array &dstArray, std::vector<DB_NavigationInfo> &srcVector)
{
    int nArraySize = dstArray.size();


    for(int i = 0; i < nArraySize; i++)
    {
        DB_NavigationInfo &info = srcVector.at(0);
        VSETJSON_S(szLOG);
        VSETJSON_S(szAIS);
        VSETJSON_S(szGPS1);
        VSETJSON_S(szGPS2);
        VSETJSON_S(szECDIS);
        VSETJSON_S(szRADAR1);
        VSETJSON_S(szRADAR2);
        VSETJSON_S(szEchoSounder);
        VSETJSON_S(szGyroCompass);
        VSETJSON_S(szAutoPilot);

    }

}



void NavigationInfo::SetNavigationInfo_Struct(std::vector<DB_NavigationInfo> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();

    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_NavigationInfo &info = destVector.at(i);

        VFIELD_S(szLOG);
        VFIELD_S(szAIS);
        VFIELD_S(szGPS1);
        VFIELD_S(szGPS2);
        VFIELD_S(szECDIS);
        VFIELD_S(szRADAR1);
        VFIELD_S(szRADAR2);
        VFIELD_S(szEchoSounder);
        VFIELD_S(szGyroCompass);
        VFIELD_S(szAutoPilot);

    }
}