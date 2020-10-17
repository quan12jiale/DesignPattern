#include "EDOImporterFactory.h"
#include "BaseEDOImporter.h"
#include "WallEDOImporter.h"
#include "BeamEDOImporter.h"

int main()
{
    EDOImporterFactory::instance()->registerImporter(BASE_ID, new BaseEDOImporter());
    EDOImporterFactory::instance()->registerImporter(WALL_ID, new WallEDOImporter());
    EDOImporterFactory::instance()->registerImporter(BEAM_ID, new BeamEDOImporter());

    EDOImporterFactory::instance()->importElement(WALL_ID);
    EDOImporterFactory::instance()->importEdo(WALL_ID);
    EDOImporterFactory::instance()->importElement(BEAM_ID);
    EDOImporterFactory::instance()->importEdo(BEAM_ID);
    EDOImporterFactory::instance()->importElement(1023);
    EDOImporterFactory::instance()->importEdo(1023);
    return 0;
}
