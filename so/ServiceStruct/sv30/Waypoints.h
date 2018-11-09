
#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class Waypoints : public EnaviBase
{
public:
	Waypoints();
	~Waypoints();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

