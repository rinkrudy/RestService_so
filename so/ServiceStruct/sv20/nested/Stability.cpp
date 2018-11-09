#include "Stability.h"

Stability::Stability()
{

}
Stability::~Stability()
{
    
}


void Stability::Set_Json(web::json::array &dstArray, std::vector<DB_Stability> &srcVector)
{
    int nArraySize = dstArray.size();

    for(int i = 0; i < nArraySize; i++)
    {
        DB_Stability &info = srcVector.at(0);
        VSETJSON_I(dForeDraft);
        VSETJSON_I(dAftDraft);
        VSETJSON_I(dKG);
        VSETJSON_I(dGoM);


    }


}


void Stability::Set_Struct(std::vector<DB_Stability> &destVector, web::json::array &srcArray)
{
    int nArraySize = srcArray.size();


    destVector.clear();
    destVector.resize(nArraySize);




    for(int i = 0; i < nArraySize; i++)
    {
        DB_Stability &info = destVector.at(i);
        VFIELD_D(dForeDraft);
        VFIELD_D(dAftDraft);
        VFIELD_D(dKG);
        VFIELD_D(dGoM);


    }
}
