#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput05 : public EnaviBase
{
public:
      vulInput05();
      ~vulInput05();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
