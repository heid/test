#include "saveimagethread.h"

SaveImageThread::SaveImageThread(QImage image, QString fileName, QObject *parent) :
    QThread(parent), m_image(image), m_fileName(fileName) {

}

void SaveImageThread::run() {

    if (m_image.save(m_fileName, "JPG")) {
        qDebug() << "Image " + m_fileName + " saved!";
    } else {
        qDebug() << "Image not saved!";
    }   
}
