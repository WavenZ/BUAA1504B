> 2020/3/18 加油

## 1. C/C++ 基础知识
(1) C语言中，局部变量能否和全局变量重名？

> 能，局部会屏蔽全局。

(2) C语言中，指针的占几个字节？

> C语言中指针的字节数与**CPU位数、操作系统位数、编译器位数**有关，为三者的最小值。
>
> 一般情况下，我们的计算机CPU为64位，操作系统一般也是装的64位操作系统。因此指针占的字节数与编译选项有关，当编译器为64位时，可以编译出32位和64位的程序，因此指针所占的字节数为4或者8。

## 2. 操作系统
(1) linux中，文件硬链接和软链接有什么区别？https://blog.csdn.net/gao_zhennan/article/details/79127232?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

(2) Linux中，查看系统所有进程命令，进程终止命令？

> 查看进程：`ps`和`top`。
> 进程终止：`kill`。

## 3. 计算机网络
(1) 对称加密与非对称加密？

> https://www.cnblogs.com/jfzhu/p/4020928.html

(2) DDos攻击？

> https://www.jianshu.com/p/e7a5fdc67b8f

## 4. 数据库
(1) 索引的底层实现原理和优化方法？

> https://blog.csdn.net/suifeng629/article/details/82624916

(2) 索引的优点？

> 1.大大加快数据的检索速度;
>
> 2.创建唯一性索引，保证数据库表中每一行数据的唯一性;
>
> 3.加速表和表之间的连接;
>
> 4.在使用分组和排序子句进行数据检索时，可以显著减少查询中分组和排序的时间。

## 5. 算法
(1) C或C++实现快速排序？

```C++
#include<iostream>

using namespace std;

template<class T>
void sort(T arr[], T low, T high) {
	//如果左边索引大于或者等于右边的索引,完成一个组
	if (low >= high)
		return;

	T first = low;
	T last = high;
	T key = arr[first];

	//在当前组查找
	while (first < last) {
		//向前遍历，找到小于key的数
		while (first < last && arr[last] >= key)
			--last;
		//小于key的数移到低端
		arr[first] = arr[last];
		//向后遍历，找到大于key的数
		while (first < last && arr[first] <= key)
			++first;
		//大于key的数移到高端
		arr[last] = arr[first];
	}

	arr[first] = key;
	sort(arr, low, first - 1);
	sort(arr, first + 1, high);
}

int main()
{
	int arr[] = { 77, 56, 73, 12, 44, 28, 11, 89, 23 };

	sort<int>(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}

```

(2) C或C++实现冒泡排序？

```C++
#include<iostream>
using namespace std;

const int BUFFSIZE = 10;
int Bubble_Sort(int Arr[]);
int main()
{
	int Arr[BUFFSIZE] = { 88,1,59,105,9,2,8,15,6,10 };  // 待排序元素
	Bubble_Sort(Arr); //排序
	system("pause");
		return 0;
}

int Bubble_Sort(int Arr[])
{
	int Counts = BUFFSIZE - 1; // 排序总轮数
	for (int i = 0; i < Counts; i++)
	{
		for (int j = 0; j < Counts - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j + 1];
				Arr[j + 1] = Arr[j];
				Arr[j] = tmp;
			}
		}
		//每一轮排序后输出元素顺序
		for (int i = 0; i < BUFFSIZE; i++)
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

```

