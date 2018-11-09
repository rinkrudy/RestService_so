#include "../../stdafx.h"
#include "vulInput06.h"
vulInput06::vulInput06()
{
}
vulInput06::~vulInput06()
{
}
void vulInput06::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput06;get";
    m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput06;post";
    m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput06;put";
    m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput06;delete";
}
string vulInput06::SetStructToJson(void * struct_Param)
{
  DB_vulInput06 *p = (DB_vulInput06 *)struct_Param;
  web::json::value root;
  SETJSON_S(shipId);
  SETJSON_S(subShipId);
  SETJSON_S(depTime);
  SETJSON_S(arrTime);
  SETJSON_S(depPort);
  SETJSON_S(arrPort);
  SETJSON_I(tugType);
  SETJSON_I(tugLen);
  SETJSON_I(mstLen);
  SETJSON_I(subLen);
  return root.serialize();
}
void * vulInput06::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput06 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput06 *)malloc(sizeof(DB_vulInput06) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput06));
      DB_vulInput06 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(shipId);
          AFIELD_S(subShipId);
          AFIELD_S(depTime);
          AFIELD_S(arrTime);
          AFIELD_S(depPort);
          AFIELD_S(arrPort);
          AFIELD_I(tugType);
          AFIELD_I(tugLen);
          AFIELD_I(mstLen);
          AFIELD_I(subLen);
          pArray++;
      }
  }
  return p;
}
