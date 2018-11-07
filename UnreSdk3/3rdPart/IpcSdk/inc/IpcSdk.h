
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
 *	��ȡ�汾��;
 */
IPC_SDK_API unsigned ES_GetVersion();


/*
 *	��ʼ��;
 */
IPC_SDK_API ES_ERROR_CODE ES_InitSdk(const char* param);


/*
 *	����ʼ��;
 */
IPC_SDK_API ES_ERROR_CODE ES_UninitSdk();


/*
 *	������־�ص�����;
 *
 *	@param[in]	pCallback	��־�ص�;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetLogCallback(ES_LogCallback pCallback, void *pUser);


/*
 *	��ȡ��������״̬;
 *
 *	@param[out]	bNetwork	��ȡ�������Ƿ�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_CheckNetwork(char* bNetwork);


/*
 *	����豸״̬�ص�;
 *
 *	@param[in]	pCallback	�豸״̬�ص�;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_AddDeviceStateCallback(ES_DeviceStateCallback pCallback, void *pUser);


/*
 *	�Ƴ��豸״̬�ص�;
 *
 *	@param[in]	pCallback	�豸״̬�ص�;
 */
IPC_SDK_API ES_ERROR_CODE ES_RemoveDeviceStateCallback(ES_DeviceStateCallback pCallback);


/*
 *	��ʼ������������;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartCountTraffic();


/*
 *	ֹͣ������������;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopCountTraffic();


/*
 *	��ȡ��������;
 *
 *	@param[out]	count	��ȡ������������;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetTrafficCount(unsigned long long* count);


/*
 *	������������;
 */
IPC_SDK_API ES_ERROR_CODE ES_ClearTrafficCount();


/*
 *	�����豸;
 *
 *	@param[in]	strDID		�豸ID;
 *	@param[in]	strUser		�û���;
 *	@param[in]	strPwd		����;
 *	@param[in]	uuid		�������͵�Ψһ��־��;
 *	@param[in]	dateTime	��ǰϵͳʱ��;
 *	@param[in]	timeZone	��ǰϵͳʱ��, +8:00  8*60*60;
 *	@param[out]	hConnecter	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectPP(const char* strDID, const char* strUser, const char* strPwd, const char* uuid, ES_DateTime dateTime, int timeZone, int* hSession);


/*
 *	�����豸;
 *
 *	@param[in]	type		�豸����;
 *	@param[in]	ip			�豸IP;
 *	@param[in]	port		�豸�˿ں�;
 *	@param[in]	timezone	ʱ��;
 *	@param[out]	hSession	���ص����Ӿ��;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectIP(ES_DEVICE_TYPE type, const char* ip, unsigned short port, int timezone, int* hSession);


/*
 *	�Ͽ�����;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_Disconnect(int hSession);


/*
 *	P2P�Ͽ����ڽ��е�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_ConnectBreak();


/*
 *	֪ͨ�Ƴ��豸;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	uuid		�������͵�Ψһ��־��;
 */
IPC_SDK_API ES_ERROR_CODE ES_NotifyDeviceRemove(int hSession, const char* uuid);


/*
 *	��ͨ��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	streamType	��������;
 */
IPC_SDK_API ES_ERROR_CODE ES_OpenChannel(int hSession, ES_StreamType streamType, ES_StreamDataCallback pCallback, void *pUser);


/*
*	��ͨ��;
*
*	@param[in]	hSession	�豸���;
*	@param[in]	streamType	��������;
*/
IPC_SDK_API ES_ERROR_CODE ES_OpenChannel_V2(int hSession, ES_StreamType streamType, ES_StreamDataCallback_V2 pCallback, void *pUser);


/*
 *	�ر�ͨ��;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_CloseChannel(int hSession);


/*
 *	��ͼ;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	filePath	ͼƬ����·��;
 *	@param[in]	fileName	ͼƬ��������;
 */
IPC_SDK_API ES_ERROR_CODE ES_CaptureImage(int hSession, const char* filePath, const char* fileName);


