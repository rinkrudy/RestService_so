#pragma once
#include<vector>

struct struct_Info
{
	bool success;
	char msg[4096];
	int data;
};
typedef struct struct_Info RestApiInfo;

struct struct_NavigableChannelInfo
{
	char name[20];
	char id[20];
	char dataTime[20];
	char lonLatString[2048];
	int vetexCnt;
	int wayDir;
	int wayType;
};
typedef struct struct_NavigableChannelInfo DB_NavigableChannelInfo;

struct struct_RestrictedSpeedAreaInfo
{
	char name[20];
	char id[20];
	char lonLatString[2048];
	char dataTime[20];
	int vetexCnt;
	int limitSpeed;
};
typedef struct struct_RestrictedSpeedAreaInfo DB_RestrictedSpeedAreaInfo;

struct struct_OilTankerProhibition
{
	char name[20];
	char id[20];
	char lonLatString[2048];
	char dataTime[20];
	int vetexCnt;
};
typedef struct struct_OilTankerProhibition DB_OilTankerProhibition;

struct struct_CoastlineInfo
{
	char name[20];
	char id[20];
	char lonLatString[2048];
	char dataTime[20];
	int vetexCnt;
	int objCnt;
};
typedef struct struct_CoastlineInfo DB_CoastlineInfo;

struct struct_TugBargeInfo
{
	char dataTime[20];
	char tugMMSI[20];
	char driftMMSI[20];
	int tdimA;
	int tdimB;
	int tdimC;
	int tdimD;
	int tposfixType;
	int tdraught;
	int ddimA;
	int ddimB;
	int ddimC;
	int ddimD;
	int dposfixType;
	int ddraught;
};
typedef struct struct_TugBargeInfo DB_TugBargeInfo;

struct struct_NarrowChannelInfo
{
	char dataTime[20];
	char lonLatString[20];
	char name[20];
	char id[20];
	int vetexCnt;
	int curSpd;
	int curDir;
	int maxWid;
	int maxDraft;
};
typedef struct struct_NarrowChannelInfo DB_NarrowChannelInfo;

struct struct_FishingAreaInfo
{
	char dataTime[20];
	char lonLatString[2048];
	char name[30];
	char id[20];

	int vetexCnt;
	int areaType;
};
typedef struct struct_FishingAreaInfo DB_FishingAreaInfo;

struct struct_LimitedAreaInfo
{
	char dataTime[20];
	char lonLatString[2048];
	char timeS[20];
	char timeE[20];
	char name[20];
	char id[20];

	int vetexCnt;
	int type;
};
typedef struct struct_LimitedAreaInfo DB_LimitedAreaInfo;

struct struct_ManeuverablilityLimitedInfo
{
	char dataTime[20];
	char shipName[20];
	char id[20];

	int shipType;
	int detailCode;
};
typedef struct struct_ManeuverablilityLimitedInfo DB_ManeuverablilityLimitedInfo;

struct struct_LowDepthReefInfo
{
	char dataTime[20];
	char id[20];
	char lonLatString[2048];
	char name[30];
	int type;
	int vetexCnt;
};
typedef struct struct_LowDepthReefInfo DB_LowDepthReefInfo;


struct struct_StrongCurrentInfo
{
	char dataTime[20];
	char lonLatString[2048];
	char id[20];
	char name[30];

	int vetexCnt;
	int curSpd;
	int curDir;
};
typedef struct struct_StrongCurrentInfo DB_StrongCurrentInfo;

struct struct_NavigationalSupportInfo
{
	char dataTime[20];
	char timeSv[20];
	char timeE[20];
	char sptMmsi[20];
	char hepMmsi[20];

	int supportType;
};
typedef struct struct_NavigationalSupportInfo DB_NavigationalSupportInfo;

struct struct_TotalNavigationTimeInfo
{
	char dataTime[20];
	char mmsi[20];
	char dstPrt1[20];
	char dstPrt2[20];
	char depPrt1[20];
	char depPrt2[20];
	char depDt[20];
	char dstArvlDt[20];
	char name[20];

	int shipType;
};
typedef struct struct_TotalNavigationTimeInfo DB_TotalNavigationTimeInfo;

struct struct_TrueNavigationRouteInfo
{
	char dataTime[20];
	char lonLatString[20];
	char id[20];
	char name[20];

