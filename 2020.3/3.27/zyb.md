> 2020/3/27

## 1. C/C++ 基础知识
(1) GC roots 对象有哪些？

虚拟机栈中 引用的对象；  
本地方法栈中 引用的的对象；  
方法区中常量 引用的对象；  
方法区中类静态属性 引用的对象

## 2. 操作系统
(1) 手写一下fork调用示例

Fork：创建一个和当前进程映像一样的进程可以通过fork( )系统调用。 

成功调用fork( )会创建一个新的进程，它几乎与调用fork( )的进程一模一样，这两个进程都会继续运行。在子进程中，成功的fork( )调用会返回0。在父进程中fork( )返回子进程的pid。如果出现错误，fork( )返回一个负值。

## 3. 计算机网络
(1) IP数据报分片的原因

如果IP数据报加上数据帧头部后大于MTU，数据报文就会分成若干片段进行传输。每一种物理网络都会规定链路层数据帧的最大长度，称为链路层MTU。在以太网的环境中可传输的最大IP报文为1500字节。如果要传输的数据帧的大小超过1500字节，即IP数据报的长度大于1472(1500-20-8=1472，普通数据报)字节，需要分片之后进行传输。

## 4. 数据库
(1) 简单说一说drop、delete与truncate的区别

[参考](https://www.cnblogs.com/zhizhao/p/7825469.html)

drop：删除内容和定义，释放空间。（表结构和数据一同删除）

【drop语句将删除表的结构，被依赖的约束（constrain),触发器（trigger)索引（index);依赖于该表的存储过程/函数将被保留，但其状态会变为：invalid。】
```sql
drop table tableName;
```
truncate：删除内容，释放空间，但不删除定义。（表结构还在，数据删除）

【truncate table 权限默认授予表所有者、sysadmin 固定服务器角色成员、db_owner 和 db_ddladmin 固定数据库角色成员且不可转让。】
```sql
truncate table tableName;
```
delete：删除内容，不删除定义，也不释放空间。
```sql
delete from tableName where ;
```
1、在速度上，一般来说，drop> truncate > delete。  
2、在使用drop和truncate时一定要注意，虽然可以恢复，但为了减少麻烦，还是要慎重。  
3、如果想删除部分数据用delete，注意带上where子句，回滚段要足够大；  如果想删除表，当然用drop；  如果想保留表而将所有数据删除，如果和事务无关，用truncate即可；  如果和事务有关，或者想触发trigger，还是用delete；  

## 5. 算法
(1) 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

```C++
class Solution {
public:
     int  NumberOf1(int n) {
         
     }
};
```

