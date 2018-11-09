#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class S57Cell : public EnaviBase
{
public:
      S57Cell();
      ~S57Cell();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};