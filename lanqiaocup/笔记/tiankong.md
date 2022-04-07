# 填空知识点

## 一、杂项

* 存储空间
  
```C++
计算机中：
    1B  = 8bit
    1KB = 1024B   
    1MB = 1024KB
    1GB = 1024MB
```

例题：
![图片](C:/Users/ZAG/Desktop/Item/algorithm/lanqiaocup/笔记/image_file/int_length.png)

32位 == 32b == 4B
因此可以存 256 × 1024 × 1024 ÷ 4个32位二进制整数

* 模拟
  
```C++
模拟题中，一般要求能够通过编程实现模拟过程
```

![图片](C:/Users/ZAG/Desktop/Item/algorithm/lanqiaocup/笔记/image_file/moni_1.png)

* 几何

几何题中一般涉及到比较大小
我们常常将大小差距在1e-8之内的两个数看成一个数

![图片](C:/Users/ZAG/Desktop/Item/algorithm/lanqiaocup/笔记/image_file/tiankong_3.png)

本题可以通过求直线方程的方式求解
一般我们会用到sort，而sort默认是升序排序，我们一般会载入第三个参数cmp对sort的比较逻辑进行修改

这里举个例子

```C++
struct Jiegouti
{
    double k, b;
}
//如果想实现先比较k，在比较b大小的逻辑操作，我们可以定义以下比较器
bool cmp(Jiegouti a, Jiegouti b)
{
    if(a.k == b.k)
    {
        return a.b < b.b;
    }
    else
    {
        return a.k < b.k;
    }
}
```
