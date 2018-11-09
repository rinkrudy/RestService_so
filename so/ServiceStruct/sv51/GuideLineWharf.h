#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineWharf : public EnaviBase
{
public:
      GuideLineWharf();
      ~GuideLineWharf();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
