#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int g(vector<string> &a, int x, int y)
{
    int ans = 0;
    int t = a.size();

    //열 2개
    int cnt = 0, i = y;

    while (a[x][i] == a[x][i + 1])
    {
        cnt++;
        i++;
    }
    if (ans < cnt)
        ans = cnt;

    cnt = 0, i = y;
    while (a[x + 1][i] == a[x + 1][i + 1])
    {
        cnt++;
        i++;
    }
    if (ans < cnt)
        ans = cnt;

    // 행 2개
    cnt = 0, i = x;
    while (a[i][y] == a[i + 1][y])
    {
        cnt++;
        i++;
    }
    if (ans < cnt)
        ans = cnt;

    cnt = 0, i = x;
    while (a[i][y + 1] == a[i + 1][y + 1])
    {
        cnt++;
        i++;
    }
    if (ans < cnt)
        ans = cnt;

    cout << ans << '\n';
    return ans;
}
int main()
{
    int t;
    cin >> t;
    vector<string> a(t);
    for (int i = 0; i < t; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (j + 1 <= t)
            {
                swap(a[i][j], a[i][j + 1]);
                int tmp = g(a, i, j);
                if (ans < tmp)
                    ans = tmp;
                swap(a[i][j], a[i][j + 1]);
            }
        }
        for (int j = 0; j < t; j++)
        {
            if (i + 1 <= t)
            {
                swap(a[i][j], a[i + 1][j]);
                int tmp = g(a, i, j);
                if (ans < tmp)
                    ans = tmp;
                swap(a[i][j], a[i + 1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}