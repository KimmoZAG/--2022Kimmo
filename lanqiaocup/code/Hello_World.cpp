#include <iostream>
#include <algorithm>

using namespace std;

struct Jiegouti
{
    double k, b;
} J[3];
//�����ʵ���ȱȽ�k���ڱȽ�b��С���߼����������ǿ��Զ������±Ƚ���
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

int main()
{
    J[0].k = 1;
    J[0].b = 1;
    J[1].k = 2;
    J[1].b = 2;
    J[2].k = 2;
    J[2].b = 1;
    J[3].k = 1;
    J[3].b = 2;
    sort(J, J + 4, cmp);
    for (int i = 0; i < 4; i++)
    {
        cout << J[i].k << J[i].b << endl;
    }
    system("pause");
    return 0;
}