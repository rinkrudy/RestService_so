#include "../../stdafx.h"
#include "SpecThreshold.h"


SpecThreshold::SpecThreshold()
{
}


SpecThreshold::~SpecThreshold()
{
}

void SpecThreshold::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/SpecThreshold;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/SpecThreshold;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/SpecThreshold;delete";
}

string SpecThreshold::SetStructToJson(void* struct_Param)
{
	DB_SpecThreshold *p = (DB_SpecThreshold *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(version);
	SETJSON_S(sv30Threshold);
	SETJSON_S(abnormalThreshold);
	SETJSON_S(sVAThreshold);
	SETJSON_S(vBRSThreshold);
	SETJSON_S(rSSThreshold);

	return root.serialize();
}

void * SpecThreshold::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_SpecThreshold *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_SpecThreshold *)malloc(sizeof(DB_SpecThreshold)*iArrayCount);
		memset(p, 0, sizeof(DB_SpecThreshold));
		DB_SpecThreshold *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_S(version);
			AFIELD_S(sv30Threshold);
			AFIELD_S(abnormalThreshold);
			AFIELD_S(sVAThreshold);
			AFIELD_S(vBRSThreshold);
			AFIELD_S(rSSThreshold);

			pArray++;
		}
	}
	
	return p;
}
