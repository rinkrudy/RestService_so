#include "../../stdafx.h"
#include "vulInput07.h"
vulInput07::vulInput07()
{
}
vulInput07::~vulInput07()
{
    
}
void vulInput07::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput07;get";
    m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput07;post";
    m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput07;put";
    m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput07;delete";
}
string vulInput07::SetStructToJson(void * struct_Param)
{
  DB_vulInput07 *p = (DB_vulInput07 *)struct_Param;
  web::json::value root;
  SETJSON_S(tgtShipId);
  SETJSON_S(shipId);
  SETJSON_I(index);
  SETJSON_S(fromTime);
  SETJSON_S(toTime);
  return root.serialize();
}
void * vulInput07::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput07 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput07 *)malloc(sizeof(DB_vulInput07) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput07));
      DB_vulInput07 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(tgtShipId);
          AFIELD_S(shipId);
          AFIELD_I(index);
          AFIELD_S(fromTime);
          AFIELD_S(toTime);
          pArray++;
      }
  }
  return p;
}
