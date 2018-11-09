#include "./RestCallClient.h"
#include <algorithm>
#include <fstream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/uri.h>
#include <thread>
#include <iostream>
#include <stdio.h>

//sv10 header
#include "./ServiceStruct/sv10/abnormalPattern.h"
#include "./ServiceStruct/sv10/AccidentRisk.h"
#include "./ServiceStruct/sv10/AccidentPrediction.h"
#include "./ServiceStruct/sv10/areaDetail.h"
#include "./ServiceStruct/sv10/areaMst.h"
#include "./ServiceStruct/sv10/areaSelect.h"
#include "./ServiceStruct/sv10/AttentionShip.h"
#include "./ServiceStruct/sv10/avsResponse.h"
#include "./ServiceStruct/sv10/DangerShipAlarm.h"
#include "./ServiceStruct/sv10/fishingHistoryArea.h"
#include "./ServiceStruct/sv10/fishingPatternArea.h"
#include "./ServiceStruct/sv10/rssResponse.h"
#include "./ServiceStruct/sv10/SpecThreshold.h"
#include "./ServiceStruct/sv10/vulInput00_1.h"
#include "./ServiceStruct/sv10/vulInput00_2.h"
#include "./ServiceStruct/sv10/vulInput01.h"
#include "./ServiceStruct/sv10/vulInput02.h"
#include "./ServiceStruct/sv10/vulInput03.h"
#include "./ServiceStruct/sv10/vulInput04.h"
#include "./ServiceStruct/sv10/vulInput05.h"
#include "./ServiceStruct/sv10/vulInput06.h"
#include "./ServiceStruct/sv10/vulInput07.h"
#include "./ServiceStruct/sv30/FTS.h"
#include "./ServiceStruct/sv30/PastNavInfo.h"
#include "./ServiceStruct/sv30/Route.h"
#include "./ServiceStruct/sv30/RouteInfo.h"
#include "./ServiceStruct/sv30/Waypoints.h"
#include "./ServiceStruct/sv30/Schedules.h"


//sv40 header
#include "./ServiceStruct/sv40/Catalogue.h"
#include "./ServiceStruct/sv40/CatalogueAll.h"
#include "./ServiceStruct/sv40/Zone.h"
#include "./ServiceStruct/sv40/ZoneAll.h"
#include "./ServiceStruct/sv40/EncUpdate.h"
#include "./ServiceStruct/sv40/S57Cell.h"
#include "./ServiceStruct/sv40/S101Cell.h"
#include "./ServiceStruct/sv40/MrnRecentVersion.h"

//sv 51 header

#include "./ServiceStruct/sv51/GuideLine.h"
#include "./ServiceStruct/sv51/ShipPosition.h"
#include "./ServiceStruct/sv51/GuideLineAnchorage.h"
#include "./ServiceStruct/sv51/GuideLineCourse.h"
#include "./ServiceStruct/sv51/GuideLineFairway.h"
#include "./ServiceStruct/sv51/GuideLineInfo.h"
#include "./ServiceStruct/sv51/GuideLinePilot.h"
#include "./ServiceStruct/sv51/GuideLinePoint.h"
#include "./ServiceStruct/sv51/GuideLineSafetySpeed.h"
#include "./ServiceStruct/sv51/GuideLineSafetyStan.h"
#include "./ServiceStruct/sv51/GuideLineSpeed.h"
#include "./ServiceStruct/sv51/GuideLineTug.h"
#include "./ServiceStruct/sv51/GuideLineVTS.h"
#include "./ServiceStruct/sv51/GuideLineWharf.h"
#include "./ServiceStruct/sv51/ShipDensity.h"


#include "./ServiceStruct/VesselStaticInfo.h"
#include "./ServiceStruct/EncSelector.h"

//sv20
#include "./ServiceStruct/sv20/ShipStaticInfo.h"

//sv52
#include "./ServiceStruct/sv52/ArgoMet.h"
#include "./ServiceStruct/sv52/FeaturesForWaterway.h"

//commone
#include "./ServiceStruct/common/ServiceLog.h"

