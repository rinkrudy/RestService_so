#include "../../stdafx.h"
#include "vulInput04.h"
vulInput04::vulInput04()
{
}
vulInput04::~vulInput04()
{
}
void vulInput04::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput04;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput04;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput04;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput04;delete";
}
string vulInput04::SetStructToJson(void * struct_Param)
{
  DB_vulInput04_input *p = (DB_vulInput04_input *)struct_Param;
  web::json::value root;
  SETJSON_S(vulId);
  SETJSON_S(areaId);
  SETJSON_I(acciRatio);
  SETJSON_I(passShips);
  return root.serialize();
}
void * vulInput04::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput04 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput04 *)malloc(sizeof(DB_vulInput04) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput04));
      DB_vulInput04 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(vulId);
          AFIELD_S(areaId);
          AFIELD_I(acciRatio);
          AFIELD_I(passShips);
          AFIELD_I(areaSeq);
          AFIELD_S(areaName);
          AFIELD_S(fromTime);
          AFIELD_S(toTime);
          AFIELD_D(areaLat);
          AFIELD_D(areaLon);
          pArray++;
      }
  }
  return p;
}
