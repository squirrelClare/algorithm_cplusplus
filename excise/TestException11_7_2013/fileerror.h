#ifndef FILEERROR_H
#define FILEERROR_H
#include<exception>
#include<stdexcept>
/**描述:自定以一个异常类,继承runtime_error,"文件类型错误"
 *自定义异常类,主要是重载what()函数.
 *问题:为什么自定义的异常类包括FileError和FileOpenError的构造函数都要调用自己父类的构造函数
 *猜测答案:异常的信息主要存储在mMsg中,而mMsg初始化由runtime_error()完成
 *
 *后续在FileOpenError的构造函数中屏蔽掉父类构造函数的调用后,自定义异常还是正常执行.由此证实猜测是正确的
    */
class FileError:public std::runtime_error
{
public:
    FileError();
    FileError(const std::string &fileIn);
    virtual const char *what() const noexcept;
    std::string GetFileName();
protected:
    std::string mFile,mMsg;
};
#endif // FILEERROR_H
