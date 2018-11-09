#include "../../stdafx.h"
#include "ServiceLog.h"


ServiceLog::ServiceLog()
{
}


ServiceLog::~ServiceLog()
{
}

void ServiceLog::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "common/ServiceLog;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "common/ServiceLog;insert";
}

string ServiceLog::SetStructToJson(void* struct_Param)
{
	DB_ServiceLog *p = (DB_ServiceLog *)struct_Param;

	web::json::value root;

    SETJSON_S(serviceName);
    SETJSON_S(intefaceName);
    SETJSON_S(regDateTime);
    SETJSON_S(content);
    
    
        
	return root.serialize();
}


void * ServiceLog::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_ServiceLog *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_ServiceLog *)malloc(sizeof(DB_ServiceLog)*iArrayCount);
		memset(p, 0, sizeof(DB_ServiceLog));
		DB_ServiceLog *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_S(serviceName);
            AFIELD_S(intefaceName);
            AFIELD_S(regDateTime);
            AFIELD_S(content);

			pArray++;
		}
	}
	
	return p;
}
