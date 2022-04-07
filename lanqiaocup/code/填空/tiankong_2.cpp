# include<iostream>

using namespace std;

int kapian[10];

int del_kapian(int num)
{
    int weishu;
    while(num != 0)
    {
        weishu = num % 10;
        num = num / 10;
        //cout << kapian[weishu] << endl;
        kapian[weishu]--;
        if(kapian[weishu] == 0) return 0;
    }
    return 1;
}

int main()
{
    for(int i = 0;i <= 9;i++)  kapian[i] = 2021;

    for(int i = 1;i <= 999999;i++)
    {
        if(del_kapian(i) == 0)
        {
            cout << "一共可以组成" << i << "个数" << endl;
            break;
        }
    }    
    system("pause");
    return 0;
}
// 最终运行的答案为3181