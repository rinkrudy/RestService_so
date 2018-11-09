#include"RestClientManager.h"
#include"RestCallClient.h"
#include"stdafx.h"


RestClientManager * RestClientManager::m_pInstance = nullptr;
RestClientManager::~RestClientManager(){
    m_vecServiceName.clear();
    m_vecServiceRange.clear();
    m_mapServiceID.clear();
}
RestClientManager::RestClientManager():m_pRestCallClient(nullptr)
{
    m_vecServiceName.clear();
    m_vecServiceRange.clear();
    m_mapServiceID.clear();
}

void RestClientManager::CreateInstance(){
    if(!m_pInstance)
    {
        m_pInstance = new RestClientManager();
    }
    return;
 }
 RestClientManager * RestClientManager::GetInstance(){
     if(!m_pInstance){
         CreateInstance();
     }
     return m_pInstance;
 }
void RestClientManager::DestoryInstance(){
    if(m_pInstance){
        m_pInstance->Release();
        delete m_pInstance;
        m_pInstance = nullptr;
    }

    return;
}
void RestClientManager::Init(const char *pstrFilePath){
        m_pInstance->m_pRestCallClient = new RestCallClient();
        m_pInstance->m_pRestCallClient->Init(pstrFilePath);
        m_vecServiceRange.resize((int)Service::E_Group::Max);


        m_vecServiceRange.at(Service::E_Group::eSV10).startIndex = (int)(Service::E_Service::eAbnormalPattern);
        m_vecServiceRange.at(Service::E_Group::eSV10).endIndex = (int)(Service::E_Service::eVulInput07);
        m_vecServiceRange.at(Service::E_Group::eSV20).startIndex = (int)(Service::E_Service::eShipStaticInfo);
        m_vecServiceRange.at(Service::E_Group::eSV20).endIndex = (int)(Service::E_Service::eShipStaticInfo);
        m_vecServiceRange.at(Service::E_Group::eSV30).startIndex = (int)(Service::E_Service::ePastNavInfo);
        m_vecServiceRange.at(Service::E_Group::eSV30).endIndex = (int)(Service::E_Service::eFTS);
        m_vecServiceRange.at(Service::E_Group::eSV40).startIndex = (int)(Service::E_Service::eCatalogue);
        m_vecServiceRange.at(Service::E_Group::eSV40).endIndex = (int)(Service::E_Service::eMrnRecentVersion);
        m_vecServiceRange.at(Service::E_Group::eSV51).startIndex = (int)(Service::E_Service::eGuideLine);
        m_vecServiceRange.at(Service::E_Group::eSV51).endIndex = (int)(Service::E_Service::eShipPosition);
        m_vecServiceRange.at(Service::E_Group::eSV52).startIndex = (int)(Service::E_Service::eArgoMet);
        m_vecServiceRange.at(Service::E_Group::eSV52).endIndex = (int)(Service::E_Service::eFeaturesForWaterway);
        m_vecServiceRange.at(Service::E_Group::eCommon).startIndex = (int)(Service::E_Service::eServiceLog);
        m_vecServiceRange.at(Service::E_Group::eCommon).endIndex = (int)(Service::E_Service::eServiceLog);
        m_vecServiceRange.at(Service::E_Group::None).startIndex = (int)(Service::E_Service::eVesselStaticinfo);
        m_vecServiceRange.at(Service::E_Group::None).endIndex = (int)(Service::E_Service::eEncSelector);
}


void RestClientManager::Release(){
    delete m_pRestCallClient;
    m_pRestCallClient = nullptr;
}


RestCallClient * RestClientManager::GetRestClient(){
    return m_pRestCallClient ? m_pRestCallClient : (m_pRestCallClient = new RestCallClient());
}

int RestClientManager::GetServiceID(const char *pstrServiceID)
{
    if(m_mapServiceID.empty())
        InitServiceIDString();
    
    int nIndex = (int)((m_mapServiceID.find(pstrServiceID))->second);

    return nIndex;
}

int RestClientManager::GetServiceID(int nServiceGroup, int nServiceID)
{
    if(nServiceID > m_vecServiceRange[nServiceGroup].endIndex)
    {
        printf("There is not Serivce\n");
        return -1;
    }

    int _serviceID = m_vecServiceRange[nServiceGroup].startIndex + nServiceID;

    return _serviceID;

}




void *RestClientManager::Select(int nServiceID, const char *strParam)
{
    return m_pRestCallClient->SelectData(nServiceID, strParam);
}
void *RestClientManager::Select(int nServiceGroup, int nServiceID, const char *strParam)
{       
    return m_pRestCallClient->SelectData(GetServiceID(nServiceGroup, nServiceID), strParam);    
}
void *RestClientManager::Insert(int nServiceID, void * strParam)
{
    return m_pRestCallClient->InsertData(nServiceID, strParam);
}
void *RestClientManager::Insert(int nServiceGroup, int nServiceID, void * strParam)
{
    return m_pRestCallClient->InsertData(GetServiceID(nServiceGroup, nServiceID), strParam);
}
void *RestClientManager::Update(int nServiceID, void * strParam)
{
    return m_pRestCallClient->UpdateData(nServiceID, strParam);
}
void *RestClientManager::Update(int nServiceGroup, int nServiceID, void * strParam)
{
    return m_pRestCallClient->UpdateData(GetServiceID(nServiceGroup, nServiceID), strParam);

}
void *RestClientManager::Delete(int nServiceID, void * strParam)
{
    return m_pRestCallClient->DeleteData(nServiceID, strParam);
}
void *RestClientManager::Delete(int nServiceGroup, int nServiceID, void * strParam)
{
    return m_pRestCallClient->DeleteData(GetServiceID(nServiceGroup, nServiceID), strParam);
}
void RestClientManager::GetDataAsString(int nServiceID, const char *pstrParam, std::string *pstrReturn)
{
    m_pRestCallClient->GetDataAsString(nServiceID, pstrParam, pstrReturn);
}
void RestClientManager::GetDataAsString(int nServiceGroup, int nServiceID, const char *pstrParam, std::string *pstrReturn)
{
    m_pRestCallClient->GetDataAsString(GetServiceID(nServiceGroup, nServiceID), pstrParam, pstrReturn);
}

