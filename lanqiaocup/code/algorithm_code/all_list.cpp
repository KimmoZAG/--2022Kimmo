#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int per_list(vector<int> &list_1, int i, int n)
{
    if (n - 1 == i)
    {
        vector<int>::iterator i;
        for (i = list_1.begin(); i != list_1.end(); i++)
        {
            cout << *i;
        }
        cout << endl;
    }
    for (int j = i; j < n; j++)
    {
        swap(list_1[i], list_1[j]);
        per_list(list_1, i + 1, n);
        swap(list_1[i], list_1[j]);
    }
}

int main()
{
    vector<int> list_1;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        list_1.push_back(k);
    }
    per_list(list_1, 0, list_1.size());
    system("pause");
    return 0;
}