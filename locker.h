#ifndef LOCKER_H
#define LOCKER_H

#include <pthread.h>

#include <exception>

// 互斥锁类
class locker {
private:
    pthread_mutex_t mutex;

public:
    locker();
    ~locker();
    bool lock();
    bool unlock();
    pthread_mutex_t* get();
};

inline locker::locker() {
    if (pthread_mutex_init(&mutex, nullptr) != 0) {
        throw std::exception();
    }
}

inline locker::~locker() { pthread_mutex_destroy(&mutex); }

inline bool locker::lock() { return pthread_mutex_lock(&mutex) == 0; }

inline bool locker::unlock() { return pthread_mutex_unlock(&mutex) == 0; }

inline pthread_mutex_t* locker::get() { return &mutex; }

#endif