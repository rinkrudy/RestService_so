#include "ResultRenderer.h"
#include "./so/ServiceStruct/EnaviDBStruct.h"
#include <ostream>
#include<fstream>
#include <malloc.h>


#include "./so/ServiceStruct/EnaviDBService.h"




using namespace std;

ResultRender::ResultRender()
{
    for (int i = 0; i < (int)E_Service::eService_Max; i++)
    {
        m_arrRenderFunction[i] = nullptr;
    }
    m_mapValueType.clear();
}
ResultRender::~ResultRender()
{
}
void ResultRender::Init()
{


    m_mapValueType.insert(std::make_pair<string, E_ValueType>("char", E_ValueType::eChar));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("string", E_ValueType::eString));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("int", E_ValueType::eInt));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("long", E_ValueType::eLong));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("float", E_ValueType::eFloat));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("double", E_ValueType::eDouble));
    m_mapValueType.insert(std::make_pair<string, E_ValueType>("bool", E_ValueType::eBoolean));
    
    
    m_vecStruct.clear();
    m_vecStruct.resize((int)Service::E_Service::eService_Max);
    m_vecStruct.at((int)E_Service::eAbnormalPattern) = "struct_abnormalPattern";
    m_vecStruct.at((int)E_Service::eAccidentPrediction) = "struct_AccidentPrediction";
    m_vecStruct.at((int)E_Service::eAccidentRisk) = "struct_AccidentRisk";
    m_vecStruct.at((int)E_Service::eAreaDetail) = "struct_areaDetail";
    m_vecStruct.at((int)E_Service::eAreaMst) = "struct_areaMst";
    m_vecStruct.at((int)E_Service::eAreaSelect) = "struct_areaSelect";
    m_vecStruct.at((int)E_Service::eAttentionShip) = "struct_AttentionShip";
    m_vecStruct.at((int)E_Service::eAvsResponse) = "struct_avsResponse";
    m_vecStruct.at((int)E_Service::eDangerShipAlarm) = "struct_DangerShipAlarm";
    m_vecStruct.at((int)E_Service::eFishingHistoryArea) = "struct_fishingHistoryArea";
    m_vecStruct.at((int)E_Service::eFishingPatternArea) = "struct_fishingPatternArea";
    m_vecStruct.at((int)E_Service::eRssResponse) = "struct_rssResponse";
    m_vecStruct.at((int)E_Service::eSpecThreshold) = "struct_SpecThreshold";
    m_vecStruct.at((int)E_Service::eVulInput00_1) = "struct_vulInput00_1";
    m_vecStruct.at((int)E_Service::eVulInput00_2) = "struct_vulInput00_2";
    m_vecStruct.at((int)E_Service::eVulInput01) = "struct_vulInput01";
    m_vecStruct.at((int)E_Service::eVulInput02) = "struct_vulInput02";
    m_vecStruct.at((int)E_Service::eVulInput03) = "struct_vulInput03";
    m_vecStruct.at((int)E_Service::eVulInput04) = "struct_vulInput04";
    m_vecStruct.at((int)E_Service::eVulInput05) = "struct_vulInput05";
    m_vecStruct.at((int)E_Service::eVulInput06) = "struct_vulInput06";
    m_vecStruct.at((int)E_Service::eVulInput07) = "struct_vulInput07";
    m_vecStruct.at((int)E_Service::eShipStaticInfo) = "struct_AwmShipStaticInfo";
    m_vecStruct.at((int)E_Service::ePastNavInfo) = "struct_PastNavInfo";
    m_vecStruct.at((int)E_Service::ePastNavVesselInfo) = "struct_PastNavVesslInfo";
    m_vecStruct.at((int)E_Service::eRoute) = "struct_Route";
    m_vecStruct.at((int)E_Service::eRouteInfo) = "struct_RouteInfo";
    m_vecStruct.at((int)E_Service::eWaypoints) = "struct_Waypoints";
    m_vecStruct.at((int)E_Service::eSchedules) = "struct_Schedules";
    m_vecStruct.at((int)E_Service::eFTS) = "struct_FTS";
    m_vecStruct.at((int)E_Service::eCatalogue) = "struct_Catalogue";
    m_vecStruct.at((int)E_Service::eCatalogueAll) = "struct_CatalogueAll";
    m_vecStruct.at((int)E_Service::eEncUpdate) = "struct_EncUpdate";
    m_vecStruct.at((int)E_Service::eS57Cell) = "struct_S57Cell";
    m_vecStruct.at((int)E_Service::eS101Cell) = "struct_S101Cell";
    m_vecStruct.at((int)E_Service::eZone) = "struct_Zone";
    m_vecStruct.at((int)E_Service::eZoneAll) = "struct_ZoneAll";
    m_vecStruct.at((int)E_Service::eGuideLine) = "struct_GuideLine";
    m_vecStruct.at((int)E_Service::eGuideLineAnchorage) = "struct_GuideLineAnchorage";
    m_vecStruct.at((int)E_Service::eGuideLineCourse) = "struct_GuideLineCourse";
    m_vecStruct.at((int)E_Service::eGuideLineFairway) = "struct_GuideLineFairway";
    m_vecStruct.at((int)E_Service::eGuideLineInfo) = "struct_GuideLineInfo";
    m_vecStruct.at((int)E_Service::eGuideLinePilot) = "struct_GuideLinePilot";
    m_vecStruct.at((int)E_Service::eGuideLinePoint) = "struct_GuideLinePoint";
    m_vecStruct.at((int)E_Service::eGuideLineSafetySpeed) = "struct_GuideLineSafetySpeed";
    m_vecStruct.at((int)E_Service::eGuideLineSafetyStan) = "struct_GuideLineSafetyStan";
    m_vecStruct.at((int)E_Service::eGuideLineSpeed) = "struct_GuideLineSpeed";
    m_vecStruct.at((int)E_Service::eGuideLineTug) = "struct_GuideLineTug";
    m_vecStruct.at((int)E_Service::eGuideLineVTS) = "struct_GuideLineVTS";
    m_vecStruct.at((int)E_Service::eGuideLineWharf) = "struct_GuideLineWharf";
    m_vecStruct.at((int)E_Service::eShipPosition) = "struct_ShipPosition";
    m_vecStruct.at((int)E_Service::eShipDensity) = "struct_ShipDensity";
    m_vecStruct.at((int)E_Service::eVesselStaticinfo) = "struct_VesselStaticInfo";


    m_arrResultRenderer[(int)Service::E_Service::eVesselStaticinfo] = &ResultRender::Render_Result_fromStream<DB_VesselStaticInfo>;
	m_arrResultRenderer[(int)Service::E_Service::eAbnormalPattern] = &ResultRender::Render_Result_fromStream<DB_abnormalPattern>;
	m_arrResultRenderer[(int)Service::E_Service::eAccidentPrediction] = &ResultRender::Render_Result_fromStream<DB_AccidentPrediction>;
	m_arrResultRenderer[(int)Service::E_Service::eAccidentRisk] = &ResultRender::Render_Result_fromStream<DB_AccidentRisk>;
	m_arrResultRenderer[(int)Service::E_Service::eAreaDetail] = &ResultRender::Render_Result_fromStream<DB_areaDetail>;
	m_arrResultRenderer[(int)Service::E_Service::eAreaMst] = &ResultRender::Render_Result_fromStream<DB_areaMst>;
	m_arrResultRenderer[(int)Service::E_Service::eAreaSelect] = &ResultRender::Render_Result_fromStream<DB_areaSelect>;
	m_arrResultRenderer[(int)Service::E_Service::eAttentionShip] = &ResultRender::Render_Result_fromStream<DB_AttentionShip>;
	m_arrResultRenderer[(int)Service::E_Service::eAvsResponse] = &ResultRender::Render_Result_fromStream<DB_avsResponse>;
	m_arrResultRenderer[(int)Service::E_Service::eDangerShipAlarm] = &ResultRender::Render_Result_fromStream<DB_DangerShipAlarm>;
	m_arrResultRenderer[(int)Service::E_Service::eFishingPatternArea] = &ResultRender::Render_Result_fromStream<DB_fishingPatternArea>;
	m_arrResultRenderer[(int)Service::E_Service::eFishingHistoryArea] = &ResultRender::Render_Result_fromStream<DB_fishingHistoryArea>;
	m_arrResultRenderer[(int)Service::E_Service::eRssResponse] = &ResultRender::Render_Result_fromStream<DB_rssResponse>;
	m_arrResultRenderer[(int)Service::E_Service::eSpecThreshold] = &ResultRender::Render_Result_fromStream<DB_SpecThreshold>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput00_1] = &ResultRender::Render_Result_fromStream<DB_vulInput00_1>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput00_2] = &ResultRender::Render_Result_fromStream<DB_vulInput00_2>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput01] = &ResultRender::Render_Result_fromStream<DB_vulInput01>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput02] = &ResultRender::Render_Result_fromStream<DB_vulInput02>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput03] = &ResultRender::Render_Result_fromStream<DB_vulInput03>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput04] = &ResultRender::Render_Result_fromStream<DB_vulInput04>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput05] = &ResultRender::Render_Result_fromStream<DB_vulInput05>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput06] = &ResultRender::Render_Result_fromStream<DB_vulInput06>;
	m_arrResultRenderer[(int)Service::E_Service::eVulInput07] = &ResultRender::Render_Result_fromStream<DB_vulInput07>;
	m_arrResultRenderer[(int)Service::E_Service::eShipStaticInfo] = &ResultRender::Render_Result_fromStream<DB_ShipStaticInfo>;
	m_arrResultRenderer[(int)Service::E_Service::eFTS] = &ResultRender::Render_Result_fromStream<DB_FTS>;
	m_arrResultRenderer[(int)Service::E_Service::ePastNavInfo] = &ResultRender::Render_Result_fromStream<DB_PastNavInfo>;
	m_arrResultRenderer[(int)Service::E_Service::ePastNavVesselInfo] = &ResultRender::Render_Result_fromStream<DB_PastNavVesselInfo>;
	m_arrResultRenderer[(int)Service::E_Service::eRoute] = &ResultRender::Render_Result_fromStream<DB_Route>;
	m_arrResultRenderer[(int)Service::E_Service::eRouteInfo] = &ResultRender::Render_Result_fromStream<DB_RouteInfo>;
	m_arrResultRenderer[(int)Service::E_Service::eSchedules] = &ResultRender::Render_Result_fromStream<DB_Schedules>;
	m_arrResultRenderer[(int)Service::E_Service::eWaypoints] = &ResultRender::Render_Result_fromStream<DB_Waypoints>;
	m_arrResultRenderer[(int)Service::E_Service::eCatalogue] = &ResultRender::Render_Result_fromStream<DB_Catalogue>;
	m_arrResultRenderer[(int)Service::E_Service::eCatalogueAll] = &ResultRender::Render_Result_fromStream<DB_Catalogue>;
	m_arrResultRenderer[(int)Service::E_Service::eEncUpdate] = &ResultRender::Render_Result_fromStream<DB_EncUpdate>;
	m_arrResultRenderer[(int)Service::E_Service::eS57Cell] = &ResultRender::Render_Result_fromStream<DB_S57Cell>;
	m_arrResultRenderer[(int)Service::E_Service::eS101Cell] = &ResultRender::Render_Result_fromStream<DB_S101Cell>;
	m_arrResultRenderer[(int)Service::E_Service::eZone] = &ResultRender::Render_Result_fromStream<DB_Zone>;
	m_arrResultRenderer[(int)Service::E_Service::eZoneAll] = &ResultRender::Render_Result_fromStream<DB_Zone>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLine] = &ResultRender::Render_Result_fromStream<DB_GuideLine>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineAnchorage] = &ResultRender::Render_Result_fromStream<DB_GuideLineAnchorage>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineCourse] = &ResultRender::Render_Result_fromStream<DB_GuideLineCourse>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineFairway] = &ResultRender::Render_Result_fromStream<DB_GuideLineFairway>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineInfo] = &ResultRender::Render_Result_fromStream<DB_GuideLineInfo>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLinePilot] = &ResultRender::Render_Result_fromStream<DB_GuideLinePilot>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLinePoint] = &ResultRender::Render_Result_fromStream<DB_GuideLinePoint>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineSafetySpeed] = &ResultRender::Render_Result_fromStream<DB_GuideLineSafetySpeed>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineSafetyStan] = &ResultRender::Render_Result_fromStream<DB_GuideLineSafetyStan>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineSpeed] = &ResultRender::Render_Result_fromStream<DB_GuideLineSpeed>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineTug] = &ResultRender::Render_Result_fromStream<DB_GuideLineTug>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineVTS] = &ResultRender::Render_Result_fromStream<DB_GuideLineVTS>;
	m_arrResultRenderer[(int)Service::E_Service::eGuideLineWharf] = &ResultRender::Render_Result_fromStream<DB_GuideLineWharf>;
	m_arrResultRenderer[(int)Service::E_Service::eShipPosition] = &ResultRender::Render_Result_fromStream<DB_ShipPosition>;
	m_arrResultRenderer[(int)Service::E_Service::eShipDensity] = &ResultRender::Render_Result_fromStream<DB_ShipDensity>;




    m_arrRenderFunction[(int)Service::E_Service::eAbnormalPattern] = &ResultRender::abnormalPattern_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAccidentPrediction] = &ResultRender::AccidentPrediction_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAccidentRisk] = &ResultRender::AccidentRisk_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAreaDetail] = &ResultRender::areaDetail_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAreaMst] = &ResultRender::areaMst_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAreaSelect] = &ResultRender::areaSelect_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAttentionShip] = &ResultRender::AttentionShip_Get;
    m_arrRenderFunction[(int)Service::E_Service::eAvsResponse] = &ResultRender::avsResponse_Get;
    m_arrRenderFunction[(int)Service::E_Service::eDangerShipAlarm] = &ResultRender::DangerShipAlarm_Get;
    m_arrRenderFunction[(int)Service::E_Service::eFishingHistoryArea] = &ResultRender::fishingHistoryArea_Get;
    m_arrRenderFunction[(int)Service::E_Service::eFishingPatternArea] = &ResultRender::fishingPatternArea_Get;
    m_arrRenderFunction[(int)Service::E_Service::eRssResponse] = &ResultRender::rssResponse_Get;
    m_arrRenderFunction[(int)Service::E_Service::eSpecThreshold] = &ResultRender::SpecThreshold_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput00_1] = &ResultRender::vulInput00_1_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput00_2] = &ResultRender::vulInput00_2_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput01] = &ResultRender::vulInput01_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput02] = &ResultRender::vulInput02_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput03] = &ResultRender::vulInput03_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput04] = &ResultRender::vulInput04_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput05] = &ResultRender::vulInput05_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput06] = &ResultRender::vulInput06_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVulInput07] = &ResultRender::vulInput07_Get;
    m_arrRenderFunction[(int)Service::E_Service::ePastNavInfo] = &ResultRender::PastNavInfo_Get;
    m_arrRenderFunction[(int)Service::E_Service::ePastNavVesselInfo] = &ResultRender::PastNavVesselInfo_Get;
    m_arrRenderFunction[(int)Service::E_Service::eRoute] = &ResultRender::Route_Get;
    m_arrRenderFunction[(int)Service::E_Service::eRouteInfo] = &ResultRender::RouteInfo_Get;
    m_arrRenderFunction[(int)Service::E_Service::eWaypoints] = &ResultRender::Waypoints_Get;
    m_arrRenderFunction[(int)Service::E_Service::eSchedules] = &ResultRender::Schedules_Get;
    m_arrRenderFunction[(int)Service::E_Service::eFTS] = &ResultRender::FTS_Get;
    m_arrRenderFunction[(int)Service::E_Service::eCatalogue] = &ResultRender::Catalogue_Get;
    m_arrRenderFunction[(int)Service::E_Service::eCatalogueAll] = &ResultRender::Catalogue_Get;
    m_arrRenderFunction[(int)Service::E_Service::eEncUpdate] = &ResultRender::EncUpdate_Get;
    m_arrRenderFunction[(int)Service::E_Service::eS57Cell] = &ResultRender::S57Cell_Get;
    m_arrRenderFunction[(int)Service::E_Service::eS101Cell] = &ResultRender::S101Cell_Get;
    m_arrRenderFunction[(int)Service::E_Service::eZone] = &ResultRender::Zone_Get;
    m_arrRenderFunction[(int)Service::E_Service::eZoneAll] = &ResultRender::Zone_Get;
    m_arrRenderFunction[(int)Service::E_Service::eMrnRecentVersion] = &ResultRender::MrnRecentVersion_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLine] = &ResultRender::GuideLine_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineAnchorage] = &ResultRender::GuideLineAnchorage_Get;     
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineCourse] = &ResultRender::GuideLineCourse_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineFairway] = &ResultRender::GuideLineFairway_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineInfo] = &ResultRender::GuideLineInfo_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLinePilot] = &ResultRender::GuideLinePilot_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLinePoint] = &ResultRender::GuideLinePoint_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineSafetySpeed] = &ResultRender::GuideLineSafetySpeed_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineSafetyStan] = &ResultRender::GuideLineSafetyStan_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineSpeed] = &ResultRender::GuideLineSpeed_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineTug] = &ResultRender::GuideLineTug_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineVTS] = &ResultRender::GuideLineVTS_Get;
    m_arrRenderFunction[(int)Service::E_Service::eGuideLineWharf] = &ResultRender::GuideLineWharf_Get;
    m_arrRenderFunction[(int)Service::E_Service::eShipPosition] = &ResultRender::ShipPosition_Get;
    m_arrRenderFunction[(int)Service::E_Service::eShipDensity] = &ResultRender::ShipDensity_Get;
    m_arrRenderFunction[(int)Service::E_Service::eShipStaticInfo] = &ResultRender::ShipStatic_Get;
    m_arrRenderFunction[(int)Service::E_Service::eServiceLog] = &ResultRender::ServiceLog_Get;
    m_arrRenderFunction[(int)Service::E_Service::eVesselStaticinfo] = &ResultRender::VesselStaticInfo_Get;


}

