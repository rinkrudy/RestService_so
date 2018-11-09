#include "../../stdafx.h"
#include "Zone.h"

Zone::Zone()
{
}


Zone::~Zone()
{
}

void Zone::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/zone/Zone;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv40/zone/Zone;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv40/zone/Zone;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv40/zone/Zone;delete";
}

string Zone::SetStructToJson(void* struct_Param)
{
	DB_Zone *p = (DB_Zone *)struct_Param;

	web::json::value root;

    SETJSON_S(name);
    SETJSON_S(slat);
    SETJSON_S(wlon);
    SETJSON_S(nlat);
    SETJSON_S(elon);
	SETJSON_S(version);


	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * Zone::GetStruct(json::value * root)
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
