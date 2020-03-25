> 2020/3/19 

## 1. C/C++ 基础知识
(1) C++ 的内存分配方式有哪些？

## 2. 操作系统
(1) 什么是虚拟内存？

## 3. 计算机网络
(1) HTTP的常见状态码有哪些？代表什么含义？

## 4. 数据库
(1) 关系型数据库和非关系型数据库区别？常见举例？

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
