#pragma once
//

class ShipPosition : public EnaviBase
{
public:
	ShipPosition();
	~ShipPosition();

	virtual void * GetStruct(json::value* root);
	virtual void Init() override;
};

