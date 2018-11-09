#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class Route : public EnaviBase
{
public:
	Route();
	~Route();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

