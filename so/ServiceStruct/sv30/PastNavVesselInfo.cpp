#include "../../stdafx.h"
#include "PastNavVesselInfo.h"

PastNavVesselInfo::PastNavVesselInfo()
{
}

PastNavVesselInfo::~PastNavVesselInfo()
{
}
void PastNavVesselInfo::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv30/PastNavVesselInfo;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv30/PastNavVesselInfo;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv30/PastNavVesselInfo;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv30/PastNavVesselInfoDel;delete";
}

void * PastNavVesselInfo::GetStruct(json::value * root)
{

	json::value tempValue = *root;

	auto array = tempValue.at(U("data")).as_array();

	int iArrayCount = array.size();

	DB_PastNavVesselInfo *p;

	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_PastNavVesselInfo *)malloc(sizeof(DB_PastNavVesselInfo)*iArrayCount);
		memset(p, 0, sizeof(DB_PastNavVesselInfo) * iArrayCount);
		DB_PastNavVesselInfo *pArray = p;
		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����

			AFIELD_L(mmsi);
			AFIELD_S(callSign);
			AFIELD_S(vesselType);
			AFIELD_L(imo);
			AFIELD_S(callSign);
			AFIELD_D(dimA);
			AFIELD_D(dimB);
			AFIELD_D(dimC);
			AFIELD_D(dimD);
			AFIELD_D(draft);

			pArray++;
		}
	}

	return p;
	}	
