#include "../../stdafx.h"
#include "GuideLineAnchorage.h"
GuideLineAnchorage::GuideLineAnchorage()
{
}
GuideLineAnchorage::~GuideLineAnchorage()
{
}
void GuideLineAnchorage::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineAnchorage;get";

}
void * GuideLineAnchorage::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineAnchorage *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineAnchorage *)malloc(sizeof(DB_GuideLineAnchorage) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineAnchorage));
      DB_GuideLineAnchorage *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(name);
          AFIELD_S(fairwayName);
          AFIELD_S(division);
          AFIELD_S(ability);
          pArray++;
      }
  }
  return p;
}
