
# 蓝桥杯数据结构

***

## 1.数组

*C的课程中已经说得很明白了，这里主要写一点有关二维数组的操作.*

### 1.1 二维数组

#### 1.1.1二维数组的定义

基本的方法有以下两种

```C++
1.直接定义

//可以使用下面的方法来初始化二维数组
//也就是直接将二维数组铺平，写成一维数组的形式
int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
 
// 也可以使用标准的二维数组的初始化方式
int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
```

```C++
2.数组指针定义
//这种定义方法不推荐，因为声明时对内存的调用不容易搞明白,不如调用malloc函数动态分配空间
// 经典的写法
int array[][4] = {arrObj};
 
// 一种更帅的写法，本质上是定义了一个数组指针
int (*array)[4];
```

### 1.1.2二维数组的遍历

除开传统的for循环遍历数组的方法之外，这里再介绍一种骚操作

```C++
int arr_int[2][3] = { {2,3,4},{3,2,4}};
for (auto p = begin(arr_int); p != end(arr_int); ++p)
{
    for (auto q = begin(*p); q != end(*p); ++q)
    {
        cout << *q << " ";
    }
}
```

***

## 2.字符串

### 2.1 字符串

#### 2.1.1字符串的定义

在C++中，为char型数组单独创建了一种数据类型，即字符串（String），定义字符串的步骤通常如下

```C++
//导入string库
#include<string>

//函数中进行定义
    string arr_string = "我带你们打";
```

#### 2.1.1字符串的常见用法

既然单独设置了string类型，就说明开发者想通过直接调用方法的方式偷懒（~~bushi~~），这里对这些常用方法进行说明

* 长度计算——length（）方法 && 判断非空——empty（）方法

```C++
//length()
//这里要说明的是，length()方法的时间复杂度是O(1)，所以可以在for循环的循环条件中直接使用
    string_name.length()

//empyt()
//empyt()方法返回的是 0 或者 1
    string_name.empty()
```

* 字符串比较——compare（）方法 && 查找子字符串——find（）方法

```C++
//compare()
//compare()方法和c语言课程上编写的判断函数的使用有一些不一样，一样的字符串返回 0 不一样的返回 1
    A_string.compare(B_string)

//find()
//find(str_needfound)方法会查找字符串内是否含有str_needfound
//若含有，返回首字母的位置 && 若不含有，则返回 -1
```

* 字符插入——insert（）方法 && 字符串与字符数组、int型与字符串的转换

```C++
//insert()
//insert(place,need_instr)有两个输入参数，分别是place-插入位置 && need_instr-插入元素，可以是字符串，也可以是单个字符
    A_string.insert(place, "example")

//c_str() 、 data()
//c_str()、data()都可以用作字符串类型转字符数组类型
//区别在于，c_str会以"\0"作为结尾，而data()不会
    const char * new_name = str_name.str()
    const char * new_name = str_name.data()
*这里需要注意的是, const char * 型不可以修改其中字符，需要间接传值才可以进行修改
e.g.
    string newstr = "wdnmd";
    const char * new_str = newstr.data();
    char wokanxing[100];//这一步尤其重要，否则newst会自动将指针指向new_str导致报错
    char * newst = wokanxing;
    strcpy(newst, new_str);

//to_string()
//to_string()负责将int型转化为string型
    string_one = to_string(12345)
```

***

## 3.队列

### 3.1普通队列

#### 3.1.1队列的定义

队列作为数据结构的最重要的特点就是 **先进先出**

在stl容器中，使用队列需要按以下方式定义

```C++
//首先是导入库
#include<queue>

//其次是定义
    queue <typename> your_queue_name;
//举个例子
    queue <int> duilie;
```

#### 3.1.2队列的常见用法

马上，我们就可以从队列中看出stl容器的简便性

* 队列的基本操作：入队、出队
* 队列的基操的再扩充：获得队首、队尾元素、获取队列长度、判断队列是否为空

基本操作

```C++
//push()
//push(x)将x送入队列中，送入队伍尾部位置
    queue_one.push(pushObj)

//pop()
//pop()将队首元素弹出，不返回任何值
    queue_one.push()
```

扩充操作

```C++
//front() && back()
//front() 获取队首元素 && back() 获取队尾元素
    x_1 = queue_one.front()
    y_1 = queue_ont.back()

//size() && empty()
//size() 返回队列长度 && empty() 判断队列是否为空
    len = queue_one.size()
    bool_num = queue_one.empty()
```

### 3.2循环队列

循环队列可以使用queue库实现，只需要判断队列中元素数量即可实现

```C++
void circular_push(queue <int> & one_queue, int i)
{
    if(one_queue.size() == 10)
    {
        cout << "队列已经满了";
    }
    else 
    {
        one_queue.push(i)
    }
}
```
