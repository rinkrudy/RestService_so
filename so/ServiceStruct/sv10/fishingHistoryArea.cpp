#include "../../stdafx.h"
#include "fishingHistoryArea.h"
fishingHistoryArea::fishingHistoryArea()
{
}
fishingHistoryArea::~fishingHistoryArea()
{
}
void fishingHistoryArea::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/FishingHistoryArea;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/FishingHistoryArea;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/FishingHistoryArea;delete";
}
string fishingHistoryArea::SetStructToJson(void * struct_Param)
{
  DB_fishingHistoryArea *p = (DB_fishingHistoryArea *)struct_Param;
  web::json::value root;
  SETJSON_S(areaId);
  SETJSON_I(fisheryType);
  SETJSON_I(fishSpecies);
  SETJSON_S(fromTime);
  SETJSON_S(toTime);
  return root.serialize();
}
void * fishingHistoryArea::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_fishingHistoryArea *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_fishingHistoryArea *)malloc(sizeof(DB_fishingHistoryArea) * iArrayCount);
      memset(p, 0, sizeof(DB_fishingHistoryArea));
      DB_fishingHistoryArea *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_S(areaId);
          AFIELD_I(fisheryType);
          AFIELD_I(fishSpecies);
          AFIELD_S(fromTime);
          AFIELD_S(toTime);
          pArray++;
      }
  }
  return p;
}
