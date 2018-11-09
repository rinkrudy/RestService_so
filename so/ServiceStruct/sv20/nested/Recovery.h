#include "../../../stdafx.h"

class Recovery
{
    public:
        Recovery();
        ~Recovery();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_Recovery> &srcVector); 
        void Set_Struct(std::vector<DB_Recovery> &destVector, web::json::array &scrArray);
};