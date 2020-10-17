#pragma once
#include <QHash>

enum EDOTypeID
{
	BASE_ID,
	WALL_ID,
	BEAM_ID
};

class IBaseEDOImporter;
class EDOImporterFactory
{
public:
	static EDOImporterFactory* instance();
	void registerImporter(int nTypeID, IBaseEDOImporter* pImporter);

public:
	void importElement(int nTypeID);
	void importEdo(int nTypeID);

private:
	EDOImporterFactory();
	~EDOImporterFactory();

private:
	IBaseEDOImporter* getImporter(int nTypeID);

private:
	QHash<int, IBaseEDOImporter*> m_hashImporters;
	static EDOImporterFactory* m_pInstance; //对象指针为单例指针类保证了只有一个对象

	class GarbageCollection // 回收单例内存
	{
	public:
		GarbageCollection()
		{
		}
		~GarbageCollection()
		{
			if (m_pInstance != nullptr)
			{
				delete m_pInstance;
				m_pInstance = nullptr;
			}
		}
	};
	static GarbageCollection m_sGc;  //回收类的静态成员
};