/*
 *	��ʼ¼��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	filePath	¼�񱣴�·��;
 *	@param[in]	fileName	¼�񱣴�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartRecord(int hSession, const char* filePath, const char* fileName);


/*
 *	ֹͣ¼��;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopRecord(int hSession);


/*
 *	��ʼ������¼��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	filePath	¼�񱣴�·��;
 *	@param[in]	fileName	¼�񱣴�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSlowMotionRecord(int hSession, const char* filePath, const char *fileName);


/*
 *	ֹͣ������¼��;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSlowMotionRecord(int hSession);


/*
 *	��ʼֱ��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	rtmpUrl		RTMP��ַ;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartLive(int hSession, const char* rtmpUrl);


/*
 *	ֱֹͣ��;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopLive(int hSession);


/*
 *	��ʼ����;
 *
 *	@param[in]	pCallback	������Ϣ�ص�;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSearch(const char* ip, ES_SearchDataCallback pCallback, void *pUser);


/*
 *	ֹͣ����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSearch();


/*
 *	��ʼ����ָ���豸����;
 *
 *	@param[in]	deviceType	�豸����;
 *	@param[in]	pCallback	������Ϣ�ص�;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartSearchWithType(ES_DEVICE_TYPE deviceType, const char* ip, ES_SearchDataCallback pCallback, void *pUser);


/*
 *	ֹͣ����ָ���豸����;
 *
 *	@param[in]	deviceType	�豸����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopSearchWithType(ES_DEVICE_TYPE deviceType);


/*
 *	��ȡ���������;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	type		��������;
 *	@param[out]	data		��ȡ���Ĳ���;
 *	@param[in]	dataSize	��������С;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_GetParam(int hSession, ES_DEVICE_PARAM_TYPE type, void* data, int dataSize);


/*
 *	�������������;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	type		��������;
 *	@param[in]	data		Ҫ���õĲ�������;
 *	@param[in]	dataSize	���ݴ�С;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_SetParam(int hSession, ES_DEVICE_PARAM_TYPE type, const void* data, int dataSize);


/*
 *	��ȡý����Ϣ;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	mediaType	ý������;
 *	@param[in]	from		��ʼ������λ��(��0��ʼ����);
 *	@param[in]	size		��ȡ����ý����Ϣ��������;
 *	@param[out]	count		��ȡ����ý����Ϣ����;
 *	@param[out]	pInfo		��ȡ����ý����Ϣ;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasInfo(int hSession, ES_MediaType mediaType, int from, int size, int *count, ES_MediaInfo *pInfo);


/*
 *	��ȡ��ý������;
 *
 *	@param[in]		hSession	�豸���;
 *	@param[in]		mediaType	ý������;
 *	@param[in, out]	count		[in]������������������ռ䲻�㣬���ز���ʧ��		[out]��ȡ�������ڸ���;
 *	@param[out]		pDate		��ȡ��������;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasDate(int hSession, ES_MediaType mediaType, int* count, ES_Date *pDate);


/*
 *	��ȡָ�����ڵĶ�ý����Ϣ;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	mediaType	ý������;
 *	@param[in]	date		ָ��������;
 *	@param[in]	from		��ʼ������λ��(��0��ʼ����);
 *	@param[in]	size		��ȡ����ý����Ϣ��������;
 *	@param[out]	count		��ȡ����ý����Ϣ����;
 *	@param[out]	pInfo		��ȡ����ý����Ϣ;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediasInfoByDate(int hSession, ES_MediaType mediaType, ES_Date date, int from, int size, int* count, ES_MediaInfo* pInfo);


/*
 *	��ȡý������ͼ;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	mediaType	ý������;
 *	@param[in]	mediaPath	ý��¼��·��;
 *	@param[out]	imageSize	ͼƬ��С;
 *	@param[out]	image		ͼƬ����;
 *
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMediaImage(int hSession, ES_MediaType mediaType, const char* mediaPath, int* imageSize, void* image);


/*
 *	��ʼ����¼��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	recordPath	¼��·��;
 *	@param[in]	savePath	����·��;
 *	@param[in]	pCallback	���ػص�;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_StartDownloadRecord(int hSession, const char* recordPath, const char* savePath, const char* saveName, ES_DownloadCallback pCallback, void* pUser);


/*
 *	ֹͣ����¼��;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopDownloadRecord(int hSession);


/*
 *	Զ��¼��ط�;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	recordPath	¼��·��;
 *	@param[in]	from		�ӵڼ�֡��ʼ�ط���Ƶ;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordPlay(int hSession, const char* recordPath, int from, ES_RecordPlayCallback pCallback, void *pUser);


/*
 *	Զ��¼��ֹͣ;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordStop(int hSession);


/*
 *	Զ��¼��ɾ��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	recordPath	¼��·��;
 */
