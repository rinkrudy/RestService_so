#include "../../stdafx.h"
#include "vulInput05.h"
vulInput05::vulInput05()
{
}
vulInput05::~vulInput05()
{
}
void vulInput05::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput05;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput05;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/VulInput05;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput05;delete";
}
string vulInput05::SetStructToJson(void * struct_Param)
{
  DB_vulInput05 *p = (DB_vulInput05 *)struct_Param;
  web::json::value root;
  SETJSON_S(shipId);
  SETJSON_S(depTime);
  SETJSON_S(arrTime);
  SETJSON_S(depPort);
  SETJSON_I(tonnage);
  return root.serialize();
}
void * vulInput05::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput05 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput05 *)malloc(sizeof(DB_vulInput05) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput05));
      DB_vulInput05 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(shipId);
          AFIELD_S(depTime);
          AFIELD_S(arrTime);
          AFIELD_S(depPort);
          AFIELD_D(tonnage);
          pArray++;
      }
  }
  return p;
}
