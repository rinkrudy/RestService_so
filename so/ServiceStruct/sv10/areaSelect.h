#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class areaSelect : public EnaviBase
{
public:
      areaSelect();
      ~areaSelect();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
