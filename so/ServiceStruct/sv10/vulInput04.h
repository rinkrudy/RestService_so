#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput04 : public EnaviBase
{
public:
      vulInput04();
      ~vulInput04();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
