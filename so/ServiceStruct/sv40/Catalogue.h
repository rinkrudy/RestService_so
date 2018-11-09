#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class Catalogue : public EnaviBase
{
public:
	Catalogue();
	~Catalogue();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

