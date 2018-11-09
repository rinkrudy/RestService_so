#include "../../stdafx.h"
#include "S57Cell.h"
S57Cell::S57Cell()
{
}
S57Cell::~S57Cell()
{
}
void S57Cell::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/S57Cell;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv40/S57Cell;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv40/S57Cell;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv40/S57CellDel;delete";
}
string S57Cell::SetStructToJson(void * struct_Param)
{
  DB_S57Cell *p = (DB_S57Cell *)struct_Param;
  web::json::value root;
  SETJSON_S(dsnm);
  SETJSON_S(edtn);
  SETJSON_S(updn);
  SETJSON_S(uadt);
  SETJSON_S(isdt);
  SETJSON_C(expp);
  SETJSON_C(intu);
  SETJSON_S(slat);
  SETJSON_S(wlon);
  SETJSON_S(nlat);
  SETJSON_S(elon);
  SETJSON_S(zone);
  return root.serialize();
}
void * S57Cell::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_S57Cell *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_S57Cell *)malloc(sizeof(DB_S57Cell) * iArrayCount);
      memset(p, 0, sizeof(DB_S57Cell));
      DB_S57Cell *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(dsnm);
          AFIELD_S(edtn);
          AFIELD_S(updn);
          AFIELD_S(uadt);
          AFIELD_S(isdt);
          AFIELD_C(expp);
          AFIELD_C(intu);
          AFIELD_S(slat);
          AFIELD_S(wlon);
          AFIELD_S(nlat);
          AFIELD_S(elon);
          AFIELD_S(zone);
          pArray++;
      }
  }
  return p;
}