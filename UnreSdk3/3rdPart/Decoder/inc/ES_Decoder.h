
#ifndef __ESONG_ES_DECODER_H_INC__
#define __ESONG_ES_DECODER_H_INC__


#ifdef WIN32
#ifdef DECODER_EXPORTS
#define DECODER_API __declspec(dllexport)
#else
#define DECODER_API __declspec(dllimport)
#endif
#else
#define DECODER_API __attribute__ ((visibility("default")))
#endif


#include "ES_Type.h"
#include "ES_Callback.h"


#ifdef __cplusplus
extern "C"
{
#endif


/*
 *	������־�ص�����;
 *
 *	@param[in]	pCallback	��־�ص�;
 *	@param[in]	pUser		�û�����;
 */
DECODER_API void ES_DECODER_SetLogCallback(ES_LogCallback pCallback, void *pUser);


/*
 *	����������;
 *
 *	@param[in]	type	��������;
 *
 *	@return	���ؽ��������;
 */
DECODER_API int ES_DECODER_Open(ES_DECODE_TYPE type);


/*
 *	��������;
 *
 *	@param[in]	hDecoder	���������;
 *	@param[in]	pData		��������;
 *	@param[in]	nDataSize	���ݴ�С;
 */
DECODER_API ES_ERROR_CODE ES_DECODER_PushData(int hDecoder, const char* pData, int nDataSize, char *pDest, int *nDest);


/*
 *	�رձ�����;
 *
 *	@param[in]	hEncoder	���������;
 */
DECODER_API void ES_DECODER_Close(int hDecoder);


#ifdef __cplusplus
}
#endif


#endif
