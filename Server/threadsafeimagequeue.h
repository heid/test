#ifndef THREADSAFEIMAGEQUEUE_H
#define THREADSAFEIMAGEQUEUE_H

#include <QObject>
#include <QQueue>
#include <QMutex>
#include <QImage>

class ThreadSafeImageQueue : public QObject {
    Q_OBJECT

public:
    explicit ThreadSafeImageQueue(QObject *parent = nullptr);

signals:
    void dequeuImage(QImage img);

public slots:
    void onQueuImage(QImage img);

private:
    void queue(const QImage &img);
    QImage dequeu();

    QMutex	m_mutex;
    QQueue<QImage> m_queueImage;

};

#endif // THREADSAFEIMAGEQUEUE_H
