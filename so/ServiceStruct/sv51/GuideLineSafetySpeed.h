#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineSafetySpeed : public EnaviBase
{
public:
      GuideLineSafetySpeed();
      ~GuideLineSafetySpeed();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
