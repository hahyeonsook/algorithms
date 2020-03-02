//https://www.acmicpc.net/problem/15664
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool s[8] = {
    false,
};
int arr[8];
vector<int> per;
set<vector<int>> over;
set<vector<int>>::iterator iter;
int n, m;
void dfs(int cnt)
{
    if (cnt == m)
        over.insert(per);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == true)
            continue;

        if (cnt == 0 || per[cnt - 1] <= arr[i])
        {
            s[i] = true;
            per.push_back(arr[i]);
            dfs(cnt + 1);
            per.pop_back();
            s[i] = false;
        }
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
    dfs(0);

    for (iter = over.begin(); iter != over.end(); iter++)
    {
        vector<int> tmp = *iter;
        for (int i = 0; i < tmp.size(); i++)
        {
            cout << tmp[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}