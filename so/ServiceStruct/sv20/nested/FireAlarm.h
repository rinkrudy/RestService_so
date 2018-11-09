#include "../../../stdafx.h"

class FireAlarm
{
    public:
        FireAlarm();
        ~FireAlarm();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_FireAlarm> &srcVector); 
        void Set_Struct(std::vector<DB_FireAlarm> &destVector, web::json::array &scrArray);
};