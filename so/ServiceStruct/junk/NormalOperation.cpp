#include "../../stdafx.h"
#include "NormalOperation.h"


NormalOperation::NormalOperation()
{
}


NormalOperation::~NormalOperation()
{
}

void NormalOperation::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/NormalOperation;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/NormalOperation;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string NormalOperation::SetStructToJson(void* struct_Param)
{
	DB_NormalOperation *p = (DB_NormalOperation *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(id);
	SETJSON_S(name);
	SETJSON_I(vertexCnt);
	SETJSON_I(latitude);
	SETJSON_I(longitude);
	SETJSON_S(gpsString);


	return root.serialize();
}

void * NormalOperation::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_NormalOperation *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_NormalOperation *)malloc(sizeof(DB_NormalOperation)*iArrayCount);
		memset(p, 0, sizeof(DB_NormalOperation));
		DB_NormalOperation *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_S(id);
			AFIELD_S(name);
			AFIELD_I(vertexCnt);
			AFIELD_I(latitude);
			AFIELD_I(longitude);
			AFIELD_S(gpsString);

			pArray++;
		}
	}
	
	return p;
}
