> 2020/3/16 今天又是元气满满的一天

## 1. C/C++ 基础知识
(1) 静态链接库和动态链接库的区别？

> 1、静态连接库就是把(lib)文件中用到的函数代码直接链接进目标程序，程序运行的时候不再需要其它的库文件；
> 2、动态链接就是把调用的函数所在文件模块（DLL）和调用函数在文件中的位置等信息链接进目标程序，程序运行的时候再从DLL中寻找相应函数代码，因此需要相应DLL文件的支持。

(2) 预编译、编译、汇编和链接几个阶段的作用？

> [参考链接](https://blog.csdn.net/qq_41899255/article/details/84791865)

## 2. 操作系统
(1) 进程有哪几个状态，各个状态之间的切换是如何发生的？

> [参考链接](https://blog.csdn.net/baidu_35534327/article/details/54317945)

(2) 分页和分段有什么区别？

> [参考链接](https://blog.csdn.net/zhongyangtony/article/details/80879425)

## 3. 计算机网络
(1) TCP 和 UDP区别，TCP如何保证可靠性？

> [参考链接](https://blog.csdn.net/qq_28804275/article/details/93377178)

(2) TCP 拥塞控制？

> [参考链接](https://www.cnblogs.com/wuchanming/p/4422779.html)

## 4. 数据库
(1) mysql 的悲观锁和乐观锁区别？

> [参考链接](https://www.cnblogs.com/cndarren/p/11787286.html)

(2) 什么是存储过程？用什么来调用？

> [参考链接](https://blog.csdn.net/xmh594603296/article/details/81879706)

## 5. 算法
(1) 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
   int result=0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i-1]<prices[i])
            {
                result += prices[i]-prices[i-1];
            }
        }
        return result;
    }
};
```

(2) 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

链接：https://leetcode-cn.com/problems/coin-change

```C++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        for (auto c : dp)
            cout << c << " ";
        return (dp[amount] > amount) ? -1 : dp[amount];

    }
};
```

