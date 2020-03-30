> 2020/3/19 

## 1. C/C++ 基础知识
(1) 在什么时候需要常引用？

不希望数据被改变时。

## 2. 操作系统
(1) 什么是上下文切换，上下文切换时操作系统做了些什么？

**进程上下文切换**
保存当前进程的虚拟内存、栈  、寄存器等，加载下一个进程的虚拟内存、栈、寄存器等。

**线程上下文切换**
保存当前进程的栈 、寄存器等，加载下一个进程的栈、寄存器等。

**中断上下文切换**
保存当前进程的栈、寄存器等，设置中断所需寄存器、内存堆栈、硬件中断参数等。

## 3. 计算机网络
(1) 从输入url到浏览器显示页面发生了什么？

https://www.cnblogs.com/yuanzhiguo/p/8119470.html


## 4. 数据库
(1) 主键和外键的区别？

主键是定义一个表中起主要作用的数据项，这些数据项的数据在表中是唯一的，同时系统按主键为表建立索引。

外键是定义一个表中的某数据项的数据，要参照另一个表的主键数据。既没有在另一个表的主键数据中出现的数据，不允许在这个表的外键数据项中出现。

## 5. 算法
(1) 最小路径和

> 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 https://leetcode-cn.com/problems/minimum-path-sum/

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(grid);
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int i = n - 2; i >= 0; --i) dp[m - 1][i] = grid[m - 1][i] + dp[m - 1][i + 1];
        for(int i = m - 2; i >= 0; --i) dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        for(int i = m - 2; i >= 0; --i){
            for(int j = n - 2; j >= 0; --j){
                dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);   
            }
        }
        return dp[0][0];
    }
};
```