	int vetexCnt;
};
typedef struct struct_TrueNavigationRouteInfo DB_TrueNavigationRouteInfo;

struct struct_WeatherInfo
{
	long id;
	char dateTime[20];
	double latitude;
	double longitude;
	double airTemp;
	double airPress;
	double waterTemp;
	double salinity;
	double windDirection;
	double windSpeed;
	double waveDirection;
	double waveHeight;
	double wavePeriod;
	double currentSpeed;
	double currentDirection;
	int weatherState;
	double visibility;
	double tidalElevation;
};
typedef struct struct_WeatherInfo DB_WeatherInfo;

struct struct_OSS_PASTNAV
{
	int wpcnt;
	double wplat;
	double wplon;
	double wpvel;
	double wpcourse;
};
typedef struct struct_OSS_PASTNAV DB_OSS_PASTNAV;

struct struct_OSS_WEATHER
{
	double visibility;
	double airPressure;
	double currentDir;
	double currentSpeed;
	double waterDepth;
	double waveDir;
	double waveHeight;
	double watherStat;
	double windRid;
	double windVel;
};
typedef struct struct_OSS_WEATHER DB_OSS_WEATHER;

struct struct_EnvironmentInfo
{
	double currentDir;
	double windVel;
	double zoneNum;
	double currentVel;
	double windDir;
};
typedef struct struct_EnvironmentInfo DB_EnvironmentInfo;


struct struct_PLT_OpinionInfo
{
	char flag[20];
	char prtAtCode[20];
	char vsslKey[20];
	char pltSerNo[20];
	char pltName[20];
	char offerNm[20];
	char vsslTp[20];
	char vsslNm[20];
	char pilotFacCode[20];
	char pltMsg[20];
};
typedef struct struct_PLT_OpinionInfo DB_PLT_OpinionInfo;

struct struct_SV30
{
	char mmsi[30];
};
typedef struct struct_SV30 DB_SV30;

struct struct_SV51
{
	char mmsi[30];
};
typedef struct struct_SV51 DB_SV51;

struct struct_Catalogue
{
	int catalogid;
	char idIdentifier[30];
	int idEditionnumber;
	char idDate[30];
	char exchangecatalogname[30];
	char category[100];
	char cataloguepath[100];
	char fileuri[300];
	char filedmzuri[300];
	char filename[100];
	char zone[100];
	char productversion[100];
	char enctype[100];
	char productdate[100];
	int filesize;
	char encrypt[100];
	char hash[100];
};
typedef struct struct_Catalogue DB_Catalogue;


struct struct_VesselStaticInfo
{
	char		shipMrn[128];
	char		mmsi[20];
	char		dateTime[20];
	char		shipName[256];
	char		callSign[20];
	int			shipType;
	int			dima;
	int			dimb;
	int			dimc;
	int			dimd;
	int			gnssType;
	int			maxDraught;
	double		aisLength;
	double		aisBeam;
	int			gpsAntennaXLocation;
	int			gpsAntennaYLocation;
	char		shipCode[64];
	int			shipLoa;
	int			shipLpp;
	int			shipWeight;
	int			shipDwt;
	int			cargoCode;
	int			cargoWeight;
	int			fuelRemain;
	double		shipDraftFwd;
	double		shipDraftAft;
	int			rudNum;
	double		rudArea;
	int			aisImoNumber;
	double		shipDisplacement;
	char		shipFlag[64];
	char		hullType[64];
	double		shipBreadth;
	double		shipDepth;
	char		vesselType[64];
	double		shipEngineHp;
};
typedef struct struct_VesselStaticInfo DB_VesselStaticInfo;

///
struct struct_PastNavInfo
{
	char 		dateTime[20];
	long 		mmsi;
	double 		latitude;
	double 		longitude;
	double 		sog;
		double 		cog;
	double 		heading;
};
typedef struct struct_PastNavInfo DB_PastNavInfo;

struct struct_PastNavVesslInfo
{
	long mmsi;
	char name[20];
	char vesselType[20];
	long imo;
	char callSign[20];
	double dimA;
	double dimB;
	double dimC;
	double dimD;
	double draft;
};
typedef struct struct_PastNavVesslInfo DB_PastNavVesselInfo;


struct struct_DepthInfo
{
	char name[30];
	int	vetexCnt;
	char lonLatString[2048];
	char depth[20];
};
typedef struct struct_DepthInfo DB_DepthInfo;

