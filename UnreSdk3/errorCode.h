//this head file is included in "logg.h"
#ifndef _ERROR_CODE_H_
#define _ERROR_CODE_H_
#define UNRE_FUNCTION_SUCCESS (0X0000) //执行成功
#define UNRE_READ_JSON_FAILED (0X0001) //
#define UNRE_REGISTER_NO_SUCH_ITEM (0X0002) //删注册表发现没有满足条件的选项
#define UNRE_REGISTER_FATAL_ERROR (0X0003)  //几个注册表不匹配，出现了一个表里删除项成功另一个表删除项失败
#define UNRE_REGISTER_ADD_ERRPR (0X0004)
#endif