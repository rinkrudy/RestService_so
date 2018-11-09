#include "../../stdafx.h"
#include "vulInput00_1.h"
vulInput00_1::vulInput00_1()
{
}
vulInput00_1::~vulInput00_1()
{
}
void vulInput00_1::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/VulInput001;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/VulInput001;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/VulInput001;delete";
    
}
string vulInput00_1::SetStructToJson(void * struct_Param)
{
  DB_vulInput00_1 *p = (DB_vulInput00_1 *)struct_Param;
  web::json::value root;
  SETJSON_S(dateTime);
  SETJSON_I(collisionLatitude);
  SETJSON_I(collisionLongitude);
  SETJSON_I(dcpa);
  SETJSON_I(tcpa);
  SETJSON_I(risk);
  SETJSON_S(firstShipId);
  SETJSON_S(firstName);
  SETJSON_S(firstType);
  SETJSON_I(firstLatitude);
  SETJSON_I(firstLongitude);
  SETJSON_I(firstCog);
  SETJSON_I(firstSog);
  SETJSON_S(firstRecvtime);
  SETJSON_S(secondShipId);
  SETJSON_S(secondName);
  SETJSON_S(secondType);
  SETJSON_I(secondLatitude);
  SETJSON_I(secondLongitude);
  SETJSON_I(secondCog);
  SETJSON_I(secondSog);
  SETJSON_S(secondRecvtime);
  return root.serialize();
}
void * vulInput00_1::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_vulInput00_1 *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_vulInput00_1 *)malloc(sizeof(DB_vulInput00_1) * iArrayCount);
      memset(p, 0, sizeof(DB_vulInput00_1));
      DB_vulInput00_1 *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(dateTime);
          AFIELD_I(collisionLatitude);
          AFIELD_I(collisionLongitude);
          AFIELD_D(dcpa);
          AFIELD_D(tcpa);
          AFIELD_D(risk);
          AFIELD_S(firstShipId);
          AFIELD_S(firstName);
          AFIELD_S(firstType);
          AFIELD_I(firstLatitude);
          AFIELD_I(firstLongitude);
          AFIELD_I(firstCog);
          AFIELD_I(firstSog);
          AFIELD_S(firstRecvtime);
          AFIELD_S(secondShipId);
          AFIELD_S(secondName);
          AFIELD_S(secondType);
          AFIELD_I(secondLatitude);
          AFIELD_I(secondLongitude);
          AFIELD_I(secondCog);
          AFIELD_I(secondSog);
          AFIELD_S(secondRecvtime);
          pArray++;
      }
  }
  return p;
}