void ResultRender::Update_Get(void *pResult)
{
    printf("UpdateData return %p\n", pResult);

    RestApiInfo *s = (RestApiInfo *)pResult;
    printf("update result: %d, %s, %d\n", s->success, s->msg, s->data);
}
void ResultRender::Render_Result(void *pResult, int iService, int nRest)
{
    if (nRest == 1 || nRest == 5)
    {
        (this->*m_arrRenderFunction[iService])(pResult);
        //(this->*m_arrResultRenderer[iService])(pResult, iService);
    }
        
    else
        Update_Get(pResult);
}


//sv10
void ResultRender::AccidentPrediction_Get(void *pResult)
{
    DB_AccidentPrediction *data = (DB_AccidentPrediction *)malloc(sizeof(DB_AccidentPrediction));
    memset(data, 0, sizeof(DB_AccidentPrediction));

    DB_AccidentPrediction *s = (DB_AccidentPrediction *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_AccidentPrediction);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime accidentTime accidentLongitude oSMmsi accidentType accidentType2 tSMmsi lastTimeSrc roTsrc sOGSrc lATSrc lONSrc cOGSrc hDGSrc targetLastTimeeSrc targetROTSrc targetSOGSrc targetLATSrc targetLONSrc targetCOGSrc targetHDGSrc\n");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
         printf("%s, %s, %d, %d, %s, %c, %c, %s, %s, %c, %d, %d, %d, %d, %d, %s, %c, %d, %d, %d, %d, %d\n", s->dateTime, s->accidentTime, s->accidentLatitude, s->accidentLongitude, s->oSMmsi, s->accidentType, s->accidentType2, s->tSMmsi, s->lastTimeSrc, s->rOTSrc, s->sOGSrc, s->lATSrc, s->lONSrc, s->cOGSrc, s->hDGSrc, s->targetLastTimeSrc, s->targetROTSrc, s->targetSOGSrc, s->targetLATSrc, s->targetLONSrc, s->targetCOGSrc, s->targetHDGSrc);
        s++;
    }
}
void ResultRender::AccidentRisk_Get(void *pResult)
{
    DB_AccidentRisk *data = (DB_AccidentRisk *)malloc(sizeof(DB_AccidentRisk));
    memset(data, 0, sizeof(DB_AccidentRisk));

    DB_AccidentRisk *s = (DB_AccidentRisk *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_AccidentRisk);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime alarmStatus oSMmsi oSLongitude OSLatitude oSCog oSSog accidentType accidentType2 tsMmsi tSLongitude tsLatitude tSCog tSSog collisionType collisionLongitude collisionLatitude dcpa tcpa oSCPDistance oSCPTime tSCPDistance tSCPTime collisionRisk collisionArea");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
         printf("%s, %c, %s, %d, %d, %d, %d, %c, %c, %s, %d,%d,%d,%d %s, %d,%d, %f, %f, %f, %f, %f, %f, %f, %s\n",
              s->dateTime, s->alarmStatus, s->oSMmsi, s->oSLongitude, s->oSLatitude,s->oSCog, s->oSSog, s->accidentType, s->accidentType2, s->tSMmsi, s->tSLongitude, s->tSLatitude, s->tSCog, s->tSSog, s->collisionType, s->collisionLongitude, s->collisionLatitude, s->dcpa, s->tcpa, s->oSCPDistance, s->oSCPTime, s->tSCPDistance, s->tSCPTime, s->collisionRisk, s->collisionArea);
        s++;
    }

}

