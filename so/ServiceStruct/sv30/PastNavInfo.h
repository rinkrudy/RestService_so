#pragma once

class PastNavInfo : public EnaviBase
{
public:
	PastNavInfo();
	~PastNavInfo();
	virtual void * GetStruct(json::value* root);
	virtual void Init() override;
};

