> 2020/3/19 

## 1. C/C++ 基础知识
(1) C++ 的内存分配方式有哪些？

> 1、栈：内存由编译器在需要时自动分配和释放。通常用来存储局部变量和函数参数。
> 2、堆：内存使用new进行分配使用delete或delete[]释放。
> 3、自由存储区：使用malloc进行分配，使用free进行回收。和堆类似。
> 4、全局/静态存储区：全局变量和静态变量被分配到同一块内存中，C语言中区分初始化和未初始化的，C++中不再区分了。
> 5、常量存储区：存储常量，不允许被修改。

## 2. 操作系统
(1) 什么是虚拟内存？

> 虚拟内存是计算机系统内存管理的一种技术。它使得应用程序认为它拥有连续的可用的内存（一个连续完整的地址空间），而实际上，它通常是被分隔成多个物理内存碎片，还有部分暂时存储在外部磁盘存储器上，在需要时进行数据交换。

## 3. 计算机网络
(1) HTTP的常见状态码有哪些？代表什么含义？

> https://blog.csdn.net/baidu_24545901/article/details/78869089

## 4. 数据库
(1) 关系型数据库和非关系型数据库区别？常见举例？

> https://blog.csdn.net/qq_37668377/article/details/82431195

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

```C++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        int node;
        while(stack1.empty()==0){
            stack2.push(stack1.top());
            stack1.pop();
        }
        node=stack2.top();
        stack2.pop();
        while(stack2.empty()==0){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return node;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};

```

