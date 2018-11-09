#include "ProgressMNG.h"
#include "./so/ServiceStruct/EnaviDBStruct.h"

using namespace Service;

ProgressMNG *ProgressMNG::m_Instance = nullptr;

ProgressMNG::ProgressMNG()
{
    m_arrService.clear();
}
ProgressMNG::~ProgressMNG()
{
}

void ProgressMNG::Init()
{
    
    
    
}

bool ProgressMNG::CreateInstance()
{
    if (m_Instance)
        return false;
    m_Instance = new ProgressMNG();
    return true;
}
ProgressMNG *ProgressMNG::GetInstance()
{
    return m_Instance;
}
void ProgressMNG::DestoryInstance()
{
    if (m_Instance)
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
    return;
}


void ProgressMNG::printServiceList()
{
 
}

int ProgressMNG::restCall_Select(string *pStr)
{
    int nInput;
    // Input Service
    std::cin >> nInput;
    
        if (nInput == (int)E_Service::eCatalogue)
        {
            //*pStr = "category=EN&zone=A1&productversion=KR/2017-NTM-000&enctype=S-101&encrypt=false&same=false";
            *pStr = "category=EN&enctype=S-101&zone=A1&productversion=WK42_17   &encrypt=false&same=true";
        }
        else if (nInput == (int)E_Service::eCatalogueAll)
        {
            *pStr = "category=category1&zone=A1";
        }
        else if (nInput == (int)E_Service::eEncUpdate)
        {
            *pStr = "license=MIT";
        }
        else if (nInput == (int)E_Service::eS57Cell)
        {
            *pStr = "";
        }
        else if (nInput == (int)E_Service::eS101Cell)
        {
            *pStr = "";
        }
        else if (nInput == (int)E_Service::ePastNavInfo)
        {
            *pStr = "startLatitude=33.51&startLongitude=126.02&endLatitude=33.53&endLongitude=126.04&startTime=20180509120000&endTime=20180909120000";
        }
        else if (nInput == (int)E_Service::ePastNavVesselInfo)
        {
            *pStr = "mmsi=1";
        }
        
        else if (nInput == (int)E_Service::eShipPosition)
        {
            *pStr = "";
        }
        else if (nInput == (int)E_Service::eGuideLine)
        {
            *pStr = "latitude=33.5&longitude=126.01&rangeKm=1";
        }
        else if (nInput == (int)E_Service::eZone)
        {
            *pStr = "name=SC";
        }
        else if(nInput == (int)E_Service::eRoute)
        {
            *pStr = "mmsi=2&voyage=123";
        }
        else if(nInput == (int)E_Service::eRouteInfo)
        {
            *pStr = "routeId=1&vesselMmsi=1&vesselVoyage=vV1";
        }
        else if(nInput == (int)E_Service::eWaypoints)
        {
            *pStr = "routeId=1";
        }
        else if(nInput == (int)E_Service::eSchedules)
        {
            *pStr = "routeId=1";
        }
        else if(nInput == (int)E_Service::eFTS)
        {
            *pStr = "routeId=1";
        }
        else if(nInput == (int)E_Service::eAttentionShip)
        {
            *pStr = "shipId=12345&attentionTimeFrom=20180101000000&attentionTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eAbnormalPattern)
        {
            *pStr = "shipId=123&dateTimeFrom=20180101000000&dateTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eSpecThreshold)
        {
            *pStr = " ";
        }
        else if(nInput == (int)E_Service::eDangerShipAlarm)
        {
            *pStr = "mmsi=12345&dateTimeFrom=20180101000000&dateTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eAccidentRisk)
        {
            *pStr = "oSMmsi=12345&tSMmsi=123&accidentType=0&dateTimeFrom=20180101000000&dateTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eAccidentPrediction)
        {
            *pStr = "oSMmsi=12345&tSMmsi=123456&accidentTimeFrom=20180101000000&accidentTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eGuideLine)
        {
            *pStr = "latitude=33.5&longitude=126.01&rangeKm=1";
        }
        else if(nInput == (int)E_Service::eGuideLineAnchorage)
        {
            pStr->assign("harbor=부산");
        }
        else if(nInput == (int)E_Service::eGuideLineCourse)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineFairway)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineInfo)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLinePilot)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLinePoint)
        {
            *pStr = "";
        }
        else if(nInput == (int)E_Service::eGuideLineSpeed)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineSafetySpeed)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineSafetyStan)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineTug)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineVTS)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eGuideLineWharf)
        {
            *pStr = "harbor=pusan";
        }
        else if(nInput == (int)E_Service::eAvsResponse)
        {
            *pStr = "osShipId=OSS1&tsShipId=TSS1";
        }
        else if(nInput == (int)E_Service::eVulInput00_2)
        {
            *pStr = "shipId=F1&dateTimeFrom=20180101000000&dateTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eRssResponse)
        {
            *pStr = "osShipId=OSS1&tsShipId=TSS1";
        }
        else if(nInput == (int)E_Service::eVulInput06)
        {
            *pStr = "paramTime=20180901520000";
        }
        else if(nInput == (int)E_Service::eVulInput07)
        {
            *pStr = "paramTime=20180901520000";
        }
        else if(nInput == (int)E_Service::eAreaSelect)
        {
            *pStr = "areaId=123";
        }
        else if(nInput == (int)E_Service::eAreaDetail)
        {
            *pStr = "areaId=123";
        }
        else if(nInput == (int)E_Service::eAreaMst)
        {
            *pStr = "areaId=123&areaType=1";
        }
        else if(nInput == (int)E_Service::eVulInput05)
        {
            *pStr = "shipId=S1";
        }
        else if(nInput == (int)E_Service::eFishingPatternArea)
        {
            *pStr = "dateTimeFrom=20180901010000&dateTimeTo=20180930180000";
        }
        else if(nInput == (int)E_Service::eFishingHistoryArea)
        {
            *pStr = "fisheryType=1&paramTime=20180919170000";
        }
        else if(nInput == (int)E_Service::eVulInput00_1)
        {
            *pStr = "firstShipId=F1&secondShipId=S1&dateTimeFrom=20180101000000&dateTimeTo=20181231235959";
        }
        else if(nInput == (int)E_Service::eShipStaticInfo)
        {
            *pStr = "serviceId=1&startUtcDateTime=20180901000000&endUtcDateTime=20180930235959";
        }
        else if(nInput == (int)E_Service::eVesselStaticinfo)
        {
            *pStr = "mmsi=995763";
        }
        else if(nInput == (int)E_Service::eFeaturesForWaterway)
        {
            *pStr = "spec=s124&version=1.0&type=member&startDate=2017-01-01 00:00:00&endDate=2018-12-31 23:00:00&geom=POINT(125.99970475393 37.4048868543718)&radius=1";
        }
        else if((nInput) == (int)E_Service::eArgoMet)
        {
            *pStr = "type=point&coordinateGeoXY=127.87038 34.6007,127.93605 34.61893,127.98248 34.6575,128.03741 34.61004,128.00308 34.5863,128.03192 34.56256,127.95858 34.56418,127.91819 34.52508,127.87038 34.6007&startDateTime=2018-09-11T15:00:00.000&endDateTime=2018-09-13T15:00:00.000&catalog=WAVE_WIND_SPEED,WAVE_WIND_DIRECTION";
        }
        else
            *pStr ="";


    return nInput;
}

