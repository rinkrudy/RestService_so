#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class fishingPatternArea : public EnaviBase
{
public:
      fishingPatternArea();
      ~fishingPatternArea();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
