#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class vulInput07 : public EnaviBase
{
public:
      vulInput07();
      ~vulInput07();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
