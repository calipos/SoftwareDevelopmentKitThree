
#ifndef __ESONG_ES_CALLBACK_H_INC__
#define __ESONG_ES_CALLBACK_H_INC__


#include "ES_Type.h"


/*
 *	日志回调;
 *
 *	@param[in]	log		日志内容;
 *	@param[in]	pUser	用户数据;
 */
typedef void(*ES_LogCallback)(ES_LOG_LEVEL level, const char* log, void *pUser);


/*
 *	设备状态回调;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	state		设备状态;
 *	@param[in]	pUser		用户数据;
 */
typedef void(*ES_DeviceStateCallback)(int hSession, ES_DEVICE_STATE state, void *pUser);


/*
 *	码流回调函数;
 *
 *	@param[in]	hSession	连接设备句柄;
 *	@param[in]	pFrame		码流信息;
 *	@param[in]	stream		码流数据;
 *	@param[in]	size		码流数据大小;
 *	@param[in]	pUser		码流回调用户数据;
 */
typedef void(*ES_StreamDataCallback)(int hSession, const ES_Frame* pFrame, const char* stream, int size, void *pUser);



/*
 *	码流回调函数;
 *
 *	@param[in]	hSession	连接设备句柄;
 *	@param[in]	frame		码流信息，对应JSON字符串;
 *	@param[in]	stream		码流数据;
 *	@param[in]	size		码流数据大小;
 *	@param[in]	pUser		码流回调用户数据;
 */
typedef void(*ES_StreamDataCallback_V2)(int hSession, const char* frame, const char* stream, int size, void *pUser);


/*
 *	远程回放回调函数;
 *
 *	@param[in]	hSession	连接设备句柄;
 *	@param[in]	pFrame		码流信息;
 *	@param[in]	stream		码流数据;
 *	@param[in]	size		码流数据大小;
 *	@param[in]	pUser		码流回调用户数据;
 */
typedef void(*ES_RecordPlayCallback)(int hSession, int current, int total, const ES_Frame* pFrame, const char* stream, int size, void *pUser);


/*
 *	下载状态回调;
 *
 *	@param[in]	hConnecter	设备句柄;
 *	@param[in]	state		下载状态;
 *	@param[in]	current		当前下载量;
 *	@param[in]	total		总共下载量;
 *	@param[in]	pUser		用户数据;
 */
typedef void(*ES_DownloadCallback)(int hSession, ES_DOWNLOAD_STATE state, int current, int total, void* pUser);


/*
 *	局域网搜索回调;
 *
 *	@param[in]	searchData	搜索到的数据;
 *	@param[in]	pUser		用户数据;
 */
typedef void(*ES_SearchDataCallback)(int handle, ES_SearchData searchData, const char* ip, void *pUser);


/*
 *	设备升级回调;
 *
 *	@param[in]	hSession	设备句柄;
 *	@param[in]	updateType	设备升级类型;
 *	@param[in]	current		当前进度;
 *	@param[in]	total		总进度;
 *	@param[in]	pUser		用户数据;
 */
typedef void(*ES_DeviceUpdateCallback)(int hSession, ES_DEVICE_UPDATE_TYPE updateType, int current, int total, void *pUser);


/*
 *	报警回调;
 *
 *	@param[in]	hConnecter	设备句柄;
 *	@param[in]	alarmType	报警类型;
 *	@param[in]	pUser		用户数据;
 */
typedef void(*ES_AlarmCallback)(int hConnecter, ES_AlarmType alarmType, void *pUser);


/*
 *	GPS信息回调;
 */
typedef void(*ES_GPSInfoCallback)(int hSession, ES_GPSInfo info, void *pUser);


/*
 *	卫星信息回调;
 */
typedef void(*ES_SatelliteInfoCallback)(int hSession, ES_SatelliteInfoList infoList, void *pUser);


#endif