> 2020/3/18 加油

## 1. C/C++ 基础知识
(1) C语言中，局部变量能否和全局变量重名？

可以，局部变量会屏蔽全局变量。

(2) C语言中，指针的占几个字节？

C语言中指针的字节数与**CPU位数、操作系统位数、编译器位数**有关，为三者的最小值。

一般情况下，我们的计算机CPU为64位，操作系统一般也是装的64位操作系统。因此指针占的字节数与编译选项有关，当编译器为64位时，可以编译出32位和64位的程序，因此指针所占的字节数为4或者8。

---
## 2. 操作系统
(1) linux中，文件硬链接和软链接有什么区别？

在Linux系统中，链接分为两种，一种是硬链接（Hard link），另一种称为符号链接或软链接（Symbolic Link）。
1. 默认不带参数的情况下，ln创建的是硬链接，带-s参数的ln命令创建的是软链接。
2. 硬链接文件与源文件的inode节点号相同，而软链接文件的inode节点号，与源文件不同，
3. ln命令不能对目录创建硬链接，但可以创建软链接。对目录的软链接会经常使用到。
4. 删除软链接文件，对源文件和硬链接文件无任何影响。
5. 删除文件的硬链接文件，对源文件及软链接文件无任何影响。
6. 删除链接文件的源文件，对硬链接文件无影响，会导致其软链接失效（红底白字闪烁状）。
7. 同时删除源文件及其硬链接文件，整个文件才会被真正的删除。
8. 很多硬件设备的快照功能，使用的就是类似硬链接的原理。
9. 软链接可以跨文件系统，硬链接不可以跨文件系统。

(2) Linux中，查看系统所有进程命令，进程终止命令？

查看进程：`ps`和`top`。
进程终止：`kill`。

---
## 3. 计算机网络
(1) 对称加密与非对称加密？

1. 对称加密：加密和解密的密钥是同一个。
2. 非对称加密：非对称加密需要两个密钥：公开密钥和私有密钥。

**对称加密**

优点：算法公开、计算量小、加密速度快、加密效率高。

缺点：通信双方中的一方密钥泄露将导致通信不安全。此外，每对用户每次使用对称加密算法时，都需要使用其他人不知道的唯一密钥，这使得收发双方所持有的密钥数量巨大。

常见对称加密算法：DES、3DES、Blowfish、IDEA、RC4、RC5、RC6和AES。


**非对称加密**

甲方生成一对密钥（公钥和私钥），将公钥对所有人公开，用以解密私钥加密的数据。而公钥加密的数据只有私有能够解密。

优点：安全

缺点：速度较慢

常见非对称加密算法：RSA、ECC、Diffie-Hellman、EI Gamal、DSA。

(2) DDos攻击？

全称 Distributed Denial of Service，中文为“分布式拒绝服务”，就是利用大量合法的分布式服务器对目标发送请求，从而导致正常合法用户无法获得服务。通俗点将就是利用网络节点资源如：IDC服务器、个人PC、手机、智能设备、打印机、摄像头等对目标发起大量攻击请求，从而导致服务器拥塞而无法对外提供正常服务。

## 4. 数据库
(1) 索引的底层实现原理和优化方法？

在常见的数据库系统中，索引使用的数据结构多是 B-Tree 或 B+Tree。例如，MySql 使用的是 B+Tree，Oracle 及 Sysbase 使用的是 B-Tree。

优化方法：


(2) 索引的优点？

## 5. 算法
(1) C或C++实现快速排序？

```cpp
template<typename T>
class Quick_sort{
public:
    static void sort(vector<T>& arr){
        if(arr.empty()) return;
        quick_sort(arr, 0, arr.size() - 1);
    }
private:
    static void quick_sort(vector<T>& arr, int start, int end){
        if(start >= end) return;
        int pos = partition(arr, start, end);
        quick_sort(arr, start, pos - 1);
        quick_sort(arr, pos + 1, end);
    }
    static int partition(vector<T>& arr, int start, int end){
        default_random_engine e;
        uniform_int_distribution<int> u(start, end);
        swap(arr[end], arr[u(e)]);
        int pivot = arr[end];
        int pos = start;
        for(int i = start; i < end; ++i){
            if(arr[i] < pivot){
                swap(arr[i], arr[pos++]);
            }
        }
        swap(arr[pos], arr[end]);
        return pos;
    }
};
```

快速排序的平均时间复杂度为 O(nlogn)，而最坏时间复杂度为 O(n²)，最坏情况发生在待排序数组为逆序排列时。

