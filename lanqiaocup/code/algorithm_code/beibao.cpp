#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n; //��Ʒ������
    int c; //����������
    //int value[4]; //��Ʒ�ļ�ֵ
    //int weight[4]; //��Ʒ������
    int value[] = { 0,1500,3000,2000 }; 
    int weight[] = { 0,1,4,3 };
    c = 4;
    n = 3;
    //�������Ž�����3��4��
    int dp[4][5]; //��¼���Ž�ֵ������ǰ����������ֵ
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 4; j++) {
            dp[i][j] = 0;
        }
    }
    //�������
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    for (int i = 1; i <= 3; i++) { //������Ž�
        for (int j = 1; j <= 4; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//��������