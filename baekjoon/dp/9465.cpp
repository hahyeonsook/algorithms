#include <iostream>
#include <string.h>
using namespace std;
#define max(a, b) (((a) > (b)) ? (a) : (b))
long long d[100001][4] = {
    -1,
};
int s[100001][3] = {
    -1,
};
int g(int n, int i)
{
    if (n == 1 && i != 2)
    {
        d[n][i] = s[n][i];
        return d[n][i];
    }
    if (d[n][i] > -1)
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
        memset(d, -1, sizeof(d));
        memset(s, -1, sizeof(s));
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> s[j][i];
            }
        }

        cout << max(max(g(n, 0), g(n, 1)), g(n, 2)) << '\n';
        //cout << g(n, 0) << ' ' << g(n, 1) << ' ' << g(n, 2) << '\n';
    }
    return 0;
}

/**
 * 연산이 너무 오래걸림. 점화식 정의가 불분명한듯
 * 2n 배열을 입력받을 때 깊게 생각안해서 이상하게 받아들임. 아마 처음 큰 값이 나왔던 건 쓰레기 값으로 계산해서 그런듯
 * 시간초과 >> 초기화를 0으로 했는데 점수값이 0일 경우 메모자이제이션이 작동하지 않음.
 * **/