#include "../../../stdafx.h"

class TankLevel
{
    public:
        TankLevel();
        ~TankLevel();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_TankLevel> &srcVector); 
        void Set_Struct(std::vector<DB_TankLevel> &destVector, web::json::array &scrArray);
};