
#ifndef __ESONG_IPC_SDK_H_INC__
#define __ESONG_IPC_SDK_H_INC__


#ifdef WIN32
#ifdef IPC_SDK_EXPORTS
#define IPC_SDK_API __declspec(dllexport)
#else
#define IPC_SDK_API __declspec(dllimport)
#endif
#else
#define IPC_SDK_API __attribute__ ((visibility("default")))
#endif


#include "ES_Type.h"
#include "ES_Callback.h"


#ifdef __cplusplus
extern "C"
{
#endif

/*
 *	获取版本号;
 */
IPC_SDK_API unsigned ES_GetVersion();


/*
 *	初始化;
 */
IPC_SDK_API ES_ERROR_CODE ES_InitSdk(const char* param);


/*
 *	反初始化;
 */
IPC_SDK_API ES_ERROR_CODE ES_UninitSdk();


/*
 *	设置日志回调函数;
 *
 *	@param[in]	pCallback	日志回调;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetLogCallback(ES_LogCallback pCallback, void *pUser);


/*
 *	获取网络连接状态;
 *
 *	@param[out]	bNetwork	获取到网络是否连接;
 */
IPC_SDK_API ES_ERROR_CODE ES_CheckNetwork(char* bNetwork);


/*
 *	添加设备状态回调;
 *
 *	@param[in]	pCallback	设备状态回调;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_AddDeviceStateCallback(ES_DeviceStateCallback pCallback, void *pUser);


/*
 *	移除设备状态回调;
 *
 *	@param[in]	pCallback	设备状态回调;
 */
IPC_SDK_API ES_ERROR_CODE ES_RemoveDeviceStateCallback(ES_DeviceStateCallback pCallback);


/*
 *	开始监听数据流量;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartCountTraffic();


/*
 *	停止监听数据流量;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopCountTraffic();


/*
 *	获取数据流量;
 *
 *	@param[out]	count	获取到的数据流量;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetTrafficCount(unsigned long long* count);


/*
 *	数据流量清零;
 */
IPC_SDK_API ES_ERROR_CODE ES_ClearTrafficCount();


/*
 *	连接设备;
 *
 *	@param[in]	strDID		设备ID;
 *	@param[in]	strUser		用户名;
 *	@param[in]	strPwd		密码;
 *	@param[in]	uuid		用于推送的唯一标志符;
 *	@param[in]	dateTime	当前系统时间;
 *	@param[in]	timeZone	当前系统时区, +8:00  8*60*60;
 *	@param[out]	hConnecter	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectPP(const char* strDID, const char* strUser, const char* strPwd, const char* uuid, ES_DateTime dateTime, int timeZone, int* hSession);


/*
 *	连接设备;
 *
 *	@param[in]	type		设备类型;
 *	@param[in]	ip			设备IP;
 *	@param[in]	port		设备端口号;
 *	@param[in]	timezone	时区;
 *	@param[out]	hSession	返回的连接句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectIP(ES_DEVICE_TYPE type, const char* ip, unsigned short port, int timezone, int* hSession);


/*
 *	断开连接;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_Disconnect(int hSession);


/*
 *	P2P断开正在进行的连接;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectBreak();


/*
 *	通知移除设备;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	uuid		用于推送的唯一标志符;
 */
IPC_SDK_API ES_ERROR_CODE ES_NotifyDeviceRemove(int hSession, const char* uuid);


/*
 *	打开通道;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	streamType	码流类型;
 */
IPC_SDK_API ES_ERROR_CODE ES_OpenChannel(int hSession, ES_StreamType streamType, ES_StreamDataCallback pCallback, void *pUser);


/*
*	打开通道;
*
*	@param[in]	hSession	设备句柄;
*	@param[in]	streamType	码流类型;
*/
IPC_SDK_API ES_ERROR_CODE ES_OpenChannel_V2(int hSession, ES_StreamType streamType, ES_StreamDataCallback_V2 pCallback, void *pUser);


/*
 *	关闭通道;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_CloseChannel(int hSession);


/*
 *	截图;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	filePath	图片保存路径;
 *	@param[in]	fileName	图片保存名称;
 */
IPC_SDK_API ES_ERROR_CODE ES_CaptureImage(int hSession, const char* filePath, const char* fileName);


/*
 *	开始录像;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	filePath	录像保存路径;
 *	@param[in]	fileName	录像保存名称;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartRecord(int hSession, const char* filePath, const char* fileName);


/*
 *	停止录像;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopRecord(int hSession);


/*
 *	开始慢动作录像;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	filePath	录像保存路径;
 *	@param[in]	fileName	录像保存名称;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSlowMotionRecord(int hSession, const char* filePath, const char *fileName);


/*
 *	停止慢动作录像;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSlowMotionRecord(int hSession);


/*
 *	开始直播;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	rtmpUrl		RTMP地址;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartLive(int hSession, const char* rtmpUrl);


/*
 *	停止直播;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopLive(int hSession);


/*
 *	开始搜索;
 *
 *	@param[in]	pCallback	搜索信息回调;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSearch(const char* ip, ES_SearchDataCallback pCallback, void *pUser);


/*
 *	停止搜索;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSearch();


/*
 *	开始搜索指定设备类型;
 *
 *	@param[in]	deviceType	设备类型;
 *	@param[in]	pCallback	搜索信息回调;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSearchWithType(ES_DEVICE_TYPE deviceType, const char* ip, ES_SearchDataCallback pCallback, void *pUser);


/*
 *	停止搜索指定设备类型;
 *
 *	@param[in]	deviceType	设备类型;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSearchWithType(ES_DEVICE_TYPE deviceType);


/*
 *	获取摄像机参数;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	type		参数类型;
 *	@param[out]	data		获取到的参数;
 *	@param[in]	dataSize	缓冲区大小;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_GetParam(int hSession, ES_DEVICE_PARAM_TYPE type, void* data, int dataSize);


/*
 *	设置摄像机参数;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	type		参数类型;
 *	@param[in]	data		要设置的参数数据;
 *	@param[in]	dataSize	数据大小;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_SetParam(int hSession, ES_DEVICE_PARAM_TYPE type, const void* data, int dataSize);


/*
 *	获取媒体信息;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	mediaType	媒体类型;
 *	@param[in]	from		开始搜索的位置(从0开始计数);
 *	@param[in]	size		获取到的媒体信息的最大个数;
 *	@param[out]	count		获取到的媒体信息个数;
 *	@param[out]	pInfo		获取到的媒体信息;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasInfo(int hSession, ES_MediaType mediaType, int from, int size, int *count, ES_MediaInfo *pInfo);


/*
 *	获取多媒体日期;
 *
 *	@param[in]		hSession	设备句柄;
 *	@param[in]		mediaType	媒体类型;
 *	@param[in, out]	count		[in]接收最大的数量，如果空间不足，返回操作失败		[out]获取到的日期个数;
 *	@param[out]		pDate		获取到的日期;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasDate(int hSession, ES_MediaType mediaType, int* count, ES_Date *pDate);


/*
 *	获取指定日期的多媒体信息;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	mediaType	媒体类型;
 *	@param[in]	date		指定的日期;
 *	@param[in]	from		开始搜索的位置(从0开始计数);
 *	@param[in]	size		获取到的媒体信息的最大个数;
 *	@param[out]	count		获取到的媒体信息个数;
 *	@param[out]	pInfo		获取到的媒体信息;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasInfoByDate(int hSession, ES_MediaType mediaType, ES_Date date, int from, int size, int* count, ES_MediaInfo* pInfo);


/*
 *	获取媒体缩略图;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	mediaType	媒体类型;
 *	@param[in]	mediaPath	媒体录像路径;
 *	@param[out]	imageSize	图片大小;
 *	@param[out]	image		图片数据;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediaImage(int hSession, ES_MediaType mediaType, const char* mediaPath, int* imageSize, void* image);


/*
 *	开始下载录像;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	recordPath	录像路径;
 *	@param[in]	savePath	保存路径;
 *	@param[in]	pCallback	下载回调;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartDownloadRecord(int hSession, const char* recordPath, const char* savePath, const char* saveName, ES_DownloadCallback pCallback, void* pUser);


/*
 *	停止下载录像;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopDownloadRecord(int hSession);


/*
 *	远程录像回放;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	recordPath	录像路径;
 *	@param[in]	from		从第几帧开始回放视频;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordPlay(int hSession, const char* recordPath, int from, ES_RecordPlayCallback pCallback, void *pUser);


/*
 *	远程录像停止;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordStop(int hSession);


/*
 *	远程录像删除;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	recordPath	录像路径;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordRemove(int hSession, const char* recordPath);


/*
 *	开启对讲;
 *
 *	@param[in]	hSession	设备句柄;	
 */
IPC_SDK_API ES_ERROR_CODE ES_StartTalk(int hSession);


/*
 *	发送对讲数据;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	pData		对讲数据;
 *	@param[in]	nDataSize	对讲数据长度;
 */
IPC_SDK_API ES_ERROR_CODE ES_PushTalkData(int hSession, const void* pData, int nDataSize);


/*
 *	停止对讲;
 *
 *	@param[in]	hSession	设备句柄;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopTalk(int hSession);


/*
 *	升级设备;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	type		升级类型;
 *	@param[in]	filePath	升级文件路径;
 *	@param[in]	pCallback	升级回调函数;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_DeviceUpdate(int hSession, ES_DEVICE_UPDATE_TYPE type, const char *filePath, ES_DeviceUpdateCallback pCallback, void *pUser);


/*
 *	SD卡格式化;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	msTimeout	超时时间;
 */
IPC_SDK_API ES_ERROR_CODE ES_SDFormat(int hSession, int msTimeout);


/*
 *	云台控制;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	controlType	控制类型;
 *	@param[in]	data1		数据1;
 *	@param[in]	data2		数据2;
 */
IPC_SDK_API ES_ERROR_CODE ES_PTZControl(int hSession, ES_PTZ_CONTROL_TYPE controlType, unsigned char data1, unsigned char data2);


/*
 *	设置静音;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	bMute		是否静音;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetMute(int hSession, bool bMute);


/*
 *	获取静音状态;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[out]	bMute		是否静音;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMute(int hSession, bool* bMute);


/*
 *	局域网控制;
 *
 *	@param[in]	handle		搜索到的设备句柄;
 *	@param[in]	type		控制类型;
 *	@param[in]	data		附加数据;
 *	@param[in]	dataSize	附加数据长度;
 */
IPC_SDK_API ES_ERROR_CODE ES_LanControl(int handle, ES_LanControlType type, const void *data, int dataSize);


/*
 *	局域网升级;
 *
 *	@param[in]	handle		搜索到的设备句柄;
 *	@param[in]	type		升级类型;
 *	@param[in]	current		当前分块;
 *	@param[in]	total		总分块;
 *	@param[in]	pData		数据;
 *	@param[in]	nDataSize	数据大小;
 */
IPC_SDK_API ES_ERROR_CODE ES_LanUpdate(int handle, ES_DEVICE_UPDATE_TYPE type, int current, int total, const void* pData, int nDataSize);


/*
 *	设备是否有该能力;
 *
 *	@param[in]	deviceType		设备类型;
 *	@param[in]	abilityType		能力类型;
 *
 *	@return	ES_ERROR_SUCCESS
 *			ES_ERROR_HAS_NO_ABILITY
 */
IPC_SDK_API ES_ERROR_CODE ES_HasAbility(ES_DEVICE_TYPE deviceType, ES_ABILITY_TYPE abilityType);


/*
 *	设置GPS信息回调;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	pCallback	回调函数;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetGPSInfoCallback(int hSession, ES_GPSInfoCallback pCallback, void *pUser);


/*
 *	设置卫星信息回调;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	pCallback	回调函数;
 *	@param[in]	pUser		用户数据;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetSatelliteInfoCallback(int hSession, ES_SatelliteInfoCallback pCallback, void *pUser);



IPC_SDK_API ES_ERROR_CODE ES_TransformMp4_PCM_AAC(const char *src_filename, const char *dst_filename);


#ifdef __cplusplus
}
#endif


#endif
