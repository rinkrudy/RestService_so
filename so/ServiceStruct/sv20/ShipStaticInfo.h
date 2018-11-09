#pragma once
#include "../EnaviDBStruct.h"
#include<vector>
class EnaviBase;



using namespace web;
using namespace std;




class ShipStaticInfo : public EnaviBase
{
public:
	ShipStaticInfo();
	~ShipStaticInfo();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;

	
};

