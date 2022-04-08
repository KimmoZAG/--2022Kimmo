# 蓝桥杯算法笔记——图论

## 一、DFS（深度优先搜索）

算法简述：

```C++
    按照设定的搜索规则，沿着树的深度遍历树的节点，尽可能深的搜索树的分支。
```

算法思想：

```C++
    回溯法（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择
    并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为"回溯"。 
```

在迷宫题型中，DFS使用较为频繁，请看以下例题

### DFS例题1

有一迷宫，白色部分表示可通行，黑色部分表示不可通行，求出走出迷宫的最少步数（如图）

![图片](C:/Users/ZAG/Desktop/Item/algorithm/lanqiaocup/笔记/image_file/DFS_1.png)

在DFS的遍历中，遍历逻辑和点的标记尤为重要，在本例中，我们不妨采用顺时针的方式进行搜索（右=>下=>左=>上）

我们常常设置两张图：

```C++
    图一：标识可通行、障碍（不可通行）、边界、终点
    
    图二：标识图一中相应的点位是否遍历过
```

具体遍历时，下一个点位必须满足：没有被遍历过 && 可通行

```C++
//向右遍历
    if(a[x][y+1] == 1 && v[x][y+1] == 0)
    {
        //标识改点已经去过
        v[x][y+1] = 1;
        //递归查找下一个行动方向
        dfs(x, y+1, step+1);
        //回溯
        v[x][y+1] = 0;
    }
```

这里给出测试样例

```C++
//地图大小
//地图格式
//起点&终点坐标
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
```

***

## 二、BFS（广度优先搜索）

算法简介：

```C++
    广度优先搜索类似于树的层次遍历过程。它需要借助一个队列来实现。
```

算法思想：

```C++
    与DFS不同，BFS没有回溯以及递归搜索的思想，事实上，因为其队列实现的特性，BFS更加强调对各个节点之间关系的表述。
    可以这么说，BFS是边走边存，是可以重现行走路径的。在具体的代码实现当中，我们将可以体会到最短路径的唯一性
    PS：在实际操作中，可能会存在两条以上的最短路径，但是由于代码规定的搜索逻辑，一般只会显示一条路径。
```

### BFS例题1

这里将DFS中的例题拿来当做BFS的第一个例题

我们将设置几张图

```C++
    图一：标识可通行、障碍（不可通行）、边界、终点
    
    图二：标识图一中相应的点位是否遍历过

    图三：标识初始节点到某一节点总共需要的步数

    图四：标识父节点到子节点的行动方向
```

同DFS，具体遍历时，下一个点位必须满足：没有被遍历过 && 可通行

实现的具体代码如下：

```C++
int bfs()
{
    //初始节点入队
    queue_point.push(make_pair(begin_m, begin_n));

    while (!queue_point.empty())
    {
        int x = queue_point.front().first;
        int y = queue_point.front().second;
        queue_point.pop();
        for(int i = 0;i < 4;i++)
        {
            int next_x = x + x_move[i];
            int next_y = y + y_move[i];
            if(biaoshi[next_x][next_y] == 0 && ditu[next_x][next_y] == 1)
            {
                step_count[next_x][next_y] = step_count[x][y] + 1;
                way_togo[next_x][next_y] = i;
                biaoshi[next_x][next_y] = 1;
                queue_point.push(make_pair(next_x, next_y));
            }
            if(next_x == end_m && next_y == end_n)
            {
                return 0;
            }
        }
    }
}
```

***

## 三、最短路径算法

### 单源最短路径算法

单源最短路径是指：
&emsp;&emsp;***从某固定源点出发的最短路径***
&emsp;&emsp;形象地说就是求某一点到另一点的最短距离

#### 1.SPFA算法

SPFA由Bellman-Ford算法优化而来，可以处理带负权的图，下面对其思想进行介绍

```C++
解释（可略过）
    指针每每指向一个新节点，则查询当前节点到各个子节点的距离，
        若原点经过当前节点到子节点比原点直接到子节点的距离近，更新距离；
        若否，则不更新
    更新主节点的方式则类似BFS中入队出队的思想，具体依据是有向边的指向
具体思路：
    1.将源点v入队；
    2.从队列中取出一个顶点k，k出队（vis[k]=0）；
    3.以顶点k为中间点遍历与顶点k相邻的顶点更新dist数组，当(v,k,t)<(v,t)时更新dist[t]的权值，若顶点t不在队列中，则将顶点t入队（vis[t]=1）；
    4.重复2，3两步直到队列为空
```

实际算法执行过程中，我们创建：

```C++
    一个队列，用于下一节点的入队以及当前源点的出队
    两个数组，   一个布尔型（或int型），用于标记节点是否在队列中
                一个int型，用于存储初始节点到各个节点的距离
```

实际的代码实现如下：

```C++
int spfa()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << tu[i][j] << " ";
        }
        cout << endl;
    }
    memset(visit, false, sizeof(visit));
    queue_point.push(1);
    visit[1] = true;
    dis[1] = 0;
    while (!queue_point.empty())
    {
        int t = queue_point.front();
        queue_point.pop();
        visit[t] = false;
        for (int i = 1; i <= n; i++)
        {
            if (tu[t][i] != 0x3f3f3f3f)
            {   
                if (dis[i] > dis[t] + tu[t][i])
                {
                    dis[i] = dis[t] + tu[t][i];
                    if (!visit[i])
                    {
                        queue_point.push(i);
                        visit[i] = true;
                    }
                }
            }
        }
    }
    return dis[n];
}
```

那为什么有的时候看spfa的代码会有点懵呢，因为其定义了邻接表（数据结构会讲）作为存储图的路径
具体可以看看这个博客：<https://blog.csdn.net/czsupercar/article/details/88735143>

#### 2.Dij——迪杰斯特拉算法

dij的实现思路大致可以参考一下视频
<https://www.bilibili.com/video/BV1QK411V7V4?from=search&seid=11772333812494729653&spm_id_from=333.337.0.0>

实际算法执行过程中，我们创建：

```C++
    两个一维数组，  一个int型，用于存储源点到各个节点的最短距离（dis）
                   一个bool型，用于标记节点是否被遍历过
    一张图，        一个二维数组，用于记录各个节点到其相邻节点的距离
```

dij代码实现过程中的难点在于 对遍历各个节点并更新最短距离的逻辑 的理解

```C++
int dij()
{
    int min_path, mid_point;
    point[s] = true;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = tu[s][i];
    }
    for (int i = 1; i <= n; i++)
    {
        min_path = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            if (!point[j] && min_path > dis[j])
            {
                min_path = dis[j];
                mid_point = j;
            }
        }
        point[mid_point] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!point[j] && dis[j] > tu[mid_point][j] + dis[mid_point])
            {
                dis[j] = tu[mid_point][j] + dis[mid_point];
            }
        }
    }
    return dis[t];
}
```
