#include "prototypemgr.h"

int main()
{
    ProductMgr mgr;
    mgr.loadCache();
    Prototype* prototypeA = mgr.getProduct("prototypeA");
    Prototype* prototypeB = mgr.getProduct("prototypeB");
}