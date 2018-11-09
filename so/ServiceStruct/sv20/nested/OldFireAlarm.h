#include "../../../stdafx.h"

class OldFireAlarm
{
    public:
        OldFireAlarm();
        ~OldFireAlarm();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_OldFireAlarm> &srcVector); 
        void Set_Struct(std::vector<DB_OldFireAlarm> &destVector, web::json::array &scrArray);
};