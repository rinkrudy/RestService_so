#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class abnormalPattern : public EnaviBase
{
public:
      abnormalPattern();
      ~abnormalPattern();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
