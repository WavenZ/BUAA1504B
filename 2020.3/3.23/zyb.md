> 2020/3/19 

## 1. C/C++ 基础知识
(1) 在什么时候需要常引用？

## 2. 操作系统
(1) 什么是上下文切换，上下文切换时操作系统做了些什么？

[参考](https://blog.csdn.net/qq_41359051/article/details/89673188)

## 3. 计算机网络
(1) 从输入url到浏览器显示页面发生了什么？

[参考](https://www.cnblogs.com/yuanzhiguo/p/8119470.html)

## 4. 数据库
(1) 主键和外键的区别？

主键是能确定一条记录的唯一标识;
外键用于与另一张表的关联。

## 5. 算法
(1) 最小路径和

> 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 https://leetcode-cn.com/problems/minimum-path-sum/
```c
# define min(a, b) ((a) < (b) ? (a) : (b))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int row=gridSize,col=*gridColSize,i,j; //行 gridSize  列 * gridColSize
    for(i=1;i<row;i++)  grid[i][0]+=grid[i-1][0];
    for(j=1;j<col;j++)  grid[0][j]+=grid[0][j-1]; //边界最小路径和
    
    for(i=1;i<row;i++){
        for(j=1;j<col;j++)
            grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
    }	//非边界求最小路径和
    
    return grid[row-1][col-1];
}
```