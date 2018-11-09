#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class avsResponse : public EnaviBase
{
public:
      avsResponse();
      ~avsResponse();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
