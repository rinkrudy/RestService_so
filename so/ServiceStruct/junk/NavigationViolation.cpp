#include "../../stdafx.h"
#include "NavigationViolation.h"


NavigationViolation::NavigationViolation()
{
}


NavigationViolation::~NavigationViolation()
{
}

void NavigationViolation::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/NavigationViolation;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/NavigationViolation;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string NavigationViolation::SetStructToJson(void* struct_Param)
{
	DB_NavigationViolation *p = (DB_NavigationViolation *)struct_Param;

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

void * NavigationViolation::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_NavigationViolation *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_NavigationViolation *)malloc(sizeof(DB_NavigationViolation)*iArrayCount);
		memset(p, 0, sizeof(DB_NavigationViolation));
		DB_NavigationViolation *pArray = p;

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