struct struct_ETCInfo
{
	long id;
	char name[30];
	char dateTime[20];
	long infoType;
};
typedef struct struct_ETCInfo DB_ETCInfo;

struct struct_ETCInfo_Etc
{
	long id;
	long etcId;
	char latitude[2048];
	char longitude[2048];
};
typedef struct struct_ETCInfo_Etc DB_ETCInfo_Etc;

struct struct_OptimumRouteInfo
{
	long id;
	long shipMmsi;
	long routeCount;
	long type;
	char routeDate[29];
	char lastTime[20];
	char expectArriveTime[20];
};
typedef struct struct_OptimumRouteInfo DB_OptimumRouteInfo;

struct struct_OptimumRouteInfo_Etc
{
	long id;
	long etcId;
	long countNumber;
	double latitude;
	double longitude;
	double speed;
	double course;
	char nextDistance[20];
};
typedef struct struct_OptimumRouteInfo_Etc DB_OptimumRouteInfo_Etc;

struct struct_ShipPosition
{
	long mmsi;
	char time[20];
	double cog;
	double sog;
	double latitude;
	double longitude;
};
typedef struct struct_ShipPosition DB_ShipPosition;

struct struct_GuideLine
{
	int guidelineId;
	int guideSimbolType;
	int displayType;
	double pointLat1;
	double pointLon1;
	double pointLat2;
	double pointLon2;
	double pointLat3;
	double pointLon3;
	double pointLat4;
	double pointLon4;
	char	message[100];
};
typedef struct struct_GuideLine DB_GuideLine;


struct struct_Zone
{
	char name[10];
	char slat[20];
	char wlon[20];
	char nlat[20];
	char elon[20];
	char version[30];
};
typedef struct struct_Zone DB_Zone;

/////////// SV 10 //////////////////

struct struct_AttentionShip
{
	char shipId[30];
	char dateTime[20];
	char name[50];
	int type;
	char attentionTime[16];
	int attentionCode;
	int shipLatitude;
	int shipLongitude;
	char content[1024];
};
typedef struct struct_AttentionShip DB_AttentionShip;

struct struct_SpecThreshold
{
	char dateTime[20];
	char version[10];
	char sv30Threshold[40];
	char abnormalThreshold[40];
	char sVAThreshold[40];
	char vBRSThreshold[40];
	char rSSThreshold[40];
};
typedef struct struct_SpecThreshold DB_SpecThreshold;

/*
struct struct_VulnerabilityAnalysis
{
	char dateTime[20];
	char sVAResult[30];
	char vBRSResult[30];
	char rSSResult[30];
};
typedef struct struct_VulnerabilityAnalysis DB_VulnerabilityAnalysis;
*/

struct struct_DangerShipAlarm
{
	char shipId[30];
	char dateTime[20];
	char areaId[8];
	bool inArea;
	char preTime[20];
	int preLatitude;
	int preLongitude;
	int shipLatitude;
	int shipLongitude;
	int shipCog;
	int shipSog;
	char recvTime[20];
	char content[1024];
};
typedef struct struct_DangerShipAlarm DB_DangerShipAlarm;

/*
struct struct_NavigationViolation
{
	char dateTime[20];
	char mmsi[20];
	char name[30];
	int type;
	int missCnt;
	char missTime[20];
	int missCode;
	char missString[2048];
};
typedef struct struct_NavigationViolation DB_NavigationViolation;
*/
/*
struct struct_CollisionRisk
{
	char dateTime[20];
	char mmsi[20];
	char name[30];
	int type;
	double risk;
};
typedef struct struct_CollisionRisk DB_CollisionRisk;
*/
/*
struct struct_StrandingRisk
{
	char dateTime[20];
	char mmsi[20];
	char name[30];
	int type;
	double risk;
};
typedef struct struct_StrandingRisk DB_StrandingRisk;
*/
/*
struct struct_NearMissViolation
{
	char dateTime[20];
	char mmsi[20];
	char name[30];
	int type;
	int missCnt;
	char missTime[20];
	int missCode;
	char missString[2048];
};
typedef struct struct_NearMissViolation DB_NearMissViolation;
*/
/*
struct struct_NormalOperation
{
	char dateTime[20];
	char id[10];
	char name[30];
	int vertexCnt;
	int latitude;
	int longitude;
	char gpsString[2048];
};
typedef struct struct_NormalOperation DB_NormalOperation;
*/

