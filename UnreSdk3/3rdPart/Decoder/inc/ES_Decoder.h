
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
 *	设置日志回调函数;
 *
 *	@param[in]	pCallback	日志回调;
 *	@param[in]	pUser		用户数据;
 */
DECODER_API void ES_DECODER_SetLogCallback(ES_LogCallback pCallback, void *pUser);


/*
 *	开启解码器;
 *
 *	@param[in]	type	解码类型;
 *
 *	@return	返回解码器句柄;
 */
DECODER_API int ES_DECODER_Open(ES_DECODE_TYPE type);


/*
 *	解码数据;
 *
 *	@param[in]	hDecoder	编码器句柄;
 *	@param[in]	pData		编码数据;
 *	@param[in]	nDataSize	数据大小;
 */
DECODER_API ES_ERROR_CODE ES_DECODER_PushData(int hDecoder, const char* pData, int nDataSize, char *pDest, int *nDest);


/*
 *	关闭编码器;
 *
 *	@param[in]	hEncoder	编码器句柄;
 */
DECODER_API void ES_DECODER_Close(int hDecoder);


#ifdef __cplusplus
}
#endif


#endif
