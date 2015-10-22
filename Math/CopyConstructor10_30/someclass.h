#ifndef SOMECLASS_H
#define SOMECLASS_H
#include<QString>

class SomeClass
{
public:
    SomeClass();
    SomeClass(QString inString,int inValue);
    SomeClass(const SomeClass& src);
    QString GetString() const;
    int GetValue() const;
    SomeClass& SetString(const QString &inString);
    SomeClass& SetValue(const int& inValue);

    SomeClass& operator =(const SomeClass& src);
    SomeClass& operator +=(const SomeClass& src);
private:
    QString mString;
    int mValue;
};

#endif // SOMECLASS_H
