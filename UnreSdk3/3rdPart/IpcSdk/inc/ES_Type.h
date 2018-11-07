
#ifndef __ESONG_ES_TYPE_H_INC__
#define __ESONG_ES_TYPE_H_INC__

typedef enum ES_ERROR_CODE
{
	ES_ERROR_SUCCESS			= 0,	//�ɹ�;
	ES_ERROR_USER_OR_PWD_ERROR	= 1,	//�û������������;
	ES_ERROR_NETWORK_ERROR		= 2,	//�������;
	ES_ERROR_SESSION_NOT_FOUND	= 3,	//�豸���������;
	ES_ERROR_OPERATOR_FAILED	= 4,	//����ʧ��;
	ES_ERROR_BAD_ALLOC			= 5,	//�ڴ����ʧ��;
	ES_ERROR_RECV_WRONG_DATA	= 6,	//���յ����ݴ���;
	ES_ERROR_HAS_NO_ABILITY		= 7,	//û�и�����;
	ES_ERROR_MAX_CLIENTS		= 8,	//����������;
	ES_ERROR_INVALID_PARAM		= 9,	//��Ч����;
	ES_ERROR_REMOTE_CLOSED		= 10,	//Զ���Ѿ��ر�;
	ES_ERROR_DEVICE_TYPE_MISMATCH	= 11,	//�豸���Ͳ�ƥ��;
	ES_ERROR_FORBID_OPERATION		= 12,   //��ֹ����;
	ES_ERROR_NOT_INITIALIZED	= 13,	//δ��ʼ��;
	
	ES_ERROR_PPCS_NOT_INITIALIZED			= 1001,
	ES_ERROR_PPCS_ALREADY_INITIALIZED		= 1002,
	ES_ERROR_PPCS_TIME_OUT					= 1003,
	ES_ERROR_PPCS_INVALID_ID				= 1004,
	ES_ERROR_PPCS_INVALID_PARAMETER			= 1005,
	ES_ERROR_PPCS_DEVICE_NOT_ONLINE			= 1006,
	ES_ERROR_PPCS_FAIL_TO_RESOLVE_NAME		= 1007,
	ES_ERROR_PPCS_INVALID_PREFIX			= 1008,
	ES_ERROR_PPCS_ID_OUT_OF_DATE			= 1009,
	ES_ERROR_PPCS_NO_RELAY_SERVER_AVAILABLE	= 1010,
	ES_ERROR_PPCS_INVALID_SESSION_HANDLE	= 1011,
	ES_ERROR_PPCS_SESSION_CLOSED_REMOTE		= 1012,
	ES_ERROR_PPCS_SESSION_CLOSED_TIMEOUT	= 1013,
	ES_ERROR_PPCS_SESSION_CLOSED_CALLED		= 1014,
	ES_ERROR_PPCS_REMOTE_SITE_BUFFER_FULL	= 1015,
	ES_ERROR_PPCS_USER_LISTEN_BREAK			= 1016,
	ES_ERROR_PPCS_MAX_SESSION				= 1017,
	ES_ERROR_PPCS_UDP_PORT_BIND_FAILED		= 1018,
	ES_ERROR_PPCS_USER_CONNECT_BREAK		= 1019,
	ES_ERROR_PPCS_SESSION_CLOSED_INSUFFICIENT_MEMORY	= 1020,
	ES_ERROR_PPCS_INVALID_APILICENSE		= 1021,
	ES_ERROR_PPCS_FAIL_TO_CREATE_THREAD		= 1022,

	ES_ERROR_RECV_TIMEOUT			= 0xFFFFFFFB,	//�������ݳ�ʱ;
	ES_ERROR_RECV_DATA_NOT_COMPLETE	= 0xFFFFFFFC,	//����δ������ȫ;
	ES_ERROR_RECV_NONE	= 0xFFFFFFFD,	//û�н��յ�����;
	ES_ERROR_SDK_ERROR	= 0xFFFFFFFE,	//SDK����;
	ES_ERROR_UNKNOWN	= 0xFFFFFFFF,	//δ֪����;

} ES_ERROR_CODE;


typedef enum ES_DEVICE_TYPE
{
	//PP
	ES_DEVICE_TYPE_SIMULATION	= 1,	//ģ�������;
	ES_DEVICE_TYPE_ESI101		= 2,	//ESI101;
	ES_DEVICE_TYPE_ESI112		= 3,	//ESI112;
	ES_DEVICE_TYPE_ESI113		= 4,	//ESI113;
	ES_DEVICE_TYPE_ESI119		= 5,	//ESI119;
	ES_DEVICE_TYPE_ESI120		= 6,	//ESI120;
	ES_DEVICE_TYPE_ESI125		= 7,	//ESI125;
	ES_DEVICE_TYPE_ESI111		= 8,	//ESI111;

	//AP
	ES_DEVICE_TYPE_C90			= 100,	//C90;
	ES_DEVICE_TYPE_C90_PLUS		= 101,	//C90+;

	ES_DEVICE_TYPE_ESR880		= 200,	//ESR880;

	//NT
	ES_DEVICE_TYPE_C91			= 300,	//C91;
    ES_DEVICE_TYPE_C60N         = 301,  //C60N;
	ES_DEVICE_TYPE_ESR303		= 302,	//ESR303;
	ES_DEVICE_TYPE_ESR306		= 303,	//ESR306;
	ES_DEVICE_TYPE_ESR307		= 304,	//ESR307;

	//PN
	ES_DEVICE_TYPE_PEN			= 400,	//¼���;
    
	//TM
    ES_DEVICE_TYPE_ESR302       = 500,	//�����豸;
    
	//GP
    ES_DEVICE_TYPE_ESR301       = 600,	//��ͨ�豸;

	//TI
	ES_DEVICE_TYPE_ERD402		= 700,	//��˼����һ�豸;

	//FR
	ES_DEVICE_TYPE_K20			= 800,	//��������豸;

	ES_DEVICE_TYPE_UNKNOWN = 0xFFFFFFFF,	//δ֪�豸;

} ES_DEVICE_TYPE;


