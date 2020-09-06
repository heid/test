#ifndef TCPWORKER_H
#define TCPWORKER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QElapsedTimer>
#include <QDataStream>
#include <QImage>

class TcpWorker : public QTcpServer {
    Q_OBJECT

public:
    TcpWorker(int port, int msPeriod, QObject *parent = 0);

    void incomingConnection(int handle);

signals:
    void dataSent(qint64 nsecsDataSend);

public slots:
    void startServer();
    void onDataSend();
    void onDisconnected();
    void onImageGenerated(QImage image);

private:
    QTcpSocket *m_socket;
    QTimer *m_dataSendTimer;
    QImage m_image;
    int m_port;
    int m_period;
};

#endif // TCPWORKER_H
