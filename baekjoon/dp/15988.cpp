#include <iostream>
using namespace std;
const long long mod = 1000000009LL;
long long d[1000001] = {0, 1, 2, 4};
long long g(int n)
{
    if (d[n] > 0)
        return d[n];
    if (n - 1 >= 0)
        d[n] += g(n - 1);
    if (n - 2 >= 0)
        d[n] += g(n - 2);
    if (n - 3 >= 0)
        d[n] += g(n - 3);

    d[n] %= mod;
    return d[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << g(n) << '\n';
    }
    return 0;
}
//예외처리에서 공집합의 경우를 추가해주지 않음, 0의 경우 경우의 수를 0으로 초기화해주니까 맞음..ㅎ