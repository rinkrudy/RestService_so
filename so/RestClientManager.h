#include<vector>
#include<map>
#include<string>
#include"./stdafx.h"

class RestCallClient;
class EnaviBase;


class RestClientManager{

    struct ServiceRange
    {

        ServiceRange(int start, int end) : startIndex(start), endIndex(end)
        {
            
        }
        ServiceRange() : ServiceRange(0, 0)
        {
            
        }
        int startIndex;
        int endIndex;
    };
    
  private:
        RestClientManager();
        ~RestClientManager();

    private:
        static RestClientManager * m_pInstance;

    public:
        static void CreateInstance();
        static RestClientManager * GetInstance();
        static void DestoryInstance();
        void Init(const char * pstrfilePath);

        // Rest Interface
        void *Select(int nServiceID, const char *pstrParam);
        void *Select(int nServiceGroup, int nServiceID, const char *pstrParam);
        void *Insert(int nServiceID, void * strParam);
        void *Insert(int nServiceGroup, int nServiceID, void * pParam);
        void *Update(int nServiceID, void * strParam);
        void *Update(int nServiceGroup, int nServiceID, void * pParam);
        void *Delete(int nServiceID, void * strParam);
        void *Delete(int nServiceGroup, int nServiceID, void * pParam);


        void GetDataAsString(int nServiceID, const char *pstrParam, std::string *pstrResturn);
        void GetDataAsString(int nServiceGroup, int nServiceID, const char *pstrParam, std::string *pstrResturn);
        
        EnaviBase * GetServiceInstance(const char * pstrServiceName);
        EnaviBase * GetServiceInstance(int nServiceID);
        EnaviBase * GetServiceInstance(int nServiceGroup, int nServiceID);

        void InitServiceIDString();

    private:
        RestCallClient *m_pRestCallClient;
        std::vector<ServiceRange> m_vecServiceRange;
        std::vector<std::string> m_vecServiceName;
        std::map<string, Service::E_Service> m_mapServiceID;

    private:
        void Release();
        int GetServiceID(const char *pstrServiceName);
        int GetServiceID(int nServiceGroup, int nServiceID);
        
    public:
        RestCallClient * GetRestClient();
        

};