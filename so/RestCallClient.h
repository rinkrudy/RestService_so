#pragma once
#include<vector>
#include "./stdafx.h"

class RestCallClient
{
	private:
	std::vector<string> m_vecTypeName;
    EnaviBase * (RestCallClient::*m_arrInstanceGenerator[((int)Service::E_Service::eService_Max)])();

public :
	std::string m_strRestUrl;
	bool m_bSetUrl;
	//CString strUrl = _T("http://10.7.80.101:8080/sample/");
	std::string m_strUrl = "http://10.7.80.100:8080/sample/";
	std::string m_strFileServerUrl;
	std::string m_strFileServerUrl_volatility;
	std::string m_strFileServerUrl_Del;
	
	EnaviBase* m_pBase;

	RestCallClient();
	~RestCallClient();

	void Init(const char *pstrIniPath);
	void SetRestUrl(const char * pstrRestUrl);
	std::string GetDefaultResturl();

	void * SetDataStruct(int nServiceID, void * pParam);

	void * SetDataStruct(int nServiceID, void * pParam, int nMethod);
	void * SelectData(int nServiceID, const char * strParam);
	void * InsertData(int nServiceID, void * pParam);
	void * UpdateData(int nServiceID, void * pParam);
	void * DeleteData(int nServiceID, void * pParam);
	std::string  Upload_File(const char *pFilePath, bool isVolatility = false ,const char *pRequestFolder = nullptr);
	const char*  Delete_File(const char *pRequestUrl);
	

	void GetDataAsString(int nServiceID, const char *pParam, std::string *pstrReturn);

	size_t MemorySize(void * ptr);

	EnaviBase* GetInstance(int resource);

	void testFunc();


private:
	pplx::task<void>  Upload_FileStream(web::http::method inMethod, const char *pFilePath, const char *pRequestFolder, string *pFullUri, string *pAppend, bool isVolatility);
	template<typename T> EnaviBase * CreateInstance() {return new T();}


};

