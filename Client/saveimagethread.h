#ifndef SAVEIMAGETHREAD_H
#define SAVEIMAGETHREAD_H

#include <QThread>
#include <QImage>
#include <QDebug>

class SaveImageThread : public QThread {
    Q_OBJECT

public:
    SaveImageThread(QImage image, QString fileName, QObject *parent = 0);

    void run();

private:
    QImage m_image;
    QString m_fileName;
};

#endif // SAVEIMAGETHREAD_H
