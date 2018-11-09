#include "../../stdafx.h"
#include "GuideLinePilot.h"
GuideLinePilot::GuideLinePilot()
{
}
GuideLinePilot::~GuideLinePilot()
{
}
void GuideLinePilot::Init(){
        	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLinePilot;get";

}
void * GuideLinePilot::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLinePilot *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLinePilot *)malloc(sizeof(DB_GuideLinePilot) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLinePilot));
      DB_GuideLinePilot *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(fairwayName);
          AFIELD_S(division);
          pArray++;
      }
  }
  return p;
}
