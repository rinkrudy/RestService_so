#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class ZoneAllDel : public EnaviBase
{
public:
	ZoneAllDel();
	~ZoneAllDel();

	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