因此，对`pivot`元素的随机化操作使得当原数组的为逆序排序时，算法的时间复杂度不会从 O(nlogn) 退化为 O(n²)。


(2) C或C++实现冒泡排序？

冒泡排序是一种稳定的排序算法，它的时间复杂度是`O(n²)`。

最经典的写法如下：
```c
template<class T>
void bubble_sort(std::vector<T>& vec) {
	int len = vec.size();
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j)
			if (vec[j] > vec[j + 1])
				std::swap(vec[j], vec[j + 1]);
	} // for(int i = 0; i < len - 1; ++i)
} // bubble_sort
```
其中值得说的只有两个点：

`for(int i = 0; i < len - 1; ++i)`：外层循环次数为`n - 1`次而不是`n`次，这是因为最后一次只有一个元素，因此不需要再比较了。

`for(int j = 0; j < len - i - 1; ++j)`：这里的`j < len - i - 1`使得内循环的次数逐渐减少，这是因为已经冒泡到的尾端`n + 1`个元素已经不需要再判断了。

上面这种经典的写法虽然比较容易令人接受，但是很容易写出不完美的循环边界，也就是上述代码中的`i < len - 1`和`j < len - i - 1`。

下面是我认为一种不容易写错，且容易令人理解的写法：

```c
template<class T>
void bubble_sort(std::vector<T>& vec) {
	int len = vec.size();
	for (; len > 1; --len) {
		for (int i = 0; i < len - 1; ++i)
			if (vec[i] > vec[i + 1])
				std::swap(vec[i], vec[i + 1]);
	} // for(; len > 1; --len)
} // bubble_sort
```
上述写法的思想在于，外层循环为**剩余要排序的元素个数**`len`，于是内层循环的次数为`len - 1`次。由于当剩余元素个数`len <= 1`时就不必排序了，因此外层for循环判断`len > 1`即可。

#### 冒泡排序优化算法

**1. 加入有序判断**

在冒泡排序的过程中，如果某一次内层循环没有发生过交换操作，则表示整个序列已经有序，可以结束排序。
```c
template<class T>
void bubble_sort(std::vector<T>& vec) {
	int len = vec.size();
	for (; len > 1; --len) {
		bool never_swap = true;
		for (int i = 0; i < len - 1; ++i)
			if (vec[i] > vec[i + 1]) {
				std::swap(vec[i], vec[i + 1]);
				never_swap = false;
			} 
		if (never_swap) break;
	} // for(; len > 1; --len)
} // bubble_sort
```
其中，加入的变量`never_swap`来记录是否发生过交换操作，如果一次内循环没有发生过交换操作，则退出循环。

例如，当对序列`{1, 3, 4, 5, 6, 6, 8, 7}`进行冒泡排序时

第一次内循环后，序列变化为`{1, 3, 4, 5, 6, 6, 7, 8}`

第二次内循环未发生元素交换，此时`never_swap = true`，退出循环。

**2. 判断有序长度**

在冒泡排序的过程中，外层循环变量`len`按照`1`的步长逐渐递减。在很多情况下实际上可以走捷径，当尾部数据有序时，之后的冒泡操作是不会更改它们的数据。

因此，可以通过记录最后一次发生交换操作的位置来控制外层循环。这也可以等价的看做最后一次交换发生的位置可以作为下一次内循环的长度。

```c
template<class T>
void bubble_sort(std::vector<T>& vec) {
	int len = vec.size();
	while(len > 1){
		int last_swap_pos = -1;
		for (int i = 0; i < len - 1; ++i)
			if (vec[i] > vec[i + 1]) {
				std::swap(vec[i], vec[i + 1]);
				last_swap_pos = i;
			} 
		if (last_swap_pos == -1) break;	// never_swap
		else len = last_swap_pos + 1; // len = last_swap_pos - 0 + 1;
	} // for(; len > 1; --len)
} // bubble_sort
```
上述代码中用`last_swap_pos`来保存最后一次发生交换的位置，则下一次循环需要排序的长度为`last_swap_pos - 0 + 1`。此外，如果`last_swap_pos`保持为初始值`-1`，则表示没有发生过交换，满足上一个优化情况。

下面分别是朴素的冒泡排序算法、第一种优化、第二种优化算法对序列`{3, 2, 1, 5, 7, 6, 7, 8}`进行排序的对比：

<div align = center>
<img src = "https://img-blog.csdnimg.cn/20190919222750978.png" width = "80%">
<div align = left>

可以看到，朴素的冒泡排序算法在序列基本有序时会进行大量无效的循环，而经过优化之后可以减少很多没必要的操作，从而提升性能。