//none
#include "./ServiceStruct/sv30/PastNavVesselInfo.h"

#include "./ServiceStruct/EnaviDBService.h"







using namespace Service;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

RestCallClient::RestCallClient() : m_bSetUrl(false), m_pBase(nullptr)
{
	
}

RestCallClient::~RestCallClient()
{
}

void RestCallClient::Init(const char *pstrFilePath)
{
	m_arrInstanceGenerator[(int)Service::E_Service::eVesselStaticinfo] = &RestCallClient::CreateInstance<VesselStaticInfo>;
	m_arrInstanceGenerator[(int)Service::E_Service::eEncSelector] = &RestCallClient::CreateInstance<EncSelector>;
	//SV10
	m_arrInstanceGenerator[(int)Service::E_Service::eAbnormalPattern] = &RestCallClient::CreateInstance<abnormalPattern>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAccidentPrediction] = &RestCallClient::CreateInstance<AccidentPrediction>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAccidentRisk] = &RestCallClient::CreateInstance<AccidentRisk>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAreaDetail] = &RestCallClient::CreateInstance<areaDetail>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAreaMst] = &RestCallClient::CreateInstance<areaMst>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAreaSelect] = &RestCallClient::CreateInstance<areaSelect>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAttentionShip] = &RestCallClient::CreateInstance<AttentionShip>;
	m_arrInstanceGenerator[(int)Service::E_Service::eAvsResponse] = &RestCallClient::CreateInstance<avsResponse>;
	m_arrInstanceGenerator[(int)Service::E_Service::eDangerShipAlarm] = &RestCallClient::CreateInstance<DangerShipAlarm>;
	m_arrInstanceGenerator[(int)Service::E_Service::eFishingHistoryArea] = &RestCallClient::CreateInstance<fishingHistoryArea>;
	m_arrInstanceGenerator[(int)Service::E_Service::eFishingPatternArea] = &RestCallClient::CreateInstance<fishingPatternArea>;
	m_arrInstanceGenerator[(int)Service::E_Service::eRssResponse] = &RestCallClient::CreateInstance<rssResponse>;
	m_arrInstanceGenerator[(int)Service::E_Service::eSpecThreshold] = &RestCallClient::CreateInstance<SpecThreshold>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput00_1] = &RestCallClient::CreateInstance<vulInput00_1>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput00_2] = &RestCallClient::CreateInstance<vulInput00_2>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput01] = &RestCallClient::CreateInstance<vulInput01>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput02] = &RestCallClient::CreateInstance<vulInput02>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput03] = &RestCallClient::CreateInstance<vulInput03>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput04] = &RestCallClient::CreateInstance<vulInput04>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput05] = &RestCallClient::CreateInstance<vulInput05>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput06] = &RestCallClient::CreateInstance<vulInput06>;
	m_arrInstanceGenerator[(int)Service::E_Service::eVulInput07] = &RestCallClient::CreateInstance<vulInput07>;
	//SV20
	m_arrInstanceGenerator[(int)Service::E_Service::eShipStaticInfo] = &RestCallClient::CreateInstance<ShipStaticInfo>;
	//SV30
	m_arrInstanceGenerator[(int)Service::E_Service::eFTS] = &RestCallClient::CreateInstance<FTS>;
	m_arrInstanceGenerator[(int)Service::E_Service::ePastNavInfo] = &RestCallClient::CreateInstance<PastNavInfo>;
	m_arrInstanceGenerator[(int)Service::E_Service::ePastNavVesselInfo] = &RestCallClient::CreateInstance<PastNavVesselInfo>;
	m_arrInstanceGenerator[(int)Service::E_Service::eRoute] = &RestCallClient::CreateInstance<Route>;
	m_arrInstanceGenerator[(int)Service::E_Service::eRouteInfo] = &RestCallClient::CreateInstance<RouteInfo>;
	m_arrInstanceGenerator[(int)Service::E_Service::eSchedules] = &RestCallClient::CreateInstance<Schedules>;
	m_arrInstanceGenerator[(int)Service::E_Service::eWaypoints] = &RestCallClient::CreateInstance<Waypoints>;
	//SV40
	m_arrInstanceGenerator[(int)Service::E_Service::eCatalogue] = &RestCallClient::CreateInstance<Catalogue>;
	m_arrInstanceGenerator[(int)Service::E_Service::eCatalogueAll] = &RestCallClient::CreateInstance<CatalogueAll>;
	m_arrInstanceGenerator[(int)Service::E_Service::eEncUpdate] = &RestCallClient::CreateInstance<EncUpdate>;
	m_arrInstanceGenerator[(int)Service::E_Service::eS57Cell] = &RestCallClient::CreateInstance<S57Cell>;
	m_arrInstanceGenerator[(int)Service::E_Service::eS101Cell] = &RestCallClient::CreateInstance<S101Cell>;
	m_arrInstanceGenerator[(int)Service::E_Service::eZone] = &RestCallClient::CreateInstance<Zone>;
	m_arrInstanceGenerator[(int)Service::E_Service::eZoneAll] = &RestCallClient::CreateInstance<ZoneAll>;
	m_arrInstanceGenerator[(int)Service::E_Service::eMrnRecentVersion] = &RestCallClient::CreateInstance<MrnRecentVersion>;
	//SV51 
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLine] = &RestCallClient::CreateInstance<GuideLine>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineAnchorage] = &RestCallClient::CreateInstance<GuideLineAnchorage>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineCourse] = &RestCallClient::CreateInstance<GuideLineCourse>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineFairway] = &RestCallClient::CreateInstance<GuideLineFairway>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineInfo] = &RestCallClient::CreateInstance<GuideLineInfo>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLinePilot] = &RestCallClient::CreateInstance<GuideLinePilot>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLinePoint] = &RestCallClient::CreateInstance<GuideLinePoint>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineSafetySpeed] = &RestCallClient::CreateInstance<GuideLineSafetySpeed>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineSafetyStan] = &RestCallClient::CreateInstance<GuideLineSafetyStan>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineSpeed] = &RestCallClient::CreateInstance<GuideLineSpeed>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineTug] = &RestCallClient::CreateInstance<GuideLineTug>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineVTS] = &RestCallClient::CreateInstance<GuideLineVTS>;
	m_arrInstanceGenerator[(int)Service::E_Service::eGuideLineWharf] = &RestCallClient::CreateInstance<GuideLineWharf>;
	m_arrInstanceGenerator[(int)Service::E_Service::eShipPosition] = &RestCallClient::CreateInstance<ShipPosition>;
	m_arrInstanceGenerator[(int)Service::E_Service::eShipDensity] = &RestCallClient::CreateInstance<ShipDensity>;

	//SV52
	m_arrInstanceGenerator[(int)Service::E_Service::eArgoMet] = &RestCallClient::CreateInstance<ArgoMet>;
	m_arrInstanceGenerator[(int)Service::E_Service::eFeaturesForWaterway] = &RestCallClient::CreateInstance<FeaturesForWaterway>;
	//Common
	m_arrInstanceGenerator[(int)Service::E_Service::eServiceLog] = &RestCallClient::CreateInstance<ServiceLog>;


	m_strFileServerUrl.assign(m_strUrl.c_str());
	m_strFileServerUrl_Del.assign(m_strFileServerUrl.c_str());


	if(pstrFilePath)
	{
		std::fstream fin(pstrFilePath);
		std::string ignore;
		std::string ipAddress;
		std::string fileServerAddress;

		if(fin)
		{
			fin >> ignore;
			fin >> ignore >> ipAddress;
			if(ipAddress.compare("[fileServerAddress]") == 0 || ipAddress.compare("None") == 0)
			{
			
			}
			else
			{
				SetRestUrl(ipAddress.c_str());
				fin >> ignore;
				fin >> ignore >> fileServerAddress;
				if(fileServerAddress.compare("None") == 0 || fileServerAddress.empty())
				{
					
				}
				else
				{
					m_strFileServerUrl.assign(fileServerAddress.c_str());
					m_strFileServerUrl_Del.assign(fileServerAddress.c_str());
					m_strFileServerUrl_volatility.assign(fileServerAddress.c_str());
				}
			}

		}

		m_strFileServerUrl.append("/enavi.java.prototype.file.distribute/upload/permanent/");
		m_strFileServerUrl_volatility.append("/enavi.java.prototype.file.distribute/upload/");
		m_strFileServerUrl_Del.append("/enavi.java.prototype.file.distribute/delete/permanent/");


		printf("IpAddress is %s\n", m_strRestUrl.c_str());
		printf("FileUploadServer is %s\n", m_strFileServerUrl.c_str());
	}
}

