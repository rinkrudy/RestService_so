#include "../../stdafx.h"
#include "DangerShipAlarm.h"


DangerShipAlarm::DangerShipAlarm()
{
}


DangerShipAlarm::~DangerShipAlarm()
{
}

void DangerShipAlarm::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/DangerShipAlarm;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/DangerShipAlarm;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/DangerShipAlarm;delete";
}

string DangerShipAlarm::SetStructToJson(void* struct_Param)
{
	DB_DangerShipAlarm *p = (DB_DangerShipAlarm *)struct_Param;

	web::json::value root;

	SETJSON_S(shipId);
	SETJSON_S(dateTime);
	SETJSON_B(inArea);
	SETJSON_S(preTime);
	SETJSON_I(preLatitude);
	SETJSON_I(preLongitude);
	SETJSON_I(shipLatitude);
	SETJSON_I(shipLongitude);
	SETJSON_I(shipCog);
	SETJSON_I(shipSog);
	SETJSON_S(recvTime);
	SETJSON_S(content);


	return root.serialize();
}

void * DangerShipAlarm::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_DangerShipAlarm *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_DangerShipAlarm *)malloc(sizeof(DB_DangerShipAlarm)*iArrayCount);
		memset(p, 0, sizeof(DB_DangerShipAlarm));
		DB_DangerShipAlarm *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			
			AFIELD_S(shipId);
			AFIELD_S(dateTime);
			AFIELD_B(inArea);
			AFIELD_S(preTime);
			AFIELD_I(preLatitude);
			AFIELD_I(preLongitude);
			AFIELD_I(shipLatitude);
			AFIELD_I(shipLongitude);
			AFIELD_I(shipCog);
			AFIELD_I(shipSog);
			AFIELD_S(recvTime);
			AFIELD_S(content);
			pArray++;
		}
	}
	
	return p;
}
