#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);

    m_nextBlockSize = 0;
}

Client::~Client() {

    delete ui;
}

static int counter = 0;

void Client::onReadyRead() {

    QDataStream stream(m_socket);
    stream.setVersion(QDataStream::Qt_4_2);

    while (1) {
        if (!m_nextBlockSize) {
            if (m_socket->bytesAvailable() < sizeof(quint32)) {
                break;
            }
            m_DataReceiveTimer.restart();
            stream >> m_nextBlockSize;
        }

        if (m_socket->bytesAvailable() < m_nextBlockSize) {
            break;
        }

        QImage image;
        stream >> image;

        if (!image.isNull()) {
            onDataRead(m_DataReceiveTimer.nsecsElapsed());

            SaveImageThread *thread = new SaveImageThread(image, QString("%1.jpg")
                                                          .arg(counter++), this);
            connect(thread, &SaveImageThread::finished, thread, &SaveImageThread::deleteLater);
            thread->start();

            QImage scaledImage = image.scaled(ui->lblImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->lblImage->setPixmap(QPixmap::fromImage(scaledImage));

            ui->lblImageInfo->setText(QString("%1 x %2")
                                      .arg(image.width())
                                      .arg(image.height()));
        }

        m_nextBlockSize = 0;
    }
}

void Client::onDisconnected() {

    m_socket->disconnectFromHost();

    qDebug() << "Disconnected from host.";
    ui->btnConnect->setText("Connect");
}

void Client::onDataRead(qint64 nsecsDataRead) {

    ui->lblNetElapsed->setText(QString("Data read in %1 us")
                               .arg(nsecsDataRead/1000));
}

void Client::on_btnConnect_clicked() {

    if (ui->btnConnect->text() == "Connect") {
        m_socket->connectToHost(ui->leIP->text(), ui->lePort->text().toInt());

        /*if (m_socket->error()) {
            qDebug() << QString("SocketState: %1, SocketError: %2 - %3")
                        .arg(m_socket->state())
                        .arg(m_socket->error())
                        .arg(m_socket->errorString());

            return;
        }*/

        qDebug() << "Connected to host.";

        ui->btnConnect->setText("Disconnect");
    } else {
        m_socket->disconnectFromHost();

        ui->btnConnect->setText("Connect");
    }
}
