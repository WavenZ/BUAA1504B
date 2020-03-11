### 1. C/C++ 基础知识
(1) static 关键字的作用有哪些？
1. 修饰局部变量：该变量仅在函数内部可用，存储于全局区。
2. 修饰全局变量：该变量仅在文件内部可用，存储于全局区。
3. 修饰全局函数：该函数仅在文件内部可用。
4. 修饰类的成员变量：类的所有成员共享，static成员变量必须在类外进行初始化。
5. 修饰类的成员函数：类的所有成员共享，static成员函数没有this指针，因此无法访问static成员。

(2) C++ 中 struct 和 class 有哪些区别？ 
1. 最大的区别是 struct 和 class 的默认访问控制权限不同：struct 是 public，class 是 private。
2. struct 和 class 的继承访问权限也不同，struct 是 public继承，class 是 private 继承。
3. 不能用 struct 声明模板形参，应该用 class 或 typename。

### 2. 操作系统
(1) 进程与线程的关系以及区别？
1. 关系：一个进程可以拥有多个线程。
2. 区别：进程是资源分配的最小单位，线程是CPU调度的最小单位。

(2) 进程间通信有哪些方式？它们的区别？

进程间通信（IPC，InterProcess Communication）是指在不同进程之间传播或交换信息。

IPC的方式通常有管道（包括无名管道和命名管道）、消息队列、信号量、共享内存、Socket、Streams等。其中 Socket 和 Streams 支持不同主机上的两个进程IPC。

https://github.com/WavenZ/LearnLinux/blob/master/os/1.md

### 3. 计算机网络
(1) Http和Https的区别？
1. https协议需要到CA申请证书，http不需要。
2. http是超文本传输协议，信息是明文传输，https则是具有安全性的ssl/tls加密传输协议。
3. http和https使用的是完全不同的连接方式，用的端口也不一样，前者是80，后者是443。
4. http的连接很简单，是无状态的；HTTPS协议是由SSL/TLS+HTTP协议构建的可进行加密传输、身份认证的网络协议，比http协议安全。

(2) 三次握手与四次挥手
 https://blog.csdn.net/qq_38950316/article/details/81087809
### 4. 数据库
(1) 事务四大特性？
1. 原子性：原子性是指事务包含的所有操作要么全部成功，要么全部失败回滚，这和前面两篇博客介绍事务的功能是一样的概念，因此事务的操作如果成功就必须要完全应用到数据库，如果操作失败则不能对数据库有任何影响。
2. 一致性：一致性是指事务必须使数据库从一个一致性状态变换到另一个一致性状态，也就是说一个事务执行之前和执行之后都必须处于一致性状态。
3. 隔离性：隔离性是当多个用户并发访问数据库时，比如操作同一张表时，数据库为每一个用户开启的事务，不能被其他事务的操作所干扰，多个并发事务之间要相互隔离。
4. 持久性： 持久性表示在某个事务的执行过程中，对数据所作的所有改动都必须在事务成功结束前保存至某种物理存储设备。

(2) 数据库隔离级别
数据库事务的隔离级别有 4 个，由低到高依次为 Read uncommitted、Read committed、Repeatable read、Serializable，这四个级别可以逐个解决脏读、不可重复读、幻读这几类问题。

||脏读|不可重复读|幻读|
|-|-|-|-|
|Read uncommitted|1|1|1|
|Read committed||1|1|
|Repeatable read|||1|
|Serializable||||


### 5. 算法
(1) 链表的倒数第 k 个节点
> 题目：输入一个链表，输出该链表中倒数第 k 个节点。为了符合大多数人的习惯，本题从 1 开始计数，即链表的尾节点是倒数第 1 个节点。例如，一个链表有 6 个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。链表节点定义如下：

```cpp
struct ListNode{
    int         m_nValue;
    ListNode*   m_pNext;
};
```
思路：双指针

需要注意的几个问题：
1. 链表为空。
2. 链表长度小于 k。
3. 长度 k 可能为0。
```cpp
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    if(pListNode == nullptr || k == 0)
        return nullptr;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = nullptr;

    for(unsigned int i = 0; i < k - 1; ++i){
        if(pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else{
            return nullptr;
        }
    }
    pBehind = pListHead;
    while(pAhead->m_pHead != nullptr){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}
```
(2) 股票的最大利润
> 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？例如，已知股票在某些时间节点的价格为 {9, 11, 8, 5, 7, 12, 16, 14}。如果我们能在价格为 5 的时候买入并在价格为 16 时卖出，则能收货最大的利润 11。

思路：在扫描的过程中记录之前的股价最小值和利润的最大值。
```cpp
int maxProfit(const int* numbers, unsigned length)
{
    if(numbers == nullptr && length < 2)
        return 0;
    int minPrice = numbers[0]; // 股价的最小值
    int maxProfit = numbers[1] - minPrice; // 利润的最大值

    for(int i = 2; i < length; ++i)
    {
        minPrice = std::min(minPrice, number[i - 1]);
        int currentProfit = numbers[i] - minPrice;
        maxProfit = std::max(maxProfit, currentProfit);
    }
    return maxProfit;
}
```
