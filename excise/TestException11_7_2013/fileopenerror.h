#ifndef FILEOPENERROR_H
#define FILEOPENERROR_H
#include"fileerror.h"
/**
 *描述:文件打开错误
 */
class FileOpenError : public FileError
{
public:
    FileOpenError(const std::string& fileNameIn);
};

#endif // FILEOPENERROR_H
