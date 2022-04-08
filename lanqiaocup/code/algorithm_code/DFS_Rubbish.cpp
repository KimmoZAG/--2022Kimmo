//找联通块数（上下左右及对角线都认为相邻）

#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> st;
int a[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int b[8] = {1, -1, -1, 0, 1, -1, 0, 1};

void dfs(int x, int y)
{
    st.erase(make_pair(x, y));
    for (int i = 0; i < 8; i++)
        if (st.find(make_pair(x + a[i], y + b[i])) != st.end()) //如果找得到这返回对应迭代器，如果找不到则返回最后一个的迭代�?
            dfs(x + a[i], y + b[i]);
}

int main()
{
    int x, y, n, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        st.insert(make_pair(x, y));
    }
    set<pair<int, int>>::iterator it;
    while (!st.empty())
    {
        it = st.begin();
        x = it->first;
        y = it->second;
        dfs(x, y);
        ans++;
    }
    cout << ans << endl;
    return 0;
}