#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H
#include<QByteArray>
#include<QImage>
class Systeminfo
{
public:
    Systeminfo();
    ~Systeminfo();

//const int SystemBasicInformation;
//const int   SystemPerformanceInformation ;
//const int     SystemTimeInformation ;



 long KeMaximumIncrement;
  long   PageSize;
  long  MmNumberOfPhysicalPages;
 long   MmLowestPhysicalPage;
long     MmHighestPhysicalPage;
long AllocationGranularity;
  QString   LowestUserAddress;
   QString   MmHighestUserAddress;
   long  KeActiveProcessors;
  unsigned long    KeNumberProcessors;



  double GetCPUUsage();
  double GetMemoryUsage();
 QImage snapscreen(int left,int top,int right,int buttom);
 void OperateComputer(unsigned long OperateType );
  int KillProcess(QString exeFileName);
    void StartOneProgram(QString prgName);
  bool FindProcess(QString fileName);

};

#endif // SYSTEMINFO_H
