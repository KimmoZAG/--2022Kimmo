# include<iostream>
# include<cstring>

using namespace std;

int startx, starty, endx, endy;
// ����[endx, endy]�Žڵ�Ϊ���սڵ�

int m, n;
int a[100][100]; //1��ʾ�յ� 2��ʾ�ϰ��� 
int v[100][100]; //0��ʾδ���� 1��ʾ����
int min_step = 0xfffffff;

void dfs(int x,int y,int step)
{
    if(x == endx && y == endy)
    {
        if(step < min_step)
            min_step = step;
        return;
    }
    //˳ʱ����̽
    //�� && �� && �� && ��
    //��ʾ�ұ߽ڵ�Ϊ "δ����" �� "�յ�"
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
    //�����ͼ��С
    cin >> m >> n;
    //cout << m << n;
    //��ʼ����ͼ
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j]; 
        }
    }
    //������� ���յ�
    cin >> startx >> starty >> endx >> endy; 
    v[startx][starty] = 1;
    dfs(startx, starty, 0);
    cout << "���·��Ϊ" << min_step;
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