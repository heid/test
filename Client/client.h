#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QImage>
#include <QDataStream>
#include <QElapsedTimer>
#include "saveimagethread.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

signals:
    void dataRead(qint64 nsecsDataRead);

public slots:
    void onReadyRead();
    void onDisconnected();
    void onDataRead(qint64 nsecsDataRead);

private slots:
    void on_btnConnect_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *m_socket;

    QElapsedTimer m_DataReceiveTimer;
    quint32 m_nextBlockSize;
};

#endif // CLIENT_H
