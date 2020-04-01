> 2020/3/24

## 1. C/C++ 基础知识
(1) Java中代码复用的方式？

组合：要使用A类的方法，为了不改变其原有结构，在一个新的类B中创建A类的一个对象a，以创建的这个对象a来调用A类的方法。  
继承：要使用A类的方法，不改变其原有结构，创建一个类B，继承自A，这个类B拥有A类的所有方法和属性，并能自身做扩展,拥有A所没有的属性和方法。  
代理：要使用A类的方法，不改变其原有结构，在一个新的类B中创建A的对象a，并且在B中创建方法fb，方法内部是a调用A类的方法，但是使用时是B的对象调用其自身方法fb。

## 2. 操作系统
(1) 什么是虚拟内存？

虚拟内存是计算机系统内存管理的一种技术。它使得应用程序认为它拥有连续的可用的内存（一个连续完整的地址空间），而实际上，它通常是被分隔成多个物理内存碎片，还有部分暂时存储在外部磁盘存储器上，在需要时进行数据交换。

## 3. 计算机网络
(1) HTTP的常见状态码有哪些？代表什么含义？

[参考](https://blog.csdn.net/banana960531/article/details/85621865?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

## 4. 数据库
(1) 关系型数据库和非关系型数据库区别？常见举例？

[参考](https://blog.csdn.net/aaronthon/article/details/81714528)

## 5. 算法
(1) 用两个栈实现队列

> 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead，分别完成在队列尾部插入节点和在队列头部删除节点的功能。

```cpp
template<typaname T>
class CQueue{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};
```
