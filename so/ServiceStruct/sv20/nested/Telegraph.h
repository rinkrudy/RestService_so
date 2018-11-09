#include "../../../stdafx.h"

class Telegraph
{
    public:
        Telegraph();
        ~Telegraph();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_Telegraph> &srcVector); 
        void Set_Struct(std::vector<DB_Telegraph> &destVector, web::json::array &scrArray);
};