void ResultRender::areaMst_Get(void *pResult) {
  DB_areaMst *data = (DB_areaMst *)malloc(sizeof(DB_areaMst));
  memset(data, 0, sizeof(DB_areaMst));
  DB_areaMst *s = (DB_areaMst *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_areaMst);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     areaId areaName areaType fromTime toTime verInfo \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %s, %s, %s\n", s->areaId, s->areaName, s->areaType, s->fromTime, s->toTime, s->verInfo);
      s++;
  }
}
void ResultRender::areaDetail_Get(void *pResult) {
  DB_areaDetail *data = (DB_areaDetail *)malloc(sizeof(DB_areaDetail));
  memset(data, 0, sizeof(DB_areaDetail));
  DB_areaDetail *s = (DB_areaDetail *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_areaDetail);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     areaSeq areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %f, %f\n", s->areaSeq, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::areaSelect_Get(void *pResult) {
  DB_areaSelect *data = (DB_areaSelect *)malloc(sizeof(DB_areaSelect));
  memset(data, 0, sizeof(DB_areaSelect));
  DB_areaSelect *s = (DB_areaSelect *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_areaSelect);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     areaSeq areaName areaType fromTime toTime areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %d, %s, %s, %f, %f\n", s->areaSeq, s->areaName, s->areaType, s->fromTime, s->toTime, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::AttentionShip_Get(void *pResult)
{
    DB_AttentionShip *data = (DB_AttentionShip *)malloc(sizeof(DB_AttentionShip));
    memset(data, 0, sizeof(DB_AttentionShip));

    DB_AttentionShip *s = (DB_AttentionShip *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_AttentionShip);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime mmsi name type attentionCnt attentionTime attentionCode");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%s, %s, %s, %d, %s, %d, %d, %d, %s\n", s->shipId, s->dateTime, s->name, s->type, s->attentionTime, s->attentionCode, s->shipLatitude, s->shipLongitude, s->content);
        s++;
    }

}
void ResultRender::DangerShipAlarm_Get(void *pResult)
{
    DB_DangerShipAlarm *data = (DB_DangerShipAlarm *)malloc(sizeof(DB_DangerShipAlarm));
    memset(data, 0, sizeof(DB_DangerShipAlarm));

    DB_DangerShipAlarm *s = (DB_DangerShipAlarm *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_DangerShipAlarm);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime mmsi inArea preTime preLatitude preLongitude");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%s, %s, %s, %s, %s, %d %d, %d, %d, %d, %d, %s, %s\n", s->shipId, s->dateTime, s->areaId, s->inArea ? "true" : "false", s->preTime, s->preLatitude, s->preLongitude, s->shipLatitude, s->shipLongitude, s->shipCog, s->shipSog, s->recvTime, s->content);
        s++;
    }

}
void ResultRender::vulInput00_1_Get(void *pResult) {
  DB_vulInput00_1 *data = (DB_vulInput00_1 *)malloc(sizeof(DB_vulInput00_1));
  memset(data, 0, sizeof(DB_vulInput00_1));
  DB_vulInput00_1 *s = (DB_vulInput00_1 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput00_1);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     dateTime collisionLatitude collisionLongitude dcpa tcpa risk firstShipId firstName firstType firstLatitude firstLongitude firstCog firstSog firstRecvtime secondShipId secondName secondType secondLatitude secondLongitude secondCog secondSog secondRecvtime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %d, %d, %f, %f, %f, %s, %s, %s, %d, %d, %d, %d, %s, %s, %s, %s, %d, %d, %d, %d, %s\n", s->dateTime, s->collisionLatitude, s->collisionLongitude, s->dcpa, s->tcpa, s->risk, s->firstShipId, s->firstName, s->firstType, s->firstLatitude, s->firstLongitude, s->firstCog, s->firstSog, s->firstRecvtime, s->secondShipId, s->secondName, s->secondType, s->secondLatitude, s->secondLongitude, s->secondCog, s->secondSog, s->secondRecvtime);
      s++;
  }
}
void ResultRender::vulInput00_2_Get(void *pResult) {
  DB_vulInput00_2 *data = (DB_vulInput00_2 *)malloc(sizeof(DB_vulInput00_2));
  memset(data, 0, sizeof(DB_vulInput00_2));
  DB_vulInput00_2 *s = (DB_vulInput00_2 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput00_2);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     shipId dateTime name type risk collisionLatitude collisionLongitude shipLatitude shipLongitude shipCog shipSog shipRecvtime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %f, %d, %d, %d, %d, %d, %d, %s\n", s->shipId, s->dateTime, s->name, s->type, s->risk, s->collisionLatitude, s->collisionLongitude, s->shipLatitude, s->shipLongitude, s->shipCog, s->shipSog, s->shipRecvtime);
      s++;
  }
}
void ResultRender::vulInput01_Get(void *pResult) {
  DB_vulInput01 *data = (DB_vulInput01 *)malloc(sizeof(DB_vulInput01));
  memset(data, 0, sizeof(DB_vulInput01));
  DB_vulInput01 *s = (DB_vulInput01 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput01);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     vulId areaId curSpd01 curDir01 curSpd02 curDir02 acciCount areaSeq areaName fromTime toTime areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %d, %d, %d, %d, %d, %s, %s, %s, %f, %f\n", s->vulId, s->areaId, s->curSpd01, s->curDir01, s->curSpd02, s->curDir02, s->acciCount, s->areaSeq, s->areaName, s->fromTime, s->toTime, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::vulInput02_Get(void *pResult) {
  DB_vulInput02 *data = (DB_vulInput02 *)malloc(sizeof(DB_vulInput02));
  memset(data, 0, sizeof(DB_vulInput02));
  DB_vulInput02 *s = (DB_vulInput02 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput02);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     vulId areaId windSpd waveHeight areaSeq areaName fromTime toTime areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %d, %d, %s, %s, %s, %f, %f\n", s->vulId, s->areaId, s->windSpd, s->waveHeight, s->areaSeq, s->areaName, s->fromTime, s->toTime, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::vulInput03_Get(void *pResult) {
  DB_vulInput03 *data = (DB_vulInput03 *)malloc(sizeof(DB_vulInput03));
  memset(data, 0, sizeof(DB_vulInput03));
  DB_vulInput03 *s = (DB_vulInput03 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput03);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     vulId areaId dynCong staCong acciRatio areaSeq areaName fromTime toTime areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %f, %f, %d, %d, %s, %s, %s, %f, %f\n", s->vulId, s->areaId, s->dynCong, s->staCong, s->acciRatio, s->areaSeq, s->areaName, s->fromTime, s->toTime, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::vulInput04_Get(void *pResult) {
  DB_vulInput04 *data = (DB_vulInput04 *)malloc(sizeof(DB_vulInput04));
  memset(data, 0, sizeof(DB_vulInput04));
  DB_vulInput04 *s = (DB_vulInput04 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput04);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     vulId areaId acciRatio passShips areaSeq areaName fromTime toTime areaLat areaLon \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %d, %d, %s, %s, %s, %f, %f\n", s->vulId, s->areaId, s->acciRatio, s->passShips, s->areaSeq, s->areaName, s->fromTime, s->toTime, s->areaLat, s->areaLon);
      s++;
  }
}
void ResultRender::vulInput05_Get(void *pResult) {
  DB_vulInput05 *data = (DB_vulInput05 *)malloc(sizeof(DB_vulInput05));
  memset(data, 0, sizeof(DB_vulInput05));
  DB_vulInput05 *s = (DB_vulInput05 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput05);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     shipId depTime arrTime depPort tonnage \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %f\n", s->shipId, s->depTime, s->arrTime, s->depPort, s->tonnage);
      s++;
  }
}
void ResultRender::vulInput06_Get(void *pResult) {
  DB_vulInput06 *data = (DB_vulInput06 *)malloc(sizeof(DB_vulInput06));
  memset(data, 0, sizeof(DB_vulInput06));
  DB_vulInput06 *s = (DB_vulInput06 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput06);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     shipId subShipId depTime arrTime depPort arrPort tugType tugLen mstLen subLen \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %s, %s, %d, %d, %d, %d\n", s->shipId, s->subShipId, s->depTime, s->arrTime, s->depPort, s->arrPort, s->tugType, s->tugLen, s->mstLen, s->subLen);
      s++;
  }
}
void ResultRender::vulInput07_Get(void *pResult) {
  DB_vulInput07 *data = (DB_vulInput07 *)malloc(sizeof(DB_vulInput07));
  memset(data, 0, sizeof(DB_vulInput07));
  DB_vulInput07 *s = (DB_vulInput07 *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_vulInput07);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     tgtShipId shipId index fromTime toTime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %s, %s\n", s->tgtShipId, s->shipId, s->index, s->fromTime, s->toTime);
      s++;
  }
}
void ResultRender::SpecThreshold_Get(void *pResult)
{
    DB_SpecThreshold *data = (DB_SpecThreshold *)malloc(sizeof(DB_SpecThreshold));
    memset(data, 0, sizeof(DB_SpecThreshold));

    DB_SpecThreshold *s = (DB_SpecThreshold *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_SpecThreshold);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime version sv20Threshold sv30Threshold abnormalThreshold sVAThreshold vBRSThreshold rSSThreshold");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%s, %f, %s, %s, %s, %s, %s, %s\n", 
        s->dateTime, s->version,  s->sv30Threshold, s->abnormalThreshold, s->sVAThreshold, s->vBRSThreshold, s->rSSThreshold);
        s++;
    }
}
void ResultRender::avsResponse_Get(void *pResult) {
  DB_avsResponse *data = (DB_avsResponse *)malloc(sizeof(DB_avsResponse));
  memset(data, 0, sizeof(DB_avsResponse));
  DB_avsResponse *s = (DB_avsResponse *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_avsResponse);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     acciTime osShipId tsShipId reqTime resTime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %s\n", s->acciTime, s->osShipId, s->tsShipId, s->reqTime, s->resTime);
      s++;
  }
}
void ResultRender::rssResponse_Get(void *pResult) {
  DB_rssResponse *data = (DB_rssResponse *)malloc(sizeof(DB_rssResponse));
  memset(data, 0, sizeof(DB_rssResponse));
  DB_rssResponse *s = (DB_rssResponse *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_rssResponse);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     acciTime osShipId tsShipId tgtShipId tgtLat tgtLon reqTime resTime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %d, %d, %s, %s\n", s->acciTime, s->osShipId, s->tsShipId, s->tgtShipId, s->tgtLat, s->tgtLon, s->reqTime, s->resTime);
      s++;
  }
}
void ResultRender::fishingHistoryArea_Get(void *pResult) {
  DB_fishingHistoryArea *data = (DB_fishingHistoryArea *)malloc(sizeof(DB_fishingHistoryArea));
  memset(data, 0, sizeof(DB_fishingHistoryArea));
  DB_fishingHistoryArea *s = (DB_fishingHistoryArea *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_fishingHistoryArea);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     AREA_ID FISHERY_TYPE FISH_SPECIES FROM_TIME TO_TIME \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %d, %d, %s, %s\n", s->areaId, s->fisheryType, s->fishSpecies, s->fromTime, s->toTime);
      s++;
  }
}
void ResultRender::fishingPatternArea_Get(void *pResult) {
  DB_fishingPatternArea *data = (DB_fishingPatternArea *)malloc(sizeof(DB_fishingPatternArea));
  memset(data, 0, sizeof(DB_fishingPatternArea));
  DB_fishingPatternArea *s = (DB_fishingPatternArea *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_fishingPatternArea);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     shipStr locStr areaStr dateTime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s\n", s->shipStr, s->locStr, s->areaStr, s->dateTime);
      s++;
  }
}
void ResultRender::abnormalPattern_Get(void *pResult) {
  DB_abnormalPattern *data = (DB_abnormalPattern *)malloc(sizeof(DB_abnormalPattern));
  memset(data, 0, sizeof(DB_abnormalPattern));
  DB_abnormalPattern *s = (DB_abnormalPattern *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_abnormalPattern);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     shipId dateTime shipLatitude shipLongitude shipCog shipSog recvTime abnormalValue \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %d, %d, %d, %d, %s, %f\n", s->shipId, s->dateTime, s->shipLatitude, s->shipLongitude, s->shipCog, s->shipSog, s->recvTime, s->abnormalValue);
      s++;
  }
}


