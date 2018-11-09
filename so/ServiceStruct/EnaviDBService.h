#pragma once
#include<string>

namespace Service
{
	enum E_Group{
		None = 0,
		eSV10,
		eSV20,
		eSV30,
		eSV40,
		eSV51,
		eSV52,
		eCommon,
		Max
	};
	enum E_Service{
		//SV10
		eAbnormalPattern = 0,
		eAccidentPrediction,
		eAccidentRisk,
		eAreaDetail,
		eAreaMst,
		eAreaSelect,
		eAttentionShip,
		eAvsResponse,
		eDangerShipAlarm,
		eFishingHistoryArea,
		eFishingPatternArea,
		eRssResponse,
		eSpecThreshold,
		eVulInput00_1,
		eVulInput00_2,
		eVulInput01,
		eVulInput02,
		eVulInput03,
		eVulInput04,
		eVulInput05,
		eVulInput06,
		eVulInput07,
		eShipStaticInfo,
		ePastNavInfo,
		ePastNavVesselInfo,
		eRoute,
		eRouteInfo,
		eWaypoints,
		eSchedules,
		eFTS,
		eCatalogue,
		eCatalogueAll,
		eEncUpdate,
		eS57Cell,
		eS101Cell,
		eZone,
		eZoneAll,
		eMrnRecentVersion,
		eGuideLine,
		eGuideLineAnchorage,
		eGuideLineCourse,
		eGuideLineFairway,
		eGuideLineInfo,
		eGuideLinePilot,
		eGuideLinePoint,
		eGuideLineSafetySpeed,
		eGuideLineSafetyStan,
		eGuideLineSpeed,
		eGuideLineTug,
		eGuideLineVTS,
		eGuideLineWharf,
		eShipPosition,
		eShipDensity,
		//sv52
		eArgoMet,
		eFeaturesForWaterway,
		//common
		eServiceLog,
		//None		
		eVesselStaticinfo,
		eEncSelector,


		

    	eService_Max
	};

	enum E_RestType{
	eSelect = 0,
	eInsert,
	eUpdate,
	eDelete,
	eRest_Max
	};

}

