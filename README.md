# DesignPattern
C++ 设计模式

## 目录

* [策略模式](#strategy)
* [观察者模式](#observer)
* [装饰模式](#decorator)

<a id="strategy"></a>

## 策略模式

<b><details><summary> 代码</summary></b>

```cpp
class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I'm flying!!"; }
};

class FlyNoWay : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I can't fly"; }
};

class FlyRocketPowered : public FlyBehavior
{
public:
	void fly() override { qDebug() << "I'm flying with a rocket!"; }
};
```

```cpp
class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	void quack() override { qDebug() << "Quack"; }
};

class MuteQuack : public QuackBehavior
{
public:
	void quack() override { qDebug() << "<< Silence >>"; }
};

class Squeak : public QuackBehavior
{
public:
	void quack() override { qDebug() << "Squeak"; }
};
```

```cpp
class Duck
{
public:
	virtual void display() = 0;
	void performFly() { flyBehavior->fly(); }
	void performQuack() { quackBehavior->quack(); }
	void swim() { qDebug() << "All ducks float, even decoys!"; }

	void setFlyBehavior(FlyBehavior* fb) { flyBehavior = fb; }
	void setQuackBehavior(QuackBehavior* qb) { quackBehavior = qb; }
protected:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

// 绿头鸭
class MallardDuck : public Duck
{
public:
	MallardDuck() {
		quackBehavior = new Quack;
		flyBehavior = new FlyWithWings;
	}
	void display() override { qDebug() << "I'm a real Mallard duck"; }
};

// 模型鸭
class ModelDuck : public Duck
{
public:
	ModelDuck() {
		quackBehavior = new Quack;
		flyBehavior = new FlyNoWay;
	}
	void display() override { qDebug() << "I'm a model duck"; }
};
```

```cpp
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
```

</details>

<a id="observer"></a>

## 观察者模式

<a id="decorator"></a>

## 装饰模式

<b><details><summary> 代码</summary></b>

```cpp
class Beverage
{
public:
	virtual QString getDescription() const { return description; }
	virtual double cost() const = 0;

protected:
	QString description;
};

// 浓缩咖啡
class Espresso : public Beverage
{
public:
	Espresso() { description = "Espresso"; }
	double cost() const override { return 1.99; }
};

// 综合咖啡
class HouseBlend : public Beverage
{
public:
	HouseBlend() { description = "House Blend Coffee"; }
	double cost() const override { return 0.89; }
};

// 深焙咖啡
class DarkRoast : public Beverage
{
public:
	DarkRoast() { description = "Dark Roast Coffee"; }
	double cost() const override { return 0.99; }
};
```

```cpp
class CondimentDecorator : public Beverage
{
public:
	QString getDescription() const override = 0;
};

// 摩卡
class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Mocha"; }
	double cost() const override { return beverage->cost() + 0.2; }

private:
	Beverage* beverage;
};

// 豆浆
class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Soy"; }
	double cost() const override { return beverage->cost() + 0.15; }

private:
	Beverage* beverage;
};

// 奶泡
class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage) { this->beverage = beverage; }
	QString getDescription() const override { return beverage->getDescription() + ", Whip"; }
	double cost() const override { return beverage->cost() + 0.1; }

private:
	Beverage* beverage;
};
```

```cpp
int main(int argc, char *argv[])
{
    Beverage* beverage = new Espresso;
    qDebug() << beverage->getDescription() << "$" << beverage->cost();

    Beverage* beverage2 = new DarkRoast;
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    qDebug() << beverage2->getDescription() << "$" << beverage2->cost();

    Beverage* beverage3 = new HouseBlend;
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    qDebug() << beverage3->getDescription() << "$" << beverage3->cost();

    return 0;
}
```

</details>
