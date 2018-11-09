#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class GuideLineCourse : public EnaviBase
{
public:
      GuideLineCourse();
      ~GuideLineCourse();
      virtual void * GetStruct(json::value* root);
      virtual void Init() override;
};
