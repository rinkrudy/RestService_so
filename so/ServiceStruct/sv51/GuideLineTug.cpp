#include "../../stdafx.h"
#include "GuideLineTug.h"
GuideLineTug::GuideLineTug()
{
}
GuideLineTug::~GuideLineTug()
{
}
void GuideLineTug::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineTug;get";
}
void * GuideLineTug::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineTug *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineTug *)malloc(sizeof(DB_GuideLineTug) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineTug));
      DB_GuideLineTug *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(scale);
          AFIELD_S(tugData);
          pArray++;
      }
  }
  return p;
}
