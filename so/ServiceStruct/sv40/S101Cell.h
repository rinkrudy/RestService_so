#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class S101Cell : public EnaviBase
{
public:
      S101Cell();
      ~S101Cell();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};