int ProgressMNG::restCall_Insert(void **ppParam)
{
    int nInput;
    std::cin >> nInput;
    // Temp Progress
    switch (nInput)
    {
    case (int)E_Service::eCatalogue:
        *ppParam = SetCatalogue_Insert();
        break;
    case (int)E_Service::eEncUpdate:
        *ppParam = SetEncUpdate();
        break;
    case (int)E_Service::eS57Cell:
        *ppParam = SetS57Cell();
        break;
    case (int)E_Service::eS101Cell:
        *ppParam = SetS101Cell();
        break;
    case (int)E_Service::eGuideLine:
        *ppParam = SetGuideLine_Insert();
        break;
    case (int)E_Service::eZone:
        *ppParam = SetZone_Insert();
        break;
    case (int)E_Service::eAccidentPrediction:
        *ppParam = SetAccidentPrediction();
        break;
    case (int)E_Service::eAccidentRisk:
        *ppParam = SetAccidentRisk();
        break;
    case (int)E_Service::eAttentionShip:
        *ppParam = SetAttentionShip();
        break;
    case (int)E_Service::eDangerShipAlarm:
        *ppParam = SetDangerShipAlarm();
        break;
    case (int)E_Service::eSpecThreshold:
        *ppParam = SetSpecThreshold();
        break;
    case (int)E_Service::eRoute:
        *ppParam = SetRoute();
        break;
    case (int)E_Service::eRouteInfo:
        *ppParam = SetRouteInfo();
        break;
    case (int)E_Service::eWaypoints:
        *ppParam = SetWaypoints();
        break;
    case (int)E_Service::eSchedules:
        *ppParam = SetSchedules();
        break;
    case (int)E_Service::eFTS:
        *ppParam = SetFTS();
        break;
    case (int)E_Service::eAreaMst:
        *ppParam = SetareaMst();
        break;
    case (int)E_Service::eAreaDetail:
        *ppParam = SetareaDetail();
        break;
    case (int)E_Service::eVulInput00_1:
        *ppParam = SetvulInput00_1();
        break;
    case (int)E_Service::eVulInput00_2:
        *ppParam = SetvulInput00_2();
        break;
    case (int)E_Service::eVulInput01:
        *ppParam = SetvulInput01();
        break;
    case (int)E_Service::eVulInput02:
        *ppParam = SetvulInput02();
        break;
    case (int)E_Service::eVulInput03:
        *ppParam = SetvulInput03();
        break;
    case (int)E_Service::eVulInput04:
        *ppParam = SetvulInput04();
        break;
    case (int)E_Service::eVulInput05:
        *ppParam = SetvulInput05();
        break;
    case (int)E_Service::eVulInput06:
        *ppParam = SetvulInput06();
        break;
    case (int)E_Service::eVulInput07:
        *ppParam = SetvulInput07();
        break;
    case (int)E_Service::eAvsResponse:
        *ppParam = SetavsResponse();
        break;
    case (int)E_Service::eRssResponse:
        *ppParam = SetrssResponse();
        break;
    case (int)E_Service::eFishingHistoryArea:
        *ppParam = SetfishingHistoryArea();
        break;
    case (int)E_Service::eFishingPatternArea:
        *ppParam = SetfishingPatternArea();
        break;
    case (int)E_Service::eAbnormalPattern:
        *ppParam = SetabnormalPattern();
        break;
    case (int)E_Service::eShipStaticInfo:
        *ppParam = SetShipStaticInfo();
        break;
    case (int)E_Service::eShipDensity:
        *ppParam = SetShipDensity();
        break;
    case (int)E_Service::eVesselStaticinfo:
        *ppParam = SetVessel_Insert();
        break;
    case (int)E_Service::eMrnRecentVersion:
        *ppParam = SetMrnRecentVersion();


    
    }

    return nInput;
}
int ProgressMNG::restCall_Update(void **ppParam)
{
    int nInput;
    std::cin >> nInput;

    // Temp Progress
    switch (nInput)
    {
    case (int)E_Service::eCatalogue:
        *ppParam = SetCatalogue_Insert();
        break;
    case (int)E_Service::eGuideLine:
        *ppParam = SetGuideLine_Insert();
        break;
    case (int)E_Service::eZone:
        *ppParam = SetZone_Insert();
        break;
    case (int)E_Service::eMrnRecentVersion:
        *ppParam = SetMrnRecentVersion();
        break;
    }

    /*
    if(pInfo->success){

		printf("Success Result : %s\n", (pInfo->msg).c_str());
		printf("Data : %d\n", pInfo->data);   
    }
*/
    return nInput;
}
int ProgressMNG::restCall_Delete(void **ppParam)
{
    int nInput;
    std::cin >> nInput;
    // Temp Progress
    switch (nInput)
    {
    case (int)E_Service::eCatalogue:
        *ppParam = SetCatalogue_Insert();
        break;
    case (int)E_Service::eGuideLine:
        *ppParam = SetGuideLine_Insert();
        break;
    case (int)E_Service::eZone:
        *ppParam = SetZone_Insert();
        break;
    case (int)E_Service::eMrnRecentVersion:
        *ppParam = SetMrnRecentVersion();
        break;
        
    }

    /*
    if(pInfo->success){

		printf("Success Result : %s\n", (pInfo->msg).c_str());
		printf("Data : %d\n", pInfo->data);   
    }
*/
    return nInput;
}

