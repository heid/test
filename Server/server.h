#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QFile>
#include <QXmlStreamReader>
#include "imagethread.h"
#include "tcpworker.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

public slots:
    void onTimeElapsed(qint64 nsecsImageGenerate, qint64 nsecsFramePeriod);
    void onDataSent(qint64 nsecsDataSend);

private:
    Ui::Server *ui;

    ImageThread *imageThread;
    QThread *tcpThread;
    TcpWorker *worker;
    QMap<QString, int> m_config;

    bool readConfig(QString fileName);
};

#endif // SERVER_H
