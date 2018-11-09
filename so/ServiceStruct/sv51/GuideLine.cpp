#include "../../stdafx.h"
#include "GuideLine.h"


GuideLine::GuideLine()
{
}


GuideLine::~GuideLine()
{
}

void GuideLine::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/Guideline;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv51/Guideline;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv51/GuidelineDel;delete";

}
string GuideLine::SetStructToJson(void* struct_Param)
{
	DB_GuideLine *p = (DB_GuideLine *)struct_Param;

	web::json::value root;


    		SETJSON_I(guidelineId);
			SETJSON_I(guideSimbolType);
			SETJSON_I(displayType);
			SETJSON_I(pointLat1);
			SETJSON_I(pointLon1);
			SETJSON_I(pointLat2);
			SETJSON_I(pointLon2);
			SETJSON_I(pointLat3);
			SETJSON_I(pointLon3);
			SETJSON_I(pointLat4);
			SETJSON_I(pointLon4);
			SETJSON_S(message);
	return root.serialize();
}
void * GuideLine::GetStruct(json::value * root)
{	
	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_GuideLine *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_GuideLine *)malloc(sizeof(DB_GuideLine)*iArrayCount);
		memset(p, 0, sizeof(DB_GuideLine));
		DB_GuideLine *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_I(guidelineId);
			AFIELD_I(guideSimbolType);
			AFIELD_I(displayType);
			AFIELD_D(pointLat1);
			AFIELD_D(pointLon1);
			AFIELD_D(pointLat2);
			AFIELD_D(pointLon2);
			AFIELD_D(pointLat3);
			AFIELD_D(pointLon3);
			AFIELD_D(pointLat4);
			AFIELD_D(pointLon4);
			AFIELD_S(message);


			pArray++;
		}
	}
	
	return p;
}
