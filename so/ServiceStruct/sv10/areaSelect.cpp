#include "../../stdafx.h"
#include "areaSelect.h"
areaSelect::areaSelect()
{
}
areaSelect::~areaSelect()
{
}
void areaSelect::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AreaSelect;get";
}
void * areaSelect::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_areaSelect *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_areaSelect *)malloc(sizeof(DB_areaSelect) * iArrayCount);
      memset(p, 0, sizeof(DB_areaSelect));
      DB_areaSelect *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(areaSeq);
          AFIELD_S(areaName);
          AFIELD_I(areaType);
          AFIELD_S(fromTime);
          AFIELD_S(toTime);
          AFIELD_D(areaLat);
          AFIELD_D(areaLon);
          pArray++;
      }
  }
  return p;
}
