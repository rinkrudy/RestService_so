#include "../stdafx.h"
#include "VesselStaticInfo.h"


VesselStaticInfo::VesselStaticInfo()
{
}


VesselStaticInfo::~VesselStaticInfo()
{
}
void VesselStaticInfo::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "VesselStaticInfo;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "VesselStaticInfo;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "VesselStaticInfo;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "VesselStaticInfo;delete";
}

string VesselStaticInfo::SetStructToJson(void * struct_Param)
{
	DB_VesselStaticInfo *p = (DB_VesselStaticInfo *)struct_Param;
	json::value root;

	SETJSON_S(shipMrn);
	SETJSON_S(mmsi);
	SETJSON_S(dateTime);
	SETJSON_S(shipName);
	SETJSON_S(callSign);
	SETJSON_I(shipType);
	SETJSON_I(dima);
	SETJSON_I(dimb);
	SETJSON_I(dimc);
	SETJSON_I(dimd);
	SETJSON_I(gnssType);
	SETJSON_I(maxDraught);
	SETJSON_I(aisLength);
	SETJSON_I(aisBeam);
	SETJSON_I(gpsAntennaXLocation);
	SETJSON_I(gpsAntennaYLocation);
	//SETJSON_S(shipCode);
	SETJSON_I(shipLoa);
	SETJSON_I(shipLpp);
	SETJSON_I(shipWeight);
	SETJSON_I(shipDwt);
	SETJSON_I(cargoCode);
	SETJSON_I(cargoWeight);
	SETJSON_I(fuelRemain);
	SETJSON_I(shipDraftFwd);
	SETJSON_I(shipDraftAft);
	SETJSON_I(rudNum);
	SETJSON_I(rudArea);
	SETJSON_I(aisImoNumber);
	SETJSON_I(shipDisplacement);
	//SETJSON_S(shipFlag);
	//SETJSON_S(hullType);
	SETJSON_I(shipBreadth);
	SETJSON_I(shipDepth);
//	SETJSON_S(vesselType);
	SETJSON_I(shipEngineHp);
	

	return root.serialize();
}

void * VesselStaticInfo::GetStruct(json::value * root)
{

	auto array = root->at(U("data")).as_array();

	int iArrayCount = array.size();
	DB_VesselStaticInfo *p;
	if (iArrayCount == 0)
	{
		return nullptr;
	}
	else
	{
		p = (DB_VesselStaticInfo *)malloc(sizeof(DB_VesselStaticInfo)*iArrayCount);
		memset(p, 0, sizeof(DB_VesselStaticInfo));
		DB_VesselStaticInfo *pArray = p;
		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����

			AFIELD_S(shipMrn);
			AFIELD_S(mmsi);
			AFIELD_S(dateTime);
			AFIELD_S(shipName);
			AFIELD_S(callSign);
			AFIELD_I(shipType);
			AFIELD_I(dima);
			AFIELD_I(dimb);
			AFIELD_I(dimc);
			AFIELD_I(dimd);
			AFIELD_I(gnssType);
			AFIELD_I(maxDraught);
			AFIELD_D(aisLength);
			AFIELD_D(aisBeam);
			AFIELD_I(gpsAntennaXLocation);
			AFIELD_I(gpsAntennaYLocation);
			AFIELD_S(shipCode);
			AFIELD_I(shipLoa);
			AFIELD_I(shipLpp);
			AFIELD_I(shipWeight);
			AFIELD_I(shipDwt);
			AFIELD_I(cargoCode);
			AFIELD_I(cargoWeight);
			AFIELD_I(fuelRemain);
			AFIELD_D(shipDraftFwd);
			AFIELD_D(shipDraftAft);
			AFIELD_I(rudNum);
			AFIELD_D(rudArea);
			AFIELD_I(aisImoNumber);
			AFIELD_D(shipDisplacement);
			AFIELD_S(shipFlag);
			AFIELD_S(hullType);
			AFIELD_D(shipBreadth);
			AFIELD_D(shipDepth);
			AFIELD_S(vesselType);
			AFIELD_D(shipEngineHp);

			pArray++;
		}
	}
	
	return p;
	
}
