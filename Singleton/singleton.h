#pragma once
#include <qDebug>
#include <QMutexLocker>

//#define lazy_loading
//#define eager_loading
#define DCL

#ifdef lazy_loading // 懒汉式

class Singleton
{
public:
	static Singleton* getInstance()
	{
		QMutexLocker locker(&mutex);
		if (uniqueInstance == nullptr)
		{
			uniqueInstance = new Singleton;
		}
		return uniqueInstance;
	}

	void showMessage() { qDebug() << "Hello World!"; }
private:
	static Singleton* uniqueInstance;
	static QMutex mutex;
	Singleton() = default;
};

Singleton* Singleton::uniqueInstance = nullptr;
QMutex Singleton::mutex;

#endif // lazy_loading


#ifdef eager_loading // 饿汉式

class Singleton
{
public:
	static Singleton* getInstance() { return uniqueInstance; }

	void showMessage() { qDebug() << "Hello World!"; }
private:
	static Singleton* uniqueInstance;
	Singleton() = default;
};

Singleton* Singleton::uniqueInstance = new Singleton;

#endif // eager_loading


#ifdef DCL // double-checked locking，双重检查加锁

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (uniqueInstance == nullptr)
		{
			QMutexLocker locker(&mutex);
			if (uniqueInstance == nullptr)
				uniqueInstance = new Singleton;
		}
		return uniqueInstance;
	}

	void showMessage() { qDebug() << "Hello World!"; }
private:
	static Singleton* uniqueInstance;
	static QMutex mutex;
	Singleton() = default;
};

Singleton* Singleton::uniqueInstance = nullptr;
QMutex Singleton::mutex;

#endif // lazy_loading
