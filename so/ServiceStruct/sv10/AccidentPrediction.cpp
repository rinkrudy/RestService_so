#include "../../stdafx.h"
#include "AccidentPrediction.h"


AccidentPrediction::AccidentPrediction()
{
}


AccidentPrediction::~AccidentPrediction()
{
}

void AccidentPrediction::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv10/AccidentPrediction;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv10/AccidentPrediction;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv10/AccidentPrediction;delete";
}

string AccidentPrediction::SetStructToJson(void* struct_Param)
{
	DB_AccidentPrediction *p = (DB_AccidentPrediction *)struct_Param;

	web::json::value root;

	SETJSON_S(dateTime);
	SETJSON_S(accidentTime);
	SETJSON_I(accidentLatitude);
	SETJSON_I(accidentLongitude);
	SETJSON_S(oSMmsi);
	SETJSON_C(accidentType);
	SETJSON_C(accidentType2);
	SETJSON_S(tSMmsi);
	SETJSON_S(lastTimeSrc);
	SETJSON_C(rOTSrc);
    SETJSON_I(sOGSrc);
    SETJSON_I(lATSrc);
    SETJSON_I(lONSrc);
    SETJSON_I(cOGSrc);
    SETJSON_I(hDGSrc);
    SETJSON_S(targetLastTimeSrc);
	SETJSON_C(targetROTSrc);
    SETJSON_I(targetSOGSrc);
    SETJSON_I(targetLATSrc);
    SETJSON_I(targetLONSrc);
    SETJSON_I(targetCOGSrc);
    SETJSON_I(targetHDGSrc);


	return root.serialize();
}

void * AccidentPrediction::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_AccidentPrediction *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_AccidentPrediction *)malloc(sizeof(DB_AccidentPrediction)*iArrayCount);
		memset(p, 0, sizeof(DB_AccidentPrediction));
		DB_AccidentPrediction *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_S(dateTime);
			AFIELD_S(accidentTime);
			AFIELD_I(accidentLatitude);
			AFIELD_I(accidentLongitude);
			AFIELD_S(oSMmsi);
			AFIELD_C(accidentType);
			AFIELD_C(accidentType2);
			AFIELD_S(tSMmsi);
			AFIELD_S(lastTimeSrc);
			AFIELD_C(rOTSrc);
		    AFIELD_I(sOGSrc);
		    AFIELD_I(lATSrc);
		    AFIELD_I(lONSrc);
		    AFIELD_I(cOGSrc);
		    AFIELD_I(hDGSrc);
		    AFIELD_S(targetLastTimeSrc);
			AFIELD_C(targetROTSrc);
		    AFIELD_I(targetSOGSrc);
		    AFIELD_I(targetLATSrc);
		    AFIELD_I(targetLONSrc);
		    AFIELD_I(targetCOGSrc);
		    AFIELD_I(targetHDGSrc);
			pArray++;
		}
	}
	
	return p;
}
