#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput02 : public EnaviBase
{
public:
      vulInput02();
      ~vulInput02();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
