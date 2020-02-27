//1932.정수 삼각형 https://www.https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long d[501][501];
int t[501][501];
long long g(int n, int i)
{
    if (d[n][i] > -1)
        return d[n][i];
    if (i == 0)
        d[n][i] = g(n - 1, i) + t[n][i];
    else
        d[n][i] = max(g(n - 1, i), g(n - 1, i - 1)) + t[n][i];
    return d[n][i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d, -1, sizeof(d));
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> t[i][j];
        }
    }
    d[0][0] = t[0][0];
    int tmp = -1; /*
    for (int i = 0; i < n; i++)
    {
        if (tmp < g(n, i))
            tmp = d[n][i];
    }*/
    cout << g(n, 1) << ' ' << g(n, 2) << '\n';
    cout << tmp << '\n';
    return 0;
}