#include "refinedAbstraction.h"
#include "concreteImplementor.h"

int main()
{
    Image* image = new JPGImage;
    ImageImp* imageImp = new WindowsImp;
    image->setImageImp(imageImp);
    image->parseFile("ÁõÒà·Æ");
    return 0;
}