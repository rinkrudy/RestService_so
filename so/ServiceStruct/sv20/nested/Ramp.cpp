#include "Ramp.h"

Ramp::Ramp()
{

}
Ramp::~Ramp()
{
    
}


void Ramp::Set_Json(web::json::array &dstArray, std::vector<DB_Ramp> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_Ramp &info = srcVector.at(0);
        VSETJSON_B(bRampUse);
        VSETJSON_I(sCount);
        VSETJSON_I(nRampId);
        VSETJSON_B(bRampDoorOpen);

    }


}


void Ramp::Set_Struct(std::vector<DB_Ramp> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();


    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_Ramp &info = destVector.at(i);
        VFIELD_B(bRampUse);
        VFIELD_I(sCount);
        VFIELD_L(nRampId);
        VFIELD_B(bRampDoorOpen);

    }
}
