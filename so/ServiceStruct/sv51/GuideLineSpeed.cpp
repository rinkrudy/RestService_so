#include "../../stdafx.h"
#include "GuideLineSpeed.h"
GuideLineSpeed::GuideLineSpeed()
{
}
GuideLineSpeed::~GuideLineSpeed()
{
}
void GuideLineSpeed::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineSpeed;get";
}
void * GuideLineSpeed::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineSpeed *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineSpeed *)malloc(sizeof(DB_GuideLineSpeed) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineSpeed));
      DB_GuideLineSpeed *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(name);
          AFIELD_D(speed);
          pArray++;
      }
  }
  return p;
}
