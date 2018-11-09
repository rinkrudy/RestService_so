#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput01 : public EnaviBase
{
public:
      vulInput01();
      ~vulInput01();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
