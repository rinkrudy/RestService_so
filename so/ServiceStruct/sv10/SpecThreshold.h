

#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class SpecThreshold : public EnaviBase
{
public:
	SpecThreshold();
	~SpecThreshold();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

