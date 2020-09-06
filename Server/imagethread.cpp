#include "imagethread.h"

ImageThread::ImageThread(int width, int height, int msPeriod, QObject *parent) :
    QThread(parent), m_width(width), m_height(height), m_period(msPeriod) {

}

void ImageThread::run() {
    QTimer m_imageGenTimer;

    connect(&m_imageGenTimer, &QTimer::timeout, this, &ImageThread::runGenerate, Qt::DirectConnection);
    m_imageGenTimer.start(m_period);

    exec();
}

void ImageThread::runGenerate() {
    QElapsedTimer timer;
    QByteArray m_data;

    timer.start();
    // m_data.clear();
    for (int i = 0; i < m_width * m_height; i++) {
        m_data.append(qrand() % 256);
    }
    QImage image((const uchar*)m_data.constData(), m_width, m_height, QImage::Format_Grayscale8);

    emit imageGenerated(image.copy(0, 0, image.width(), image.height()));
    emit timeElapsed(timer.nsecsElapsed(), m_fpsTimer.nsecsElapsed());
    m_fpsTimer.restart();

    // qDebug() << "Thread working...";
}

void ImageThread::onFinished() {

    quit();
    wait();
}
