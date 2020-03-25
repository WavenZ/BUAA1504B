> 2020/3/19 

## 1. C/C++ 基础知识
(1) JAVA中的泛型

泛型是用来限制传入容器（集合）、接口中的数据类型的。  
容器中都是某一种类型数据时，可以进行指定。  
```java
HashMap <integer student> hm = new HashMap <integer student> ();
```
(2) HashMap的get和put方法

get方法是用来检索hashmap中的元素的，只要给出键对象就会返回对应的值对象；put用于添加元素，必须提供一对键对象和值对象。  
Object get(Object key)  
Object put(Object key, Object value)

## 2. 操作系统
(1) 互斥锁（mutex）机制，以及互斥锁和读写锁的区别

[参考](https://blog.csdn.net/daaikuaichuan/article/details/82950711?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

(2)请你来说一说协程

[参考](https://www.cnblogs.com/xiaobaizzz/p/12285681.html)

## 3. 计算机网络
(1)  请介绍一下操作系统中的中断

中断是指程序执行过程中，遇到急需处理的事件时，暂时中止CPU上现行程序的运行，转去执行相应的事件处理程序，待处理完成后再返回原程序被中断处或调度其他程序执行的过程。中断来源于外设。

(2) 请问server端监听端口，但还没有客户端连接进来，此时进程处于什么状态？

阻塞

## 4. 数据库
(1) 请你介绍一下mysql的MVCC机制

[参考](https://www.cnblogs.com/wangfengming/articles/8074283.html)

(2) 请问SQL优化方法有哪些

MySQL的优化主要涉及SQL语句及索引的优化、数据表结构的优化、系统配置的优化和硬件的优化四个方面。

## 5. 算法
(1) 对称二叉树

> 给定一个二叉树，检查它是否是镜像对称的。https://leetcode-cn.com/problems/symmetric-tree/
```c
bool  _isSymmetric(struct TreeNode* left,struct TreeNode* right)
 {
    
    if(left==NULL&&right==NULL)
    {
        return true;
    }
    if(left==NULL||right==NULL)
    {
        return false;
    }
    
    return left->val==right->val && _isSymmetric(left->left,right->right) && _isSymmetric(left->right,right->left);
 }
 
bool isSymmetric(struct TreeNode* root) {
    
    if(root==NULL)
    {
        return true;
    }
   return _isSymmetric(root->left,root->right);

```


(2) 二叉树的层次遍历 II

> 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
```c
/* 完整代码 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MaxSize 100
 
struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};
 
typedef struct queue{
    struct tree* numQ[MaxSize];
    int front;
    int rear;
}Queue;
 
Queue Q;
 
void initilize() { //初始化队列
    Q.front = 0;
    Q.rear = 0;
}
 
void Push(struct tree* root) { //入队
    Q.numQ[++Q.rear] = root;
}
 
struct tree* Pop() { //出队
    return Q.numQ[++Q.front];
}
 
int empty() { //判断对列是否为空
    return Q.rear == Q.front;
}
 
struct tree* creatTree (struct tree* root) {
    int value;
    scanf("%d", &value);
    if (value == -1)
        return NULL;
    root = (struct tree*)malloc(sizeof(struct tree));
    root->data = value;
    printf("请输入%d的左子树：", root->data);
    root->left = creatTree(root->left);
    printf("请输入%d的右子树：", root->data);
    root->right = creatTree(root->right);
    return root;
}
 
void LevelOrderTraversal (struct tree* root) { //二叉树的层次遍历
    struct tree* temp;
    Push(root);
    while (!empty()) {
        temp = Pop();
        printf("%d ", temp->data);  //输出队首结点
        if (temp->left)     //把Pop掉的结点的左子结点加入队列
            Push(temp->left);
        if (temp->right)    //把Pop掉的结点的右子结点加入队列
            Push(temp->right);
    }
}
 
int main() {
    printf("请输入头节点：");
    struct tree* root = creatTree(root);
    
    initilize();  //初始化队列
    
    LevelOrderTraversal(root);
    putchar('\n');
    
    return 0;
}
```