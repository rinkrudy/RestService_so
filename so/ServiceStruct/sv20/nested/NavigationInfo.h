
#include "../../../stdafx.h"

class NavigationInfo
{
    public:
        NavigationInfo();
        ~NavigationInfo();

    public:
        void SetNavigationInfo_Json(web::json::array &dstArray, std::vector<DB_NavigationInfo> &srcVector); 
        void SetNavigationInfo_Struct(std::vector<DB_NavigationInfo> &destVector, web::json::array &scrArray);
};