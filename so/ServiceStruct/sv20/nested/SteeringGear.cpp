#include "SteeringGear.h"

SteeringGear::SteeringGear()
{

}
SteeringGear::~SteeringGear()
{
    
}


void SteeringGear::Set_Json(web::json::array &dstArray, std::vector<DB_SteeringGear> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_SteeringGear &info = srcVector.at(0);
        VSETJSON_I(sNo);
        VSETJSON_I(sCount);
        VSETJSON_S(szHydLoTk_LL);
        VSETJSON_S(szMotor_Run);
        VSETJSON_S(szNoVolt);
        VSETJSON_S(szOverload);
        VSETJSON_S(szPhase_Fail);


    }


}


void SteeringGear::Set_Struct(std::vector<DB_SteeringGear> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();

    destVector.clear();
    destVector.resize(nArraySize);




    for(int i = 0; i < nArraySize; i++)
    {
        DB_SteeringGear &info = destVector.at(i);
        VFIELD_I(sNo);
        VFIELD_I(sCount);
        VFIELD_S(szHydLoTk_LL);
        VFIELD_S(szMotor_Run);
        VFIELD_S(szNoVolt);
        VFIELD_S(szOverload);
        VFIELD_S(szPhase_Fail);

    }
}
