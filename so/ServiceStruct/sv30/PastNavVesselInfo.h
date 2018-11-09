#pragma once

class PastNavVesselInfo : public EnaviBase
{
public:
	PastNavVesselInfo();
	~PastNavVesselInfo();

	virtual void * GetStruct(json::value* root);
	virtual void Init() override;
};