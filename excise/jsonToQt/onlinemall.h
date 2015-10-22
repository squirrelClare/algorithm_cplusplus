#ifndef ONLINEMALL_H
#define ONLINEMALL_H
#include<QString>
class OnlineMall : public TTradeBase
{
private:
    QString  module;
    QString  ParseQueryShopCategory(QString returnStr);
    QString ParseShopHomePageInfo(QString returnStr);
    QString ParseShopProductInfo(QString,returnStr);
    QString ParseBuyProduct(QString Str);
    void GetShopCategory(Json *json,QDomElement node,int level);

    void InitPrintInfo();
    void SetBasePrintInfo(QString busstype, QString trancode,QString  tranmoney, QString trantime );
    void  SetPrintInfoSystemCode(QString systemcode);
    void SetOrderNo(QString orderno);
public:
    OnlineMall(Debugger *debug);//****
    ~OnlineMall();

    QString QueryShopCategory(Json *json);
    QString QueryShopHomepageInfo(Json *json);
    QString QueryShopProductInfo(Json *json);
    QString BuyProduct(Json *json);
    QString ExecuteCharge(Json *json);
    QString GetChargeMoney(Json *json);
    QString GetChargeTxCode(Json *json);


};

#endif // ONLINEMALL_H
