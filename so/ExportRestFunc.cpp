#include"RestCallClient.h"
#include"RestClientManager.h"
#include <string>

extern "C" void CreateRestService(const char *pFilepath){
    RestClientManager::GetInstance()->Init(pFilepath);
}

extern "C" void* SelectData(int nServiceID, const char * pStrParam){
    return RestClientManager::GetInstance()->Select(nServiceID, pStrParam);
}
extern "C" void *SelectDataByGroup(int nServiceGroup, int nServiceID, const char *pStrParam)
{
    return RestClientManager::GetInstance()->Select(nServiceGroup, nServiceID, pStrParam);
}
extern "C" void * InsertData(int nServiceID, void * pstrParam){
    return RestClientManager::GetInstance()->Insert(nServiceID, pstrParam);
}
extern "C" void * InsertDataByGroup(int nServiceGroup, int nServiceID, void * pstrParam){
    return RestClientManager::GetInstance()->Insert(nServiceGroup, nServiceID, pstrParam);
}
extern "C" void *UpdateData(int nServiceID, void *pstrParam){
    return RestClientManager::GetInstance()->Update(nServiceID, pstrParam);
}
extern "C" void *UpdateDataByGroup(int nServiceGroup, int nServiceID, void *pstrParam){
    return RestClientManager::GetInstance()->Update(nServiceGroup, nServiceID, pstrParam);
}
extern "C" void *DeleteData(int nServiceID, void *pstrParam){
    return RestClientManager::GetInstance()->Delete(nServiceID, pstrParam);
}
extern "C" void *DeleteDataByGroup(int nServiceGroup, int nServiceID, void *pstrParam){
    return RestClientManager::GetInstance()->Delete(nServiceGroup, nServiceID, pstrParam);
}

extern "C" void GetDataAsString(int nServiceID, const char *pstrParam, string *pstrReturn)
{
    RestClientManager::GetInstance()->GetDataAsString(nServiceID, pstrParam, pstrReturn);
}
extern "C" void GetDataAsStringByGroup(int nServiceGroup, int nServiceID, const char *pstrParam, string *pstrReturn)
{
    RestClientManager::GetInstance()->GetDataAsString(nServiceGroup, nServiceID, pstrParam, pstrReturn);
}



extern "C" void ReleaseRestService(){
    return RestClientManager::DestoryInstance();
}

extern "C" void SetRestUrl(const char * restUrl)
{
    RestClientManager::GetInstance()->GetRestClient()->SetRestUrl(restUrl);
}

extern "C" string UploadFile(const char *path, bool isVolatility = false, const char *targetMrn = nullptr)
{
    return RestClientManager::GetInstance()->GetRestClient()->Upload_File(path, isVolatility, targetMrn);
}
extern "C" const char * DeleteFile(const char *uri)
{
    return RestClientManager::GetInstance()->GetRestClient()->Delete_File(uri);
}
