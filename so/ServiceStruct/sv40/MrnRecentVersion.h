#pragma once
class EnaviBase;
using namespace web;
using namespace std;


class MrnRecentVersion : public EnaviBase
{
public:
      MrnRecentVersion();
      ~MrnRecentVersion();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};