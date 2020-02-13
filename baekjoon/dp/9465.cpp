#include <iostream>
using namespace std;
long long d[100001][4] = {
    0,
};
int s[100001][3] = {
    0,
};
int g(int n, int i)
{
    if (n == 1 && i != 2)
    {
        d[n][i] = s[n][i];
        return d[n][i];
    }
    if (d[n][i] > 0)
        return d[n][i];

    if (i == 0)
        d[n][i] = max(g(n - 1, 1), g(n - 1, 2)) + s[n][0];
    else if (i == 1)
        d[n][i] = max(g(n - 1, 0), g(n - 1, 2)) + s[n][1];
    else if (n != 1 && i == 2)
        d[n][i] = max(max(g(n - 1, 0), g(n - 1, 1)), g(n - 1, 2));
    return d[n][i];
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
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> s[i][j];
                cin.ignore();
            }
        }
        //cout << max(max(g(n, 0), g(n, 1)), g(n, 2)) << '\n';
        cout << g(n, 0) << ' ' << g(n, 1) << ' ' << g(n, 2) << '\n';
    }
    return 0;
}

/**
 * 연산이 너무 오래걸림. 점화식 정의가 불분명한듯
 * 
 * **/