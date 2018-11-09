#pragma once

class EnaviBase;


class ShipDensity : public EnaviBase
{
public:
	ShipDensity();
	~ShipDensity();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);
	virtual void Init() override;

};