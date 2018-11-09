#include "../../stdafx.h"
#include "ShipPosition.h"


ShipPosition::ShipPosition()
{
}


ShipPosition::~ShipPosition()
{
}


void ShipPosition::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv51/ShipPosition;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv51/ShipPosition;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv51/ShipPosition;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv51/ShipPositionDel;delete";
	
}

void * ShipPosition::GetStruct(json::value * root)
{

	printf("Called SelectData of ShipPosition\n");
	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_ShipPosition *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_ShipPosition *)malloc(sizeof(DB_ShipPosition)*iArrayCount);
		memset(p, 0, sizeof(DB_ShipPosition));
		DB_ShipPosition *pArray = p;

		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_I(mmsi);
			AFIELD_S(time);
			AFIELD_D(cog);
			AFIELD_D(sog);
			AFIELD_D(latitude);
			AFIELD_D(longitude);

			pArray++;
		}
	}

	printf("Ship PositionData return\n");
	
	return p;
}
