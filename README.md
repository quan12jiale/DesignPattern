# DesignPattern
C++ 设计模式

## 目录

* [策略模式](#strategy)
* [观察者模式](#observer)
* [装饰者模式](#decorator)
* [工厂模式](#factory)
* [单例模式](#singleton)
* [命令模式](#command)
* [适配器模式](#adapter)
* [外观模式](#facade)
* [模板方法模式](#template)
* [迭代器模式](#iterator)
* [组合模式](#composite)

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

## 装饰者模式

<a id="factory"></a>

## 工厂模式

<a id="singleton"></a>

## 单例模式

<a id="command"></a>

## 命令模式

<a id="adapter"></a>

## 适配器模式

<a id="facade"></a>

## 外观模式

<a id="template"></a>

## 模板方法模式

<a id="iterator"></a>

## 迭代器模式

<a id="composite"></a>

## 组合模式

