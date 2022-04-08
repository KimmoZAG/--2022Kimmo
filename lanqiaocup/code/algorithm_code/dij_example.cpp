#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 3000

using namespace std;

bool point[MAXN];
int tu[MAXN][MAXN];
int dis[MAXN];
int n, m, s, t;

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

int main()
{
    cin >> n >> m >> s >> t;
    int a, b, c;
    memset(tu, 0x3f3f3f3f, sizeof(tu));
    memset(point, false, sizeof(point));
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        tu[a][b] = c;
        tu[b][a] = c;
    }
    int min_step = dij();
    cout << min_step << endl;
    system("pause");
    return 0;
}
