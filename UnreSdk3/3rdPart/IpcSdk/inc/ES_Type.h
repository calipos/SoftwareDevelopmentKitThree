
#ifndef __ESONG_ES_TYPE_H_INC__
#define __ESONG_ES_TYPE_H_INC__

typedef enum ES_ERROR_CODE
{
	ES_ERROR_SUCCESS			= 0,	//成功;
	ES_ERROR_USER_OR_PWD_ERROR	= 1,	//用户名或密码错误;
	ES_ERROR_NETWORK_ERROR		= 2,	//网络错误;
	ES_ERROR_SESSION_NOT_FOUND	= 3,	//设备句柄不存在;
	ES_ERROR_OPERATOR_FAILED	= 4,	//操作失败;
	ES_ERROR_BAD_ALLOC			= 5,	//内存分配失败;
	ES_ERROR_RECV_WRONG_DATA	= 6,	//接收到数据错误;
	ES_ERROR_HAS_NO_ABILITY		= 7,	//没有该能力;
	ES_ERROR_MAX_CLIENTS		= 8,	//连接数上限;
	ES_ERROR_INVALID_PARAM		= 9,	//无效参数;
	ES_ERROR_REMOTE_CLOSED		= 10,	//远程已经关闭;
	ES_ERROR_DEVICE_TYPE_MISMATCH	= 11,	//设备类型不匹配;
	ES_ERROR_FORBID_OPERATION		= 12,   //禁止操作;
	ES_ERROR_NOT_INITIALIZED	= 13,	//未初始化;
	
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

	ES_ERROR_RECV_TIMEOUT			= 0xFFFFFFFB,	//接收数据超时;
	ES_ERROR_RECV_DATA_NOT_COMPLETE	= 0xFFFFFFFC,	//数据未接收完全;
	ES_ERROR_RECV_NONE	= 0xFFFFFFFD,	//没有接收到数据;
	ES_ERROR_SDK_ERROR	= 0xFFFFFFFE,	//SDK出错;
	ES_ERROR_UNKNOWN	= 0xFFFFFFFF,	//未知错误;

} ES_ERROR_CODE;


