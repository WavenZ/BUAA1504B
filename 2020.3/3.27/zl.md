> 2020/3/27

## 1. C/C++ 基础知识
(1) 几种形参方式 - 空间分配比较

by value、by pointer、by refernce


## 2. 操作系统
(1) 手写一下fork调用示例

```cpp
pid_t pid = fork();
if(pid == -1){
     // error
}
else if(pid == 0){
     // subprocess
}else{
     // parent process
}
```

## 3. 计算机网络
(1) IP数据报分片的原因

如果IP数据报加上数据帧头部后大于MTU，数据报文就会分成若干片进行传输。那么什么是MTU呢？每一种物理网络都会规定链路层数据帧的最大长度，称为链路层MTU。在以太网的环境中可传输的最大IP报文为1500字节。如果要传输的数据帧的大小超过1500字节，即IP数据报的长度大于1472(1500-20-8=1472，普通数据报)字节，需要分片之后进行传输。

## 4. 数据库
(1) 简单说一说drop、delete与truncate的区别

drop：删除内容和定义，释放空间。（表结构和数据一同删除）

【drop语句将删除表的结构，被依赖的约束（constrain),触发器（trigger)索引（index);依赖于该表的存储过程/函数将被保留，但其状态会变为：invalid。】
```sql
drop table user;
```
truncate：删除内容，释放空间，但不删除定义。（表结构还在，数据删除）

【truncate table 权限默认授予表所有者、sysadmin 固定服务器角色成员、db_owner 和 db_ddladmin 固定数据库角色成员且不可转让。】
```sql
truncate table user;
```
delete：删除内容，不删除定义，也不释放空间。
```sql
delete from user;
```

## 5. 算法
(1) 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

```C++
class Solution {
public:
     int  NumberOf1(int n) {
         
     }
};
```

