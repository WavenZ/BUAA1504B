> 2020/3/26

## 1. C/C++ 基础知识
(1) C语言中NULL的含义？

> 空，值为0，一般用于指针https://www.cnblogs.com/qingergege/p/6494751.html

## 2. 操作系统
(1) 死锁避免的基本思想？

> 死锁避免的基本思想是：对进程所发出的的每一个申请资源命令加以动态地检查，并根据检查结果决定是否进行资源分配。就是说，在资源分配过程中若预测有发生死锁的可能性，则加以避免。这种方法的关键是确定资源分配的安全性。

## 3. 计算机网络
(1) 常见http响应报文状态码含义

> https://blog.csdn.net/TyphoonHao/article/details/81040700

## 4. 数据库
(1) 主键和索引有什么区别？

> https://www.cnblogs.com/chuijingjing/p/11725235.html

## 5. 算法
(1) 实现汉诺塔

```C++
class Solution {//https://leetcode-cn.com/problems/hanota-lcci/
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C){
        if (n == 1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n-1, A, C, B);    // 将A上面n-1个通过C移到B
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了
        move(n-1, B, A, C);     // 将B上面n-1个通过空的A移到C
    }
};
```

