#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class areaMst : public EnaviBase
{
public:
      areaMst();
      ~areaMst();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
