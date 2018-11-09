#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineInfo : public EnaviBase
{
public:
      GuideLineInfo();
      ~GuideLineInfo();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
