#include "../../stdafx.h"
#include "AttentionShip.h"


AttentionShip::AttentionShip()
{
}


AttentionShip::~AttentionShip()
{
}

void AttentionShip::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AttentionShip;get";;
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AttentionShip;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AttentionShip;delete";
}

string AttentionShip::SetStructToJson(void* struct_Param)
{
	DB_AttentionShip *p = (DB_AttentionShip *)struct_Param;

	web::json::value root;

	SETJSON_S(shipId);
	SETJSON_S(dateTime);
	SETJSON_S(name);
	SETJSON_I(type);
	SETJSON_S(attentionTime);
	SETJSON_I(attentionCode);
	SETJSON_I(shipLatitude);
	SETJSON_I(shipLongitude);
	SETJSON_S(content);

	return root.serialize();
}


void * AttentionShip::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_AttentionShip *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_AttentionShip *)malloc(sizeof(DB_AttentionShip)*iArrayCount);
		memset(p, 0, sizeof(DB_AttentionShip));
		DB_AttentionShip *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(shipId);
			AFIELD_S(dateTime);
			AFIELD_S(name);
			AFIELD_I(type);
			AFIELD_S(attentionTime);
			AFIELD_I(attentionCode);
			AFIELD_I(shipLatitude);
			AFIELD_I(shipLongitude);
			AFIELD_S(content);
			pArray++;
		}
	}
	
	return p;
}
