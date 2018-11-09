#include "../../stdafx.h"
#include "AccidentAdvice.h"
#include "EnaviDBService.h"


AccidentAdvice::AccidentAdvice()
{
}


AccidentAdvice::~AccidentAdvice()
{
}

void AccidentAdvice::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AccidentAdvice;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AccidentAdvice;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = " ";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = " ";
}

string AccidentAdvice::SetStructToJson(void* struct_Param)
{
	DB_AccidentAdvice *p = (DB_AccidentAdvice *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(accidentTime);
	SETJSON_S(oSMmsi);
	SETJSON_S(tSMmsi);
	SETJSON_I(accidentLatitude);
	SETJSON_I(accidentLongitude);
	SETJSON_I(accidentArea);



	return root.serialize();
}

void * AccidentAdvice::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_AccidentAdvice *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_AccidentAdvice *)malloc(sizeof(DB_AccidentAdvice)*iArrayCount);
		memset(p, 0, sizeof(DB_AccidentAdvice));
		DB_AccidentAdvice *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_S(dateTime);
			AFIELD_S(accidentTime);
			AFIELD_S(oSMmsi);
			AFIELD_S(tSMmsi);
			AFIELD_I(accidentLatitude);
			AFIELD_I(accidentLongitude);
			AFIELD_I(accidentArea);

			pArray++;
		}
	}
	
	return p;
}


