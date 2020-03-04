//https://www.acmicpc.net/problem/15649
#include <iostream>
using namespace std;
bool c[8]; //bool의 초기값은 0, 0 = false
int a[8], n, m;
int g(int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == true)
            continue;
        a[index] = i;
        c[i] = true;
        g(index + 1);
        c[i] = false;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g(0);
    return 0;
}

/**
//https://yabmoons.tistory.com/100?category=838490
#include <iostream>
#include <vector>
using namespace std;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
bool s[8] = {
    false,
};
vector<int> per;
int n, m;
void out()
{
    for (int i = 0; i < per.size(); i++)
    {
        cout << per[i] << ' ';
    }
    cout << '\n';
}
void dfs(int cnt)
{
    if (cnt == m)
        out();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == true)
            continue;
        s[i] = true;
        per.push_back(arr[i]);
        dfs(cnt + 1);
        per.pop_back();
        s[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dfs(0);
    return 0;
} 
**/