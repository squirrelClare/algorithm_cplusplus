#include "testqdatasream.h"

TestQDataSream::TestQDataSream()
{
}

void TestQDataSream::testOut()
{
    QFile file("C:\\Users\\lenovo\\Desktop\\file.dat");
     file.open(QIODevice::WriteOnly);
     QDataStream out(&file);   // we will serialize the data into the file
     out.setVersion(QDataStream::Qt_4_0);

     out << (qint32)42;        // serialize an integer

     out << (quint32)0xA0B0C0D0;
     out << (qint32)123;

     // Write the data
     out << QString("lots_of_interesting_data");
     out << QString("the answer is");   // serialize a string
     out<<QString("Hello Word!ÄãºÃ!");
}

void TestQDataSream::testIn()
{
    QFile file("C:\\Users\\lenovo\\Desktop\\file.dat");
     file.open(QIODevice::ReadOnly);
     QDataStream in(&file);    // read the data serialized from the file
     QString str;
     qint32 a,b,c;
     QString str1;
//     in >> str1 >> a>>str>>b>>c;           // extract "the answer is" and 42
//     qDebug()<<str<<a<<str1<<b<<c;
}

void TestQDataSream::others()
{
    QFile file("C:\\Users\\lenovo\\Desktop\\file.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    // Read and check the header
    quint32 magic;
    in >> magic;
    if (magic != 0xA0B0C0D0)
        qDebug()<<"XXX_BAD_FILE_FORMAT";

    // Read the version
    qint32 version;
    in >> version;
    if (version < 100)
        qDebug()<<"XXX_BAD_FILE_TOO_OLD";
    if (version > 123)
        qDebug()<<" XXX_BAD_FILE_TOO_NEW";

    if (version <= 110)
        in.setVersion(QDataStream::Qt_4_7);
    else
        in.setVersion(QDataStream::Qt_4_0);

    qint32 lots_of_interesting_data,data_new_in_XXX_version_1_2;
    // Read the data
    in >> lots_of_interesting_data;
    if (version >= 120)
        in >> data_new_in_XXX_version_1_2;
}
