#include "../../../stdafx.h"

class EmergencyInfo
{
    public:
        EmergencyInfo();
        ~EmergencyInfo();

    public:
        void SetEmergencyInfo_Json(web::json::array &dstArray, std::vector<DB_EmergencyInfo> &srcVector); 
        void SetEmergencyInfo_Struct(std::vector<DB_EmergencyInfo> &destVector, web::json::array &scrArray);
};