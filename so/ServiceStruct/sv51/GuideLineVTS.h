#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineVTS : public EnaviBase
{
public:
      GuideLineVTS();
      ~GuideLineVTS();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
