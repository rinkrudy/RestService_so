#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class Schedules : public EnaviBase
{
public:
	Schedules();
	~Schedules();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

