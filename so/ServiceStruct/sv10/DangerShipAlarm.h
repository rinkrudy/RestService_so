

#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class DangerShipAlarm : public EnaviBase
{
public:
	DangerShipAlarm();
	~DangerShipAlarm();
	
	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