typedef enum ES_DEVICE_TYPE
{
	//PP
	ES_DEVICE_TYPE_SIMULATION	= 1,	//模拟摄像机;
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
	ES_DEVICE_TYPE_PEN			= 400,	//录像笔;
    
	//TM
    ES_DEVICE_TYPE_ESR302       = 500,	//升迈设备;
    
	//GP
    ES_DEVICE_TYPE_ESR301       = 600,	//凌通设备;

	//TI
	ES_DEVICE_TYPE_ERD402		= 700,	//海思三合一设备;

	//FR
	ES_DEVICE_TYPE_K20			= 800,	//人脸检测设备;

	ES_DEVICE_TYPE_UNKNOWN = 0xFFFFFFFF,	//未知设备;

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
	ES_ABILITY_TYPE_PTZ		= 1,	//云台功能;
	ES_ABILITY_TYPE_TALK	= 2,	//对讲功能;
	ES_ABILITY_TYPE_SD		= 3,	//标清码流;

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


enum { ES_WIFI_NAME_LEN = 32 };			//Wifi名称长度;
enum { ES_WIFI_PASSWORD_LEN = 32 };		//Wifi密码长度;
enum { ES_WIFI_SECURITY_LEN = 64 };		//WiFi加密方式长度;
enum { ES_DEVICE_NAME_MAX_LEN = 64 };   //设备名称最大长度;
enum { ES_DEVICE_ID_MAX_LEN	= 20 };		//设备ID最大长度;
enum { ES_REMOTE_RECORD_NAME_MAX_LEN = 32 };	//远程录像名称最大长度;
enum { ES_PATH_MAX_LEN = 128 };			//路径最大长度;
enum { ES_VERSION_MAX_LEN = 32 };			//设备版本号最大长度;
enum { ES_PWD_MD5_LEN = 36 };	//MD5加密后的密码长度;
enum { ES_UUID_MAX_LEN = 40 };	//UUID最大长度;
enum { ES_IP_LEN = 16 };	//IP地址长度;
enum { ES_MAC_LEN = 6 };	//MAC地址长度;
enum { ES_MAX_CLIENTS = 4 };	//客户端最大数量;
enum { ES_ENCRYPTION_CODE_LEN = 16 };	//设备端加密密钥长度;
enum { ES_OSD_MAX_LEN = 256 };	//OSD最大长度;
enum { ES_DEVICE_FONT_MAX_SIZE = 128*32*32/4 };	//设备端字库最大长度;


//设备状态;
typedef enum ES_DEVICE_STATE
{
	ES_DEVICE_STATE_CONNECTED		= 0,	//设备连接成功;
	ES_DEVICE_STATE_PASSWORD_ERROR	= 1,	//密码错误;
	ES_DEVICE_STATE_MAX_CLIENTS		= 2,	//连接数上限;
	ES_DEVICE_STATE_OFFLINE			= 3,	//离线;
	ES_DEVICE_STATE_NETWORK_ERROR	= 4,	//网络超时;
	ES_DEVICE_STATE_INVALID_ID		= 5,	//设备ID无效;
	ES_DEVICE_STATE_DISCONNECTED	= 6,	//设备断开连接成功;

	ES_DEVICE_STATE_BATTERY_CHARGING	= 0x100,	//电池充电中;
	ES_DEVICE_STATE_BATTERY_IDLE		= 0x101,	//电池空闲中;

	ES_DEVICE_STATE_RECORD_RECORDING	= 0x200,	//循环录影中;
	ES_DEVICE_STATE_RECORD_IDLE			= 0x201,	//循环录影空闲中;

	ES_DEVICE_STATE_EDOG_UPDATE_SUCCESS	= 0x301,	//电子狗数据升级成功;
	ES_DEVICE_STATE_EDOG_UPDATE_FAILED	= 0x302,	//电子狗数据升级失败;

	ES_DEVICE_STATE_UNKNOWN		= 0xFFFFFFFF,
} ES_DEVICE_STATE;


//摄像机升级类型;
typedef enum ES_DEVICE_UPDATE_TYPE
{
	ES_DEVICE_UPDATE_TYPE_KERNEL	= 0,
	ES_DEVICE_UPDATE_TYPE_ROOTFS	= 1,
	ES_DEVICE_UPDATE_TYPE_APP		= 2,
	ES_DEVICE_UPDATE_TYPE_DEVICEID	= 3,	//设备ID;
	ES_DEVICE_UPDATE_TYPE_EDOG_DATA	= 4,	//电子狗数据;

	ES_DEVICE_UPDATE_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_UPDATE_TYPE;


//摄像机语言类型;
typedef enum ES_LANGUAGE_TYPE
{
	ES_LANGUAGE_TYPE_DEFAULT	= 0,
	ES_LANGUAGE_TYPE_CHINESE	= 1,
	ES_LANGUAGE_TYPE_ENGLISH	= 2,

	ES_LANGUAGE_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_LANGUAGE_TYPE;


//码流类型;
typedef enum ES_StreamType
{ 
	ES_ST_HD			= 0,	//高清;
	ES_ST_BALANCE		= 1,	//均衡;
	ES_ST_SMOOTH		= 2,	//流畅;

	ES_ST_UNKNOWN = 0xFFFFFFFF 
} ES_StreamType;


//媒体类型;
typedef enum ES_MediaType
{
	ES_MT_TIMER			= 0,	//定时录像;
	ES_MT_ALARM			= 1,	//报警录像;
	ES_MT_TIME_LAPSE	= 2,	//缩时录影;
	ES_MT_MANUAL_RECORD	= 3,	//用户手动录像;
	ES_MT_MANUAL_IMAGE	= 4,	//用户手动拍照;

	ES_MT_RECORDING		= 0x100,	//正在录像的视频;

	ES_MT_UNKNOWN = 0xFFFFFFFF,
} ES_MediaType;


//下载状态;
typedef enum ES_DOWNLOAD_STATE
{
	ES_DOWNLOAD_STATE_RUNNING	= 0,
	ES_DOWNLOAD_STATE_OK		= 1,
	ES_DOWNLOAD_STATE_STOP		= 2,
	ES_DOWNLOAD_STATE_ERROR		= 3,

	ES_DOWNLOAD_STATE_UNKNOWN	= 0xFFFFFFFF,
} ES_DOWNLOAD_STATE;


//报警类型;
typedef enum ES_AlarmType
{
	ES_AT_MOTION	= 0,	//移动侦测;
	ES_AT_GPIO		= 1,	//GPIO报警;
	ES_AT_PIR		= 2,	//人体感应;

	ES_AT_UNKNOWN	= 0xFFFFFFFF,
} ES_AlarmType;


//云台控制类型;
typedef enum ES_PTZ_CONTROL_TYPE
{
	ES_PTZ_CONTROL_TYPE_STOP		= 0,	//停止;
	ES_PTZ_CONTROL_TYPE_UP		= 1,	//上;
	ES_PTZ_CONTROL_TYPE_DOWN		= 2,	//下;
	ES_PTZ_CONTROL_TYPE_LEFT		= 3,	//左;
	ES_PTZ_CONTROL_TYPE_RIGHT	= 4,	//右;

	ES_PTZ_CONTROL_TYPE_OPEN_LR_CRUISE	= 0x10,	//开启左右巡航;
	ES_PTZ_CONTROL_TYPE_CLOSE_LR_CRUISE	= 0x11,	//关闭左右巡航;
	ES_PTZ_CONTROL_TYPE_OPEN_UD_CRUISE	= 0x12,	//开启上下巡航;
	ES_PTZ_CONTROL_TYPE_CLOSE_UD_CRUISE	= 0x13,	//关闭上下巡航;

	ES_PTZ_CONTROL_TYPE_SET_PRESET		= 0x20,	//设置预置位;
	ES_PTZ_CONTROL_TYPE_CALL_PRESET		= 0x21,	//调用预置位;

} ES_PTZ_CONTROL_TYPE;



//局域网控制类型;
typedef enum ES_LanControlType
{
	ES_LCT_LIGHT_FAST	= 0,	//状态灯快闪;
	ES_LCT_LIGHT_NORMAL	= 1,	//状态灯正常闪;
	ES_LCT_REBOOT		= 2,	//重启设备;
	ES_LCT_FACTORY		= 3,	//恢复出厂;
	ES_LCT_KILL			= 4,	//重启应用程序;
	ES_LCT_DEFECT_PIXEL	= 5,	//坏点校正;
	ES_LCT_LANGUAGE		= 6,	//语言设置	ES_DeviceParamLanguage;
	ES_LCT_ENCRYPTION	= 7,	//加密设置	ES_DeviceParamEncryption;

	ES_LCT_UNKNOWN		= 0xFFFFFFFF,
} ES_LanControlType;


//日志等级;
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


//码流信息;
typedef struct ES_Frame
{
	unsigned int nbframe;
	unsigned int seconds;
	unsigned int useconds;
	unsigned short width;
	unsigned short height;
	unsigned int size;
	unsigned int frame_type : 4;	//帧类型: 0 - 音频    2 - I Frame	3 - P Frame    4 - 字幕;
	unsigned int stream_type : 4;	//如果是音频: 1 - 8000HZ   2 - 44100HZ	3 - 48000HZ;
	unsigned int fps_base : 8; 
	unsigned int fps_interval: 8;
	unsigned int vidcompressor: 2;	//视频压缩格式： 0 - H.264	1 - H.265;
	unsigned int audcompressor: 2;	//音频压缩格式： 1 - PCM		2 - G.711    3 - AAC;
	unsigned int audio_channels: 1;		//音频通道数: 0 - 单通道    1 - 双通道;
	unsigned int audio_sample_size: 1;	//音频样本大小: 0 - 16位    1 - 8位;
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


//设备参数类型;
typedef enum ES_DEVICE_PARAM_TYPE
{
	ES_DEVICE_PARAM_TYPE_WIFI       = 1,	//Wifi参数:		ES_DeviceParamWifi;
	ES_DEVICE_PARAM_TYPE_NAME       = 2,	//设备名称参数:  ES_DeviceParamName;
	ES_DEVICE_PARAM_TYPE_STORAGE    = 4,    //存储状态参数:  ES_DeviceParamStorage;
	ES_DEVICE_PARAM_TYPE_VERSION    = 5,    //设备版本参数:  ES_DeviceParamVersion;
	ES_DEVICE_PARAM_TYPE_PASSWORD	= 8,	//密码参数:		ES_DeviceParamPassword;
	ES_DEVICE_PARAM_TYPE_MIRROR		= 9,	//镜像参数:		ES_DeviceParamMirror;
	ES_DEVICE_PARAM_TYPE_BRIGHTNESS	= 10,	//亮度参数:		ES_DeviceParamBrightness;
	ES_DEVICE_PARAM_TYPE_CHROMA		= 11,	//色度参数:		ES_DeviceParamChroma;
	ES_DEVICE_PARAM_TYPE_CONTRAST	= 12,	//对比度参数:	ES_DeviceParamContrast;
	ES_DEVICE_PARAM_TYPE_SATURATION	= 13,	//饱和度参数:	ES_DeviceParamSaturation;
	ES_DEVICE_PARAM_TYPE_SHARPNESS	= 14,	//锐度参数:		ES_DeviceParamSharpness;
	ES_DEVICE_PARAM_TYPE_NETWORK	= 15,	//有线网络参数:	ES_DeviceParamNetwork;
	ES_DEVICE_PARAM_TYPE_WIFILIST	= 16,	//Wi-Fi列表:		ES_DeviceParamWiFiList;
	ES_DEVICE_PARAM_TYPE_ALARM		= 17,	//活动检测参数:	ES_DeviceParamAlarm;
	ES_DEVICE_PARAM_TYPE_TIME		= 18,	//时间参数:		ES_DeviceParamTime;
	ES_DEVICE_PARAM_TYPE_SD_RECORD	= 19,	//SD卡录像参数:	ES_DeviceParamSDRecord;
	ES_DEVICE_PARAM_TYPE_IMAGE_DEFAULT = 20,	//恢复默认图像参数;
	ES_DEVICE_PARAM_TYPE_CRUISE		= 21,	//巡航状态:		ES_DeviceParamCruise;
	ES_DEVICE_PARAM_TYPE_DEVICE_TYPE = 22,	//设备类型:		ES_DeviceParamDeviceType;
	ES_DEVICE_PARAM_TYPE_UNVIEWED_ALARMS = 23,	//未查看的报警: ES_DeviceParamUnviewedAlarms;
	ES_DEVICE_PARAM_TYPE_WIFI_AP	= 24,	//设备AP参数:	ES_DeviceParamWiFiAP;
	ES_DEVICE_PARAM_TYPE_STARTUP	= 25,	//开机设置:		ES_DeviceParamStartup;
	ES_DEVICE_PARAM_TYPE_RECORD		= 26,	//录像设置:		ES_DeviceParamRecord;
	ES_DEVICE_PARAM_TYPE_BATTERY	= 27,	//电池参数:		ES_DeviceParamBattery;
	ES_DEVICE_PARAM_TYPE_ISP		= 28,	//ISP参数:		ES_DeviceParamIsp;
	ES_DEVICE_PARAM_TYPE_DEVICE_ID	= 29,	//设备ID;		ES_DeviceParamDeviceID;
	ES_DEVICE_PARAM_TYPE_IP			= 30,	//设备IP;		ES_DeviceParamIP;
	ES_DEVICE_PARAM_TYPE_RECORD_RESOLUTION	= 31,	//录像分辨率;	ES_DeviceParamRecordResolution;
	ES_DEVICE_PARAM_TYPE_TIME_LAPSE	= 32,	//缩时录影状态;	ES_DeviceParamTimeLapse;
	ES_DEVICE_PARAM_TYPE_BIT_RATE	= 33,	//码率;			ES_DeviceParamBitRate;
	ES_DEVICE_PARAM_TYPE_SEARCH		= 34,	//搜索;			ES_DeviceParamSearch;
	ES_DEVICE_PARAM_TYPE_SILENT		= 35,	//静默模式;		ES_DeviceParamSilent;
	ES_DEVICE_PARAM_TYPE_COUNTRY	= 36,	//国家;			ES_DeviceParamCountry;
	ES_DEVICE_PARAM_TYPE_ENCRYPTION	= 37,	//加密;			ES_DeviceParamEncryption;
	ES_DEVICE_PARAM_TYPE_OSD		= 38,	//OSD;			ES_DeviceParamOSD;
	ES_DEVICE_PARAM_TYPE_TIME_OFF	= 40,	//定时关机;		ES_DeviceParamTimeOff;
	ES_DEVICE_PARAM_TYPE_WIFI_V2	= 41,	//Wifi参数:		ES_DeviceParamWifi_V2;
	
	ES_DEVICE_PARAM_TYPE_REBOOT				= 0x100,	//重启设备;
	ES_DEVICE_PARAM_TYPE_KILL				= 0x101,	//重启程序;
	ES_DEVICE_PARAM_TYPE_FACTORY			= 0x102,	//恢复出厂设置;
	ES_DEVICE_PARAM_TYPE_RESTART_NETWORK	= 0x103,	//重启网络;
	ES_DEVICE_PARAM_TYPE_DEFECT_PIXEL		= 0x105,	//坏点校正;


	ES_DEVICE_PARAM_TYPE_TM_VIDEO_RESOLUTION	= 0x1001,	//录像分辨率;	ES_DeviceParamTMVideoResolution;
	ES_DEVICE_PARAM_TYPE_TM_LOOPING_VIDEO		= 0x1002,	//视频分段;		ES_DeviceParamTMLoopingVideo;
	ES_DEVICE_PARAM_TYPE_TM_OSD_ON				= 0x1003,	//时间水印;		ES_DeviceParamTMOsdOn;
	ES_DEVICE_PARAM_TYPE_TM_NETWORK_AP			= 0x1004,	//WiFi;			ES_DeviceParamTMNetworkAP;
	ES_DEVICE_PARAM_TYPE_TM_FLICKER_FREQUENCY	= 0x1005,	//电源频率;		ES_DeviceParamTMFlickerFrequency;
	ES_DEVICE_PARAM_TYPE_TM_GSENSOR_SENSITIVITY	= 0x1006,	//重力感应;		ES_DeviceParamTMGSensorSensitivity;

	ES_DEVICE_PARAM_TYPE_TM_TIME				= 0x1007,	//时间;			ES_DeviceParamTMTime;
	ES_DEVICE_PARAM_TYPE_TM_TV					= 0x1008,	//CVBS;			ES_DeviceParamTMTV;

	ES_DEVICE_PARAM_TYPE_NT_SSID				= 0x2001,	//摄像机名称;	ES_DeviceParamNTSSID;
	ES_DEVICE_PARAM_TYPE_NT_PASSWORD			= 0x2002,	//摄像机密码;	ES_DeviceParamNTPassword;
	ES_DEVICE_PARAM_TYPE_NT_AUTO_RECORDING		= 0x2003,	//自动录制;		ES_DeviceParamNTAutoRecording;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_DATE_IN_PRINT	= 0x2004,	//录像时长;		ES_DeviceParamNTMovieDateInPrint;
	ES_DEVICE_PARAM_TYPE_NT_TV_FORMAT			= 0x2005,	//电视模式;		ES_DeviceParamNTTVFormat;
	ES_DEVICE_PARAM_TYPE_NT_CAPTURE_SIZE		= 0x2006,	//照片大小;		ES_DeviceParamNTCaptureSize;
	ES_DEVICE_PARAM_TYPE_NT_GSENSOR_SENSITIVITY	= 0x2007,	//碰撞感应灵敏度;	ES_DeviceParamNTGSensorSensitivity;
	ES_DEVICE_PARAM_TYPE_NT_CYCLIC_RECORD		= 0x2008,	//录制文件时长;	ES_DeviceParamNTCyclicRecord;
	ES_DEVICE_PARAM_TYPE_NT_MOTION_DETECTION	= 0x2009,	//移动侦测;		ES_DeviceParamNTMotionDetection;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_RECORD_BITRATE	= 0x2010,	//录制质量;	ES_DeviceParamNTMovieRecordBitrate;
	ES_DEVICE_PARAM_TYPE_NT_MOVIE_RECORD_SIZE	= 0x2011,	//录像分辨率;	ES_DeviceParamNTMovieRecordSize;

	ES_DEVICE_PARAM_TYPE_TI_TIME				= 0x3000,	//时间;			ES_DeviceParamTITime;
	ES_DEVICE_PARAM_TYPE_TI_RECORD_TIME			= 0x3001,	//录像时长;		ES_DeviceParamTIRecordTime;
	ES_DEVICE_PARAM_TYPE_TI_GSENSOR_SENSITIVITY	= 0x3002,	//G-Sensor灵敏度;	ES_DeviceParamTIGSensorSensitivity;
	ES_DEVICE_PARAM_TYPE_TI_SUBTITLE			= 0x3003,	//字幕;			ES_DeviceParamTISubtitle;
	ES_DEVICE_PARAM_TYPE_TI_MIC					= 0x3004,	//mic开关;		ES_DeviceParamTIMic;
	ES_DEVICE_PARAM_TYPE_TI_RTSP_RESOLUTION		= 0x3005,	//RTSP视频分辨率;	ES_DeviceParamTIRtspResolution;
	ES_DEVICE_PARAM_TYPE_TI_RECORD_RESOLUTION	= 0x3006,	//录像分辨率;	ES_DeviceParamTIRecordResolution;
	ES_DEVICE_PARAM_TYPE_TI_RADAR				= 0x3007,	//雷达;			ES_DeviceParamTIRadar;
	ES_DEVICE_PARAM_TYPE_TI_EDOG				= 0x3008,	//电子狗;		ES_DeviceParamTIEDog;
	ES_DEVICE_PARAM_TYPE_TI_BEEP				= 0x3009,	//beep音量;		ES_DeviceParamTIBeep;
	ES_DEVICE_PARAM_TYPE_TI_DELAY_POWER_OFF		= 0x3010,	//延时关机;		ES_DeviceParamTIDelayPowerOff;
	ES_DEVICE_PARAM_TYPE_TI_GPS_INFO			= 0x3011,	//GPS收星信息;	ES_DeviceParamTIGPSInfo;
	ES_DEVICE_PARAM_TYPE_TI_DATA_VERSION		= 0x3012,	//数据版本;		ES_DeviceParamTIDataVersion;

	ES_DEVICE_PARAM_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_PARAM_TYPE;


//视频编码类型;
typedef enum ES_VIDEO_TYPE
{
	ES_VIDEO_TYPE_H264	= 0,
	ES_VIDEO_TYPE_H265	= 1,

	ES_VIDEO_TYPE_UNKNOWN = 0xFFFFFFFF,
} ES_VIDEO_TYPE;


//音频编码类型;
typedef enum ES_AUDIO_TYPE
{
	ES_AUDIO_TYPE_AAC	= 0,
	ES_AUDIO_TYPE_PCM	= 1,

	ES_AUDIO_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_AUDIO_TYPE;


//多媒体文件信息;
typedef struct ES_FileInfo
{
	int videoCount;				//视频总帧数;
	int fps;					//帧率;
	int width;					//视频宽;
	int height;					//视频高;
	ES_VIDEO_TYPE videoType;	//视频编码类型;

	int numberOfChannels;		//音频通道数;
	int sampleSize;				//音频样本大小;
	int sampleRate;				//音频采样率;
	ES_AUDIO_TYPE audioType;	//音频编码类型;

} ES_FileInfo;


//视频文件GPS信息;
typedef struct ES_GPSInfo
{
	ES_DateTime dateTime;
	double longitude;	//经度，其中东经为正数，西经为负数;
	double latitude;	//纬度，其中北纬为正数，南纬为负数;
	double speed;		//速度;
	double x;			//G-Sensor X;
	double y;			//G-Sensor Y;
	double z;			//G-Sensor Z;

} ES_GPSInfo;


//卫星信息;
typedef struct ES_SatelliteInfo
{
	int id;		//卫星编号;
	int signal;	//信号质量;
	int used;	//是否为用于定位的有效星;

} ES_SatelliteInfo;


//卫星信息列表;
typedef struct ES_SatelliteInfoList
{
	int count;	//卫星个数;
	ES_SatelliteInfo infos[64];	//卫星信息;

} ES_SatelliteInfoList;


//远程录像信息;
typedef struct ES_MediaInfo
{
	ES_MediaType mediaType;
	char name[ES_REMOTE_RECORD_NAME_MAX_LEN];
	char path[ES_PATH_MAX_LEN];
	ES_DateTime mediaStartTime;	//录像开始时间;
	int mediaCount;				//录像视频帧数;
	int mediaFPS;				//录像视频帧率;
	int mediaTotalSize;			//录像总大小;

} ES_MediaInfo;


//设备Wifi参数: ES_DEVICE_PARAM_TYPE_WIFI;
typedef struct ES_DeviceParamWifi
{
	char name[ES_WIFI_NAME_LEN];			//SSID;
	char password[ES_WIFI_PASSWORD_LEN];	//密码;
	char security[ES_WIFI_SECURITY_LEN];	//加密方式;
	int level;	//信号强度;
	int wep_key_index;	//WEP加密方式的密钥index;

} ES_DeviceParamWifi;


//设备Wifi参数: ES_DEVICE_PARAM_TYPE_WIFI_V2;
typedef struct ES_DeviceParamWifi_V2
{
	char name[ES_WIFI_NAME_LEN];			//SSID;
	char password[ES_WIFI_PASSWORD_LEN];	//密码;
	char security[ES_WIFI_SECURITY_LEN];	//加密方式;
	int level;	//信号强度;
	int wep_key_index;	//WEP加密方式的密钥index;
	
	char bStatic;				//是否静态分配IP;
	char resv[3];
	char ip[ES_IP_LEN];			//IP地址;
	char subnet[ES_IP_LEN];		//子网掩码;
	char gateway[ES_IP_LEN];	//网关;

	char bDNS;					//是否需要手动分配DNS;
	char resv2[3];
	char dns1[ES_IP_LEN];		//首选DNS;
	char dns2[ES_IP_LEN];		//备选DNS;

} ES_DeviceParamWifi_V2;


//设备名称参数: ES_DEVICE_PARAM_TYPE_NAME;
typedef struct ES_DeviceParamName
{
	char name[ES_DEVICE_NAME_MAX_LEN];

} ES_DeviceParamName;


//移动侦测灵敏度;
typedef enum ES_DEVICE_MOTION_LEVEL
{
	ES_DEVICE_MOTION_LEVEL_LOW		= 0,	//低;
	ES_DEVICE_MOTION_LEVEL_MEDIUM	= 1,	//中;
	ES_DEVICE_MOTION_LEVEL_HIGH		= 2,	//高;

	ES_DEVICE_MOTION_LEVEL_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_MOTION_LEVEL;


//GPIO报警类型;
typedef enum ES_DEVICE_ALARM_TYPE
{
	ES_DEVICE_ALARM_TYPE_OPEN		= 0,	//常开;
	ES_DEVICE_ALARM_TYPE_CLOSE		= 1,	//常闭;

	ES_DEVICE_ALARM_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_ALARM_TYPE;


//活动检测参数: ES_DEVICE_PARAM_TYPE_ALARM;
typedef struct ES_DeviceParamAlarm
{
	char isMotionValid;		//移动侦测是否开启;
	char isPIRValid;		//PIR是否开启;
	char isInputValid;		//报警输入是否开启;
	char isOutputValid;		//报警输出是否开启;

	char resv[84];

	ES_DEVICE_MOTION_LEVEL level;		//移动侦测灵敏度等级;
	ES_DEVICE_ALARM_TYPE inputType;		//报警输入报警类型;
	ES_DEVICE_ALARM_TYPE outputType;	//报警输出报警类型;

} ES_DeviceParamAlarm;


//SD卡存储状态;
typedef enum ES_DEVICE_SD_STORAGE_TYPE
{
	ES_DEVICE_SD_STORAGE_TYPE_NO_CARD   = 0,    //未插卡;
	ES_DEVICE_SD_STORAGE_TYPE_RECORDING = 1,    //录像中;
	ES_DEVICE_SD_STORAGE_TYPE_IDLE		= 2,	//空闲中;

	ES_DEVICE_SD_STORAGE_TYPE_UNKNOWN   = 0xFFFFFFFF,
} ES_DEVICE_SD_STORAGE_TYPE;


//存储状态参数: ES_DEVICE_PARAM_TYPE_STORAGE;
typedef struct ES_DeviceParamStorage
{
	char has_sd;							//是否有SD卡;
	char resv[3];
	ES_DEVICE_SD_STORAGE_TYPE sd_type;		//SD卡状态;
	unsigned long long sd_total_capacity;	//SD卡总容量;
	unsigned long long sd_free_capacity;	//SD卡当前容量;

} ES_DeviceParamStorage;


//设备版本参数: ES_DEVICE_PARAM_TYPE_VERSION;
typedef struct ES_DeviceParamVersion
{
	char version[ES_VERSION_MAX_LEN];

} ES_DeviceParamVersion;


//密码参数: ES_DEVICE_PARAM_TYPE_PASSWORD;
typedef struct ES_DeviceParamPassword
{
	char pwd_md5[ES_PWD_MD5_LEN];

} ES_DeviceParamPassword;


//镜像参数: ES_DEVICE_PARAM_TYPE_MIRROR;
typedef struct ES_DeviceParamMirror
{
	char vertical;		//垂直镜像;
	char horizontal;	//水平镜像;
	char resv[2];

} ES_DeviceParamMirror;


//亮度参数: ES_DEVICE_PARAM_TYPE_BRIGHTNESS;
typedef struct ES_DeviceParamBrightness
{
	int value;		//取值范围0-255;

} ES_DeviceParamBrightness;


//色度参数: ES_DEVICE_PARAM_TYPE_CHROMA;
typedef struct ES_DeviceParamChroma
{
	int value;		//取值范围0-255;

} ES_DeviceParamChroma;


//对比度参数: ES_DEVICE_PARAM_TYPE_CONTRAST;
typedef struct ES_DeviceParamContrast
{
	int value;		//取值范围0-255;

} ES_DeviceParamContrast;


//饱和度参数: ES_DEVICE_PARAM_TYPE_SATURATION;
typedef struct ES_DeviceParamSaturation
{
	int value;		//取值范围0-255;

} ES_DeviceParamSaturation;


//锐度参数: ES_DEVICE_PARAM_TYPE_SHARPNESS;
typedef struct ES_DeviceParamSharpness
{
	int value;		//取值范围0-255;

} ES_DeviceParamSharpness;


//有线网络参数: ES_DEVICE_PARAM_TYPE_NETWORK;
typedef struct ES_DeviceParamNetwork
{
	char bStatic;				//是否静态分配IP;
	char resv[3];
	char ip[ES_IP_LEN];			//IP地址;
	char subnet[ES_IP_LEN];		//子网掩码;
	char gateway[ES_IP_LEN];	//网关;

	char bDNS;					//是否需要手动分配DNS;
	char resv2[3];
	char dns1[ES_IP_LEN];		//首选DNS;
	char dns2[ES_IP_LEN];		//备选DNS;

} ES_DeviceParamNetwork;


//Wi-Fi列表: ES_DEVICE_PARAM_TYPE_WIFILIST;
typedef struct ES_DeviceParamWiFiList
{
	int count;
	int wifiStruSize;	//ES_DeviceParamWifi的结构体大小

} ES_DeviceParamWiFiList;


//时间参数： ES_DEVICE_PARAM_TYPE_TIME;
typedef struct ES_DeviceParamTime
{
	char bAuto;		//是否自动时间校准;
	char resv[3];

	ES_DateTime dateTime;	//时间，关闭自动时间校准时才可以设置;
	int timeZone;			//时区，开启自动时间校准时才可以设置 +8:00  8*60*60;

} ES_DeviceParamTime;


//SD卡录像参数: ES_DEVICE_PARAM_TYPE_SD_RECORD
typedef struct ES_DeviceParamSDRecord
{
	char bAlarmRecord;	//是否开启报警录像;
	char bTimeRecord;	//是否开启定时录像;
	char resv[2];

	int time;			//当前录像时长;
	int duration;		//单录像时长，单位秒;
	char resv2[76];

} ES_DeviceParamSDRecord;


//巡航参数: ES_DEVICE_PARAM_CRUISE;
typedef struct ES_DeviceParamCruise
{
	char bLRCruise;		//是否开启左右巡航;
	char bUDCruise;		//是否开启上下巡航;
	char resv[2];

} ES_DeviceParamCruise;


//设备类型: ES_DEVICE_PARAM_DEVICE_TYPE;
typedef struct ES_DeviceParamDeviceType
{
	ES_DEVICE_TYPE deviceType;

} ES_DeviceParamDeviceType;


//未查看的报警: ES_DEVICE_PARAM_UNVIEWED_ALARMS;
typedef struct ES_DeviceParamUnviewedAlarms
{
	char hasUnviewedAlarms;	//是否有未查看的报警;
	char resv[3];

} ES_DeviceParamUnviewedAlarms;


//自动关闭WiFi;
typedef enum ES_AUTO_CLOSE_WIFI_TYPE
{
	ES_AUTO_CLOSE_WIFI_TYPE_CLOSE	= 0,	//不自动关闭WiFi;
	ES_AUTO_CLOSE_WIFI_TYPE_60		= 60,	//1分钟;
	ES_AUTO_CLOSE_WIFI_TYPE_180		= 180,	//3分钟;
	ES_AUTO_CLOSE_WIFI_TYPE_300		= 300,	//5分钟;

	ES_AUTO_CLOSE_WIFI_TYPE_UNKNOWN	= 0xFFFFFFFF,
} ES_AUTO_CLOSE_WIFI_TYPE;


//设备AP参数;
typedef struct ES_DeviceParamWiFiAP
{
	char name[ES_WIFI_NAME_LEN];
	char password[ES_WIFI_PASSWORD_LEN];

	ES_AUTO_CLOSE_WIFI_TYPE	autoCloseWiFi;	//自动关闭WiFi;

} ES_DeviceParamWiFiAP;


//自动拍照时间间隔;
typedef enum ES_AUTO_PHOTO_INTERVAL
{
	ES_AUTO_PHOTO_INTERVAL_3		= 3,	//3秒;
	ES_AUTO_PHOTO_INTERVAL_10	= 10,	//10秒;
	ES_AUTO_PHOTO_INTERVAL_15	= 15,	//15秒;
	ES_AUTO_PHOTO_INTERVAL_20	= 20,	//20秒;
	ES_AUTO_PHOTO_INTERVAL_30	= 30,	//30秒;

	ES_AUTO_PHOTO_INTERVAL_UNKNOWN	= 0xFFFFFFFF,
} ES_AUTO_PHOTO_INTERVAL;


//开机设置;
typedef struct ES_DeviceParamStartup
{
	char autoRecord;	//开机自动录像;
	char autoPhoto;		//开机自动拍照;
	char resv[2];

	ES_AUTO_PHOTO_INTERVAL autoPhotoInterval;	//拍照时间间隔;
} ES_DeviceParamStartup;


//录像设置;
typedef struct ES_DeviceParamRecord
{
	char cycle;		//循环录影;
	char resv[3];

} ES_DeviceParamRecord;


//电池状态类型;
typedef enum ES_DEVICE_PARAM_BATTERY_STATE
{
	ES_DEVICE_PARAM_BATTERY_STATE_IDLE		= 0,	//空闲;
	ES_DEVICE_PARAM_BATTERY_STATE_CHARGING	= 1,	//充电中;

	ES_DEVICE_PARAM_BATTERY_STATE_UNKNOWN	= 0xFFFFFFFF,
} ES_DEVICE_PARAM_BATTERY_STATE;


//电池参数;
typedef struct ES_DeviceParamBattery
{
	ES_DEVICE_PARAM_BATTERY_STATE batteryState;	//电池状态;
	unsigned int batteryPower;	//电量;

} ES_DeviceParamBattery;


//ISP参数;
typedef struct ES_DeviceParamIsp
{
	unsigned char ISPDGain; 
	unsigned char SysGain; 
	unsigned char DRC_enable; 
	unsigned char DNR_enable;

} ES_DeviceParamIsp;


//设备ID;
typedef struct ES_DeviceParamDeviceID
{
	char deviceID[ES_DEVICE_ID_MAX_LEN];

} ES_DeviceParamDeviceID;


//语言参数: ES_LCT_LANGUAGE;
typedef struct ES_DeviceParamLanguage
{
	ES_LANGUAGE_TYPE language;

} ES_DeviceParamLanguage;


//加密参数: ES_LCT_ENCRYPTION;
typedef struct ES_DeviceParamEncryption
{
	unsigned char codes[ES_ENCRYPTION_CODE_LEN];

} ES_DeviceParamEncryption;


typedef struct ES_DeviceParamIP
{
	char lanIP[ES_IP_LEN];	//有线IP;
	char wifiIP[ES_IP_LEN];	//无线IP;

} ES_DeviceParamIP;


typedef enum ES_RESOLUTION_TYPE
{
	ES_RESOLUTION_TYPE_1920_1080	= 0,	//1080P;
	ES_RESOLUTION_TYPE_1280_720		= 1,	//720P;
	ES_RESOLUTION_TYPE_640_360		= 2,	//360P;

	ES_RESOLUTION_TYPE_Unknown		= 0xFFFFFFFF,
} ES_RESOLUTION_TYPE;


//录像分辨率;
typedef struct ES_DeviceParamRecordResolution
{
	ES_RESOLUTION_TYPE recordResolution;
	
} ES_DeviceParamRecordResolution;


//缩时录影状态;
typedef struct ES_DeviceParamTimeLapse
{
	char isRecord;	//是否正在缩时录影;
	char resv[3];
	int recordTime;	//录像时间;
	int realTime;	//真实时间;

} ES_DeviceParamTimeLapse;


//码率;
typedef struct ES_DeviceParamBitRate
{
	ES_StreamType streamType;	//码流类型;
	int bit_rate;				//码率，单位bps;
	
} ES_DeviceParamBitRate;


//搜索信息;
typedef struct ES_SearchData
{
	char deviceID[ES_DEVICE_ID_MAX_LEN];		//设备ID;
	ES_DEVICE_TYPE deviceType;					//设备类型;
	char deviceName[ES_DEVICE_NAME_MAX_LEN];	//设备名称;
	char lanIP[ES_IP_LEN];						//有线IP;
	unsigned char lanMAC[ES_MAC_LEN];			//有线MAC;
	unsigned char resv1[2];						//保留;
	char wifiSSID[ES_WIFI_NAME_LEN];			//无线SSID;
	unsigned char wifiMAC[ES_MAC_LEN];			//无线MAC;
	unsigned char resv2[2];						//保留;
	char kernelVersion[ES_VERSION_MAX_LEN];		//内核版本;
	char appVersion[ES_VERSION_MAX_LEN];		//软件版本;
	ES_DEVICE_SD_STORAGE_TYPE deviceSDType;		//SD卡状态;
	unsigned long long sd_total_capacity;		//SD卡总容量;
	unsigned char factoryStatus;				//0 - 未知;  1 - 出厂状态;   2 - 非出厂状态;
	unsigned char defectPixelStatus;			//0 - 未知;  1 - 已经坏点校正;  2 - 未进行坏点校正;
	unsigned char resv3[2];						//保留;
	ES_LANGUAGE_TYPE language;					//语言;
	unsigned char encryption;					//0 - 未知;  1 - 已经加密;   2 - 未加密;
	unsigned char resv4[3];						//保留;

} ES_SearchData;


typedef struct ES_DeviceParamSearch
{
	ES_SearchData searchData;

} ES_DeviceParamSearch;


//静默模式;
typedef struct ES_DeviceParamSilent
{
	char silent;	//是否静默;
	char resv[3];
	
} ES_DeviceParamSilent;


//国家;
typedef struct ES_DeviceParamCountry
{
	char country[4];	//国家代码，如中国：CN;
	
} ES_DeviceParamCountry;


//OSD时间格式;
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


//定时关机（在不录像时用户 x 秒不操作设备，设备自动关机）;
typedef struct ES_DeviceParamTimeOff
{
	int timeoff;	//单位：秒，其中 0 表示不关机;

} ES_DeviceParamTimeOff;


#endif
