#include "TankLevel.h"

TankLevel::TankLevel()
{

}
TankLevel::~TankLevel()
{
    
}


void TankLevel::Set_Json(web::json::array &dstArray, std::vector<DB_TankLevel> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_TankLevel &info = srcVector.at(0);
        VSETJSON_I(sCount);
        VSETJSON_S(szTankType);
        VSETJSON_S(szTankName);
        VSETJSON_I(sTankNumber);
        VSETJSON_I(dVal);

    }


}


void TankLevel::Set_Struct(std::vector<DB_TankLevel> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();

    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_TankLevel &info = destVector.at(i);
        VFIELD_I(sCount);
        VFIELD_S(szTankType);
        VFIELD_S(szTankName);
        VFIELD_I(sTankNumber);
        VFIELD_D(dVal);

    }
}
