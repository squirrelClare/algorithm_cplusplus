#include <QCoreApplication>
#include<QFile>
#include<QDomDocument>
#include<QDomText>
#include<QTextStream>
#include<QDebug>
int main(int argc, char *argv[])

{QCoreApplication a(argc,argv);

       QFile file( "domwrite.kdevelop" );

       if ( !file.open( QIODevice::WriteOnly | QIODevice::Truncate ) ){
              return 0;
       }else{
           qDebug()<<"OPEN!";
       }



       QDomDocument doc;

       QDomText text;

       QDomElement element;

       QDomProcessingInstruction instruction;

       instruction = doc.createProcessingInstruction( "xml", "version = \'1.0\'" );

       doc.appendChild( instruction );

       QDomElement root = doc.createElement( "kdevelop" );

       doc.appendChild( root );

       QDomElement general = doc.createElement( "general" );

       root.appendChild( general );



       element = doc.createElement( "author" );

       text = doc.createTextNode( "zeki" );



       general.appendChild( element );
        element.appendChild( text );



       element = doc.createElement( "email" );

       text = doc.createTextNode( "caizhiming@tom.com" );

       element.appendChild( text );

       general.appendChild( element );



       element = doc.createElement( "version" );

       text = doc.createTextNode( "$VERSION" );

       element.appendChild( text );

       general.appendChild( element );



       QDomElement keywords = doc.createElement( "keywords" );

       element = doc.createElement( "keyword" );

       text = doc.createTextNode( "C++" );

       element.appendChild( text );

       keywords.appendChild( element );

       general.appendChild( keywords );



       element = doc.createElement( "ignoreparts" );

       general.appendChild( element );



       QDomElement kdevfileview = doc.createElement( "kdevfileview" );

       QDomElement groups = doc.createElement( "groups" );

       element = doc.createElement( "group" );

       QDomAttr pattern = doc.createAttribute( "pattern" );

       pattern.setValue( "*.cpp;*.cxx;*.h" );

       QDomAttr name = doc.createAttribute( "name" );

       name.setValue( "Sources" );

       element.setAttributeNode( pattern );

       element.setAttributeNode( name );

       groups.appendChild( element );

       kdevfileview.appendChild( groups );

       root.appendChild( kdevfileview );





       QTextStream out( &file );

       doc.save( out, 4 );

    file.close();

       a.exec();

}
