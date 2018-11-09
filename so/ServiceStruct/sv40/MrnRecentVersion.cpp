#include "../../stdafx.h"
#include "MrnRecentVersion.h"

MrnRecentVersion::MrnRecentVersion()
{

}
MrnRecentVersion::~MrnRecentVersion()
{

}

void MrnRecentVersion::Init()
{
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/MrnRecentVersion;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv40/MrnRecentVersion;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv40/MrnRecentVersion;put";
    
}
string MrnRecentVersion::SetStructToJson(void * struct_Param)
{
  DB_MrnRecentVersion *p = (DB_MrnRecentVersion *)struct_Param;
  web::json::value root;
  SETJSON_S(shipMrn);
  SETJSON_S(license);
  SETJSON_S(w1Version);
  SETJSON_S(w2Version);
  SETJSON_S(w3Version);
  SETJSON_S(s1Version);
  SETJSON_S(s2Version);
  SETJSON_S(s3Version);
  SETJSON_S(s4Version);
  SETJSON_S(s5Version);
  SETJSON_S(e1Version);
  SETJSON_S(e2Version);
  SETJSON_S(e3Version);
  SETJSON_S(scVersion);

  return root.serialize();
}
void * MrnRecentVersion::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_MrnRecentVersion *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_MrnRecentVersion *)malloc(sizeof(DB_MrnRecentVersion) * iArrayCount);
      memset(p, 0, sizeof(DB_MrnRecentVersion));
      DB_MrnRecentVersion *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
            AFIELD_S(shipMrn);
            AFIELD_S(license);
            AFIELD_S(w1Version);
            AFIELD_S(w2Version);
            AFIELD_S(w3Version);
            AFIELD_S(s1Version);
            AFIELD_S(s2Version);
            AFIELD_S(s3Version);
            AFIELD_S(s4Version);
            AFIELD_S(s5Version);
            AFIELD_S(e1Version);
            AFIELD_S(e2Version);
            AFIELD_S(e3Version);
            AFIELD_S(scVersion);
          pArray++;
      }
  }
  return p;
}