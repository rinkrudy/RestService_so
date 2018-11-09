#include "../../stdafx.h"
#include "GuideLineWharf.h"
GuideLineWharf::GuideLineWharf()
{
}
GuideLineWharf::~GuideLineWharf()
{
}
void GuideLineWharf::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineWharf;get";
}
void * GuideLineWharf::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineWharf *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineWharf *)malloc(sizeof(DB_GuideLineWharf) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineWharf));
      DB_GuideLineWharf *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(name);
          AFIELD_S(dName);
          AFIELD_S(dName);
          AFIELD_D(length);
          AFIELD_D(fromtDepthMin);
          AFIELD_D(fromtDepthMax);
          AFIELD_S(loadingCapacity);
          AFIELD_S(division);
          pArray++;
      }
  }
  return p;
}