struct struct_AccidentRisk
{
	char dateTime[20];
	char alarmStatus;
	char oSMmsi[30];
	int oSLongitude;
	int oSLatitude;
	int oSCog;
	int oSSog;
	char accidentType;
	char accidentType2;
	char tSMmsi[30];
	int tSLongitude;
	int tSLatitude;
	int tSCog;
	int tSSog;
	char collisionType[128];
	int collisionLongitude;
	int collisionLatitude;
	double dcpa;
	double tcpa;
	double oSCPDistance;
	double oSCPTime;
	double tSCPDistance;
	double tSCPTime;
	double collisionRisk;
	char collisionArea[1024];
	char validTime[20];
};
typedef struct struct_AccidentRisk DB_AccidentRisk;

struct struct_AccidentPrediction
{
	char dateTime[20];
	char accidentTime[20];
	int accidentLatitude;
	int accidentLongitude;
	char oSMmsi[30];
	char accidentType;
	char accidentType2;
	char tSMmsi[30];
	char lastTimeSrc[20];
	char rOTSrc;
	int sOGSrc;
	int lATSrc;
	int lONSrc;
	int cOGSrc;
	int hDGSrc;
	char targetLastTimeSrc[20];
	char targetROTSrc;
	int targetSOGSrc;
	int targetLATSrc;
	int targetLONSrc;
	int targetCOGSrc;
	int targetHDGSrc;
};
typedef struct struct_AccidentPrediction DB_AccidentPrediction;

/*
struct struct_AccidentAdvice
{
	char dateTime[20];
	char accidentTime[20];
	char oSMmsi[20];
	char tSMmsi[20];
	int accidentLatitude;
	int accidentLongitude;
	int accidentArea;
};
typedef struct struct_AccidentAdvice DB_AccidentAdvice;
*/

struct struct_Route
{
	long routeId;
	char version[100];
	char vesselVoyage[128];
	long vesselMmsi;
	double defaultWaypointRadius;
};
typedef struct struct_Route DB_Route;

struct struct_RouteInfo
{
	long routeId;
	char routeName[32];
	char routeAuthor[32];
	char routeStatus[32];
	char validityPeriodStart[20];
	char validityPeriodStop[20];
	char vesselName[32];
	long vesselMmsi;
	long vesselImo;
	char vesselVoyage[128];
	long vesselDisplacement;
	long vesselCargo;
	double vesselGm;
	char optimizationMethod[32];
	long vesselMaxRoll;
	double vesselMaxWave;
	double vesselMaxWind;
	double vesselSpeedMax;
	double vesselServiceMin;
	double vesselServiceMax;
	char routeChangesHistory[128];
};
typedef struct struct_RouteInfo DB_RouteInfo;

struct struct_Waypoints
{
	long routeId;
	long defaultWaypoint;
	double defaultWaypointRadius;
	long id;
	long revision;
	char name[32];
	double radius;
	double lat;
	double lon;
	double starboardXtd;
	double portsideXtd;
	double safetyContour;
	double safetyDepth;
	long geometryType;
	double speedMin;
	double speedMax;
	double draughtForward;
	double draughtAft;
	double staticUkc;
	double dynamicUkc;
	double masthead;
	char legReport[32];
	char legInfo[128];
	char legNote1[128];
	char legNote2[238]; 

};
typedef struct struct_Waypoints DB_Waypoints;

struct struct_Schedules
{
	long routeId;
	long id;
	char name[32];
	long manual;
	long calculated;
	long waypointId;
	char etd[20];
	char etdWindowBefore[10];
	char etdWindowAfter[10];
	char etaWindowBefore[10];
	char etaWindowAfter[10];
	char stay[10];
	double speed;
	double speedWindow;
	double windSpeed;
	double windDirection;
	double currentSpeed;
	double currentDirection;
	double windLoss;
	double waveLoss;
	double totalLoss;
	long rpm;
	long pitch;
	double fuel;
	double relFuelSave;
	double absFuelSave;
	char note[128];
};
typedef struct struct_Schedules DB_Schedules;


struct struct_FTS
{
	long routeId;
	long waypointId;
	double rudderAngle;
	double rpm;
	double spareControlForce;
	double spare1;
	double spare2;
	double spare3;
	double spare4;
};
typedef struct struct_FTS DB_FTS;


