#include "FireDoor.h"

FireDoor::FireDoor()
{

}
FireDoor::~FireDoor()
{
    
}


void FireDoor::Set_Json(web::json::array &dstArray, std::vector<DB_FireDoor> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_FireDoor &info = srcVector.at(0);
        VSETJSON_B(bUse);
        VSETJSON_B(bDoorOpen);
        VSETJSON_I(nPositionId);

    }



}


void FireDoor::Set_Struct(std::vector<DB_FireDoor> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();
    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_FireDoor &info = destVector.at(i);

        VFIELD_B(bUse);
        VFIELD_B(bDoorOpen);
        VFIELD_I(nPositionId);

    }
}
