#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class RouteInfo : public EnaviBase
{
public:
	RouteInfo();
	~RouteInfo();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};
