#include <QCoreApplication>
#include<iostream>
#include<QStringList>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString winter = "December, January, February";
        QString spring = "March, April, May";
        QString summer = "June, July, August";
        QString fall = "September, October, November";

        QStringList list;
        list << winter;
        list += spring;
        list.append(summer);
        list << fall;

        qDebug() << "The Spring months are: " << list[1] ;

        QString allmonths = list.join(", ");
        /* from list to string - join with a ", " delimiter */
        qDebug() << allmonths;

        QStringList list2 = allmonths.split(", ");
        /* split is the opposite of join. Each month will have its
        own element. */

        //assert(list2.size() == 12);
        qDebug()<<"**********************************************************";
        foreach (QString str, list)  {
          qDebug() << QString(" [%1] ").arg(str);
           // qDebug()<<str;
        }

        for (QStringList::iterator it = list.begin();
             it != list.end(); ++it) {
            QString current = *it;
            qDebug() << "[[" << current << "]]";
        }

        QListIterator<QString> itr (list2);
        while (itr.hasNext()) {
            QString current = itr.next();
            qDebug() << "{" <<  current << "}";
        }




    return a.exec();
}
