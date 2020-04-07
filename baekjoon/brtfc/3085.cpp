#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int init(vector<string> &c)
{
    int row = 0, column = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {

        if (c[i][2] != c[i + 1][2])
        {
            column += 1;
            if (ans < column)
                ans = column;
            column = 0;
        }
        else
        {
            std::cout << c[i][2] << ", " << c[i + 1][2] << " ";
            column += 1;
        }
    }
    if (column != 0)
    {
        column += 1;
        if (ans < column)
            ans = column;
        column = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (c[2][i] != c[2][i + 1])
        {
            column += 1;
            if (ans < column)
                ans = column;
            column = 0;
        }
        else
        {
            std::cout << c[2][i] << ", " << c[2][i + 1] << " ";
            column += 1;
        }
    }
    if (column != 0)
    {
        column += 1;
        if (ans < column)
            ans = column;
        column = 0;
    }
    return ans;
} //해결!!! 같은 문자열이 마지막 행, 열까지 있을 때 그 줄을 count하지 않음. if 문에 걸리고 cnt 값을 올린 후 ans와 값을 비교하지 않고 반복문을 나감.. 그래서 카운트가 안됐던 것.. 그래서 while으로 모두 돌린 후 ans와 비교했구나..
int check(vector<string> &c, int a, int b)
{
    int i = 0;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (c[i][b] == c[i + 1][b])
            cnt++;
        else
        {
            cnt++;
            if (ans < cnt)
                ans = cnt;
            cnt = 0;
        }
    }
    cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {

        if (c[a][i] == c[a][i + 1])
            cnt++;
        else
        {
            cnt++;
            if (ans < cnt)
                ans = cnt;
            cnt = 0;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<string> c(n); //candy
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int ans = init(c);
    /*
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int tmp = 0;
            if (c[i][j] != c[i + 1][j])
            {
                swap(c[i][j], c[i + 1][j]);
                std::cout << "R> [ " << j << ", " << i << " ] " << ans
                          << "\n";
                tmp = check(c, i, j);
                if (ans < tmp)
                    ans = tmp;

                swap(c[i][j], c[i + 1][j]);
            }
            if (c[i][j] != c[i][j + 1])
            {
                swap(c[i][j], c[i][j + 1]);
                tmp = check(c, i, j);
                if (ans < tmp)
                    ans = tmp;
                std::cout << "C> [ " << j << ", " << i << " ] " << ans
                          << "\n";
                swap(c[i][j], c[i][j + 1]);
            }
        }
    }*/
    std::cout << ans;
    return 0;
}

/*
for (int i = 0; i < n - 1; i++)
    {
        if (c[i][b] == c[i + 1][b])
        {
            row += 1;
        }
        else
        {
            if (ans < row)
                ans = row;
            row = 0;
        }
        if (c[a][i] == c[a][i + 1])
        {
            column += 1;
        }
        else
        {
            if (ans < column)
                ans = column;
            column = 0;
        }
    }
    이게 안되는데 아마도 같이 하면서 검사하지 않는 부분이 잇는듯
*/

/*
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
*/