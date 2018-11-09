#include "../../stdafx.h"
#include "vulInput01.h"
vulInput01::vulInput01()
{
}
vulInput01::~vulInput01()
{
}
void vulInput01::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput01;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput01;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput01;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput01;delete";
}
string vulInput01::SetStructToJson(void * struct_Param)
{
  DB_vulInput01_input *p = (DB_vulInput01_input *)struct_Param;
  web::json::value root;
  SETJSON_S(vulId);
  SETJSON_S(areaId);
  SETJSON_I(curSpd01);
  SETJSON_I(curDir01);
  SETJSON_I(curSpd02);
  SETJSON_I(curDir02);
  SETJSON_I(acciCount);
  return root.serialize();
}
void * vulInput01::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput01 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput01 *)malloc(sizeof(DB_vulInput01) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput01));
      DB_vulInput01 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(vulId);
          AFIELD_S(areaId);
          AFIELD_I(curSpd01);
          AFIELD_I(curDir01);
          AFIELD_I(curSpd02);
          AFIELD_I(curDir02);
          AFIELD_I(acciCount);
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
