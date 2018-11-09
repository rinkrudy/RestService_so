#include "../../../stdafx.h"

class MainEngine
{
    public:
        MainEngine();
        ~MainEngine();

    public:
        void Set_Json(web::json::array &dstArray, std::vector<DB_MainEngine> &srcVector); 
        void Set_Struct(std::vector<DB_MainEngine> &destVector, web::json::array &scrArray);
};