#include "../../stdafx.h"
#include "GuideLineInfo.h"
GuideLineInfo::GuideLineInfo()
{
}
GuideLineInfo::~GuideLineInfo()
{
}
void GuideLineInfo::Init(){
        	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineInfo;get";

}
void * GuideLineInfo::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineInfo *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineInfo *)malloc(sizeof(DB_GuideLineInfo) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineInfo));
      DB_GuideLineInfo *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(fairwayName);
          AFIELD_S(division);
          AFIELD_S(content);
          pArray++;
      }
  }
  return p;
}
