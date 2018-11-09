#include "../../stdafx.h"
#include "avsResponse.h"
avsResponse::avsResponse()
{
}
avsResponse::~avsResponse()
{
}
void avsResponse::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AvsResponse;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AvsResponse;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/AvsResponse;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AvsResponse;delete";
}
string avsResponse::SetStructToJson(void * struct_Param)
{
  DB_avsResponse *p = (DB_avsResponse *)struct_Param;
  web::json::value root;
  SETJSON_S(acciTime);
  SETJSON_S(osShipId);
  SETJSON_S(tsShipId);
  SETJSON_S(reqTime);
  SETJSON_S(resTime);
  return root.serialize();
}
void * avsResponse::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_avsResponse *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_avsResponse *)malloc(sizeof(DB_avsResponse) * iArrayCount);
      memset(p, 0, sizeof(DB_avsResponse));
      DB_avsResponse *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(acciTime);
          AFIELD_S(osShipId);
          AFIELD_S(tsShipId);
          AFIELD_S(reqTime);
          AFIELD_S(resTime);
          pArray++;
      }
  }
  return p;
}
