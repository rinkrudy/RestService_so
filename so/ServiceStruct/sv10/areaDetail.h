#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class areaDetail : public EnaviBase
{
public:
      areaDetail();
      ~areaDetail();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
