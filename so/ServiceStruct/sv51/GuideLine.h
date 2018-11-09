#pragma once


class GuideLine : public EnaviBase
{
public:
	GuideLine();
	~GuideLine();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);
	virtual void Init() override;

};