#include "../../stdafx.h"
#include "RouteInfo.h"


RouteInfo::RouteInfo()
{
}


RouteInfo::~RouteInfo()
{
}

void RouteInfo::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/RouteInfo;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/RouteInfo;post";
}

string RouteInfo::SetStructToJson(void* struct_Param)
{
	DB_RouteInfo *p = (DB_RouteInfo *)struct_Param;

	web::json::value root;

	SETJSON_I(routeId);
	SETJSON_S(routeName);
	SETJSON_S(routeAuthor);
	SETJSON_S(routeStatus);
	SETJSON_S(validityPeriodStart);
    SETJSON_S(validityPeriodStop);
    SETJSON_S(vesselName);
    SETJSON_I(vesselMmsi);
    SETJSON_I(vesselImo);
    SETJSON_S(vesselVoyage);
	SETJSON_I(vesselDisplacement);
    SETJSON_I(vesselCargo);
    SETJSON_I(vesselGm);
    SETJSON_S(optimizationMethod);
    SETJSON_I(vesselMaxRoll);
    SETJSON_I(vesselMaxWave);
	SETJSON_I(vesselMaxWind);
    SETJSON_I(vesselSpeedMax);
    SETJSON_I(vesselServiceMin);
    SETJSON_I(vesselServiceMax);
    SETJSON_S(routeChangesHistory);    

	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * RouteInfo::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_RouteInfo *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_RouteInfo *)malloc(sizeof(DB_RouteInfo)*iArrayCount);
		memset(p, 0, sizeof(DB_RouteInfo));
		DB_RouteInfo *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			
			AFIELD_L(routeId);
			AFIELD_S(routeName);
			AFIELD_S(routeAuthor);
			AFIELD_S(routeStatus);
			AFIELD_S(validityPeriodStart);
    		AFIELD_S(validityPeriodStop);
    		AFIELD_S(vesselName);
    		AFIELD_L(vesselMmsi);
    		AFIELD_L(vesselImo);
    		AFIELD_S(vesselVoyage);
			AFIELD_L(vesselDisplacement);
    		AFIELD_L(vesselCargo);
    		AFIELD_D(vesselGm);
    		AFIELD_S(optimizationMethod);
    		AFIELD_L(vesselMaxRoll);
    		AFIELD_D(vesselMaxWave);
			AFIELD_D(vesselMaxWind);
    		AFIELD_D(vesselSpeedMax);
    		AFIELD_D(vesselServiceMin);
    		AFIELD_D(vesselServiceMax);
    		AFIELD_S(routeChangesHistory);    
			
			pArray++;



		}
	}
	
	return p;
}
