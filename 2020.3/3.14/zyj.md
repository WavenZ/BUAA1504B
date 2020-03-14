> 2020/3/14若有恒，何必三更起五更眠；最无益，莫过一日曝十日寒

## 1. C/C++ 基础知识
(1) 下列程序编译时，（1）（2）（3）（4）（5）中有语法错误的语句是

```
#include<iostream>
#include<string>
using namespace std; 
class Pet
{
     string name;
public:
     Pet(string p=" "){name=p;}
      string getName()const {return name;}
     virtual void call()const=0;
}; 
class Dog: public Pet{
public:
Dog(string n):Pet(n){}
void call()const{cout<<"##"<<" ";}
};
class Cat:public Pet{
public:
Cat(string n):Pet(n){}
void call()const{cout<<"**";}
};
void f(Pet *p)
{p->call();}
int main()
{ 
Pet pet0("#");           	//(1)
Dog pet1("*");           	//(2)
Cat pet2("$");           	//(3)
f(&pet1);					//(4)
f(&pet2);					//(5)
return 0;
}
```

(2) 请说一下C/C++ 中指针和引用的区别？

## 2. 操作系统
(1) 操作系统中的缺页中断

(2) 操作系统中的结构体对齐，字节对齐

## 3. 计算机网络
(1) 搜索baidu，会用到计算机网络中的什么层？每层是干什么的

(2) 数字证书是什么，里面都包含那些内容

## 4. 数据库
(1) 索引是什么，多加索引一定会好吗

(2) 请你说一说inner join和left join

## 5. 算法
(1) 求1+2+…+n [Leetcode链接](https://leetcode-cn.com/problems/qiu-12n-lcof/)  
> 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。  限制：1 <= n <= 10000  
> 示例:
```c
输入: n = 3
输出: 6
输入: n = 9
输出: 45
```

(2) 两数相加 [Leetcode链接](https://leetcode-cn.com/problems/add-two-numbers)
> 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。   
>
> 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
>
> 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。  
> 示例:
```c
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```