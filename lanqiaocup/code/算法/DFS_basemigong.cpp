# include<iostream>
# include<cstring>

using namespace std;

int startx, starty, endx, endy;
// 定义[endx, endy]号节点为最终节点

int m, n;
int a[100][100]; //1表示空地 2表示障碍物 
int v[100][100]; //0表示未访问 1表示访问
int min_step = 0xfffffff;

void dfs(int x,int y,int step)
{
    if(x == endx && y == endy)
    {
        if(step < min_step)
            min_step = step;
        return;
    }
    //顺时针试探
    //右 && 下 && 左 && 上
    //表示右边节点为 "未访问" 的 "空地"
    if(a[x][y+1] == 1 && v[x][y+1] == 0)
    {
        v[x][y+1] = 1;
        dfs(x, y+1, step+1);
        v[x][y+1] = 0;
    }
    if(a[x+1][y] == 1 && v[x+1][y] == 0)
    {
        v[x+1][y] = 1;
        dfs(x+1, y, step+1);
        v[x+1][y] = 0;
    }
    if(a[x][y-1] == 1 && v[x][y-1] == 0)
    {
        v[x][y-1] = 1;
        dfs(x, y-1, step+1);
        v[x][y-1] = 0;
    }
    if(a[x-1][y] == 1 && v[x-1][y] == 0)
    {
        v[x-1][y] = 1;
        dfs(x-1, y, step+1);
        v[x-1][y] = 0;
    }
}

int main()
{
    //输入地图大小
    cin >> m >> n;
    //cout << m << n;
    //初始化地图
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j]; 
        }
    }
    //输入起点 、终点
    cin >> startx >> starty >> endx >> endy; 
    v[startx][starty] = 1;
    dfs(startx, starty, 0);
    cout << "最短路径为" << min_step;
    system("pause");
    return 0;
}

/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
*/