#pragma once
class EnaviBase;

using namespace web;
using namespace std;

class CatalogueAll : public EnaviBase
{
public:
	CatalogueAll();
	~CatalogueAll();

	virtual void * GetStruct(json::value* root);

	virtual void Init() override;
	
};