int ProgressMNG::Progress()
{
    int nInput;
    std::cout << "Wait for your signal" << std::endl;
    std::cout << "0 : Quit, 1 : Select, 2 : Insert, 3 : Update, 4 : Delete" << std::endl;
    // Input Rest Service Type or Quit
    std::cin >> nInput;
    bool bContinue = true;

    if (nInput == 0)
        return 0;

    printServiceList();
    return nInput;
}


void *ProgressMNG::SetCatalogue_Insert()
{
    DB_Catalogue *p = (DB_Catalogue *)malloc(sizeof(DB_Catalogue));
    memset(p, 0x00, sizeof(p));

    p->catalogid = 2;
    strcpy(p->idIdentifier, "id2");
    p->idEditionnumber = 1;

    strcpy(p->idDate, "2017-10-13");
    strcpy(p->exchangecatalogname, "exchange2");
    strcpy(p->cataloguepath, "cataloguepath");
    strcpy(p->category, "catgory2");
    strcpy(p->fileuri, "fileuri");
    strcpy(p->filedmzuri, "filedmzuri");
    strcpy(p->filename, "filename2");
    strcpy(p->zone, "EU");
    strcpy(p->productversion, "1.1");
    strcpy(p->enctype, "1");
    strcpy(p->encrypt, "encrypt10");
    strcpy(p->hash, "hashvalue1");
    strcpy(p->productdate, "2017-10-13");

    p->filesize = 200;

    return p;
}
void *ProgressMNG::SetVessel_Insert()
{
    DB_VesselStaticInfo *p = (DB_VesselStaticInfo *)malloc(sizeof(DB_VesselStaticInfo));
    memset(p, 0x00, sizeof(p));


    strcpy(p->mmsi, "995763");
    strcpy(p->dateTime, "2017-03-29");
    strcpy(p->shipName, "패스파인더호");
    strcpy(p->callSign, "DSFD9");
    p->shipType = 1;
    p->dima = 0;
    p->dimb = 0;
    p->dimc = 0;
    p->dimd = 0;
    p->gnssType = 0;
    p->maxDraught = 0;
    p->aisLength = 103;
    p->aisBeam = 16;
    p->gpsAntennaXLocation = 0;
    p->gpsAntennaYLocation = 0;
    p->shipLoa = 0;
    p->shipLpp = 0;
    p->shipWeight = 3901;
    p->shipDwt = 0;
    p->cargoCode = 0;
    p->cargoWeight = 0;
    p->fuelRemain = 0;
    p->shipDraftFwd = 0.0f;
    p->shipDraftAft = 0.0f;
    p->rudNum = 0;
    p->rudArea = 0.0f;
    p->aisImoNumber = 8718720;
    p->shipDisplacement = 0.0f;
    p->shipBreadth = 0.0f;
    p->shipDepth = 8.0f;
    p->shipEngineHp = 0.0f;


    return p;
}

void *ProgressMNG::SetOptimumRoute_Insert()
{
    DB_OptimumRouteInfo *p = (DB_OptimumRouteInfo *)malloc(sizeof(DB_OptimumRouteInfo));
    memset(p, 0x00, sizeof(p));

    p->shipMmsi = 3;
    p->routeCount = 200;
    p->type = 11;
    strcpy(p->routeDate, "20180515130000");
    strcpy(p->lastTime, "20180517130000");
    strcpy(p->expectArriveTime, "20180517130000");
    return p;
}

void *ProgressMNG::SetOptimumRoute_Ect_Insert()
{
    DB_OptimumRouteInfo_Etc *p = (DB_OptimumRouteInfo_Etc *)malloc(sizeof(DB_OptimumRouteInfo_Etc));
    memset(p, 0x00, sizeof(p));

    p->id = 1;
    p->countNumber = 5;
    p->latitude = 33.7;
    p->longitude = 126.05;
    p->speed = 90;
    p->course = 100;
    strcpy(p->nextDistance, "20180517130000");
    return p;
}
void *ProgressMNG::SetGuideLine_Insert()
{
    DB_GuideLine *p = (DB_GuideLine *)malloc(sizeof(DB_GuideLine));
    memset(p, 0x00, sizeof(p));

    p->guidelineId = 3;
    p->guideSimbolType = 2;
    p->displayType = 1;
    p->pointLat1 = 33.5;
    p->pointLon1 = 126.01;
    strcpy(p->message, "msg1");

    return p;
}

void *ProgressMNG::SetZone_Insert()
{

    DB_Zone *p = (DB_Zone *)malloc(sizeof(DB_Zone));
    memset(p, 0x00, sizeof(DB_Zone));

    strcpy(p->name, "W4");
    strcpy(p->slat, "38.100000");

    strcpy(p->wlon, "127.000000");

    strcpy(p->nlat, "38.000000");

    strcpy(p->elon, "-180.000000");
    //strcpy(p->version, "-180.000000");    

    return p;
}

