#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n; //物品的数量
    int c; //背包的容量
    //int value[4]; //物品的价值
    //int weight[4]; //物品的重量
    int value[] = { 0,1500,3000,2000 }; 
    int weight[] = { 0,1,4,3 };
    c = 4;
    n = 3;
    //构造最优解网格：3行4列
    int dp[4][5]; //记录最优解值，即当前背包的最大价值
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 4; j++) {
            dp[i][j] = 0;
        }
    }
    //填充网格
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    for (int i = 1; i <= 3; i++) { //输出最优解
        for (int j = 1; j <= 4; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//背包问题