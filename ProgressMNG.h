#include<vector>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include"./so/ServiceStruct/EnaviDBService.h"
#include "./so/ServiceStruct/EnaviDBStruct.h"

using namespace std;

enum E_Progress_State{
    Init = 0,
    Continue,
    Quit,
};
enum E_RestServiceType{
    Select = 0,
    Insert,
    Update,
    Delete,
    Max
};



class ResultRender;

class ProgressMNG
{
    private:
        ProgressMNG();
        ~ProgressMNG();

    private:
        static ProgressMNG * m_Instance;

    public:
        static bool CreateInstance();
        static ProgressMNG * GetInstance();
        static void DestoryInstance();
        void Init();

    private:
        std::vector<std::string> m_arrService;
        std::vector<std::string> m_arrSelectQuery;

        //RestCallClient * m_restCallService;
    public:

        E_Progress_State InputProgress(const char *);
        void printServiceList();
        int restCall_Select(string *pStr);
        int restCall_Insert(void **ppParam);
        int restCall_Update(void **ppParam);
        int restCall_Delete(void **ppParam);

    private:
        //Test Function
        void * SetCatalogue_Insert();
        void * SetVessel_Insert();
        void * SetOptimumRoute_Insert();
        void * SetOptimumRoute_Ect_Insert();
        void * SetGuideLine_Insert();
        void * SetZone_Insert();
        //SV10
        void * SetAccidentPrediction();
        void * SetAccidentRisk();
        void * SetAttentionShip();
        void * SetDangerShipAlarm();
        void * SetSpecThreshold();
        void*   SetareaMst();
        void*   SetareaDetail();
        void*   SetvulInput00_1();
        void*   SetvulInput00_2();
        void*   SetvulInput01();
        void*   SetvulInput02();
        void*   SetvulInput03();
        void*   SetvulInput04();
        void*   SetvulInput05();
        void*   SetvulInput06();
        void*   SetvulInput07();
        void*   SetavsResponse();
        void*   SetrssResponse();
        void*   SetfishingHistoryArea();
        void*   SetfishingPatternArea();
        void*   SetabnormalPattern();

        //SV20 Insert
        void *  SetShipStaticInfo();
        void *  SetNavigationInfo(std::vector<DB_NavigationInfo> &vecData);
        void *  SetEmergencyInfo(std::vector<DB_EmergencyInfo> &vecData);
        void *  SetFireAlarm(std::vector<DB_FireAlarm> &vecData);
        void *  SetFireDoor(std::vector<DB_FireDoor> &vecData);
        void *  SetGenerator(std::vector<DB_Generator> &vecData);
        void *  SetMainEngine(std::vector<DB_MainEngine> &vecData);
        void *  SetOldFireAlarm(std::vector<DB_OldFireAlarm> &vecData);
        void *  SetRamp(std::vector<DB_Ramp> &vecData);
        void *  SetRecovery(std::vector<DB_Recovery> &vecData);
        void *  SetStability(std::vector<DB_Stability> &vecData);
        void *  SetSteeringGear(std::vector<DB_SteeringGear> &vecData);
        void *  SetTankLevel(std::vector<DB_TankLevel> &vecData);
        void *  SetTelegraph(std::vector<DB_Telegraph> &vecData);

        //SV30 Insert
        void * SetRoute();
        void * SetRouteInfo();
        void * SetWaypoints();
        void * SetSchedules();
        void * SetFTS();
        void * SetMrnRecentVersion();


        //SV40 Insert
        void * SetEncUpdate();
        void * SetS57Cell();
        void * SetS101Cell();

        //SV51 Insert
        void * SetShipDensity();

        
    public:
        int Progress();
        void RestServiceRequest(E_RestServiceType eType, int iSerivce, void *strParam);
};