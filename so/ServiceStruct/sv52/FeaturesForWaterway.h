#pragma once
class EnaviBase;
using namespace web;
using namespace std;
class FeaturesForWaterway : public EnaviBase
{
public:
      FeaturesForWaterway();
      ~FeaturesForWaterway();
	virtual const char * GetStructAndString(json::value *root, void **returnStruct);
      virtual void Init() override;
};
