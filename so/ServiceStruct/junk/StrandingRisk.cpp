#include "../../stdafx.h"
#include "StrandingRisk.h"


StrandingRisk::StrandingRisk()
{
}


StrandingRisk::~StrandingRisk()
{
}

void StrandingRisk::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/StrandingRisk;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/StrandingRisk;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string StrandingRisk::SetStructToJson(void* struct_Param)
{
	DB_StrandingRisk *p = (DB_StrandingRisk *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(mmsi);
	SETJSON_S(name);
	SETJSON_I(type);
	SETJSON_I(risk);


	return root.serialize();
}

void * StrandingRisk::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_StrandingRisk *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_StrandingRisk *)malloc(sizeof(DB_StrandingRisk)*iArrayCount);
		memset(p, 0, sizeof(DB_StrandingRisk));
		DB_StrandingRisk *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_S(mmsi);
			AFIELD_S(name);
			AFIELD_I(type);
			AFIELD_D(risk);

			pArray++;
		}
	}
	
	return p;
}