void * ProgressMNG::SetAccidentPrediction()
{
    DB_AccidentPrediction *p = (DB_AccidentPrediction *)malloc(sizeof(DB_AccidentPrediction));
    memset(p, 0x00, sizeof(DB_AccidentPrediction));

    strcpy(p->dateTime, "20180718140100");
    strcpy(p->accidentTime, "20180718140000");
    strcpy(p->oSMmsi, "12345");
    strcpy(p->tSMmsi, "123456");
    p->accidentLatitude = 128;
    p->accidentLongitude = 32;
    p->accidentType = '0';
    p->accidentType2 = '0';
    strcpy(p->lastTimeSrc, "20180718135000");
    //p->rOTSrc = "80";
    p->sOGSrc = 35;
    p->lATSrc = 45;
    p->lONSrc = 55;
    p->cOGSrc = 65;
    p->hDGSrc = 75;
    strcpy(p->targetLastTimeSrc, "20180718135500");
    //p->targetROTSrc = "33";
    p->targetSOGSrc = 43;
    p->targetLATSrc = 53;
    p->targetLONSrc = 63;
    p->targetCOGSrc = 73;
    p->targetHDGSrc = 83;
    
    return p;
}
void * ProgressMNG::SetAccidentRisk()
{
    DB_AccidentRisk *p = (DB_AccidentRisk *)malloc(sizeof(DB_AccidentRisk));
    memset(p, 0x00, sizeof(DB_AccidentRisk));

    strcpy(p->dateTime, "20180916220000");
    p->alarmStatus = '0';
    strcpy(p->oSMmsi, "12345");
    p->oSLongitude = 130;
    p->oSLatitude = 30;
    p->oSCog = 10;
    p->oSSog = 20;
    p->accidentType = '0';
    p->accidentType2 = '0';
    strcpy(p->tSMmsi, "123");
    p->tSLongitude = 120;
    p->tSLatitude = 20;
    p->tSCog = 15;
    p->tSSog = 45;
    strcpy(p->collisionType, "abc");
    p->collisionLongitude = 100;
    p->collisionLatitude = 15;
    p->dcpa = 35;
    p->tcpa = 35;
    p->oSCPDistance = 55;
    p->oSCPTime = 65;
    p->tSCPDistance = 75;
    p->tSCPTime = 85;
    p->collisionRisk = 95;
    strcpy(p->collisionArea, "127 30 128 31");
    strcpy(p->validTime, "20180916230000");

    return p;
}
void * ProgressMNG::SetAttentionShip()
{
    DB_AttentionShip *p = (DB_AttentionShip *)malloc(sizeof(DB_AttentionShip));
    memset(p, 0x00, sizeof(DB_AttentionShip));

    strcpy(p->shipId, "12345");
    strcpy(p->dateTime, "20180916190000");
    strcpy(p->name, "ship1");
    p->type = 1;
    strcpy(p->attentionTime, "20180916190000");
    p->attentionCode = 0;
    p->shipLatitude = 80;
    p->shipLongitude = 120;
    strcpy(p->content, "cont1");

    return p;
}

void * ProgressMNG::SetDangerShipAlarm()
{
    DB_DangerShipAlarm *p = (DB_DangerShipAlarm *)malloc(sizeof(DB_DangerShipAlarm));
    memset(p, 0x00, sizeof(DB_DangerShipAlarm));

    strcpy(p->shipId, "12345");
    strcpy(p->dateTime, "20180916220000");
    strcpy(p->areaId, "123");
    p->inArea = true;
    strcpy(p->preTime, "20180916220000");
    p->preLatitude = 130;
    p->preLongitude = 35;
    p->shipLatitude = 131;
    p->shipLongitude = 36;
    p->shipCog = 10;
    p->shipSog = 10;
    strcpy(p->recvTime, "20180916220000");
    strcpy(p->content, "content1");
//
    return p;
}

void * ProgressMNG::SetSpecThreshold()
{
    DB_SpecThreshold *p = (DB_SpecThreshold *)malloc(sizeof(DB_SpecThreshold));
    memset(p, 0x00, sizeof(DB_SpecThreshold));

    strcpy(p->dateTime, "20180718140100");
    strcpy(p->version, "0.1");
    strcpy(p->sv30Threshold, "20");
    strcpy(p->abnormalThreshold, "30");
    strcpy(p->sVAThreshold, "40");
    strcpy(p->vBRSThreshold, "50");
    strcpy(p->rSSThreshold, "60");


    return p;
}


