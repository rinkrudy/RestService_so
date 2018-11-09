#include "../../../stdafx.h"

class Ramp
{
    public:
        Ramp();
        ~Ramp();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_Ramp> &srcVector); 
        void Set_Struct(std::vector<DB_Ramp> &destVector, web::json::array &scrArray);
};