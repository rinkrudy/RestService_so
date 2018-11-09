#include "../../stdafx.h"
#include "fishingPatternArea.h"
fishingPatternArea::fishingPatternArea()
{
}
fishingPatternArea::~fishingPatternArea()
{
}
void fishingPatternArea::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/FishingPatternArea;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/FishingPatternArea;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/FishingPatternArea;delete";
}
string fishingPatternArea::SetStructToJson(void * struct_Param)
{
  DB_fishingPatternArea *p = (DB_fishingPatternArea *)struct_Param;
  web::json::value root;
  SETJSON_S(shipStr);
  SETJSON_S(locStr);
  SETJSON_S(areaStr);
  SETJSON_S(dateTime);
  return root.serialize();
}
void * fishingPatternArea::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_fishingPatternArea *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_fishingPatternArea *)malloc(sizeof(DB_fishingPatternArea) * iArrayCount);
      memset(p, 0, sizeof(DB_fishingPatternArea));
      DB_fishingPatternArea *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(shipStr);
          AFIELD_S(locStr);
          AFIELD_S(areaStr);
          AFIELD_S(dateTime);
          pArray++;
      }
  }
  return p;
}