void * ProgressMNG::SetRoute()
{
    DB_Route *p = (DB_Route *)malloc(sizeof(DB_Route));
    memset(p, 0x00, sizeof(DB_Route));

    p->routeId = 1;
    strcpy(p->version, "1");
    strcpy(p->vesselVoyage, "123");
    p->vesselMmsi = 2;
    p->defaultWaypointRadius = 0.3f;
    
    return p;
}
void * ProgressMNG::SetRouteInfo()
{
    DB_RouteInfo *p = (DB_RouteInfo *)malloc(sizeof(DB_RouteInfo));
    memset(p, 0x00, sizeof(DB_RouteInfo));

    p->routeId = 1;
    strcpy(p->routeName, "N1");
    strcpy(p->routeAuthor, "A1");
    strcpy(p->routeStatus, "S1");
    strcpy(p->validityPeriodStart, "1");
    strcpy(p->validityPeriodStop, "9");
    strcpy(p->vesselName, "ship1");
    p->vesselMmsi = 1;
    p->vesselImo = 2;
    strcpy(p->vesselVoyage, "vV1");
    p->vesselDisplacement = 2;
    p->vesselCargo = 3;
    p->vesselGm =4;
    strcpy(p->optimizationMethod, "optm1");
    p->vesselMaxRoll = 5;
    p->vesselMaxWave = 1.1f;
    p->vesselMaxWind = 2.1f;
    p->vesselSpeedMax = 3.1f;
    p->vesselServiceMin = 4.1f;
    p->vesselServiceMax = 5.1f;
    strcpy(p->routeChangesHistory, "RCH1");
    
    return p;
}
void * ProgressMNG::SetWaypoints()
{
    DB_Waypoints *p = (DB_Waypoints *)malloc(sizeof(DB_Waypoints));
    memset(p, 0x00, sizeof(DB_Waypoints));

    p->routeId = 1;
    p->defaultWaypoint = 2;
    p->defaultWaypointRadius = 3;
    p->id = 4;
    p->revision = 5;
    strcpy(p->name, "Nm1");
    p->radius = 6;
    p->lat = 37.1f;
    p->lon = 126.1f;
    p->starboardXtd = 1.1f;
    p->portsideXtd = 1.2f;
    p->safetyContour = 1.3f;
    p->safetyDepth = 1.6f;
    p->geometryType = 1;
    p->speedMin = 1;
    p->speedMax = 10;
    p->draughtForward = 20;
    p->draughtAft = 21;
    p->staticUkc = 10.1f;
    p->dynamicUkc = 10.2f;
    p->masthead = 10.3f;
    strcpy(p->legReport, "lr1");
    strcpy(p->legInfo, "li2");
    strcpy(p->legNote1, "ln1");
    strcpy(p->legNote2, "ln2");
    
    return p;
}
void * ProgressMNG::SetSchedules()
{
    DB_Schedules *p = (DB_Schedules *)malloc(sizeof(DB_Schedules));
    memset(p, 0x00, sizeof(DB_Schedules));

    p->routeId = 1;
    p->id = 2;
    strcpy(p->name, "n1");
    p->manual = 4;
    p->calculated = 5;
    p->waypointId = 5.1f;
    strcpy(p->etd, "etd1");
    strcpy(p->etdWindowBefore, "etdwb");
    strcpy(p->etdWindowAfter, "etdwa");
    strcpy(p->etaWindowBefore, "etawb");
    strcpy(p->etaWindowAfter, "etawa");
    strcpy(p->stay, "sty");
    p->speed = 1.6f;
    p->speedWindow = 1;
    p->windSpeed = 1;
    p->windDirection = 10;
    p->currentSpeed = 20;
    p->currentDirection = 21;
    p->windLoss = 10.1f;
    p->waveLoss = 10.2f;
    p->totalLoss = 10.3f;
    p->rpm = 31;
    p->pitch = 32;
    p->fuel = 33;
    p->relFuelSave = 34;
    p->absFuelSave = 35;
    strcpy(p->note, "cmt1");
    
    return p;

}
void * ProgressMNG::SetFTS()
{
    DB_FTS *p = (DB_FTS *)malloc(sizeof(DB_FTS));
    memset(p, 0x00, sizeof(DB_FTS));

    p->routeId = 1;
    p->waypointId = 2;
    p->rudderAngle = 3;
    p->rpm = 4;
    p->spareControlForce = 5;
    p->spare1 = 5.1f;
    p->spare2 = 5.2f;
    p->spare3 = 5.3f;
    p->spare4 = 5.4f;
    
    return p;
}

void* ProgressMNG::SetEncUpdate() {
  DB_EncUpdate *p= (DB_EncUpdate *)malloc(sizeof(DB_EncUpdate));
  memset(p, 0x00, sizeof(DB_EncUpdate));
//  p->updateId = ;
  strcpy(p->shipMrn, "shipMrn1");
  strcpy(p->license, "MIT");
  strcpy(p->responseTopic, "topic");
  strcpy(p->responseTime, "2018-09-13 10:00:00");
  return p;
}
void* ProgressMNG::SetS57Cell() {
  DB_S57Cell *p= (DB_S57Cell *)malloc(sizeof(DB_S57Cell));
  memset(p, 0x00, sizeof(DB_S57Cell));
  strcpy(p->dsnm, "dsnm1");
  strcpy(p->edtn, "ed1");
  strcpy(p->updn, "up1");   
  strcpy(p->isdt, "2018-09-13");
  p->expp = 'E';
  p->intu = 'l';
  strcpy(p->slat, "137.0");
  strcpy(p->wlon, "37.0");
  strcpy(p->nlat, "137.1");
  strcpy(p->elon, "37.1");
  strcpy(p->zone, "zone1");
  return p;
}
void* ProgressMNG::SetS101Cell() {
  DB_S101Cell *p= (DB_S101Cell *)malloc(sizeof(DB_S101Cell));
  memset(p, 0x00, sizeof(DB_S101Cell));
  strcpy(p->dsnm, "dsnm1");
  strcpy(p->edtn, "ed1");
  strcpy(p->updn, "up1");
  strcpy(p->uadt, "2018-09-13");
  strcpy(p->isdt, "2018-09-13");
  strcpy(p->slat, "137.0");
  strcpy(p->wlon, "37.0");
  strcpy(p->nlat, "137.1");
  strcpy(p->elon, "37.1");
  strcpy(p->zone, "zone1");
  return p;
}


