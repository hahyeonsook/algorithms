#include <iostream>
using namespace std;
const long long mod = 1000000000;
long long d[10001][10];
int main()
{

    int n;
    cin >> n;

    d[1][0] = 0;
    for (int i = 0; i <= 9; i++)
        d[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                d[i][j] = d[i - 1][1];
            else if (j == 9)
                d[i][j] = d[i - 1][8];
            else
                d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]);
            d[i][j] %= mod;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';

    return 0;
}

/**
 * https://www.acmicpc.net/board/view/12771
 * dp식은 맞는데 결과값이 틀리게 나오는 경우 초기값이 문제인 경우이다.
 * 0으로 시작하는 수가 없다.
 * 1. 초기식 잘 세우기
 * 2. 관계식 잘 세우기
 * 
 * 
 *         cout << d[n][i] << ' ';
    cout << '\n';
 **/