void RestCallClient::SetRestUrl(const char *pstrRestUrl)
{
	m_strRestUrl.assign(pstrRestUrl);
	m_strRestUrl.append("/sample/");
	printf("Url Set : %s\n", m_strRestUrl.c_str());
	m_bSetUrl = true;
}

string RestCallClient::GetDefaultResturl()
{
	if (m_bSetUrl == false)
	{
		m_strRestUrl.assign(m_strUrl);
	}
	return m_strRestUrl;
}




void *RestCallClient::SelectData(int nServiceID, const char *pstrParam)
{
	if(nServiceID == -1 || nServiceID == Service::E_Service::eFeaturesForWaterway || nServiceID == Service::E_Service::eArgoMet)
		return nullptr;
	string param;
	EnaviBase *pBase = nullptr;
	pBase = GetInstance(nServiceID);
	if(pBase == nullptr)
	{
		printf("The Service does not exist\n");
		return nullptr;
	}
		
	E_RestType type = E_RestType::eSelect;
	http_response response;
	string url = GetDefaultResturl();

	string nullStr(pstrParam);
	try
	{

		if (nullStr == "")
		{
			param = web::uri::encode_uri("");
		}
		else
		{
			param = web::uri::encode_uri(pstrParam);
		}
			//param = web::uri::encode_uri(strParam);




		string service = pBase->GetSerivceUrl(type);
		url.append(service);
		printf("Rquest Url : %s\n", url.c_str());
		http_client client(url.c_str());

		uri_builder builder(U(""));
		builder.append_query(param);

		printf("Request param : %s\n", param.c_str());

		response = client.request(methods::GET, builder.to_string()).get();
	}
	catch (const web::http::http_exception &e)
	{
		printf(" ,[What] : %s", e.error_code().message().c_str());
		return nullptr;
	}

	printf("server is running at %s \n", url.c_str());


	json::value root = response.extract_json(true).get();

	bool isArray = root.at(U("data")).is_array();

	void *result = nullptr;

	try
	{
		if (isArray == true)
		{
			auto array = root.at(U("data")).as_array();
			int iArrayCount = array.size();
			result = pBase->GetStruct(&root);
			if(iArrayCount == 0)
			{
				printf("DataArray is empty\n");
			}

		}
		else
		{
			//result = pBase->SetStructInfo(&root);
		}
	}
	catch (const std::exception &e)
	{
		printf("Error exception: %s\n", e.what());
		return nullptr;
	}

	delete pBase;
	pBase = nullptr;

	return result;
}