// SV40 Added(09.12)
struct struct_EncUpdate
{
  int          updateId;
  char          shipMrn[100];
  char          license[100];
  char          responseTopic[4086];
  char          responseTime[20];
};
typedef struct struct_EncUpdate DB_EncUpdate;

struct struct_S57Cell
{
  char          dsnm[10];
  char          edtn[4];
  char          updn[4];
  char          uadt[11];
  char          isdt[11];
  char          expp;
  char          intu;
  char          slat[20];
  char          wlon[20];
  char          nlat[20];
  char          elon[20];
  char          zone[11];
};
typedef struct struct_S57Cell DB_S57Cell;

struct struct_S101Cell
{
  char          dsnm[20];
  char          edtn[4];
  char          updn[4];
  char          uadt[11];
  char          isdt[11];
  char          slat[20];
  char          wlon[20];
  char          nlat[20];
  char          elon[20];
  char          zone[11];
};
typedef struct struct_S101Cell DB_S101Cell;

struct struct_MrnRecentVersion
{
	char shipMrn[100];
	char license[100];
	char w1Version[30];
	char w2Version[30];
	char w3Version[30];
	char s1Version[30];
	char s2Version[30];
	char s3Version[30];
	char s4Version[30];
	char s5Version[30];
	char e1Version[30];
	char e2Version[30];
	char e3Version[30];
	char scVersion[30];
};
typedef struct struct_MrnRecentVersion DB_MrnRecentVersion;


// SV41 added (9.14)
struct struct_GuideLineWharf
{
  int          index;
  char          harbor[32];
  char          name[64];
  char          dName[32];
  double          length;
  double          fromtDepthMin;
  double          fromtDepthMax;
  char          loadingCapacity[64];
  char 			division[32];
};
typedef struct struct_GuideLineWharf DB_GuideLineWharf;

struct struct_GuideLineAnchorage
{
  int        	  index;
  char          harbor[32];
  char          name[32];
  char          fairwayName[32];
  char          division[32];
  char          ability[64];
};
typedef struct struct_GuideLineAnchorage DB_GuideLineAnchorage;

struct struct_GuideLineVTS
{
  int          index;
  char          harbor[32];
  char          callSign[32];
  char          division[32];
  char          vhfChannel[64];
  char          reportingPoint[32];
  char          reportingTime[64];
  char          reportingContent[128];
};
typedef struct struct_GuideLineVTS DB_GuideLineVTS;

struct struct_GuideLineSafetyStan
{
  int          index;
  char          harbor[32];
  char          state[64];
  char          content[256];
};
typedef struct struct_GuideLineSafetyStan DB_GuideLineSafetyStan;

struct struct_GuideLineSafetySpeed
{
  int          index;
  char          harbor[32];
  char          restrictedWater[32];
  char          targetVessel[32];
  char          limitedSpeed[32];
};
typedef struct struct_GuideLineSafetySpeed DB_GuideLineSafetySpeed;

struct struct_GuideLineTug
{
  int          index;
  char          harbor[32];
  char          scale[32];
  char          tugData[50];
};
typedef struct struct_GuideLineTug DB_GuideLineTug;

struct struct_GuideLineFairway
{
  int          index;
  char          harbor[32];
  char          name[32];
  double          length;
  double          depthMin;
  double          depthMax;
  double          widthMin;
  double          widthMax;
  char          content[64];
};
typedef struct struct_GuideLineFairway DB_GuideLineFairway;

struct struct_GuideLinePilot
{
  int          index;
  char          harbor[32];
  char          fairwayName[32];
  char          division[16];
};
typedef struct struct_GuideLinePilot DB_GuideLinePilot;

struct struct_GuideLineCourse
{
  int          index;
  char          harbor[32];
  char          fairwayName[32];
  char          division[16];
};
typedef struct struct_GuideLineCourse DB_GuideLineCourse;

struct struct_GuideLineSpeed
{
  int          index;
  char          harbor[32];
  char          name[32];
  double          speed;
};
typedef struct struct_GuideLineSpeed DB_GuideLineSpeed;

struct struct_GuideLineInfo
{
  int          index;
  char          harbor[32];
  char          fairwayName[32];
  char          division[16];
  char          content[256];
};
typedef struct struct_GuideLineInfo DB_GuideLineInfo;

