#include "../../stdafx.h"
#include "vulInput00_2.h"
vulInput00_2::vulInput00_2()
{
}
vulInput00_2::~vulInput00_2()
{
}
void vulInput00_2::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput002;get";
    m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput002;post";
    m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput002;delete";
}
string vulInput00_2::SetStructToJson(void * struct_Param)
{
  DB_vulInput00_2 *p = (DB_vulInput00_2 *)struct_Param;
  web::json::value root;
  SETJSON_S(shipId);
  SETJSON_S(dateTime);
  SETJSON_S(name);
  SETJSON_S(type);
  SETJSON_I(risk);
  SETJSON_I(collisionLatitude);
  SETJSON_I(collisionLongitude);
  SETJSON_I(shipLatitude);
  SETJSON_I(shipLongitude);
  SETJSON_I(shipCog);
  SETJSON_I(shipSog);
  SETJSON_S(shipRecvtime);
  return root.serialize();
}
void * vulInput00_2::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput00_2 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput00_2 *)malloc(sizeof(DB_vulInput00_2) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput00_2));
      DB_vulInput00_2 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(shipId);
          AFIELD_S(dateTime);
          AFIELD_S(name);
          AFIELD_S(type);
          AFIELD_D(risk);
          AFIELD_I(collisionLatitude);
          AFIELD_I(collisionLongitude);
          AFIELD_I(shipLatitude);
          AFIELD_I(shipLongitude);
          AFIELD_I(shipCog);
          AFIELD_I(shipSog);
          AFIELD_S(shipRecvtime);
          pArray++;
      }
  }
  return p;
}
