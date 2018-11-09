#include<iostream>
#include<dlfcn.h>
#include<cpprest/http_client.h>
#include <fstream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/uri.h>

#include"ProgressMNG.h"
#include<wchar.h>
#include<locale.h>
#include<bits/codecvt.h>
#include"ResultRenderer.h"
#include<thread>
#include"./so/ServiceStruct/EnaviDBService.h"
#include"./so/ServiceStruct/EnaviBase.h"

using namespace std;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

void *handle = nullptr;
void (*fnCreateRestService)(const char *);
void *(*fnSelectData)(int,const char *);
void *(*fnSelectDataByGroup)(int,int,const char *);
void *(*fnInsertData)(int, void *);
void *(*fnInsertDataByGroup)(int,int, void *);
void *(*fnUpdateData)(int, void *);
void *(*fnUpdateDataByGroup)(int, int, void *);
void *(*fnDeleteData)(int, void *);
void *(*fnDeleteDataByGroup)(int, int, void *);

void (*fnGetDataAsString)(int, const char *, std::string *);
void (*fnGetDataAsStringByGroup)(int, int, const char *, std::string *);
EnaviBase * (*fnGetInstanceByServiceName)(const char *);

void (*fnReleaseRestService)();
void (*fnSetRestUrl)(const char *);
string (*fnUploadfile)(const char *, bool, const char *);
const char * (*fnDeletefile)(const char *);




struct testStruct
{
    long nData;
    int nInt_1;
    int nInt_2;
    float fData;
    char c;
    char str[100];
    char str_1[100];
};