//sv30
void ResultRender::FTS_Get(void *pResult)
{
    DB_FTS *data = (DB_FTS *)malloc(sizeof(DB_FTS));
    memset(data, 0, sizeof(DB_FTS));

    DB_FTS *s = (DB_FTS *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_FTS);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  routeId waypointid rudderAngle rpm spareControlForce spare1 spare2 spare3 spare4");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%d, %d, %f, %f, %f, %f, %f, %f, %f \n", s->routeId, s->waypointId, s->rudderAngle, s->rpm, s->spareControlForce, s->spare1, s->spare2, s->spare3, s->spare4);
        s++;
    }
}
void ResultRender::PastNavInfo_Get(void *pResult)
{
    DB_PastNavInfo *data = (DB_PastNavInfo *)malloc(sizeof(DB_PastNavInfo));
    memset(data, 0, sizeof(DB_PastNavInfo));

    DB_PastNavInfo *s = (DB_PastNavInfo *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_PastNavInfo);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  dateTime msi latitude longitude sog cog heading");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%s, %d, %f, %f, %f, %f, %f\n",
               s->dateTime, s->mmsi, s->latitude, s->longitude, s->sog, s->cog, s->heading);
        s++;
    }
}

void ResultRender::PastNavVesselInfo_Get(void *pResult)
{
    DB_PastNavVesselInfo *data = (DB_PastNavVesselInfo *)malloc(sizeof(DB_PastNavVesselInfo));
    memset(data, 0, sizeof(DB_PastNavVesselInfo));

    DB_PastNavVesselInfo *s = (DB_PastNavVesselInfo *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_PastNavVesselInfo);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  mmsi name vesselType imo callSign dimA dimB dimC dimD draft");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%d, %s, %s, %d, %s, %f, %f, %f, %f, %f \n",
               s->mmsi, s->name, s->vesselType, s->imo, s->callSign, s->dimA, s->dimB, s->dimC, s->dimD, s->draft);
        s++;
    }
}
void ResultRender::Route_Get(void *pResult)
{
    DB_Route *data = (DB_Route *)malloc(sizeof(DB_Route));
    memset(data, 0, sizeof(DB_Route));

    DB_Route *s = (DB_Route *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_Route);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  routeId version vesselVoyage vesselMmsi defaultWaypointRadius ");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%d, %s, %s, %d, %f\n",
              s->routeId, s->version, s->vesselVoyage, s->vesselMmsi, s->defaultWaypointRadius);
        s++;
    }
}
void ResultRender::RouteInfo_Get(void *pResult)
{
    DB_RouteInfo *data = (DB_RouteInfo *)malloc(sizeof(DB_RouteInfo));
    memset(data, 0, sizeof(DB_RouteInfo));

    DB_RouteInfo *s = (DB_RouteInfo *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_RouteInfo);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  routeId routeName routeAuthor routeStatus validityPeriodStart validityPeriodStop vesselName vesselMmsi vesselIMO vesselVoyage vesselDisplacement vesselCargo vesselGM optimizationMethod vesselMaxRoll vesselMaxWave vesselMaxWind vesselSpeedMax vesselServiceMin vesselServiceMax routeChangesHistoryt");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%d, %s, %s, %s, %s, %s, %s, %d, %d, %s, %d, %d, %.12f, %s, %d, %.12f, %.12f, %.12f, %.12f, %.12f, %s\n", s->routeId, s->routeName, s->routeAuthor, s->routeStatus, s->validityPeriodStart, s->validityPeriodStop, s->vesselName, s->vesselMmsi, s->vesselImo, s->vesselVoyage, s->vesselDisplacement, s->vesselCargo, s->vesselGm, s->optimizationMethod, s->vesselMaxRoll, s->vesselMaxWave, s->vesselMaxWind, s->vesselSpeedMax, s->vesselServiceMin, s->vesselServiceMax, s->routeChangesHistory);
        s++;
    }
}
void ResultRender::Waypoints_Get(void *pResult)
{
    DB_Waypoints *data = (DB_Waypoints *)malloc(sizeof(DB_Waypoints));
    memset(data, 0, sizeof(DB_Waypoints));

    DB_Waypoints *s = (DB_Waypoints *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_Waypoints);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  routeId defaultWaypoint defaultWaypointRadius id revision name radius lat lon starboardXtd portsideXtd safetyContour safetyDepth geometryType speedMin speedMax draughtForward draughtAft staticUkc dynamicUkc masthead legReport legInfo legNote1 legNote2");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%d, %d, %f, %d, %d, %s, %f, %f, %f, %f, %f, %f, %f, %d, %f, %f, %f, %f, %f, %f, %f, %s, %s, %s, %s\n",
              s->routeId, s->defaultWaypoint, s->defaultWaypointRadius, s->id, s->revision, s->name, s->radius, s->lat, s->lon, s->starboardXtd, s->portsideXtd, s->safetyContour, s->safetyDepth, s->geometryType, s->speedMin, s->speedMax, s->draughtForward, s->draughtAft, s->staticUkc, s->dynamicUkc, s->masthead, s->legReport, s->legInfo, s->legNote1, s->legNote2);
        s++;
    }
}
void ResultRender::Schedules_Get(void *pResult)
{
    DB_Schedules *data = (DB_Schedules *)malloc(sizeof(DB_Schedules));
    memset(data, 0, sizeof(DB_Schedules));

    DB_Schedules *s = (DB_Schedules *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_Schedules);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  routeId id name manual calculated waypointId etd etdWindowBefore etdWindowAfter etaWindowBefore etaWindowAfter stay speed speedWindow windSpeed windDirection currentSpeed currentDirection windLoss waveLoss totalLoss rpm pitch fuel relFuelSave absFuelSave note");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%d, %d, %s, %d, %d, %d, %s, %s, %s, %s, %s, %s, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %d, %f, %f, %f, %s\n",
              s->routeId, s->id, s->name, s->manual, s->calculated, s->waypointId, s->etd, s->etdWindowBefore, s->etdWindowAfter, s->etaWindowBefore, s->etaWindowAfter, s->stay, s->speed, s->speedWindow, s->windSpeed, s->windDirection, s->currentSpeed, s->currentDirection, s->windLoss, s->waveLoss, s->totalLoss, s->rpm, s->pitch, s->fuel, s->relFuelSave,  s->absFuelSave, s->note);
        s++;
    }
}