//SV10 Setting
void* ProgressMNG::SetareaMst() {
  DB_areaMst *p= (DB_areaMst *)malloc(sizeof(DB_areaMst));
  memset(p, 0x00, sizeof(DB_areaMst));
  strcpy(p->areaId,  "123");
  strcpy(p->areaName,  "Area1");
  p->areaType = 1;
  strcpy(p->fromTime,  "20180919170000");
  strcpy(p->toTime,  "20181231170000");
  strcpy(p->verInfo, "1.0" );
  return p;
}
void* ProgressMNG::SetareaDetail() {
  DB_areaDetail *p= (DB_areaDetail *)malloc(sizeof(DB_areaDetail));
  memset(p, 0x00, sizeof(DB_areaDetail));
  strcpy(p->areaId, "123");
  p->areaSeq = 1;
  p->areaLat = 37;
  p->areaLon = 131;
  return p;
}
void* ProgressMNG::SetvulInput00_1() {
  DB_vulInput00_1 *p= (DB_vulInput00_1 *)malloc(sizeof(DB_vulInput00_1));
  memset(p, 0x00, sizeof(DB_vulInput00_1));
  strcpy(p->dateTime, "20180919160000");
  p->collisionLatitude = 30;
  p->collisionLongitude = 130;
  p->dcpa = 1;
  p->tcpa = 2;
  p->risk = 3;
  strcpy(p->firstShipId, "F1" );
  strcpy(p->firstName, "FirstShip" );
  strcpy(p->firstType, "TP1" );
  p->firstLatitude = 30;
  p->firstLongitude = 130;
  p->firstCog = 1;
  p->firstSog = 1;
  strcpy(p->firstRecvtime,  "20180919163000");
  strcpy(p->secondShipId, "S1" );
  strcpy(p->secondName,  "SecondShip");
  strcpy(p->secondType, "TP1" );
  p->secondLatitude = 30;
  p->secondLongitude = 130;
  p->secondCog = 1;
  p->secondSog = 1;
  strcpy(p->secondRecvtime, "20180919163000" );
  return p;
}
void* ProgressMNG::SetvulInput00_2() {
  DB_vulInput00_2 *p= (DB_vulInput00_2 *)malloc(sizeof(DB_vulInput00_2));
  memset(p, 0x00, sizeof(DB_vulInput00_2));
  strcpy(p->shipId, "F1" );
  strcpy(p->dateTime, "20180919160000");
  strcpy(p->name, "Ship1");
  strcpy(p->type, "TP1");
  p->risk = 12;
  p->collisionLatitude = 30;
  p->collisionLongitude = 130;
  p->shipLatitude = 30;
  p->shipLongitude = 130;
  p->shipCog = 1;
  p->shipSog = 1;
  strcpy(p->shipRecvtime,  "20180919163000");
  return p;
}
void* ProgressMNG::SetvulInput01() {
  DB_vulInput01_input *p= (DB_vulInput01_input *)malloc(sizeof(DB_vulInput01_input));
  memset(p, 0x00, sizeof(DB_vulInput01_input));
  strcpy(p->vulId, "V1");
  strcpy(p->areaId,  "123");
  p->curSpd01 = 10;
  p->curDir01 = 11;
  p->curSpd02 = 1;
  p->curDir02 = 1;
  p->acciCount = 3;
  return p;
}
void* ProgressMNG::SetvulInput02() {
  DB_vulInput02_input *p= (DB_vulInput02_input *)malloc(sizeof(DB_vulInput02_input));
  memset(p, 0x00, sizeof(DB_vulInput02_input));
  strcpy(p->vulId, "V1" );
  strcpy(p->areaId, "123" );
  p->windSpd = 20;
  p->waveHeight = 21;
  //p->areaSeq = ;
  //strcpy(p->areaName,  );
  //strcpy(p->fromTime,  );
  //strcpy(p->toTime,  );
  //p->areaLat = ;
  //p->areaLon = ;
  return p;
}
void* ProgressMNG::SetvulInput03() {
  DB_vulInput03_input *p= (DB_vulInput03_input *)malloc(sizeof(DB_vulInput03_input));
  memset(p, 0x00, sizeof(DB_vulInput03_input));
  strcpy(p->vulId,  "V1");
  strcpy(p->areaId,  "123");
  p->dynCong = 10;
  p->staCong = 11;
  p->acciRatio = 30;
  //p->areaSeq = ;
  //strcpy(p->areaName,  );
  //strcpy(p->fromTime,  );
  //strcpy(p->toTime,  );
  //p->areaLat = ;
  //p->areaLon = ;
  return p;
}
void* ProgressMNG::SetvulInput04() {
  DB_vulInput04_input *p= (DB_vulInput04_input *)malloc(sizeof(DB_vulInput04_input));
  memset(p, 0x00, sizeof(DB_vulInput04_input));
  strcpy(p->vulId, "V1" );
  strcpy(p->areaId, "123" );
  p->acciRatio = 10;
  p->passShips = 20;
  //p->areaSeq = ;
  //strcpy(p->areaName,  );
  //strcpy(p->fromTime,  );
  //strcpy(p->toTime,  );
  //p->areaLat = ;
  //p->areaLon = ;
  return p;
}
void* ProgressMNG::SetvulInput05() {
  DB_vulInput05 *p= (DB_vulInput05 *)malloc(sizeof(DB_vulInput05));
  memset(p, 0x00, sizeof(DB_vulInput05));
  strcpy(p->shipId,  "S1");
  strcpy(p->depTime,  "20180901120000");
  strcpy(p->arrTime, "20180919170000" );
  strcpy(p->depPort, "Pusan" );
  p->tonnage = 60;
  return p;
}
void* ProgressMNG::SetvulInput06() {
  DB_vulInput06 *p= (DB_vulInput06 *)malloc(sizeof(DB_vulInput06));
  memset(p, 0x00, sizeof(DB_vulInput06));
  strcpy(p->shipId,  "S1");
  strcpy(p->subShipId,  "SUB1");
  strcpy(p->depTime,  "20180901120000");
  strcpy(p->arrTime,  "20180919170000");
  strcpy(p->depPort,  "Pusan");
  strcpy(p->arrPort,  "Inchon");
  p->tugType = 0;
  p->tugLen = 10;
  p->mstLen = 20;
  p->subLen = 5;
  return p;
}
void* ProgressMNG::SetvulInput07() {
  DB_vulInput07 *p= (DB_vulInput07 *)malloc(sizeof(DB_vulInput07));
  memset(p, 0x00, sizeof(DB_vulInput07));
  strcpy(p->tgtShipId, "TS1" );
  strcpy(p->shipId,  "S1");
  p->index = 1;
  strcpy(p->fromTime, "20180901120000" );
  strcpy(p->toTime,  "20180919170000");
  return p;
}
void* ProgressMNG::SetavsResponse() {
  DB_avsResponse *p= (DB_avsResponse *)malloc(sizeof(DB_avsResponse));
  memset(p, 0x00, sizeof(DB_avsResponse));
  strcpy(p->acciTime, "20180919170000");
  strcpy(p->osShipId, "OSS1" );
  strcpy(p->tsShipId, "TSS1");
  strcpy(p->reqTime, "20180919170000" );
  strcpy(p->resTime, "20180919170500" );
  return p;
}
void* ProgressMNG::SetrssResponse() {
  DB_rssResponse *p= (DB_rssResponse *)malloc(sizeof(DB_rssResponse));
  memset(p, 0x00, sizeof(DB_rssResponse));
  strcpy(p->acciTime, "20180919170000");
  strcpy(p->osShipId, "OSS1");
  strcpy(p->tsShipId, "TSS1");
  strcpy(p->tgtShipId,  "TGTS1");
  p->tgtLat = 30;
  p->tgtLon = 130;
  strcpy(p->reqTime,  "20180919170000");
  strcpy(p->resTime,  "20180919170500");
  return p;
}
void* ProgressMNG::SetfishingHistoryArea() {
  DB_fishingHistoryArea *p= (DB_fishingHistoryArea *)malloc(sizeof(DB_fishingHistoryArea));
  memset(p, 0x00, sizeof(DB_fishingHistoryArea));
  strcpy(p->areaId,  "123");
  p->fisheryType = 1;
  p->fishSpecies = 2;
  strcpy(p->fromTime,  "20180919100000");
  strcpy(p->toTime,  "20180930180000");
  return p;
}
void* ProgressMNG::SetfishingPatternArea() {
  DB_fishingPatternArea *p= (DB_fishingPatternArea *)malloc(sizeof(DB_fishingPatternArea));
  memset(p, 0x00, sizeof(DB_fishingPatternArea));
  strcpy(p->shipStr,  "SS1");
  strcpy(p->locStr,  "111");
  strcpy(p->areaStr, "222" );
  strcpy(p->dateTime,  "20180919100000");
  return p;
}
void* ProgressMNG::SetabnormalPattern() {
  DB_abnormalPattern *p= (DB_abnormalPattern *)malloc(sizeof(DB_abnormalPattern));
  memset(p, 0x00, sizeof(DB_abnormalPattern));
  strcpy(p->shipId,  "123");
  strcpy(p->dateTime, "20180918180000" );
  p->shipLatitude =37;
  p->shipLongitude = 131;
  p->shipCog = 32;
  p->shipSog = 123;
  strcpy(p->recvTime, "20180918160000" );
  p->abnormalValue = 1.0;
  return p;
}

