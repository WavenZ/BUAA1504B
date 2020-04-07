> 2020/3/27

## 1. C/C++ 基础知识
(1) 请你回答一下 C++ 中拷贝赋值函数的形参能否进行值传递？

> 不能。如果是这种情况下，调用拷贝构造函数的时候，首先要将实参传递给形参，这个传递的时候又要调用拷贝构造函数。。如此循环，无法完成拷贝，栈也会满。

## 2. 操作系统
(1) 请你说一下多进程和多线程的使用场景。

> https://blog.csdn.net/weixin_39731083/article/details/82015830

## 3. 计算机网络
(1) 请你来说一下GET和POST的区别。

> 同313

## 4. 数据库
(1) 请你回答一下 map 和 unordered_map 优点和缺点？

> - map： map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是**有序的**，红黑树的每一个节点都代表着map的一个元素，因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行这样的操作，故红黑树的效率决定了map的效率。
> - unordered_map: unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的

## 5. 算法
(1) 在排序数组中查找数字，要求时间复杂度为 O(logn)
> 统计一个数字在排序数组中出现的次数。例如，输入排序数组 {1, 2, 3, 3, 3, 3, 4, 5} 和数字 3。由于 3 在这个数组中出现了 4 次，因此输出 4。

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        int n=nums.size();
        int left=0,right=n-1,mid;
        int x;
        int y;
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]>=target)right=mid;
            else left=mid+1;
        }
        if(nums[left]!=target)return 0;
        x=left;
        right=n;
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]<=target) left=mid+1;
            else right=mid;
        }
        y=left;
        return y-x;
    }
};
```

