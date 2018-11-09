#include "../../stdafx.h"
#include "GuideLineVTS.h"
GuideLineVTS::GuideLineVTS()
{
}
GuideLineVTS::~GuideLineVTS()
{
}
void GuideLineVTS::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineVTS;get";
}
void * GuideLineVTS::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineVTS *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineVTS *)malloc(sizeof(DB_GuideLineVTS) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineVTS));
      DB_GuideLineVTS *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(callSign);
          AFIELD_S(division);
          AFIELD_S(vhfChannel);
          AFIELD_S(reportingPoint);
          AFIELD_S(reportingTime);
          AFIELD_S(reportingContent);
          pArray++;
      }
  }
  return p;
}
