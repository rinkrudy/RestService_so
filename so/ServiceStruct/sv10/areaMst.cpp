#include "../../stdafx.h"
#include "areaMst.h"
areaMst::areaMst()
{
}
areaMst::~areaMst()
{
}
void areaMst::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AreaMst;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AreaMst;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AreaMst;delete";
}
string areaMst::SetStructToJson(void * struct_Param)
{
  DB_areaMst *p = (DB_areaMst *)struct_Param;
  web::json::value root;
  SETJSON_S(areaId);
  SETJSON_S(areaName);
  SETJSON_I(areaType);
  SETJSON_S(fromTime);
  SETJSON_S(toTime);
  SETJSON_S(verInfo);
  return root.serialize();
}
void * areaMst::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_areaMst *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_areaMst *)malloc(sizeof(DB_areaMst) * iArrayCount);
      memset(p, 0, sizeof(DB_areaMst));
      DB_areaMst *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(areaId);
          AFIELD_S(areaName);
          AFIELD_I(areaType);
          AFIELD_S(fromTime);
          AFIELD_S(toTime);
          AFIELD_S(verInfo);
          pArray++;
      }
  }
  return p;
}
