> 若有恒，何必三更起五更眠；最无益，莫过一日曝十日寒。

[TOC]

### 1. C/C++ 基础知识

##### (1) static 关键字的作用有哪些？

①将全局变量修饰为静态全局变量存储在静态存储区，整个程序运行期间一直存在，仅在声明它的文件可见，而普通的全局变量则是所有文件可见。

②将局部变量修饰为静态局部变量存储在静态存储区，作用域仍为局部作用域，但是当局部变量离开作用域之后，并没有销毁，而是仍然存储在内存中，只不过目前暂时不能对它进行访问，直到该函数再次被调用，并且值不变，只会被初始化一次。

③将普通函数修饰为静态函数静态函数只在声明它的文件中可见，所以不会同其他cpp中的同名函数引起冲突。

④将类的成员变量修饰为静态成员变量，静态成员变量是属于类的，而不是属于对象的。故可以实现多个对象之间的数据共享，且静态成员变量还不会破坏隐藏的原则，对多个对象来说，静态成员变量只存储一处，供所有对象共用。

⑤将类的成员函数修饰为静态成员函数，静态成员函数同样是属于类的，而不是属于对象，需要注意的是在静态成员函数的实现中不可以直接引用类中的非静态数据成员，但是可以直接引用静态成员，如果非要引用非静态的成员，则可以通过对象来引用。

##### (2) C++ 中 struct 和 class 有哪些区别？ 

在C++中引入struct是为了保持对C程序的兼容，在引入之后C++对其进行了扩充，现在struct可以拥有静态成员、成员数据可进行初始化、拥有函数、也可以继承、甚至多态也支持。

区别：

①默认属性不同：struct默认属性是public的，而class默认属性是private，继承中也是如此。

②class关键字还可用于定义模板参数，同typename

### 2. 操作系统

##### (1) 进程与线程的关系以及区别？

进程：指在系统中正在运行的一个应用程序；程序一旦运行就是进程；进程——资源分配的最小单位。

线程：系统分配处理器时间资源的基本单元，或者说进程之内独立执行的一个单元执行流。线程——程序执行的最小单位。

线程是进程中的一部分，进程包含多个线程在运行。线程是一个进程中代码的不同执行路线。

进程之间相互独立，但同一进程下的各个线程之间共享程序的内存空间(包括代码段，数据集，堆等)及一些进程级的资源(如打开文件和信号等)，某进程内的线程在其他进程不可见。

线程上下文切换比进程上下文切换要快得多

##### (2) 进程间通信有哪些方式？它们的区别？  

进程间通信（IPC，InterProcess Communication）是指在不同进程之间传播或交换信息。

IPC的方式通常有管道（包括无名管道和命名管道）、消息队列、信号量、共享存储、Socket、Streams等。

①管道，通常指无名管道，是 UNIX 系统IPC最古老的形式。特点：

​		a. 它是半双工的（即数据只能在一个方向上流动），具有固定的读端和写端。

​		b. 它只能用于具有亲缘关系的进程之间的通信（也是父子进程或者兄弟进程之间）。

​		c. 它可以看成是一种特殊的文件，对于它的读写也可以使用普通的read、write 等函数。但是它不是普通的文件，并不属于其他任何文件系统，并且只存在于内存中。

②FIFO，也称为命名管道，它是一种文件类型。特点：

​		a. FIFO可以在无关的进程之间交换数据，与无名管道不同。

​		b. FIFO有路径名与之相关联，它以一种特殊设备文件形式存在于文件系统中。

③消息队列，是消息的链接表，存放在内核中。一个消息队列由一个标识符（即队列ID）来标识。

​		a. 消息队列是面向记录的，其中的消息具有特定的格式以及特定的优先级。

​		b. 消息队列独立于发送与接收进程。进程终止时，消息队列及其内容并不会被删除。

​		c. 消息队列可以实现消息的随机查询,消息不一定要以先进先出的次序读取,也可以按消息的类型读取。

④信号量（semaphore）与已经介绍过的 IPC 结构不同，它是一个计数器。信号量用于实现进程间的互斥与同步，而不是用于存储进程间通信数据。特点：

​		a. 信号量用于进程间同步，若要在进程间传递数据需要结合共享内存。

​		b. 信号量基于操作系统的 PV 操作，程序对信号量的操作都是原子操作。

​		c. 每次对信号量的 PV 操作不仅限于对信号量值加 1 或减 1，而且可以加减任意正整数。

​		d. 支持信号量组。

​	⑤共享内存（Shared Memory），指两个或多个进程共享一个给定的存储区。特点：

​		a. 共享内存是最快的一种 IPC，因为进程是直接对内存进行存取。

​		b. 因为多个进程可以同时操作，所以需要进行同步。