void *RestCallClient::InsertData(int nServiceID, void *pstrParam)
{
	return SetDataStruct(nServiceID, pstrParam, 1);
}

void *RestCallClient::UpdateData(int nServiceID, void *pstrParam)
{
	return SetDataStruct(nServiceID, pstrParam, 2);
}

void *RestCallClient::DeleteData(int nServiceID, void *pstrParam)
{
	return SetDataStruct(nServiceID, pstrParam, 3);
}

//***************************************************************************
size_t RestCallClient::MemorySize(void *ptr)
{
	return malloc_usable_size(ptr);
}

void *RestCallClient::SetDataStruct(int nServiceID, void *pstrParam, int method)
{
	if(nServiceID == -1)
		return nullptr;
	std::string url = GetDefaultResturl();
	printf("Rquest Url : %s\n", url.c_str());

	http_response response;
	methods requestMethod;
	EnaviBase *pBase = GetInstance(nServiceID);

	if(pBase == nullptr)
	{
		printf("The Service does not exist\n");
		return nullptr;
	}	
	std::string service;
	try
	{
		switch (method)
		{
		case 1:
			service = pBase->GetSerivceUrl(E_RestType::eInsert);
			break;
		case 2:
			service = pBase->GetSerivceUrl(E_RestType::eUpdate);
			break;
		case 3:
			service = pBase->GetSerivceUrl(E_RestType::eDelete);
			break;
		}
		url.append(service);

		http_client client(url.c_str());

		string param;
		if(pstrParam != nullptr)
			param = pBase->SetStructToJson(pstrParam);
		else
			param = " ";

		printf("Send Request : %s\n", param.c_str());

		if (method == 1)
			response = client.request(methods::POST, "", param.c_str(), "application/json").get();
		else if (method == 2)
			response = client.request(methods::PUT, "", param.c_str(), "application/json").get();
		else if (method == 3)
			response = client.request(methods::DEL, "", param.c_str(), "application/json").get();
	}
	catch (const std::exception &e)
	{
		printf("Error exception: %s\n", e.what());
		return nullptr;
	}

	json::value root = response.extract_json(true).get(); 
	void *result = nullptr;
	try
	{
		result = pBase->SetStructInfo(&root);
	}
	catch (const exception &e){
		printf("Error exception: %s\n", e.what());
		return nullptr;
	}

	delete pBase;
	pBase = nullptr;
	return result;
}
const char*  RestCallClient::Delete_File(const char *pRequestUrl)
{
	http_client client(m_strFileServerUrl_Del.c_str());
	std::string strRequest(pRequestUrl);
	std::string qu;
	if(strRequest.find(m_strFileServerUrl_Del) > -1)
	{
		qu =  web::uri::encode_uri(strRequest.substr(m_strFileServerUrl.length()).c_str());
	}
	else
	{
		qu = web::uri::encode_uri(pRequestUrl);
	}

    uri_builder builder(U(""));
    
	builder.append_path(qu);
    http_response response = client.request(methods::GET, builder.to_string()).get();

	printf("File Delete uri request : %s\n", builder.to_string().c_str());
    printf("File Delete Result : %s\n", response.extract_string().get().c_str());

	return response.extract_string().get().c_str();

}