void * ProgressMNG::SetShipDensity() {
    DB_ShipDensity *p = (DB_ShipDensity *)malloc(sizeof(DB_ShipDensity));
    memset(p, 0x00, sizeof(DB_ShipDensity));


    p->index = 1;
	strcpy(p->time, "2018-09-06 16:30");
	p->pointLat1 = 37.1f;
	p->pointLon1 = 130.1f;
	p->pointLat2 = 37.2f;
	p->pointLon2 = 130.2f;
	p->pointLat3 = 37.3f;
	p->pointLon3 = 130.3f;
	p->pointLat4 = 37.4f;
	p->pointLon4 = 130.4f;
	p->densityValue =0.1f;
	p->shipCount = 10;
    return p;

}


void *  ProgressMNG::SetShipStaticInfo()
{
    DB_DataSetShipStaticInfo *p = new DB_DataSetShipStaticInfo();

    strcpy(p->szShipmrn, "Mrn1" );
    (p->arrShipStaticInfoList).clear();
    (p->arrShipStaticInfoList).resize(1);
    p->arrShipStaticInfoList.at(0).nServiceId = 1;
    strcpy(p->arrShipStaticInfoList.at(0).szUtcDate, "2018-09-21" );
    strcpy(p->arrShipStaticInfoList.at(0).szUtcTime, "11:30:00" );
    (p->arrShipStaticInfoList.at(0)).dLatitude = 37;
    (p->arrShipStaticInfoList.at(0)).dLongitude = 131;
    SetNavigationInfo(p->arrShipStaticInfoList.at(0).arrNavigationInfo);
    SetEmergencyInfo(p->arrShipStaticInfoList.at(0).arrEmergencyInfo);
    SetFireAlarm(p->arrShipStaticInfoList.at(0).arrFireAlarm);
    SetFireDoor(p->arrShipStaticInfoList.at(0).arrFireDoor);
    SetGenerator(p->arrShipStaticInfoList.at(0).arrGenerator);
    SetMainEngine(p->arrShipStaticInfoList.at(0).arrMainEngine);
    SetOldFireAlarm(p->arrShipStaticInfoList.at(0).arrOldFireAlarm);
    SetRamp(p->arrShipStaticInfoList.at(0).arrRamp);
    SetRecovery(p->arrShipStaticInfoList.at(0).arrRecovery);
    SetStability(p->arrShipStaticInfoList.at(0).arrStability);
    SetSteeringGear(p->arrShipStaticInfoList.at(0).arrSteeringGear);
    SetTankLevel(p->arrShipStaticInfoList.at(0).arrTankLevel);
    SetTelegraph(p->arrShipStaticInfoList.at(0).arrTelegraph);

    return p;    
}
void *  ProgressMNG::SetNavigationInfo(std::vector<DB_NavigationInfo> &vecData)
{
    vecData.clear();
    vecData.resize(1);

    strcpy(vecData.at(0).szLOG, "log1" );
    strcpy(vecData.at(0).szAIS, "ais1" );
    strcpy(vecData.at(0).szGPS1, "gps1" );
    strcpy(vecData.at(0).szGPS2, "gps2" );
    strcpy(vecData.at(0).szECDIS, "ecdis" );
    strcpy(vecData.at(0).szRADAR1, "radar1" );
    strcpy(vecData.at(0).szRADAR2, "radar2" );
    strcpy(vecData.at(0).szEchoSounder, "sounder" );
    strcpy(vecData.at(0).szGyroCompass, "compass" );
    strcpy(vecData.at(0).szAutoPilot, "pilot" );

}
void *  ProgressMNG::SetEmergencyInfo(std::vector<DB_EmergencyInfo> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).nFireLevel = 1;
    vecData.at(0).nSeakeepingLevel = 2;
    vecData.at(0).nNavigationLevel = 3;
    strcpy(vecData.at(0).szRunTime, "20180921140000" );
    strcpy(vecData.at(0).szFireSafetyCode, "safeCd" );
    strcpy(vecData.at(0).szSeakeepingQualiyCode, "qualityCd" );
    strcpy(vecData.at(0).szNavigationSafetyCode, "NavSafeCd" );


}

