#include "fileopenerror.h"

FileOpenError::FileOpenError(const std::string& fileNameIn):FileError(fileNameIn)
{
    mMsg="Unable to open"+fileNameIn;
}