std::string RestCallClient::Upload_File(const char *pstrFilePath, bool isVolatility, const char *pstrRequestFolder)
{
	std::string fullUri;
	std::string appendstr;
	try
	{
		this->Upload_FileStream(web::http::methods::POST, pstrFilePath, pstrRequestFolder, &fullUri, &appendstr, isVolatility).wait();	}
	catch(web::http::http_exception &e)
	{
		printf(" ,[What] : %s", e.what());

	}
	
	if(fullUri.empty() == false)
	{
		if(appendstr.empty() == false)
		{
			fullUri.append(appendstr.c_str());
		}
	}
		

	return fullUri;
}




pplx::task<void> RestCallClient::Upload_FileStream(web::http::method inMethod,  const char *pstrFilePath, const char * pstrRequestFolder, string *pFullUri, string *pAppend, bool isVolatility)
{

	using concurrency::streams::file_stream;
	using concurrency::streams::basic_istream;

	string filename;
	filename.assign(pstrFilePath);
	size_t location =  filename.rfind("/");
    string sub = filename.substr(location + 1, filename.length() - (location + 1));
	string url;
	if(isVolatility)
		url.assign(m_strFileServerUrl_volatility.c_str());
	else
		url.assign(m_strFileServerUrl.c_str());
	if(pstrRequestFolder)
		url.append(pstrRequestFolder);
	else
		url.append("default");

	printf("request file upload, file : %s\n", pstrFilePath);


	return file_stream<unsigned char>::open_istream(pstrFilePath).then([inMethod, url, pFullUri, sub, pAppend](basic_istream<unsigned char>	 fileStream)
		{

			try{
				http_client client(url.c_str());
				
				return client.request(inMethod, sub.c_str(), fileStream).then([fileStream, pFullUri, pAppend](pplx::task<http_response> preResponse)
				{
					fileStream.close();
					printf("response get\n");


					try{
						auto response = preResponse.get();
						printf("file upload result : %s\n", response.to_string().c_str());


						json::value root = response.extract_json(true).get();

						if(root.at(U("fullUri")).as_string().c_str() == "" || root.at(U("fullUri")).as_string().empty())
							throw "Empty uri returned";
						printf("return Uri : %s\n", root.at(U("fullUri")).as_string().c_str());
						int blank = (int)root.at(U("fullUri")).as_string().rfind(" ");
						int length = root.at(U("fullUri")).as_string().length();
						if(blank == length -1)
						{
							blank = (int)root.at(U("fullUri")).as_string().substr(0, blank -1).rfind(" ");
							if(blank == -1)
							{
								pFullUri->assign(root.at(U("fullUri")).as_string().c_str());
							}
							else
							{
 								pFullUri->assign(root.at(U("fullUri")).as_string().substr(0, blank + 1).c_str());
								pAppend->assign(root.at(U("fullUri")).as_string().substr(blank + 1, length -1).c_str());
							}
								
						}
						else
						{

							if(blank == -1)
							{
								pFullUri->assign(root.at(U("fullUri")).as_string().c_str());
							}
							else
							{
 								pFullUri->assign(root.at(U("fullUri")).as_string().substr(0, blank + 1).c_str());
								pAppend->assign(root.at(U("fullUri")).as_string().substr(blank + 1, length -1).c_str());
							}

						}

					}
					catch(const char *str)
					{
						printf("file upload exception : %s\n", str);
					}
					catch(web::http::http_exception &e)
					{
						//std::cout << "file upload error " << "[Code] : " << e.error_code().message << " ,[What] : " << e.what() << std::endl;
						printf(" ,[What] : %s", e.error_code().message().c_str());
						
					}
					
				});
			}
			catch(web::http::http_exception &e)
			{
				printf(" ,[What] : %s", e.what());
			}
		});
	
}

