#include "../../../stdafx.h"

class SteeringGear
{
    public:
        SteeringGear();
        ~SteeringGear();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_SteeringGear> &srcVector); 
        void Set_Struct(std::vector<DB_SteeringGear> &destVector, web::json::array &scrArray);
};