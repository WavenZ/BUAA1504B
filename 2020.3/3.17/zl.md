> 2020/3/17 go go go

## 1. C/C++ 基础知识
(1) 在linux系统下使用gcc编译c++，若程序跑挂了怎么找到程序里面的问题？

1. 检查程序中是否存在访问错误（数组越界，空指针等）、堆栈溢出等常见错误。
2. 可以通过gdb调试或者利用打印信息来定位程序跑飞的位置。
3. 如果有core生成，利用gdb来分析core文件找到跑飞的原因。

(2) 接上一问，有没有办法把出错的现场保留下来，然后事后去定位问题？

编译程序时打开-g参数，当程序崩溃时会产生core文件，core文件会包含程序运行时的内存，寄存器状态、堆栈指针，内存管理信息还有各种堆栈信息等。通过分析core可以定位到程序产生异常时的堆栈信息，从而找到出现问题的代码。

## 2. 操作系统
(1) linux下什么命令可以查看所有进程？

1. ps命令：运用该命令可以确定有哪些进程正在运行和运行状态、进程是否结束、进程是否僵死、进程占用系统资源等信息。
2. top命令：top命令可以是实时显示各个进程状况。
3. pstree命令：pstree命令以树状图的方式展现进程之间的派生关系。
4. pgrep命令：pgrep命令以名称为一句从运行队列中查找进程，并显示查找到的进程id。

(2) 常见的Linux命令：查看程序占用多少内存？

方法一：
1. 首先利用`ps -ef | grep name`查找到进程name的进程id。
2. 再利用`top -p id`命令查看内存。

方法二：
1. `ps -aux | grep 进程名`。

方法三：
1. `cat /proc/进程号/status`。

## 3. 计算机网络
(1) 什么场景下比较适合UDP协议？

UDP一般用于即时通信、在线视频等要求实时性能好，但不用保证不丢包的场景。

(2) TCP怎么样做流量控制？

1. 为什么要流量控制：TCP通信的时候，发送方的速率和接收方的速率不一定相等，如果发送方的发送速率太快，会导致接收方处理不过来，这时候接收方只能把处理不过来的数据存在缓存区里。如果缓存区满了发送方还再疯狂着发送数据，接收方只能把收到的数据包丢掉，大量的丢包会极大的浪费网络资源。因此，我们需要控制发送方的发送速率，让接收方与发送方处于一种动态平衡。

2. TCP流量控制方法：接收方每次收到数据包，可以再发送确认报文的时候，同时告诉发送方自己的缓存区还剩余多少是空闲的，我们把这个缓存区的剩余大小称之为接收窗口大小。当发送方收到之后，便会调整自己的发送速率，也就是调整自己发送窗口的大小，当发送方收到接收方窗口的大小为0时，发送方就会停止发送数据，防止出现大量丢包的情况发生。

## 4. 数据库
(1) 请你说一说数据库索引

数据库索引的优点：
1. 通过创建唯一性索引，可以保证数据库表中的每一行数据的唯一性。
2. 可以大大加快数据的检索速度。
3. 加速表和表之间的连接，特别是再实现数据的参考完整性方面特别有意义。
4. 在使用分组和排序子句进行数据检索时，可以显著减少查询中分组和排序的时间。
5. 通过使用索引，可以在查询的过程中，使用优化隐藏器，提高系统的性能。

增加索引的缺点：
1. 创建索引和维护索引要耗费时间，且随着数据量的增加而增加。
2. 索引需要占用物理空间。
3. 当对表中的数据进行增加、删除和修改的时候，索引也要动态的维护，降低了数据的维护速度。


(2) 多加索引一定会好吗？

不一定，如上题。

## 5. 算法
(1) 给你一个长度为N的无序数组，然后找出里面最大的K个数。

方法一：利用快排中的partition，时间复杂度O(n)。

```cpp
template<typename T>
class TopK{
public:
    static vector<T> search(vector<T>& arr, unsigned k){
        if(arr.size() <= k) return vector<T>(arr.begin(), arr.end());
        quick_search(arr, 0, arr.size() - 1, k);
        return vector<T>(arr.begin(), arr.begin() + k);
    }
private:
    static void quick_search(vector<T>& arr, int start, int end, unsigned k){
        int pos = partition(arr, start, end);
        if(pos == k) return;
        else if(pos < k) quick_search(arr, pos + 1, end, k);
        else quick_search(arr, start , pos - 1, k);
    }
    static int partition(vector<T>& arr, int start, int end){
        default_random_engine e;
        uniform_int_distribution<unsigned> u(start, end);
        swap(arr[end], arr[u(e)]);
        int pivot = arr[end];
        int pos = start;
        for(int i = start; i < end; ++i){
            if(arr[i] < pivot){
                swap(arr[pos++], arr[i]);
            }
        }
        swap(arr[pos], arr[end]);
        return pos;
    }
};
```
缺点：需要修改原数组。

方法二：维护一个大小为K的容器，当容器未满时，将元素插入，否则将当前元素与容器中的最小元素比较，如果大于该元素，则替换之。时间复杂度为O(nlogk)。
```cpp
```

(2) 爬楼梯问题，你可以一次爬1层或2层，如果有n层楼梯，一共有点多少种解法？。

思路和斐波那契数列的解法一样，通过自底向上的方法来计算。

```cpp
int climb_stairs(int n){
    if(n <= 0) return 0;
    if(n <= 2) return n;
    int ans, ans1 = 1, ans2 = 2;
    for(int i = 3; i <= n; ++i){
        ans = ans1 + ans2;
        ans2 = ans1;
        ans1 = ans;
    }
    return ans;
}
```

