#include "OldFireAlarm.h"

OldFireAlarm::OldFireAlarm()
{

}
OldFireAlarm::~OldFireAlarm()
{
    
}


void OldFireAlarm::Set_Json(web::json::array &dstArray, std::vector<DB_OldFireAlarm> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_OldFireAlarm &info = srcVector.at(0);
        VSETJSON_B(bUse);
        VSETJSON_I(sCount);
        VSETJSON_B(bBreakOut);

    }

}


void OldFireAlarm::Set_Struct(std::vector<DB_OldFireAlarm> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();


    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_OldFireAlarm &info = destVector.at(i);
        VFIELD_B(bUse);
        VFIELD_I(sCount);
        VFIELD_B(bBreakOut);

    }
}
