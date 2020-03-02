//https://www.acmicpc.net/problem/15665
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int arr[7];
int s[7];
int n, m;
set<string> over;
void dfs(int cnt)
{
    if (cnt == m)
    {
        string ans;
        for (int i = 0; i < m; i++)
        {
            ans += to_string(s[i]);
            ans += ' ';
        }
        over.insert(ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        s[cnt] = arr[i];
        dfs(cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << '\n';
    dfs(0);

    set<string>::iterator iter;
    for (iter = over.begin(); iter != over.end(); iter++)
    {
        cout << *iter << '\n';
    }
    return 0;
}

/**
 * 1. 틀렸습니다로 나옴 -> 9999 9999 555 555로 받았을 때 숫자값이 아니라 ?가 나옴, +'0'대신 to_string()으로 바꿈
 * 2. 틀렸습니다로 나옴
**/