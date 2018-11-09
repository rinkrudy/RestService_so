#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class Zone : public EnaviBase
{
public:
	Zone();
	~Zone();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

