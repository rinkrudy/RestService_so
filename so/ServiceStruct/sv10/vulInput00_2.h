#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput00_2 : public EnaviBase
{
public:
      vulInput00_2();
      ~vulInput00_2();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
