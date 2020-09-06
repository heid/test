#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    if (readConfig("xml/config.xml")) {
        qDebug() << "Сonfiguration load ok";
    } else {
        qDebug() << "Сonfiguration load error!";
    }

    tcpThread = new QThread(this);
    connect(this, &Server::destroyed, tcpThread, &QThread::deleteLater);

    worker = new TcpWorker(m_config.value("Port", 8888), m_config.value("NetPeriod", 1000));
    worker->moveToThread(tcpThread);
    connect(tcpThread, &QThread::started, worker, &TcpWorker::startServer);
    connect(worker, &TcpWorker::dataSent, this, &Server::onDataSent);
    connect(tcpThread, &QThread::finished, worker, &TcpWorker::deleteLater);

    tcpThread->start();

    imageThread = new ImageThread(m_config.value("X", 320), m_config.value("Y", 240), m_config.value("FramePeriod", 1000), this);
    connect(this, &Server::destroyed, imageThread, &ImageThread::onFinished);
    connect(imageThread, &ImageThread::finished, imageThread, &ImageThread::deleteLater);

    connect(imageThread, &ImageThread::timeElapsed, this, &Server::onTimeElapsed);
    connect(imageThread, &ImageThread::imageGenerated, worker, &TcpWorker::onImageGenerated);

    imageThread->start();
}

Server::~Server() {
    tcpThread->quit();
    tcpThread->wait();
    delete ui;
}

void Server::onTimeElapsed(qint64 nsecsImageGenerate, qint64 nsecsFramePeriod) {

    ui->lblImgElapsed->setText(QString("Image generate in %1 us")
                               .arg(nsecsImageGenerate/1000));
    ui->lblFps->setText(QString("FPS %1")
                        .arg(1 / (nsecsFramePeriod / 1000000000.0)));
}

void Server::onDataSent(qint64 nsecsDataSend) {

    ui->lblNetElapsed->setText(QString("Data sent in %1 us")
                               .arg(nsecsDataSend/1000));
}

bool Server::readConfig(QString fileName) {

    QFile *file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Config read error!";

        return false;
    }

    QXmlStreamReader xmlReader(file);
    while (!xmlReader.atEnd() && !xmlReader.hasError()) {
        if (xmlReader.isStartElement()) {
            if (xmlReader.name() == "net") {
                do {
                    xmlReader.readNext();
                    if (xmlReader.isStartElement()) {
                        m_config[xmlReader.name().toString()] = xmlReader.readElementText().toInt();
                    }
                } while (!(xmlReader.isEndElement() && xmlReader.name() == "net"));
            } else if (xmlReader.name() == "image") {
                do {
                    xmlReader.readNext();
                    if (xmlReader.isStartElement()) {
                        m_config[xmlReader.name().toString()] = xmlReader.readElementText().toInt();
                    }
                } while (!(xmlReader.isEndElement() && xmlReader.name() == "image"));
            }
        }
        xmlReader.readNext();
    }
    file->close();

    if (xmlReader.hasError()) {
        qDebug() << xmlReader.errorString();

        return false;
    }

    return true;
}
