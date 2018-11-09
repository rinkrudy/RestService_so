#include "../../stdafx.h"
#include "ShipStaticInfo.h"
#include "./nested/EmergencyInfo.h"
#include "./nested/NavigationInfo.h"
#include "./nested/FireAlarm.h"
#include "./nested/FireDoor.h"
#include "./nested/Generator.h"
#include "./nested/MainEngine.h"
#include "./nested/OldFireAlarm.h"
#include "./nested/Ramp.h"
#include "./nested/Recovery.h"
#include "./nested/Stability.h"
#include "./nested/SteeringGear.h"
#include "./nested/TankLevel.h"
#include "./nested/Telegraph.h"


ShipStaticInfo::ShipStaticInfo()
{
}


ShipStaticInfo::~ShipStaticInfo()
{
}

void ShipStaticInfo::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv20/ShipStaticInfo;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv20/ShipStaticInfo;post";
}

string ShipStaticInfo::SetStructToJson(void* struct_Param)
{

	printf("Start Inserting ShipStaticInfo\n");
	DB_DataSetShipStaticInfo *p = (DB_DataSetShipStaticInfo *)struct_Param;

	
	web::json::value root;

	root["szShipmrn"] = json::value::string(p->szShipmrn);
	
	if(p->arrShipStaticInfoList.size() != 0)
	{
		root["arrShipStaticInfoList"] = web::json::value::array(p->arrShipStaticInfoList.size());
		printf("alloc arrShipStaticInfoList in datasetShipStaticInfo\n");
		json::value * tempData = &((root["arrShipStaticInfoList"].as_array())[0]);
		(*tempData)["nServiceId"] = p->arrShipStaticInfoList.at(0).nServiceId;
		(*tempData)["dLatitude"] = p->arrShipStaticInfoList.at(0).dLatitude;
		(*tempData)["dLongitude"] = p->arrShipStaticInfoList.at(0).dLongitude;
		(*tempData)["szUtcTime"] = json::value::string(p->arrShipStaticInfoList.at(0).szUtcTime);
		(*tempData)["szUtcDate"] = json::value::string(p->arrShipStaticInfoList.at(0).szUtcDate);

		if((p->arrShipStaticInfoList.at(0)).arrNavigationInfo.size() != 0)
		{
			(*tempData)["arrNavigationInfo"] = web::json::value::array((p->arrShipStaticInfoList.at(0)).arrNavigationInfo.size());
			NavigationInfo *pNavigationInfo = new NavigationInfo();
			pNavigationInfo->SetNavigationInfo_Json((*tempData)["arrNavigationInfo"].as_array(), (p->arrShipStaticInfoList.at(0)).arrNavigationInfo);

			auto naviInfo = ((*tempData)["arrNavigationInfo"]).as_array()[0];
			printf("starting write strData\n");
			printf("Success write : %s\n", naviInfo["szLOG"].as_string().c_str());
		}

		if(p->arrShipStaticInfoList.at(0).arrEmergencyInfo.size() != 0)
		{
			(*tempData)["arrEmergencyInfo"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrEmergencyInfo.size());
			EmergencyInfo *pEmergencyInfo = new EmergencyInfo();
			pEmergencyInfo->SetEmergencyInfo_Json((*tempData)["arrEmergencyInfo"].as_array(), (p->arrShipStaticInfoList.at(0)).arrEmergencyInfo);

			auto emInfo = (*tempData)["arrEmergencyInfo"].as_array()[0];
			printf("Success write emergencyData : %s\n", emInfo["szRunTime"].as_string().c_str());
		}

		FireDoor * pFireDoor = new FireDoor();
		(*tempData)["arrFireDoor"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrFireDoor.size());
		pFireDoor->Set_Json((*tempData)["arrFireDoor"].as_array(), (p->arrShipStaticInfoList.at(0)).arrFireDoor);

		FireAlarm * pFireAlarm = new FireAlarm();
		(*tempData)["arrFireAlarm"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrFireAlarm.size());
		pFireAlarm->Set_Json((*tempData)["arrFireAlarm"].as_array(), (p->arrShipStaticInfoList.at(0)).arrFireAlarm);
		Generator * pGenerator = new Generator();
		(*tempData)["arrGenerator"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrGenerator.size());
		pGenerator->Set_Json((*tempData)["arrGenerator"].as_array(), (p->arrShipStaticInfoList.at(0)).arrGenerator);
		MainEngine * pMainEngine = new MainEngine();
		(*tempData)["arrMainEngine"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrMainEngine.size());
		pMainEngine->Set_Json((*tempData)["arrMainEngine"].as_array(), (p->arrShipStaticInfoList.at(0)).arrMainEngine);
		OldFireAlarm * pOldFireAlarm = new OldFireAlarm();
		(*tempData)["arrOldFireAlarm"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrOldFireAlarm.size());
		pOldFireAlarm->Set_Json((*tempData)["arrOldFireAlarm"].as_array(), (p->arrShipStaticInfoList.at(0)).arrOldFireAlarm);
		Ramp * pRamp = new Ramp();
		(*tempData)["arrRamp"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrRamp.size());
		pRamp->Set_Json((*tempData)["arrRamp"].as_array(), (p->arrShipStaticInfoList.at(0)).arrRamp);
		Recovery * pRecovery = new Recovery();
		(*tempData)["arrRecovery"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrRecovery.size());
		pRecovery->Set_Json((*tempData)["arrRecovery"].as_array(), (p->arrShipStaticInfoList.at(0)).arrRecovery);
		Stability * pStability = new Stability();
		(*tempData)["arrStability"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrStability.size());
		pStability->Set_Json((*tempData)["arrStability"].as_array(), (p->arrShipStaticInfoList.at(0)).arrStability);
		SteeringGear * pSteeringGear = new SteeringGear();
		(*tempData)["arrSteeringGear"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrSteeringGear.size());
		pSteeringGear->Set_Json((*tempData)["arrSteeringGear"].as_array(), (p->arrShipStaticInfoList.at(0)).arrSteeringGear);
		TankLevel * pTankLevel = new TankLevel();
		(*tempData)["arrTankLevel"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrTankLevel.size());
		pTankLevel->Set_Json((*tempData)["arrTankLevel"].as_array(), (p->arrShipStaticInfoList.at(0)).arrTankLevel);
		Telegraph * pTelegraph = new Telegraph();
		(*tempData)["arrTelegraph"] = web::json::value::array(p->arrShipStaticInfoList.at(0).arrTelegraph.size());
		pTelegraph->Set_Json((*tempData)["arrTelegraph"].as_array(), (p->arrShipStaticInfoList.at(0)).arrTelegraph);

		
		
	}

	return root.serialize();
}


