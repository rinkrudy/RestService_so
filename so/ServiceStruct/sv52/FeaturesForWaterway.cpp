#include "../../stdafx.h"
#include "FeaturesForWaterway.h"


FeaturesForWaterway::FeaturesForWaterway()
{
}
FeaturesForWaterway::~FeaturesForWaterway()
{
}
void FeaturesForWaterway::Init(){
    m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv52/msi/getFeaturesForWaterway;get";
}

const char * FeaturesForWaterway::GetStructAndString(json::value *root, void ** returnStruct)
{
  auto array = root->at("data").as_array();
  int iArrayCount = array.size();
  DB_FeaturesForWaterway *p;
  if(iArrayCount == 0)
      return nullptr;
  else
  {
      p = (DB_FeaturesForWaterway *)malloc(sizeof(DB_FeaturesForWaterway) * iArrayCount);
      memset(p, 0, sizeof(DB_FeaturesForWaterway));
      DB_FeaturesForWaterway *pArray = p;
      for(int i = 0; i < iArrayCount; i++)
      {

            AFIELD_S(spec);
            AFIELD_S(version);
            AFIELD_S(startDate);
            AFIELD_S(endDate);
            AFIELD_S(generalCategory);
            AFIELD_S(geomtype);
            printf("here : %s\n", array[i].at(U("geom")).as_string().c_str());
            //(pArray->geom).assign(array[i].at(U("geom")).as_string());
            //array[i].at(U("geom")).is_null() ? (pArray->geom).assign(" ") : (pArray->geom).assign(array[i].at(U("geom")).as_string().c_str());

          pArray++;
      }
  }
  *returnStruct = p;
  return array[0].at(U("geom")).as_string().c_str();
}
