

#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class AccidentRisk : public EnaviBase
{
public:
	AccidentRisk();
	~AccidentRisk();

	virtual string SetStructToJson(void* struct_Param);
	virtual void * GetStruct(json::value * root);
	virtual void Init() override;
	
};

