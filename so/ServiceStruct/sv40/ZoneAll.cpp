#include "../../stdafx.h"
#include "ZoneAll.h"

ZoneAll::ZoneAll()
{
}


ZoneAll::~ZoneAll()
{
}

void ZoneAll::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/zone/ZoneAll;get";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv40/zone/ZoneAll;delete";
}




void * ZoneAll::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Zone *p;
	if (iArrayCount == 0)
	{
		return nullptr;
	}
	else
	{
		p = (DB_Zone *)malloc(sizeof(DB_Zone)*iArrayCount);
		memset(p, 0, sizeof(DB_Zone));
		DB_Zone *pArray = p;

		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_S(name);
            AFIELD_S(slat);
            AFIELD_S(wlon);
            AFIELD_S(nlat);
            AFIELD_S(elon);
			AFIELD_S(version);


			pArray++;
		}
	}
	
	return p;
}

	string ZoneAll::SetStructToJson(void* struct_Param)
	{
		string strnull;
		return strnull;
	}