void * ShipStaticInfo::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_ShipStaticInfo *p;




	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_ShipStaticInfo *)malloc(sizeof(DB_ShipStaticInfo)*iArrayCount);
		memset(p, 0, sizeof(DB_ShipStaticInfo));
		DB_ShipStaticInfo *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			
			NavigationInfo *pNavigationInfo = new NavigationInfo();
			EmergencyInfo *pEmergencyInfo = new EmergencyInfo();
			FireAlarm * pFireAlarm = new FireAlarm();
			FireDoor * pFireDoor = new FireDoor();
			Generator * pGenerator = new Generator();
			MainEngine * pMainEngine = new MainEngine();
			OldFireAlarm * pOldFireAlarm = new OldFireAlarm();
			Ramp * pRamp = new Ramp();
			Recovery * pRecovery = new Recovery();
			Stability * pStability = new Stability();
			SteeringGear * pSteeringGear = new SteeringGear();
			TankLevel * pTankLevel = new TankLevel();
			Telegraph * pTelegraph = new Telegraph();
			pNavigationInfo->SetNavigationInfo_Struct(pArray[i].arrNavigationInfo, array[i].at("arrNavigationInfo").as_array());
			pEmergencyInfo->SetEmergencyInfo_Struct(pArray[i].arrEmergencyInfo, array[i].at("arrEmergencyInfo").as_array());

			pFireAlarm->Set_Struct(pArray[i].arrFireAlarm, array[i].at("arrFireAlarm").as_array());
			pFireDoor->Set_Struct(pArray[i].arrFireDoor, array[i].at("arrFireDoor").as_array());
			pGenerator->Set_Struct(pArray[i].arrGenerator, array[i].at("arrGenerator").as_array());
			pMainEngine->Set_Struct(pArray[i].arrMainEngine, array[i].at("arrMainEngine").as_array());
			pOldFireAlarm->Set_Struct(pArray[i].arrOldFireAlarm, array[i].at("arrOldFireAlarm").as_array());
			pRamp->Set_Struct(pArray[i].arrRamp, array[i].at("arrRamp").as_array());
			pRecovery->Set_Struct(pArray[i].arrRecovery, array[i].at("arrRecovery").as_array());
			pStability->Set_Struct(pArray[i].arrStability, array[i].at("arrStability").as_array());
			pSteeringGear->Set_Struct(pArray[i].arrSteeringGear, array[i].at("arrSteeringGear").as_array());
			pTankLevel->Set_Struct(pArray[i].arrTankLevel, array[i].at("arrTankLevel").as_array());
			pTelegraph->Set_Struct(pArray[i].arrTelegraph, array[i].at("arrTelegraph").as_array());
			
			AFIELD_I(nServiceId);
			AFIELD_S(szUtcDate);
			AFIELD_S(szUtcTime);
			AFIELD_D(dLatitude);
			AFIELD_D(dLongitude);

			pArray++;
		}
	}


	
	return p;
}

