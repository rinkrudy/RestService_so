#include "FireAlarm.h"

FireAlarm::FireAlarm()
{

}
FireAlarm::~FireAlarm()
{
    
}


void FireAlarm::Set_Json(web::json::array &dstArray, std::vector<DB_FireAlarm> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_FireAlarm &info = srcVector.at(0);
        VSETJSON_B(bUse);
        VSETJSON_I(sCount);
        VSETJSON_S(szDetectorType);
        VSETJSON_I(nPositionId);
        VSETJSON_S(szAlarmTime);

    }


}


void FireAlarm::Set_Struct(std::vector<DB_FireAlarm> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();
    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_FireAlarm &info = destVector.at(i);

        VFIELD_B(bUse);
        VFIELD_I(sCount);
        VFIELD_S(szDetectorType);
        VFIELD_I(nPositionId);
        VFIELD_S(szAlarmTime);

    }
}
