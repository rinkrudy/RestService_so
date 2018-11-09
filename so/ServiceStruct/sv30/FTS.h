#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class FTS : public EnaviBase
{
public:
	FTS();
	~FTS();

	virtual void * GetStruct(json::value* root);
	virtual string SetStructToJson(void* struct_Param);

	virtual void Init() override;
	
};