// sv40
void ResultRender::Catalogue_Get(void *pResult)
{
    DB_Catalogue *data = (DB_Catalogue *)malloc(sizeof(DB_Catalogue));
    memset(data, 0, sizeof(DB_Catalogue));

    DB_Catalogue *s = (DB_Catalogue *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_Catalogue);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  catalogid idIdentifier idDate exchangecatalogname category cataloguepath fileuri filedmzuri filename zone  productversion enctype productdate filesize encrypt hash");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%d) %d, %s, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s, %s\n",
               i, s->catalogid, s->idIdentifier, s->idEditionnumber, s->idDate, s->exchangecatalogname,
               s->category, s->cataloguepath, s->fileuri, s->filedmzuri, s->filename, s->zone,
               s->productversion, s->enctype, s->productversion, s->productdate, s->filesize, s->encrypt, s->hash);
        if (s->catalogid == 98)
            memcpy(data, s, sizeof(DB_Catalogue));
        s++;
    }
}
void ResultRender::EncUpdate_Get(void *pResult) {
  DB_EncUpdate *data = (DB_EncUpdate *)malloc(sizeof(DB_EncUpdate));
  memset(data, 0, sizeof(DB_EncUpdate));
  DB_EncUpdate *s = (DB_EncUpdate *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_EncUpdate);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     updateId shipMrn license responseTopic responseTime \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s\n", s->updateId, s->shipMrn, s->license, s->responseTopic, s->responseTime);
      s++;
  }
}
void ResultRender::S57Cell_Get(void *pResult) {
  DB_S57Cell *data = (DB_S57Cell *)malloc(sizeof(DB_S57Cell));
  memset(data, 0, sizeof(DB_S57Cell));
  DB_S57Cell *s = (DB_S57Cell *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_S57Cell);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     dsnm edtn updn uadt isdt expp intu slat wlon nlat elon zone \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %s, %c, %c, %s, %s, %s, %s, %s\n", s->dsnm, s->edtn, s->updn, s->uadt, s->isdt, s->expp, s->intu, s->slat, s->wlon, s->nlat, s->elon, s->zone);
      s++;
  }
}
void ResultRender::S101Cell_Get(void *pResult) {
  DB_S101Cell *data = (DB_S101Cell *)malloc(sizeof(DB_S101Cell));
  memset(data, 0, sizeof(DB_S101Cell));
  DB_S101Cell *s = (DB_S101Cell *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_S101Cell);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     dsnm edtn updn uadt isdt slat wlon nlat elon zone \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", s->dsnm, s->edtn, s->updn, s->uadt, s->isdt, s->slat, s->wlon, s->nlat, s->elon, s->zone);
      s++;
  }
}
void ResultRender::Zone_Get(void *pResult)
{
    DB_Zone *data = (DB_Zone *)malloc(sizeof(DB_Zone));
    memset(data, 0, sizeof(DB_Zone));

    DB_Zone *s = (DB_Zone *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_Zone);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  name sea slat wlon nla elon version");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        //printf("%s\n", s->sea);
        printf("%s, %s, %s, %s, %s, %s\n",
               s->name, s->slat, s->wlon, s->nlat, s->elon, s->version);
        s++;
    }
}

