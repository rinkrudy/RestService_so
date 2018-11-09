#include "../../stdafx.h"
#include "Waypoints.h"

Waypoints::Waypoints()
{
}


Waypoints::~Waypoints()
{
}

void Waypoints::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/Waypoints;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/Waypoints;post";

}

string Waypoints::SetStructToJson(void* struct_Param)
{
	DB_Waypoints *p = (DB_Waypoints *)struct_Param;

	web::json::value root;

    SETJSON_I(routeId);
    SETJSON_I(defaultWaypoint);
    SETJSON_I(defaultWaypointRadius);
    SETJSON_I(id);
    SETJSON_I(revision);
    SETJSON_S(name);
    SETJSON_I(radius);
    SETJSON_I(lat);
    SETJSON_I(lon);
    SETJSON_I(portsideXtd);
    SETJSON_I(starboardXtd);
    SETJSON_I(safetyContour);
    SETJSON_I(safetyDepth);
    SETJSON_I(geometryType);
    SETJSON_I(speedMax);
    SETJSON_I(speedMin);
    SETJSON_I(draughtForward);
    SETJSON_I(draughtAft);
    SETJSON_I(staticUkc);
    SETJSON_I(masthead);
    SETJSON_S(legReport);
    SETJSON_S(legInfo);
    SETJSON_S(legNote1);
    SETJSON_S(legNote2);



	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * Waypoints::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Waypoints *p;
	if (iArrayCount == 0)
	{
		return nullptr;
	}
	else
	{
		p = (DB_Waypoints *)malloc(sizeof(DB_Waypoints)*iArrayCount);
		memset(p, 0, sizeof(DB_Waypoints));
		DB_Waypoints *pArray = p;

		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_L(routeId);
            AFIELD_L(defaultWaypoint);
            AFIELD_D(defaultWaypointRadius);
            AFIELD_L(id);
            AFIELD_L(revision);
            AFIELD_S(name);
            AFIELD_D(radius);
            AFIELD_D(lat);
            AFIELD_D(lon);
            AFIELD_D(portsideXtd);
            AFIELD_D(starboardXtd);
            AFIELD_D(safetyContour);
            AFIELD_D(safetyDepth);
            AFIELD_L(geometryType);
            AFIELD_D(speedMax);
            AFIELD_D(speedMin);
            AFIELD_D(draughtForward);
            AFIELD_D(draughtAft);
            AFIELD_D(staticUkc);
            AFIELD_D(masthead);
            AFIELD_S(legReport);
            AFIELD_S(legInfo);
            AFIELD_S(legNote1);
            AFIELD_S(legNote2);

			pArray++;
		}
	}
	
	return p;
}
