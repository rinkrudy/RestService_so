#include "../../stdafx.h"
#include "ShipDensity.h"


ShipDensity::ShipDensity()
{
}


ShipDensity::~ShipDensity()
{
}

void ShipDensity::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/ShipDensity;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv51/ShipDensity;post";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv51/ShipDensityDel;delete";

}
string ShipDensity::SetStructToJson(void* struct_Param)
{
	DB_ShipDensity *p = (DB_ShipDensity *)struct_Param;

		web::json::value root;


	SETJSON_I(index);
	SETJSON_S(time);
	SETJSON_I(pointLat1);
	SETJSON_I(pointLon1);
	SETJSON_I(pointLat2);
	SETJSON_I(pointLon2);
	SETJSON_I(pointLat3);
	SETJSON_I(pointLon3);
	SETJSON_I(pointLat4);
	SETJSON_I(pointLon4);
	SETJSON_I(densityValue);
	SETJSON_I(shipCount);
    		
	return root.serialize();
}
void * ShipDensity::GetStruct(json::value * root)
{	
	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_ShipDensity *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_ShipDensity *)malloc(sizeof(DB_ShipDensity)*iArrayCount);
		memset(p, 0, sizeof(DB_ShipDensity));
		DB_ShipDensity *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_I(index);
			AFIELD_S(time);
			AFIELD_D(pointLat1);
			AFIELD_D(pointLon1);
			AFIELD_D(pointLat2);
			AFIELD_D(pointLon2);
			AFIELD_D(pointLat3);
			AFIELD_D(pointLon3);
			AFIELD_D(pointLat4);
			AFIELD_D(pointLon4);
			AFIELD_D(densityValue);
			AFIELD_L(shipCount);


			pArray++;
		}
	}
	
	return p;
}