void *  ProgressMNG::SetFireAlarm(std::vector<DB_FireAlarm> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bUse = true;
    vecData.at(0).sCount = 1;
    strcpy(vecData.at(0).szDetectorType, "DetectTP" );
    strcpy(vecData.at(0).szAlarmTime, "2018092810400000" );
    vecData.at(0).nPositionId = 3;


}
void *  ProgressMNG::SetFireDoor(std::vector<DB_FireDoor> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bUse = true;
    vecData.at(0).bDoorOpen = true;
    vecData.at(0).nPositionId = 2;

}
void *  ProgressMNG::SetGenerator(std::vector<DB_Generator> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).sNo = 1;
    vecData.at(0).sCount = 2;
    strcpy(vecData.at(0).szCFW_HighTemp_Trip, "CFWHTT" );
    strcpy(vecData.at(0).szLO_LowPress_Trip, "LLPT" );
    strcpy(vecData.at(0).szOverSpeed_Trip, "OST" );
    strcpy(vecData.at(0).szCommon_Trip, "CT" );
    strcpy(vecData.at(0).szSpeedSensorFail_Trip, "SSFT" );
    strcpy(vecData.at(0).szStartFail, "SF" );
    strcpy(vecData.at(0).szCommonShutdown, "CS" );



}
void *  ProgressMNG::SetMainEngine(std::vector<DB_MainEngine> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bUseRpm1 = true;
    vecData.at(0).bUseRpm2 = true;
    vecData.at(0).dRpm1 = 1.0f;
    vecData.at(0).dRpm2 = 2.0f;
    strcpy(vecData.at(0).szShutdown, "shutdown" );
    strcpy(vecData.at(0).szSlowdown, "slowdown" );

}
void *  ProgressMNG::SetOldFireAlarm(std::vector<DB_OldFireAlarm> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bUse = true;
    vecData.at(0).sCount = 1;
    vecData.at(0).bBreakOut = true;


}
void *  ProgressMNG::SetRamp(std::vector<DB_Ramp> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bRampUse = true;
    vecData.at(0).sCount = 2;
    vecData.at(0).nRampId = 3;
    vecData.at(0).bRampDoorOpen = true;

}
void *  ProgressMNG::SetRecovery(std::vector<DB_Recovery> &vecData)
{
vecData.clear();
    vecData.resize(1);


    vecData.at(0).bUseRoll = true;
    vecData.at(0).bUsePitch = true;
    vecData.at(0).bUseGps = true;
    vecData.at(0).bUseWind = true;
    vecData.at(0).bUseRudder1 = true;
    vecData.at(0).bUseRudder2 = true;
    vecData.at(0).dRolling = 1;
    vecData.at(0).dPitching = 2;
    vecData.at(0).dCog = 3;
    vecData.at(0).dSog = 4;
    vecData.at(0).dShipHeading = 5;
    vecData.at(0).dShipSpeed = 6;
    vecData.at(0).dWindDirection = 7;
    vecData.at(0).dWindSpeed = 8;
    vecData.at(0).dRudder1 = 9;
    vecData.at(0).dRudder2 = 10;

}
void *  ProgressMNG::SetStability(std::vector<DB_Stability> &vecData)
{
vecData.clear();
    vecData.resize(1);


    vecData.at(0).dForeDraft = 1;
    vecData.at(0).dAftDraft = 2;
    vecData.at(0).dKG = 3;
    vecData.at(0).dGoM = 4;
}
void *  ProgressMNG::SetSteeringGear(std::vector<DB_SteeringGear> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).sNo = 1;
    vecData.at(0).sCount = 2;
    strcpy(vecData.at(0).szHydLoTk_LL, "HLTL" );
    strcpy(vecData.at(0).szMotor_Run, "MR" );
    strcpy(vecData.at(0).szNoVolt, "NV" );
    strcpy(vecData.at(0).szOverload, "OL" );
    strcpy(vecData.at(0).szPhase_Fail, "PF" );


}
void *  ProgressMNG::SetTankLevel(std::vector<DB_TankLevel> &vecData)
{
vecData.clear();
    vecData.resize(1);


    vecData.at(0).sCount = 1;
    vecData.at(0).dVal = 11;
    vecData.at(0).sTankNumber = 3;
    strcpy(vecData.at(0).szTankType, "TT" );
    strcpy(vecData.at(0).szTankName, "TName" );


}
void *  ProgressMNG::SetTelegraph(std::vector<DB_Telegraph> &vecData)
{
    vecData.clear();
    vecData.resize(1);


    vecData.at(0).bTelegraphUse = true;
    vecData.at(0).sCount = 1;
    vecData.at(0).nTelegraphId = 2;
    vecData.at(0).nTelegraphStatus= 3;
}

void * ProgressMNG::SetMrnRecentVersion()
{
    DB_MrnRecentVersion *p = new DB_MrnRecentVersion();


    strcpy(p->shipMrn, "shipMrn1");
    strcpy(p->license, "MIT");
    strcpy(p->w1Version, "W1");
    strcpy(p->w2Version, "W2");
    strcpy(p->w3Version, "W3");
    strcpy(p->s1Version, "S1");
    strcpy(p->s2Version, "S2");
    strcpy(p->s3Version, "S3");
    strcpy(p->s4Version, "S4");
    strcpy(p->s5Version, "S5");
    strcpy(p->e1Version, "E1");
    strcpy(p->e2Version, "E2");
    strcpy(p->e3Version, "E3");
    strcpy(p->scVersion, "SC");

    return p;
    
}