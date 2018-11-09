#include "../../../stdafx.h"

class FireDoor
{
    public:
        FireDoor();
        ~FireDoor();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_FireDoor> &srcVector); 
        void Set_Struct(std::vector<DB_FireDoor> &destVector, web::json::array &scrArray);
};