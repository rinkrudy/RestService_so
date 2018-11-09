#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class AttentionShip : public EnaviBase
{
public:
	AttentionShip();
	~AttentionShip();

	virtual string SetStructToJson(void* struct_Param);
	virtual void * GetStruct(json::value* root);


	virtual void Init() override;
	
};

