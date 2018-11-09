#include "../../stdafx.h"
#include "NearMissViolation.h"


NearMissViolation::NearMissViolation()
{
}


NearMissViolation::~NearMissViolation()
{
}

void NearMissViolation::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/NearMissViolation;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/NearMissViolation;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string NearMissViolation::SetStructToJson(void* struct_Param)
{
	DB_NearMissViolation *p = (DB_NearMissViolation *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(mmsi);
	SETJSON_S(name);
	SETJSON_I(type);
	SETJSON_I(missCnt);
	SETJSON_S(missTime);
	SETJSON_I(missCode);
	SETJSON_S(missString);


	return root.serialize();
}

void * NearMissViolation::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_NearMissViolation *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_NearMissViolation *)malloc(sizeof(DB_NearMissViolation)*iArrayCount);
		memset(p, 0, sizeof(DB_NearMissViolation));
		DB_NearMissViolation *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_S(mmsi);
			AFIELD_S(name);
			AFIELD_I(type);
			AFIELD_I(missCnt);
			AFIELD_S(missTime);
			AFIELD_I(missCode);
			AFIELD_S(missString);

			pArray++;
		}
	}
	
	return p;
}
