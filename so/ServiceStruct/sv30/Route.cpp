#include "../../stdafx.h"
#include "Route.h"


Route::Route()
{
}


Route::~Route()
{
}

void Route::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/Route;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/Route;post";

}

string Route::SetStructToJson(void* struct_Param)
{
	DB_Route *p = (DB_Route *)struct_Param;

	web::json::value root;

	SETJSON_I(routeId);
	SETJSON_S(version);
	SETJSON_S(vesselVoyage);
	SETJSON_I(vesselMmsi);
	SETJSON_I(defaultWaypointRadius);

	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * Route::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Route *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_Route *)malloc(sizeof(DB_Route)*iArrayCount);
		memset(p, 0, sizeof(DB_Route));
		DB_Route *pArray = p;

		printf("Array count : %d \n", iArrayCount);
		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_L(routeId);
        	AFIELD_S(version);
        	AFIELD_S(vesselVoyage);
        	AFIELD_L(vesselMmsi);
        	AFIELD_D(defaultWaypointRadius);

			pArray++;
		}
	}
	
	return p;
}