//sv51
void ResultRender::GuideLine_Get(void *pResult)
{
   DB_GuideLine *data = (DB_GuideLine *)malloc(sizeof(DB_GuideLine));
    memset(data, 0, sizeof(DB_GuideLine));

    DB_GuideLine *s = (DB_GuideLine *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLine);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  guidelineid guideSimbolType displayType pointLat1 pointLon1 pointLat2 pointLon2 pointLat3 pointLon3 pointLat4 pointLon4 message");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%d, %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %s\n",
               s->guidelineId, s->guideSimbolType, s->displayType, s->pointLat1, s->pointLon1,
               s->pointLat2, s->pointLon2, s->pointLat3, s->pointLon3, s->pointLat4, s->pointLon4,
               s->message);
        s++;
    }
}
void ResultRender::GuideLineWharf_Get(void *pResult) {
  DB_GuideLineWharf *data = (DB_GuideLineWharf *)malloc(sizeof(DB_GuideLineWharf));
  memset(data, 0, sizeof(DB_GuideLineWharf));
  DB_GuideLineWharf *s = (DB_GuideLineWharf *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineWharf);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor name dName dName length fromtDepthMin fromtDepthMax loadingCapacity \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s, %f, %f, %f, %s\n", s->index, s->harbor, s->name, s->dName, s->dName, s->length, s->fromtDepthMin, s->fromtDepthMax, s->loadingCapacity);
      s++;
  }
}
void ResultRender::GuideLineAnchorage_Get(void *pResult) {
  DB_GuideLineAnchorage *data = (DB_GuideLineAnchorage *)malloc(sizeof(DB_GuideLineAnchorage));
  memset(data, 0, sizeof(DB_GuideLineAnchorage));
  DB_GuideLineAnchorage *s = (DB_GuideLineAnchorage *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineAnchorage);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor name fairwayName division ability \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s, %s\n", s->index, s->harbor, s->name, s->fairwayName, s->division, s->ability);
      s++;
  }
}
void ResultRender::GuideLineVTS_Get(void *pResult) {
  DB_GuideLineVTS *data = (DB_GuideLineVTS *)malloc(sizeof(DB_GuideLineVTS));
  memset(data, 0, sizeof(DB_GuideLineVTS));
  DB_GuideLineVTS *s = (DB_GuideLineVTS *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineVTS);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor callSign division vhfChannel reportingPoint reportingTime reportingContent \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s, %s, %s, %s\n", s->index, s->harbor, s->callSign, s->division, s->vhfChannel, s->reportingPoint, s->reportingTime, s->reportingContent);
      s++;
  }
}
void ResultRender::GuideLineSafetyStan_Get(void *pResult) {
  DB_GuideLineSafetyStan *data = (DB_GuideLineSafetyStan *)malloc(sizeof(DB_GuideLineSafetyStan));
  memset(data, 0, sizeof(DB_GuideLineSafetyStan));
  DB_GuideLineSafetyStan *s = (DB_GuideLineSafetyStan *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineSafetyStan);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor state content \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s\n", s->index, s->harbor, s->state, s->content);
      s++;
  }
}
void ResultRender::GuideLineSafetySpeed_Get(void *pResult) {
  DB_GuideLineSafetySpeed *data = (DB_GuideLineSafetySpeed *)malloc(sizeof(DB_GuideLineSafetySpeed));
  memset(data, 0, sizeof(DB_GuideLineSafetySpeed));
  DB_GuideLineSafetySpeed *s = (DB_GuideLineSafetySpeed *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineSafetySpeed);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor restrictedWater targetVessel limitedSpeed \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s\n", s->index, s->harbor, s->restrictedWater, s->targetVessel, s->limitedSpeed);
      s++;
  }
}
void ResultRender::GuideLineTug_Get(void *pResult) {
  DB_GuideLineTug *data = (DB_GuideLineTug *)malloc(sizeof(DB_GuideLineTug));
  memset(data, 0, sizeof(DB_GuideLineTug));
  DB_GuideLineTug *s = (DB_GuideLineTug *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineTug);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor scale tugData \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s\n", s->index, s->harbor, s->scale, s->tugData);
      s++;
  }
}
void ResultRender::GuideLineFairway_Get(void *pResult) {
  DB_GuideLineFairway *data = (DB_GuideLineFairway *)malloc(sizeof(DB_GuideLineFairway));
  memset(data, 0, sizeof(DB_GuideLineFairway));
  DB_GuideLineFairway *s = (DB_GuideLineFairway *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineFairway);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor name length depthMin depthMax widthMin widthMax content \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %f, %f, %f, %f, %f, %s\n", s->index, s->harbor, s->name, s->length, s->depthMin, s->depthMax, s->widthMin, s->widthMax, s->content);
      s++;
  }
}
void ResultRender::GuideLinePilot_Get(void *pResult) {
  DB_GuideLinePilot *data = (DB_GuideLinePilot *)malloc(sizeof(DB_GuideLinePilot));
  memset(data, 0, sizeof(DB_GuideLinePilot));
  DB_GuideLinePilot *s = (DB_GuideLinePilot *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLinePilot);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor fairwayName division \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s\n", s->index, s->harbor, s->fairwayName, s->division);
      s++;
  }
}
void ResultRender::GuideLineCourse_Get(void *pResult) {
  DB_GuideLineCourse *data = (DB_GuideLineCourse *)malloc(sizeof(DB_GuideLineCourse));
  memset(data, 0, sizeof(DB_GuideLineCourse));
  DB_GuideLineCourse *s = (DB_GuideLineCourse *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineCourse);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor fairwayName division \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s\n", s->index, s->harbor, s->fairwayName, s->division);
      s++;
  }
}
void ResultRender::GuideLineSpeed_Get(void *pResult) {
  DB_GuideLineSpeed *data = (DB_GuideLineSpeed *)malloc(sizeof(DB_GuideLineSpeed));
  memset(data, 0, sizeof(DB_GuideLineSpeed));
  DB_GuideLineSpeed *s = (DB_GuideLineSpeed *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineSpeed);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor name speed \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %f\n", s->index, s->harbor, s->name, s->speed);
      s++;
  }
}
void ResultRender::GuideLineInfo_Get(void *pResult) {
  DB_GuideLineInfo *data = (DB_GuideLineInfo *)malloc(sizeof(DB_GuideLineInfo));
  memset(data, 0, sizeof(DB_GuideLineInfo));
  DB_GuideLineInfo *s = (DB_GuideLineInfo *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLineInfo);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     index harbor fairwayName division content \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%d, %s, %s, %s, %s\n", s->index, s->harbor, s->fairwayName, s->division, s->content);
      s++;
  }
}
void ResultRender::GuideLinePoint_Get(void *pResult) {
  DB_GuideLinePoint *data = (DB_GuideLinePoint *)malloc(sizeof(DB_GuideLinePoint));
  memset(data, 0, sizeof(DB_GuideLinePoint));
  DB_GuideLinePoint *s = (DB_GuideLinePoint *)pResult;
  int rows = malloc_usable_size(pResult) / sizeof(DB_GuideLinePoint);
  printf(" rows : %d\n", rows);
  puts("---------------------------------------------------------------------------------------------------\n"); 
  puts("     tableDv rowDv sequence latitude longitude heading \n" );
  puts("---------------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < rows; i++)
  {
      printf("%f, %f, %d, %f, %f, %f\n", s->tableDv, s->rowDv, s->sequence, s->latitude, s->longitude, s->heading);
      s++;
  }
}
void ResultRender::ShipPosition_Get(void *pResult)
{
DB_ShipPosition *data = (DB_ShipPosition *)malloc(sizeof(DB_ShipPosition));
    memset(data, 0, sizeof(DB_ShipPosition));

    DB_ShipPosition *s = (DB_ShipPosition *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_ShipPosition);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  mmsi time cog sog latitude lngitude\n");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%d, %s, %f, %f, %f, %f\n",
               s->mmsi, s->time, s->sog, s->cog, s->latitude, s->longitude);
        s++;
    }
}


void ResultRender::ShipDensity_Get(void *pResult)
{
    DB_ShipDensity *data = (DB_ShipDensity *)malloc(sizeof(DB_ShipDensity));
    memset(data, 0, sizeof(DB_ShipDensity));

     DB_ShipDensity *s = (DB_ShipDensity *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_ShipDensity);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts("  index time pointLat1 pointLon1 pointLat2 pointLon2 pointLat3 pointLon3 pointLat4 pointLon4 densityValue shipCount \n");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%d, %s, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d\n",
               s->index, s->time, s->pointLat1, s->pointLon1, s->pointLat2, s->pointLon2, s->pointLat3, s->pointLon3, s->pointLat4, s->pointLon4, s->densityValue, s->shipCount);
        s++;
    }

}


