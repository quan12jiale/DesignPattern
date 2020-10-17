# DesignPattern
C++ 设计模式

## 目录

### 创建型模式

* [工厂模式](#factory)
* [抽象工厂模式](#abstractfactory)
* [单例模式](#singleton)
* [生成器模式](#builder)
* [原型模式](#prototype)

### 结构型模式

* [适配器模式](#adapter)
* [桥接模式](#bridge)
* 过滤器模式
* [组合模式](#composite)
* [装饰者模式](#decorator)
* [外观模式](#facade)
* [享元模式](#flyweight)
* [代理模式](#proxy)

### 行为型模式

* 责任链模式
* [命令模式](#command)
* 解释器模式
* [迭代器模式](#iterator)
* 中介者模式
* 备忘录模式
* [观察者模式](#observer)
* [状态模式](#state)
* 空对象模式
* [策略模式](#strategy)
* [模板方法模式](#template)
* 访问者模式

### 复合模式

* [MVC模式](#MVC)


<a id="strategy"></a>

## 策略模式

<p><b>定义：</b>定义了算法族，分别封装起来，让它们之间可以互相替换。</p>
<p><b>主要解决：</b>在有多种算法相似的情况下，使用 if...else 所带来的复杂和难以维护。</p>
<p><b>优点：</b>
1、算法可以自由切换。
2、避免使用多重条件判断。
3、扩展性良好。
</p>
<p><b>缺点：</b>
1、策略类会增多。
2、所有策略类都需要对外暴露。
</p>
<p><b>使用场景：</b>
1、如果在一个系统里面有许多类，它们之间的区别仅在于它们的行为，那么使用策略模式可以动态地让一个对象在许多行为中选择一种行为。
2、一个系统需要动态地在几种算法中选择一种。
3、如果一个对象有很多的行为，如果不用恰当的模式，这些行为就只好使用多重的条件选择语句来实现。
</p>
<p><b>注意事项：</b>如果一个系统的策略多于四个，就需要考虑使用混合模式，解决策略类膨胀的问题。</p>
<p><b>类图：</b>策略接口：Strategy类，Contex类中有一个Strategy类的指针。</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/strategy_pattern_uml_diagram.jpg" alt="策略模式的 UML 图" />

<a id="observer"></a>

## 观察者模式

<p><b>定义：</b>定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。</p>
<p><b>主要解决：</b>一个对象状态改变给其他对象通知的问题，而且要考虑到易用和低耦合，保证高度的协作。</p>
<p><b>优点：</b>
1、观察者和被观察者是抽象耦合的。
2、建立一套触发机制。
</p>
<p><b>缺点：</b>
1、如果一个被观察者对象有很多的直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间。
2、如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，可能导致系统崩溃。
3、观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。
</p>
<p><b>注意事项：</b>
1、避免循环引用。
2、如果顺序执行，某一观察者错误会导致系统卡壳，一般采用异步方式。
</p>
<p><b>类图：</b>
<br>Subject接口：声明registerObserver、removeObserver、notifyObservers纯虚函数，以及QList<Observer*> observers的成员。
<br>Observer接口声明update纯虚函数，以及Subject* subject的成员。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/observer_pattern_uml_diagram.jpg" alt="观察者模式的 UML 图" />

<a id="decorator"></a>

## 装饰者模式

<p><b>定义：</b>动态地将责任附加到对象上。就扩展功能来说，装饰者提供了比继承更有弹性的替代方案</p>
<p><b>主要解决：</b>一般的，我们为了扩展一个类经常使用继承方式实现，由于继承为类引入静态特征，并且随着扩展功能的增多，子类会很膨胀。</p>
<p><b>优点：</b>装饰类和被装饰类可以独立发展，不会相互耦合，装饰模式是继承的一个替代模式，装饰模式可以动态扩展一个实现类的功能。</p>
<p><b>缺点：</b>多层装饰比较复杂。</p>
<p><b>使用场景：</b>
1、扩展一个类的功能。
2、动态增加功能，动态撤销。
</p>
<p><b>注意事项：</b>可代替继承。</p>
<p><b>类图：</b>
<br>组件：定义Beverage饮料接口，以及cost价格纯虚函数；定义实现了Beverage接口的具体饮料类。
<br>装饰者：定义继承了Beverage接口的CondimentDecorator调料装饰者接口；定义实现了调料装饰者接口的具体调料类，其中有一个Beverage类型的指针成员。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/decorator_pattern_uml_diagram.jpg" alt="装饰者模式的 UML 图" />

<a id="factory"></a>

## 工厂模式

<a id="abstractfactory"></a>

## 抽象工厂模式

<a id="singleton"></a>

## 单例模式

<p><b>意图：</b>保证一个类仅有一个实例，并提供一个访问它的全局访问点。</p>
<p><b>主要解决：</b>一个全局使用的类频繁地创建与销毁。</p>
<p><b>优点：</b></p><ul><li>
1、在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例。</li><li>
2、避免对资源的多重占用（比如写文件操作）。
</li></ul>
<p><b>缺点：</b>没有接口，不能继承，与单一职责原则冲突，一个类应该只关心内部逻辑，而不关心外面怎么样来实例化。</p>
<p><b>使用场景：</b></p>
<ul><li>
1、创建的一个对象需要消耗的资源过多，比如 I/O 与数据库的连接等。</li></ul>
<p><b>注意事项：</b>getInstance() 方法中需要使用互斥锁 防止多线程同时进入造成 instance 被多次实例化。</p>
<p><b>类图：</b>
<br>私有的构造函数；私有的静态指向单例的指针成员；公有的getInstance函数。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/singleton_pattern_uml_diagram.jpg" alt="单例模式的 UML 图" />

<a id="command"></a>

## 命令模式

<p><b>定义：</b>将“请求”封装成对象，以便使用不同的请求、队列或者日志来参数化其他对象。命令模式也支持可撤销的操作。</p>
<p><b>主要解决：</b>在软件系统中，行为请求者与行为实现者通常是一种紧耦合的关系，但某些场合，比如需要对行为进行记录、撤销或重做、事务等处理时，这种无法抵御变化的紧耦合的设计就不太合适。</p>
<p><b>优点：</b>
1、降低了系统耦合度。
2、新的命令可以很容易添加到系统中去。
</p> 
<p><b>缺点：</b>使用命令模式可能会导致某些系统有过多的具体命令类。</p>
<p><b>使用场景：</b>认为是命令的地方都可以使用命令模式，比如：
1、GUI 中每一个按钮都是一条命令。
2、模拟 CMD。
</p>
<p><b>注意事项：</b>系统需要支持命令的撤销(Undo)操作和恢复(Redo)操作，也可以考虑使用命令模式，见命令模式的扩展。</p>
<p><b>类图：</b>
<br>Receiver；接收者，真正执行命令的对象，定义了buy，sell函数。
<br>声明Command接口，及execute纯虚函数；分别针对buy，sell函数，定义实现了Command接口的BuyCommand和SellCommand具体类，其中有一个Receiver* receiver成员。Qt中有QUndoCommand类。
<br>Invoker；调用者，有一个QList<Command*> commandList成员，以及addCommand和runCommand(int index)函数。Qt中有QUndoStack类。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/command_pattern_uml_diagram.jpg" alt="命令模式的 UML 图" />

<a id="adapter"></a>

## 适配器模式

<p><b>定义：</b>将一个类的接口转换成客户希望的另外一个接口。适配器模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。</p>
<p><b>主要解决：</b>主要解决在软件系统中，常常要将一些"现存的对象"放到新的环境中，而新环境要求的接口是现对象不能满足的。</p>
<p><b>优点：</b>
1、可以让任何两个没有关联的类一起运行。
2、提高了类的复用。
3、增加了类的透明度。
4、灵活性好。
</p>
<p><b>缺点：</b>
1、过多地使用适配器，会让系统非常零乱，不易整体进行把握。比如，明明看到调用的是 A 接口，其实内部被适配成了 B 接口的实现，一个系统如果太多出现这种情况，无异于一场灾难。因此如果不是很有必要，可以不使用适配器，而是直接对系统进行重构。
2.由于 JAVA 至多继承一个类，所以至多只能适配一个适配者类，而且目标类必须是抽象类。
</p>
<p><b>使用场景：</b>有动机地修改一个正常运行的系统的接口，这时应该考虑使用适配器模式。</p>
<p><b>注意事项：</b>适配器不是在详细设计时添加的，而是解决正在服役的项目的问题。</p>
<p><b>类图：</b>
<br>Target接口；想适配成的目标。
<br>Adaptee接口：被适配者，以及实现了Adaptee接口的具体类。
<br>Adapter；对象适配器，继承了Target接口，有一个Adaptee指针成员；类适配器，同时继承Target接口和Adaptee接口。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/adapter_pattern_uml_diagram.jpg" alt="适配器模式的 UML 图" />

<a id="facade"></a>

## 外观模式

<p><b>意图：</b>为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。</p>
<p><b>主要解决：</b>降低访问复杂系统的内部子系统时的复杂度，简化客户端与之的接口。</p>
<p><b>优点：</b>
1、减少系统相互依赖。
2、提高灵活性。
3、提高了安全性。
</p>
<p><b>缺点：</b>不符合开闭原则，如果要改东西很麻烦，继承重写都不合适。</p>
<p><b>使用场景：</b>
1、为复杂的模块或子系统提供外界访问的模块。
2、子系统相对独立。
3、预防低水平人员带来的风险。
</p>
<p><b>注意事项：</b>在层次化结构中，可以使用外观模式定义系统中每一层的入口。</p>

<a id="template"></a>

## 模板方法模式

<p><b>意图：</b>定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。</p>
<p><b>主要解决：</b>一些方法通用，却在每一个子类都重新写了这一方法。</p>
<p><b>优点：</b>
1、封装不变部分，扩展可变部分。
2、提取公共代码，便于维护。
3、行为由父类控制，子类实现。
</p>
<p><b>缺点：</b>每一个不同的实现都需要一个子类来实现，导致类的个数增加，使得系统更加庞大。</p>
<p><b>使用场景：</b>
1、有多个子类共有的方法，且逻辑相同。
2、重要的、复杂的方法，可以考虑作为模板方法。</p>
<p><b>注意事项：</b>为防止恶意操作，一般模板方法都加上 final 关键词。</p>
<p><b>类图：</b>创建一个抽象类，它的模板方法被设置为 final。</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/template_pattern_uml_diagram.jpg" alt="模板方法模式的 UML 图" />

<a id="iterator"></a>

## 迭代器模式

<p><b>意图：</b>提供一种方法顺序访问一个聚合对象中各个元素, 而又无须暴露该对象的内部表示。</p>
<p><b>关键代码：</b>定义接口：hasNext, next。</p>
<p><b>优点：</b>
1、它支持以不同的方式遍历一个聚合对象。
2、迭代器简化了聚合类。
3、在同一个聚合上可以有多个遍历。
4、在迭代器模式中，增加新的聚合类和迭代器类都很方便，无须修改原有代码。
</p>
<p><b>缺点：</b>由于迭代器模式将存储数据和遍历数据的职责分离，增加新的聚合类需要对应增加新的迭代器类，类的个数成对增加，这在一定程度上增加了系统的复杂性。</p>
<p><b>使用场景：</b>
1、访问一个聚合对象的内容而无须暴露它的内部表示。
2、需要为聚合对象提供多种遍历方式。
3、为遍历不同的聚合结构提供一个统一的接口。
</p> 
<p><b>注意事项：</b>迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器类来负责，这样既可以做到不暴露集合的内部结构，又可让外部代码透明地访问集合内部的数据。</p>
<p><b>类图：</b>
<br>Iterator接口；声明了bool hasNext以及QVariant next纯虚函数；以及实现该接口的具体迭代器。
<br>Container接口：声明了getIterator纯虚函数；以及实现了该接口的具体容器类。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/iterator_pattern_uml_diagram.jpg" alt="迭代器模式的 UML 图" />

<a id="composite"></a>

## 组合模式

<p><b>定义：</b>将对象组合成树形结构以表示"部分-整体"的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。</p>
<p><b>主要解决：</b>它在我们树型结构的问题中，模糊了简单元素和复杂元素的概念，客户程序可以像处理简单元素一样来处理复杂元素，从而使得客户程序与复杂元素的内部结构解耦。</p>
<p><b>优点：</b>
1、高层模块调用简单。
2、节点自由增加。
</p>
<p><b>缺点：</b>在使用组合模式时，其叶子和树枝的声明都是实现类，而不是接口，违反了依赖倒置原则。</p>
<p><b>使用场景：</b>部分、整体场景，如树形菜单，文件、文件夹的管理。</p>
<p><b>类图：</b>
<br>Component接口；声明了add、remove、getChild以及operation函数，均实现为抛出异常。
<br>Leaf叶节点类：继承Component接口，实现operation函数。
<br>Composite枝节点类：继承Component接口，实现add、remove、getChild以及operation函数。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/composite_pattern_uml_diagram.jpg" alt="组合模式的 UML 图" />

<a id="state"></a>

## 状态模式

<p><b>意图：</b>允许对象在内部状态发生改变时改变它的行为，对象看起来好像修改了它的类。</p>
<p><b>主要解决：</b>对象的行为依赖于它的状态（属性），并且可以根据它的状态改变而改变它的相关行为。</p>
<p><b>优点：</b>
1、封装了转换规则。 
2、枚举可能的状态，在枚举状态之前需要确定状态种类。
3、将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为。
4、允许状态转换逻辑与状态对象合成一体，而不是某一个巨大的条件语句块。
5、可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数。
</p>
<p><b>缺点：</b>
1、状态模式的使用必然会增加系统类和对象的个数。 
2、状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱。
3、状态模式对"开闭原则"的支持并不太好，对于可以切换状态的状态模式，增加新的状态类需要修改那些负责状态转换的源代码，否则无法切换到新增状态，而且修改某个状态类的行为也需修改对应类的源代码。
</p>
<p><b>使用场景：</b>
1、行为随状态改变而改变的场景。
2、条件、分支语句的代替者。</p>
<p><b>注意事项：</b>在行为受状态约束的时候使用状态模式。</p>
<p><b>类图：</b>
<br>State接口：声明了insertQuarter、ejectQuarter、turnCrank以及dispense纯虚函数。
<br>定义了NoQuarterState、HasQuarterState、SoldState、SoldOutState类，实现了State接口，有一个Context类型的指针成员，并在合适的函数中切换Context的状态
<br>Context类：有State类型的noQuarterState、hasQuarterState、soldState、soldOutState以及当前状态state，
<br>定义了insertQuarter、ejectQuarter、turnCrank函数，定义了getState、setState、getNoQuarterState、getHasQuarterState、getSoldState、getSoldOutState函数。
</p>

<a id="proxy"></a>

## 代理模式

<p><b>意图：</b>为其他对象提供一种代理以控制对这个对象的访问。</p>
<p><b>主要解决：</b>在直接访问对象时带来的问题，比如说：要访问的对象在远程的机器上。在面向对象系统中，有些对象由于某些原因（比如对象创建开销很大，或者某些操作需要安全控制，或者需要进程外的访问），直接访问会给使用者或者系统结构带来很多麻烦，我们可以在访问此对象时加上一个对此对象的访问层。</p>
<p><b>优点：</b>
1、职责清晰。
2、高扩展性。
3、智能化。
</p>
<p><b>缺点：</b>
1、由于在客户端和真实主题之间增加了代理对象，因此有些类型的代理模式可能会造成请求的处理速度变慢。
2、实现代理模式需要额外的工作，有些代理模式的实现非常复杂。
</p>
<p><b>使用场景：</b>按职责来划分，通常有以下使用场景：
1、远程代理。
2、虚拟代理。
3、Copy-on-Write 代理。
4、保护（Protect or Access）代理。
5、Cache代理。
6、防火墙（Firewall）代理。
7、同步化（Synchronization）代理。
8、智能引用（Smart Reference）代理。
</p>
<p><b>注意事项：</b>
1、和适配器模式的区别：适配器模式主要改变所考虑对象的接口，而代理模式不能改变所代理类的接口。
2、和装饰器模式的区别：装饰器模式为了增强功能，而代理模式是为了加以控制。
</p>
<p><b>类图：</b>
<br>Printable接口：声明了setPrinterName、getPrinterName以及print纯虚函数。
<br>Printer打印机类：实现了Printable接口，打印机对象创建开销很大，其构造函数会花费较多时间才能执行完毕。
<br>PrinterProxy打印机代理类：实现了Printable接口，有一个Printer打印机成员，当第一次调用print时，才会构造打印机对象。
</p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/proxy_pattern_uml_diagram.jpg" alt="代理模式的 UML 图" />

<a id="MVC"></a>

## MVC模式

<p><b>观察者：</b>
<br>模型实现了观察者模式，当状态改变时，相关对象将更新。使用观察者模式，可以让模型完全独立于视图和控制器。同一个模型可以使用不同的视图，甚至可以同时使用多个视图。
</p>
<p><b>策略：</b>
<br>视图和控制器实现了策略模式：视图是一个对象，可以被调整使用不同的策略，而控制器提供了策略。视图只关心系统中可视的部分，对于任何界面行为，都委托给控制器处理。
</p>
<p><b>组合：</b>
<br>视图内部使用组合模式来管理窗口、按钮以及其他显示组件：当控制器告诉视图更新时，只需告诉视图最顶层的组件即可，组合会处理其余的事。
</p>
<p><b>类图：</b></p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/master/images/MVC_pattern_uml_diagram.jpg" alt="MVC模式的 UML 图" />

<a id="builder"></a>

## 生成器模式

<p><b>定义：</b>生成器模式，又称建造者模式。它提供了一种创建对象的最佳方式，一个 Builder 类会一步一步构造最终的对象。</p>
<p><b>生成器模式有4个角色：</b>
<br><b>1、Product: </b>最终要生成的对象，例如 Computer实例。
<br><b>2、Builder：</b>构建者的抽象基类（有时会使用接口代替）。其定义了构建Product的抽象步骤，其实体类需要实现这些步骤。其会包含一个用来返回最终产品的方法Product getProduct()。
<br><b>3、ConcreteBuilder: </b>Builder的实现类。
<br><b>4、Director: </b>决定如何构建最终产品的算法. 其会包含一个负责组装的方法void Construct(Builder builder)， 在这个方法中通过调用builder的方法，就可以设置builder，等设置完成后，就可以通过builder的 getProduct() 方法获得最终的产品。
</p>
<p><b>注意事项：</b>
<br>与工厂模式的区别是：生成器模式更加关注于零件装配的顺序。
<br>与模板方法的区别是：到底谁承担了"监工"的责任。
在模板方法中父类承担了这个责任，而在生成器模式中，有另外一个专门的Director类来完成这样的操作。
这样做的好处是类的隔离，隔离的越好复用起来就越方便。
我们完全可以思考，假如还有另外一个监工，使用了不同的construct方法来组装这些复杂的事件，
那么对于原来的代码我们不用做任何的修改，只用增加这样的一个监工类，然后定义好相应的方法就好了。
我们再看看模板方法，责任全放在了父类里，如果责任需要改变，则必须要修改父类中的责任方法了，
这样就修改了原来的代码，不利于复用，这也是两者的本质区别。
</p>
<p><b>类图：</b></p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/sourcemaking/images/builder_pattern_uml_diagram.jpg" alt="生成器模式的 UML 图" />

<a id="prototype"></a>

## 原型模式

<p><b>定义：</b>原型模式使用原型实例指定创建对象的种类，并且通过拷贝原型对象创建新的对象。</p>
<p>
Prototype模式提供了一个通过已存在对象进行新对象创建的接口（clone）， clone()实现和具体的语言相关，在C++中通过拷贝构造函数实现。
<br>原型模式实际上就是从一个对象再创建另外一个可定制的对象，而且不需要知道任何创建的细节。在初始化的信息不发生变化的情况下，克隆是最好的办法，既隐藏了对象创建的细节，又大大提高了性能。因为如果不用clone，每次new都需要执行一次构造函数，如果构造函数的执行时间很长，那么多次的执行初始化操作就太低效了。
<br>原型模式实现clone接口的时候必须使用深拷贝。原型模式重点在从自身赋值自己创建新的类对象，隐藏创建的细节。
</p>
<p><b>类图：</b></p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/sourcemaking/images/prototype_pattern_uml_diagram.jpg" alt="原型模式的 UML 图" />

<a id="bridge"></a>

## 桥接模式

<p><b>定义：</b>桥接（Bridge）是用于把抽象化与实现化解耦，使得二者可以独立变化。这种类型的设计模式属于结构型模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。</p>
<p><b>桥接模式所涉及的角色有：</b>
<br><b>1、抽象化(Abstraction)角色：</b>抽象化给出的定义，并保存一个对实现化对象的引用。
<br><b>2、修正抽象化(RefinedAbstraction)角色：</b>扩展抽象化角色，改变和修正父类对抽象化的定义。
<br><b>3、实现化(Implementor)角色：</b>这个角色给出实现化角色的接口，但不给出具体的实现。
<br>必须指出的是，这个接口不一定和抽象化角色的接口定义相同，实际上，这两个接口可以非常不一样。
<br>实现化角色应当只给出底层操作，而抽象化角色应当只给出基于底层操作的更高一层的操作。
<br><b>4、具体实现化(ConcreteImplementor)角色：</b>这个角色给出实现化角色接口的具体实现。
</p>
<p><b>类图：</b></p>
<img src="https://github.com/quan12jiale/DesignPattern/blob/sourcemaking/images/bridge_pattern_uml_diagram.jpg" alt="原型模式的 UML 图" />

<a id="flyweight"></a>

## 享元模式


<p>享元模式主要用于减少创建对象的数量，以减少内存占用和提高性能。这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的对象结构的方式。</p>
<p>享元模式尝试重用现有的同类对象，如果未找到匹配的对象，则创建新对象。</p>
<p><b>关键代码：</b>用 HashMap 存储这些对象。</p>
<p><b>应用实例：</b>
1、JAVA 中的 String，如果有则返回，如果没有则创建一个字符串保存在字符串缓存池里面。
2、数据库的数据池。
</p>
<p><b>优点：</b>大大减少对象的创建，降低系统的内存，使效率提高。</p>
<p><b>使用场景：</b>
1、系统有大量相似对象。
2、需要缓冲池的场景。
</p>
<p><b>注意事项：</b>
1、这些类必须有一个工厂对象加以控制。
</p>
