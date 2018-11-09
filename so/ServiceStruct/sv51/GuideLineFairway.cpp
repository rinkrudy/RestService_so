#include "../../stdafx.h"
#include "GuideLineFairway.h"
GuideLineFairway::GuideLineFairway()
{
}
GuideLineFairway::~GuideLineFairway()
{
}
void GuideLineFairway::Init(){
        	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineFairway;get";

}
void * GuideLineFairway::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineFairway *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineFairway *)malloc(sizeof(DB_GuideLineFairway) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineFairway));
      DB_GuideLineFairway *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {
          AFIELD_I(index);
          AFIELD_S(harbor);
          AFIELD_S(name);
          AFIELD_D(length);
          AFIELD_D(depthMin);
          AFIELD_D(depthMax);
          AFIELD_D(widthMin);
          AFIELD_D(widthMax);
          AFIELD_S(content);
          pArray++;
      }
  }
  return p;
}
