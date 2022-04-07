#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//定义边界，起始点，终点
int max_m, max_n, begin_m, begin_n, end_m, end_n;
//定义四张图
int ditu[101][101];
int biaoshi[101][101];
int step_count[101][101];
int way_togo[101][101];
//初始化队列
queue<pair<int, int>> queue_point;

//规定行进方向， 顺时针， 右、下、左、上
int x_move[4] = {1, 0, -1, 0};
int y_move[4] = {0, 1, 0, -1};

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

int print_out()
{
    cout << "总共花费了" << step_count[end_m][end_n] << "步" << endl;
    stack <int> move_direction;
    int before_x = end_m;
    int before_y = end_n;
    int x = end_m;
    int y = end_n;
    for(int n = 1;n <= step_count[end_m][end_n];n++)
    {
        move_direction.push(way_togo[x][y]);
        x = x - x_move[way_togo[before_x][before_y]];
        y = y - y_move[way_togo[before_x][before_y]];
        before_x = x;
        before_y = y;
    }
    while(!move_direction.empty())
    {
        int ml = move_direction.top();
        if(ml == 0)         cout << "下";
        else if(ml == 1)    cout << "右";
        else if(ml == 2)    cout << "上";
        else if(ml == 3)    cout << "左";
        move_direction.pop();
    }
    return 0;
}

int main()
{
    //输入地图大小
    cin >> max_m >> max_n;
    // cout << m << n;
    //初始化地图
    for (int i = 1; i <= max_m; i++)
    {
        for (int j = 1; j <= max_n; j++)
        {
            cin >> ditu[i][j];
        }
    }
    //输入起点 、终点
    cin >> begin_m >> begin_n >> end_m >> end_n;

    //标记初始节点
    biaoshi[begin_m][begin_n] = 1;
    bfs();
    print_out();
    system("pause");
    return 0;
}