​		c. 信号量+共享内存通常结合在一起使用，信号量用来同步对共享内存的访问。

### 3. 计算机网络

##### (1) Http和Https的区别？

HTTP协议传输的数据都是未加密的，也就是明文的，因此使用HTTP协议传输隐私信息非常不安全，为了保证这些隐私数据能加密传输，于是网景公司设计了SSL（Secure Sockets Layer）协议用于对HTTP协议传输的数据进行加密，从而就诞生了HTTPS。简单来说，HTTPS协议是由SSL+HTTP协议构建的可进行加密传输、身份认证的网络协议，要比http协议安全。

　　HTTPS和HTTP的区别主要如下：

　　1、https协议需要到ca申请证书，一般免费证书较少，因而需要一定费用。

　　2、http是超文本传输协议，信息是明文传输，https则是具有安全性的ssl加密传输协议。

　　3、http和https使用的是完全不同的连接方式，用的端口也不一样，前者是80，后者是443。

　　4、http的连接很简单，是无状态的；HTTPS协议是由SSL+HTTP协议构建的可进行加密传输、身份认证的网络协议，比http协议安全。

##### (2) 三次握手与四次挥手

在了解三次握手和四次挥手之前，先知道TCP报文内部包含了哪些东西。

TCP报头中的源端口号和目的端口号同IP数据报中的源IP与目的IP唯一确定一条TCP连接。TCP在发送数据前必须在彼此间建立连接，这里连接意思是：双方需要内保存对方信息（例如：IP，Port…）

报文主要段的意思

​		序号：表示发送的数据字节流，确保TCP传输有序，对每个字节编号

​		确认序号：发送方期待接收的下一序列号，接收成功后的数据字节序列号加 1。只有ACK=1时才有效。

​		ACK：确认序号的标志，ACK=1表示确认号有效，ACK=0表示报文不含确认序号信息

​		SYN：连接请求序号标志，用于建立连接，SYN=1表示请求连接

​		FIN：结束标志，用于释放连接，为1表示关闭本方数据流

①三次握手过程
建立TCP连接时，需要客户端和服务器共发送3个包。

第一次：客户端发送初始序号x和syn=1请求标志

第二次：服务器发送请求标志syn，发送确认标志ACK，发送自己的序号seq=y，发送客户端的确认序号ack=x+1

第三次：客户端发送ACK确认号，发送自己的序号seq=x+1，发送对方的确认号ack=y+1

三次握手分析：

第一次：客户端发送请求到服务器，服务器知道客户端发送，自己接收正常。SYN=1,seq=x
第二次：服务器发给客户端，客户端知道自己发送、接收正常，服务器接收、发送正常。ACK=1,ack=x+1,SYN=1,seq=y
第三次：客户端发给服务器：服务器知道客户端发送，接收正常，自己接收，发送也正常。seq=x+1,ACK=1,ack=y+1

②四次挥手

第一次挥手：客户端发出释放FIN=1，自己序列号seq=u，进入FIN-WAIT-1状态
第二次挥手：服务器收到客户端的后，发出ACK=1确认标志和客户端的确认号ack=u+1，自己的序列号seq=v，进入CLOSE-WAIT状态
第三次挥手：客户端收到服务器确认结果后，进入FIN-WAIT-2状态。此时服务器发送释放FIN=1信号，确认标志ACK=1，确认序号ack=u+1，自己序号seq=w，服务器进入LAST-ACK（最后确认态）
第四次挥手：客户端收到回复后，发送确认ACK=1，ack=w+1，自己的seq=u+1，客户端进入TIME-WAIT（时间等待）。客户端经过2个最长报文段寿命后，客户端CLOSE；服务器收到确认后，立刻进入CLOSE状态。

### 4. 数据库

##### (1) 事务四大特性？

事务的四大特性(ACID)：

原子性(Atomicity):    不可分割，要么全部执行，要么全部失败回滚，失败回滚后，数据库的状态与改事务执行之前的数据库状态相同
一致性(Consistency):    在事务执行前后，整个数据库处于一致状态，保持数据的完整性；比如，A有500元，B有500元，A与B之间进行转账，在没有第三方介入的情况下，无论A和B之间进行多少次的转账，他们两个的总金额都应该是1000元
隔离性(Isolation):   即在事务存在并发的情况下，每个事务之间感觉不到对方的存在，互不干扰。
持久性(Durability):  事务成功执行完后，对数据库的改变是永久、不可改变的，即便系统崩溃，也能回到这个成功的状态。

##### (2) 数据库隔离级别？

Serializable (串行化)：可避免脏读、不可重复读、幻读的发生
Repeatable read (可重复读)：可避免脏读、不可重复读的发生
Read committed (读已提交)：可避免脏读的发生
Read uncommitted (读未提交)：最低级别，任何情况都无法保证

