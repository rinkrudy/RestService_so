#include "../../stdafx.h"
#include "PastNavInfo.h"

PastNavInfo::PastNavInfo()
{
}

PastNavInfo::~PastNavInfo()
{
}
void PastNavInfo::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/PastNavInfo;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/PastNavInfo;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv30/PastNavInfo;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv30/PastNavInfoDel;delete";

}

void * PastNavInfo::GetStruct(json::value * root)
{
	auto array = root->at(U("data")).as_array();

	int iArrayCount = array.size();
	DB_PastNavInfo *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_PastNavInfo *)malloc(sizeof(DB_PastNavInfo)*iArrayCount);
		memset(p, 0, sizeof(DB_PastNavInfo));
		DB_PastNavInfo *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			AFIELD_S(dateTime);
			AFIELD_L(mmsi);
			AFIELD_D(latitude);
			AFIELD_D(longitude);
			AFIELD_D(sog);
			AFIELD_D(cog);
			AFIELD_D(heading);
			pArray++;
		}
	}

	return p;
}

