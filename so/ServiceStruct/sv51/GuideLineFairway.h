#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineFairway : public EnaviBase
{
public:
      GuideLineFairway();
      ~GuideLineFairway();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
