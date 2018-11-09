#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLinePoint : public EnaviBase
{
public:
      GuideLinePoint();
      ~GuideLinePoint();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
