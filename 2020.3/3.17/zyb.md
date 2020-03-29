2020/3/17

## 1. C/C++ 基础知识
(1) HashSet判定元素重复的原则？

向hashsSet中添加对象时，HashSet先通过该对象的HashCode方法计算出该对象相应的桶（在HashSet中存放的位置），然后再根据equals方法找到相应的对象。如果容器中已经存在该对象，则不再添加，如果不存在，则添加进去。
在自定义的类，去new出对象时，如果存放在hashSet，则必须重写hashCode方法和equals方法。

(2) collection接口，collections类，comparable接口，Iterator接口？

collection接口：Java容器的概念，专门用来存放Java类的对象  
collections接口：对collection接口的实现类进行处理，比如：排序，翻转等等  
comparable接口：为自定义类的对象之间的比较提供标准  
Iterator接口：迭代器接口，常用来遍历所有collection接口的实现类。  

## 2. 操作系统
(1) linux下什么命令可以查看所有进程？

ps aux

(2) 常见的Linux命令：查看程序占用多少内存？

ps aux 再通过管道符取出某一个程序
VSZ：该进程占用虚拟内存的大小，单位KB

## 3. 计算机网络
(1) 什么场景下比较适合UDP协议？

DP应用场景：
1.面向数据报方式
2.网络数据大多为短消息
3.拥有大量Client
4.对数据安全性无特殊要求
5.网络负担非常重，但对响应速度要求高

(2) TCP怎么样做流量控制？

由滑动窗口协议实现。滑动窗口协议既保证了分组无差错、有序接收，也实现了流量控制。主要的方式就是接收方返回的 ACK 中会包含自己的接收窗口的大小，并且利用大小来控制发送方的数据发送。

## 4. 数据库
(1) 请你说一说数据库索引

索引是对数据库表中一个或多个列的值进行排序的数据结构，以协助快速查询、更新数据库表中数据。索引的实现通常使用B_TREE及其变种。索引加速了数据访问，因为存储引擎不会再去扫描整张表得到需要的数据；相反，它从根节点开始，根节点保存了子节点的指针，存储引擎会根据指针快速寻找数据。

(2) 多加索引一定会好吗？

会造成时间空间上的损失：时间方面：创建索引和维护索引要耗费时间，具体地，当对表中的数据进行增加、删除和修改的时候，索引也要动态的维护，这样就降低了数据的维护速度；空间方面：索引需要占物理空间。

## 5. 算法
(1) 给你一个长度为N的无序数组，然后找出里面最大的K个数。

```c
//给你一个长度为N的无序数组，然后找出里面最大的K个数。
#include <stdio.h>
 
int h[100000],n;
 
void swap(int a, int b)
{
    int t;
    t = h[a];
    h[a] = h[b];
    h[b] = t;
}
 
void siftdown(int i)
{
    int t, flag = 0;
    while(2*i <= n && flag == 0)
    {
        if(h[i] > h[2*i])
        {
            t = 2*i;
        }
        else
        {
            t = i;
        }
 
        if(2*i + 1 <= n)
        {
            if(h[t] > h[2*i + 1])
            {
                t = 2*i + 1;
            }
        }
        if(t != i)
        {
            swap(i, t);
            i = t;
        }
        else
        {
            flag = 1;
        }
    }
}
 
void creat()
{
    for(int i = n/2; i >= 1; i--)
    {
        siftdown(i);
    }
}
 
int main()
{
    int num, maxi, a[100000];
    while(scanf("%d %d", &num, &maxi) != EOF)
    {
        n = maxi;
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &a[i]);
            h[i] = a[i];
        }
 
        creat();
 
        for(int i = n + 1; i <= num; i++)
        {
            if(a[i] > h[1])
            {
                h[1] = a[i];
                siftdown(1);
            }
            else
            {
                continue;
            }
        }
        for(int j=1; j<=maxi; j++)
        {
        	printf("%d\n", h[j]);
		}   
    }
 
    return 0;
}
```



(2) 爬楼梯问题，你可以一次爬1层或2层，如果有n层楼梯，一共有点多少种解法？。
```c
int Stairs(int n){
	if (n <= 0){
		return -1;
	}
	if (n < 2){
		return n;
	}
	int older = 1, old = 2, now;
	for(int i = 3; i <= n; ++i){
        now = old + older;
        older = old;
        old = now;
    }
    return now;
}
```