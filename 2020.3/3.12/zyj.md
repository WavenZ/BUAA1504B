> 2020/3/12 第二天 坚持就是胜利

## 1. C/C++ 基础知识
(1) C++ 中空类对象sizeof的返回值是多少？为什么不能是0？
>为了使得空类对象的地址唯一  

(2) C++ 中多态是怎么实现的？ 
>多态用虚函数来实现，结合动态绑定。  
[参考链接](https://blog.csdn.net/tujiaw/article/details/6753498)  

## 2. 操作系统
(1) 扩容的时候内存用什么来分配？
>vector 常被称为“容器”，习惯将之理解为动态数组。  
[参考链接](https://blog.csdn.net/denghecsdn/article/details/78975954)

(2) 怎么判断机器的大小端？
>所谓大小端模式就是存储数据时，数据的高低位怎么存储在地址的高低位上。（位指的是bit，一个char类型数据有8位）  
 大端模式：数据的高位，存放在地址的低位。（高位存低位，低位存高位）  
 小端模式：数据的高位，存放在地址的高位。（高位存高位，低位存低位）  
 第一种：用位移方法判断  
 第二种：数据类型强制转换  
 第三种：用共同体  
[参考链接](https://blog.csdn.net/YuZhiHui_No1/article/details/38455073?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
## 3. 计算机网络
(1) TCP、UDP区别？
>TCP与UDP基本区别  
1.基于连接与无连接  
2.TCP要求系统资源较多，UDP较少   
3.UDP程序结构较简单  
4.流模式（TCP）与数据报模式(UDP)   
5.TCP保证数据正确性，UDP可能丢包   
6.TCP保证数据顺序，UDP不保证  
> [参考链接](https://blog.csdn.net/li_ning_/article/details/52117463)

(2) 网络里面为什么要有网络序的概念？是用来解决什么问题的？  
>网络序就是大端法字节顺序。  
> [参考链接](https://blog.csdn.net/zhulin2609/article/details/52795495)

## 4. 数据库
(1) 什么是存储引擎？MySQL不同存储引擎间有什么区别？
>存储引擎就是存储数据、为存储的数据建立索引和更新、查询数据等技术的实现方法。因为在关系数据库中，数据是以表的形式存储的，所以存储引擎简而言之就是指表的类型，数据库的存储引擎决定了表在计算机中的存储方式。在Oracle和SQL Server等数据库中只有一种存储引擎，所有数据存储管理机制都是一样的。而MySQL数据库提供了多种存储引擎，用户可以根据不同的需求为数据表选择不同的存储引擎，用户也可以根据需要编写自己的存储引擎，MySQL的核心就是存储引擎。  
MEMORY存储引擎是MySQL中一类特殊的存储引擎。该存储引擎使用存在于内存中的内容来创建表，每个表实际对应一个磁盘文件，格式为.frm。这类表因为数据在内存中，且默认使用HASH索引，所以访问速度非常快；但一旦服务关闭，表中的数据就会丢失。  
[参考链接](https://blog.csdn.net/Watkins_OS/article/details/100511348)


(2) 数据库mysql索引机制，为什么要用B+树？  
> [参考链接](https://mp.weixin.qq.com/s/-qnYTrKNZeOE9Mvn4kyugg)  
> 
## 5. 算法
(1) 反转字符串中的单词 III [Leetcode链接](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)  
> 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。  
> 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。  
示例:
```c
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
```
>思路：分别找到每个单词的起点和终点，将每个单词逆置
```c
char * reverseWords(char * s){
    int l=0,r=0;
    int len=strlen(s);
    while(r<len)
    {
        l=r;
        while(s[r+1]!=' ' && s[r+1]!='\0')            //找到每个单词的起点l和终点r
            r++;
        int left=l,right=r;                           //用left和right分别记录l和r，
        while(left<right)                             //将一个单词逆置
        {
            char tmp=s[right];
            s[right]=s[left];
            s[left]=tmp;
            left++;
            right--;
        }
        if(s[r+1]=='\0')                              //到达句子末尾，终止循环
            break;
        r++;
        r++;
    }
    return s;
}
```
(2) 三色排序 [Leetcode链接](https://leetcode-cn.com/problems/sort-colors/)
> 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。  
> 注意:
不能使用代码库中的排序函数来解决这道题。  
示例:
```c
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```

```c
void sortColors(int* nums, int numsSize){
    short red=0,white=0,blue=0,i;
    for(i=0;i<numsSize;i++)
        switch(nums[i]){
            case 0:red++;break;
            case 1:white++;break;
            case 2:blue++;
        }
    for(i=0;i<red;i++) nums[i]=0;
    for(i=red;i<red+white;i++) nums[i]=1;
    for(i=red+white;i<numsSize;i++) nums[i]=2;
}
```