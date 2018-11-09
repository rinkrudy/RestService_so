#include "../../stdafx.h"
#include "Schedules.h"

Schedules::Schedules()
{
}


Schedules::~Schedules()
{
}

void Schedules::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/Schedules;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/Schedules;post";
	
}

string Schedules::SetStructToJson(void* struct_Param)
{
	DB_Schedules *p = (DB_Schedules *)struct_Param;

	web::json::value root;

    SETJSON_I(routeId);
    SETJSON_I(id);
    SETJSON_S(name);
    SETJSON_I(manual);
    SETJSON_I(calculated);
    SETJSON_I(waypointId);
    SETJSON_S(etd);
    SETJSON_S(etdWindowBefore);
    SETJSON_S(etdWindowAfter);
    SETJSON_S(etaWindowBefore);
    SETJSON_S(etaWindowAfter);
    SETJSON_I(speed);
    SETJSON_I(speedWindow);
    SETJSON_I(windSpeed);
    SETJSON_I(windDirection);
    SETJSON_I(currentSpeed);
    SETJSON_I(currentDirection);
    SETJSON_I(windLoss);
    SETJSON_I(waveLoss);
    SETJSON_I(totalLoss);
    SETJSON_I(rpm);
    SETJSON_I(pitch);
    SETJSON_I(fuel);
    SETJSON_I(relFuelSave);
    SETJSON_I(absFuelSave);
    SETJSON_S(note);



	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * Schedules::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Schedules *p;
	if (iArrayCount == 0)
	{
		return nullptr;
	}
	else
	{
		p = (DB_Schedules *)malloc(sizeof(DB_Schedules)*iArrayCount);
		memset(p, 0, sizeof(DB_Schedules));
		DB_Schedules *pArray = p;

		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_L(routeId);
            AFIELD_L(id);
            AFIELD_S(name);
            AFIELD_L(manual);
            AFIELD_L(calculated);
            AFIELD_L(waypointId);
            AFIELD_S(etd);
            AFIELD_S(etdWindowBefore);
            AFIELD_S(etdWindowAfter);
            AFIELD_S(etaWindowBefore);
            AFIELD_S(etaWindowAfter);
            AFIELD_D(speed);
            AFIELD_D(speedWindow);
            AFIELD_D(windSpeed);
            AFIELD_D(windDirection);
            AFIELD_D(currentSpeed);
            AFIELD_D(currentDirection);
            AFIELD_D(windLoss);
            AFIELD_D(waveLoss);
            AFIELD_D(totalLoss);
            AFIELD_L(rpm);
            AFIELD_L(pitch);
            AFIELD_D(fuel);
            AFIELD_D(relFuelSave);
            AFIELD_D(absFuelSave);
            AFIELD_S(note);

			pArray++;
		}
	}
	
	return p;
}
