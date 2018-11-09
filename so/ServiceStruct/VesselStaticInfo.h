#pragma once
class VesselStaticInfo : public EnaviBase
{
public:
	VesselStaticInfo();
	~VesselStaticInfo();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);
	virtual void Init() override;
};

