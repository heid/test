#include "threadsafeimagequeue.h"

ThreadSafeImageQueue::ThreadSafeImageQueue(QObject *parent) : QObject(parent) {

}

void ThreadSafeImageQueue::onQueuImage(QImage img) {

    queue(img);
    emit dequeuImage(dequeu());
}

void ThreadSafeImageQueue::queue(const QImage &img) {

    m_mutex.lock();
    if (m_queueImage.size() > 10) {
        QImage blank = m_queueImage.dequeue();
    }
    m_queueImage.enqueue(img);

    m_mutex.unlock();
}

QImage ThreadSafeImageQueue::dequeu() {

    QMutexLocker locker (&m_mutex);

    return m_queueImage.empty() ? QImage() : m_queueImage.dequeue();
}


