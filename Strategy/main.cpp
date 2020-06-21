#include "duck.h"

int main(int argc, char *argv[])
{
    Duck* mallard = new MallardDuck;
    mallard->performQuack();
    mallard->performFly();

    Duck* model = new ModelDuck;
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered);
    model->performFly();

    return 0;
}
