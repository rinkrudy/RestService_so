#include "../../stdafx.h"
#include "EncUpdate.h"

EncUpdate::EncUpdate()
{

}
EncUpdate::~EncUpdate()
{

}

void EncUpdate::Init()
{
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/EncUpdate;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv40/EncUpdate;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv40/EncUpdate;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv40/EncUpdateDel;delete";
}
string EncUpdate::SetStructToJson(void * struct_Param)
{
  DB_EncUpdate *p = (DB_EncUpdate *)struct_Param;
  web::json::value root;
  SETJSON_I(updateId);
  SETJSON_S(shipMrn);
  SETJSON_S(license);
  SETJSON_S(responseTopic);
  SETJSON_S(responseTime);
  return root.serialize();
}
void * EncUpdate::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_EncUpdate *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_EncUpdate *)malloc(sizeof(DB_EncUpdate) * iArrayCount);
      memset(p, 0, sizeof(DB_EncUpdate));
      DB_EncUpdate *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(updateId);
          AFIELD_S(shipMrn);
          AFIELD_S(license);
          AFIELD_S(responseTopic);
          AFIELD_S(responseTime);
          pArray++;
      }
  }
  return p;
}