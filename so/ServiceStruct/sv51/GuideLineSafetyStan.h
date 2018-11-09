#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineSafetyStan : public EnaviBase
{
public:
      GuideLineSafetyStan();
      ~GuideLineSafetyStan();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
