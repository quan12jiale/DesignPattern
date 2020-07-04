#pragma once
#include <QVariant>

class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual QVariant next() = 0;
};

class Container
{
public:
	virtual Iterator* getIterator() = 0;
};

class NameIterator : public Iterator
{
private:
	int index;
	QStringList names;

public:
	NameIterator(const QStringList& names)
	{
		this->names = names;
		index = 0;
	}
	bool hasNext() override
	{
		if (index < names.size())
		{
			return true;
		}
		return false;
	}
	QVariant next() override
	{
		return names[index++];
	}
};

class NameRepository : public Container
{
private:
	QStringList names;

public:
	NameRepository(const QStringList& names)
	{
		this->names = names;
	}
	Iterator* getIterator() override 
	{
		return new NameIterator(names);
	}
};
