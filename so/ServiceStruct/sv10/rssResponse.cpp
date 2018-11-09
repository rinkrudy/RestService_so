#include "../../stdafx.h"
#include "rssResponse.h"
rssResponse::rssResponse()
{
}
rssResponse::~rssResponse()
{
}
void rssResponse::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/RssResponse;get";
    m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/RssResponse;post";
    m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv10/RssResponse;put";
    m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/RssResponse;delete";
}
string rssResponse::SetStructToJson(void * struct_Param)
{
  DB_rssResponse *p = (DB_rssResponse *)struct_Param;
  web::json::value root;
  SETJSON_S(acciTime);
  SETJSON_S(osShipId);
  SETJSON_S(tsShipId);
  SETJSON_S(tgtShipId);
  SETJSON_I(tgtLat);
  SETJSON_I(tgtLon);
  SETJSON_S(reqTime);
  SETJSON_S(resTime);
  return root.serialize();
}
void * rssResponse::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_rssResponse *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_rssResponse *)malloc(sizeof(DB_rssResponse) * iArrayCount);
      memset(p, 0, sizeof(DB_rssResponse));
      DB_rssResponse *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(acciTime);
          AFIELD_S(osShipId);
          AFIELD_S(tsShipId);
          AFIELD_S(tgtShipId);
          AFIELD_I(tgtLat);
          AFIELD_I(tgtLon);
          AFIELD_S(reqTime);
          AFIELD_S(resTime);
          pArray++;
      }
  }
  return p;
}
