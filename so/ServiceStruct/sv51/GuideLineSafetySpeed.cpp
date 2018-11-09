#include "../../stdafx.h"
#include "GuideLineSafetySpeed.h"
GuideLineSafetySpeed::GuideLineSafetySpeed()
{
}
GuideLineSafetySpeed::~GuideLineSafetySpeed()
{
}
void GuideLineSafetySpeed::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineSafetySpeed;get";
}

void * GuideLineSafetySpeed::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineSafetySpeed *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineSafetySpeed *)malloc(sizeof(DB_GuideLineSafetySpeed) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineSafetySpeed));
      DB_GuideLineSafetySpeed *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(restrictedWater);
          AFIELD_S(targetVessel);
          AFIELD_S(limitedSpeed);
          pArray++;
      }
  }
  return p;
}
