#include "../../stdafx.h"
#include "GuideLineCourse.h"
GuideLineCourse::GuideLineCourse()
{
}
GuideLineCourse::~GuideLineCourse()
{
}
void GuideLineCourse::Init(){
    	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/GuideLineCourse;get";

}
void * GuideLineCourse::GetStruct(json::value *root)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_GuideLineCourse *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_GuideLineCourse *)malloc(sizeof(DB_GuideLineCourse) * iArrayCount);
      memset(p, 0, sizeof(DB_GuideLineCourse));
      DB_GuideLineCourse *pArray = p;
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
