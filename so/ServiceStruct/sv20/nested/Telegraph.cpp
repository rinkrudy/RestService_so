#include "Telegraph.h"

Telegraph::Telegraph()
{

}
Telegraph::~Telegraph()
{
    
}


void Telegraph::Set_Json(web::json::array &dstArray, std::vector<DB_Telegraph> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_Telegraph &info = srcVector.at(0);
        VSETJSON_B(bTelegraphUse);
        VSETJSON_I(sCount);
        VSETJSON_I(nTelegraphId);
        VSETJSON_I(nTelegraphStatus);

    }


}


void Telegraph::Set_Struct(std::vector<DB_Telegraph> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();

    destVector.clear();
    destVector.resize(nArraySize);



    for(int i = 0; i < nArraySize; i++)
    {
        DB_Telegraph &info = destVector.at(i);
        VFIELD_B(bTelegraphUse);
        VFIELD_I(sCount);
        VFIELD_L(nTelegraphId);
        VFIELD_L(nTelegraphStatus);


    }
}
