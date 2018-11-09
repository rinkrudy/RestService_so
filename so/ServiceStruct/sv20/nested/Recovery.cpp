#include "Recovery.h"

Recovery::Recovery()
{

}
Recovery::~Recovery()
{
    
}


void Recovery::Set_Json(web::json::array &dstArray, std::vector<DB_Recovery> &srcVector)
{
    int nArraySize = dstArray.size();


    for(int i = 0; i < nArraySize; i++)
    {
        DB_Recovery &info = srcVector.at(0);
        VSETJSON_B(bUseRoll);
        VSETJSON_B(bUsePitch);
        VSETJSON_B(bUseGps);
        VSETJSON_B(bUseWind);
        VSETJSON_B(bUseRudder1);
        VSETJSON_B(bUseRudder2);
        VSETJSON_I(dRolling);
        VSETJSON_I(dPitching);
        VSETJSON_I(dCog);
        VSETJSON_I(dSog);
        VSETJSON_I(dShipHeading);
        VSETJSON_I(dShipSpeed);
        VSETJSON_I(dWindDirection);
        VSETJSON_I(dWindSpeed);
        VSETJSON_I(dRudder1);
        VSETJSON_I(dRudder2);


    }


}


void Recovery::Set_Struct(std::vector<DB_Recovery> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();


    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_Recovery &info = destVector.at(i);
        VFIELD_B(bUseRoll);
        VFIELD_B(bUsePitch);
        VFIELD_B(bUseGps);
        VFIELD_B(bUseWind);
        VFIELD_B(bUseRudder1);
        VFIELD_B(bUseRudder2);
        VFIELD_D(dRolling);
        VFIELD_D(dPitching);
        VFIELD_D(dCog);
        VFIELD_D(dSog);
        VFIELD_D(dShipHeading);
        VFIELD_D(dShipSpeed);
        VFIELD_D(dWindDirection);
        VFIELD_D(dWindSpeed);
        VFIELD_D(dRudder1);
        VFIELD_D(dRudder2);

    }
}
