#include <iostream>
using namespace std;
const int mod = 10007LL;
long long d[1001][11];
long long g(int n, int i)
{
    if (n == 1)
    {
        d[n][i] = 1;
        return d[n][i];
    }

    if (d[n][i] > 0)
        return d[n][i];

    for (int k = 0; k <= i; k++)
    {
        d[n][i] += g(n - 1, k) % mod;
    }

    return d[n][i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += g(n, i);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
/**
 * 예외 처리에서 2를 예외로 잘못처리함
 * 인수 두개를 받는 재귀함수는 처음 만들어봤는데, 1일때 예외를 처리할 때 초기화가 되지 않아 뒤의 연산에 반영되지 않았어서 틀렷엇음
 * **/