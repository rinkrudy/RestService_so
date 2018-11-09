#include "../../stdafx.h"
#include "vulInput03.h"
vulInput03::vulInput03()
{
}
vulInput03::~vulInput03()
{
}
void vulInput03::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput03;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput03;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput03;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput03;delete";
}
string vulInput03::SetStructToJson(void * struct_Param)
{
  DB_vulInput03_input *p = (DB_vulInput03_input *)struct_Param;
  web::json::value root;
  SETJSON_S(vulId);
  SETJSON_S(areaId);
  SETJSON_I(dynCong);
  SETJSON_I(staCong);
  SETJSON_I(acciRatio);
  return root.serialize();
}
void * vulInput03::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput03 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput03 *)malloc(sizeof(DB_vulInput03) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput03));
      DB_vulInput03 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(vulId);
          AFIELD_S(areaId);
          AFIELD_D(dynCong);
          AFIELD_D(staCong);
          AFIELD_I(acciRatio);
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
