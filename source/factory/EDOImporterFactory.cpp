#include "EDOImporterFactory.h"
#include "IBaseEDOImporter.h"

EDOImporterFactory* EDOImporterFactory::m_pInstance = nullptr;
EDOImporterFactory::GarbageCollection EDOImporterFactory::m_sGc;

EDOImporterFactory::EDOImporterFactory()
{

}

EDOImporterFactory::~EDOImporterFactory()
{
	qDeleteAll(m_hashImporters.values());
}

EDOImporterFactory* EDOImporterFactory::instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new EDOImporterFactory;

	}
	return m_pInstance;
}

void EDOImporterFactory::registerImporter(int nTypeID, IBaseEDOImporter* pImporter)
{
	if (!m_hashImporters.contains(nTypeID))
	{
		m_hashImporters.insert(nTypeID, pImporter);
	}
}

IBaseEDOImporter* EDOImporterFactory::getImporter(int nTypeID)
{
	IBaseEDOImporter* pEDOImporter = nullptr;
	if (m_hashImporters.contains(nTypeID))
	{
		pEDOImporter = m_hashImporters[nTypeID];
	}
	else
	{
		pEDOImporter = m_hashImporters[BASE_ID];
	}
	return pEDOImporter;
}

void EDOImporterFactory::importElement(int nTypeID)
{
	IBaseEDOImporter* pImporter = getImporter(nTypeID);
	pImporter->importElement();
}

void EDOImporterFactory::importEdo(int nTypeID)
{
	IBaseEDOImporter* pImporter = getImporter(nTypeID);
	pImporter->importEdo();
}