struct struct_GuideLinePoint
{
  double          tableDv;
  double          rowDv;
  int          	sequence;
  char			harbor[32];
  double          latitude;
  double          longitude;
  double          heading;
};
typedef struct struct_GuideLinePoint DB_GuideLinePoint;


// SV10 added (9. 14)
struct struct_areaMst
{
  char          areaId[8];
  char          areaName[30];
  int          areaType;
  char          fromTime[20];
  char          toTime[20];
  char          verInfo[14];
};
typedef struct struct_areaMst DB_areaMst;

struct struct_areaDetail
{
   char			areaId[8];
  int          areaSeq;
  double          areaLat;
  double          areaLon;
};
typedef struct struct_areaDetail DB_areaDetail;

struct struct_areaSelect
{
  int          areaSeq;
  char          areaName[30];
  int          areaType;
  char          fromTime[20];
  char          toTime[20];
  double          areaLat;
  double          areaLon;
};
typedef struct struct_areaSelect DB_areaSelect;

struct struct_vulInput00_1
{
  char          dateTime[20];
  int          collisionLatitude;
  int          collisionLongitude;
  double          dcpa;
  double          tcpa;
  double          risk;
  char          firstShipId[30];
  char          firstName[50];
  char          firstType[4];
  int          firstLatitude;
  int          firstLongitude;
  int          firstCog;
  int          firstSog;
  char          firstRecvtime[20];
  char          secondShipId[30];
  char          secondName[50];
  char          secondType[4];
  int          secondLatitude;
  int          secondLongitude;
  int          secondCog;
  int          secondSog;
  char          secondRecvtime[20];
};
typedef struct struct_vulInput00_1 DB_vulInput00_1;

struct struct_vulInput00_2
{
  char          shipId[30];
  char          dateTime[20];
  char          name[50];
  char          type[4];
  double          risk;
  int          collisionLatitude;
  int          collisionLongitude;
  int          shipLatitude;
  int          shipLongitude;
  int          shipCog;
  int          shipSog;
  char          shipRecvtime[20];
};
typedef struct struct_vulInput00_2 DB_vulInput00_2;

struct struct_vulInput01
{
  char          vulId[8];
  char          areaId[8];
  int          curSpd01;
  int          curDir01;
  int          curSpd02;
  int          curDir02;
  int          acciCount;
  int          areaSeq;
  char          areaName[30];
  char          fromTime[20];
  char          toTime[20];
  double          areaLat;
  double          areaLon;
};
typedef struct struct_vulInput01 DB_vulInput01;
struct struct_vulInput01_input
{
  char          vulId[8];
  char          areaId[8];
  int          curSpd01;
  int          curDir01;
  int          curSpd02;
  int          curDir02;
  int          acciCount;
};
typedef struct struct_vulInput01_input DB_vulInput01_input;

struct struct_vulInput02
{
  char          vulId[8];
  char          areaId[8];
  int          windSpd;
  int          waveHeight;
  int          areaSeq;
  char          areaName[30];
  char          fromTime[20];
  char          toTime[20];
  double          areaLat;
  double          areaLon;
};
typedef struct struct_vulInput02 DB_vulInput02;
struct struct_vulInput02_input
{
  char          vulId[8];
  char          areaId[8];
  int          windSpd;
  int          waveHeight;
};
typedef struct struct_vulInput02_input DB_vulInput02_input;

struct struct_vulInput03
{
  char          vulId[8];
  char          areaId[8];
  double          dynCong;
  double          staCong;
  int          acciRatio;
  int          areaSeq;
  char          areaName[30];
  char          fromTime[20];
  char          toTime[20];
  double          areaLat;
  double          areaLon;
};
typedef struct struct_vulInput03 DB_vulInput03;
struct struct_vulInput03_input
{
  char          vulId[8];
  char          areaId[8];
  double          dynCong;
  double          staCong;
  int          acciRatio;
};
typedef struct struct_vulInput03_input DB_vulInput03_input;

struct struct_vulInput04
{
  char          vulId[8];
  char          areaId[8];
  int          acciRatio;
  int          passShips;
  int          areaSeq;
  char          areaName[30];
  char          fromTime[20];
  char          toTime[20];
  double          areaLat;
  double          areaLon;
};
typedef struct struct_vulInput04 DB_vulInput04;
struct struct_vulInput04_input
{
  char          vulId[8];
  char          areaId[8];
  int          acciRatio;
  int          passShips;
};
typedef struct struct_vulInput04_input DB_vulInput04_input;

