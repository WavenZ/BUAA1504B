> 2020/3/14若有恒，何必三更起五更眠；最无益，莫过一日曝十日寒

## 1. C/C++ 基础知识
(1) JAVA中的装箱和拆箱

装箱是将基本数据类型转化为包装类型，拆箱是将包装类型转化为基本数据类型。  
基本类型(包装类型)：byte(Byte), short(Short), int(Integer), long(Long), float(Float), double(Double), char(Character), boolean(Boolean)
```java
public class TestBox {
    public static void main(String[] args) {
        //自动装箱，底层其实执行了Integer a=Integer.valueOf(1);
        Integer a = 1;
        //自动拆箱，底层其实执行了int b=a.intValue();
        int b = a;
    }
}
```

(2) String StringBuffer StringBUilder的区别

1. 可变与不可变：String底层使用final修饰的字符数组来存储字符串，它属于不可变类，对String对象的任何改变操作都不会改变原对象，而是生成一个新对象。StringBuilder和StringBuffer有一个共同的抽象父类AbstractStringBuiler，它们底层是一个不用final修饰的字符数组，因此它们是可变的。

2. 是否线程安全:String由final修饰，因此必然是线程安全的。StringBuilder与StringBuffer的唯一区别就是StringBuffer的方法都加上了syncharnized，因此StringBuffer是线程安全的。

3. 执行效率：StringBuilder > StringBuffer > String


## 2. 操作系统
(1) 操作系统中的缺页中断

[缺页中断](https://blog.csdn.net/CJL5678/article/details/9010353)  
进程线性地址空间里的页面不必常驻内存，在执行一条指令时，如果发现他要访问的页没有在内存中（存在位为0），那么停止该指令的执行，并产生一个页不存在异常，对应的故障处理程序可通过从外存加载加载该页到内存的方法来排除故障，之后，原先引起的异常的指令就可以继续执行，而不再产生异常。

(2) 操作系统中的结构体对齐，字节对齐

结构体是一种构造数据类型，里面可以有不同数据类型的成员。在这些成员中，不同的数据类型所占的内存空间是不同的。那么系统是怎么给结构体变量的成员分配内存的呢？按字节对齐的方式存储的！即以结构体成员中占内存最多的数据类型所占的字节数为标准，所有的成员在分配内存时都要与这个长度对齐。  
[参考](http://c.biancheng.net/view/243.html)

## 3. 计算机网络
(1) 搜索baidu，会用到计算机网络中的什么层？每层是干什么的

[参考](https://blog.csdn.net/qq_41007781/article/details/94410597)

(2) 数字证书是什么，里面都包含那些内容

数字证书是指在互联网通讯中标志通讯各方身份信息的一个数字认证，人们可以在网上用它来识别对方的身份。  
包含的内容：[参考](https://blog.csdn.net/qq_41007781/article/details/94590161)

## 4. 数据库
(1) 索引是什么，多加索引一定会好吗

索引是对数据库表中一列或多列的值进行排序的一种结构，使用索引可快速访问数据库表中的特定信息。  
不，索引会占用磁盘空间，并且影响数据更新的速度。

(2) 请你说一说inner join和left join

内连接, 单行匹配整表，若不筛选，两个表一个5行，一个6行，连接完30行。
左外连接：用左表第一行分别和右表的所有行进行连接，有匹配行，一起输出；多行匹配，输出多行，没有匹配，也会输出一行，右表部分都是NULL。

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
```c
//阶乘
# include <stdio.h>

long f(long n)
//问题的规模为n，此问题的解决可以通过n-1规模问题的解决而解决 
{
	if (1 == n)
		return 1;
	else
	{  
		return f(n-1) + n;//求和 
	} 
}

int main(void)
{
	printf("%ld\n", f(10));
	return 0;
}

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

