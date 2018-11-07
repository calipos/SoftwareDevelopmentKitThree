
#ifndef __ESONG_ES_CALLBACK_H_INC__
#define __ESONG_ES_CALLBACK_H_INC__


#include "ES_Type.h"


/*
 *	��־�ص�;
 *
 *	@param[in]	log		��־����;
 *	@param[in]	pUser	�û�����;
 */
typedef void(*ES_LogCallback)(ES_LOG_LEVEL level, const char* log, void *pUser);


/*
 *	�豸״̬�ص�;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	state		�豸״̬;
 *	@param[in]	pUser		�û�����;
 */
typedef void(*ES_DeviceStateCallback)(int hSession, ES_DEVICE_STATE state, void *pUser);


/*
 *	�����ص�����;
 *
 *	@param[in]	hSession	�����豸���;
 *	@param[in]	pFrame		������Ϣ;
 *	@param[in]	stream		��������;
 *	@param[in]	size		�������ݴ�С;
 *	@param[in]	pUser		�����ص��û�����;
 */
typedef void(*ES_StreamDataCallback)(int hSession, const ES_Frame* pFrame, const char* stream, int size, void *pUser);



/*
 *	�����ص�����;
 *
 *	@param[in]	hSession	�����豸���;
 *	@param[in]	frame		������Ϣ����ӦJSON�ַ���;
 *	@param[in]	stream		��������;
 *	@param[in]	size		�������ݴ�С;
 *	@param[in]	pUser		�����ص��û�����;
 */
typedef void(*ES_StreamDataCallback_V2)(int hSession, const char* frame, const char* stream, int size, void *pUser);


/*
 *	Զ�̻طŻص�����;
 *
 *	@param[in]	hSession	�����豸���;
 *	@param[in]	pFrame		������Ϣ;
 *	@param[in]	stream		��������;
 *	@param[in]	size		�������ݴ�С;
 *	@param[in]	pUser		�����ص��û�����;
 */
typedef void(*ES_RecordPlayCallback)(int hSession, int current, int total, const ES_Frame* pFrame, const char* stream, int size, void *pUser);


/*
 *	����״̬�ص�;
 *
 *	@param[in]	hConnecter	�豸���;
 *	@param[in]	state		����״̬;
 *	@param[in]	current		��ǰ������;
 *	@param[in]	total		�ܹ�������;
 *	@param[in]	pUser		�û�����;
 */
typedef void(*ES_DownloadCallback)(int hSession, ES_DOWNLOAD_STATE state, int current, int total, void* pUser);


/*
 *	�����������ص�;
 *
 *	@param[in]	searchData	������������;
 *	@param[in]	pUser		�û�����;
 */
typedef void(*ES_SearchDataCallback)(int handle, ES_SearchData searchData, const char* ip, void *pUser);


/*
 *	�豸�����ص�;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	updateType	�豸��������;
 *	@param[in]	current		��ǰ����;
 *	@param[in]	total		�ܽ���;
 *	@param[in]	pUser		�û�����;
 */
typedef void(*ES_DeviceUpdateCallback)(int hSession, ES_DEVICE_UPDATE_TYPE updateType, int current, int total, void *pUser);


/*
 *	�����ص�;
 *
 *	@param[in]	hConnecter	�豸���;
 *	@param[in]	alarmType	��������;
 *	@param[in]	pUser		�û�����;
 */
typedef void(*ES_AlarmCallback)(int hConnecter, ES_AlarmType alarmType, void *pUser);


/*
 *	GPS��Ϣ�ص�;
 */
typedef void(*ES_GPSInfoCallback)(int hSession, ES_GPSInfo info, void *pUser);


/*
 *	������Ϣ�ص�;
 */
typedef void(*ES_SatelliteInfoCallback)(int hSession, ES_SatelliteInfoList infoList, void *pUser);


#endif