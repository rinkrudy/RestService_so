#include "../../stdafx.h"
#include "abnormalPattern.h"
abnormalPattern::abnormalPattern()
{
}
abnormalPattern::~abnormalPattern()
{
}
void abnormalPattern::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AbnormalPattern;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AbnormalPattern;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AbnormalPattern;delete";
}
string abnormalPattern::SetStructToJson(void * struct_Param)
{
  DB_abnormalPattern *p = (DB_abnormalPattern *)struct_Param;
  web::json::value root;
  SETJSON_S(shipId);
  SETJSON_S(dateTime);
  SETJSON_I(shipLatitude);
  SETJSON_I(shipLongitude);
  SETJSON_I(shipCog);
  SETJSON_I(shipSog);
  SETJSON_S(recvTime);
  SETJSON_I(abnormalValue);
  return root.serialize();
}
void * abnormalPattern::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_abnormalPattern *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_abnormalPattern *)malloc(sizeof(DB_abnormalPattern) * iArrayCount);
      memset(p, 0, sizeof(DB_abnormalPattern));
      DB_abnormalPattern *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(shipId);
          AFIELD_S(dateTime);
          AFIELD_I(shipLatitude);
          AFIELD_I(shipLongitude);
          AFIELD_I(shipCog);
          AFIELD_I(shipSog);
          AFIELD_S(recvTime);
          AFIELD_D(abnormalValue);
          pArray++;
      }
  }
  return p;
}