typedef enum ES_DECODE_TYPE
{
    ES_DECODE_TYPE_YUV	= 0,
    ES_DECODE_TYPE_RGB	= 1,
    
} ES_DECODE_TYPE;


typedef enum ES_PLATFORM_TYPE
{
	ES_PLATFORM_TYPE_ANDROID	= 0,
	ES_PLATFORM_TYPE_IOS		= 1,
	ES_PLATFORM_TYPE_WINDOWS	= 2,
	ES_PLATFORM_TYPE_MAC_OS_X	= 3,

} ES_PLATFORM_TYPE;


typedef enum ES_ABILITY_TYPE
{
	ES_ABILITY_TYPE_PTZ		= 1,	//��̨����;
	ES_ABILITY_TYPE_TALK	= 2,	//�Խ�����;
	ES_ABILITY_TYPE_SD		= 3,	//��������;

	ES_ABILITY_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_ABILITY_TYPE;


typedef enum ES_SV_CHECK_CODE_TYPE
{
	ES_SV_CHECK_CODE_TYPE_REGISTER	= 0,
	ES_SV_CHECK_CODE_TYPE_FIND_PWD	= 1,
	
	ES_SV_CHECK_CODE_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_SV_CHECK_CODE_TYPE;


typedef enum ES_SV_LOGIN_TYPE
{
	ES_SV_LOGIN_TYPE_MAIL		= 0,
	ES_SV_LOGIN_TYPE_QQ			= 1,
	ES_SV_LOGIN_TYPE_WX			= 2,
	ES_SV_LOGIN_TYPE_FACEBOOK	= 3,
	ES_SV_LOGIN_TYPE_TWITTER	= 4,
	ES_SV_LOGIN_TYPE_PHONE		= 5,
	ES_SV_LOGIN_TYPE_GOOGLE		= 6,
	ES_SV_LOGIN_TYPE_WHATSAPP	= 7,
	
	ES_SV_LOGIN_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_SV_LOGIN_TYPE;


enum { ES_WIFI_NAME_LEN = 32 };			//Wifi���Ƴ���;
enum { ES_WIFI_PASSWORD_LEN = 32 };		//Wifi���볤��;
enum { ES_WIFI_SECURITY_LEN = 64 };		//WiFi���ܷ�ʽ����;
enum { ES_DEVICE_NAME_MAX_LEN = 64 };   //�豸������󳤶�;
enum { ES_DEVICE_ID_MAX_LEN	= 20 };		//�豸ID��󳤶�;
enum { ES_REMOTE_RECORD_NAME_MAX_LEN = 32 };	//Զ��¼��������󳤶�;
enum { ES_PATH_MAX_LEN = 128 };			//·����󳤶�;
enum { ES_VERSION_MAX_LEN = 32 };			//�豸�汾����󳤶�;
enum { ES_PWD_MD5_LEN = 36 };	//MD5���ܺ�����볤��;
enum { ES_UUID_MAX_LEN = 40 };	//UUID��󳤶�;
enum { ES_IP_LEN = 16 };	//IP��ַ����;
enum { ES_MAC_LEN = 6 };	//MAC��ַ����;
enum { ES_MAX_CLIENTS = 4 };	//�ͻ����������;
enum { ES_ENCRYPTION_CODE_LEN = 16 };	//�豸�˼�����Կ����;
enum { ES_OSD_MAX_LEN = 256 };	//OSD��󳤶�;
enum { ES_DEVICE_FONT_MAX_SIZE = 128*32*32/4 };	//�豸���ֿ���󳤶�;


//�豸״̬;
typedef enum ES_DEVICE_STATE
{
	ES_DEVICE_STATE_CONNECTED		= 0,	//�豸���ӳɹ�;
	ES_DEVICE_STATE_PASSWORD_ERROR	= 1,	//�������;
	ES_DEVICE_STATE_MAX_CLIENTS		= 2,	//����������;
	ES_DEVICE_STATE_OFFLINE			= 3,	//����;
	ES_DEVICE_STATE_NETWORK_ERROR	= 4,	//���糬ʱ;
	ES_DEVICE_STATE_INVALID_ID		= 5,	//�豸ID��Ч;
	ES_DEVICE_STATE_DISCONNECTED	= 6,	//�豸�Ͽ����ӳɹ�;

	ES_DEVICE_STATE_BATTERY_CHARGING	= 0x100,	//��س����;
	ES_DEVICE_STATE_BATTERY_IDLE		= 0x101,	//��ؿ�����;

	ES_DEVICE_STATE_RECORD_RECORDING	= 0x200,	//ѭ��¼Ӱ��;
	ES_DEVICE_STATE_RECORD_IDLE			= 0x201,	//ѭ��¼Ӱ������;

	ES_DEVICE_STATE_EDOG_UPDATE_SUCCESS	= 0x301,	//���ӹ����������ɹ�;
	ES_DEVICE_STATE_EDOG_UPDATE_FAILED	= 0x302,	//���ӹ���������ʧ��;

	ES_DEVICE_STATE_UNKNOWN		= 0xFFFFFFFF,
} ES_DEVICE_STATE;


//�������������;
typedef enum ES_DEVICE_UPDATE_TYPE
{
	ES_DEVICE_UPDATE_TYPE_KERNEL	= 0,
	ES_DEVICE_UPDATE_TYPE_ROOTFS	= 1,
	ES_DEVICE_UPDATE_TYPE_APP		= 2,
	ES_DEVICE_UPDATE_TYPE_DEVICEID	= 3,	//�豸ID;
	ES_DEVICE_UPDATE_TYPE_EDOG_DATA	= 4,	//���ӹ�����;

	ES_DEVICE_UPDATE_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_UPDATE_TYPE;


//�������������;
typedef enum ES_LANGUAGE_TYPE
{
	ES_LANGUAGE_TYPE_DEFAULT	= 0,
	ES_LANGUAGE_TYPE_CHINESE	= 1,
	ES_LANGUAGE_TYPE_ENGLISH	= 2,

	ES_LANGUAGE_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_LANGUAGE_TYPE;


//��������;
typedef enum ES_StreamType
{ 
	ES_ST_HD			= 0,	//����;
	ES_ST_BALANCE		= 1,	//����;
	ES_ST_SMOOTH		= 2,	//����;

	ES_ST_UNKNOWN = 0xFFFFFFFF 
} ES_StreamType;


//ý������;
typedef enum ES_MediaType
{
	ES_MT_TIMER			= 0,	//��ʱ¼��;
	ES_MT_ALARM			= 1,	//����¼��;
	ES_MT_TIME_LAPSE	= 2,	//��ʱ¼Ӱ;
	ES_MT_MANUAL_RECORD	= 3,	//�û��ֶ�¼��;
	ES_MT_MANUAL_IMAGE	= 4,	//�û��ֶ�����;

	ES_MT_RECORDING		= 0x100,	//����¼�����Ƶ;

	ES_MT_UNKNOWN = 0xFFFFFFFF,
} ES_MediaType;


//����״̬;
typedef enum ES_DOWNLOAD_STATE
{
	ES_DOWNLOAD_STATE_RUNNING	= 0,
	ES_DOWNLOAD_STATE_OK		= 1,
	ES_DOWNLOAD_STATE_STOP		= 2,
	ES_DOWNLOAD_STATE_ERROR		= 3,

	ES_DOWNLOAD_STATE_UNKNOWN	= 0xFFFFFFFF,
} ES_DOWNLOAD_STATE;


//��������;
typedef enum ES_AlarmType
{
	ES_AT_MOTION	= 0,	//�ƶ����;
	ES_AT_GPIO		= 1,	//GPIO����;
	ES_AT_PIR		= 2,	//�����Ӧ;

	ES_AT_UNKNOWN	= 0xFFFFFFFF,
} ES_AlarmType;


//��̨��������;
typedef enum ES_PTZ_CONTROL_TYPE
{
	ES_PTZ_CONTROL_TYPE_STOP		= 0,	//ֹͣ;
	ES_PTZ_CONTROL_TYPE_UP		= 1,	//��;
	ES_PTZ_CONTROL_TYPE_DOWN		= 2,	//��;
	ES_PTZ_CONTROL_TYPE_LEFT		= 3,	//��;
	ES_PTZ_CONTROL_TYPE_RIGHT	= 4,	//��;

	ES_PTZ_CONTROL_TYPE_OPEN_LR_CRUISE	= 0x10,	//��������Ѳ��;
	ES_PTZ_CONTROL_TYPE_CLOSE_LR_CRUISE	= 0x11,	//�ر�����Ѳ��;
	ES_PTZ_CONTROL_TYPE_OPEN_UD_CRUISE	= 0x12,	//��������Ѳ��;
	ES_PTZ_CONTROL_TYPE_CLOSE_UD_CRUISE	= 0x13,	//�ر�����Ѳ��;

	ES_PTZ_CONTROL_TYPE_SET_PRESET		= 0x20,	//����Ԥ��λ;
	ES_PTZ_CONTROL_TYPE_CALL_PRESET		= 0x21,	//����Ԥ��λ;

} ES_PTZ_CONTROL_TYPE;



//��������������;
typedef enum ES_LanControlType
{
	ES_LCT_LIGHT_FAST	= 0,	//״̬�ƿ���;
	ES_LCT_LIGHT_NORMAL	= 1,	//״̬��������;
	ES_LCT_REBOOT		= 2,	//�����豸;
	ES_LCT_FACTORY		= 3,	//�ָ�����;
	ES_LCT_KILL			= 4,	//����Ӧ�ó���;
	ES_LCT_DEFECT_PIXEL	= 5,	//����У��;
	ES_LCT_LANGUAGE		= 6,	//��������	ES_DeviceParamLanguage;
	ES_LCT_ENCRYPTION	= 7,	//��������	ES_DeviceParamEncryption;

	ES_LCT_UNKNOWN		= 0xFFFFFFFF,
} ES_LanControlType;


//��־�ȼ�;
typedef enum ES_LOG_LEVEL
{
	ES_LOG_LEVEL_HIGH				= 1 << 0,
	ES_LOG_LEVEL_FUNCTION			= 1 << 1,
	ES_LOG_LEVEL_DETAIL				= 1 << 2,
	ES_LOG_LEVEL_FUNCTION_DATAIL	= 1 << 3,
	ES_LOG_LEVEL_STREAM				= 1 << 4,

} ES_LOG_LEVEL;


#ifdef WIN32
typedef size_t SOCKET;
#else
typedef int SOCKET;
#endif


//������Ϣ;
typedef struct ES_Frame
{
	unsigned int nbframe;
	unsigned int seconds;
	unsigned int useconds;
	unsigned short width;
	unsigned short height;
	unsigned int size;
	unsigned int frame_type : 4;	//֡����: 0 - ��Ƶ    2 - I Frame	3 - P Frame    4 - ��Ļ;
	unsigned int stream_type : 4;	//�������Ƶ: 1 - 8000HZ   2 - 44100HZ	3 - 48000HZ;
	unsigned int fps_base : 8; 
	unsigned int fps_interval: 8;
	unsigned int vidcompressor: 2;	//��Ƶѹ����ʽ�� 0 - H.264	1 - H.265;
	unsigned int audcompressor: 2;	//��Ƶѹ����ʽ�� 1 - PCM		2 - G.711    3 - AAC;
	unsigned int audio_channels: 1;		//��Ƶͨ����: 0 - ��ͨ��    1 - ˫ͨ��;
	unsigned int audio_sample_size: 1;	//��Ƶ������С: 0 - 16λ    1 - 8λ;
	unsigned int reserved : 2;
} ES_Frame;


typedef struct ES_Date
{
	unsigned short	year;
	unsigned char	month;
	unsigned char	day;
} ES_Date;


typedef struct ES_Time
{
	unsigned char	hour;
	unsigned char	minute;
	unsigned char	second;
	unsigned char	resv;
} ES_Time;


typedef struct ES_DateTime
{
	ES_Date date;
	ES_Time time;
} ES_DateTime;


//�豸��������;
typedef enum ES_DEVICE_PARAM_TYPE
{
	ES_DEVICE_PARAM_TYPE_WIFI       = 1,	//Wifi����:		ES_DeviceParamWifi;
	ES_DEVICE_PARAM_TYPE_NAME       = 2,	//�豸���Ʋ���:  ES_DeviceParamName;
	ES_DEVICE_PARAM_TYPE_STORAGE    = 4,    //�洢״̬����:  ES_DeviceParamStorage;
	ES_DEVICE_PARAM_TYPE_VERSION    = 5,    //�豸�汾����:  ES_DeviceParamVersion;
	ES_DEVICE_PARAM_TYPE_PASSWORD	= 8,	//�������:		ES_DeviceParamPassword;
	ES_DEVICE_PARAM_TYPE_MIRROR		= 9,	//�������:		ES_DeviceParamMirror;
	ES_DEVICE_PARAM_TYPE_BRIGHTNESS	= 10,	//���Ȳ���:		ES_DeviceParamBrightness;
	ES_DEVICE_PARAM_TYPE_CHROMA		= 11,	//ɫ�Ȳ���:		ES_DeviceParamChroma;
	ES_DEVICE_PARAM_TYPE_CONTRAST	= 12,	//�ԱȶȲ���:	ES_DeviceParamContrast;
	ES_DEVICE_PARAM_TYPE_SATURATION	= 13,	//���ͶȲ���:	ES_DeviceParamSaturation;
	ES_DEVICE_PARAM_TYPE_SHARPNESS	= 14,	//��Ȳ���:		ES_DeviceParamSharpness;
	ES_DEVICE_PARAM_TYPE_NETWORK	= 15,	//�����������:	ES_DeviceParamNetwork;
	ES_DEVICE_PARAM_TYPE_WIFILIST	= 16,	//Wi-Fi�б�:		ES_DeviceParamWiFiList;
	ES_DEVICE_PARAM_TYPE_ALARM		= 17,	//�������:	ES_DeviceParamAlarm;
	ES_DEVICE_PARAM_TYPE_TIME		= 18,	//ʱ�����:		ES_DeviceParamTime;
	ES_DEVICE_PARAM_TYPE_SD_RECORD	= 19,	//SD��¼�����:	ES_DeviceParamSDRecord;
	ES_DEVICE_PARAM_TYPE_IMAGE_DEFAULT = 20,	//�ָ�Ĭ��ͼ�����;
	ES_DEVICE_PARAM_TYPE_CRUISE		= 21,	//Ѳ��״̬:		ES_DeviceParamCruise;
	ES_DEVICE_PARAM_TYPE_DEVICE_TYPE = 22,	//�豸����:		ES_DeviceParamDeviceType;
	ES_DEVICE_PARAM_TYPE_UNVIEWED_ALARMS = 23,	//δ�鿴�ı���: ES_DeviceParamUnviewedAlarms;
	ES_DEVICE_PARAM_TYPE_WIFI_AP	= 24,	//�豸AP����:	ES_DeviceParamWiFiAP;
	ES_DEVICE_PARAM_TYPE_STARTUP	= 25,	//��������:		ES_DeviceParamStartup;
	ES_DEVICE_PARAM_TYPE_RECORD		= 26,	//¼������:		ES_DeviceParamRecord;
	ES_DEVICE_PARAM_TYPE_BATTERY	= 27,	//��ز���:		ES_DeviceParamBattery;
	ES_DEVICE_PARAM_TYPE_ISP		= 28,	//ISP����:		ES_DeviceParamIsp;
	ES_DEVICE_PARAM_TYPE_DEVICE_ID	= 29,	//�豸ID;		ES_DeviceParamDeviceID;
	ES_DEVICE_PARAM_TYPE_IP			= 30,	//�豸IP;		ES_DeviceParamIP;
	ES_DEVICE_PARAM_TYPE_RECORD_RESOLUTION	= 31,	//¼��ֱ���;	ES_DeviceParamRecordResolution;
	ES_DEVICE_PARAM_TYPE_TIME_LAPSE	= 32,	//��ʱ¼Ӱ״̬;	ES_DeviceParamTimeLapse;
	ES_DEVICE_PARAM_TYPE_BIT_RATE	= 33,	//����;			ES_DeviceParamBitRate;
	ES_DEVICE_PARAM_TYPE_SEARCH		= 34,	//����;			ES_DeviceParamSearch;
	ES_DEVICE_PARAM_TYPE_SILENT		= 35,	//��Ĭģʽ;		ES_DeviceParamSilent;
	ES_DEVICE_PARAM_TYPE_COUNTRY	= 36,	//����;			ES_DeviceParamCountry;
	ES_DEVICE_PARAM_TYPE_ENCRYPTION	= 37,	//����;			ES_DeviceParamEncryption;
	ES_DEVICE_PARAM_TYPE_OSD		= 38,	//OSD;			ES_DeviceParamOSD;
	ES_DEVICE_PARAM_TYPE_TIME_OFF	= 40,	//��ʱ�ػ�;		ES_DeviceParamTimeOff;
	ES_DEVICE_PARAM_TYPE_WIFI_V2	= 41,	//Wifi����:		ES_DeviceParamWifi_V2;
	
	ES_DEVICE_PARAM_TYPE_REBOOT				= 0x100,	//�����豸;
	ES_DEVICE_PARAM_TYPE_KILL				= 0x101,	//��������;
	ES_DEVICE_PARAM_TYPE_FACTORY			= 0x102,	//�ָ���������;
	ES_DEVICE_PARAM_TYPE_RESTART_NETWORK	= 0x103,	//��������;
	ES_DEVICE_PARAM_TYPE_DEFECT_PIXEL		= 0x105,	//����У��;


	ES_DEVICE_PARAM_TYPE_TM_VIDEO_RESOLUTION	= 0x1001,	//¼��ֱ���;	ES_DeviceParamTMVideoResolution;
	ES_DEVICE_PARAM_TYPE_TM_LOOPING_VIDEO		= 0x1002,	//��Ƶ�ֶ�;		ES_DeviceParamTMLoopingVideo;
	ES_DEVICE_PARAM_TYPE_TM_OSD_ON				= 0x1003,	//ʱ��ˮӡ;		ES_DeviceParamTMOsdOn;
	ES_DEVICE_PARAM_TYPE_TM_NETWORK_AP			= 0x1004,	//WiFi;			ES_DeviceParamTMNetworkAP;
	ES_DEVICE_PARAM_TYPE_TM_FLICKER_FREQUENCY	= 0x1005,	//��ԴƵ��;		ES_DeviceParamTMFlickerFrequency;
	ES_DEVICE_PARAM_TYPE_TM_GSENSOR_SENSITIVITY	= 0x1006,	//������Ӧ;		ES_DeviceParamTMGSensorSensitivity;

	ES_DEVICE_PARAM_TYPE_TM_TIME				= 0x1007,	//ʱ��;			ES_DeviceParamTMTime;
	ES_DEVICE_PARAM_TYPE_TM_TV					= 0x1008,	//CVBS;			ES_DeviceParamTMTV;

	ES_DEVICE_PARAM_TYPE_NT_SSID				= 0x2001,	//���������;	ES_DeviceParamNTSSID;
	ES_DEVICE_PARAM_TYPE_NT_PASSWORD			= 0x2002,	//���������;	ES_DeviceParamNTPassword;
	ES_DEVICE_PARAM_TYPE_NT_AUTO_RECORDING		= 0x2003,	//�Զ�¼��;		ES_DeviceParamNTAutoRecording;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_DATE_IN_PRINT	= 0x2004,	//¼��ʱ��;		ES_DeviceParamNTMovieDateInPrint;
	ES_DEVICE_PARAM_TYPE_NT_TV_FORMAT			= 0x2005,	//����ģʽ;		ES_DeviceParamNTTVFormat;
	ES_DEVICE_PARAM_TYPE_NT_CAPTURE_SIZE		= 0x2006,	//��Ƭ��С;		ES_DeviceParamNTCaptureSize;
	ES_DEVICE_PARAM_TYPE_NT_GSENSOR_SENSITIVITY	= 0x2007,	//��ײ��Ӧ������;	ES_DeviceParamNTGSensorSensitivity;
	ES_DEVICE_PARAM_TYPE_NT_CYCLIC_RECORD		= 0x2008,	//¼���ļ�ʱ��;	ES_DeviceParamNTCyclicRecord;
	ES_DEVICE_PARAM_TYPE_NT_MOTION_DETECTION	= 0x2009,	//�ƶ����;		ES_DeviceParamNTMotionDetection;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_RECORD_BITRATE	= 0x2010,	//¼������;	ES_DeviceParamNTMovieRecordBitrate;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_RECORD_SIZE	= 0x2011,	//¼��ֱ���;	ES_DeviceParamNTMovieRecordSize;

	ES_DEVICE_PARAM_TYPE_TI_TIME				= 0x3000,	//ʱ��;			ES_DeviceParamTITime;
	ES_DEVICE_PARAM_TYPE_TI_RECORD_TIME			= 0x3001,	//¼��ʱ��;		ES_DeviceParamTIRecordTime;
	ES_DEVICE_PARAM_TYPE_TI_GSENSOR_SENSITIVITY	= 0x3002,	//G-Sensor������;	ES_DeviceParamTIGSensorSensitivity;
	ES_DEVICE_PARAM_TYPE_TI_SUBTITLE			= 0x3003,	//��Ļ;			ES_DeviceParamTISubtitle;
	ES_DEVICE_PARAM_TYPE_TI_MIC					= 0x3004,	//mic����;		ES_DeviceParamTIMic;
	ES_DEVICE_PARAM_TYPE_TI_RTSP_RESOLUTION		= 0x3005,	//RTSP��Ƶ�ֱ���;	ES_DeviceParamTIRtspResolution;
	ES_DEVICE_PARAM_TYPE_TI_RECORD_RESOLUTION	= 0x3006,	//¼��ֱ���;	ES_DeviceParamTIRecordResolution;
	ES_DEVICE_PARAM_TYPE_TI_RADAR				= 0x3007,	//�״�;			ES_DeviceParamTIRadar;
	ES_DEVICE_PARAM_TYPE_TI_EDOG				= 0x3008,	//���ӹ�;		ES_DeviceParamTIEDog;
	ES_DEVICE_PARAM_TYPE_TI_BEEP				= 0x3009,	//beep����;		ES_DeviceParamTIBeep;
	ES_DEVICE_PARAM_TYPE_TI_DELAY_POWER_OFF		= 0x3010,	//��ʱ�ػ�;		ES_DeviceParamTIDelayPowerOff;
	ES_DEVICE_PARAM_TYPE_TI_GPS_INFO			= 0x3011,	//GPS������Ϣ;	ES_DeviceParamTIGPSInfo;
	ES_DEVICE_PARAM_TYPE_TI_DATA_VERSION		= 0x3012,	//���ݰ汾;		ES_DeviceParamTIDataVersion;

	ES_DEVICE_PARAM_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_PARAM_TYPE;


//��Ƶ��������;
typedef enum ES_VIDEO_TYPE
{
	ES_VIDEO_TYPE_H264	= 0,
	ES_VIDEO_TYPE_H265	= 1,

	ES_VIDEO_TYPE_UNKNOWN = 0xFFFFFFFF,
} ES_VIDEO_TYPE;


//��Ƶ��������;
typedef enum ES_AUDIO_TYPE
{
	ES_AUDIO_TYPE_AAC	= 0,
	ES_AUDIO_TYPE_PCM	= 1,

	ES_AUDIO_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_AUDIO_TYPE;


//��ý���ļ���Ϣ;
typedef struct ES_FileInfo
{
	int videoCount;				//��Ƶ��֡��;
	int fps;					//֡��;
	int width;					//��Ƶ��;
	int height;					//��Ƶ��;
	ES_VIDEO_TYPE videoType;	//��Ƶ��������;

	int numberOfChannels;		//��Ƶͨ����;
	int sampleSize;				//��Ƶ������С;
	int sampleRate;				//��Ƶ������;
	ES_AUDIO_TYPE audioType;	//��Ƶ��������;

} ES_FileInfo;


//��Ƶ�ļ�GPS��Ϣ;
typedef struct ES_GPSInfo
{
	ES_DateTime dateTime;
	double longitude;	//���ȣ����ж���Ϊ����������Ϊ����;
	double latitude;	//γ�ȣ����б�γΪ��������γΪ����;
	double speed;		//�ٶ�;
	double x;			//G-Sensor X;
	double y;			//G-Sensor Y;
	double z;			//G-Sensor Z;

} ES_GPSInfo;


//������Ϣ;
typedef struct ES_SatelliteInfo
{
	int id;		//���Ǳ��;
	int signal;	//�ź�����;
	int used;	//�Ƿ�Ϊ���ڶ�λ����Ч��;

} ES_SatelliteInfo;


//������Ϣ�б�;
typedef struct ES_SatelliteInfoList
{
	int count;	//���Ǹ���;
	ES_SatelliteInfo infos[64];	//������Ϣ;

} ES_SatelliteInfoList;


//Զ��¼����Ϣ;
typedef struct ES_MediaInfo
{
	ES_MediaType mediaType;
	char name[ES_REMOTE_RECORD_NAME_MAX_LEN];
	char path[ES_PATH_MAX_LEN];
	ES_DateTime mediaStartTime;	//¼��ʼʱ��;
	int mediaCount;				//¼����Ƶ֡��;
	int mediaFPS;				//¼����Ƶ֡��;
	int mediaTotalSize;			//¼���ܴ�С;

} ES_MediaInfo;


//�豸Wifi����: ES_DEVICE_PARAM_TYPE_WIFI;
typedef struct ES_DeviceParamWifi
{
	char name[ES_WIFI_NAME_LEN];			//SSID;
	char password[ES_WIFI_PASSWORD_LEN];	//����;
	char security[ES_WIFI_SECURITY_LEN];	//���ܷ�ʽ;
	int level;	//�ź�ǿ��;
	int wep_key_index;	//WEP���ܷ�ʽ����Կindex;

} ES_DeviceParamWifi;


//�豸Wifi����: ES_DEVICE_PARAM_TYPE_WIFI_V2;
typedef struct ES_DeviceParamWifi_V2
{
	char name[ES_WIFI_NAME_LEN];			//SSID;
	char password[ES_WIFI_PASSWORD_LEN];	//����;
	char security[ES_WIFI_SECURITY_LEN];	//���ܷ�ʽ;
	int level;	//�ź�ǿ��;
	int wep_key_index;	//WEP���ܷ�ʽ����Կindex;
	
	char bStatic;				//�Ƿ�̬����IP;
	char resv[3];
	char ip[ES_IP_LEN];			//IP��ַ;
	char subnet[ES_IP_LEN];		//��������;
	char gateway[ES_IP_LEN];	//����;

	char bDNS;					//�Ƿ���Ҫ�ֶ�����DNS;
	char resv2[3];
	char dns1[ES_IP_LEN];		//��ѡDNS;
	char dns2[ES_IP_LEN];		//��ѡDNS;

} ES_DeviceParamWifi_V2;


//�豸���Ʋ���: ES_DEVICE_PARAM_TYPE_NAME;
typedef struct ES_DeviceParamName
{
	char name[ES_DEVICE_NAME_MAX_LEN];

} ES_DeviceParamName;


//�ƶ����������;
typedef enum ES_DEVICE_MOTION_LEVEL
{
	ES_DEVICE_MOTION_LEVEL_LOW		= 0,	//��;
	ES_DEVICE_MOTION_LEVEL_MEDIUM	= 1,	//��;
	ES_DEVICE_MOTION_LEVEL_HIGH		= 2,	//��;

	ES_DEVICE_MOTION_LEVEL_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_MOTION_LEVEL;


//GPIO��������;
typedef enum ES_DEVICE_ALARM_TYPE
{
	ES_DEVICE_ALARM_TYPE_OPEN		= 0,	//����;
	ES_DEVICE_ALARM_TYPE_CLOSE		= 1,	//����;

	ES_DEVICE_ALARM_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_ALARM_TYPE;


//�������: ES_DEVICE_PARAM_TYPE_ALARM;
typedef struct ES_DeviceParamAlarm
{
	char isMotionValid;		//�ƶ�����Ƿ���;
	char isPIRValid;		//PIR�Ƿ���;
	char isInputValid;		//���������Ƿ���;
	char isOutputValid;		//��������Ƿ���;

	char resv[84];

	ES_DEVICE_MOTION_LEVEL level;		//�ƶ���������ȵȼ�;
	ES_DEVICE_ALARM_TYPE inputType;		//�������뱨������;
	ES_DEVICE_ALARM_TYPE outputType;	//���������������;

} ES_DeviceParamAlarm;


//SD���洢״̬;
typedef enum ES_DEVICE_SD_STORAGE_TYPE
{
	ES_DEVICE_SD_STORAGE_TYPE_NO_CARD   = 0,    //δ�忨;
	ES_DEVICE_SD_STORAGE_TYPE_RECORDING = 1,    //¼����;
	ES_DEVICE_SD_STORAGE_TYPE_IDLE		= 2,	//������;

	ES_DEVICE_SD_STORAGE_TYPE_UNKNOWN   = 0xFFFFFFFF,
} ES_DEVICE_SD_STORAGE_TYPE;


//�洢״̬����: ES_DEVICE_PARAM_TYPE_STORAGE;
typedef struct ES_DeviceParamStorage
{
	char has_sd;							//�Ƿ���SD��;
	char resv[3];
	ES_DEVICE_SD_STORAGE_TYPE sd_type;		//SD��״̬;
	unsigned long long sd_total_capacity;	//SD��������;
	unsigned long long sd_free_capacity;	//SD����ǰ����;

} ES_DeviceParamStorage;


//�豸�汾����: ES_DEVICE_PARAM_TYPE_VERSION;
typedef struct ES_DeviceParamVersion
{
	char version[ES_VERSION_MAX_LEN];

} ES_DeviceParamVersion;


//�������: ES_DEVICE_PARAM_TYPE_PASSWORD;
typedef struct ES_DeviceParamPassword
{
	char pwd_md5[ES_PWD_MD5_LEN];

} ES_DeviceParamPassword;


//�������: ES_DEVICE_PARAM_TYPE_MIRROR;
typedef struct ES_DeviceParamMirror
{
	char vertical;		//��ֱ����;
	char horizontal;	//ˮƽ����;
	char resv[2];

} ES_DeviceParamMirror;


//���Ȳ���: ES_DEVICE_PARAM_TYPE_BRIGHTNESS;
typedef struct ES_DeviceParamBrightness
{
	int value;		//ȡֵ��Χ0-255;

} ES_DeviceParamBrightness;


//ɫ�Ȳ���: ES_DEVICE_PARAM_TYPE_CHROMA;
typedef struct ES_DeviceParamChroma
{
	int value;		//ȡֵ��Χ0-255;

} ES_DeviceParamChroma;


//�ԱȶȲ���: ES_DEVICE_PARAM_TYPE_CONTRAST;
typedef struct ES_DeviceParamContrast
{
	int value;		//ȡֵ��Χ0-255;

} ES_DeviceParamContrast;


//���ͶȲ���: ES_DEVICE_PARAM_TYPE_SATURATION;
typedef struct ES_DeviceParamSaturation
{
	int value;		//ȡֵ��Χ0-255;

} ES_DeviceParamSaturation;


//��Ȳ���: ES_DEVICE_PARAM_TYPE_SHARPNESS;
typedef struct ES_DeviceParamSharpness
{
	int value;		//ȡֵ��Χ0-255;

} ES_DeviceParamSharpness;


//�����������: ES_DEVICE_PARAM_TYPE_NETWORK;
typedef struct ES_DeviceParamNetwork
{
	char bStatic;				//�Ƿ�̬����IP;
	char resv[3];
	char ip[ES_IP_LEN];			//IP��ַ;
	char subnet[ES_IP_LEN];		//��������;
	char gateway[ES_IP_LEN];	//����;

	char bDNS;					//�Ƿ���Ҫ�ֶ�����DNS;
	char resv2[3];
	char dns1[ES_IP_LEN];		//��ѡDNS;
	char dns2[ES_IP_LEN];		//��ѡDNS;

} ES_DeviceParamNetwork;


//Wi-Fi�б�: ES_DEVICE_PARAM_TYPE_WIFILIST;
typedef struct ES_DeviceParamWiFiList
{
	int count;
	int wifiStruSize;	//ES_DeviceParamWifi�Ľṹ���С

} ES_DeviceParamWiFiList;


//ʱ������� ES_DEVICE_PARAM_TYPE_TIME;
typedef struct ES_DeviceParamTime
{
	char bAuto;		//�Ƿ��Զ�ʱ��У׼;
	char resv[3];

	ES_DateTime dateTime;	//ʱ�䣬�ر��Զ�ʱ��У׼ʱ�ſ�������;
	int timeZone;			//ʱ���������Զ�ʱ��У׼ʱ�ſ������� +8:00  8*60*60;

} ES_DeviceParamTime;


//SD��¼�����: ES_DEVICE_PARAM_TYPE_SD_RECORD
typedef struct ES_DeviceParamSDRecord
{
	char bAlarmRecord;	//�Ƿ�������¼��;
	char bTimeRecord;	//�Ƿ�����ʱ¼��;
	char resv[2];

	int time;			//��ǰ¼��ʱ��;
	int duration;		//��¼��ʱ������λ��;
	char resv2[76];

} ES_DeviceParamSDRecord;


//Ѳ������: ES_DEVICE_PARAM_CRUISE;
typedef struct ES_DeviceParamCruise
{
	char bLRCruise;		//�Ƿ�������Ѳ��;
	char bUDCruise;		//�Ƿ�������Ѳ��;
	char resv[2];

} ES_DeviceParamCruise;


//�豸����: ES_DEVICE_PARAM_DEVICE_TYPE;
typedef struct ES_DeviceParamDeviceType
{
	ES_DEVICE_TYPE deviceType;

} ES_DeviceParamDeviceType;


//δ�鿴�ı���: ES_DEVICE_PARAM_UNVIEWED_ALARMS;
typedef struct ES_DeviceParamUnviewedAlarms
{
	char hasUnviewedAlarms;	//�Ƿ���δ�鿴�ı���;
	char resv[3];

} ES_DeviceParamUnviewedAlarms;


//�Զ��ر�WiFi;
typedef enum ES_AUTO_CLOSE_WIFI_TYPE
{
	ES_AUTO_CLOSE_WIFI_TYPE_CLOSE	= 0,	//���Զ��ر�WiFi;
	ES_AUTO_CLOSE_WIFI_TYPE_60		= 60,	//1����;
	ES_AUTO_CLOSE_WIFI_TYPE_180		= 180,	//3����;
	ES_AUTO_CLOSE_WIFI_TYPE_300		= 300,	//5����;

	ES_AUTO_CLOSE_WIFI_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_AUTO_CLOSE_WIFI_TYPE;


//�豸AP����;
typedef struct ES_DeviceParamWiFiAP
{
	char name[ES_WIFI_NAME_LEN];
	char password[ES_WIFI_PASSWORD_LEN];

	ES_AUTO_CLOSE_WIFI_TYPE	autoCloseWiFi;	//�Զ��ر�WiFi;

} ES_DeviceParamWiFiAP;


//�Զ�����ʱ����;
typedef enum ES_AUTO_PHOTO_INTERVAL
{
	ES_AUTO_PHOTO_INTERVAL_3		= 3,	//3��;
	ES_AUTO_PHOTO_INTERVAL_10	= 10,	//10��;
	ES_AUTO_PHOTO_INTERVAL_15	= 15,	//15��;
	ES_AUTO_PHOTO_INTERVAL_20	= 20,	//20��;
	ES_AUTO_PHOTO_INTERVAL_30	= 30,	//30��;

	ES_AUTO_PHOTO_INTERVAL_UNKNOWN	= 0xFFFFFFFF,
} ES_AUTO_PHOTO_INTERVAL;


//��������;
typedef struct ES_DeviceParamStartup
{
	char autoRecord;	//�����Զ�¼��;
	char autoPhoto;		//�����Զ�����;
	char resv[2];

	ES_AUTO_PHOTO_INTERVAL autoPhotoInterval;	//����ʱ����;
} ES_DeviceParamStartup;


//¼������;
typedef struct ES_DeviceParamRecord
{
	char cycle;		//ѭ��¼Ӱ;
	char resv[3];

} ES_DeviceParamRecord;


//���״̬����;
typedef enum ES_DEVICE_PARAM_BATTERY_STATE
{
	ES_DEVICE_PARAM_BATTERY_STATE_IDLE		= 0,	//����;
	ES_DEVICE_PARAM_BATTERY_STATE_CHARGING	= 1,	//�����;

	ES_DEVICE_PARAM_BATTERY_STATE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_PARAM_BATTERY_STATE;


//��ز���;
typedef struct ES_DeviceParamBattery
{
	ES_DEVICE_PARAM_BATTERY_STATE batteryState;	//���״̬;
	unsigned int batteryPower;	//����;

} ES_DeviceParamBattery;


//ISP����;
typedef struct ES_DeviceParamIsp
{
	unsigned char ISPDGain; 
	unsigned char SysGain; 
	unsigned char DRC_enable; 
	unsigned char DNR_enable;

} ES_DeviceParamIsp;


//�豸ID;
typedef struct ES_DeviceParamDeviceID
{
	char deviceID[ES_DEVICE_ID_MAX_LEN];

} ES_DeviceParamDeviceID;


//���Բ���: ES_LCT_LANGUAGE;
typedef struct ES_DeviceParamLanguage
{
	ES_LANGUAGE_TYPE language;

} ES_DeviceParamLanguage;


//���ܲ���: ES_LCT_ENCRYPTION;
typedef struct ES_DeviceParamEncryption
{
	unsigned char codes[ES_ENCRYPTION_CODE_LEN];

} ES_DeviceParamEncryption;


typedef struct ES_DeviceParamIP
{
	char lanIP[ES_IP_LEN];	//����IP;
	char wifiIP[ES_IP_LEN];	//����IP;

} ES_DeviceParamIP;


typedef enum ES_RESOLUTION_TYPE
{
	ES_RESOLUTION_TYPE_1920_1080	= 0,	//1080P;
	ES_RESOLUTION_TYPE_1280_720		= 1,	//720P;
	ES_RESOLUTION_TYPE_640_360		= 2,	//360P;

	ES_RESOLUTION_TYPE_Unknown		= 0xFFFFFFFF,
} ES_RESOLUTION_TYPE;


//¼��ֱ���;
typedef struct ES_DeviceParamRecordResolution
{
	ES_RESOLUTION_TYPE recordResolution;
	
} ES_DeviceParamRecordResolution;


//��ʱ¼Ӱ״̬;
typedef struct ES_DeviceParamTimeLapse
{
	char isRecord;	//�Ƿ�������ʱ¼Ӱ;
	char resv[3];
	int recordTime;	//¼��ʱ��;
	int realTime;	//��ʵʱ��;

} ES_DeviceParamTimeLapse;


//����;
typedef struct ES_DeviceParamBitRate
{
	ES_StreamType streamType;	//��������;
	int bit_rate;				//���ʣ���λbps;
	
} ES_DeviceParamBitRate;


//������Ϣ;
typedef struct ES_SearchData
{
	char deviceID[ES_DEVICE_ID_MAX_LEN];		//�豸ID;
	ES_DEVICE_TYPE deviceType;					//�豸����;
	char deviceName[ES_DEVICE_NAME_MAX_LEN];	//�豸����;
	char lanIP[ES_IP_LEN];						//����IP;
	unsigned char lanMAC[ES_MAC_LEN];			//����MAC;
	unsigned char resv1[2];						//����;
	char wifiSSID[ES_WIFI_NAME_LEN];			//����SSID;
	unsigned char wifiMAC[ES_MAC_LEN];			//����MAC;
	unsigned char resv2[2];						//����;
	char kernelVersion[ES_VERSION_MAX_LEN];		//�ں˰汾;
	char appVersion[ES_VERSION_MAX_LEN];		//����汾;
	ES_DEVICE_SD_STORAGE_TYPE deviceSDType;		//SD��״̬;
	unsigned long long sd_total_capacity;		//SD��������;
	unsigned char factoryStatus;				//0 - δ֪;  1 - ����״̬;   2 - �ǳ���״̬;
	unsigned char defectPixelStatus;			//0 - δ֪;  1 - �Ѿ�����У��;  2 - δ���л���У��;
	unsigned char resv3[2];						//����;
	ES_LANGUAGE_TYPE language;					//����;
	unsigned char encryption;					//0 - δ֪;  1 - �Ѿ�����;   2 - δ����;
	unsigned char resv4[3];						//����;

} ES_SearchData;


typedef struct ES_DeviceParamSearch
{
	ES_SearchData searchData;

} ES_DeviceParamSearch;


//��Ĭģʽ;
typedef struct ES_DeviceParamSilent
{
	char silent;	//�Ƿ�Ĭ;
	char resv[3];
	
} ES_DeviceParamSilent;


//����;
typedef struct ES_DeviceParamCountry
{
	char country[4];	//���Ҵ��룬���й���CN;
	
} ES_DeviceParamCountry;


//OSDʱ���ʽ;
typedef enum OSD_TIME_FORMAT
{
	OSD_TIME_FORMAT_YYYYmmDDHHMMSS	= 1,
	
	OSD_TIME_FORMAT_UNKNOWN = 0xFFFFFFFF,
} OSD_TIME_FORMAT;


//OSD;
typedef struct ES_DeviceParamOSD
{
	char isShowTime;
	char isShowOSD1;
	char isShowOSD2;
	char isShowOSD3;
	OSD_TIME_FORMAT timeFormat;
	char osd1[ES_OSD_MAX_LEN];
	char osd2[ES_OSD_MAX_LEN];
	char osd3[ES_OSD_MAX_LEN];
	
} ES_DeviceParamOSD;


//��ʱ�ػ����ڲ�¼��ʱ�û� x �벻�����豸���豸�Զ��ػ���;
typedef struct ES_DeviceParamTimeOff
{
	int timeoff;	//��λ���룬���� 0 ��ʾ���ػ�;

} ES_DeviceParamTimeOff;


#endif
