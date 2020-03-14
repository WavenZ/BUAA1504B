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
>指针：指针是一个变量，只不过这个变量存储的是一个地址，指向内存的一个存储单元；而引用跟原来的变量实质上是同一个东西，只不过是原变量的一个别名而已。
>* 相同点  
>1. 都是地址的概念；指针指向一块内存，它的内容是所指内存的地址；而引用则是某块内存的别名。
>* 不同点
>1. 指针是一个实体，而引用仅是个别名；
>2. 引用只能在定义时被初始化一次，之后不可变；指针可变；引用“从一而终”，指针可以“见异思迁”；
>3. 引用没有const，指针有const，const的指针不可变；具体指没有int& const a这种形式，而const int& a是有的，前者指引用本身即别名不可以改变，这是当然的，所以不需要这种形式，后者指引用所指的值不可以改变）
>4. 引用不能为空，指针可以为空；
>5. sizeof 引用”得到的是所指向的变量(对象)的大小，而“sizeof 指针”得到的是指针本身的大小；
>6. 指针和引用的自增(++)运算意义不一样；
>7. 引用是类型安全的，而指针不是 (引用比指针多了类型检查）
[参考链接](https://blog.csdn.net/weixin_30270889/article/details/97389623?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

## 2. 操作系统
(1) 操作系统中的缺页中断
>[参考链接](https://blog.csdn.net/JIAYINYA/article/details/82932674)

(2) 操作系统中的结构体对齐，字节对齐
>[参考链接](http://c.biancheng.net/view/243.html)

## 3. 计算机网络
(1) 搜索baidu，会用到计算机网络中的什么层？每层是干什么的
>[参考链接](https://blog.csdn.net/qq_41007781/article/details/94410597)

(2) 数字证书是什么，里面都包含那些内容
>[参考链接](https://blog.csdn.net/qq_41007781/article/details/94590161)

## 4. 数据库
(1) 索引是什么，多加索引一定会好吗
>[参考链接](https://www.nowcoder.com/ta/review-c/review?page=264)

(2) 请你说一说inner join和left join
>left join(左联接) 返回包括左表中的所有记录和右表中联结字段相等的记录 right join(右联接) 返回包括右表中的所有记录和左表中联结字段相等的记录 inner join(等值连接) 只返回两个表中联结字段相等的行  
>[参考链接](https://www.nowcoder.com/tutorial/93/60c2f308109c4a7d8089a710b9ba1dab)


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