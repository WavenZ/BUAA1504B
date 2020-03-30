> 2020/3/30

## 1. C/C++ 基础知识
(1) 请你回答一下什么是右值引用，跟左值又有什么区别？

> 左值引用
> 一个C++引用声明后必须被初始化，否则编译不过，初始化之后就相当与一个变量（地址为初始化时所引用变量的地址）。由于拥有共同的地址，而且也是同一个类型，所以对其操作就相当于对原对象的操作，用法和普通变量相同。与指针最大的区别：指针是一种数据类型，而引用不是。当其用作函数传参时，传递的就是变量的左值即地址。
>
> 右值引用
> 形式：类型 && a= 被引用的对象。与左值的区别在于：右值是临时变量，如函数返回值，且不变。右值引用可以理解为右值的引用，右值初始化后临时变量消失。
> 右值引用是 C++ 新标准 (C++11, 11 代表 2011 年 ) 中引入的新特性 , 它实现了转移语义和精确传递。
> C++11 标准新特性: 右值引用与转移语义，它的主要目的有两个方面：
> 1.消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率；
> 2.能够更简洁明确地定义泛型函数；

## 2. 操作系统
(1) 请你说一说用户态和内核态区别

> 用户态和内核态是操作系统的两种运行级别，两者最大的区别就是特权级不同。用户态拥有最低的特权级，内核态拥有较高的特权级。运行在用户态的程序不能直接访问操作系统内核数据结构和程序。内核态和用户态之间的转换方式主要包括：系统调用，异常和中断。

## 3. 计算机网络
(1) 请你说说TCP/IP数据链路层的交互过程

> 网络层等到数据链路层用mac地址作为通信目标，数据包到达网络准备往数据链路层发送的时候，首先会去自己的arp缓存表（存ip-mac对应关系）去查找该目标IP的mac地址，如果查到了，就将目标ip的mac地址封装到链路层数据包的包头。如果缓存中没有找到，会发起一个广播（who is ip XXX tell ip XXX），所有收到广播的机器看这个ip是不是自己，如果是自己，就一单播的形式将自己的mac地址回复给请求的机器。

## 4. 数据库
(1) 请你来说一说Redis是单线程的，但是为什么这么高效呢?

> 1. 单线程避免了线程安全相关问题和导致的代码逻辑结构数据结构的复杂度，线程间切换。
> 2. 使用了 epoll 异步事件处理调度机制。 
> 3. 内存数据读写本身快。

## 5. 算法
(1) 在 O(1) 时间内删除链表节点。
> 给定单项链表的头指针和一个节点指针，定义一个函数在 O(1) 时间内删除该节点。链表节点与函数的定义如下：
```cpp
struct ListNode {
	int         m_nValue;
	ListNode*   m_pNext;
};

void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted) {
	if (!pListHead || !pToBeDeleted)
		return;

	// 要删除的节点不是尾节点,复制下一节点，指向下下节点，变相删除
	if (pToBeDeleted->m_pNext != nullptr) {
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	// 链表只有一个节点，删除头结点（也就是尾节点）
	else if (pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}
	// 链表中有多个节点，删除尾节点
	else {
		ListNode* pNode = pListHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
```

