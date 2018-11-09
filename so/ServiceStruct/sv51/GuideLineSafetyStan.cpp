#include "../../stdafx.h"
#include "GuideLineSafetyStan.h"
GuideLineSafetyStan::GuideLineSafetyStan()
{
}
GuideLineSafetyStan::~GuideLineSafetyStan()
{
}
void GuideLineSafetyStan::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineSafetyStan;get";
}
void * GuideLineSafetyStan::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineSafetyStan *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineSafetyStan *)malloc(sizeof(DB_GuideLineSafetyStan) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineSafetyStan));
      DB_GuideLineSafetyStan *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(state);
          AFIELD_S(content);
          pArray++;
      }
  }
  return p;
}