void ResultRender::ServiceLog_Get(void *pResult)
{
    DB_ServiceLog *data = (DB_ServiceLog *)malloc(sizeof(DB_ServiceLog));
    memset(data, 0, sizeof(DB_ServiceLog));

     DB_ServiceLog *s = (DB_ServiceLog *)pResult;
    int rows = malloc_usable_size(pResult) / sizeof(DB_ServiceLog);
    printf("rows: %d\n", rows);
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    puts(" serviceName  interfaceName  regDateTime  content \n");
    puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < rows; i++)
    {
        printf("%s, %s, %s, %s \n", s->serviceName, s->intefaceName,s->regDateTime,s->content);
        s++;
    }
}



void ResultRender::VesselStaticInfo_Get(void *pResult)
{
    
    DB_VesselStaticInfo *data = (DB_VesselStaticInfo *)malloc(sizeof(DB_VesselStaticInfo));
	memset(data, 0, sizeof(DB_VesselStaticInfo));


	DB_VesselStaticInfo *s = (DB_VesselStaticInfo *)pResult;
	int rows = malloc_usable_size(pResult)/sizeof(DB_VesselStaticInfo);
	printf("rows: %d\n", rows);
	puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("  catalogid idIdentifier idDate exchangecatalogname category cataloguepath fileuri filedmzuri filename zone  productversion enctype productdate filesize encrypt hash");
	puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	for (int i=0; i<rows; i++) {
        printf("%s, %s, %s, %s, %s, %d, %d, %d, %d, %d, %d, %d, %f, %f, %d, %d, %s, %d, %d, %d, %d, %d, %d, %d, %f, %f, %d, %f, %d, %f, %s, %s, %f, %f, %s, %f", s->shipMrn,s->mmsi,s->dateTime,s->shipName,s->callSign,s->shipType,s->dima,s->dimb,s->dimc,s->dimd,s->gnssType,s->maxDraught,s->aisLength,s->aisBeam,s->gpsAntennaXLocation,s->gpsAntennaYLocation,s->shipCode,s->shipLoa,s->shipLpp,s->shipWeight,s->shipDwt,s->cargoCode,s->cargoWeight,s->fuelRemain,s->shipDraftFwd,s->shipDraftAft,s->rudNum,s->rudArea,s->aisImoNumber,s->shipDisplacement,s->shipFlag,s->hullType,s->shipBreadth,s->shipDepth,s->vesselType,s->shipEngineHp);
		s++;
	}
}

void ResultRender::ShipStatic_Get(void *pResult)
{
    DB_ShipStaticInfo *data = (DB_ShipStaticInfo *)malloc(sizeof(DB_ShipStaticInfo));
	memset(data, 0, sizeof(DB_ShipStaticInfo));


	DB_ShipStaticInfo *s = (DB_ShipStaticInfo *)pResult;
	int rows = malloc_usable_size(pResult)/sizeof(DB_ShipStaticInfo);
	printf("rows: %d\n", rows);
	puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	for (int i=0; i<rows; i++) {
        printf("%d, %s, %s, %f, %f \n", s->nServiceId, s->szUtcDate, s->szUtcTime, s->dLatitude, s->dLongitude);        
        printf("    { ");
        NavigationInfo_Get(s->arrNavigationInfo);
        EmergencyInfo_Get(s->arrEmergencyInfo);
        FireDoor_Get(s->arrFireDoor);
        FireAlarm_Get(s->arrFireAlarm);
        OldFireAlarm_Get(s->arrOldFireAlarm);
        MainEngine_Get(s->arrMainEngine);
        Generator_Get(s->arrGenerator);
        SteeringGear_Get(s->arrSteeringGear);
        Recovery_Get(s->arrRecovery);
        TankLevel_Get(s->arrTankLevel);
        Ramp_Get(s->arrRamp);
        Telegraph_Get(s->arrTelegraph);
        Stability_Get(s->arrStability);
        printf("}\n");
		s++;
	}
}


void ResultRender::ArgoMet_Get(void *pResult)
{

}


