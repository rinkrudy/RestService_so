#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class ZoneAll : public EnaviBase
{
public:
	ZoneAll();
	~ZoneAll();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);\

	virtual void Init() override;
	
};