### 5. 算法

##### (1) 链表的倒数第 k 个节点

> 题目：输入一个链表，输出该链表中倒数第 k 个节点。为了符合大多数人的习惯，本题从 1 开始计数，即链表的尾节点是倒数第 1 个节点。例如，一个链表有 6 个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。链表节点定义如下：

```cpp
struct ListNode{
    int         m_nValue;
    ListNode*   m_pNext;
};
#include "iostream"
#include "cstdlib"
using namespace std;
//问题：寻找链表中倒数第k个节点(从1开始计数)

ListNode* Tail_to_find(ListNode* pHead, int k);
void Print_list_node(ListNode* pHead);


void test01()
{
	ListNode* pHead = NULL;
	ListNode* pNode1 = NULL;
	ListNode* pNode2 = NULL;
	ListNode* pNode3 = NULL;

	ListNode* pThis = NULL;


	pHead = (ListNode*)malloc(sizeof(ListNode));
	pNode1 = (ListNode*)malloc(sizeof(ListNode));
	pNode2 = (ListNode*)malloc(sizeof(ListNode));
	pNode3 = (ListNode*)malloc(sizeof(ListNode));
	pThis = (ListNode*)malloc(sizeof(ListNode));

	if (pHead == NULL || pNode1 == NULL || pNode2 == NULL || pNode3 == NULL || pThis == NULL)
	{
		cout << "malloc fail" << endl;
		return;
	}

	pHead->m_nValue = 0;
	pHead->m_pNext = pNode1;

	pNode1->m_nValue = 1;
	pNode1->m_pNext = pNode2;

	pNode2->m_nValue = 2;
	pNode2->m_pNext = pNode3;

	pNode3->m_nValue = 3;
	pNode3->m_pNext = NULL;

	cout << "list:";
	Print_list_node(pHead);		//打印链表节点信息

	pThis = Tail_to_find(pHead, 1);
	if (pThis != NULL)
		cout << "k = 1, value = " << pThis->m_nValue << endl;
	else
		cout << "k = 1, input error" << endl;

	pThis = Tail_to_find(pHead, 2);
	if (pThis != NULL)
		cout << "k = 2, value = " << pThis->m_nValue << endl;
	else
		cout << "k = 2, input error" << endl;

	pThis = Tail_to_find(pHead, 4);
	if (pThis != NULL)
		cout << "k = 4, value = " << pThis->m_nValue << endl;
	else
		cout << "k = 4, input error" << endl;

	pThis = Tail_to_find(pHead, 0);
	if (pThis != NULL)
		cout << "k = 0, value = " << pThis->m_nValue << endl;
	else
		cout << "k = 0, input error" << endl;

	pThis = Tail_to_find(pHead, 100);
	if (pThis != NULL)
		cout << "k = 100, value = " << pThis->m_nValue << endl;
	else
		cout << "k = 100, input error" << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}

//功能：反向查找链表
//输入：pHead 首节点指针， k 节点总数
//返回：链表中倒数第k个节点的指针
ListNode* Tail_to_find(ListNode* pHead, int k)
{
	//1.输入参数的合法性
	if ((NULL == pHead) || (k <= 0))
	{
		return NULL;
	}

	//2.使p1指向第1个节点，p2指向第k个节点
	ListNode* p1 = pHead;
	ListNode* p2 = pHead;
	for (int i = 0; i < k - 1; i++)
	{
		if (p2->m_pNext != NULL)
		{//没有达到尾部
			p2 = p2->m_pNext;
		}
		else
		{//特殊情况：k大于链表中节点总数
			return NULL;
		}
	}

	//3.同时移动p1 p2,使p2指向尾节点
	while (p2->m_pNext != NULL)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}

	//4.返回p1指针
	return p1;
}


//功能：打印链表所有节点
//输入：pHead 头节点地址
//返回：无
void Print_list_node(ListNode* pHead)
{
	if (pHead != NULL)
	{
		while (pHead->m_pNext != NULL)
		{
			cout << pHead->m_nValue << ",";	//打印节点信息
			pHead = pHead->m_pNext;
		}
		cout << pHead->m_nValue << endl;	//打印尾节点
	}
}
```

##### (2) 股票的最大利润

> 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？例如，已知股票在某些时间节点的价格为 {9, 11, 8, 5, 7, 12, 16, 14}。如果我们能在价格为 5 的时候买入并在价格为 16 时卖出，则能收货最大的利润 11。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        int min = prices[0], max = 0;
        for(int i = 0;i < prices.size(); i++){
            max = (max < prices[i] - min) ? (prices[i] - min) : max;
            min = (min < prices[i]) ? min : prices[i];
        }
        return max;
    }
};
```

