#include "../../../stdafx.h"

class Generator
{
    public:
        Generator();
        ~Generator();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_Generator> &srcVector); 
        void Set_Struct(std::vector<DB_Generator> &destVector, web::json::array &scrArray);
};