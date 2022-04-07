#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//����߽磬��ʼ�㣬�յ�
int max_m, max_n, begin_m, begin_n, end_m, end_n;
//��������ͼ
int ditu[101][101];
int biaoshi[101][101];
int step_count[101][101];
int way_togo[101][101];
//��ʼ������
queue<pair<int, int>> queue_point;

//�涨�н����� ˳ʱ�룬 �ҡ��¡�����
int x_move[4] = {1, 0, -1, 0};
int y_move[4] = {0, 1, 0, -1};

int bfs()
{
    //��ʼ�ڵ����
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
    cout << "�ܹ�������" << step_count[end_m][end_n] << "��" << endl;
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
        if(ml == 0)         cout << "��";
        else if(ml == 1)    cout << "��";
        else if(ml == 2)    cout << "��";
        else if(ml == 3)    cout << "��";
        move_direction.pop();
    }
    return 0;
}

int main()
{
    //�����ͼ��С
    cin >> max_m >> max_n;
    // cout << m << n;
    //��ʼ����ͼ
    for (int i = 1; i <= max_m; i++)
    {
        for (int j = 1; j <= max_n; j++)
        {
            cin >> ditu[i][j];
        }
    }
    //������� ���յ�
    cin >> begin_m >> begin_n >> end_m >> end_n;

    //��ǳ�ʼ�ڵ�
    biaoshi[begin_m][begin_n] = 1;
    bfs();
    print_out();
    system("pause");
    return 0;
}