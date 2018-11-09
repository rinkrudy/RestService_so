#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class rssResponse : public EnaviBase
{
public:
      rssResponse();
      ~rssResponse();
      virtual void * GetStruct(json::value* root);
      virtual string SetStructToJson(void* struct_Param);
      virtual void Init() override;
};
