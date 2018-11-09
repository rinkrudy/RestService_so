#include "../../stdafx.h"
#include "AccidentRisk.h"


AccidentRisk::AccidentRisk()
{
}


AccidentRisk::~AccidentRisk()
{
}

void AccidentRisk::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AccidentRisk;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AccidentRisk;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AccidentRisk;delete";
}

string AccidentRisk::SetStructToJson(void* struct_Param)
{
	DB_AccidentRisk *p = (DB_AccidentRisk *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_C(alarmStatus);
	SETJSON_S(oSMmsi);
	SETJSON_I(oSLongitude);
	SETJSON_I(oSLatitude);
	SETJSON_I(oSCog);
	SETJSON_I(oSSog);
	SETJSON_C(accidentType);
	SETJSON_C(accidentType2);
	SETJSON_S(tSMmsi);
	SETJSON_I(tSLongitude);
	SETJSON_I(tSLatitude);
	SETJSON_I(tSCog);
	SETJSON_I(tSSog);
	SETJSON_S(collisionType);
	SETJSON_I(collisionLongitude);
	SETJSON_I(collisionLatitude);	
	SETJSON_I(dcpa);	
	SETJSON_I(tcpa);	
	SETJSON_I(oSCPDistance);	
	SETJSON_I(oSCPTime);	
	SETJSON_I(tSCPDistance);	
	SETJSON_I(tSCPTime);	
	SETJSON_I(collisionRisk);	
	SETJSON_S(collisionArea);	


	return root.serialize();
}

void * AccidentRisk::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_AccidentRisk *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_AccidentRisk *)malloc(sizeof(DB_AccidentRisk)*iArrayCount);
		memset(p, 0, sizeof(DB_AccidentRisk));
		DB_AccidentRisk *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_C(alarmStatus);
			AFIELD_S(oSMmsi);
			AFIELD_I(oSLongitude);
			AFIELD_I(oSLatitude);
			AFIELD_I(oSCog);
			AFIELD_I(oSSog);
			AFIELD_C(accidentType);
			AFIELD_C(accidentType2);
			AFIELD_S(tSMmsi);
			AFIELD_I(tSLongitude);
			AFIELD_I(tSLatitude);
			AFIELD_I(tSCog);
			AFIELD_I(tSSog);
			AFIELD_S(collisionType);
			AFIELD_I(collisionLongitude);
			AFIELD_I(collisionLatitude);	
			AFIELD_D(dcpa);	
			AFIELD_D(tcpa);	
			AFIELD_D(oSCPDistance);	
			AFIELD_D(oSCPTime);	
			AFIELD_D(tSCPDistance);	
			AFIELD_D(tSCPTime);	
			AFIELD_D(collisionRisk);	
			AFIELD_S(collisionArea);
			pArray++;
		}
	}
	
	return p;
}
