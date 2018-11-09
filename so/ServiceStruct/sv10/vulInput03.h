#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput03 : public EnaviBase
{
public:
      vulInput03();
      ~vulInput03();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
