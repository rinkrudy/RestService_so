#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineSpeed : public EnaviBase
{
public:
      GuideLineSpeed();
      ~GuideLineSpeed();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
