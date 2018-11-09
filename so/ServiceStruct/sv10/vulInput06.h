#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput06 : public EnaviBase
{
public:
      vulInput06();
      ~vulInput06();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
