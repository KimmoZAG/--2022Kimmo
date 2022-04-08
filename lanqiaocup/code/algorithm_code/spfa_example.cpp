#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000

int n, m;
int tu[MAXN][MAXN]; //����ͼ�������ڴ洢�����㵽��Ӧ�ڵ�ĳ���
int dis[MAXN];
bool visit[MAXN];       //������飬���ڱ�Ǹ������Ƿ��ڶ�����
queue<int> queue_point; //���У�����spfa

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
    //���þ��룬0x3f3f3f3f��ʾ���޳�
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
        cout << "���·��Ϊ" << ret << endl;
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