#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineTug : public EnaviBase
{
public:
      GuideLineTug();
      ~GuideLineTug();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
