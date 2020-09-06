#ifndef IMAGETHREAD_H
#define IMAGETHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QImage>
#include <QElapsedTimer>
#include <QDebug>

class ImageThread : public QThread {
    Q_OBJECT

public:
    ImageThread(int width, int height, int msPeriod, QObject *parent = 0);

    void run();

signals:
    void timeElapsed(qint64 nsecsImageGenerate, qint64 nsecsFramePeriod);
    void imageGenerated(QImage img);

public slots:
    void runGenerate();
    void onFinished();

private:
    int m_width;
    int m_height;
    int m_period;
    // QByteArray m_data;
    QElapsedTimer m_fpsTimer;
};

#endif // IMAGETHREAD_H