int main(int argc, char * argv[]){
    std::setlocale(LC_ALL, "");
    //test
    ResultRender *pRenderer = new ResultRender();
    pRenderer->Init();
    
    ProgressMNG::CreateInstance();
    ProgressMNG::GetInstance()->Init();

    handle = dlopen("/usr/lib/librestService.so", RTLD_NOW);
 
    if(!handle) {
        printf("error occur\n");
        return -1;
    }
    else
        printf("Success get handler\n");

    fnCreateRestService = (void (*)(const char *))dlsym(handle, "CreateRestService");
    fnSelectData = (void*(*)(int, const char*))dlsym(handle, "SelectData");
    fnReleaseRestService = (void(*)())dlsym(handle, "ReleaseRestService");
    fnInsertData = (void *(*)(int, void *))dlsym(handle, "InsertData");
    fnDeleteData = (void *(*)(int, void *))dlsym(handle, "DeleteData");
    fnUpdateData =(void *(*)(int, void *))dlsym(handle, "UpdateData");
    fnSetRestUrl = (void(*)(const char *))dlsym(handle, "SetRestUrl");
    fnUploadfile = (string (*)(const char *, bool, const char *))dlsym(handle, "UploadFile");
    fnDeletefile = (const char * (*)(const char *))dlsym(handle, "DeleteFile");
    fnSelectDataByGroup = (void*(*)(int, int, const char*))dlsym(handle, "SelectDataByGroup");
    fnInsertDataByGroup = (void *(*)(int,int, void *))dlsym(handle, "InsertDataByGroup");
    fnDeleteDataByGroup = (void *(*)(int,int, void *))dlsym(handle, "DeleteDataByGroup");
    fnUpdateDataByGroup =(void *(*)(int, int,void *))dlsym(handle, "UpdateDataByGroup");

    fnGetDataAsString = (void (*)(int, const char*, std::string *))dlsym(handle, "GetDataAsString");
    fnGetDataAsStringByGroup = (void (*)(int, int, const char*, std::string *))dlsym(handle, "GetDataAsStringByGroup");

    fnCreateRestService("./config.ini");

/*
    void * pData = fnSelectDataByGroup(4, 0, "category=EN&zone=A1&productversion=KR/2017-NTM-000&enctype=S-101&encrypt=false&same=false");
    pRenderer->Render_Result(pData, 30, 1);

    pData = fnSelectDataByGroup(2, 0, "serviceId=1&startUtcDateTime=20180901000000&endUtcDateTime=20180930235959");
    pRenderer->Render_Result(pData, 22, 1);

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

*/
    //void *pInsert = fnInsertDataByGroup(4, 0, (void *)p);
    //pRenderer->Render_Result(pInsert, 30, 2);
//
    //void *pDelete = fnDeleteDataByGroup(4, 0, (void *)p);
    //pRenderer->Render_Result(pDelete, 30, 4);
//
    //void *pUpdate = fnDeleteDataByGroup(4, 0, (void *)p);
    //pRenderer->Render_Result(pUpdate, 30, 3);
//
    //pDelete = fnDeleteDataByGroup(4, 0, (void *)p);
    //pRenderer->Render_Result(pDelete, 30, 4);

    //pData = fnSelectDataByGroup(7, 0, "serviceName=SV10&intefaceNameselect_attentionShip&startRegDate=20181001000000&endRegDate=20181231235959");
    //pRenderer->Render_Result(pData, 53, 1);

    //string tempStr = fnGetDataAsString(52, "coordinateGeoXY=127.87038 34.6007,127.93605 34.61893,127.98248 34.6575,128.03741 34.61004,128.00308 34.5863,128.03192 34.56256,127.95858 34.56418,127.91819 34.52508,127.87038 34.6007&startDateTime=2018-09-11T15:00:00.000&endDateTime=2018-09-13T15:00:00.000&catalog=WAVE_WIND_SPEED,WAVE_WIND_DIRECTION");

    //printf("Get String : %s\n", tempStr.c_str());


    /*


    testStruct s[2];
    s[0].fData = 1.0f;
    s[0].nData = 1;
    s[0].nInt_1 = 10;
    s[0].nInt_2 = 11;
    s[0].c = 'A';
    strcpy(s[0].str, "Hello");
    strcpy(s[0].str_1, "Hello Again!");

    s[1].fData = 2.0f;
    s[1].nData = 2;
    s[1].c = 'B';
    s[1].nInt_1 = 20;
    s[1].nInt_2 = 21;
    strcpy(s[1].str, "Bye");
    strcpy(s[1].str_1, "Bye Again!");


    testStruct * pOrigin = s; 
    void *pCurrent = (void *)pOrigin;

    long * pLong = (long *)pCurrent;
    printf("test memory move : %d\n", *pLong);
    int * pInt = (int *)(pLong + 1);
    printf("test memory move : %d\n", *pInt);
    pInt = (pInt + 1);
    printf("test memory move : %d\n", *pInt);
    float *fData = (float *)(pInt + 1);
    printf("test memory move : %f\n", *fData);
    char * pC = (char *)(fData + 1);
    printf("test memory move : %c\n", *pC);
    const char *pStr = (const char *)(pC + 1);
    printf("test str : %s\n", pStr);
    const char *pStr_1 = (const char *)(pStr + 100);
    printf("test str : %s\n", pStr_1);

    pOrigin = pOrigin + 1;

    pCurrent = (void *)pOrigin;

    long * pData_1 = (long *)pCurrent;
    printf("test memory move : %d\n", *pData_1);
    float *fData_1 = (float *)(pData_1 + 1);
    printf("test memory move : %f\n", *fData_1);
    char * pC_1 = (char *)(fData_1 + 1);
    printf("test memory move : %c\n", *pC_1);
    const char *_pStr = (const char *)(pC + 1);    
    printf("test str : %s\n", _pStr);
    const char *_pStr_1 = (const char *)(_pStr + 100);
    printf("test str : %s\n", _pStr_1);




    //printf("Result : %s\n", fnUploadfile("./config.ini", "TEST"));

    //printf("resutl : %s", fullUri.c_str());
    //std::this_thread::sleep_for(std::chrono::seconds(2));


    */




   // string fileUri;
   // fileUri = fnUploadfile("/home/rink/Desktop/RestService_so/config.ini", nullptr);
   // printf("Try Count : %d, Result : %s\n", 0, fileUri.c_str());



    printf("Result : %s\n", (fnUploadfile("./config.ini", true, "TEST")).c_str());

    //http://211.232.17.43:8080/enavi.java.prototype.file.distribute/delete/permanent/ 


    //string server = "http://211.232.17.43:8080/enavi.java.prototype.file.distribute/delete/permanent/";
	//http_client client(server.c_str());
    //uri_builder builder(U(""));
    //string qu = web::uri::encode_uri("09a649d0-2bcb-4ee8-9d5f-f0a4421d5b1d");
	//builder.append_path(qu);
    //http_response response = client.request(methods::GET, builder.to_string()).get();
//
    //printf("File Delete Result : %s\n", response.extract_string().get().c_str());

    //printf("fileDelete Result : %s\n", fnDeletefile("7fff440f-b98e-4fbb-83b0-9e0ab8b63a24"));
//
	//client.request(methods::DEL, )
//
	//response = client.request(methods::POST, "", param.c_str(), "application/json").get();

    //printf("resutl : %s", fullUri.c_str());


   // std::string *pStr = new std::string();
   // fnGetDataAsString(53,"type=point&", pStr);
   // printf("result : %s\n", pStr->c_str());
   // delete pStr;
   // pStr = nullptr;
    int nMode = 0;
    int nService = 0;
    void *pResult = nullptr;
    void *getFeature = nullptr;
    //int test = 1;
    

   // do{
   //     std::cin >> test;
   //     
   //     tempstr.assign(fnGetDataAsString(53,"type=point&coordinateGeoXY=127.87038 34.6007,127.93605 34.61893,127.98248 34.6575,128.03741 34.61004,128.00308 34.5863,128.03192 34.56256,127.95858 34.56418,127.91819 34.52508,127.87038 34.6007&startDateTime=2018-09-11T15:00:00.000&endDateTime=2018-09-13T15:00:00.000&catalog=WAVE_WIND_SPEED,WAVE_WIND_DIRECTION"));
   //     printf("Result : %s\n", returnStr.c_str());
//
   // }while(test);
//
//
     do
     {
         nMode = ProgressMNG::GetInstance()->Progress();

         string str;

         if(nMode == 0)
         {
             continue;
         }

         switch(nMode)
         {
             case 1:
                 nService = ProgressMNG::GetInstance()->restCall_Select(&str);
                 pResult = fnSelectData(nService, str.c_str());
                 break;
             case 2:
                 nService = ProgressMNG::GetInstance()->restCall_Insert(&pResult);
                 pResult = fnInsertData(nService, pResult);
                 break;
             case 3:
                 nService = ProgressMNG::GetInstance()->restCall_Insert(&pResult);
                 pResult = fnUpdateData(nService, pResult);
                 break;
             case 4:
                 nService = ProgressMNG::GetInstance()->restCall_Insert(&pResult);
                 pResult = fnDeleteData(nService, pResult);
                 break;
         }

         if(pResult)
             pRenderer->Render_Result(pResult, nService, nMode);
         else
             printf("result is empty\n");


     }while(nMode);
      fnReleaseRestService();

    return 0;
}