EnaviBase *RestCallClient::GetInstance(int nServiceID)
{
	EnaviBase *base = nullptr;

	Service::E_Service eService = (Service::E_Service) nServiceID;

	base = (this->*m_arrInstanceGenerator[nServiceID])();
	if(base)
		base->Init();
	else
		printf("instance is not createed\n");

	return base;
}





void RestCallClient::GetDataAsString(int nServiceID, const char *pstrParam, string *pstrReturn)
{

	if(nServiceID == -1)
		return;
	string param;
	EnaviBase *pBase = nullptr;
	pBase = GetInstance(nServiceID);
	if(pBase == nullptr)
	{
		printf("The Service does not exist\n");
		return;
	}
		
	E_RestType type = E_RestType::eSelect;
	http_response response;
	string url = GetDefaultResturl();

	string nullStr(pstrParam);
	try
	{

		if (nullStr == "")
		{
			param = web::uri::encode_uri("");
		}
		else
		{
			param = web::uri::encode_uri(pstrParam);
		}
			//param = web::uri::encode_uri(strParam);




		string service = pBase->GetSerivceUrl(type);
		url.append(service);
		printf("Rquest Url : %s\n", url.c_str());
		http_client client(url.c_str());

		uri_builder builder(U(""));
		builder.append_query(param);

		printf("Request param : %s\n", param.c_str());

		response = client.request(methods::GET, builder.to_string()).get();
	}
	catch (const web::http::http_exception &e)
	{
		printf(" ,[What] : %s", e.error_code().message().c_str());
	}

	printf("server is running at %s \n", url.c_str());



	json::value root = response.extract_json(true).get();

	bool isArray = root.at(U("data")).is_array();

	//printf("ArraySize : %d\n", root.at(U("data")).as_array().size());
	
	
	pstrReturn->assign(root.at(U("data")).serialize().c_str());

	delete pBase;
	pBase = nullptr;

}