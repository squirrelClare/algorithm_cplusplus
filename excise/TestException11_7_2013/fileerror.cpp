#include "fileerror.h"

FileError::FileError():runtime_error("")
{

}

FileError::FileError(const std::string &fileIn):runtime_error(""),mFile(fileIn)
{
}

const char *FileError::what() const noexcept
{
    return mMsg.c_str();
}

std::string FileError::GetFileName()
{
    return this->mFile;
}