EnaviBase * RestClientManager::GetServiceInstance(const char * pstrServiceName)
{
    EnaviBase *pNaviBase = m_pRestCallClient->GetInstance(GetServiceID(pstrServiceName));
    pNaviBase->Init();
    return pNaviBase;
}
EnaviBase * RestClientManager::GetServiceInstance(int nServiceID)
{
    EnaviBase *pNaviBase =  m_pRestCallClient->GetInstance(nServiceID);
    pNaviBase->Init();
    return pNaviBase;
}
EnaviBase * RestClientManager::GetServiceInstance(int nServiceGroup, int nServiceID)
{
    EnaviBase *pNaviBase =  m_pRestCallClient->GetInstance(GetServiceID(nServiceGroup, nServiceID));
    pNaviBase->Init();
    return pNaviBase;
}

void RestClientManager::InitServiceIDString()
{
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AbnormalPattern", Service::E_Service::eAbnormalPattern));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AccidentPrediction", Service::E_Service::eAccidentPrediction));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AccidentRisk", Service::E_Service::eAccidentRisk));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AreaDetail", Service::E_Service::eAreaDetail));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AreaMst", Service::E_Service::eAreaMst));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AreaSelect", Service::E_Service::eAreaSelect));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AttentionShip", Service::E_Service::eAttentionShip));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("AvsResponse", Service::E_Service::eAvsResponse));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("DangerShipAlarm", Service::E_Service::eDangerShipAlarm));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("FishingHistoryArea", Service::E_Service::eFishingHistoryArea));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("FishingPatternArea", Service::E_Service::eFishingPatternArea));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("RssResponse", Service::E_Service::eRssResponse));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("SpecThreshold", Service::E_Service::eSpecThreshold));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput00_1", Service::E_Service::eVulInput00_1));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput00_2", Service::E_Service::eVulInput00_2));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput01", Service::E_Service::eVulInput01));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput02", Service::E_Service::eVulInput02));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput03", Service::E_Service::eVulInput03));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput04", Service::E_Service::eVulInput04));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput05", Service::E_Service::eVulInput05));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput06", Service::E_Service::eVulInput06));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VulInput07", Service::E_Service::eVulInput07));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ShipStaticInfo", Service::E_Service::eShipStaticInfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("PastNavInfo", Service::E_Service::ePastNavInfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("PastNavVesselInfo", Service::E_Service::ePastNavVesselInfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("Route", Service::E_Service::eRoute));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("RouteInfo", Service::E_Service::eRouteInfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("Waypoints", Service::E_Service::eWaypoints));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("Schedules", Service::E_Service::eSchedules));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("FTS", Service::E_Service::eFTS));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("Catalogue", Service::E_Service::eCatalogue));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("CatalogueAll", Service::E_Service::eCatalogueAll));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("EncUpdate", Service::E_Service::eEncUpdate));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("S57Cell", Service::E_Service::eS57Cell));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("S101Cell", Service::E_Service::eS101Cell));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("Zone", Service::E_Service::eZone));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ZoneAll", Service::E_Service::eZoneAll));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLine", Service::E_Service::eGuideLine));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineAnchorage", Service::E_Service::eGuideLineAnchorage));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineCourse", Service::E_Service::eGuideLineCourse));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineFairway", Service::E_Service::eGuideLineFairway));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineInfo", Service::E_Service::eGuideLineInfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLinePilot", Service::E_Service::eGuideLinePilot));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLinePoint", Service::E_Service::eGuideLinePoint));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineSafetySpeed", Service::E_Service::eGuideLineSafetySpeed));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineSafetyStan", Service::E_Service::eGuideLineSafetyStan));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineSpeed", Service::E_Service::eGuideLineSpeed));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineTug", Service::E_Service::eGuideLineTug));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineVTS", Service::E_Service::eGuideLineVTS));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("GuideLineWharf", Service::E_Service::eGuideLineWharf));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ShipPosition", Service::E_Service::eShipPosition));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ShipDensity", Service::E_Service::eShipDensity));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("VesselStaticinfo", Service::E_Service::eVesselStaticinfo));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ArgoMet", Service::E_Service::eArgoMet));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("ServiceLog", Service::E_Service::eServiceLog));
    m_mapServiceID.insert(std::make_pair<string, Service::E_Service>("EncSelector", Service::E_Service::eEncSelector));
        

}