struct struct_vulInput05
{
  char          shipId[30];
  char          depTime[20];
  char          arrTime[20];
  char          depPort[8];
  double          tonnage;
};
typedef struct struct_vulInput05 DB_vulInput05;

struct struct_vulInput06
{
  char          shipId[30];
  char          subShipId[30];
  char          depTime[20];
  char          arrTime[20];
  char          depPort[8];
  char          arrPort[8];
  int          tugType;
  int          tugLen;
  int          mstLen;
  int          subLen;
};
typedef struct struct_vulInput06 DB_vulInput06;

struct struct_vulInput07
{
  char          tgtShipId[30];
  char          shipId[30];
  int          index;
  char          fromTime[20];
  char          toTime[20];
};
typedef struct struct_vulInput07 DB_vulInput07;

struct struct_avsResponse
{
  char          acciTime[20];
  char          osShipId[30];
  char          tsShipId[30];
  char          reqTime[20];
  char          resTime[20];
};
typedef struct struct_avsResponse DB_avsResponse;

struct struct_rssResponse
{
  char          acciTime[20];
  char          osShipId[30];
  char          tsShipId[30];
  char          tgtShipId[30];
  int          tgtLat;
  int          tgtLon;
  char          reqTime[20];
  char          resTime[20];
};
typedef struct struct_rssResponse DB_rssResponse;

struct struct_fishingHistoryArea
{
  char          areaId[8];
  int          fisheryType;
  int          fishSpecies;
  char          fromTime[20];
  char          toTime[20];
};
typedef struct struct_fishingHistoryArea DB_fishingHistoryArea;

struct struct_fishingPatternArea
{
  char          shipStr[1024];
  char          locStr[2048];
  char          areaStr[2048];
  char          dateTime[20];
};
typedef struct struct_fishingPatternArea DB_fishingPatternArea;

struct struct_abnormalPattern
{
  char          shipId[30];
  char          dateTime[20];
  int          shipLatitude;
  int          shipLongitude;
  int          shipCog;
  int          shipSog;
  char          recvTime[20];
  double          abnormalValue;
};
typedef struct struct_abnormalPattern DB_abnormalPattern;

struct struct_ShipDensity
{
	int 	index;
	char	time[16];
	double 	pointLat1;
	double	pointLon1;
	double 	pointLat2;
	double	pointLon2;
	double 	pointLat3;
	double	pointLon3;
	double 	pointLat4;
	double	pointLon4;
	double 	densityValue;
	long	shipCount;
};
typedef struct struct_ShipDensity DB_ShipDensity;


//SV20
struct struct_AwmNavigationInfo
{
	char szLOG[20];
	char szAIS[20];
	char szGPS1[20];
	char szGPS2[20];
	char szECDIS[20];
	char szRADAR1[20];
	char szRADAR2[20];
	char szEchoSounder[20];
	char szGyroCompass[20];
	char szAutoPilot[20];
};
typedef struct struct_AwmNavigationInfo DB_NavigationInfo;

struct struct_AwmEmergencyInfo
{
	char szRunTime[50];
	long nFireLevel;
	long nSeakeepingLevel;
	long nNavigationLevel;
	char szFireSafetyCode[10];
	char szSeakeepingQualiyCode[10];
	char szNavigationSafetyCode[10];
};
typedef struct struct_AwmEmergencyInfo DB_EmergencyInfo;

struct struct_AwmFireDoor
{
	bool bUse;
	bool bDoorOpen;
	long nPositionId;
};
typedef struct struct_AwmFireDoor DB_FireDoor;

struct struct_AwmFireAlarm
{
	bool bUse;
	short sCount;
	char szDetectorType[20];
	long nPositionId;
	char szAlarmTime[20];
};
typedef struct struct_AwmFireAlarm DB_FireAlarm;

struct struct_AwmOldFireAlarm
{
	bool 	bUse;
	short 	sCount;
	bool 	bBreakOut;
};
typedef struct struct_AwmOldFireAlarm DB_OldFireAlarm;

struct struct_AwmMainEngine
{
	char 	szShutdown[20];
	char 	szSlowdown[20];
	bool 	bUseRpm1;
	bool 	bUseRpm2;
	double 	dRpm1;
	double 	dRpm2;
};
typedef struct struct_AwmMainEngine DB_MainEngine;

