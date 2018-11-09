#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput00_1 : public EnaviBase
{
public:
      vulInput00_1();
      ~vulInput00_1();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
