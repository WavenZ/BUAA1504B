> 2020/3/19 

## 1. C/C++ 基础知识
(1) malloc与new区别

1. 属性：new/delete是C++关键字，需要编译器支持。malloc/free是库函数，需要头文件支持。

2. 参数：使用new操作符申请内存分配时无须指定内存块的大小，编译器会根据类型信息自行计算。而malloc则需要显式地指出所需内存的尺寸。

3. 返回类型：new操作符内存分配成功时，返回的是对象类型的指针，类型严格与对象匹配，无须进行类型转换，故new是符合类型安全性的操作符。而malloc内存分配成功则是返回void * ，需要通过强制类型转换将void*指针转换成我们需要的类型。

4. 分配失败：new内存分配失败时，会抛出bac_alloc异常。malloc分配内存失败时返回NULL。

5. 自定义类型：new会先调用operator new函数，申请足够的内存（通常底层使用malloc实现）。然后调用类型的构造函数，初始化成员变量，最后返回自定义类型指针。delete先调用析构函数，然后调用operator delete函数释放内存（通常底层使用free实现）。malloc/free是库函数，只能动态的申请和释放内存，无法强制要求其做自定义类型对象构造和析构工作。

6. 重载：C++允许重载new/delete操作符，特别的，布局new的就不需要为对象分配内存，而是指定了一个地址作为内存起始区域，new在这段内存上为对象调用构造函数完成初始化工作，并返回此地址。而malloc不允许重载。

7. 内存区域：new操作符从自由存储区（free store）上为对象动态分配内存空间，而malloc函数从堆上动态分配内存。自由存储区是C++基于new操作符的一个抽象概念，凡是通过new操作符进行内存申请，该内存即为自由存储区。而堆是操作系统中的术语，是操作系统所维护的一块特殊内存，用于程序的内存动态分配，C语言使用malloc从堆上分配内存，使用free释放已分配的对应内存。自由存储区不等于堆，如上所述，布局new就可以不位于堆中。

(2) 静态函数和虚函数的区别


## 2. 操作系统
(1) 互斥锁（mutex）机制，以及互斥锁和读写锁的区别

互斥锁在任何时候都保证只有一个线程进行读或者写，获取锁失败后线程会进行睡眠状态。

读写锁保证只有一个线程进行写，但可以有多个线程同时进行读。

(2)请你来说一说协程

协程（Coroutines）是一种比线程更加轻量级的存在，正如一个进程可以拥有多个线程一样，一个线程可以拥有多个协程。

协程不是被操作系统内核所管理的，而是完全由程序所控制，也就是在用户态执行。这样带来的好处是性能大幅度的提升，因为不会像线程切换那样消耗资源。

协程不是进程也不是线程，而是一个特殊的函数，这个函数可以在某个地方挂起，并且可以重新在挂起处外继续运行。所以说，协程与进程、线程相比并不是一个维度的概念。

一个进程可以包含多个线程，一个线程也可以包含多个协程。简单来说，一个线程内可以由多个这样的特殊函数在运行，但是有一点必须明确的是，一个线程的多个协程的运行是串行的。如果是多核CPU，多个进程或一个进程内的多个线程是可以并行运行的，但是一个线程内协程却绝对是串行的，无论CPU有多少个核。毕竟协程虽然是一个特殊的函数，但仍然是一个函数。一个线程内可以运行多个函数，但这些函数都是串行运行的。当一个协程运行时，其它协程必须挂起。

## 3. 计算机网络
(1) 请介绍一下操作系统中的中断

中断是指CPU对系统发生的某个事件做出的一种反应，CPU暂停正在执行的程序，保存现场后自动去执行相应的处理程序，处理完该事件后再返回中断处继续执行原来的程序。中断一般三类，一种是由CPU外部引起的，如I/O中断、时钟中断，一种是来自CPU内部事件或程序执行中引起的中断，例如程序非法操作，地址越界、浮点溢出），最后一种是在程序中使用了系统调用引起的。而中断处理一般分为中断响应和中断处理两个步骤，中断响应由硬件实施，中断处理主要由软件实施。

(2) 请问server端监听端口，但还没有客户端连接进来，此时进程处于什么状态？


## 4. 数据库
(1) 请你介绍一下mysql的MVCC机制

MVCC是一种多版本并发控制机制，是MySQL的InnoDB存储引擎实现隔离级别的一种具体方式，用于实现提交读和可重复读这两种隔离级别。MVCC是通过保存数据在某个时间点的快照来实现该机制，其在每行记录后面保存两个隐藏的列，分别保存这个行的创建版本号和删除版本号，然后Innodb的MVCC使用到的快照存储在Undo日志中，该日志通过回滚指针把一个数据行所有快照连接起来。


(2) 请问SQL优化方法有哪些

https://blog.csdn.net/wufaliang003/article/details/79875383

## 5. 算法
(1) 对称二叉树

> 给定一个二叉树，检查它是否是镜像对称的。https://leetcode-cn.com/problems/symmetric-tree/

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        else if(left == nullptr || right == nullptr) return false;
        else if(left->val != right->val) return false;
        else return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
```


(2) 二叉树的层次遍历 II

> 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> vec;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            vec.clear();
            for(int i = Q.size(); i > 0; --i){
                TreeNode* node = Q.front(); Q.pop();
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
                vec.push_back(node->val);
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```