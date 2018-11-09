#include "../../stdafx.h"
#include "areaDetail.h"
areaDetail::areaDetail()
{
}
areaDetail::~areaDetail()
{
}
void areaDetail::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AreaDetail;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AreaDetail;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AreaDetail;delete";
}
string areaDetail::SetStructToJson(void * struct_Param)
{
  DB_areaDetail *p = (DB_areaDetail *)struct_Param;
  web::json::value root;
  SETJSON_S(areaId);
  SETJSON_I(areaSeq);
  SETJSON_I(areaLat);
  SETJSON_I(areaLon);
  return root.serialize();
}
void * areaDetail::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_areaDetail *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_areaDetail *)malloc(sizeof(DB_areaDetail) * iArrayCount);
      memset(p, 0, sizeof(DB_areaDetail));
      DB_areaDetail *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(areaSeq);
          AFIELD_D(areaLat);
          AFIELD_D(areaLon);
          pArray++;
      }
  }
  return p;
}