template <typename T>
void ResultRender::Render_Result_fromStream(void *pResult, int nServiceID)
{
    std::fstream fsReadStruct("./so/ServiceStruct/EnaviDBStruct.h");

    if(fsReadStruct.is_open() == false)
    {
        return;
    }

    string line;
    string ignore;
    string type;
    string strStruct = m_vecStruct.at(nServiceID);
    string valueName;
    std::vector<S_Element> vecValueName;
    vecValueName.clear();

    while(std::getline(fsReadStruct, line))
    {
        if(line.find(strStruct) != string::npos)
        {
            fsReadStruct >> ignore;
            fsReadStruct >> type >> valueName;

            while(type != "};")
            {

                S_Element sElement;
                sElement.nSize = 1;
                sElement.valueName = valueName;

                int frontIndex = valueName.find('[');

                E_ValueType eType = (m_mapValueType.find(type))->second;
                sElement.type = eType;
                
                if(frontIndex != string::npos)
                {
                    int rearIndex = valueName.find(']');
                    string strSize = valueName.substr(frontIndex + 1, rearIndex - 1);
                    if(eType == E_ValueType::eChar)
                    {
                        sElement.nSize = std::stoi(strSize);
                        sElement.type = E_ValueType::eString;
                    }
                }
                                printf("value name : %s, type name : %d\n", valueName.c_str(), (int)sElement.type);


                vecValueName.push_back(sElement);
                
                fsReadStruct >> type >> valueName;

            }

            break;
        }


    }
    for(int i = 0; i < vecValueName.size(); i++)
    {
        printf("%s  ", vecValueName.at(i).valueName.c_str());
    }
    printf("\n");



	T *s = (T *)pResult;
	int rows = malloc_usable_size(pResult)/sizeof(T);

	printf("rows: %d\n", rows);

    int prevSize = 0;


    S_Mover mover;



    for(int i = 0; i < rows ;i++)
    {
        void *pCurrent = (void *)s;
        if(pCurrent == nullptr)
            printf("pCurrent is null\n");

        prevSize= 1;

        S_Mover *pMover = nullptr;
        S_Mover *pPreMover = new S_Mover();


        for(int j = 0; j < vecValueName.size(); j++)
        {
            if(j == 0)
            {
                if(vecValueName.at(j).type == eChar)
                  {
                      pPreMover->pChar = (char *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eChar;
                  }
                  else if(vecValueName.at(j).type == eInt)
                  {
                      pPreMover->pInt= (int *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eInt;
                  }
                  else if(vecValueName.at(j).type == eLong)
                  {
                      pPreMover->pLong = (long *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eLong;
                  }
                  else if(vecValueName.at(j).type == eFloat)
                  {
                      pPreMover->pFloat = (float *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eFloat;
                  }
                  else if(vecValueName.at(j).type == eDouble)
                  {
                      pPreMover->pDouble = (double *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eDouble;
                  }
                  else if(vecValueName.at(j).type == eString)
                  {
                      pPreMover->pStr = (const char *)pCurrent;
                      pPreMover->eDataMoved = E_ValueType::eString;
                      prevSize = vecValueName.at(j).nSize;
                  }
            }
            else
            {
                  if(vecValueName.at(j).type == eChar)
                  {
                    pMover = MoveAndCast<char>(pPreMover, eChar, prevSize);
                  }
                  else if(vecValueName.at(j).type == eInt)
                  {
                    pMover = MoveAndCast<int>(pPreMover, eInt, prevSize);
                  }
                  else if(vecValueName.at(j).type == eLong)
                  {
                      pMover = MoveAndCast<long>(pPreMover, eLong, prevSize);
                  }
                  else if(vecValueName.at(j).type == eFloat)
                  {
                      pMover = MoveAndCast<float>(pPreMover, eFloat, prevSize);
                  }
                  else if(vecValueName.at(j).type == eDouble)
                  {
                      pMover = MoveAndCast<double>(pPreMover, eDouble, prevSize);
                  }
                  else if(vecValueName.at(j).type == eString)
                  {
                      pMover = MoveAndCast<const char>(pPreMover, eString, prevSize);
                  }
                 prevSize = vecValueName.at(j).nSize;
                 pPreMover = pMover;


            }
            

        }
        
        printf("\n");

        s = s + 1;
    }




}


    template<typename T> 
    S_Mover * ResultRender::MoveAndCast(S_Mover *pMover, E_ValueType eType, int prevSize)
        {
            E_ValueType eMoved = pMover->eDataMoved;
            T * pData = nullptr;
            S_Mover *pNewMover = new S_Mover();

            if(eMoved == E_ValueType::eInt)
            {
                printf("%d(%d) ,", *(pMover->pInt), prevSize);
                pData = (T*)(pMover->pInt + prevSize);
            }
            else if(eMoved == E_ValueType::eFloat)
            {
                printf("%f ,", *(pMover->pFloat));
                pData = (T*)(pMover->pFloat + prevSize);
            }
            else if(eMoved == E_ValueType::eLong)
            {
                printf("%d ,", *(pMover->pLong));
                pData = (T*)(pMover->pLong + prevSize);
            }
            else if(eMoved == E_ValueType::eDouble)
            {
                printf("%f ,", *(pMover->pDouble));
                pData = (T*)(pMover->pDouble + prevSize);
            }
            else if(eMoved == E_ValueType::eChar)
            {
                printf("%c ,", *(pMover->pChar));
                pData = (T*)(pMover->pChar + prevSize);
            }
            else if(eMoved == E_ValueType::eString)
            {
                printf("STR(%d) : %s ,", prevSize, (pMover->pStr));
                pData = (T*)(pMover->pStr + prevSize);
            }

            

            if(eType == E_ValueType::eInt)
            {
                pNewMover->eDataMoved = E_ValueType::eInt;
                pNewMover->pInt = (int *)pData;
            }
            else if(eType == E_ValueType::eFloat)
            {
                pNewMover->eDataMoved = E_ValueType::eFloat;
                pNewMover->pFloat = (float *)pData;
            }
            else if(eType == E_ValueType::eLong)
            {
                 pNewMover->eDataMoved = E_ValueType::eLong;
                pNewMover->pLong = (long *)pData;
            }
            else if(eType == E_ValueType::eDouble)
            {
                 pNewMover->eDataMoved = E_ValueType::eDouble;
                pNewMover->pDouble = (double *)pData;
            }
            else if(eType == E_ValueType::eChar)
            {
                 pNewMover->eDataMoved = E_ValueType::eChar;
                pNewMover->pChar = (char *)pData;
            }
            else if(eType == E_ValueType::eString)
            {
                pNewMover->eDataMoved = E_ValueType::eString;
                pNewMover->pStr = (const char *)pData;
            }

        }



void ResultRender::NavigationInfo_Get(vector<DB_NavigationInfo> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_NavigationInfo & s = vecData.at(i);
        printf("{ ");
        printf("%s, %s, %s, %s, %s, %s, %s, %s, %s, %s", s.szLOG,s.szAIS,s.szGPS1,s.szGPS2,s.szECDIS,s.szRADAR1,s.szRADAR2,s.szEchoSounder,s.szGyroCompass,s.szAutoPilot);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::EmergencyInfo_Get(vector<DB_EmergencyInfo> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_EmergencyInfo & s = vecData.at(i);
        printf("{ ");
        printf("%s, %d, %d, %d, %s, %s, %s", s.szRunTime,s.nFireLevel,s.nSeakeepingLevel,s.nNavigationLevel,s.szFireSafetyCode,s.szSeakeepingQualiyCode,s.szNavigationSafetyCode);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::FireDoor_Get(vector<DB_FireDoor> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_FireDoor & s = vecData.at(i);
        printf("{ ");
        printf("%s, %s, %d", s.bUse ? "true" : "false",s.bDoorOpen? "true" : "false",s.nPositionId);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::FireAlarm_Get(vector<DB_FireAlarm> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_FireAlarm & s = vecData.at(i);
        printf("{ ");
        printf("%s, %d, %s, %d, %s", s.bUse ? "true" : "false",s.sCount,s.szDetectorType,s.nPositionId,s.szAlarmTime);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::OldFireAlarm_Get(vector<DB_OldFireAlarm> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_OldFireAlarm & s = vecData.at(i);
        printf("{ ");
        printf("%s, %d, %s", s.bUse ? "true" : "false",s.sCount,s.bBreakOut ? "true" : "false");
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::MainEngine_Get(vector<DB_MainEngine> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_MainEngine & s = vecData.at(i);
        printf("{ ");
        printf("%s, %s, %s, %s, %f, %f",s.szShutdown,s.szSlowdown, s.bUseRpm1 ? "true" : "false",s.bUseRpm2 ? "true" : "false",s.dRpm1,s.dRpm2);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::Generator_Get(vector<DB_Generator> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_Generator & s = vecData.at(i);
        printf("{ ");
        printf("%d, %d, %s, %s, %s, %s, %s, %s, %s",s.sNo,s.sCount,s.szCFW_HighTemp_Trip,s.szLO_LowPress_Trip,s.szOverSpeed_Trip,s.szCommon_Trip,s.szSpeedSensorFail_Trip,s.szStartFail,s.szCommonShutdown);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::SteeringGear_Get(vector<DB_SteeringGear> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_SteeringGear & s = vecData.at(i);
        printf("{ ");
        printf("%d, %d, %s, %s, %s, %s, %s",s.sNo,s.sCount,s.szHydLoTk_LL,s.szMotor_Run,s.szNoVolt,s.szOverload,s.szPhase_Fail);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::Recovery_Get(vector<DB_Recovery> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_Recovery & s = vecData.at(i);
        printf("{ ");
        printf("%s, %s, %s, %s,%s, %s, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f", s.bUseRoll ? "true" : "false",s.bUsePitch ? "true" : "false",s.bUseGps ? "true" : "false",s.bUseWind ? "true" : "false", s.bUseRudder1 ? "true" : "false", s.bUseRudder2 ? "true" : "false",s.dRolling,s.dPitching,s.dCog,s.dSog,s.dShipHeading,s.dShipSpeed,s.dWindDirection,s.dWindSpeed,s.dRudder1,s.dRudder2);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::TankLevel_Get(vector<DB_TankLevel> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_TankLevel & s = vecData.at(i);
        printf("{ ");
        printf("%d, %s, %s, %d, %f", s.sCount,s.szTankType,s.szTankName,s.sTankNumber,s.dVal);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::Ramp_Get(vector<DB_Ramp> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_Ramp & s = vecData.at(i);
        printf("{ ");
        printf("%s, %d, %d, %s", s.bRampUse ? "true" : "false",s.sCount,s.nRampId,s.bRampDoorOpen? "true" : "false");
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::Telegraph_Get(vector<DB_Telegraph> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_Telegraph & s = vecData.at(i);
        printf("{ ");
        printf("%s, %d, %d, %d",s.bTelegraphUse ? "true" : "false",s.sCount,s.nTelegraphId,s.nTelegraphStatus);
        printf("}, ");
    }
    printf("]\n");
}
void ResultRender::Stability_Get(vector<DB_Stability> &vecData){
    int nCount = vecData.size();
    printf("[\n");
    for(int i = 0; i< nCount; i++)
    {
        DB_Stability & s = vecData.at(i);
        printf("{ ");
        printf("%f, %f, %f, %f",s.dForeDraft,s.dAftDraft,s.dKG,s.dGoM);
        printf("}, ");
    }
    printf("]\n");
}


void ResultRender::MrnRecentVersion_Get(void *pResult)
{
    DB_MrnRecentVersion *data = (DB_MrnRecentVersion *)malloc(sizeof(DB_MrnRecentVersion));
	memset(data, 0, sizeof(DB_MrnRecentVersion));
	DB_MrnRecentVersion *s = (DB_MrnRecentVersion *)pResult;
	int rows = malloc_usable_size(pResult)/sizeof(DB_MrnRecentVersion);
	printf("rows: %d\n", rows);
	puts("  shipMrn   license    w1Version   w2Version  w3Version s1Version    s2Version   s3Version  s4Version s5Version    e1Version   e2Version  e3Version scVersion");
	for (int i=0; i<rows; i++) {
        printf("%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s \n", s->shipMrn,s->license,s->w1Version,s->w2Version,s->w3Version,s->s1Version,s->s2Version,s->s3Version,s->s4Version,s->s5Version,s->e1Version,s->e2Version,s->e3Version,s->scVersion);
		s++;
	}
}
void ResultRender::FeaturesForWaterway_Get(void *pResult)
{
    DB_FeaturesForWaterway *data = (DB_FeaturesForWaterway *)malloc(sizeof(DB_FeaturesForWaterway));
	memset(data, 0, sizeof(DB_FeaturesForWaterway));
	DB_FeaturesForWaterway *s = (DB_FeaturesForWaterway *)pResult;
	int rows = malloc_usable_size(pResult)/sizeof(DB_FeaturesForWaterway);
	printf("rows: %d\n", rows);
	puts("     spec   version      startDate  endDate     generalCategory       geomtype       geom");
	for (int i=0; i<rows; i++) {
        printf( "%s, %s, %s, %s, %s, %s, %s\n",s->spec,s->version,s->startDate,s->endDate,s->generalCategory,s->geomtype,s->geom);
		s++;
	}
}