#include "tcpworker.h"

TcpWorker::TcpWorker(int port, int msPeriod, QObject *parent) :
    QTcpServer(parent), m_port(port), m_period(msPeriod) {

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpWorker::onDisconnected, Qt::DirectConnection);

    m_dataSendTimer = new QTimer(this);
    connect(m_dataSendTimer, &QTimer::timeout, this, &TcpWorker::onDataSend, Qt::DirectConnection);
}

void TcpWorker::incomingConnection(int handle) {

    m_socket->setSocketDescriptor(handle);

    qDebug() << handle << "Client connected.";

    m_dataSendTimer->start(m_period);
}

void TcpWorker::startServer() {

    if (this->listen(QHostAddress::Any, m_port)) {
        qDebug() << "Server started!";
    } else {
        qDebug() << "Server not started!";
    }
}

void TcpWorker::onDataSend() {
    QElapsedTimer timer;
    QByteArray arrBlock;

    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    timer.start();
    out << quint32(0) << m_image;
    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));

    m_socket->write(arrBlock);

    emit dataSent(timer.nsecsElapsed());
}

void TcpWorker::onDisconnected() {

    m_dataSendTimer->stop();

    m_socket->disconnect();
    m_socket->close();

    qDebug() << "Client disconnected.";
}

void TcpWorker::onImageGenerated(QImage image) {

    m_image = image;
}
