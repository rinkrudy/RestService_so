#include "../stdafx.h"
#include "EnaviBase.h"


EnaviBase::EnaviBase()
{

}


EnaviBase::~EnaviBase()
{
}
void * EnaviBase::GetStruct(json::value* root)
{
	return nullptr;
}


string EnaviBase::SetStructToJson(void * struct_Param)
{
	return NULL;
}



void * EnaviBase::SetStructInfo(json::value * root)
{	
	//Struct Info
	bool isNull;

	RestApiInfo* p = (RestApiInfo *)malloc(sizeof(RestApiInfo));
	memset(p, 0, sizeof(RestApiInfo));

	p->success = root->at("success").as_bool();
	if(!(root->at("data").is_integer()))
	{
		p->data = 0;
	}
	else
		p->data = root->at("data").as_integer();
		
	isNull = root->at("msg").is_null();
	if (!isNull)
	{
		strcpy(p->msg, root->at("msg").as_string().c_str());
	}

	return p;
}

const char *EnaviBase::GetDataAsString(json::value *root)
{
	web::json::value arr = root->at("data");
	return (arr.serialize()).c_str();
}




std::string EnaviBase::GetSerivceUrl(Service::E_RestType eRest){
	return m_arrRestUrl[(int)eRest];
}