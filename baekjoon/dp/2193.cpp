#include <iostream>
using namespace std;
long long d[91][2];
void g(int n)
{
    d[1][0] = 0;
    d[1][1] = 1;
    d[2][0] = 1;
    d[2][1] = 0;

    for (int i = 3; i <= n; i++)
    {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }
    cout << d[n][0] + d[n][1] << '\n';
}
int main()
{
    int n;
    for (int i = 1; i <= 90; i++)
        g(i);

    return 0;
}

/**
 * dp 행렬을 담는 데이터가 int일 경우 범위를 넘어가서 음수값을 출력함.
 * long long으로 바꿈
 * 
 **/