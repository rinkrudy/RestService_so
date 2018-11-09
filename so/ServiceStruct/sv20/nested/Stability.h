#include "../../../stdafx.h"

class Stability
{
    public:
        Stability();
        ~Stability();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_Stability> &srcVector); 
        void Set_Struct(std::vector<DB_Stability> &destVector, web::json::array &scrArray);
};