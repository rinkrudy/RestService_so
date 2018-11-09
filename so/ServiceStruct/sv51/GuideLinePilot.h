#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLinePilot : public EnaviBase
{
public:
      GuideLinePilot();
      ~GuideLinePilot();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
