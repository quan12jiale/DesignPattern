#include "adapter.h"

static void testDuck(Duck* duck)
{
    duck->quack();
    duck->fly();
}

int main(int argc, char *argv[])
{
    MallardDuck* duck = new MallardDuck;

    WildTurkey* turkey = new WildTurkey;
    Duck* turkeyAdapter = new TurkeyAdapter(turkey);

    qDebug() << "The Turkey says...";
    turkey->gobble();
    turkey->fly();

    qDebug() << "\nThe Duck says...";
    testDuck(duck);

    qDebug() << "\nThe TurkeyAdapter says...";
    testDuck(turkeyAdapter);

    return 0;
}
