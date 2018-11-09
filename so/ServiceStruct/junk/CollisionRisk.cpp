#include "../../stdafx.h"
#include "CollisionRisk.h"


CollisionRisk::CollisionRisk()
{
}


CollisionRisk::~CollisionRisk()
{
}

void CollisionRisk::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/CollisionRisk;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/CollisionRisk;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string CollisionRisk::SetStructToJson(void* struct_Param)
{
	DB_CollisionRisk *p = (DB_CollisionRisk *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(mmsi);
	SETJSON_S(name);
	SETJSON_I(type);
	SETJSON_I(risk);

	return root.serialize();
}

void * CollisionRisk::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_CollisionRisk *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_CollisionRisk *)malloc(sizeof(DB_CollisionRisk)*iArrayCount);
		memset(p, 0, sizeof(DB_CollisionRisk));
		DB_CollisionRisk *pArray = p;

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