struct struct_AwmGenerator
{
	short 	sNo;
	short 	sCount;
	char 	szCFW_HighTemp_Trip[20];
	char 	szLO_LowPress_Trip[20];
	char 	szOverSpeed_Trip[20];
	char 	szCommon_Trip[20];
	char 	szSpeedSensorFail_Trip[20];
	char 	szStartFail[20];
	char 	szCommonShutdown[20];
};
typedef struct struct_AwmGenerator DB_Generator;

struct struct_AwmSteeringGear
{
	short 	sNo;
	short 	sCount;
	char 	szHydLoTk_LL[20];
	char 	szMotor_Run[20];
	char 	szNoVolt[20];
	char 	szOverload[20];
	char 	szPhase_Fail[20];
};
typedef struct struct_AwmSteeringGear DB_SteeringGear;

struct struct_AwmRecovery
{
	bool 		bUseRoll;
	bool 		bUsePitch;
	bool 		bUseGps;
	bool 		bUseWind;
	bool 		bUseRudder1;
	bool 		bUseRudder2;
	double 		dRolling;
	double 		dPitching;
	double 		dCog;
	double 		dSog;
	double 		dShipHeading;
	double 		dShipSpeed;
	double 		dWindDirection;
	double 		dWindSpeed;
	double 		dRudder1;
	double 		dRudder2;

};
typedef struct struct_AwmRecovery DB_Recovery;

struct struct_AwmTankLevel
{
	short 		sCount;
	char 		szTankType[20];
	char 		szTankName[10];
	short 		sTankNumber;
	double 		dVal;
};
typedef struct struct_AwmTankLevel DB_TankLevel;

struct struct_AwmRamp
{
	bool 		bRampUse;
	short 		sCount;
	long 		nRampId;
	bool 		bRampDoorOpen;
};
typedef struct struct_AwmRamp DB_Ramp;

struct struct_AwmTelegraph
{
	bool 		bTelegraphUse;
	short 		sCount;
	long 		nTelegraphId;
	long 		nTelegraphStatus;
};
typedef struct struct_AwmTelegraph DB_Telegraph;

struct struct_AwmStability
{
	double dForeDraft;
	double dAftDraft;
	double dKG;
	double dGoM;
};
typedef struct struct_AwmStability DB_Stability;




struct struct_AwmShipStaticInfo
{
	long nServiceId;
	char szUtcDate[12];
	char szUtcTime[12];
	double dLatitude;
	double dLongitude;
	std::vector<DB_NavigationInfo> arrNavigationInfo;
	std::vector<DB_EmergencyInfo> arrEmergencyInfo;
	std::vector<DB_FireDoor> arrFireDoor;
	std::vector<DB_FireAlarm> arrFireAlarm;
	std::vector<DB_OldFireAlarm> arrOldFireAlarm;
	std::vector<DB_MainEngine> arrMainEngine;
	std::vector<DB_Generator> arrGenerator;
	std::vector<DB_SteeringGear> arrSteeringGear;
	std::vector<DB_Recovery> arrRecovery;
	std::vector<DB_TankLevel> arrTankLevel;
	std::vector<DB_Ramp> arrRamp;
	std::vector<DB_Telegraph> arrTelegraph;
	std::vector<DB_Stability> arrStability;

};
typedef struct struct_AwmShipStaticInfo DB_ShipStaticInfo;

struct struct_AwmDataSetShipStaticInfo
{
	char szShipmrn[128];
	std::vector<DB_ShipStaticInfo> arrShipStaticInfoList;
};
typedef struct struct_AwmDataSetShipStaticInfo  DB_DataSetShipStaticInfo;



//SV 52
struct struct_ArgoMet
{
	char coodinateGeoXY[2500];
	char startDateTime[25];
	char endDateTime[25];
	char catalog[450];
};
typedef struct struct_ArgoMet DB_ArgoMet;


//Common
struct struct_ServiceLog
{
	char serviceName[10];
	char intefaceName[50];
	char regDateTime[20];
	char content[500];
};
typedef struct struct_ServiceLog DB_ServiceLog;

struct struct_FeaturesForWaterway
{
	char 		spec[10];
	char 		version[10];
	char 		startDate[10];
	char 		endDate[10];
	char 		generalCategory[10];
	char 		geomtype[10];
	char * 		geom;

};
typedef struct struct_FeaturesForWaterway DB_FeaturesForWaterway;