IPC_SDK_API ES_ERROR_CODE ES_RecordRemove(int hSession, const char* recordPath);


/*
 *	�����Խ�;
 *
 *	@param[in]	hSession	�豸���;	
 */
IPC_SDK_API ES_ERROR_CODE ES_StartTalk(int hSession);


/*
 *	���ͶԽ�����;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	pData		�Խ�����;
 *	@param[in]	nDataSize	�Խ����ݳ���;
 */
IPC_SDK_API ES_ERROR_CODE ES_PushTalkData(int hSession, const void* pData, int nDataSize);


/*
 *	ֹͣ�Խ�;
 *
 *	@param[in]	hSession	�豸���;
 */
IPC_SDK_API ES_ERROR_CODE ES_StopTalk(int hSession);


/*
 *	�����豸;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	type		��������;
 *	@param[in]	filePath	�����ļ�·��;
 *	@param[in]	pCallback	�����ص�����;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_DeviceUpdate(int hSession, ES_DEVICE_UPDATE_TYPE type, const char *filePath, ES_DeviceUpdateCallback pCallback, void *pUser);


/*
 *	SD����ʽ��;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	msTimeout	��ʱʱ��;
 */
IPC_SDK_API ES_ERROR_CODE ES_SDFormat(int hSession, int msTimeout);


/*
 *	��̨����;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	controlType	��������;
 *	@param[in]	data1		����1;
 *	@param[in]	data2		����2;
 */
IPC_SDK_API ES_ERROR_CODE ES_PTZControl(int hSession, ES_PTZ_CONTROL_TYPE controlType, unsigned char data1, unsigned char data2);


/*
 *	���þ���;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	bMute		�Ƿ���;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetMute(int hSession, bool bMute);


/*
 *	��ȡ����״̬;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[out]	bMute		�Ƿ���;
 */
IPC_SDK_API ES_ERROR_CODE ES_GetMute(int hSession, bool* bMute);


/*
 *	����������;
 *
 *	@param[in]	handle		���������豸���;
 *	@param[in]	type		��������;
 *	@param[in]	data		��������;
 *	@param[in]	dataSize	�������ݳ���;
 */
IPC_SDK_API ES_ERROR_CODE ES_LanControl(int handle, ES_LanControlType type, const void *data, int dataSize);


/*
 *	����������;
 *
 *	@param[in]	handle		���������豸���;
 *	@param[in]	type		��������;
 *	@param[in]	current		��ǰ�ֿ�;
 *	@param[in]	total		�ֿܷ�;
 *	@param[in]	pData		����;
 *	@param[in]	nDataSize	���ݴ�С;
 */
IPC_SDK_API ES_ERROR_CODE ES_LanUpdate(int handle, ES_DEVICE_UPDATE_TYPE type, int current, int total, const void* pData, int nDataSize);


/*
 *	�豸�Ƿ��и�����;
 *
 *	@param[in]	deviceType		�豸����;
 *	@param[in]	abilityType		��������;
 *
 *	@return	ES_ERROR_SUCCESS
 *			ES_ERROR_HAS_NO_ABILITY
 */
IPC_SDK_API ES_ERROR_CODE ES_HasAbility(ES_DEVICE_TYPE deviceType, ES_ABILITY_TYPE abilityType);


/*
 *	����GPS��Ϣ�ص�;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	pCallback	�ص�����;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetGPSInfoCallback(int hSession, ES_GPSInfoCallback pCallback, void *pUser);


/*
 *	����������Ϣ�ص�;
 *
 *	@param[in]	hSession	�豸���;
 *	@param[in]	pCallback	�ص�����;
 *	@param[in]	pUser		�û�����;
 */
IPC_SDK_API ES_ERROR_CODE ES_SetSatelliteInfoCallback(int hSession, ES_SatelliteInfoCallback pCallback, void *pUser);



IPC_SDK_API ES_ERROR_CODE ES_TransformMp4_PCM_AAC(const char *src_filename, const char *dst_filename);


#ifdef __cplusplus
}
#endif


#endif
