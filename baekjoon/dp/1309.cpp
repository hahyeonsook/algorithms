#include <iostream>
using namespace std;
const int mod = 9901;
long long d[100001][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            d[i][0] = 1;
            d[i][1] = 1;
            d[i][2] = 1;
        }
        else
        {
            d[i][0] = (d[i - 1][1] + d[i - 1][2] + d[i - 1][0]) % mod;
            d[i][1] = (d[i - 1][0] + d[i - 1][2]) % mod;
            d[i][2] = (d[i - 1][0] + d[i - 1][1]) % mod;
        }
    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';
    return 0;
}

/**
 * d[i][0]에서 d[i-1][0]을 더하는 걸 잊었음.
 *
 **/