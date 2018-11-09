#include "../../stdafx.h"
#include "FTS.h"

FTS::FTS()
{
}


FTS::~FTS()
{
}

void FTS::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/Fts;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/Fts;post";
	}

string FTS::SetStructToJson(void* struct_Param)
{
	DB_FTS *p = (DB_FTS *)struct_Param;

	web::json::value root;

    SETJSON_I(routeId);
    SETJSON_I(waypointId);
    SETJSON_I(rudderAngle);
    SETJSON_I(rpm);
    SETJSON_I(spareControlForce);
    SETJSON_I(spare1);
    SETJSON_I(spare2);
    SETJSON_I(spare3);
    SETJSON_I(spare4);

	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * FTS::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_FTS *p;
	if (iArrayCount == 0)
	{
		return nullptr;
	}
	else
	{
		p = (DB_FTS *)malloc(sizeof(DB_FTS)*iArrayCount);
		memset(p, 0, sizeof(DB_FTS));
		DB_FTS *pArray = p;

		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_L(routeId);
            AFIELD_L(waypointId);
            AFIELD_D(rudderAngle);
            AFIELD_D(rpm);
            AFIELD_D(spareControlForce);
            AFIELD_D(spare1);
            AFIELD_D(spare2);
            AFIELD_D(spare3);
            AFIELD_D(spare4);

			pArray++;
		}
	}
	
	return p;
}
