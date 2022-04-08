#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000

int n, m;
int tu[MAXN][MAXN]; //有向图矩阵，用于存储各个点到相应节点的长度
int dis[MAXN];
bool visit[MAXN];       //标记数组，用于标记各个点是否在队列中
queue<int> queue_point; //队列，用于spfa

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

int main()
{
    cin >> n >> m;
    //设置距离，0x3f3f3f3f表示无限长
    memset(tu, 0x3f3f3f3f, sizeof(tu));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tu[a][b] = c;
    }
    int ret = spfa();
    if (ret == 0x3f3f3f3f)
        cout << "impossible" << endl;
    else
        cout << "最短路径为" << ret << endl;
    system("pause");
    return 0;
}

/*
3 3
1 2 5
2 3 -3
1 3 4
2
*/

/*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << tu[i][j] << " ";
        }
        cout << endl;
    }
*/