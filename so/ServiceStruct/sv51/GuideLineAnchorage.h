#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineAnchorage : public EnaviBase
{
public:
      GuideLineAnchorage();
      ~GuideLineAnchorage();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
