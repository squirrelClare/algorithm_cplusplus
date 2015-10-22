#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void Stop();
private:
    volatile bool stopped;
protected:
    void run();
    
signals:
    
public slots:
    
};

#endif // MYTHREAD_H
