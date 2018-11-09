#pragma once

#include<stdio.h>
#include<string.h>
#include"./so/ServiceStruct/EnaviDBService.h"
#include"./so/ServiceStruct/EnaviDBStruct.h"
#include<vector>
#include<map>
#include<typeinfo>

using namespace Service;
using namespace std;

#define STRUCT(s) 



enum E_ValueType
{
    eNone = 0,
    eChar,
    eString,
    eInt,
    eLong,
    eFloat,
    eDouble,
    eBoolean,
    eMax,
};

struct S_Element
{
    E_ValueType type;
    std::string valueName;
    int nSize;
};
struct S_Mover
{
    E_ValueType eDataMoved;
    int *pInt;
    float *pFloat;
    long *pLong;
    double *pDouble;
    char *pChar;
    const char *pStr;
    bool *pBool;
};

class ResultRender
{
    public:
        ResultRender();
        ~ResultRender();


    private:
        void (ResultRender::*m_arrRenderFunction[((int)E_Service::eService_Max)])(void *);

    private:
        //sv10
        void abnormalPattern_Get(void *pResult);
        void areaDetail_Get(void *pResult);
        void areaMst_Get(void *pResult);
        void areaSelect_Get(void *pResult);
        void avsResponse_Get(void *pResult);
        void fishingHistoryArea_Get(void *pResult);
        void fishingPatternArea_Get(void *pResult);
        void rssResponse_Get(void *pResult);
        void vulInput00_1_Get(void *pResult);
        void vulInput00_2_Get(void *pResult);
        void vulInput01_Get(void *pResult);
        void vulInput02_Get(void *pResult);
        void vulInput03_Get(void *pResult);
        void vulInput04_Get(void *pResult);
        void vulInput05_Get(void *pResult);
        void vulInput06_Get(void *pResult);
        void vulInput07_Get(void *pResult);
        
        
        


        void AccidentRisk_Get(void *pResult);
        void AccidentPrediction_Get(void *pResult);
        void DangerShipAlarm_Get(void *pResult);
        void SpecThreshold_Get(void *pResult);
        void AttentionShip_Get(void *pResult);


        //sv20
        void ShipStatic_Get(void *pResult);


        //sv30
        void FTS_Get(void *pResult);
        void PastNavInfo_Get(void *pResult);
        void PastNavVesselInfo_Get(void *pResult);
        void Route_Get(void *pResult);
        void RouteInfo_Get(void *pResult);





        //sv40
        void Catalogue_Get(void *pResult);
        void EncUpdate_Get(void *pResult);
        void S57Cell_Get(void *pResult);
        void S101Cell_Get(void *pResult);
        void Zone_Get(void *pResult);
        void Waypoints_Get(void *pResult);
        void Schedules_Get(void *pResult);
        void MrnRecentVersion_Get(void *pResult);

        //sv51
        void GuideLine_Get(void *pResult);
        void GuideLineAnchorage_Get(void *pResult);
        void GuideLineCourse_Get(void *pResult);
        void GuideLineFairway_Get(void *pResult);
        void GuideLineInfo_Get(void *pResult);
        void GuideLinePilot_Get(void *pResult);
        void GuideLinePoint_Get(void *pResult);
        void GuideLineSafetySpeed_Get(void *pResult);
        void GuideLineSafetyStan_Get(void *pResult);
        void GuideLineSpeed_Get(void *pResult);
        void GuideLineTug_Get(void *pResult);
        void GuideLineVTS_Get(void *pResult);
        void GuideLineWharf_Get(void *pResult);
        void ShipPosition_Get(void *pResult);
        void ShipDensity_Get(void *pResult);

        //sv52
        void ArgoMet_Get(void *pResult);
        void FeaturesForWaterway_Get(void *pResult);
        //nested
        void NavigationInfo_Get(vector<DB_NavigationInfo> &vecData);
        void EmergencyInfo_Get(vector<DB_EmergencyInfo> &vecData);
        void FireDoor_Get(vector<DB_FireDoor> &vecData);
        void FireAlarm_Get(vector<DB_FireAlarm> &vecData);
        void OldFireAlarm_Get(vector<DB_OldFireAlarm> &vecData);
        void MainEngine_Get(vector<DB_MainEngine> &vecData);
        void Generator_Get(vector<DB_Generator> &vecData);
        void SteeringGear_Get(vector<DB_SteeringGear> &vecData);
        void Recovery_Get(vector<DB_Recovery> &vecData);
        void TankLevel_Get(vector<DB_TankLevel> &vecData);
        void Ramp_Get(vector<DB_Ramp> &vecData);
        void Telegraph_Get(vector<DB_Telegraph> &vecData);
        void Stability_Get(vector<DB_Stability> &vecData);


        void VesselStaticInfo_Get(void *pResult);

        void ServiceLog_Get(void *pResult);

        void WeatherInfo_Get(void *pResult);
        void RestrictedSpeedAreaInfo_Get(void *pResult);
        void OilTankerProhibition_Get(void *pResult);
        void CoastlineInfo_Get(void *pResult);  
        void FishingAreaInfo_Get(void *pResult);
        void LimitedAreaInfo_Get(void *pResult);
        void LowDepthreefInfo_Get(void *pResult);
        void DepthInfo_Get(void *pResult);
        void EtcInfo_Get(void *pResult);
        void EtcInfoEtc_Get(void *pResult);
        void OptimumRouteInfo_Get(void *pResult);
        void OptimumRouteInfoEtc_Get(void *pResult);

        void VulnerabilityAnalysis_Get(void *pResult);
        void NavigationViolationa_Get(void *pResult);
        void CollisionRisk_Get(void *pResult);
        void StrandingRisk_Get(void *pResult);
        void NearMissViolation(void *pResult);
        void NormalOperation_Get(void *pResult);

        void AccidentAdvice_Get(void *pResult);

        
    

        void Update_Get(void *pResult);

    private:
        std::vector<std::string> m_vecStruct;
        std::map<std::string, E_ValueType> m_mapValueType;
        void (ResultRender::*m_arrResultRenderer[(int)Service::E_Service::eService_Max])(void *pResult, int nServiceID);
        

        template<typename T> S_Mover * MoveAndCast(S_Mover *pMover, E_ValueType eType, int prevSize);
       

    public:
        void Init();
        void Render_Result(void *pResult, int iService, int nRest);
        template<typename T> void Render_Result_fromStream(void *pResult, int nServiceID);
        
};