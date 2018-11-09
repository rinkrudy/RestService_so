#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class ServiceLog : public EnaviBase
{
public:
	ServiceLog();
	~ServiceLog();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

