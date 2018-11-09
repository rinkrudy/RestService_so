#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class fishingHistoryArea : public EnaviBase
{
public:
      fishingHistoryArea();
      ~fishingHistoryArea();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
