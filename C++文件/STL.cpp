//STL
/*
STL(standard template libaray-标准模板库):
是C++标准库的重要组成部分，不仅是一个可复用的组件库，而且是一个包罗数据结构与算法的软件框架
*/



//STL的版本
/*
原始版本:
Alexander Stepanov、Meng Lee 在惠普实验室完成的原始版本，
本着开源精神，他们声明允许任何人任意运用、拷贝、修改、传播、商业使用这些代码，无需付费。
唯一的条件就是也需要向原始版本一样做开源使用。
HP版本--所有STL实现版本的始祖。

P.J.版本:
由P.J.Plauger开发，继承自HP版本，被Windows Visual C++采用，不能公开或修改，
缺陷:可读性比较低，符号命名比较怪异。

RW版本:
由Rouge Wage公司开发，继承自HP版本，被C++ Builder 采用，不能公开或修改，可读性一般。

SGI版本:
由Silicon Graphics Computer Systems，Inc公司开发，继承自HP版本。
被GCC(Linux)采用，可移植性好，可公开、修改甚至贩卖，从命名风格和编程风格上看，阅读性非常高。
我们后面学习STL要阅读部分源代码，主要参考的就是这个版本
*/



//STL的六大组件
/*
容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
(1)容器:
各种数据结构，用来存放数据。从实现角度来看，STL容器是一种class templats(类模板)

(2)算法:
各种常用的算法。从实现角度来看，STL算法是一种function template(函数模板)

(3)迭代器:
扮演了容器与算法之间的胶合剂，共有五种类型。
从实现角度来看，迭代器是一种将operator*,operator->,operator++,operator--等指针相关操作予以重载的class template。
所有STL容器都附带自己专属的迭代器，只有容器的设计者才知道如何遍历自己的元素。原生指针也是一种迭代器。

(4)仿函数:
行为类似函数，可作为算法的某种策略。
从实现角度来看，仿函数是一种重载了operator()的class或class template

(5)适配器(配接器)
一种用来修饰容器或仿函数或迭代器接口的东西

(6)空间配置器:
负责空间的配置与管理。从实现角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的class template

STL六大组件的交互关系:
容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同策略的变化，适配器可以修饰仿函数。
*/



//STL的缺陷
/*
1.STL库的更新太慢了。上一版靠谱是C++98，中间的C++03基本一些修订。C++11出来已经相隔了13年，STL才进一步更新

2.STL现在都没有支持线程安全。并发环境下需要我们自己加锁。且锁的粒度是比较大的

3.STL极度的追求效率，导致内部比较复杂。比如类型萃取，迭代器萃取

4.STL的使用会有代码膨胀的问题，比如使用vector<int>/vector<double>/vector<char>这样会生成多份代码，当然这是模板语法本身导致的
*/


