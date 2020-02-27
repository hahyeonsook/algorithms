#include <iostream>
#include <algorithm>
using namespace std;
long long d[10001][2] = {
    -1,
};
int p[1001] = {
    -1,
};
long long g(int n, int i)
{
    if (n == 1)
        return d[n][0];
    if (d[n][i] > -1)
        return d[n][i];

    if (i == 0)
        d[n][0] = g(n - 1, 2) + p[n - 1] + p[n];
    else if (i == 1)
        d[n][1] = g(n - 1, 1) + p[n];
    else if (i == 2)
        d[n][2] = g(n - 1, 0);

    return d[n][i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    d[1][0] = *max_element(p, p + n);
    cout << max(max(g(n, 0), g(n, 1)), g(n, 2)) << '\n';
    cout << d[n][0] << ' ' << d[n][1] << ' ' << d[n][2] << '\n';
    return 0;
}