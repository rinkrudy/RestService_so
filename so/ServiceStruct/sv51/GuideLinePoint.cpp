#include "../../stdafx.h"
#include "GuideLinePoint.h"
GuideLinePoint::GuideLinePoint()
{
}
GuideLinePoint::~GuideLinePoint()
{
}
void GuideLinePoint::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLinePoint;get";
}
void * GuideLinePoint::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLinePoint *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLinePoint *)malloc(sizeof(DB_GuideLinePoint) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLinePoint));
      DB_GuideLinePoint *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_D(tableDv);
          AFIELD_D(rowDv);
          AFIELD_I(sequence);
          AFIELD_S(harbor);
          AFIELD_D(latitude);
          AFIELD_D(longitude);
          AFIELD_D(heading);
          pArray++;
      }
  }
  return p;
}
