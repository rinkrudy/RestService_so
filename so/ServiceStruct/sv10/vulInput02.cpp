#include "../../stdafx.h"
#include "vulInput02.h"
vulInput02::vulInput02()
{
}
vulInput02::~vulInput02()
{
}
void vulInput02::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput02;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput02;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput02;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput02;delete";
}
string vulInput02::SetStructToJson(void * struct_Param)
{
  DB_vulInput02_input *p = (DB_vulInput02_input *)struct_Param;
  web::json::value root;
  SETJSON_S(vulId);
  SETJSON_S(areaId);
  SETJSON_I(windSpd);
  SETJSON_I(waveHeight);
  return root.serialize();
}
void * vulInput02::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput02 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput02 *)malloc(sizeof(DB_vulInput02) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput02));
      DB_vulInput02 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(vulId);
          AFIELD_S(areaId);
          AFIELD_I(windSpd);
          AFIELD_I(waveHeight);
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
